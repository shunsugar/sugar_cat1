cmake_minimum_required(VERSION 3.0.2)
project(motor_controller)

# find dependencies
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  geometry_msgs
  std_srvs
)

# Declare a catkin package
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES hard_lecture
#  CATKIN_DEPENDS roscpp rospy std_msgs tf
#  DEPENDS system_lib
)

# Specify additional locations of header files
include_directories(include
  ${catkin_INCLUDE_DIRS}
)

# Create Cpp executable
add_executable(motor_controller 
  src/motor_controller.cpp
)
target_link_libraries(motor_controller
  ${catkin_LIBRARIES}
)

# Install Cpp executable
#install(TARGETS motor_controller RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
#install(TARGETS motor_listener RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
