# cmake needs this line
cmake_minimum_required(VERSION 2.8)

# Define project name
project(Code)

# add C++ 11 standard support for (nullptr and chrono)
# SET( CMAKE_CXX_FLAGS "-std=c++11 -O3" )
SET( CMAKE_CXX_FLAGS "-std=c++11 -g3" )

# Find OpenCV, you may need to set OpenCV_DIR variable to the absolute path to the directory containing OpenCVConfig.cmake file via the command line or GUI
set (OpenCV_DIR /usr/local/share/OpenCV)
find_package(OpenCV REQUIRED)
# If the package has been found, several variables will be set, you can find the full list with descriptions in the OpenCVConfig.cmake file. Print some message showing some of them
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
if(CMAKE_VERSION VERSION_LESS "2.8.11")
  # Add OpenCV headers location to your include paths
  include_directories(${OpenCV_INCLUDE_DIRS})
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/include)

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath,\"$ORIGIN:$ORIGIN/../lib:/lib:/home/root/lib:${MO_3RD_PARTY_DIR}/lib/embed\"")

# Declare the executable target built from your sources
add_executable(BubbleSort Code_00_BubbleSort.cpp)
add_executable(InsertionSort Code_01_InsertionSort.cpp)
add_executable(SelectionSort Code_02_SelectionSort.cpp)
add_executable(HeapSort Code_03_HeapSort.cpp)
add_executable(QuickSort Code_04_QuickSort.cpp)
add_executable(MergeSort Code_05_MergeSort.cpp)
add_executable(BucketSort Code_06_BucketSort.cpp)
add_executable(RadixSort Code_07_RadixSort.cpp)
add_executable(NetherlandsFlag Code_08_NetherlandsFlag.cpp)
add_executable(MaxGap Code_11_MaxGap.cpp)
add_executable(SmallSum Code_12_SmallSum.cpp)
add_executable(KMP Code_KMP.cpp)
# add_executable(KMPShortestHaveTwice Code_KMP_ShortestHaveTwice.cpp)
add_executable(ArrayToStackQueue Code_Array_To_Stack_Queue.cpp)
add_executable(GetMinStack Code_GetMinStack.cpp)
add_executable(StackAndQueueConvert Code_StackAndQueueConvert.cpp)
add_executable(DogCatQueue Code_DogCatQueue.cpp)

target_link_libraries(BubbleSort ${OpenCV_LIBS}
)

