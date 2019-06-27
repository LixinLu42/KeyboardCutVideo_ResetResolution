cmake_minimum_required(VERSION 2.8.3)
project(cut_video_handle)



find_package(OpenCV 3.4.5 REQUIRED)


#ADD_LIBRARY (${PROJECT_NAME} SHARED 
#cut_video_handle.cpp
#)

include_directories(
${PROJECT_SOURCE_DIR}
)

add_executable(${PROJECT_NAME}  cut_video_handle.cpp)

#target_link_libraries(cut_video_handle ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} 
${OpenCV_LIBS}
)






