#include <iostream>

#include "Color.hpp"
#include "MapPolygon.hpp"
#include "Point2D.hpp"
#include "Polygon.hpp"
#include "Matrix.hpp"

int main(){
    Point2D p1;
    p1.y() = 20.5;
    Point2D *p2;
    p2 = new Point2D(11.0, 60.7);
    std::cout << "Distance between two points: " << p1.getDistance(*p2) << "\n";
    std::cout << "Polar coordinates of p2: " << p2->getAngle() << ", " << p2->getRadius() << "\n";
    std::cout << "Size of Point2D: " << sizeof(p1) << "\n";

    Polygon f;
    f.appendPoint(Point2D(10, 20));
    f.appendPoint(Point2D(5, 30));
    f.appendPoint(Point2D(-5, 20));
    f.appendPoint(Point2D(-10, 10));
    f[2].x() = -10;

    std::cout << "Perimeter of f: " << f.getPerimeter() << "\n";
    std::cout << "Area of the triangle calculated with Vector cross product method: " << f.calTriangleAreaVectorMethod(Point2D(10, 20), Point2D(20, 10), Point2D (-10, 5)) << "\n";
    std::cout << "Area of the triangle calculated with Heron method: " << f.calTriangleAreaHeronMethod(Point2D(10, 20), Point2D(20, 10), Point2D (-10, 5)) << "\n";
    std::cout << "Area of the f shape with Convex shape area calculation: " << f.calConvexArea() << "\n";
    std::cout << "Area of the f shape with Shoelace formula: " << f.calArea() << "\n";

    Point2D arr[]{
        Point2D(10, 10),
        Point2D(40, 40),
        Point2D(10, 30),
        Point2D(20, 10),
        Point2D(0, 0)
    };

    Polygon f2(arr, 5);
    Polygon f3, f4;
    Point2D p3(20, 10);
    Point2D p4(50, 60);
    std::cout << "Area of the f2 shape with Shoelace formula: " << f2.calArea() << "\n";
    std::cout << "Egzisting polygon objects: " << f2.objCount() << "\n";
    std::cout << "Egzisting point objects: " << p1.objCount() << "\n";
    delete p2;
    std::cout << "Egzisting point objects: " << p1.objCount() << "\n";
    std::cout << "p4 - p3 = " << p4 - p3 << "\n";
    std::cout << "p3 * 2 = " << p3 * 2 << "\n";

    Polygon f5(f2);
    std::cout << "Vertexes of copied object: " << f5 << "\n";
    Point2D p6({10, 20});
    Polygon f6({Point2D(10, 20), Point2D(5, 30), Point2D(15, 15)});
    std::cout << "P6 with initializer: " << p6 << "\n";
    std::cout << "F6 with initializer: " << f6 << "\n";
    f5 = f6;
    std::cout << "Vertexes of copied object: " << f5 << "\n";
    f5.deletePoint();
    f5.appendPoint(Point2D(15, 25));
    
    for(unsigned i = 0; i < f5.size(); i++)
        std::cout << "Vertex " << i << " is: " << f5[i] << "\n";
    
    Matrix m11(2, 2);
    m11[0][0] = 1;
    m11[1][0] = 2;
    m11[0][1] = 4;
    m11[1][1] = 8;

    Matrix m12(2, 2);
    m12[0][0] = 10;
    m12[1][0] = 3;
    m12[0][1] = 5;
    m12[1][1] = 18;
    
    std::cout << m11 + m12 << "\n";
    std::cout << m11 - m12 << "\n";

    Matrix m2(3, 2), m3(2, 3);
    m2[0][0] = 1;
    m2[1][0] = 5;
    m2[2][0] = 0;
    m2[0][1] = 2;
    m2[1][1] = -3;
    m2[2][1] = 1;

    m3[0][0] = 0;
    m3[1][0] = -2;
    m3[0][1] = 1;
    m3[1][1] = 1;
    m3[0][2] = 3;
    m3[1][2] = 4;

    std::cout << m2 * m3 << "\n";
    std::cout << m2 * 5 << "\n";
    m2 *= m3;
    std::cout << m2 << "\n";

    Polygon f7;
    MapPolygon mp7;
    Color c1(0, 0.5, 1);
    std::cout << c1.toIntegerValues() << "\n";

}
