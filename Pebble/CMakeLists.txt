cmake_minimum_required(VERSION 3.16)

project(Pebble VERSION 1.0 LANGUAGES CXX)

# 1. Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. Enable Qt-specific compilation tools
set(CMAKE_AUTOMOC ON) # Handles Meta-Object Compiler (Q_OBJECT macro)
set(CMAKE_AUTORCC ON) # Handles Resources (.qrc)
set(CMAKE_AUTOUIC ON) # Handles UI files (.ui)

# 3. Find Packages
# For macOS Homebrew, you might need to set CMAKE_PREFIX_PATH if not found automatically
# set(CMAKE_PREFIX_PATH "/usr/local/opt/qt5" ${CMAKE_PREFIX_PATH})

find_package(Qt6 REQUIRED COMPONENTS Widgets Gui) 
# Note: Change "Qt6" to "Qt5" if you are using the older version.

find_package(OpenCV REQUIRED)

# 4. Define Source Files
# Including the .ui file here allows CMAKE_AUTOUIC to process it
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    image_Processing.hpp
    file_Processing.hpp
    logic_handler.hpp
    image_Processing.cpp
)

# 5. Create Executable
add_executable(Pebble ${PROJECT_SOURCES})

# 6. Include Directories and Link Libraries
target_link_libraries(Pebble PRIVATE 
    Qt6::Widgets
    Qt6::Gui
    ${OpenCV_LIBS}
)

# 7. macOS Specific Bundle settings (Optional)
set_target_properties(Pebble PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.pebble
    MACOSX_BUNDLE TRUE
)