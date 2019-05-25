#include "expression_object.h"

#include <algorithm>
#include <utility>

using std::move;
using std::string;
using std::unique_ptr;

string ExpressionObject::Emit() const {
  string result = "{";
  for (const auto& field : fields_) {
    // Trailing coma doesn't seem to matter here.
    result += field.first + ": " + field.second->Emit() + ",\n";
  }
  return result + "}";
}

void ExpressionObject::AddField(const string& identifier,
                                unique_ptr<Expression> expression) {
  fields_[identifier] = move(expression);
}
