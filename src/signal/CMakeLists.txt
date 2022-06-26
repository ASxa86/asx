project(asx-signal)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
	${PROJECT_INCLUDE_DIR}/asx/signal/Connection.h
	${PROJECT_INCLUDE_DIR}/asx/signal/ConnectionShared.h
	${PROJECT_INCLUDE_DIR}/asx/signal/ConnectionUnique.h
	${PROJECT_INCLUDE_DIR}/asx/signal/Signal.h
	${PROJECT_INCLUDE_DIR}/asx/signal/Slot.h
)

target_sources(${PROJECT_NAME} PRIVATE
	Connection.cpp
	ConnectionShared.cpp
	ConnectionUnique.cpp
	Signal.cpp
)

project_install_target()
project_compile_options()
project_gen_export()
