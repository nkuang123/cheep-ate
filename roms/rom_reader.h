#pragma once

#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

#include "emulator/emulator_types.h"

namespace rom {

template <emulator::EmulatorType E> class RomReader {
public:
  RomReader(const std::string &rom_file_path) {
    // Copy the ROM into our buffer.
    std::fstream input_rom(rom_file_path,
                           std::ios_base::in | std::ios_base::binary);
    std::istreambuf_iterator<char> first = input_rom, last;
    rom_buffer_.insert(rom_buffer_.end(), first, last);
  }

  // Standard getters.
  // TODO(nkuang): this function should return an int. But GetInstruction()'s
  // return type should be auto deduced depending on the instructon size.
  decltype(auto) get_instruction_size() {
    return emulator::kEmulatorParamsMap.at(E).instruction_size;
  }

  int get_rom_size() { return static_cast<int>(rom_buffer_.size()); }

private:
  // ROM buffer.
  std::vector<char> rom_buffer_;
};

} // namespace rom
