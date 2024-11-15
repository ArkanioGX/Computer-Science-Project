file( GLOB Codility_SOURCES "*.cpp" "*.h" )
add_library( Codility ${Codility_SOURCES})
target_include_directories(Codility PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
