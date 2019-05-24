#ifndef JAVASCRIPT_INTERFACE_H_
#define JAVASCRIPT_INTERFACE_H_

#include <memory>
#include <vector>

#include "statements/instruction.h"

// JavascriptInterface is a layer between fluff and the execution engine.
// Given a list of instructions, it will execute them in the jevascript engine
// which is currently targeted. This class will have many implementations
// (one for each target), only one of which will be enabled in each build.
class JavascriptInterface {
 public:
  void Init();
  void Execute(const std::vector<std::unique_ptr<Instruction>>& instructions);
};

#endif  // JAVASCRIPT_INTERFACE_H_
