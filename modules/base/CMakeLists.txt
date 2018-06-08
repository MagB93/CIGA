project( ciga-base C CXX )

include_directories( "include/base"  )

add_library( base INTERFACE )

target_link_libraries( base INTERFACE armadillo )

target_include_directories( base INTERFACE include/)

# install( TARGETS base DESTINATION lib )
