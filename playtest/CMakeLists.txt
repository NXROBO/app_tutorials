cmake_minimum_required(VERSION 2.8.3)
project(playtest)
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)
 add_service_files(
   FILES
   play.srv
   scene.srv
 )
 generate_messages(
   DEPENDENCIES
   std_msgs
 )
catkin_package(
)
include_directories(
  ${catkin_INCLUDE_DIRS}
)
 add_executable(playtest src/playtest.cpp)
 target_link_libraries(playtest
   ${catkin_LIBRARIES}
 )
 install(TARGETS playtest
   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
 )

