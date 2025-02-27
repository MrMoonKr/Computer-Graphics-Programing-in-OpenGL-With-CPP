cmake_minimum_required( VERSION 3.30 )


# 프로젝트 설정

project( Chapter03 
    VERSION 1.0
    DESCRIPTION "Chapter 03"
    LANGUAGES CXX
)


# 타겟 설정

add_executable( program_3_1 program_3_1.cpp )
target_link_libraries( program_3_1 PRIVATE glad::glad )
target_link_libraries( program_3_1 PRIVATE glfw )

add_executable( program_3_2 program_3_2.cpp )
target_link_libraries( program_3_2 PRIVATE glad::glad )
target_link_libraries( program_3_2 PRIVATE glfw )
target_link_libraries( program_3_2 PRIVATE ftgl )

add_executable( program_3_3 program_3_3.cpp )
#target_link_libraries( program_3_3 PRIVATE glad::glad )
target_link_libraries( program_3_3 PRIVATE GLEW::GLEW )
target_link_libraries( program_3_3 PRIVATE glfw )
target_link_libraries( program_3_3 PRIVATE ftgl )


# 출력 경로 설정

set_target_properties( program_3_1 
    program_3_2
    program_3_3
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/msvc/Debug/Chapter03"
)


# 에셋 복사

file( COPY ${CMAKE_SOURCE_DIR}/data DESTINATION "${CMAKE_SOURCE_DIR}/bin/msvc/Debug/Chapter03" )

