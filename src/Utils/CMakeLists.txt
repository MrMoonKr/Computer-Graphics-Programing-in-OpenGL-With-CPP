# Utils Library

set( target Utils )

set( target_SOURCES
    GLApp.cpp GLApp.h
    GLAppState.cpp GLAppState.h
    Utils.cpp Utils.h
)

add_library( ${target} STATIC 
    ${target_SOURCES}
)

target_link_libraries( ${target} PUBLIC
    glad::glad
    glfw
    glm::glm
    imgui::imgui
    soil2
)

