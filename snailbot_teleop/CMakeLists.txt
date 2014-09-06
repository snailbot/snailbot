cmake_minimum_required(VERSION 2.8.3)
project(snailbot_teleop)

find_package(catkin REQUIRED COMPONENTS joy teleop_twist_joy roslaunch)

catkin_package(
  CATKIN_DEPENDS
  )

install(DIRECTORY launch rviz
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

roslaunch_add_file_check(launch/teleop.launch)
