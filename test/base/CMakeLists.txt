project( Base-Tests )

file( GLOB SOURCES *.cpp )
add_executable( base_tests ${SOURCES} )

target_link_libraries( base_tests base gtest_main )
