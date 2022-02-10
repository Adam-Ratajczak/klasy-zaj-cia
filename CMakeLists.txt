cmake_minimum_required(VERSION 3.19)
project(out)

set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(
    out
    main.cpp
    Color.cpp
    MapPolygon.cpp
    Matrix.cpp
    Polygon.cpp
    Point2D.cpp
    Vector2D.cpp
    BrokenLine.cpp
    MapBrokenLine.cpp
    Map.cpp
)