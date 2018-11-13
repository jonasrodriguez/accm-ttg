cmake_minimum_required(VERSION 3.1)

project(accm-ttg LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick Sql REQUIRED)

# include
include_directories(${CMAKE_SOURCE_DIR}/interfaces)
include_directories(${CMAKE_SOURCE_DIR}/src/accmTtgUI ${CMAKE_SOURCE_DIR}/src/accmTtgUI/utilities)
include_directories(${CMAKE_SOURCE_DIR}/src/accmTtgDb ${CMAKE_SOURCE_DIR}/src/accmTtgBusiness)

# Looking for files
file(GLOB_RECURSE SRC "src/*.cpp" )
file(GLOB_RECURSE HDR "src/*.h" "interfaces/*.h" )
file(GLOB_RECURSE QRC "src/*qrc")

add_executable(${PROJECT_NAME} ${SRC} ${HDR} ${QRC})

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick Qt5::Sql)
