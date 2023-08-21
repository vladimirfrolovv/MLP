cmake_minimum_required(VERSION 3.22)

project(CPP7_MLP-2 VERSION 2.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include_directories(View/MSEgraph/qcp)
find_package(Qt6 COMPONENTS Core Gui Widgets PrintSupport REQUIRED)

set(PROJECT_SOURCES
        main.cc

        View/mainwindow.cc
        View/mainwindow.h
        View/mainwindow.ui

        View/Form/form.cc
        View/Form/form.h

        View/MSEgraph/qcp/qcustomplot.cc
        View/MSEgraph/qcp/qcustomplot.h

        View/MSEgraph/msegraphwindow.cc
        View/MSEgraph/msegraphwindow.h
        View/MSEgraph/msegraphwindow.ui

        View/Statuswindow/statuswindow.h
        View/Statuswindow/statuswindow.cc
        View/Statuswindow/statuswindow.ui

        View/Worker/worker.h
        View/Worker/worker.cc

        Controller/controller.cc
        Controller/controller.h

        Model/fastmatrix.cc
        Model/fastmatrix.h
        Model/model.cc
        Model/model.h
        Model/reader.cc
        Model/reader.h
        Model/graphnetwork.cc
        Model/graphnetwork.h
        Model/neuralnetwork.h
        Model/neuralnetwork.cc
        Model/matrixnetwork.cc
        Model/matrixnetwork.h
        icon/icon.qrc)

qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::PrintSupport)

qt_finalize_executable(${PROJECT_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        COMPILE_FLAGS "-Ofast -flto"
)

