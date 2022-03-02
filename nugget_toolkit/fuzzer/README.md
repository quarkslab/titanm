# Titan M fuzzer
`nosclient` integrates [`libprotobuf-mutator`](https://github.com/google/libprotobuf-mutator) to mutate messages and feed them to Titan M.

## Oracle
The fuzzer adopts a black box approach, and only relies on the code returned after sending a command. In practice, this is the return code of `NuggetClient::CallApp`, forwarded from `nos_call_application`. Return codes greater than 1 are considered "interesting".

This oracle clearly comes with some drawbacks. The logic is based on a header in the AOSP, defining an `app_status` enum as:
```c
/* Application status codes are uint32_t, but an enum is easier to read. */
enum app_status {
  /* A few values are common to all applications */
  APP_SUCCESS = 0,
  APP_ERROR_BOGUS_ARGS, /* caller being stupid */
  APP_ERROR_INTERNAL,   /* application being stupid */
  APP_ERROR_TOO_MUCH,   /* caller sent too much data */
  APP_ERROR_IO,         /* problem sending or receiving data */
  APP_ERROR_RPC,        /* problem during RPC communication */
  APP_ERROR_CHECKSUM,   /* checksum failed, only used within protocol */
  APP_ERROR_BUSY,       /* the app is already working on a commnad */
  APP_ERROR_TIMEOUT,    /* the app took too long to respond */
  /* more? */
```

From our analysis, interesting bugs return `APP_ERROR_INTERNAL`. However, we also look for other error codes, which may indicate logic errors or faulty message handling.

## Architecture
The mutator works in a quite straightforward way. All we have to do is instantiate it with a seed and call the `Mutate` function, passing the class we want to mutate and its maximum size.

We have a list of all the commands per each task. At every iteration we pick a task, then a command, we mutate it and we feed it to the Titan M. In practice, we decided to leave out AVB for the moment, since many of its commands should be sent in bootloader mode and return application-specific return codes.

## Corpus
At the moment, there is a very basic corpus included in the fuzzer. This is for two reasons: first, messages are often very simple, thus it takes just few iterations to form a fairly complex one; second, capturing one or more versions of each message is time consuming, if at all possible (this means understanding each and every command and the context in which they are used).

Still, we initialize requests containing a key blob, with a valid one (that can be created with `./nosclient keyblob`. This at least allows to pass the first checks, but there's plenty of space for improvement.

## Extensions
There are a few ways in which this fuzzer can be improved. Some of them follow.

* To build a better picture of what happens on the Titan M, we can try to parse the response of commands (passing a valid `std::vector<uint8_t>` to `CallApp`). This may allow to improve awareness of what happened on the chip side, especially if paired with some reversing to obtain what responses can be interesting.

* Explore how to create an accurate corpus, by either sniffing valid messages and understanding more about them, or using test cases on the AOSP.  

* While valid, the mutations offered by `libprotobuf-mutator` are fairly basic. They can be improved by overriding the `Mutate` function, or post-processing mutated messages. To this end, more hardcoded values may be included, similarly to what we are doing with `KeyBlob` fields.