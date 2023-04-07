cmake_minimum_required(VERSION 3.5.0)
project(mapstitch)

find_package(catkin REQUIRED COMPONENTS roscpp std_msgs nav_msgs tf)

find_package(OpenCV REQUIRED)

catkin_package(
    INCLUDE_DIRS include
    LIBRARIES ${PROJECT_NAME}
)

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
    ${OpenCV_INCLUDE_DIRS}
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
set_target_properties(${PROJECT_NAME}_tool PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CATKIN_DEVEL_PREFIX}/bin)

# mapstitch node
add_executable(${PROJECT_NAME}_node src/rosmain.cpp)
add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME}_node
    ${catkin_LIBRARIES}
    ${PROJECT_NAME}
)
set_target_properties(${PROJECT_NAME}_node PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CATKIN_DEVEL_PREFIX}/bin)
