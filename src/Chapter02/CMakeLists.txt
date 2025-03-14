cmake_minimum_required( VERSION 3.30 )


# 프로젝트 설정

project( Chapter02 
    VERSION 1.0
    DESCRIPTION "Chapter 02"
    LANGUAGES CXX
)


# 타겟 설정

add_executable( Program02_01 Program02_01.cpp )
target_link_libraries( Program02_01 PRIVATE glad::glad glfw )

add_executable( Program02_02 Program02_02.cpp )
target_link_libraries( Program02_02 PRIVATE glad::glad glfw )

add_executable( Program02_03 Program02_03.cpp )
target_link_libraries( Program02_03 PRIVATE glad::glad glfw )

add_executable( Program02_04 Program02_04.cpp )
target_link_libraries( Program02_04 PRIVATE glad::glad glfw )

add_executable( Program02_05 Program02_05.cpp )
target_link_libraries( Program02_05 PRIVATE glad::glad glfw )

add_executable( Program02_06 Program02_06.cpp Utils.h Utils.cpp )
target_link_libraries( Program02_06 PRIVATE glad::glad glfw soil2 )

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


# 출력 경로 설정

set_target_properties( Program02_01
    Program02_02
    Program02_03
    Program02_04
    Program02_05
    Program02_06
    program_2_2
    program_2_3
    program_2_4
    program_2_5
    program_2_6
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/msvc/Debug/Chapter02"
)


# 에셋 복사

file( COPY ${CMAKE_SOURCE_DIR}/data DESTINATION "${CMAKE_SOURCE_DIR}/bin/msvc/Debug/Chapter02" )

