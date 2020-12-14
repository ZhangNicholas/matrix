cmake_minimum_required(VERSION 3.5)

if($ENV{TRAVIS_BUILD_NUMBER})
	project(matrix VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
	project(matrix VERSION 0.0.1)
endif()

set(CMAKE_CXX_STANDARD 14)
find_package(GTest REQUIRED)

set(SOURCES main.cpp
)

# Main target
add_executable(matrix ${SOURCES})

add_executable(
	tests
	test/tests.cpp
)

set_target_properties(matrix tests PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
)

target_include_directories(
	matrix
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/includes"
)

target_include_directories(
	tests
	PRIVATE ${GTEST_INCLUDE_DIRS}
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src"
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/includes"
)

target_link_libraries(
	tests PRIVATE
	${GTEST_BOTH_LIBRARIES}
)

if (MSVC)
	# @see https://github.com/google/googletest/blob/master/googletest/README.md
	# Visual Studio Dynamic vs Static Runtimes
	#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

	target_compile_options(
		matrix PRIVATE
		/WX
	)
	target_compile_options(
	tests PRIVATE
	/WX
	)
else ()
	target_compile_options(
		matrix PRIVATE
		-Wall -Wextra -pedantic -Werror
	)
	target_compile_options(
		tests PRIVATE
		-Wall -Wextra -pedantic -Werror
	)
endif()

install(TARGETS matrix RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT cnickol@gmail.com)

include(CPack)

enable_testing()

add_test(tests tests) 