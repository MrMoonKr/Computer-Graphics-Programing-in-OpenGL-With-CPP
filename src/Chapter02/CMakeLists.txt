cmake_minimum_required( VERSION 3.30 )


# 프로젝트 설정

project( Chapter02 
    VERSION 1.0
    DESCRIPTION "Chapter 02"
    LANGUAGES CXX
)


# 헬퍼 함수

function( my_executable target_name )
    add_executable( ${target_name} ${target_name}.cpp )
    target_link_libraries( ${target_name} PRIVATE glad::glad )
    target_link_libraries( ${target_name} PRIVATE glfw )
endfunction()


# 타겟 설정

my_executable( Program02_01 )
my_executable( Program02_02 )
my_executable( Program02_03 )
my_executable( Program02_04 )
my_executable( Program02_05 )
my_executable( Program02_06 )


# 에셋 복사

file( COPY ${CMAKE_SOURCE_DIR}/data DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Debug" )

