cmake_minimum_required( VERSION 3.30 )


# 프로젝트 설정

project( Chapter04
    VERSION 1.0
    DESCRIPTION "Chapter 04"
    LANGUAGES CXX
)


# 헬퍼 함수

function( my_executable target_name )
    add_executable( ${target_name} ${target_name}.cpp Utils.cpp Utils.h )
    target_link_libraries( ${target_name} PRIVATE glad::glad )
    target_link_libraries( ${target_name} PRIVATE glfw )
    target_link_libraries( ${target_name} PRIVATE glm::glm )
    target_link_libraries( ${target_name} PRIVATE soil2 )
endfunction()


# 타겟 설정

my_executable( Program04_01 )


# 에셋 복사

file( COPY ${CMAKE_SOURCE_DIR}/data DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Debug" )

