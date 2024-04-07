#include "base/logging.h"

namespace base {

void InitLogging(int* argc, char*** argv) {
  google::InitGoogleLogging(*argv[0]);
}

}