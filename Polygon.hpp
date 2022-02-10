//plik Polygon.hpp

	/*! \file Polygon.hpp
	*
	* \brief Zawiera deklarację klasy Polygon
	*
	* Plik zawiera deklarację klasy Polygon.
	* Współrzędne wierzchołków przechowywane są jako punkty klasy Point2D w tablicy alokowanej
    * dynamicznie i aktualizowanej w czasie operacji na zbiorze wierzchołków w wielokącie.
	* Klasa zawiera kilka metod skladowych
	*
	* \author Adam Ratajczak
	* \date 2022.01.13
	* \version 1.00.00
	*/

#pragma once
#include "Point2D.hpp"
#include "Vector2D.hpp"

#include <initializer_list>
#include <iostream>

class Polygon{
    // tablica wierzchołków wraz z wielkością
    unsigned m_count = 0;
    Point2D* m_vertices{};

    // Sprawdza czy figura jest convex czy concave
    bool isConvex();

    static unsigned object_count;

public:
    // deklaracja wierzchołków
    void setVertices(Point2D* vertices, unsigned count);

    // operator umożliwiający zapis i odczyt w tablicy wierzchołków.
    Point2D& operator[](unsigned i) {return m_vertices[i];};
    Point2D operator[](unsigned i) const {return m_vertices[i];};
    Point2D* getVertexArray(){return m_vertices;}
    Polygon& operator=(const Polygon& toCopy);
    Polygon& operator=(Polygon& toMove);

    //Funkcje do manipulowania wierzchołkami w wielokoncie
    void setCount(unsigned n);
    void appendPoint(Point2D x);
    void deletePoint();

    // funkcja obliczjąca obwód wielokąta
    double getPerimeter();

    // fukcja zwracająca ilość wierzchołków w wielokącie
    unsigned size() const{return m_count;}
    unsigned objCount(){return object_count;}

    // obliczanie pól trójkąta
    double calTriangleAreaVectorMethod(Point2D p1, Point2D p2, Point2D p3);
    double calTriangleAreaHeronMethod(Point2D p1, Point2D p2, Point2D p3);

    double calConvexArea();
    double calArea();

    friend std::ostream& operator<<(std::ostream& out, Polygon x){
        out << "[";
        for(unsigned i = 0; i < x.m_count; i++)
            out << x[i] << "; ";
        out << "\b\b]";

        return out;
    }

    // konstruktory
    Polygon(){object_count++;};
    Polygon(Point2D* vertices, unsigned count){setVertices(vertices, count);}
    Polygon(const Polygon& toCopy);
    Polygon(std::initializer_list<Point2D> vertices);

    // destruktor zapobiegający wyciekom pamięci w funkcji
    ~Polygon(){delete[] m_vertices; object_count--;}
};