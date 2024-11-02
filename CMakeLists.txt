cmake_minimum_required(VERSION 3.14)

project(MapWidget VERSION 1.0.0 LANGUAGES CXX)

# Enable AUTOMOC for QObject classes
set(CMAKE_AUTOMOC ON)

# Find the required Qt packages
find_package(Qt6 REQUIRED COMPONENTS Core Gui Network Widgets)

# Create a shared library
add_library(MapWidget SHARED
    mapWidget.cpp
    tile.cpp
    tileManager.cpp
    mapWidget.h
    tile.h
    tileManager.h
    drone.h drone.cpp
    drone.png
    dronemanager.h
    dronemanager.cpp
)

# Specify the C++ standard
set_target_properties(MapWidget PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

# Link Qt libraries
target_link_libraries(MapWidget PRIVATE Qt6::Widgets Qt6::Gui Qt6::Network Qt6::Core)

# Include directories
target_include_directories(MapWidget PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

# Optionally install the library
install(TARGETS MapWidget
    EXPORT MapWidgetTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

# Install header files only
install(FILES mapWidget.h tile.h tileManager.h drone.h dronemanager.h DESTINATION include/MapWidget)
