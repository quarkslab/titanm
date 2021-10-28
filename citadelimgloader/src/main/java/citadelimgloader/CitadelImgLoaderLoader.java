/* ###
 * Copyright 2021 Quarkslab
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package citadelimgloader;

import ghidra.app.util.Option;
import ghidra.app.util.bin.BinaryReader;
import ghidra.app.util.bin.ByteProvider;
import ghidra.app.util.importer.MessageLog;
import ghidra.app.util.opinion.AbstractLibrarySupportLoader;
import ghidra.app.util.opinion.LoadSpec;
import ghidra.app.util.xml.ProgramXmlMgr;
import ghidra.app.util.xml.XmlProgramOptions;
import ghidra.framework.Application;
import ghidra.framework.model.DomainObject;
import ghidra.framework.store.LockException;
import ghidra.program.flatapi.FlatProgramAPI;
import ghidra.program.model.address.AddressOverflowException;
import ghidra.program.model.data.DataUtilities;
import ghidra.program.model.data.DataUtilities.ClearDataMode;
import ghidra.program.model.data.Structure;
import ghidra.program.model.data.StructureDataType;
import ghidra.program.model.lang.CompilerSpecID;
import ghidra.program.model.lang.LanguageCompilerSpecPair;
import ghidra.program.model.lang.LanguageID;
import ghidra.program.model.listing.Program;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryConflictException;
import ghidra.program.model.util.CodeUnitInsertionException;
import ghidra.util.Msg;
import ghidra.util.exception.CancelledException;
import ghidra.util.exception.DuplicateNameException;
import ghidra.util.task.TaskMonitor;

import java.io.IOException;
import java.io.InputStream;
import java.util.*;
import java.io.*;

/**
 * Class used by Ghidra to load Titan M images
 */
public class CitadelImgLoaderLoader extends AbstractLibrarySupportLoader {
    /* Static values from C headers */
    public static final int CHIP_FLASH_BASE = 0x40000;
    public static final int CHIP_FLASH_SIZE = (512 * 1024);
    public static final int CHIP_FLASH_HALF = CHIP_FLASH_SIZE >> 1;
    public static final int CHIP_RO_SIZE = 0x4000;
    public static final int CHIP_RW_A_MEM_OFF = CHIP_RO_SIZE;
    public static final int CHIP_RO_B_MEM_OFF = CHIP_FLASH_HALF;
    public static final int CHIP_RW_B_MEM_OFF = (CHIP_FLASH_HALF + CHIP_RO_SIZE);
    public static final int CHIP_SIG_HEADER_SIZE = 1024;
    public static final int CHIP_RW_SIZE = CHIP_RO_B_MEM_OFF - CHIP_RW_A_MEM_OFF;
    public static final int RO_CERTS_A_OFF = 0x2800;
    public static final int RO_CERTS_B_OFF = (CHIP_RO_B_MEM_OFF + 0x2800);
    public static final int RO_CERTS_A_SIZE = 0x01000;
    public static final int RO_CERTS_B_SIZE = 0x00c00;
    public static final int RO_PROVISION_DATA_A_OFF = 0x3800;
    public static final int RO_PROVISION_DATA_A_SIZE = 0x0800;

    public SignedHeader ro_a_header;
    public SignedHeader rw_a_header;
    public SignedHeader ro_b_header;
    public SignedHeader rw_b_header;

    @Override
    public String getName() {
        return "CitadelImgLoader";
    }

    @Override
    public Collection<LoadSpec> findSupportedLoadSpecs(ByteProvider provider)
            throws IOException {
        List<LoadSpec> loadSpecs = new ArrayList<>();

        BinaryReader reader = new BinaryReader(provider, true);
        Long magic = reader.readNextUnsignedInt();
        if (magic == 0xfffffffeL)
            loadSpecs.add(new LoadSpec(
                    this, 0,
                    new LanguageCompilerSpecPair(new LanguageID("ARM:LE:32:Cortex"),
                            new CompilerSpecID("default")),
                    true));

        return loadSpecs;
    }

