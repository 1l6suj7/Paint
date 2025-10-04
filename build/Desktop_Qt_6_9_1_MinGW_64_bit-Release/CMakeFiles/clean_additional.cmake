# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\appRectangleDragging_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appRectangleDragging_autogen.dir\\ParseCache.txt"
  "appRectangleDragging_autogen"
  )
endif()
