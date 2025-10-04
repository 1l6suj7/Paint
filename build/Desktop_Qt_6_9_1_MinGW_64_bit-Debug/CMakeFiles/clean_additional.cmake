# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appPaint_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appPaint_autogen.dir\\ParseCache.txt"
  "appPaint_autogen"
  )
endif()
