cmake_minimum_required (VERSION 2.8.12)

# add c++11 standard to compiler
add_compile_options(-std=c++11)

project(HS)

set(BINDIR ${PROJECT_BINARY_DIR})
set(SRCDIR ${PROJECT_SOURCE_DIR})

set(GAME_TITLE "Historical Smackdown")
set(GAME_VERSION_MAJOR 0)
set(GAME_VERSION_MINOR 1)
set(GAME_VERSION_RELEASE pre-alpha)


configure_file(
	"${SRCDIR}/config.h.in"
	"${BINDIR}/config.h"
)
include_directories("${BINDIR}")

file(GLOB_RECURSE SRC_FILES
    GLOB_CPP_PATTERNS src/*.cpp 
    GLOB_H_PATTERNS include/*.h RECURSE_GROUP
)

set(EXE_NAME "HS")
add_executable(${EXE_NAME} ${SRC_FILES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${SFML_DIR}/include)


if(WIN32 OR MINGW OR MSVC)
add_subdirectory("${PROJECT_SOURCE_DIR}/ext/sfml")

# link with SFML library dependiences
target_link_libraries(${EXE_NAME} sfml-system sfml-window sfml-graphics sfml-audio)

target_include_directories(${EXE_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/sfml/include"
)
target_include_directories(${EXE_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/boost/algorithm/include"
)
target_include_directories(${EXE_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/boost/config/include"
)
target_include_directories(${EXE_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/boost/function/include"
)
target_include_directories(${EXE_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/boost/iterator/include"
)
target_include_directories(${EXE_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/boost/mpl/include"
)
target_include_directories(${EXE_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/boost/range/include"
)
target_include_directories(${EXE_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/boost/preprocessor/include"
)
target_include_directories(${EXE_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/boost/type_traits/include"
)
target_include_directories(${EXE_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/boost/concept_check/include"
)
target_include_directories(${EXE_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/boost/utility/include"
)
target_include_directories(${EXE_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/boost/assert/include"
)
target_include_directories(${EXE_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/boost/core/include"
)
target_include_directories(${EXE_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/boost/static_assert/include"
)
target_include_directories(${EXE_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/boost/type_index/include"
)
target_include_directories(${EXE_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/boost/detail/include"
)
target_include_directories(${EXE_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/boost/bind/include"
)
target_include_directories(${EXE_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/boost/throw_exception/include"
)
target_include_directories(${EXE_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/boost/integer/include"
)
target_include_directories(${EXE_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/boost/container_hash/include"
)
endif(WIN32 OR MINGW OR MSVC)



if(UNIX)

#SFML
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    target_link_libraries(${EXE_NAME} sfml-system sfml-window sfml-graphics sfml-audio)
endif()

endif(UNIX)
