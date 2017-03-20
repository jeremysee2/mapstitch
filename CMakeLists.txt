cmake_minimum_required(VERSION 2.8.3)
project(mapstitch)

find_package(catkin REQUIRED COMPONENTS roscpp std_msgs nav_msgs tf)

find_package(OpenCV 2 REQUIRED)

catkin_package(
    INCLUDE_DIRS include
    LIBRARIES ${PROJECT_NAME}
)

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

# mapstitch lib
add_library(${PROJECT_NAME}
    src/mapstitch.cpp
    src/utils.cpp
)
add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBS}
    ${catkin_LIBRARIES}
)

# mapstitch standalone tool
add_executable(${PROJECT_NAME}_tool src/main.cpp)
add_dependencies(${PROJECT_NAME}_tool ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME}_tool
    ${catkin_LIBRARIES}
    ${PROJECT_NAME}
)

# mapstitch node
#add_executable(${PROJECT_NAME}_node src/rosmain.cpp)
#add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
#target_link_libraries(${PROJECT_NAME}_node
#    ${catkin_LIBRARIES}
#    ${PROJECT_NAME}
#)

