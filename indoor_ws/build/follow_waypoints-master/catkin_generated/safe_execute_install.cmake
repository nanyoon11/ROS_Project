execute_process(COMMAND "/home/nanyoon/indoor_ws/build/follow_waypoints-master/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/nanyoon/indoor_ws/build/follow_waypoints-master/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
