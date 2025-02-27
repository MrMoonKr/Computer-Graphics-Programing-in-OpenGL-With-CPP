cmake_minimum_required( VERSION 3.30 )


# 프로젝트 설정

project( Chapter01 
    VERSION 1.0
    DESCRIPTION "Chapter 01"
    LANGUAGES CXX
)


# 타겟 설정

add_executable( Ch01-01-HelloCPP Ch01-01-HelloCPP.cpp )

add_executable( Ch01-02-HelloGLFW Ch01-02-HelloGLFW.cpp )
target_link_libraries( Ch01-02-HelloGLFW PRIVATE glad::glad )
target_link_libraries( Ch01-02-HelloGLFW PRIVATE glfw )

add_executable( Ch01-03-GLFWApp Ch01-03-GLFWApp.cpp )
target_link_libraries( Ch01-03-GLFWApp PRIVATE glad::glad )
target_link_libraries( Ch01-03-GLFWApp PRIVATE glfw )

# 출력 경로 설정

set_target_properties( Ch01-01-HelloCPP
    Ch01-02-HelloGLFW
    Ch01-03-GLFWApp
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/msvc/Debug/Chapter01"
)

