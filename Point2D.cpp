#include "Point2D.hpp"
#include <cmath>

unsigned Point2D::object_count = 0;

double Point2D::getRadius(){
    return std::sqrt(m_x * m_x + m_y * m_y);
}

double Point2D::getAngle(){
    return std::atan2(m_y, m_x);
}

double Point2D::getDistance(Point2D x){
    return std::sqrt((x.m_x - m_x) * (x.m_x - m_x) + (x.m_y - m_y) * (x.m_y - m_y));
}

Point2D Point2D::operator+(Point2D x){
    return Point2D(m_x + x.x(), m_y + x.y());
}

Point2D Point2D::operator-(Point2D x){
    return Point2D(m_x - x.x(), m_y - x.y());
}

Point2D Point2D::operator*(double x){
    return Point2D(m_x * x, m_y * x);
}