cmake_minimum_required(VERSION 3.15)
project(ComputerScience VERSION 0.1.0)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

include(CTest)
enable_testing()

# subdirectories
add_subdirectory(src/Codility)
add_subdirectory(src/CityTravel)


# Executable and link
add_executable(ComputerScience src/main.cpp)
target_link_libraries(ComputerScience CityTravel Codility)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)