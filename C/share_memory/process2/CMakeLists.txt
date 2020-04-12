SET(TARGET_NAME "process2")

file(GLOB process2_all_srcs
    LIST_DIRECTORIES false
    "${CMAKE_CURRENT_SOURCE_DIR}/*c"
    )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)
include_directories(${PROJECT_SOURCE_DIR}/shm_lib/)

set_source_files_properties(${TARGET_NAME}, PROPERTIES, LANGUAGE, C)

add_executable(${TARGET_NAME} ${process2_all_srcs})

target_link_libraries(${TARGET_NAME}
    shmLib
)