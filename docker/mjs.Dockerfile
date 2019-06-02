FROM base

ARG ver
ENV CC /home/build/afl/afl-2.52b/afl-clang

RUN git clone https://github.com/cesanta/mjs
RUN if [ "latest" != "$ver" ]; then cd mjs && git checkout $ver; fi
RUN ln -s /usr/bin/clang-6.0 /usr/bin/clang
WORKDIR /home/build/mjs/mjs 
RUN ${CC} -c -fsanitize=address -lm -std=c99 -Wall -Wextra -pedantic -g -O3  -I. -I.. -Isrc -DMJS_MAIN -DMJS_EXPOSE_PRIVATE -DCS_ENABLE_STDIO -DMJS_ENABLE_DEBUG -I../frozen  -DCS_MMAP -DMJS_MODULE_LINES -Wl,--no-as-needed -ldl  src/../../common/cs_dbg.c src/../../common/cs_file.c src/../../common/cs_varint.c src/../../common/mbuf.c src/../../common/mg_str.c src/../../common/str_util.c src/../../frozen/frozen.c src/ffi/ffi.c src/mjs_array.c src/mjs_bcode.c src/mjs_builtin.c src/mjs_conversion.c src/mjs_core.c src/mjs_dataview.c src/mjs_exec.c src/mjs_ffi.c src/mjs_gc.c src/mjs_json.c src/mjs_main.c src/mjs_object.c src/mjs_parser.c src/mjs_primitive.c src/mjs_string.c src/mjs_tok.c src/mjs_util.c
RUN ar -rv libmjs.a cs_dbg.o cs_file.o cs_varint.o mbuf.o mg_str.o str_util.o frozen.o ffi.o mjs_array.o mjs_bcode.o mjs_builtin.o mjs_conversion.o mjs_core.o mjs_dataview.o mjs_exec.o mjs_ffi.o mjs_gc.o mjs_json.o mjs_main.o mjs_object.o mjs_parser.o mjs_primitive.o mjs_string.o mjs_tok.o mjs_util.o

WORKDIR /home/build/mjs/mjs/build
RUN cp ../libmjs.a .
WORKDIR /home/build/mjs/mjs/build/mjs
RUN cp /home/build/mjs/mjs.h .
WORKDIR /home/build/
CMD [ "/bin/bash", "-c" ]