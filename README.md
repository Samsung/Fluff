# Fluff
A tool designed to synthesise semantically correct JavaScript snippets given arbitrary data.

Useful for fuzzing.

# Requirements
* bazel
* c++17 compatible compiler
* yaml-cpp library

# Usage
Typical fuzzing setup:

* Compile target interpreter using [American Fuzzy Lop] (http://lcamtuf.coredump.cx/afl/) for instrumentation.
* Compile Fluff with the correct interface (for example to fuzz ChakraCore pass `-DFUZZ_CHAKRA` as a flag for compilation). `bazel build :fluff --cxxopt="-DFUZZ_CHAKRA"`
* Start fuzzing using `afl-fuzz`, for example: `afl-fuzz -m none -i dir_in -o dir_out ./fluff @@ js_grammar.yaml`

# Description
Detailed information about the design of Fluff can be read in the [whitepaper](https://i.blackhat.com/asia-19/Fri-March-29/bh-asia-Dominiak-Efficient-Approach-to-Fuzzing-Interpreters-wp.pdf).

# Contributing
Patches, additions and other contributions are welcome! If you see a feature which you could implement or a bug which you could fix please send us a message or a pull request.

# Contact
If you want to drop us a message, feel free to send a mail to <m.dominiak@samsung.com> or <w.rauner@samsung.com>.
