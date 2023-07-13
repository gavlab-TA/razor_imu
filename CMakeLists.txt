cmake_minimum_required(VERSION 3.0)

project(razor_imu_serial)

find_package(serial)

add_executable(test src/test.cpp src/razor_imu/razor_imu_serial.cpp)
target_link_libraries(test ${SERIAL_LIBS})

add_library(razor_imu_serial SHARED 
    src/razor_imu/razor_imu_serial.cpp
    src/razor_imu/razor_imu_serial.hpp
)

include(CMakePackageConfigHelpers)

configure_package_config_file(razor_imu_serialConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/razor_imu_serialConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/razor_imu_serial)

install(TARGETS razor_imu_serial DESTINATION /usr/local/lib/razor_imu_serial)
install(FILES src/razor_imu/razor_imu_serial.hpp DESTINATION /usr/local/include/razor_imu_serial)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/razor_imu_serialConfig.cmake DESTINATION /usr/local/lib/cmake/razor_imu_serial)
