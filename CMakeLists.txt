cmake_minimum_required(VERSION 3.13)
project(TestMagick)

if(CMAKE_TOOLCHAIN_FILE)
	string(FIND "${CMAKE_TOOLCHAIN_FILE}" "vcpkg.cmake" VCPKG_FOUND)
	if(VCPKG_FOUND)
		message(STATUS "Using vcpkg toolchain: ${CMAKE_TOOLCHAIN_FILE}")
		set(DEPENDS_FROM_VCPKG ON)
	endif()
else()
	if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
		include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
		conan_basic_setup(TARGETS)
		set(DEPENDS_FROM_CONAN ON)
	endif()
endif()

add_executable(TestMagick test-magick.cpp)

if(DEPENDS_FROM_VCPKG)
	find_package(unofficial-graphicsmagick CONFIG REQUIRED)
	target_link_libraries(TestMagick PRIVATE unofficial::graphicsmagick::graphicsmagick)
endif()

if (DEPENDS_FROM_CONAN)
	target_link_libraries(TestMagick PRIVATE CONAN_PKG::imagemagick)
endif()

