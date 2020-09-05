cmake_minimum_required(VERSION 3.16)
project(Stereo_OpenCV_PCL)

set(OpenCV_DIR  /home/lucas/OpenCV/build)
find_package(OpenCV  REQUIRED)
message(STATUS "OpenCV library status:")
message(STATUS "   OpenCV Version: ${OpenCV_VERSION}")
message(STATUS "    library:${OpenCV_LIBS}")
message(STATUS "    include path:${OpenCV_INCLUDE_DIRS}")
set(CMAKE_CXX_STANDARD  14)

set(VTK_DIR /home/lucas/VTK-8.2.0/build)
find_package(VTK  REQUIRED)
message(STATUS "VTK library status:")
message(STATUS "   VTK Version: ${VTK_VERSION}")
message(STATUS "    library:${VTK_LIBRARIES}")
message(STATUS "    include path:${VTK_INCLUDE_DIRS}")
#include(${VTK_USE_FILE})

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${VTK_INCLUDE_DIRS})

add_executable(vtkDisplay ./main.cpp )

target_link_libraries(vtkDisplay ${OpenCV_LIBS}  ${VTK_LIBRARIES} )