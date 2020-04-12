SET(TARGET_NAME "shmLib")

file(GLOB process1_all_hdrs
    LIST_DIRECTORIES false
    "${CMAKE_CURRENT_SOURCE_DIR}/*h"
    )

file(GLOB shmLib_all_srcs
    LIST_DIRECTORIES false
    "${CMAKE_CURRENT_SOURCE_DIR}/*cpp"
    )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)

add_library(${TARGET_NAME} SHARED ${shmLib_all_srcs})
