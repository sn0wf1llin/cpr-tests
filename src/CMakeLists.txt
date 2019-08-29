cmake_minimum_required(VERSION 3.10)
project(undetected)

set(CMAKE_CXX_STANDARD 11)

SET( PROJECT_SOURCE_DIR "/home/nn5h/CLionProjects/undetected" )
SET( INCLUDE_LIBS_DIR "${PROJECT_SOURCE_DIR}/include/libs" )
SET( SOURCE_DIR "${PROJECT_SOURCE_DIR}/src" )
SET( CURL_INCLUDE_DIR "/usr/lib/x86_64-linux-gnu" )
SET( FMT_INCLUDE_DIR "/usr/local/include" )

SET( EXECUTABLE main )

INCLUDE_DIRECTORIES( ${CURL_INCLUDE_DIR} )
INCLUDE_DIRECTORIES( ${FMT_INCLUDE_DIR} )
INCLUDE_DIRECTORIES( ${INCLUDE_LIBS_DIR} )
INCLUDE_DIRECTORIES( ${INCLUDE_LIBS_DIR}/cpr )

ADD_EXECUTABLE( ${EXECUTABLE} main.cpp shared/networkOperations.cpp collectSystemData.cpp shared/Helper.cpp pawn.cpp shared/PRNG.cpp )

LINK_LIBRARIES( curl )
LINK_LIBRARIES( fmt )

ADD_LIBRARY( cpr_lib ${INCLUDE_LIBS_DIR}/cpr/cpr/auth.cpp ${INCLUDE_LIBS_DIR}/cpr/cpr/cookies.cpp ${INCLUDE_LIBS_DIR}/cpr/cpr/cprtypes.cpp ${INCLUDE_LIBS_DIR}/cpr/cpr/digest.cpp ${INCLUDE_LIBS_DIR}/cpr/cpr/error.cpp ${INCLUDE_LIBS_DIR}/cpr/cpr/multipart.cpp ${INCLUDE_LIBS_DIR}/cpr/cpr/parameters.cpp ${INCLUDE_LIBS_DIR}/cpr/cpr/payload.cpp ${INCLUDE_LIBS_DIR}/cpr/cpr/proxies.cpp ${INCLUDE_LIBS_DIR}/cpr/cpr/session.cpp ${INCLUDE_LIBS_DIR}/cpr/cpr/ssl_options.cpp ${INCLUDE_LIBS_DIR}/cpr/cpr/timeout.cpp ${INCLUDE_LIBS_DIR}/cpr/cpr/util.cpp )
TARGET_LINK_LIBRARIES( ${EXECUTABLE} ${CURL_LIBRARIES} )
TARGET_LINK_LIBRARIES( ${EXECUTABLE} cpr_lib )
