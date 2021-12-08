// hook and trace requests and answers to/from citadel via citadeld
const moduleBase =  Module.getExportByName("libnos_transport.so",
    'nos_call_application')

const log_function = new NativeFunction(Module.getExportByName(null, "__android_log_write"), "int", ["int", "pointer", "pointer"]);
const LOG_TAG = Memory.allocUtf8String("qb_parser");
const LOG_DEBUG = 3;
function log(msg) {
    log_function(LOG_DEBUG, LOG_TAG, Memory.allocUtf8String(msg));
}

var dev;
var app_id, param;
var request, request_size;
var reply, reply_size_addr, reply_size;

var libname = "libparser.so";
var libdir = "/data/local/tmp/";
var libpath = libdir + libname;

Module.load(libpath);
// remember that C++ mangles symbols!
var sanity_func = new NativeFunction(Module.findExportByName(libname, "_Z12sanity_checkv"), 'int', []);
log("Found sanity function at: " + sanity_func);
var sanity_res = sanity_func();
log("Sanity function returned " + sanity_res);

var parser_func = new NativeFunction(Module.findExportByName(libname, "parser"), "void", ["int", "int", "pointer", "int", "pointer", "int"]);

Interceptor.attach(moduleBase, {
    onEnter: function(args) {
        dev = args[0];
        app_id = parseInt(args[1]);
        param = parseInt(args[2]);
        request = args[3];
        // this is the actual size of the request
        request_size = args[4].toInt32();
        reply = args[5];
        // this is instead a pointer to the reply size
        reply_size_addr = args[6];
        log("appID: " + args[1] + ", param: " + args[2]);
        log("request: " + args[3] + ", request_size: " + args[4]);
        log("reply: " + args[5] + ", reply_size_addr: " + args[6]);

        if (request_size > 0) {
            log("Request:\n" + hexdump(Memory.readByteArray(request, request_size)));
        }
        else {
            log("Request has null size");
        }
    },

    onLeave: function(retval) {
        if (reply != 0) {
            log("Reply size:\n" + hexdump(Memory.readByteArray(reply_size_addr, 4)));
            reply_size = Memory.readUInt(reply_size_addr, 4);
            log("Reply size is " + reply_size);
            if (reply_size > 0) {
                log("Reply:\n" + hexdump(Memory.readByteArray(reply, reply_size)));
            }
        }
        else {
            log("Reply has null size");
        }

        parser_func(app_id, param, request, request_size, reply, reply_size);

        log("------------------------------------------------------------------------------------------------------");
    }
});