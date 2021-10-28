package citadelimgloader;

import java.io.IOException;

import ghidra.app.util.bin.BinaryReader;
import ghidra.app.util.bin.StructConverter;
import ghidra.program.flatapi.FlatProgramAPI;
import ghidra.program.model.data.ArrayDataType;
import ghidra.program.model.data.DataType;
import ghidra.program.model.data.Structure;
import ghidra.program.model.data.StructureDataType;
import ghidra.util.exception.DuplicateNameException;

public class SignedHeader implements StructConverter {

	public static final int FUSE_MAX = 128;
	public static final int FUSAMAP_SIZE = FUSE_MAX / (8); // bytes
	public static final int INFO_MAX = 128;
	public static final int INFOMAP_SIZE = INFO_MAX / (8); // bytes
	public static final int SIGNATURE_SIZE = 96 * 4; // in bytes
	public static final int TAG_SIZE = 7 * 4; // in bytes
	public static final int KEY_SIZE = 96 * 4; // in bytes
	public static final int S_SIZE = 8 * 4; // in bytes
	public static final int R_SIZE = 8 * 4; // in bytes
	public static final int PAD_SIZE = 27*4 - R_SIZE - S_SIZE - 4;

	public long magic;
	public byte signature[];
	public long img_chk;
	public byte[] tag;
	public long keyid;
	public byte[] key;
	public long image_size;
	public long ro_base;
	public long ro_max;
	public long rx_base;
	public long rx_max;
	public byte fusemap[];
	public byte infomap[];
	public long epoch;
	public long major;
	public long minor;
	public long timestamp;
	public long p4cl;
	public long applysec;
	public long config1;
	public long err_response;
	public long expect_response;
	public long keyid2;
	public byte r[];
	public byte s[];
	public byte pad[];
	public long dev_id0;
	public long dev_id1;
	public long fuses_chk;
	public long info_chk;

	public SignedHeader(FlatProgramAPI api, BinaryReader reader) throws IOException {
		magic = reader.readNextUnsignedInt();
		signature = reader.readNextByteArray(SIGNATURE_SIZE);
		img_chk = reader.readNextUnsignedInt();
		tag = reader.readNextByteArray(TAG_SIZE);
		keyid = reader.readNextUnsignedInt();
		key = reader.readNextByteArray(KEY_SIZE);
		image_size = reader.readNextUnsignedInt();
		ro_base = reader.readNextUnsignedInt();
		ro_max = reader.readNextUnsignedInt();
		rx_base = reader.readNextUnsignedInt();
		rx_max = reader.readNextUnsignedInt();
		fusemap = reader.readNextByteArray(FUSAMAP_SIZE);
		infomap = reader.readNextByteArray(INFOMAP_SIZE);
		epoch = reader.readNextUnsignedInt();
		major = reader.readNextUnsignedInt();
		minor = reader.readNextUnsignedInt();
		timestamp = reader.readNextLongArray(1)[0];
		p4cl = reader.readNextUnsignedInt();
		applysec = reader.readNextUnsignedInt();
		config1 = reader.readNextUnsignedInt();
		err_response = reader.readNextUnsignedInt();
		expect_response = reader.readNextUnsignedInt();
		keyid2 = reader.readNextUnsignedInt();
		r = reader.readNextByteArray(R_SIZE);
		s = reader.readNextByteArray(S_SIZE);
		pad = reader.readNextByteArray(PAD_SIZE);
		dev_id0 = reader.readNextUnsignedInt();
		dev_id1 = reader.readNextUnsignedInt();
		fuses_chk = reader.readNextUnsignedInt();
		info_chk = reader.readNextUnsignedInt();
	}

	@Override
	public DataType toDataType() throws DuplicateNameException, IOException {
		Structure struct = new StructureDataType("SignedHeader", 0);
		struct.add(DWORD, 4, "magic", null);
		struct.add(new ArrayDataType(BYTE, SIGNATURE_SIZE, 1), "signature", null);
		struct.add(DWORD, 4, "img_chk", null);
		struct.add(new ArrayDataType(BYTE, TAG_SIZE, 1), "tag", null);
		struct.add(DWORD, 4, "keyid", null);
		struct.add(new ArrayDataType(BYTE, KEY_SIZE, 1), "key", null);
		struct.add(DWORD, 4, "image_size", null);
		struct.add(DWORD, 4, "ro_base", null);
		struct.add(DWORD, 4, "ro_max", null);
		struct.add(DWORD, 4, "rx_base", null);
		struct.add(DWORD, 4, "rx_max", null);
		struct.add(new ArrayDataType(BYTE, FUSAMAP_SIZE, 1), "fusemap", null);
		struct.add(new ArrayDataType(BYTE, INFOMAP_SIZE, 1), "infomap", null);
		struct.add(DWORD, 4, "epoch", null);
		struct.add(DWORD, 4, "major", null);
		struct.add(DWORD, 4, "minor", null);
		struct.add(DWORD, 8, "timestamp", null);
		struct.add(DWORD, 4, "p4cl", null);
		struct.add(DWORD, 4, "applysec", null);
		struct.add(DWORD, 4, "config1", null);
		struct.add(DWORD, 4, "err_response", null);
		struct.add(DWORD, 4, "expect_response", null);
		struct.add(DWORD, 4, "keyid2", null);
		struct.add(new ArrayDataType(BYTE, R_SIZE, 1), "r", null);
		struct.add(new ArrayDataType(BYTE, S_SIZE, 1), "s", null);
		struct.add(new ArrayDataType(BYTE, PAD_SIZE, 1), "pad", null);
		struct.add(DWORD, 4, "dev_id0", null);
		struct.add(DWORD, 4, "dev_id1", null);
		struct.add(DWORD, 4, "fuses_chk", null);
		struct.add(DWORD, 4, "info_chk", null);

		return struct;
	}

}
