FROM base

ARG ver
ENV CC /home/build/afl/afl-2.52b/afl-gcc
ENV CXX /home/build/afl/afl-2.52b/afl-g++

WORKDIR /home/build/
RUN hg clone http://hg.nginx.org/njs
RUN if [ "latest" != "$ver" ]; then cd njs && hg update -r $ver; fi
RUN sed -i -e 's/delete/del/g' njs/njs/njs.h
WORKDIR /home/build/njs
RUN CFLAGS="-DNXT_HAVE_POSIX_MEMALIGN=1 -fsanitize=address" ./configure && make
RUN find /home/build/njs -iname nxt*.h -exec cp {} /usr/include \;
WORKDIR /home/build/

CMD [ "/bin/bash", "-c" ]
