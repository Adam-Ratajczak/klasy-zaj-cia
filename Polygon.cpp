#include "Polygon.hpp"
#include "Point2D.hpp"
#include "Vector2D.hpp"
#include <cmath>
#include <iostream>

unsigned Polygon::object_count = 0;

void Polygon::setVertices(Point2D* vertices, unsigned count){
    // powtórna alokacja pamięci w tablicy
    delete[] m_vertices;
    m_vertices = new Point2D[count];

    // przepisywanie z jedej tablicy do drugiej
    for(unsigned i = 0; i < count; i++)
        m_vertices[i] = vertices[i];
    
    // aktuaizacja wielkości tablicy
    m_count = count;
}

void Polygon::appendPoint(Point2D x){
    setCount(m_count + 1);
    m_vertices[m_count - 1] = x;
}

void Polygon::deletePoint(){
    setCount(m_count - 1);
}

double Polygon::getPerimeter(){
    // deklaracja zmiennej będącej wynikiem działania
    double result = 0;

    // iteracja po elementach tablicy od 0 do m_count-2 w celu dodawania długości boków do wyniku
    for(unsigned i = 0; i < m_count - 1; i++)
        result += m_vertices[i].getDistance(m_vertices[i+1]);
    
    // korekcja wyniku przez dodanie nieuwzględnionego wcześniej boku. Między punktem n-1, a 0.
    result += m_vertices[m_count - 1].getDistance(m_vertices[0]);

    return result;
}

void Polygon::setCount(unsigned n){
    // alokacja tablicy pomocniczej
    Point2D* temp;
    temp = new Point2D[n];

    // wpisiywanie danych do tablicy pomocniczej
    for(unsigned i = 0; i < m_count; i++)
        temp[i] = m_vertices[i];
    
    // nadpisanie wskaźnika do funkcji z danymi
    delete[] m_vertices;
    m_vertices = temp;
    
    m_count = n;
}

double Polygon::calTriangleAreaVectorMethod(Point2D p1, Point2D p2, Point2D p3){
    Vector2D v1(p2.x() - p1.x(), p2.y() - p1.y());
    Vector2D v2(p3.x() - p1.x(), p3.y() - p1.y());

    return std::fabs(v1 * v2) / 2;
}

double Polygon::calTriangleAreaHeronMethod(Point2D p1, Point2D p2, Point2D p3){
    double a = p1.getDistance(p2);
    double b = p2.getDistance(p3);
    double c = p3.getDistance(p1);

    double p = (a + b + c) / 2;

    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

bool Polygon::isConvex(){
    double result = 0;
    for(unsigned i = 1; i < m_count - 2; i++)
        result += calTriangleAreaVectorMethod(m_vertices[0], m_vertices[i], m_vertices[i + 1]);
    
    if(calArea() == result)
        return true;
    return false;
}

double Polygon::calConvexArea(){
    if(isConvex()){
        double result = 0;
        for(unsigned i = 1; i < m_count - 2; i++)
            result += calTriangleAreaVectorMethod(m_vertices[0], m_vertices[i], m_vertices[i + 1]);
        return result;
    }
    throw std::runtime_error("This shape isn't convex!");
}

double Polygon::calArea(){
    double result = 0;

    for(unsigned i = 0; i < m_count - 1; i++)
        result += m_vertices[i].x()*m_vertices[i + 1].y();
    result += m_vertices[m_count - 1].x() * m_vertices[0].y();

    for(unsigned i = 0; i < m_count - 1; i++)
        result -= m_vertices[i + 1].x()*m_vertices[i].y();
    result -= m_vertices[0].x() * m_vertices[m_count - 1].y();

    return std::fabs(result) / 4;
}

Polygon& Polygon::operator=(const Polygon& toCopy){
    setVertices(toCopy.m_vertices, toCopy.m_count);
    this->object_count = toCopy.object_count;

    return *this;
}

Polygon& Polygon::operator=(Polygon& toMove){
    setVertices(toMove.m_vertices, toMove.m_count);
    this->object_count = toMove.object_count;

    delete[] toMove.m_vertices;
    toMove.m_count = 0;

    return *this;
}

Polygon::Polygon(const Polygon& toCopy){
    setVertices(toCopy.m_vertices, toCopy.m_count);
    this->object_count = toCopy.object_count;
}

Polygon::Polygon(std::initializer_list<Point2D> vertices){
    m_vertices = new Point2D[vertices.size()];
    unsigned i = 0;
    for(auto& v : vertices){
        m_vertices[i] = v;
        i++;
    }
    m_count = vertices.size();
}
