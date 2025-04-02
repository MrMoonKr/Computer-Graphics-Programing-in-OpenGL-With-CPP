cmake_minimum_required( VERSION 3.30 )


# 프로젝트

project( Chapter00 
    LANGUAGES CXX
    VERSION 1.0.0
    DESCRIPTION "Chapter 00"
)


# 헬퍼 함수

function( my_executable target_name )
    add_executable( ${target_name} ${target_name}.cpp )
    target_link_libraries( ${target_name} PRIVATE glad::glad )
    target_link_libraries( ${target_name} PRIVATE glfw )
endfunction()


# 타겟

my_executable( Program00_01 )

