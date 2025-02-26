cmake_minimum_required( VERSION 3.30 )

project( Chapter02 
    VERSION 1.0
    DESCRIPTION "Chapter 02"
    LANGUAGES CXX
)


add_executable( program_2_1 program_2_1.cpp )
target_link_libraries( program_2_1 PRIVATE glad::glad )
target_link_libraries( program_2_1 PRIVATE glfw )

add_executable( program_2_2 program_2_2.cpp )
target_link_libraries( program_2_2 PRIVATE glad::glad )
target_link_libraries( program_2_2 PRIVATE glfw )

add_executable( program_2_3 program_2_3.cpp )
target_link_libraries( program_2_3 PRIVATE glad::glad )
target_link_libraries( program_2_3 PRIVATE glfw )

add_executable( program_2_4 program_2_4.cpp )
target_link_libraries( program_2_4 PRIVATE glad::glad )
target_link_libraries( program_2_4 PRIVATE glfw )

add_executable( program_2_5 program_2_5.cpp )
target_link_libraries( program_2_5 PRIVATE glad::glad )
target_link_libraries( program_2_5 PRIVATE glfw )

add_executable( program_2_6 program_2_6.cpp )
target_link_libraries( program_2_6 PRIVATE glad::glad )
target_link_libraries( program_2_6 PRIVATE glfw )



set_target_properties( program_2_1 
    program_2_2
    program_2_3
    program_2_4
    program_2_5
    program_2_6
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/msvc/Debug/Chapter02"
)

file( COPY ${CMAKE_SOURCE_DIR}/data DESTINATION "${CMAKE_SOURCE_DIR}/bin/msvc/Debug/Chapter02" )

