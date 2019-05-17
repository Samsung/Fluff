FROM base

ARG ver
ENV CC /home/build/afl/afl-2.52b/afl-gcc
ENV CXX /home/build/afl/afl-2.52b/afl-g++

WORKDIR /home/build
RUN git clone https://github.com/pando-project/jerryscript
RUN if [ "latest" != "$ver" ]; then cd njs && git checkout $ver; fi
WORKDIR /home/build/jerryscript
RUN python tools/build.py --debug --lto=off --profile=es2015-subset

WORKDIR /home/build

CMD [ "/bin/bash", "-c" ]