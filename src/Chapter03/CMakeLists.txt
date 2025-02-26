cmake_minimum_required( VERSION 3.30 )

project( Chapter03 
    VERSION 1.0
    DESCRIPTION "Chapter 03"
    LANGUAGES CXX
)


add_executable( program_3_1 program_3_1.cpp )
target_link_libraries( program_3_1 PRIVATE glad::glad )
target_link_libraries( program_3_1 PRIVATE glfw )




set_target_properties( program_3_1 
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/msvc/Debug/Chapter03"
)

file( COPY ${CMAKE_SOURCE_DIR}/data DESTINATION "${CMAKE_SOURCE_DIR}/bin/msvc/Debug/Chapter03" )

