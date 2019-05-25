#ifndef STATUS_H_
#define STATUS_H_

#include <string>

class [[nodiscard]] Status {
 public:
  static Status Error(const std::string &error_message);
  static Status OkStatus();
  std::string Message() const;
  bool Ok() const;

 private:
  Status();
  std::string message_;
  bool ok_;
};

#define CHECK_RET(expr)             \
  {                                 \
    auto check_ret_status = (expr); \
    if (!check_ret_status.Ok()) {   \
      return check_ret_status;      \
    }                               \
  }

#define CHECK_FINALLY_RET(expr, finally) \
  {                                      \
    auto check_ret_status = (expr);      \
    finally;                             \
    if (!check_ret_status.Ok()) {        \
      return check_ret_status;           \
    }                                    \
  }

#define CHECK_SUCCECSS_RET(expr, success, finally) \
  {                                                \
    auto check_ret_status = (expr);                \
    success;                                       \
    finally;                                       \
    return check_ret_status;                       \
  }

#endif  // ifndef STATUS_H_
