#pragma once
#include "Color.hpp"
#include "Polygon.hpp"
#include <initializer_list>
#include <ostream>

class MapPolygon : public Polygon{
private:
    unsigned m_border_width = 0;
    Color m_border_color;
    Color m_fill_color;
    unsigned m_opacity = 255;

public:
    MapPolygon() = default;
    MapPolygon(unsigned t_border_width, Color t_border_color, Color t_fill_color, unsigned t_opacity = 255) : m_border_width(t_border_width), m_border_color(t_border_color), m_fill_color(t_fill_color), m_opacity(t_opacity){}
    MapPolygon(MapPolygon& toCopy){*this = toCopy;}
    MapPolygon(std::initializer_list<unsigned> list);

    unsigned getBorderWidth(){ return m_border_width;}
    Color getBorderColor(){ return m_border_color;}
    Color getFillColor(){ return m_fill_color;}
    unsigned getOpacity(){ return m_opacity;}

    void setBorderWidth(unsigned t_border_width){m_border_width = t_border_width;}
    void setBorderColor(Color t_border_color){m_border_color = t_border_color;}
    void setFillColor(Color t_fill_color){m_fill_color = t_fill_color;}
    void setOpacity(unsigned t_opacity){m_opacity = t_opacity;}

    friend std::ostream& operator<<(std::ostream& out, MapPolygon x){
        out << "Border width: " << x.m_border_width << "\n";
        out << "Border color: " << x.m_border_color.toIntegerValues() << "\n";
        out << "Fill color: " << x.m_fill_color.toIntegerValues() << "\n";
        out << "Opacity: " << x.m_opacity << "\n";

        return out;
    }

    ~MapPolygon(){std::cout << "Polygon Map destroyed!\n";}

};