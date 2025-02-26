cmake_minimum_required( VERSION 3.30 )

project( Chapter01 
    VERSION 1.0
    DESCRIPTION "Chapter 01"
    LANGUAGES CXX
)


add_executable( Ch01-01-HelloCPP Ch01-01-HelloCPP.cpp )

add_executable( Ch01-02-HelloGLFW Ch01-02-HelloGLFW.cpp )
target_link_libraries( Ch01-02-HelloGLFW PRIVATE glad::glad )
target_link_libraries( Ch01-02-HelloGLFW PRIVATE glfw )

add_executable( Ch01-03-GLFWApp Ch01-03-GLFWApp.cpp )
target_link_libraries( Ch01-03-GLFWApp PRIVATE glad::glad )
target_link_libraries( Ch01-03-GLFWApp PRIVATE glfw )


# add_executable( program_2_1 program_2_1.cpp )
# target_link_libraries( program_2_1 PRIVATE GLEW::GLEW )
# target_link_libraries( program_2_1 PRIVATE GLUT::GLUT )
# target_link_libraries( program_2_1 PRIVATE $<IF:$<TARGET_EXISTS:FreeGLUT::freeglut>,FreeGLUT::freeglut,FreeGLUT::freeglut_static>)
# target_link_libraries( program_2_1 PRIVATE glad::glad )
# target_link_libraries( program_2_1 PRIVATE glfw )

# add_executable( ch02-square-glfw ch02-square-glfw.cpp )
# target_link_libraries( ch02-square-glfw PRIVATE GLEW::GLEW )
# # target_link_libraries( ch02-square-glfw PRIVATE GLUT::GLUT )
# # target_link_libraries( ch02-square-glfw PRIVATE $<IF:$<TARGET_EXISTS:FreeGLUT::freeglut>,FreeGLUT::freeglut,FreeGLUT::freeglut_static>)
# target_link_libraries( ch02-square-glfw PRIVATE glfw )

# add_executable( ch02-circle ch02-circle.cpp )
# target_link_libraries( ch02-circle PRIVATE GLEW::GLEW )
# target_link_libraries( ch02-circle PRIVATE GLUT::GLUT )
# target_link_libraries( ch02-circle PRIVATE $<IF:$<TARGET_EXISTS:FreeGLUT::freeglut>,FreeGLUT::freeglut,FreeGLUT::freeglut_static>)


set_target_properties( Ch01-01-HelloCPP
    Ch01-02-HelloGLFW
    Ch01-03-GLFWApp
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/msvc/Debug/Chapter01"
)

