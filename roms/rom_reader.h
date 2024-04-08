#pragma once

#include <boost/endian/conversion.hpp>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

namespace rom {

template <class T> class RomReader {
public:
  RomReader(const std::string &rom_file_path) {
    // Copy the ROM into our buffer.
    std::fstream input_rom(rom_file_path,
                           std::ios_base::in | std::ios_base::binary);
    std::istreambuf_iterator<char> first = input_rom, last;
    rom_buffer_.insert(rom_buffer_.end(), first, last);
  }

  // Standard getters.
  int get_instruction_size() const { return static_cast<int>(sizeof(T)); }

  int get_rom_size() const { return static_cast<int>(rom_buffer_.size()); }

  // Retrieves the next instruction and updates the instruction index.
  T GetInstruction() {
    // TODO(nkuang): std::assert doesn't work??? Need to find an assert lib.
    // assert(instruction_idx < rom_buffer_.size());

    auto instruction =
        reinterpret_cast<const T *>(rom_buffer_.data())[instruction_idx++];
    // Convert to big-endian for ease of reading. That means the first nibble
    // that determines opcode type is at (instruction & 0xF000).
    boost::endian::native_to_big_inplace(instruction);

    return instruction;
  }

private:
  // ROM buffer.
  std::vector<char> rom_buffer_;

  // Tracks the next instruction to fetch.
  int instruction_idx = 0;
};

} // namespace rom
