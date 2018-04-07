cmake_minimum_required(VERSION 3.7)
project(CAL_proj)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Projeto_Parte1/Debug/src/Accommodation.o
        Projeto_Parte1/Debug/src/Algorithms.o
        Projeto_Parte1/Debug/src/Clients.o
        Projeto_Parte1/Debug/src/Coordinates.o
        Projeto_Parte1/Debug/src/Date.o
        Projeto_Parte1/Debug/src/Destiny.o
        Projeto_Parte1/Debug/src/ExportInfor.o
        Projeto_Parte1/Debug/src/graphviewer.o
        Projeto_Parte1/Debug/src/ImportInfo.o
        Projeto_Parte1/Debug/src/Interface.o
        Projeto_Parte1/Debug/src/main.o
        Projeto_Parte1/Debug/src/Period.o
        Projeto_Parte1/Debug/src/PossibleDestinies.o
        Projeto_Parte1/Debug/src/Projeto_Parte1.o
        Projeto_Parte1/Debug/Projeto_Parte1.exe
        Projeto_Parte1/InfoFiles/1.txt
        Projeto_Parte1/InfoFiles/2.txt
        Projeto_Parte1/InfoFiles/3.txt
        Projeto_Parte1/InfoFiles/4.txt
        Projeto_Parte1/InfoFiles/5.txt
        Projeto_Parte1/InfoFiles/clients.txt
        Projeto_Parte1/src/Accommodation.cpp
        Projeto_Parte1/src/Accommodation.h
        Projeto_Parte1/src/Agency.cpp
        Projeto_Parte1/src/Agency.h
        Projeto_Parte1/src/Algorithms.cpp
        Projeto_Parte1/src/Algorithms.h
        Projeto_Parte1/src/Clients.cpp
        Projeto_Parte1/src/Clients.h
        Projeto_Parte1/src/connection.cpp
        Projeto_Parte1/src/connection.h
        Projeto_Parte1/src/Coordinates.cpp
        Projeto_Parte1/src/Coordinates.h
        Projeto_Parte1/src/Date.cpp
        Projeto_Parte1/src/Date.h
        Projeto_Parte1/src/Destiny.cpp
        Projeto_Parte1/src/Destiny.h
        Projeto_Parte1/src/edgetype.h
        Projeto_Parte1/src/ExportInfo.h
        Projeto_Parte1/src/ExportInfor.cpp
        Projeto_Parte1/src/Graph.h
        Projeto_Parte1/src/graphviewer.cpp
        Projeto_Parte1/src/graphviewer.h
        Projeto_Parte1/src/ImportInfo.cpp
        Projeto_Parte1/src/ImportInfo.h
        Projeto_Parte1/src/Interface.cpp
        Projeto_Parte1/src/Interface.h
        Projeto_Parte1/src/Libraries.h
        Projeto_Parte1/src/MutablePriorityQueue.h
        Projeto_Parte1/src/Period.cpp
        Projeto_Parte1/src/Period.h
        Projeto_Parte1/src/PossibleDestinies.cpp
        Projeto_Parte1/src/PossibleDestinies.h
        Projeto_Parte1/background.jpg
        Projeto_Parte1/background_small.jpg
        Projeto_Parte1/GraphViewerController.jar
        README.md)

add_executable(CAL_proj ${SOURCE_FILES})