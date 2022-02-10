#include "BrokenLine.hpp"
#include <X11/X.h>

BrokenLine::BrokenLine(std::initializer_list<Point2D> list){
    for(auto& l : list)
        v_vertices.push_back(l);
}

BrokenLine::BrokenLine(std::vector<Point2D> vec){
    v_vertices = vec;
}

BrokenLine::BrokenLine(const BrokenLine& to_copy){
    v_vertices = to_copy.v_vertices;
}

void BrokenLine::append_point(Point2D point){
    v_vertices.push_back(point);
}

void BrokenLine::delete_point(){
    v_vertices.pop_back();
}