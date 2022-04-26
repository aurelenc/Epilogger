set (INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/Src)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/Src)

set (SRC
    ${SRC_ROOT}/LoggableException.cpp
    ${SRC_ROOT}/LoggableException.hpp
    ${SRC_ROOT}/Logger.cpp
    ${SRC_ROOT}/Logger.hpp
)

add_library(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC INCLUDE_ROOT)

set_target_properties(${PROJECT_NAME} PROPERTIES
    PREFIX ""
    ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)