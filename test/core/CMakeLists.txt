project(test-asx-core)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
	Factory.test.cpp
	Properties.test.cpp
)

find_package(GTest CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE
	asx-core
	GTest::gtest_main
	GTest::gtest
)

project_install_target()
project_compile_options()
