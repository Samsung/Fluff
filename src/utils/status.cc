<<<<<<< HEAD
#include "status.h"
=======
#include "utils/status.h"
>>>>>>> parent of 0e0b3a7... Revert "Revert "Initial commit""

using std::string;

Status Status::Error(const string& error_message) {
  Status status;
  status.ok_ = false;
  status.message_ = error_message;
  return status;
}

Status Status::OkStatus() {
  Status status;
  status.ok_ = true;
  return status;
}

string Status::Message() const { return message_; }

bool Status::Ok() const { return ok_; }

Status::Status() {}
