#include "RString.h"

RString::RString(std::string str, ...) {
  va_list args;
  va_start (args, str);
  vsprintf (buffer, str.c_str(), args);
  va_end (args);
}

std::string RString::str() {
  return buffer;
}

RString::~RString() {
  delete buffer;
}