    @Override
    protected void load(ByteProvider provider, LoadSpec loadSpec,
                        List<Option> options, Program program,
                        TaskMonitor monitor, MessageLog log)
            throws CancelledException, IOException {

        BinaryReader reader = new BinaryReader(provider, true);
        FlatProgramAPI api = new FlatProgramAPI(program, monitor);
        InputStream inStream = provider.getInputStream(0);

        Memory mem = program.getMemory();
        /* Load segments */
        try {
            loadMemBlocks(mem, api, inStream, monitor);
        } catch (LockException | MemoryConflictException |
                AddressOverflowException | CancelledException |
                DuplicateNameException e1) {
            // TODO Auto-generated catch block
            e1.printStackTrace();
        }

        /* Set headers */
        // Set RO_A header
        reader.setPointerIndex(0);
        ro_a_header = new SignedHeader(api, reader);
        // Set RW_A header
        reader.setPointerIndex(CHIP_RW_A_MEM_OFF);
        rw_a_header = new SignedHeader(api, reader);
        // Set RO_B header
        reader.setPointerIndex(CHIP_RO_B_MEM_OFF);
        ro_b_header = new SignedHeader(api, reader);
        // Set RW_B header
        reader.setPointerIndex(CHIP_RW_B_MEM_OFF);
        rw_b_header = new SignedHeader(api, reader);

        try {
            DataUtilities.createData(program, api.toAddr(CHIP_FLASH_BASE),
                    ro_a_header.toDataType(), -1, false,
                    ClearDataMode.CLEAR_ALL_UNDEFINED_CONFLICT_DATA);
            DataUtilities.createData(program,
                    api.toAddr(CHIP_FLASH_BASE + CHIP_RW_A_MEM_OFF),
                    rw_a_header.toDataType(), -1, false,
                    ClearDataMode.CLEAR_ALL_UNDEFINED_CONFLICT_DATA);
            DataUtilities.createData(program,
                    api.toAddr(CHIP_FLASH_BASE + CHIP_RO_B_MEM_OFF),
                    ro_b_header.toDataType(), -1, false,
                    ClearDataMode.CLEAR_ALL_UNDEFINED_CONFLICT_DATA);
            DataUtilities.createData(program,
                    api.toAddr(CHIP_FLASH_BASE + CHIP_RW_B_MEM_OFF),
                    rw_b_header.toDataType(), -1, false,
                    ClearDataMode.CLEAR_ALL_UNDEFINED_CONFLICT_DATA);
        } catch (CodeUnitInsertionException | DuplicateNameException e) {
            Msg.error(this, e.getMessage());
        }

        // set labels
        try {
            api.createLabel(api.toAddr(CHIP_FLASH_BASE), "RO_A_HEADER", true);
            api.createLabel(api.toAddr(CHIP_FLASH_BASE + CHIP_RW_A_MEM_OFF),
                    "RW_A_HEADER", true);
            api.createLabel(api.toAddr(CHIP_FLASH_BASE + CHIP_RO_B_MEM_OFF),
                    "RO_B_HEADER", true);
            api.createLabel(api.toAddr(CHIP_FLASH_BASE + CHIP_RW_B_MEM_OFF),
                    "RW_B_HEADER", true);

            api.createLabel(api.toAddr(CHIP_FLASH_BASE + CHIP_SIG_HEADER_SIZE),
                    "RO_A_START", true);
            api.createLabel(api.toAddr(CHIP_FLASH_BASE + CHIP_RW_A_MEM_OFF +
                            CHIP_SIG_HEADER_SIZE),
                    "RW_A_START", true);
            api.createLabel(api.toAddr(CHIP_FLASH_BASE + CHIP_RO_B_MEM_OFF +
                            CHIP_SIG_HEADER_SIZE),
                    "RO_B_START", true);
            api.createLabel(api.toAddr(CHIP_FLASH_BASE + CHIP_RW_B_MEM_OFF +
                            CHIP_SIG_HEADER_SIZE),
                    "RW_B_START", true);
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

        /* Set certs and provision area */
        Structure certsBufA = new StructureDataType("RO_CERTS_A", RO_CERTS_A_SIZE);
        Structure certsBufB = new StructureDataType("RO_CERTS_B", RO_CERTS_B_SIZE);
        Structure provData =
                new StructureDataType("RO_PROVISION_DATA_A", RO_PROVISION_DATA_A_SIZE);

        try {
            DataUtilities.createData(
                    program, api.toAddr(CHIP_FLASH_BASE + RO_CERTS_A_OFF), certsBufA, -1,
                    false, ClearDataMode.CLEAR_ALL_UNDEFINED_CONFLICT_DATA);
            DataUtilities.createData(
                    program, api.toAddr(CHIP_FLASH_BASE + RO_CERTS_B_OFF), certsBufB, -1,
                    false, ClearDataMode.CLEAR_ALL_UNDEFINED_CONFLICT_DATA);
            DataUtilities.createData(
                    program, api.toAddr(CHIP_FLASH_BASE + RO_PROVISION_DATA_A_OFF),
                    provData, -1, false, ClearDataMode.CLEAR_ALL_UNDEFINED_CONFLICT_DATA);
        } catch (CodeUnitInsertionException e) {
            Msg.error(this, e.getMessage());
        }
        try {
            api.createLabel(api.toAddr(CHIP_FLASH_BASE + RO_CERTS_A_OFF),
                    "RO_CERTS_A", true);
            api.createLabel(api.toAddr(CHIP_FLASH_BASE + RO_CERTS_B_OFF),
                    "RO_CERTS_B", true);
            api.createLabel(api.toAddr(CHIP_FLASH_BASE + RO_PROVISION_DATA_A_OFF),
                    "RO_PROVISION_DATA_A", true);
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

        try {
            loadSymbolsFromXml(program, monitor, log);
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

    private void loadMemBlocks(Memory mem, FlatProgramAPI api,
                               InputStream inStream, TaskMonitor monitor)
            throws LockException, MemoryConflictException, AddressOverflowException,
            CancelledException, DuplicateNameException {
        // load RO_A
        mem.createInitializedBlock("RO_A_HEADER", api.toAddr(CHIP_FLASH_BASE),
                inStream, CHIP_SIG_HEADER_SIZE, monitor, false);
        mem.createInitializedBlock(
                "RO_A", api.toAddr(CHIP_FLASH_BASE + CHIP_SIG_HEADER_SIZE), inStream,
                CHIP_RO_SIZE - CHIP_SIG_HEADER_SIZE, monitor, false);

        // load RW_A
        mem.createInitializedBlock("RW_A_HEADER",
                api.toAddr(CHIP_FLASH_BASE + CHIP_RW_A_MEM_OFF),
                inStream, CHIP_SIG_HEADER_SIZE, monitor, false);
        mem.createInitializedBlock(
                "RW_A",
                api.toAddr(CHIP_FLASH_BASE + CHIP_RW_A_MEM_OFF + CHIP_SIG_HEADER_SIZE),
                inStream, CHIP_RO_B_MEM_OFF - CHIP_RW_A_MEM_OFF - CHIP_SIG_HEADER_SIZE,
                monitor, false);

        // load RO_B
        mem.createInitializedBlock("RO_B_HEADER",
                api.toAddr(CHIP_FLASH_BASE + CHIP_RO_B_MEM_OFF),
                inStream, CHIP_SIG_HEADER_SIZE, monitor, false);
        mem.createInitializedBlock(
                "RO_B",
                api.toAddr(CHIP_FLASH_BASE + CHIP_RO_B_MEM_OFF + CHIP_SIG_HEADER_SIZE),
                inStream, CHIP_RO_SIZE - CHIP_SIG_HEADER_SIZE, monitor, false);

        // load RW_B
        mem.createInitializedBlock("RW_B_HEADER",
                api.toAddr(CHIP_FLASH_BASE + CHIP_RW_B_MEM_OFF),
                inStream, CHIP_SIG_HEADER_SIZE, monitor, false);
        mem.createInitializedBlock(
                "RW_B",
                api.toAddr(CHIP_FLASH_BASE + CHIP_RW_B_MEM_OFF + CHIP_SIG_HEADER_SIZE),
                inStream, CHIP_RW_SIZE - CHIP_SIG_HEADER_SIZE, monitor, false);

        // Add uninitialized SRAM
        mem.createUninitializedBlock("SRAM", api.toAddr(0x10000), 0x1ffff, false);

        // Add HW registers region
        mem.createUninitializedBlock("HW_REGS", api.toAddr(0x40000000), 0x5fffff, false);
        // Add CPU registers
        mem.createUninitializedBlock("CPU_REGS", api.toAddr(0xe0000000), 0xeffff, false);
    }

    @Override
    public List<Option>
    getDefaultOptions(ByteProvider provider, LoadSpec loadSpec,
                      DomainObject domainObject, boolean isLoadIntoProgram) {
        List<Option> list = super.getDefaultOptions(
                provider, loadSpec, domainObject, isLoadIntoProgram);

        // TODO: If this loader has custom options, add them to 'list'
        list.add(
                new Option("Option name goes here", "Default option value goes here"));

        return list;
    }

    private String getSymbolsFilePath() throws IOException {
        String databasePath = Application.getModuleDataFile("symbols.xml").toString();
        return databasePath;
    }

    /* Load symbols from HW_REGS and CPU_REGS memory regions */
    private void loadSymbolsFromXml(Program program, TaskMonitor monitor, MessageLog log) throws IOException {
        MessageLog mgrLog = null;
        try {
            ProgramXmlMgr pxml = new ProgramXmlMgr(new File(getSymbolsFilePath()));
            // Option for XML importation
            XmlProgramOptions options = new XmlProgramOptions();
            options.setAddToProgram(true); // update existing program
            options.setSymbols(true);

            mgrLog = pxml.read(program, monitor, options);
            log.copyFrom(mgrLog);
        } catch (Exception e) {
            String message = "(empty)";
            if (mgrLog != null && !"".equals(mgrLog.toString())) {
                message = mgrLog.toString();
            }
            if (log != null && !"".equals(log.toString())) {
                message = log.toString();
            }
            Msg.warn(this, "XML import exception, log: " + message, e);
            throw new IOException(e.getMessage(), e);
        }
    }

    @Override
    public String validateOptions(ByteProvider provider, LoadSpec loadSpec,
                                  List<Option> options, Program program) {

        // TODO: If this loader has custom options, validate them here.  Not all
        // options require validation.

        return super.validateOptions(provider, loadSpec, options, program);
    }
}
