#include <fstream>
#include <iostream>

#include "base/logging.h"
#include "emulator/cheep_ate.h"
#include "emulator/emulator_types.h"
#include "roms/rom_reader.h"

int main(int argc, char* argv[]) {
  // Initialize base utils.
  base::InitLogging(&argc, &argv);

  // Create the emulator.
  emulator::CheepAte cheep_ate;
  // TODO(nkuang): clean up file path.
  rom::RomReader<emulator::EmulatorType::kCheepAte> cheep_ate_reader(
      "/mnt/c/Users/nkuan/Documents/emulators/cheep-ate/roms/ibm.ch8");

  LOG(ERROR) << cheep_ate.GetMemoryUsage();
  LOG(ERROR) << "ROM Size: " << cheep_ate_reader.get_rom_size();
  LOG(ERROR) << "Instruction Size: "
             << static_cast<int>(cheep_ate_reader.get_instruction_size());

  return 0;
}
