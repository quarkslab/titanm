#!/bin.sh

BUILDIR="${PWD}/build"
OUTDIR="/out"

if ! [[ -d "$OUTDIR" ]]
then
    echo "$OUTDIR not present"
    mkdir $OUTDIR
fi

mkdir $BUILDIR

# Build Android library
mkdir $OUTDIR/android

cd $BUILDIR
rm -rf * # Clean build dir

echo "Building Android client"
cmake -DCMAKE_TOOLCHAIN_FILE=$NDK_ROOT/build/cmake/android.toolchain.cmake -DCMAKE_SYSTEM_NAME=Android -DCMAKE_ANDROID_NDK=$NDK_ROOT -DCMAKE_ANDROID_ARCH_ABI=arm64-v8a -DANDROID_ABI=arm64-v8a -DANDROID_NATIVE_API_LEVEL=android-26 -DCMAKE_ANDROID_STL_TYPE=c++_static  -DCMAKE_ANDROID_NDK_TOOLCHAIN_VERSION=clang -DCMAKE_FIND_ROOT_PATH="$NDK_ROOT/sysroot" -DCMAKE_SYSROOT_COMPILE=$NDK_ROOT/toolchains/llvm/prebuilt/linux-x86_64/sysroot -DCMAKE_NO_SYSTEM_FROM_IMPORTED=1 ..
make -j8 \
  && cp nosclient libparser.so $OUTDIR/android/ \
  || echo "Error while building Android client"

# Build Linux library
mkdir $OUTDIR/linux

rm -rf * # Clean build dir

echo "Building Linux client"
cmake ..
make -j8 \
  && cp libparser.so $OUTDIR/linux/ \
  || echo "Error while building Android client"

