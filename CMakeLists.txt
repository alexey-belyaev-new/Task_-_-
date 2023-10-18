cmake_minimum_required(VERSION 3.0)

project(Task)

set(HEADERS
	IdentifierGroup.h
	Identifier.h)

SET(SOURCE
	Test1_v2.cpp
	IdentifierGroup.cpp
	Identifier.cpp)

add_executable(test ${SOURCE} ${HEADERS})

set_target_properties(
	test PROPERTIES
	CXX_STANDART 17
	CXX_STANDART_REQUIRED ON
)