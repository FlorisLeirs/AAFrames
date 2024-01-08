cmake_minimum_required(VERSION 3.10)

message(STATUS "CMAKE_VERSION: ${CMAKE_VERSION}")
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

cmake_policy(SET CMP0054 NEW)

# Support for visual studio build
set(CMAKE_VS_INCLUDE_INSTALL_TO_DEFAULT_BUILD 1)

# Build shared libraries opposed to single exe
set(NV_SHARED_REPLAY_LIB 0)

#Use Agility SDK
set(NV_USE_AGILITY_SDK 0)

# Allow builds with incompatibilities to succeed if the environment variable is set
if(DEFINED ENV{BUILD_UNSUPPORTED_CAPTURE})
    add_compile_definitions(BUILD_UNSUPPORTED_CAPTURE)
endif()

# Choose an available Windows SDK in order to meet the Direct3D feature level
set(REQUIRED_WIN_SDK_VERSION 10.0.16299.0)
if(WIN32 AND REQUIRED_WIN_SDK_VERSION AND NOT CMAKE_SYSTEM_VERSION)
    # Detect all the Windows SDKs that exist on the machine.
    set(WIN_SDK_VERSIONS "")

    # We have to check "Windows.h" to verify if the SDK is really installed because there's no reliable registry value since v10.
    macro(AddWinSDKIfInstalled SDK_INCLUDE_PATH SDK_VERSION)
        if(EXISTS "${SDK_INCLUDE_PATH}/um/Windows.h")
            list(APPEND WIN_SDK_VERSIONS "${SDK_VERSION}")
        endif()
    endmacro()

    # Helper to identify all sub - sdks within a windows SDK directory
    macro(AddWin10SDKIfInstalled SDK_DIR)
        if(IS_DIRECTORY ${SDK_DIR})
            file(GLOB SUB_FOLDERS RELATIVE ${SDK_DIR}/Include ${SDK_DIR}/Include/*)
            foreach(SUB_FOLDER ${SUB_FOLDERS})
                AddWinSDKIfInstalled(${SDK_DIR}/Include/${SUB_FOLDER} ${SUB_FOLDER})
            endforeach()
        endif()
    endmacro()

    # Start at v8.1 because the minimum Visual Studio supported version is 2015.
    get_filename_component(WIN_SDK_V81_ROOT "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows Kits\\Installed Roots;KitsRoot81]" ABSOLUTE CACHE)
    if(NOT WIN_SDK_V81_ROOT)
        set(WIN_SDK_V81_ROOT "%ProgramFiles%/Windows Kits/8.1")
    endif()
    if(IS_DIRECTORY ${WIN_SDK_V81_ROOT})
        AddWinSDKIfInstalled(${WIN_SDK_V81_ROOT}/Include 8.1)
    endif()

    # Add system-identified windows 10 SDKs
    get_filename_component(WIN_SDK_V10_ROOT "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows Kits\\Installed Roots;KitsRoot10]" ABSOLUTE CACHE)
    if(NOT WIN_SDK_V10_ROOT)
        set(WIN_SDK_V10_ROOT "%ProgramFiles%/Windows Kits/10")
    endif()
    AddWin10SDKIfInstalled(${WIN_SDK_V10_ROOT})

    # Add a user-specified WINDOWS_SDK_DIR if one is defined
    if(DEFINED ENV{WINDOWS_SDK_DIR})
        AddWin10SDKIfInstalled($ENV{WINDOWS_SDK_DIR})
    endif()

    message(STATUS "Finding Windows SDK to satisfy required SDK of: ${REQUIRED_WIN_SDK_VERSION}")
    if (WIN_SDK_VERSIONS)
        message(STATUS "Windows SDK candidates: ${WIN_SDK_VERSIONS}")
    else()
        message(STATUS "Windows SDK candidates: none found")
    endif()

    # Select a version that satisfies the requirement
    list(REVERSE WIN_SDK_VERSIONS)
    foreach(WIN_SDK_VERSION ${WIN_SDK_VERSIONS})
        if (WIN_SDK_VERSION VERSION_GREATER_EQUAL REQUIRED_WIN_SDK_VERSION)
            message(STATUS "Windows SDK selected: ${WIN_SDK_VERSION}")
            set(CMAKE_SYSTEM_VERSION ${WIN_SDK_VERSION})
            break()
        endif()
    endforeach()

    if(NOT CMAKE_SYSTEM_VERSION)
        message(FATAL_ERROR "Failed to find a Windows SDK that available to use. The minimum version required is ${REQUIRED_WIN_SDK_VERSION}")
    endif()
endif()

# Set project name
set(CPP_PROJECT_NAME "ProjectAdvanced__2023_12_28__16_34_03")
set(CPP_PROJECT_NAME_NOTIMESTAMP "ProjectAdvanced")

# Set output name
option(NV_USE_TIMESTAMP_IN_APPLICATION_NAME "Rename output file to be timestamped" OFF)
if (NV_USE_TIMESTAMP_IN_APPLICATION_NAME)
    set(CPP_OUTPUT_NAME ${CPP_PROJECT_NAME})
else()
    set(CPP_OUTPUT_NAME ${CPP_PROJECT_NAME_NOTIMESTAMP})
endif()

# The target name is trim so that cmake path lengths are short; the actual
# executable will be renamed via a property below
set(EXECUTABLE_TARGET cppcap)

# Information of original capture
set(NV_ORIGINAL_OS WIN32)
set(NV_ORIGINAL_WINSYS win32)
set(NV_ORIGINAL_ARCH 64)

# Detect current platform the CMake is running under
if(WIN32)
    set(NV_HOST_PLATFORM "WIN32")
elseif(UNIX AND (NOT APPLE))

    # Differentiate Arm host from desktop
    # Ideally, "CMAKE_HOST_SYSTEM_PROCESSOR" should return what we need but somehow it returns empty
    # when running CMake (3.16.3) on Arm host, hence currently we need to call "uname" by ourselves
    execute_process(COMMAND "uname" "-p" OUTPUT_VARIABLE NV_HOST_SYSTEM_PROCESSOR OUTPUT_STRIP_TRAILING_WHITESPACE)
    if(NV_HOST_SYSTEM_PROCESSOR STREQUAL "aarch64")
        set(NV_HOST_PLATFORM "LINUX_EMBEDDED")
    else()
        set(NV_HOST_PLATFORM "LINUX_DESKTOP")
    endif()

else()
    message(FATAL_ERROR "The CMake must be running under Windows/Linux Desktop")
endif()
message(STATUS "NV_HOST_PLATFORM: ${NV_HOST_PLATFORM}")

# Determine default target platform if not specified by "-DNV_TARGET_PLATFORM"
if(NOT NV_TARGET_PLATFORM)
    if(NV_HOST_PLATFORM STREQUAL "WIN32")
        set(NV_TARGET_PLATFORM "WIN32")
    elseif(NV_HOST_PLATFORM STREQUAL "LINUX_DESKTOP")
        if(NV_ORIGINAL_OS STREQUAL "WIN32")
            set(NV_TARGET_PLATFORM "LINUX_DESKTOP")
        else()
            set(NV_TARGET_PLATFORM "${NV_ORIGINAL_OS}")
        endif()
    elseif(NV_HOST_PLATFORM STREQUAL "LINUX_EMBEDDED")
        set(NV_TARGET_PLATFORM "LINUX_EMBEDDED")
    else()
        message(FATAL_ERROR "Unknown host platform: '${NV_HOST_PLATFORM}'")
    endif()
endif()
message(STATUS "NV_TARGET_PLATFORM: ${NV_TARGET_PLATFORM}")

# Make NV_TARGET_PLATFORM to be an option selectable in cmake-GUI
# The supported target platforms are determined based on the host platform
set(NV_TARGET_PLATFORM "${NV_TARGET_PLATFORM}" CACHE STRING "Select target platform to build for")
if(NV_HOST_PLATFORM STREQUAL "WIN32")
    set_property(CACHE NV_TARGET_PLATFORM PROPERTY STRINGS "WIN32")
elseif(NV_HOST_PLATFORM STREQUAL "LINUX_DESKTOP")
    set_property(CACHE NV_TARGET_PLATFORM PROPERTY STRINGS "LINUX_DESKTOP" "LINUX_EMBEDDED" "QNX")
elseif(NV_HOST_PLATFORM STREQUAL "LINUX_EMBEDDED")
    set_property(CACHE NV_TARGET_PLATFORM PROPERTY STRINGS "LINUX_EMBEDDED")
else()
    message(FATAL_ERROR "Unknown host platform: '${NV_HOST_PLATFORM}'")
endif()

# Check if we are building for the original platform
if(NV_TARGET_PLATFORM STREQUAL "${NV_ORIGINAL_OS}")
    set(NV_BUILD_FOR_ORIGINAL_PLATFORM 1)
else()
    set(NV_BUILD_FOR_ORIGINAL_PLATFORM 0)
endif()

# Currently we only support building Vulkan C++ capture on a different platform
if(NOT NV_BUILD_FOR_ORIGINAL_PLATFORM)

    # Read metadata.json
    file(READ ${CMAKE_CURRENT_SOURCE_DIR}/metadata.json NV_METADATA_CONTENTS)

    # Get primary API
    # First try to use the CMake json query functionality, if supported
    if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.19")
        string(JSON NV_PRIMARY_API ERROR_VARIABLE errorParseJson GET ${NV_METADATA_CONTENTS} "primary_api")
    endif()
    # Fallback to do the search by ourselves
    if((NOT NV_PRIMARY_API) OR (NV_PRIMARY_API STREQUAL "NOTFOUND"))
        string(REPLACE "\n" ";" metadataLines ${NV_METADATA_CONTENTS})
        foreach(metadataLine ${metadataLines})
            string(REGEX MATCH "\\s*\"primary_api\": \"([0-9A-Za-z]+)\",\\s*" matched ${metadataLine})
            if(matched)
                set(NV_PRIMARY_API ${CMAKE_MATCH_1})
                break()
            endif()
        endforeach()
    endif()

    # Reject if not supported
    if(NOT NV_PRIMARY_API STREQUAL "vulkan")
        message(FATAL_ERROR "Building '${NV_PRIMARY_API}' C++ capture on a different platform is not supported")
    endif()

endif()

# Determine default window system if not specified by "-DNV_WINSYS"
if(NOT NV_WINSYS)
    if(NV_BUILD_FOR_ORIGINAL_PLATFORM)
        set(NV_WINSYS ${NV_ORIGINAL_WINSYS})
    else()
        # Choose default window system for the target platform
        if(NV_TARGET_PLATFORM STREQUAL "LINUX_DESKTOP")
            set(NV_WINSYS xcb)
        elseif(NV_TARGET_PLATFORM STREQUAL "WIN32")
            set(NV_WINSYS win32)
        elseif(NV_TARGET_PLATFORM STREQUAL "LINUX_EMBEDDED")
            set(NV_WINSYS x11)
        elseif(NV_TARGET_PLATFORM STREQUAL "QNX")
            set(NV_WINSYS screen)
        endif()
    endif()
endif()
message(STATUS "NV_WINSYS: ${NV_WINSYS}")

# Make NV_WINSYS to be an option selectable in cmake-GUI
# The supported window systems are determined based on the target platform
set(NV_WINSYS "${NV_WINSYS}" CACHE STRING "Select window system type to interact with graphics API")
if(NV_TARGET_PLATFORM STREQUAL "LINUX_DESKTOP")
    set_property(CACHE NV_WINSYS PROPERTY STRINGS xcb x11 vulkan-d2d)
elseif(NV_TARGET_PLATFORM STREQUAL "WIN32")
    set_property(CACHE NV_WINSYS PROPERTY STRINGS win32)
elseif(NV_TARGET_PLATFORM STREQUAL "LINUX_EMBEDDED")
    set_property(CACHE NV_WINSYS PROPERTY STRINGS x11 wayland vulkan-d2d egldevice nvsci)
elseif(NV_TARGET_PLATFORM STREQUAL "QNX")
set_property(CACHE NV_WINSYS PROPERTY STRINGS screen vulkan-d2d egldevice nvsci)
elseif()
    message(FATAL_ERROR "Unknown target platform: '${NV_TARGET_PLATFORM}'")
endif()

if(NV_WINSYS STREQUAL xcb)
    set(NV_USE_XCB 1)
elseif(NV_WINSYS STREQUAL x11)
    set(NV_USE_X11 1)
elseif(NV_WINSYS STREQUAL vulkan-d2d)
    set(NV_USE_D2D 1)
elseif(NV_WINSYS STREQUAL win32)
    set(NV_USE_WIN32 1)
elseif(NV_WINSYS STREQUAL wayland)
    set(NV_USE_WAYLAND 1)
elseif(NV_WINSYS STREQUAL egldevice)
    set(NV_USE_EGL_DEVICE 1)
elseif(NV_WINSYS STREQUAL screen)
    set(NV_USE_SCREEN 1)
elseif(NV_WINSYS STREQUAL nvsci)
    set(NV_USE_NVSCI 1)
else()
    if(NV_TARGET_PLATFORM STREQUAL "WIN32")
        message(FATAL_ERROR "Specified wrong 'NV_WINSYS' argument. Must be 'win32' for Windows.")
    elseif(NV_TARGET_PLATFORM STREQUAL "LINUX_DESKTOP")
        message(FATAL_ERROR "Specified wrong 'NV_WINSYS' argument. Must be one of 'xcb'/'x11'/'vulkan-d2d' for Linux Desktop.")
    elseif(NV_TARGET_PLATFORM STREQUAL "LINUX_EMBEDDED")
        message(FATAL_ERROR "Specified wrong 'NV_WINSYS' argument. Must be one of 'xcb'/'x11'/'vulkan-d2d'/'wayland'/'egldevice'/'nvsci' for Embedded Linux.")
    elseif(NV_TARGET_PLATFORM STREQUAL "QNX")
        message(FATAL_ERROR "Specified wrong 'NV_WINSYS' argument. Must be one of 'screen'/'vulkan-d2d'/'egldevice'/'nvsci' for QNX.")
    endif()
endif()

# Native compile on Arm host
if((NV_HOST_PLATFORM STREQUAL "LINUX_EMBEDDED") AND (NV_TARGET_PLATFORM STREQUAL "LINUX_EMBEDDED"))

    set(NV_LINUX_EMBEDDED_INC_DIR "")
    set(NV_LINUX_EMBEDDED_LINKER_FLAGS "")

# Handle cross-compiling for embedded linux
elseif(NV_TARGET_PLATFORM STREQUAL "LINUX_EMBEDDED")

    # Check if the SDK is specified in environment
    if((NOT NV_SDKDIR) AND (DEFINED ENV{NV_SDKDIR}))
        set(NV_SDKDIR $ENV{NV_SDKDIR})
    endif()

    # Validate the SDK
    if(NOT NV_SDKDIR)
        message(FATAL_ERROR "Must specify 'NV_SDKDIR' offering the path to DriveOS/L4T SDK directory for compiling")
    endif()
    if(NOT EXISTS "${NV_SDKDIR}")
        message(FATAL_ERROR "'${NV_SDKDIR}' not found")
    endif()

    # Identify this is building for L4T or Drive OS
    if(EXISTS "${NV_SDKDIR}/drive-linux")
        message(STATUS "Building for DriveOS")
        set(NV_LINUX_EMBEDDED_TARGET "DriveOS")
        set(NV_DRIVE_OS_DIR "${NV_SDKDIR}/drive-linux")
    elseif(EXISTS "${NV_SDKDIR}/Linux_for_Tegra/rootfs")
        message(STATUS "Building for JetPack-L4T")
        set(NV_LINUX_EMBEDDED_TARGET "L4T")
    else()
        message(FATAL_ERROR "Cannot find DriveOS or JetPack-L4T SDK directory")
    endif()

    # Locate toolchain directory
    if(NV_LINUX_EMBEDDED_TARGET STREQUAL "DriveOS")

        set(DRIVE_TOOLCHAIN_ROOT "${NV_DRIVE_OS_DIR}/../toolchains/")

        if(EXISTS "${DRIVE_TOOLCHAIN_ROOT}/gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu")
            set(NV_BUILD_CROSS_BIN "${DRIVE_TOOLCHAIN_ROOT}/gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-")
        elseif(EXISTS "${DRIVE_TOOLCHAIN_ROOT}/tegra-4.9-nv/usr/bin/aarch64-gnu-linux")
            set(NV_BUILD_CROSS_BIN "${DRIVE_TOOLCHAIN_ROOT}/tegra-4.9-nv/usr/bin/aarch64-gnu-linux/aarch64-gnu-linux-")
        else()
            # 6.0.x toolchain folder name is in form of: aarch64--glibc--stable-YYYY.MM-N
            file(GLOB aarch64_toolchain_dirs "${DRIVE_TOOLCHAIN_ROOT}/aarch64--glibc--stable-*/usr/bin")
            if(aarch64_toolchain_dirs)
                list(GET aarch64_toolchain_dirs 0 dir)
                message(STATUS "Using toolchain in ${dir}")
                set(NV_BUILD_CROSS_BIN "${dir}/aarch64-linux-")
            endif()
        endif()

        if(NOT NV_BUILD_CROSS_BIN)
            message(FATAL_ERROR "Cannot find DriveOS SDK toolchain")
        endif()

        set(NV_LINUX_EMBEDDED_INC_DIR "${NV_DRIVE_OS_DIR}/include")
        set(NV_LINUX_EMBEDDED_LIB_DIR "${NV_DRIVE_OS_DIR}/lib-target" "${NV_DRIVE_OS_DIR}/lib-target/${NV_WINSYS}")
        set(NV_LINUX_EMBEDDED_LINKER_FLAGS "-Wl,-rpath-link=${NV_DRIVE_OS_DIR}/lib-target:${NV_DRIVE_OS_DIR}/lib-target/${NV_WINSYS}")
        if(NV_USE_WAYLAND)
            set(NV_LINUX_EMBEDDED_LINKER_FLAGS "${NV_LINUX_EMBEDDED_LINKER_FLAGS} -Wl,-rpath-link=${NV_DRIVE_OS_DIR}/oss/liblzma/liblzma/lib/aarch64-linux-gnu:${NV_DRIVE_OS_DIR}/oss/zlib/zlib1g/lib/aarch64-linux-gnu:${NV_DRIVE_OS_DIR}/oss/xml2/libxml2/usr/lib/aarch64-linux-gnu")
        endif()

    elseif(NV_LINUX_EMBEDDED_TARGET STREQUAL "L4T")

        # Make sure aarch64-linux-gnu-g++ can be found from PATH environment
        find_program(NV_BUILD_CROSS_COMPILER NAMES "aarch64-linux-gnu-g++")
        if(NOT NV_BUILD_CROSS_COMPILER)
            message(FATAL_ERROR "Cannot find aarch64-linux-gnu-g++ in the \${PATH}. You need to install it by \"sudo apt-get install g++-aarch64-linux-gnu\"")
        endif()

        get_filename_component(NV_BUILD_CROSS_BIN_DIR "${NV_BUILD_CROSS_COMPILER}" DIRECTORY)
        set(NV_BUILD_CROSS_BIN "${NV_BUILD_CROSS_BIN_DIR}/aarch64-linux-gnu-")

        set(NV_LINUX_EMBEDDED_INC_DIR      "${NV_SDKDIR}/Linux_for_Tegra/rootfs/usr/include" "${NV_SDKDIR}/Linux_for_Tegra/rootfs/usr/include/drm" "${NV_SDKDIR}/Linux_for_Tegra/rootfs/usr/include/aarch64-linux-gnu")
        set(NV_LINUX_EMBEDDED_LIB_DIR      "")
        set(NV_LINUX_EMBEDDED_LINKER_FLAGS "--sysroot=${NV_SDKDIR}/Linux_for_Tegra/rootfs")

    endif()

    # Specify compiler/linker/... for cross-compiling
    # This must be done before any language is set (i.e., before any project() or enable_language() command)
    set(CMAKE_C_COMPILER   "${NV_BUILD_CROSS_BIN}gcc"    CACHE INTERNAL "")
    set(CMAKE_CXX_COMPILER "${NV_BUILD_CROSS_BIN}g++"    CACHE INTERNAL "")
    set(CMAKE_AR           "${NV_BUILD_CROSS_BIN}ar"     CACHE INTERNAL "")
    set(CMAKE_RANLIB       "${NV_BUILD_CROSS_BIN}ranlib" CACHE INTERNAL "")
    set(CMAKE_STRIP        "${NV_BUILD_CROSS_BIN}strip"  CACHE INTERNAL "")
    set(CMAKE_NM           "${NV_BUILD_CROSS_BIN}nm"     CACHE INTERNAL "")
    set(CMAKE_LINKER       "${NV_BUILD_CROSS_BIN}ld"     CACHE INTERNAL "")

    # Turn ld into a multi-pass linker by adding --{begin,end}-group (listing order of .a libs no longer matters).
    set(CMAKE_CXX_LINK_EXECUTABLE "<CMAKE_CXX_COMPILER>  <FLAGS> <CMAKE_CXX_LINK_FLAGS> <LINK_FLAGS> <OBJECTS>  -o <TARGET> -Wl,--start-group <LINK_LIBRARIES> -Wl,--end-group")
    set(CMAKE_CXX_CREATE_SHARED_LIBRARY "<CMAKE_CXX_COMPILER> <CMAKE_SHARED_LIBRARY_CXX_FLAGS> <LANGUAGE_COMPILE_FLAGS> <LINK_FLAGS> <CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS> <SONAME_FLAG><TARGET_SONAME> -o <TARGET> <OBJECTS> -Wl,--start-group <LINK_LIBRARIES> -Wl,--end-group")

    # Specify platform-specific library search paths
    link_directories(${NV_LINUX_EMBEDDED_LIB_DIR})

endif()

# Handle cross-compiling for QNX
if(NV_TARGET_PLATFORM STREQUAL "QNX")

    # Check if the SDK is specified in environment
    if((NOT QNX_TOPDIR) AND (DEFINED ENV{QNX_TOPDIR}))
        set(QNX_TOPDIR $ENV{QNX_TOPDIR})
    endif()

    # Validate the SDK
    if(NOT QNX_TOPDIR)
        message(FATAL_ERROR "Must specify 'QNX_TOPDIR' offering the path to QNX SDK directory for compiling")
    endif()
    if(NOT EXISTS "${QNX_TOPDIR}")
        message(FATAL_ERROR "'${QNX_TOPDIR}' not found")
    endif()

    # Identify the QNX SDK version
    if(EXISTS "${QNX_TOPDIR}/drive-qnx")
        message(STATUS "Building for Drive-QNX")
        set(NV_QNX_DIR "${QNX_TOPDIR}/drive-qnx")
    else()
        message(FATAL_ERROR "Cannot find QNX SDK directory")
    endif()

    # Check QNX_HOST / QNX_TARGET environment
    if(NOT DEFINED ENV{QNX_HOST})
        message(FATAL_ERROR "The QNX_HOST environment variable must be set")
    endif()
    if(NOT DEFINED ENV{QNX_TARGET})
        message(FATAL_ERROR "The QNX_TARGET environment variable must be set")
    endif()

    set(NV_QNX_HOST   $ENV{QNX_HOST})
    set(NV_QNX_TARGET $ENV{QNX_TARGET})

    # Locate QNX toolchain directory
    set(NV_QNX_BASE "${QNX_TOPDIR}/toolchains/qnx_toolchain")
    if(EXISTS "${NV_QNX_BASE}/host/linux/x86")
        set(NV_QNX_KERNEL_VERSION   "6.6.0")
        set(NV_QNX_COMPILER_VERSION "4.7.3")
        set(NV_QNX_ARCH             "armle-v7")
        set(NV_QNX_TOOLS_VARIANT    "arm-unknown-nto-qnx${NV_QNX_KERNEL_VERSION}eabi")
        set(NV_BUILD_CROSS_BIN      "${NV_QNX_HOST}/usr/bin/${NV_QNX_TOOLS_VARIANT}-")
    elseif(EXISTS "${NV_QNX_BASE}/host/linux/x86_64")

        # 7.0.0 or 7.1.10?
        if(EXISTS "${NV_QNX_BASE}/host/linux/x86_64/usr/lib/gcc/aarch64-unknown-nto-qnx7.1.0/8.3.0")
            set(NV_QNX_KERNEL_VERSION   "7.1.0")
            set(NV_QNX_COMPILER_VERSION "8.3.0")
        else()
            set(NV_QNX_KERNEL_VERSION   "7.0.0")
            set(NV_QNX_COMPILER_VERSION "5.3.0")
        endif()

        set(NV_QNX_ARCH          "aarch64le")
        set(NV_QNX_TOOLS_VARIANT "aarch64-unknown-nto-qnx${NV_QNX_KERNEL_VERSION}")
        set(NV_BUILD_CROSS_BIN   "${NV_QNX_HOST}/usr/bin/${NV_QNX_TOOLS_VARIANT}-")

    else()
        message(FATAL_ERROR "Invalid QNX toolchain")
    endif()

    # Specify compiler/linker/... for cross-compiling
    # This must be done before any language is set (i.e., before any project() or enable_language() command)
    # It is recommended to use qcc/q++ instead of invoking gcc/g++ directly
    set(CMAKE_C_COMPILER   "${NV_QNX_HOST}/usr/bin/qcc"  CACHE INTERNAL "")
    set(CMAKE_CXX_COMPILER "${NV_QNX_HOST}/usr/bin/q++"  CACHE INTERNAL "")
    set(CMAKE_AR           "${NV_BUILD_CROSS_BIN}ar"     CACHE INTERNAL "")
    set(CMAKE_RANLIB       "${NV_BUILD_CROSS_BIN}ranlib" CACHE INTERNAL "")
    set(CMAKE_STRIP        "${NV_BUILD_CROSS_BIN}strip"  CACHE INTERNAL "")
    set(CMAKE_NM           "${NV_BUILD_CROSS_BIN}nm"     CACHE INTERNAL "")
    set(CMAKE_LINKER       "${NV_QNX_HOST}/usr/bin/qcc"  CACHE INTERNAL "")

    # Update flags
    set(NV_QNX_COMMON_FLAGS "-V${NV_QNX_COMPILER_VERSION},gcc_nto${NV_QNX_ARCH} -DWIN_INTERFACE_CUSTOM -DNV_GLES_VER_MAJOR=2 -D_FILE_OFFSET_BITS=64 -D_QNX_SOURCE -D_POSIX_C_SOURCE=200112L -DNV_EMBEDDED_BUILD")
    set(CMAKE_C_FLAGS   "${NV_QNX_COMMON_FLAGS}" CACHE INTERNAL "")
    set(CMAKE_CXX_FLAGS "${NV_QNX_COMMON_FLAGS}" CACHE INTERNAL "")

    set(NV_QNX_INC_DIR
        "${NV_QNX_DIR}/include"
        "${NV_QNX_DIR}/nvidia-bsp/usr/include"
        "${NV_QNX_HOST}/usr/lib/gcc/${NV_QNX_TOOLS_VARIANT}/${NV_QNX_COMPILER_VERSION}/include"
        "${NV_QNX_TARGET}/usr/include/c++/v1"
        "${NV_QNX_TARGET}/usr/include/c++/${NV_QNX_COMPILER_VERSION}/${NV_QNX_TOOLS_VARIANT}"
        "${NV_QNX_TARGET}/usr/include"
    )
    set(NV_QNX_LIB_DIR
        "${NV_QNX_DIR}/lib-target"
        "${NV_QNX_DIR}/lib-target/screen"
        "${NV_QNX_DIR}/nvidia-bsp/${NV_QNX_ARCH}/usr/lib"
        "${NV_QNX_DIR}/qnx-early-access/${NV_QNX_ARCH}/lib"
        "${NV_QNX_DIR}/qnx-early-access/${NV_QNX_ARCH}/usr/lib"
        "${NV_QNX_TARGET}/${NV_QNX_ARCH}/lib"
        "${NV_QNX_TARGET}/${NV_QNX_ARCH}/lib/gcc/${NV_QNX_COMPILER_VERSION}"
        "${NV_QNX_TARGET}/${NV_QNX_ARCH}/usr/lib"
    )

    # Specify platform-specific library search paths
    link_directories(${NV_QNX_LIB_DIR})

endif()

project(${CPP_PROJECT_NAME})

# Determine bitness
if(CMAKE_SIZEOF_VOID_P STREQUAL "8")
    set(NV_USE_64BIT 1)
elseif(CMAKE_SIZEOF_VOID_P STREQUAL "4")
    set(NV_USE_32BIT 1)
else()
    message(FATAL_ERROR "Unrecognized bitness.")
endif()

if(NV_USE_64BIT)
    link_directories(
)
endif()

if(NV_USE_32BIT)
    link_directories(
)
endif()

# Checking arch mismatch
if((NV_USE_64BIT AND NV_ORIGINAL_ARCH STREQUAL 64) OR (NV_USE_32BIT AND NV_ORIGINAL_ARCH STREQUAL 32))
    message(STATUS "Building ${NV_ORIGINAL_ARCH}-bit app.")
elseif(NV_USE_64BIT AND NV_ORIGINAL_ARCH STREQUAL 32)
    message(WARNING "Application originally targeted 32-bit; compiling now as 64-bit.")
elseif(NV_USE_32BIT AND NV_ORIGINAL_ARCH STREQUAL 64)
    message(FATAL_ERROR "Application originally targeted 64-bit; compiling now as 32-bit.")
else()
    message(FATAL_ERROR "Unrecognized original bitwise.")
endif()
if(CMAKE_BUILD_TYPE)
    message(STATUS "Building with a ${CMAKE_BUILD_TYPE} configuration.")
endif()

# Control library linkage mode
if (NV_SHARED_REPLAY_LIB)
    set(ReplayExecutorLibraryType "SHARED")
    set(NV_REPLAY_LIB_TYPE "NV_REPLAY_LIB_SHARED")
else()
    if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.13")
        # Using object-library to prevent a few size-limitation issues. CMake v3.13 is required
        # because target_link_libraries is supported by object-library since then.
        set(ReplayExecutorLibraryType "OBJECT")
    else()
        set(ReplayExecutorLibraryType "STATIC")
    endif()
    set(NV_REPLAY_LIB_TYPE "NV_REPLAY_LIB_STATIC")
endif()

################################################################################
# Global Compiler Options
################################################################################
if(${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined")
    set(CMAKE_MODULE_LINKER_FLAGS "-Wl,--no-undefined")
    set(CMAKE_EXE_LINKER_FLAGS "-Wl,--no-undefined")
endif()

################################################################################
# Replay Executor (library)
################################################################################

add_library(ReplayExecutor ${ReplayExecutorLibraryType}
    Application.cpp
    CommonReplay.cpp
    D3D11Replay.cpp
    DXGIReplay.cpp
    DataScope.cpp
    Helpers.cpp
    ReadOnlyDatabase.cpp
    ThreadPool.cpp
    Threading.cpp
)

target_include_directories(ReplayExecutor PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    include)

# The platform include may have old/incompatible Vulkan headers, hence they need to be put
# after the local include
if(NV_TARGET_PLATFORM STREQUAL "LINUX_EMBEDDED")
    target_include_directories(ReplayExecutor
        PUBLIC
            ${NV_LINUX_EMBEDDED_INC_DIR}
    )
elseif(NV_TARGET_PLATFORM STREQUAL "QNX")
    target_include_directories(ReplayExecutor
        PUBLIC
            ${NV_QNX_INC_DIR}
    )
endif()

set(NV_USE_AGILITY_SDK_PREPROCESSOR_DEFINITION)
if(NV_USE_AGILITY_SDK)
    set(NV_USE_AGILITY_SDK_PREPROCESSOR_DEFINITION "NV_USE_AGILITY_SDK")
endif()

target_compile_definitions(ReplayExecutor
    PUBLIC
        NV_HAS_FUNCTION_OVERRIDES

        ${NV_USE_AGILITY_SDK_PREPROCESSOR_DEFINITION}
    PRIVATE
        ${NV_REPLAY_LIB_TYPE}
        ReplayExecutor_EXPORTS)


if(NV_TARGET_PLATFORM STREQUAL "WIN32")
    target_compile_options(ReplayExecutor PUBLIC
        -std:c++17
    )
elseif(NV_TARGET_PLATFORM STREQUAL "LINUX_DESKTOP")
    target_compile_options(ReplayExecutor PUBLIC
        -std=c++17
        -fvisibility=hidden
        -Os
        -g
        -O2
        -Werror=return-type)
elseif((NV_TARGET_PLATFORM STREQUAL "LINUX_EMBEDDED") OR (NV_TARGET_PLATFORM STREQUAL "QNX"))
    target_compile_options(ReplayExecutor PUBLIC
        -std=c++17
        -fvisibility=hidden
        -Os
        -g
        -O2
        -fomit-frame-pointer
        -finline-functions
        -finline-limit=300
        -fgcse-after-reload
        -fno-strict-aliasing
        -Wcast-align
        -Wno-unused-variable
        -Werror=return-type
    )
endif()

option(NV_USE_MANAGED_WINSYS "Use replayer managed windowing system" OFF)
if(NV_USE_MANAGED_WINSYS OR NOT NV_BUILD_FOR_ORIGINAL_PLATFORM OR NOT NV_WINSYS STREQUAL NV_ORIGINAL_WINSYS)
    target_compile_definitions(ReplayExecutor PUBLIC NV_USE_MANAGED_WINSYS)
endif()

target_include_directories(ReplayExecutor PUBLIC
)

if(NV_USE_64BIT)
    target_link_libraries(ReplayExecutor
    PRIVATE
)
endif()

if(NV_USE_32BIT)
    target_link_libraries(ReplayExecutor
    PRIVATE
)
endif()

# Specify platform-specific linker flags
if(NV_TARGET_PLATFORM STREQUAL "LINUX_EMBEDDED")
    target_link_libraries(ReplayExecutor
        PUBLIC
            ${NV_LINUX_EMBEDDED_LINKER_FLAGS}
    )
elseif(NV_TARGET_PLATFORM STREQUAL "QNX")
    target_link_libraries(ReplayExecutor
        PUBLIC
            -Wl,-rpath-link=${NV_QNX_DIR}/lib-target
            -Wl,-rpath-link=${NV_QNX_DIR}/lib-target/screen
            -Wl,-rpath-link=${NV_QNX_DIR}/nvidia-bsp/${NV_QNX_ARCH}/usr/lib
    )
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # Remove the default warning level so that it can be replaced below
    string(REPLACE "-Ob1" "" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})

    # -W3     - Warning level 3 (see https://docs.microsoft.com/en-us/cpp/build/reference/compiler-option-warning-level?view=vs-2019)
    # -MP     - Build with multiple processes to speed up the build
    # -Ob2    - Inline expansion level, allows compiler to expand any function not explicitly marked for no inlining
    # -wdXXXX - disable a specific Warning (see https://docs.microsoft.com/en-us/cpp/error-messages/compiler-warnings/compiler-warnings-c4800-through-c4999?view=vs-2019)
    # -bigobj - Increase number of sections in .obj file to a capacity of 4Gb, we have some very large files
    # -GS-    - Disable buffer security check, this is local .exe that is primarily built from generated code and requires full performance
    target_compile_options(ReplayExecutor PUBLIC -W3 -MP $<$<CONFIG:RELEASE>:-Ob2> -wd4351 -wd4819 -bigobj -GS-)

    # -MDd - Defines _DEBUG, _MT, and _DLL for multithreaded debug builds, uses shared run-time library
    target_compile_options(ReplayExecutor PUBLIC $<$<CONFIG:DEBUG>:-MDd>)

    # -MD - Defines _MT and _DLL for multithreaded builds, uses shared run-time library
    # -Oi - Generate instrinsic functions to replace some function calls with instrinsic functions for better performance
    target_compile_options(ReplayExecutor PUBLIC $<$<CONFIG:RELEASE>:-Oi -MD>)

    # /OPT:NOICF - Disable COMDAT folding
    # /OPT:REF - Remove identical comdats
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "/INCREMENTAL:NO /OPT:NOICF /OPT:REF")

    # /STACK: 32 MB stack
    # /WX - Warnings as errors
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /WX /STACK:33554432")

    # /WX - Warnings as errors
    # /Zc:__cplusplus - Enable the __cplusplus preprocessor macro
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /WX /Zc:__cplusplus")
endif()

# Set platform specific properties.
if(NV_USE_WIN32)

    # Windows application & Win32 windowing system
    target_sources(ReplayExecutor
        PRIVATE
            Win32Application.cpp
            WindowSystem_Win32.cpp)
    target_compile_definitions(ReplayExecutor
        PUBLIC
            _CRT_SECURE_NO_DEPRECATE
            NOMINMAX
            NV_USE_WIN32=1
            VK_USE_PLATFORM_WIN32_KHR
            UNICODE
        PRIVATE
            ReplayExecutor_EXPORTS)

endif()

# NGX definitions
if(NV_TARGET_PLATFORM STREQUAL "WIN32")
    target_compile_definitions(ReplayExecutor
        PUBLIC
            NV_NGX_SUPPORTS_D3D
            NV_NGX_SUPPORTS_D3D11
            NV_NGX_SUPPORTS_D3D12
            NV_NGX_SUPPORTS_VULKAN
            NV_NGX_SUPPORTS_CUDA
    )
elseif(NV_TARGET_PLATFORM STREQUAL "LINUX_DESKTOP")
    target_compile_definitions(ReplayExecutor
        PUBLIC
            NV_NGX_SUPPORTS_VULKAN
    )
endif()

if((NV_TARGET_PLATFORM STREQUAL "LINUX_DESKTOP") OR (NV_TARGET_PLATFORM STREQUAL "LINUX_EMBEDDED") OR (NV_TARGET_PLATFORM STREQUAL "QNX"))

    # QNX/Linux application
    if(NV_TARGET_PLATFORM STREQUAL "QNX")
        target_sources(ReplayExecutor
            PRIVATE
                QnxApplication.cpp
        )
    else()
        target_sources(ReplayExecutor
            PRIVATE
                LinuxApplication.cpp
        )
        target_link_libraries(ReplayExecutor
            PRIVATE
                dl
                pthread
        )
    endif()

    # XCB Windowing System
    if(NV_USE_XCB)
        target_sources(ReplayExecutor
            PRIVATE
                WindowSystem_Xcb.cpp)
        target_compile_definitions(ReplayExecutor
            PUBLIC
                NV_USE_XCB=1
                VK_USE_PLATFORM_XCB_KHR)
        target_link_libraries(ReplayExecutor
            PRIVATE
                xcb
                xcb-icccm
        )
    endif()

    # X11 Windowing System
    if(NV_USE_X11)
        target_sources(ReplayExecutor
            PRIVATE
                WindowSystem_X11.cpp)
        target_compile_definitions(ReplayExecutor
            PUBLIC
                NV_USE_X11=1
                VK_USE_PLATFORM_XLIB_KHR)
        target_link_libraries(ReplayExecutor
            PRIVATE
                X11
                Xau
        )
    endif()

    # D2D Windowing System
    if(NV_USE_D2D)
        target_sources(ReplayExecutor
            PRIVATE
                WindowSystem_Null.cpp)
        target_compile_definitions(ReplayExecutor
            PUBLIC
                NV_USE_D2D=1
                VK_USE_PLATFORM_D2D_KHR
        )
    endif()

    # Wayland Windowing System
    if(NV_USE_WAYLAND)
        target_sources(ReplayExecutor
            PRIVATE
                WindowSystem_Wayland.cpp
        )
        target_compile_definitions(ReplayExecutor
            PUBLIC
                NV_USE_WAYLAND=1
                VK_USE_PLATFORM_WAYLAND_KHR
        )
        target_link_libraries(ReplayExecutor
            PRIVATE
                xkbcommon
                wayland-client
                wayland-egl
        )
    endif()

    # EGL Device Windowing System
    if(NV_USE_EGL_DEVICE)
        target_sources(ReplayExecutor
            PRIVATE
                WindowSystem_Egldevice.cpp
        )
        target_compile_definitions(ReplayExecutor
            PUBLIC
                NV_USE_EGL_DEVICE=1
        )
    endif()

    # Screen Windowing System
    if(NV_USE_SCREEN)
        target_sources(ReplayExecutor
            PRIVATE
                WindowSystem_Screen.cpp
        )
        target_link_libraries(ReplayExecutor
            PRIVATE
                screen
        )
    endif()

    # NvSci Windowing System
    if(NV_USE_NVSCI)
        target_sources(ReplayExecutor
            PRIVATE
                WindowSystem_Null.cpp
        )
        target_compile_definitions(ReplayExecutor
            PUBLIC
                NV_USE_NVSCI=1
                VK_USE_PLATFORM_SCI
        )
    endif()

endif()

################################################################################
# Generated Replay (library)
################################################################################

add_library(GeneratedReplay ${ReplayExecutorLibraryType}
    Frame0Part00.cpp
    Frame0Part01.cpp
    Frame0Part02.cpp
    Frame0Part03.cpp
    Frame0Part04.cpp
    Frame0Part05.cpp
    Frame0Part06.cpp
    Frame0Part07.cpp
    Frame0Part08.cpp
    FrameReset00.cpp
    FrameSetup00.cpp
    FrameSetup01.cpp
    PerfMarkersReset.cpp
    PerfMarkersSetup.cpp
    ReplayProcedures.cpp
    Resources00.cpp
    Resources01.cpp
    Resources02.cpp
    Resources03.cpp
    WinResourcesReset.cpp
    WinResourcesSetup.cpp
    function_overrides.cpp
)

target_include_directories(GeneratedReplay
    PRIVATE
        include)

target_link_libraries(GeneratedReplay
    PRIVATE
        ReplayExecutor
    d3d11.lib
    d3d9.lib
    dxgi.lib
)

target_compile_definitions(GeneratedReplay
    PUBLIC
        ${NV_REPLAY_LIB_TYPE})

if(NV_USE_WIN32)
    target_compile_definitions(GeneratedReplay
        PUBLIC
            _CRT_SECURE_NO_DEPRECATE
            NV_USE_WIN32=1
            VK_USE_PLATFORM_WIN32_KHR)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(GeneratedReplay
        PRIVATE
            -bigobj
            -GS-
    )
endif()

################################################################################
# Main (executable)
################################################################################

add_executable(Main
    Main.cpp
)

set_target_properties(Main PROPERTIES OUTPUT_NAME ${CPP_OUTPUT_NAME})
set_directory_properties(PROPERTY VS_STARTUP_PROJECT Main)

if(NV_TARGET_PLATFORM STREQUAL "WIN32")
    target_compile_definitions(Main
        PRIVATE
            NOMINMAX)
endif()

if((NV_TARGET_PLATFORM STREQUAL "LINUX_DESKTOP") OR (NV_TARGET_PLATFORM STREQUAL "LINUX_EMBEDDED"))
    target_link_libraries(Main
        PRIVATE
            pthread)
endif()

# Dynamic DLL dependency
add_dependencies(Main GeneratedReplay)

# Link libraries
target_link_libraries(Main
    PRIVATE
        ReplayExecutor)

# Static link the generate replay for the non-shared (e.g. static build)
if (NOT NV_SHARED_REPLAY_LIB)
    target_link_libraries(Main PRIVATE
        GeneratedReplay)
endif()

################################################################################
# Install
################################################################################

# Install targets
if(NOT NV_INSTALL_FOLDER)
    set(NV_INSTALL_FOLDER bin)
endif()
install(TARGETS Main RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/${NV_INSTALL_FOLDER}/)

if(NV_SHARED_REPLAY_LIB)
    if(NV_TARGET_PLATFORM STREQUAL "WIN32")
        install(TARGETS GeneratedReplay RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/${NV_INSTALL_FOLDER}/)
        install(TARGETS ReplayExecutor RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/${NV_INSTALL_FOLDER}/)
    else()
        install(TARGETS GeneratedReplay LIBRARY DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/${NV_INSTALL_FOLDER}/)
        install(TARGETS ReplayExecutor LIBRARY DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/${NV_INSTALL_FOLDER}/)
    endif()
endif()

set(RESOURCE_FILES_OR_FOLDERS)

if(NV_USE_64BIT)
    list(APPEND RESOURCE_FILES_OR_FOLDERS
)
endif()

if(NV_USE_32BIT)
    list(APPEND RESOURCE_FILES_OR_FOLDERS
)
endif()

if((NV_TARGET_PLATFORM STREQUAL "LINUX_DESKTOP") OR (NV_TARGET_PLATFORM STREQUAL "LINUX_EMBEDDED"))
    install(PROGRAMS "Linux/run_replay.sh" DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/${NV_INSTALL_FOLDER}/ RENAME "${CPP_OUTPUT_NAME}.sh")
endif()

if(RESOURCE_FILES_OR_FOLDERS)
    set(RESOURCES)
    foreach(FILE_OR_FOLDER ${RESOURCE_FILES_OR_FOLDERS})

        # The behavior of "IS_DIRECTORY" is well-defined only for full paths.
        get_filename_component(ABSOLUTE_FILE_OR_FOLDER "${FILE_OR_FOLDER}" ABSOLUTE)

        if(IS_DIRECTORY ${ABSOLUTE_FILE_OR_FOLDER})
            file(GLOB SUB_FILES ${ABSOLUTE_FILE_OR_FOLDER}/*.*)
            list(APPEND RESOURCES ${SUB_FILES})
        else()
            list(APPEND RESOURCES ${FILE_OR_FOLDER})
        endif()
    endforeach()
    install(FILES ${RESOURCES} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/${NV_INSTALL_FOLDER}/)
endif()

if(NV_USE_AGILITY_SDK)
    set(AGILITY_SDK_FILES)
    list(APPEND AGILITY_SDK_FILES
)

    set(RESOURCES)
    foreach(FILE_OR_FOLDER ${AGILITY_SDK_FILES})

        # The behavior of "IS_DIRECTORY" is well-defined only for full paths.
        get_filename_component(ABSOLUTE_FILE_OR_FOLDER "${FILE_OR_FOLDER}" ABSOLUTE)

        if(IS_DIRECTORY ${ABSOLUTE_FILE_OR_FOLDER})
            file(GLOB SUB_FILES ${ABSOLUTE_FILE_OR_FOLDER}/*.*)
            list(APPEND RESOURCES ${SUB_FILES})
        else()
            list(APPEND RESOURCES ${FILE_OR_FOLDER})
        endif()
    endforeach()
    install(FILES ${RESOURCES} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/${NV_INSTALL_FOLDER}/AgilitySDK/)
endif()

################################################################################
# User defined MARCO
################################################################################

if (DEFINED EXTRA_DEFINITIONS)
    message(STATUS "Using extra definitions: ${EXTRA_DEFINITIONS}")
    add_definitions(-D${EXTRA_DEFINITIONS})
endif()

