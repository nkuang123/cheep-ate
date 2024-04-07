#include "base/logging.h"
#include "emulator/cheep_ate.h"

int main(int argc, char* argv[]) {
  // Initialize base utils.
  base::InitLogging(&argc, &argv);

  // Create the emulator.
  emulator::CheepAte cheep_ate;
  LOG(ERROR) << cheep_ate.GetMemoryUsage();
  LOG(ERROR) << emulator::CheepAte::kRamBufferSize;
  LOG(ERROR) << "Finished";

  return 0;
}
