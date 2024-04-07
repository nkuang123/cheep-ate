#pragma once

#include <array>
#include <stack>

namespace emulator {

class CheepAte {
 public:
  static constexpr uint16_t kRamBufferSize = 4096;  // 4 KB
  static constexpr uint8_t kNumVariableRegisters = 16;

  // This should run in a separate thread at a specified interval.
  void Process();

  // Returns the current amount of memory used.
  int GetMemoryUsage() const;

 private:
  void Fetch();
  void Decode();
  void Execute();

  // Program memory.
  std::array<char, kRamBufferSize> ram;

  // Points to current instruction in memory.
  uint16_t program_counter;

  // Points to location addresses in memory.
  uint16_t index_register;

  // Execution stack. Used to call and return from subroutines so only addresses
  // are stored.
  std::stack<uint16_t> execution_stack;

  // General-purpose variable registers.
  std::array<char, kNumVariableRegisters> variable_registers;
};

}  // namespace emulator
