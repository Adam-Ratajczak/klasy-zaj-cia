#pragma once
#include "Point2D.hpp"
#include <X11/X.h>
#include <initializer_list>
#include <vector>

class BrokenLine{
private:
    std::vector<Point2D> v_vertices;

public:
    BrokenLine(std::initializer_list<Point2D> list);
    BrokenLine(std::vector<Point2D> vec);
    BrokenLine(const BrokenLine& to_copy);
    BrokenLine() = default;

    Point2D& operator[](unsigned index){return v_vertices[index];}
    Point2D operator[](unsigned index) const {return v_vertices[index];}

    void append_point(Point2D point);
    void delete_point();

    unsigned line_size(){ return v_vertices.size(); }
};