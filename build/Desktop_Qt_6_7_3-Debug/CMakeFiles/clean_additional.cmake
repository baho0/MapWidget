# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/MapWidget_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/MapWidget_autogen.dir/ParseCache.txt"
  "MapWidget_autogen"
  )
endif()
