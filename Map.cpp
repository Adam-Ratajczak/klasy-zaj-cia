#include "Map.hpp"
#include <X11/X.h>

Map::Map(std::initializer_list<MapPolygonCell> polygon_list, std::initializer_list<MapLineCell> line_list){
    for(auto& p : polygon_list)
        v_map_polgons.push_back(p);

    for(auto& l : line_list)
        v_map_lines.push_back(l);
}

Map::MapPolygonCell* Map::get_polygons(){return v_map_polgons.data();}
Map::MapLineCell* Map::get_lines(){return v_map_lines.data();}


unsigned Map::get_polygon_count(){return v_map_polgons.size();}
unsigned Map::get_line_count(){return v_map_lines.size();}