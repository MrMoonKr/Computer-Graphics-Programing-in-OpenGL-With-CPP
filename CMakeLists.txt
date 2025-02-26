cmake_minimum_required( VERSION 3.30 )

set( VCPKG_TARGET_TRIPLET "x64-windows" CACHE STRING "" )
set( CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "" )
# set( VCPKG_TARGET_TRIPLET "x64-mingw-dynamic" CACHE STRING "" )
# set( CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "" )

project( ComputerGraphicsProgrammingInOpenGLWithCPP
    VERSION 1.0
    DESCRIPTION "Computer Graphics Programming in OpenGL with C++ 3rd Edition"
    LANGUAGES CXX
)

set( CMAKE_CXX_STANDARD 17 )

find_package( fmt CONFIG REQUIRED )
# target_link_libraries( main PRIVATE fmt::fmt )
find_package( httplib CONFIG REQUIRED )
# target_link_libraries( main PRIVATE httplib::httplib )
find_package( CURL REQUIRED )
# target_link_libraries( main PRIVATE CURL::libcurl )
find_package( nlohmann_json CONFIG REQUIRED )
# target_link_libraries( main PRIVATE nlohmann_json::nlohmann_json )
find_package( glfw3 CONFIG REQUIRED )
# target_link_libraries( main PRIVATE glfw )
find_package( imgui CONFIG REQUIRED )
# target_link_libraries( main PRIVATE imgui::imgui )
find_package( Stb REQUIRED )
# target_include_directories( main PRIVATE ${Stb_INCLUDE_DIR} )

find_package( GLEW REQUIRED )
# target_link_libraries( main PRIVATE GLEW::GLEW )
find_package( GLUT REQUIRED )
# target_link_libraries( main PRIVATE GLUT::GLUT )
find_package( FreeGLUT CONFIG REQUIRED )
# target_link_libraries( main PRIVATE $<IF:$<TARGET_EXISTS:FreeGLUT::freeglut>,FreeGLUT::freeglut,FreeGLUT::freeglut_static> )
find_package( FTGL CONFIG REQUIRED )
# target_link_libraries( main PRIVATE ftgl )

find_package( glm CONFIG REQUIRED )
# target_link_libraries( main PRIVATE glm::glm )
# target_link_libraries( main PRIVATE glm::glm-header-only )

find_package( glad CONFIG REQUIRED )
# target_link_libraries( main PRIVATE glad::glad )

# add_subdirectory( "src" )
add_subdirectory( "src/Chapter01" )
add_subdirectory( "src/Chapter02" )
add_subdirectory( "src/Chapter03" )


