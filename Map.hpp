#pragma once

#include "MapBrokenLine.hpp"
#include "MapPolygon.hpp"
#include "Polygon.hpp"
#include <initializer_list>
#include <ostream>
#include <string>
#include <vector>

class Map{
public:
    struct MapPolygonCell{
        MapPolygon polygon;
        std::string info;
    };


    struct MapLineCell{
        MapBrokenLine line;
        std::string info;
    };

private:
    std::vector<MapPolygonCell> v_map_polgons;
    std::vector<MapLineCell> v_map_lines;

public:
    Map() = default;
    Map(std::initializer_list<MapPolygonCell> polygon_list, std::initializer_list<MapLineCell> line_list);
    Map(std::vector<MapPolygonCell> p_vec, std::vector<MapLineCell> l_vec) : v_map_polgons(p_vec), v_map_lines(l_vec){}
    Map(const Map& to_copy){*this = to_copy;}

    MapPolygonCell* get_polygons();
    MapLineCell* get_lines();

    unsigned get_polygon_count();
    unsigned get_line_count();

    friend std::ostream& operator<<(std::ostream& out, Map x){
        out << "========== POLYGONS ==========\n";
        for(auto& p : x.v_map_polgons)
            out << p.polygon << "\t\t" << p.info << "\n";
        
        out << "\n\n==========  LINES   ==========\n";
        for(auto& l : x.v_map_lines)
            out << l.line << ":\n" << l.info << "\n\n";
        return out;
    }

};
