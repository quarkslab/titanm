FROM debian:10

ENV ANDROID_NDK_HOME /opt/android-ndk
ENV NDK_ROOT /opt/android-ndk
ENV ANDROID_NDK_VERSION r21e

RUN apt-get update -yq \
&& apt-get install -yq wget unzip

# ------------------------------------------------------
# --- Android NDK

# download
RUN mkdir /opt/android-ndk-tmp && \
    cd /opt/android-ndk-tmp && \
    wget -q https://dl.google.com/android/repository/android-ndk-${ANDROID_NDK_VERSION}-linux-x86_64.zip && \
# uncompress
    unzip -q android-ndk-${ANDROID_NDK_VERSION}-linux-x86_64.zip && \
# move to its final location
    mv ./android-ndk-${ANDROID_NDK_VERSION} ${ANDROID_NDK_HOME} && \
# remove temp dir
    cd ${ANDROID_NDK_HOME} && \
    rm -rf /opt/android-ndk-tmp

# add to PATH
ENV PATH ${PATH}:${ANDROID_NDK_HOME}

# ------------------------------------------------------
# --- Other dependencies

RUN apt-get install -yq clang cmake make \
&& apt-get install -yq zlib1g-dev \
&& apt-get clean

COPY . /nostoolkit

WORKDIR /nostoolkit

CMD bash /nostoolkit/buildAll.sh
