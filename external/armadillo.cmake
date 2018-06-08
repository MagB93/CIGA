cmake_minimum_required( VERSION 2.8.2 )

project( armadillo-download NONE )

include(ExternalProject)
ExternalProject_Add( armadillo
  GIT_REPOSITORY https://gitlab.com/conradsnicta/armadillo-code.git
  GIT_TAG 8.500.x
  SOURCE_DIR "${CMAKE_BINARY_DIR}/armadillo-src"
  BINARY_DIR "${CMAKE_BINARY_DIR}/armadillo-build"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  INSTALL_COMMAND ""
  TEST_COMMAND ""

  )
