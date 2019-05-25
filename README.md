# Fluff
A tool designed to synthesise semantically correct JavaScript snippets given arbitrary data.

Useful for fuzzing.

<<<<<<< HEAD
# JS Runtimes supported out-of-the-box
* [jerryscript](https://github.com/pando-project/jerryscript)
* [njs](https://hg.nginx.org/njs)
* [duktape](https://duktape.org/download.html)
* [v8](https://v8.dev/)

# Requirements
* docker
* make

# Building
* (optional) Check if you have access to docker (run ```docker info```)
* (optional) Specify desired version of JS runtime in ```Makefile.conf```
* Run ```make (jerryscript | njs | duktape | v8)```
* If everything builds correctly the process will result in:
    * build/fluff_* - binary to fuzz
    * build/fluff_*_dry - binary that will convert Fluff bytecode to JS testcase (stdout)
    * build/grammars
        * js_grammar.yaml - es5.1 grammar file
        * js_grammar_es6.yaml - es6 grammar file
=======
# Requirements
* bazel
* c++17 compatible compiler
* yaml-cpp library
>>>>>>> parent of 0e0b3a7... Revert "Revert "Initial commit""

# Usage
Typical fuzzing setup:

<<<<<<< HEAD
* Create input folder and sample testcase, i.e. ```mkdir in && echo "420" >> in/testcase```
* Start fuzzing using `afl-fuzz`, for example: `afl-fuzz -m none -i in -o out ./fluff_njs @@ js_grammar.yaml`
* (optional) you can use build container to run fuzzing, requires some manual work
```
docker run -it -d -v path/to/fluff/repository/build:/home/build/fluff /bin/bash
docker exec -it container_number bash
# afl-fuzz is preinstalled in /home/build/afl
```

* Enjoy your cup of tea/coffee and wait for crashes
=======
* Compile target interpreter using [American Fuzzy Lop] (http://lcamtuf.coredump.cx/afl/) for instrumentation.
* Compile Fluff with the correct interface (for example to fuzz ChakraCore pass `-DFUZZ_CHAKRA` as a flag for compilation). `bazel build :fluff --cxxopt="-DFUZZ_CHAKRA"`
* Start fuzzing using `afl-fuzz`, for example: `afl-fuzz -m none -i dir_in -o dir_out ./fluff @@ js_grammar.yaml`
>>>>>>> parent of 0e0b3a7... Revert "Revert "Initial commit""

# Description
Detailed information about the design of Fluff can be read in the [whitepaper](https://i.blackhat.com/asia-19/Fri-March-29/bh-asia-Dominiak-Efficient-Approach-to-Fuzzing-Interpreters-wp.pdf).

# Contributing
<<<<<<< HEAD
Patches, additions and other contributions are welcome! If you see a feature which you could implement or a bug which you could fix please send us a message or a pull request. If you have found some interesting bug with this tool, please leave us a message/github issue for the future Hall Of Fame.
=======
Patches, additions and other contributions are welcome! If you see a feature which you could implement or a bug which you could fix please send us a message or a pull request.
>>>>>>> parent of 0e0b3a7... Revert "Revert "Initial commit""

# Contact
If you want to drop us a message, feel free to send a mail to <m.dominiak@samsung.com> or <w.rauner@samsung.com>.
