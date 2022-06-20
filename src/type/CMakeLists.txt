project(asx-type)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME} INTERFACE
	${PROJECT_INCLUDE_DIR}/asx/type/TypeInfo.h
	${PROJECT_INCLUDE_DIR}/asx/type/TypeTraits.h
)

project_install_target()
project_compile_options()
project_gen_export()
