project(test-asx-type)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
	TypeInfo.test.cpp
	TypeTraits.test.cpp
)

find_package(GTest CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE
	GTest::gtest_main
	GTest::gtest
)

project_install_target()
project_compile_options()
