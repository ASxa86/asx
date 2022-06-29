project(asx-core)

add_library(${PROJECT_NAME})


target_sources(${PROJECT_NAME} PRIVATE
	${PROJECT_INCLUDE_DIR}/asx/core/Properties.h
	${PROJECT_INCLUDE_DIR}/asx/core/Property.h
)

target_sources(${PROJECT_NAME} PRIVATE
	Properties.cpp
	Property.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
	asx-string
)

project_install_target()
project_compile_options()
project_gen_export()
