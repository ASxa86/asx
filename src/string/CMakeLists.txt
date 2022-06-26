project(asx-string)

add_library(${PROJECT_NAME})


target_sources(${PROJECT_NAME} PRIVATE
	${PROJECT_INCLUDE_DIR}/asx/string/StringConv.h
)

target_sources(${PROJECT_NAME} PRIVATE
	StringConv.cpp
)

find_package(magic_enum CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE
	magic_enum::magic_enum
	nlohmann_json::nlohmann_json
)

project_install_target()
project_compile_options()
project_gen_export()
