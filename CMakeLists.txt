cmake_minimum_required(VERSION 3.23)
project(QtGUI LANGUAGES CXX VERSION 0.1.0)
configure_file(${PROJECT_NAME}Config.h.in ${PROJECT_NAME}Config.h)

FIND_PACKAGE(Qt6 REQUIRED COMPONENTS GUI Widgets Charts )

SET(CMAKE_INCLUDE_CURRENT_DIR ON)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
SET(CMAKE_AUTORCC ON)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} 
PRIVATE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindowform.ui
    drawingwidget.h
    drawingwidget.cpp
    piestimator.h
    piestimator.cpp

) 
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_include_directories(${PROJECT_NAME} PRIVATE)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Widgets
    Qt6::Gui
    Qt6::Charts
)

install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    FILE_SET HEADERS
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include)

