FROM base

ARG url
ENV CC /home/build/afl/afl-2.52b/afl-gcc
ENV CXX /home/build/afl/afl-2.52b/afl-g++

WORKDIR /home/build/duktape
RUN wget -q -O duktape.tar.xz $url
RUN tar xf duktape.tar.xz && mv duktape-* duktape
WORKDIR /home/build/duktape/duktape
RUN make -f Makefile.sharedlibrary
RUN mkdir /usr/lib/duktape
RUN cp libduktape.so.* /usr/lib/duktape/libduktape.so
RUN cp src/*.h /usr/lib/duktape/

WORKDIR /home/build

CMD [ "/bin/bash", "-c" ]