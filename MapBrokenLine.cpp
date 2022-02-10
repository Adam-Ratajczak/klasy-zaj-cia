#include "MapBrokenLine.hpp"

MapBrokenLine::MapBrokenLine(std::initializer_list<unsigned> list){
    const unsigned* arr;
    arr = list.begin();

    m_border_width = arr[0];
    m_border_color.fromIntegerValues(arr[1], arr[2], arr[3]);
    m_fill_color.fromIntegerValues(arr[4], arr[5], arr[6]);
    m_opacity = arr[7];
}
