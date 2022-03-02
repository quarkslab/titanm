# Nos client
## Build instructions

### Android

```bash
$ export NDK_ROOT=path_to_ndk
$ mkdir out
$ cd out
$ cmake -DCMAKE_TOOLCHAIN_FILE=$NDK_ROOT/build/cmake/android.toolchain.cmake -DCMAKE_SYSTEM_NAME=Android -DCMAKE_ANDROID_NDK=$NDK_ROOT -DCMAKE_ANDROID_ARCH_ABI=arm64-v8a -DANDROID_ABI=arm64-v8a -DANDROID_NATIVE_API_LEVEL=android-26 -DCMAKE_ANDROID_STL_TYPE=c++_static  -DCMAKE_ANDROID_NDK_TOOLCHAIN_VERSION=clang -DCMAKE_FIND_ROOT_PATH="$NDK_ROOT/sysroot" -DCMAKE_SYSROOT_COMPILE=$NDK_ROOT/toolchains/llvm/prebuilt/linux-x86_64/sysroot -DCMAKE_NO_SYSTEM_FROM_IMPORTED=1 ..
$ make -j8
```

### Linux

```bash
$ mkdir out
$ cd out
$ cmake ..
$ make -j8
```

### Using Docker

```bash
$ docker build . -t nosclient
$ mkdir out
$ docker run -v $PWD/out:/out --rm nosclient
```

## Usage

### Running the client

```bash
$ adb push nosclient /data/local/tmp/
$ adb shell
# cd /data/local/tmp/
# chmod 777 nosclient
# ./nosclient # to print usage
```

### Leaking Titan M boot ROM

First, downgrade the firmware to `ec_2020-09-25.bin` using SPI rescue feature.

```bash
$ adb push {out/android/nosclient,scripts/leak.sh} /data/local/tmp/
$ adb shell
# cd /data/local/tmp/
# chmod 777 nosclient
# sh leak.sh brom
```

### Parse sigrok SPI traces

```bash
$ cd scripts
$ LD_PRELOAD=../out/libparser.so python parse_signrok-csv.py spi-trace.csv
```
