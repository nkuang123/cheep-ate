#pragma once

#include <unordered_map>

namespace emulator {

// Supported emulator types.
enum class EmulatorType {
  kCheepAte,
};

// Base parameters, shared by all emulators.
struct EmulatorParams {
  uint8_t instruction_size;
};

// Hardcoded parameters for each emulator type.
const std::unordered_map<EmulatorType, EmulatorParams> kEmulatorParamsMap = {
    // Cheep Ate parameters.
    {EmulatorType::kCheepAte,
     {
         .instruction_size = sizeof(uint16_t),
     }},
};

} // namespace emulator
