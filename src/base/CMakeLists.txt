include_directories( "include" )
file( GLOB SOURCES "src/*.cpp")

add_library( CIGA-Base SHARED STATIC ${SOURCES})

# install( TARGETS CIGA-Base DESTINATION lib )
   

