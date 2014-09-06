cmake_minimum_required(VERSION 2.8.3)
project(snailbot_description)

find_package(catkin REQUIRED roslaunch)

catkin_package()

install(
  DIRECTORY launch meshes urdf
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

roslaunch_add_file_check(launch/bringup.launch)
roslaunch_add_file_check(launch/description.launch)
