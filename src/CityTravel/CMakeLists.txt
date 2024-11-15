file( GLOB CityTravel_SOURCES *.cpp )
add_library( CityTravel ${CityTravel_SOURCES})
target_include_directories(CityTravel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
