#ifndef EXPRESSION_FUNCTION_MOCK_H_
#define EXPRESSION_FUNCTION_MOCK_H_

#include "gmock/gmock.h"
#include "statements/expression_function.h"

class ExpressionFunctionMock : public ExpressionFunction {
 public:
  MOCK_CONST_METHOD0(Emit, std::string());
};

#endif  // ifndef EXPRESSION_FUNCTION_MOCK_H_
