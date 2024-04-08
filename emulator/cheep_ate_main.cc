#include "base/logging.h"
#include "emulator/cheep_ate.h"
#include "roms/rom_reader.h"

int main(int argc, char* argv[]) {
  // Initialize base utils.
  base::InitLogging(&argc, &argv);

  // Create the emulator.
  emulator::CheepAte cheep_ate;
  // TODO(nkuang): clean up file path.
  rom::RomReader<uint16_t> cheep_ate_reader(
      "/mnt/c/Users/nkuan/Documents/emulators/cheep-ate/roms/ibm.ch8");

  LOG(ERROR) << cheep_ate.GetMemoryUsage();
  LOG(ERROR) << "ROM Size: " << cheep_ate_reader.get_rom_size();
  LOG(ERROR) << "Instruction Size: "
             << static_cast<int>(cheep_ate_reader.get_instruction_size());
  for (int idx = 0; idx < cheep_ate_reader.get_rom_size(); idx += 2) {
    LOG(ERROR) << std::hex
               << static_cast<int>(cheep_ate_reader.GetInstruction());
  }

  return 0;
}
