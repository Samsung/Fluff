FROM base

ARG ver
ENV CC /home/build/afl/afl-2.52b/afl-clang
ENV CXX /home/build/afl/afl-2.52b/afl-clang++

WORKDIR /home/build/v8
RUN fetch v8
RUN if [ "latest" != "$ver" ]; then cd v8 && git checkout $ver; fi
WORKDIR /home/build/v8/v8
RUN mkdir -p out/x64.release
RUN echo "is_component_build = false" > out/x64.release/args.gn
RUN echo "is_debug = false" >> out/x64.release/args.gn
RUN echo "target_cpu = \"x64\"" >> out/x64.release/args.gn
RUN echo "use_goma = false" >> out/x64.release/args.gn
RUN echo "goma_dir = \"None\"" >> out/x64.release/args.gn
RUN echo "v8_enable_backtrace = true" >> out/x64.release/args.gn
RUN echo "v8_enable_disassembler = true" >> out/x64.release/args.gn
RUN echo "v8_enable_object_print = true" >> out/x64.release/args.gn
RUN echo "v8_enable_verify_heap = true" >> out/x64.release/args.gn
RUN gn gen out/x64.release

ENV PATH="${PATH}:/home/build/v8/v8/third_party/llvm-build/Release+Asserts/bin/"

RUN sed -i '2c\ \ command = /home/build/afl/afl-2.52b/afl-clang -MMD -MF ${out}.d ${defines} ${include_dirs} ${cflags} ${cflags_c} -c ${in} -o ${out}' out/x64.release/toolchain.ninja
RUN sed -i '7c\ \ command = /home/build/afl/afl-2.52b/afl-clang++ -MMD -MF ${out}.d ${defines} ${include_dirs} ${cflags} ${cflags_cc} -c ${in} -o ${out}' out/x64.release/toolchain.ninja

RUN autoninja -C out/x64.release d8

RUN tools/dev/v8gen.py x64.release.sample
RUN sed -i '2c\ \ command = /home/build/afl/afl-2.52b/afl-clang -MMD -MF ${out}.d ${defines} ${include_dirs} ${cflags} ${cflags_c} -c ${in} -o ${out}' out.gn/x64.release.sample/toolchain.ninja
RUN sed -i '7c\ \ command = /home/build/afl/afl-2.52b/afl-clang++ -MMD -MF ${out}.d ${defines} ${include_dirs} ${cflags} ${cflags_cc} -c ${in} -o ${out}' out/x64.release/toolchain.ninja
RUN ninja -C out.gn/x64.release.sample v8_monolith

RUN cp -r include/* /usr/include

WORKDIR /home/build

CMD [ "/bin/bash", "-c" ]
