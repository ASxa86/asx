project(asx-type)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
	${PROJECT_INCLUDE_DIR}/asx/type/TypeName.h
	${PROJECT_INCLUDE_DIR}/asx/type/TypeTraits.h
)

target_sources(${PROJECT_NAME} PRIVATE
	TypeName.cpp
)

project_install_target()
project_compile_options()
project_gen_export()
