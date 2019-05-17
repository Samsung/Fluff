FROM ubuntu:18.04
WORKDIR /home/build

RUN apt-get update && apt-get install -y -qq pkg-config zip g++ zlib1g-dev google-mock unzip \
    python wget libgtest-dev clang-6.0 cmake libyaml-cpp-dev clang-format mercurial libpcre3-dev \
    autoconf2.13 tree git

RUN wget -q -O /tmp/bazel.sh https://github.com/bazelbuild/bazel/releases/download/0.24.1/bazel-0.24.1-installer-linux-x86_64.sh
RUN chmod +x /tmp/bazel.sh
RUN /tmp/bazel.sh
RUN bazel -h

WORKDIR /usr/src/gtest
RUN cmake CMakeLists.txt && make && cp *.a /usr/lib

WORKDIR /usr/src/gmock
RUN cmake CMakeLists.txt && make && cp *.a /usr/lib

#setup afl-2.52b
WORKDIR /home/build/afl
RUN wget -q http://lcamtuf.coredump.cx/afl/releases/afl-latest.tgz
RUN tar xf afl-latest.tgz && cd afl-2.52b && make

#setup for building V8
WORKDIR /home/build
RUN git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git
ENV PATH="${PATH}:/home/build/depot_tools"
