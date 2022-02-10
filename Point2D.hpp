
//plik Punkt2.h

	/*! \file Punkt2.h
	*
	* \brief Zawiera deklarację klasy Punkt2
	*
	* Plik zawiera deklarację klasy Punkt2.h.
	* Współrzędne punktu są podawane w układzie kartezjańskim.
	* Klasa zawiera kilka metod skladowych
	*
	* \author Adam Ratajczak
	* \date 2022.01.13
	* \version 1.00.00
	*/

#pragma once
#include <cmath>
#include <ostream>
#include <initializer_list>

class Point2D{
private:
    static unsigned object_count;

    // członkowie klasy
    double m_x, m_y;

public:
    // Konstruktory
    Point2D() : m_x(.0), m_y(.0){object_count++;}
    Point2D(double x, double y) : m_x(x), m_y(y){object_count++;}
    Point2D(std::initializer_list<double> coords) : m_x(*coords.begin()), m_y(*(coords.end() - 1)){}

    ~Point2D(){object_count--;}

    // Settery i gettery
    double& x(){return m_x;}
    double& y(){return m_y;}
    double x() const{return m_x;}
    double y() const{return m_y;}

    unsigned objCount(){return object_count;}

    // Współrzędne biegunowe i dystans
    double getRadius();
    double getAngle();
    double getDistance(Point2D x);

    Point2D operator+(Point2D x);
    Point2D operator-(Point2D x);
    Point2D operator*(double x);

    friend std::ostream& operator<<(std::ostream& out, Point2D x){
        return out << "(" << x.x() << ", " << x.y() << ")";
    }
};