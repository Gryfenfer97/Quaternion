cmake_minimum_required(VERSION 3.16)

project(Quaternions VERSION 0.1)


add_library(${PROJECT_NAME} INTERFACE)
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

target_include_directories(${PROJECT_NAME} INTERFACE include)


set_target_properties(
  ${PROJECT_NAME}  
  PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)


option(BUILD_TESTS  "build all the units test" On)

if(BUILD_TESTS)
    message("Building tests...")
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
    add_subdirectory(tests)
endif()
