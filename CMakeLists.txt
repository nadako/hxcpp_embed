cmake_minimum_required(VERSION 3.1)

project(hello CXX)

add_compile_definitions(
	HX_WINDOWS
	HXCPP_API_LEVEL=400
	HXCPP_VISIT_ALLOCS
)

include_directories(
	cpp_gen/include
	hxcpp/include
)

file(GLOB_RECURSE project_srcs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
	cpp_gen/src/*.cpp
)

list(REMOVE_ITEM project_srcs
	cpp_gen/src/__main__.cpp
)

add_executable(hello
	hxcpp/src/hx/gc/GcCommon.cpp
	hxcpp/src/hx/gc/GcRegCapture.cpp
	hxcpp/src/hx/gc/Immix.cpp
	hxcpp/src/hx/Object.cpp
	hxcpp/src/hx/Anon.cpp
	hxcpp/src/hx/Hash.cpp
	hxcpp/src/hx/Class.cpp
	hxcpp/src/hx/Debug.cpp
	hxcpp/src/hx/Thread.cpp
	hxcpp/src/hx/StdLibs.cpp
	hxcpp/src/hx/Boot.cpp
	hxcpp/src/String.cpp
	hxcpp/src/Dynamic.cpp
	hxcpp/src/Array.cpp
	hxcpp/src/Enum.cpp
	hxcpp/src/Math.cpp
	cpp_gen/src/__lib__.cpp
	${project_srcs}
	cpp_src/main.cpp
)
