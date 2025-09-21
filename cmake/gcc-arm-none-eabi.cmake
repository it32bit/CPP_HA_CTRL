set(CMAKE_SYSTEM_NAME               Generic)
set(CMAKE_SYSTEM_PROCESSOR          arm)

# Some default GCC settings
# arm-none-eabi- must be part of path environment

set(TOOLCHAIN_PREFIX                arm-none-eabi-)
set(TOOLCHAIN_PATH                  "/usr/bin")
set(STM32CUBE_PROGRAMMER            "/usr/bin/STM32_Programmer_CLI")

set(FLAGS                           "-fdata-sections -ffunction-sections -Wl,--gc-sections")
set(CPP_FLAGS                       "${FLAGS} -fno-rtti -fno-exceptions -fno-threadsafe-statics")

set(CMAKE_C_FLAGS                   ${FLAGS})
set(CMAKE_CXX_FLAGS                 ${CPP_FLAGS})

set(CMAKE_C_COMPILER                "${TOOLCHAIN_PATH}/${TOOLCHAIN_PREFIX}gcc")
set(CMAKE_ASM_COMPILER              ${CMAKE_C_COMPILER})
set(CMAKE_CXX_COMPILER              "${TOOLCHAIN_PATH}/${TOOLCHAIN_PREFIX}g++")
set(CMAKE_OBJCOPY                   "${TOOLCHAIN_PATH}/${TOOLCHAIN_PREFIX}objcopy")
set(CMAKE_SIZE                      "${TOOLCHAIN_PATH}/${TOOLCHAIN_PREFIX}size")

set(CMAKE_EXECUTABLE_SUFFIX_ASM     ".elf")
set(CMAKE_EXECUTABLE_SUFFIX_C       ".elf")
set(CMAKE_EXECUTABLE_SUFFIX_CXX     ".elf")

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# # MCU specific flags
# set(TARGET_FLAGS "-mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard ")

# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${TARGET_FLAGS}")
# set(CMAKE_ASM_FLAGS "${CMAKE_C_FLAGS} -x assembler-with-cpp -MMD -MP")
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -fdata-sections -ffunction-sections")

# set(CMAKE_C_FLAGS_DEBUG "-O0 -g3")
# set(CMAKE_C_FLAGS_RELEASE "-Os -g0")
# set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3")
# set(CMAKE_CXX_FLAGS_RELEASE "-Os -g0")

# set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -fno-rtti -fno-exceptions -fno-threadsafe-statics")

# set(CMAKE_EXE_LINKER_FLAGS "${TARGET_FLAGS}")

# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --specs=nano.specs")

# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--print-memory-usage")
# set(TOOLCHAIN_LINK_LIBRARIES "m")
