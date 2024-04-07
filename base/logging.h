// Logging wrapper around glog.

#pragma once

#include <glog/logging.h>

namespace base {

void InitLogging(int* argc, char*** argv);

}  // namespace base
