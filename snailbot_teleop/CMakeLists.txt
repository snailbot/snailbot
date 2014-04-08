cmake_minimum_required(VERSION 2.8.3)
project(snailbot_teleop)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp joy geometry_msgs sensor_msgs)

catkin_package(
  CATKIN_DEPENDS roscpp geometry_msgs sensor_msgs
)

###########
## Build ##
###########

include_directories(${catkin_INCLUDE_DIRS})

add_executable(joystick_teleop src/joystick_teleop.cpp)
target_link_libraries(joystick_teleop ${catkin_LIBRARIES})

#############
## Install ##
#############

install(TARGETS joystick_teleop
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

