#pragma once

#include <cmath>
#include <iostream>

class Matrix{
    double** arr{};
    unsigned sizeX, sizeY;

public:
    Matrix(unsigned sx, unsigned sy, double val = 0);

    double* operator[](unsigned i);

    Matrix& operator=(Matrix x);
    
    Matrix operator+(Matrix& m);
    Matrix operator-(Matrix& m);
    Matrix operator*(Matrix& m);
    Matrix operator*(double m);
    
    Matrix& operator+=(Matrix& x);
    Matrix& operator-=(Matrix& x);
    Matrix& operator*=(Matrix& x);
    Matrix& operator*=(double x);

    friend std::ostream& operator<<(std::ostream& out, Matrix m){
        for(unsigned y = 0; y < m.sizeY; y++){
            out << "| ";
            for(unsigned x = 0; x < m.sizeX; x++){
                out << m.arr[x][y] << "\t";
            }
            out << " |\n";
        }
        return out;
    }
};