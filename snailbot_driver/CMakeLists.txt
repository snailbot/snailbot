cmake_minimum_required(VERSION 2.8.3)
project(snailbot_driver)

find_package(catkin REQUIRED COMPONENTS roscpp geometry_msgs tf dynamic_reconfigure)

find_package(Boost REQUIRED COMPONENTS system thread signals)

generate_dynamic_reconfigure_options(cfg/MotorGains.cfg)


catkin_package(
	 DEPENDS
	 CATKIN_DEPENDS roscpp geometry_msgs tf dynamic_reconfigure
   INCLUDE_DIRS include
   LIBRARIES snailbot_driver
)

###########
## Build ##
###########
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
)

link_directories(${catkin_LIBRARY_DIRS})

## Declare a cpp library
add_library(snailbot_driver src/snailbot_driver.cpp)
add_dependencies(snailbot_driver ${PROJECT_NAME}_gencfg)
target_link_libraries(snailbot_driver ${catkin_LIBRARIES} ${Boost_LIBRARIES})

add_executable(snailbot_driver_node src/snailbot_driver_node.cpp)
add_dependencies(snailbot_driver_node ${PROJECT_NAME}_gencfg) 
target_link_libraries(snailbot_driver_node snailbot_driver ${catkin_LIBRARIES} ${Boost_LIBRARIES})

#############
## Install ##
#############
install(TARGETS snailbot_driver snailbot_driver_node
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

