package(default_visibility = ["//visibility:public"])

cc_library(
  name = "cheep_ate",
  srcs = ["cheep_ate.cc"],
  hdrs = ["cheep_ate.h"],
)

cc_library(
  name = "emulator_types",
  hdrs = ["emulator_types.h"],
)

cc_binary(
  name = "cheep_ate_main",
  srcs = ["cheep_ate_main.cc"],
  deps = [
    ":cheep_ate",
    ":emulator_types",
    "//base:logging",
    "//roms:rom_reader",
  ],
)
