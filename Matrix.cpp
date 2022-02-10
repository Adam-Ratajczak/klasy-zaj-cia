#include "Matrix.hpp"
#include <stdexcept>

Matrix::Matrix(unsigned sx, unsigned sy, double val) : sizeX(sx), sizeY(sy){
    arr = new double*[sizeX];

    for(unsigned i = 0; i < sizeX; i++)
        arr[i] = new double[sizeY]{val};
}

double* Matrix::operator[](unsigned n){
    return arr[n];
}

Matrix& Matrix::operator=(Matrix x){
    sizeX = x.sizeX;
    sizeY = x.sizeY;

    delete [] arr;
    arr = new double*[sizeX];

    for(unsigned i = 0; i < sizeX; i++){
        arr[i] = new double[sizeY];
        for(unsigned j = 0; j < sizeY; j++){
            arr[i][j] = x[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+(Matrix& m){
    if(sizeX != m.sizeX || sizeY != m.sizeY)
        throw std::runtime_error("Adding matrixes with different dimensions is not allowed!");
    
    Matrix result(sizeX, sizeY);
    
    for(unsigned y = 0; y < sizeY; y++){
        for(unsigned x = 0; x < sizeX; x++){
            result[x][y] = arr[x][y] + m[x][y];
        }
    }
    return result;
}

Matrix Matrix::operator-(Matrix& m){
    if(sizeX != m.sizeX || sizeY != m.sizeY)
        throw std::runtime_error("Subtracting matrixes with different dimensions is not allowed!");
    
    Matrix result(sizeX, sizeY);
    
    for(unsigned y = 0; y < sizeY; y++){
        for(unsigned x = 0; x < sizeX; x++){
            result[x][y] = arr[x][y] - m[x][y];
        }
    }
    return result;
}

Matrix Matrix::operator*(Matrix& m){
    if(sizeX != m.sizeY || sizeY != m.sizeX)
        throw std::runtime_error("Multiplying matrixes with incorrect dimensions is not allowed!");
    
    Matrix result(m.sizeX, sizeY);
    
    for(unsigned i = 0; i < result.sizeX; i++){
        for(unsigned j = 0; j < result.sizeY; j++){
            for(unsigned k = 0; k < sizeX; k++){
                result[j][i] += arr[k][i] * m[j][k];
            }
        }
    }
    return result;
}

Matrix Matrix::operator*(double m){
    Matrix result(sizeX, sizeY);
    
    for(unsigned y = 0; y < sizeY; y++){
        for(unsigned x = 0; x < sizeX; x++){
            result[x][y] = arr[x][y] * m;
        }
    }
    return result;
}

Matrix& Matrix::operator+=(Matrix& x){
    *this = *this + x;
    return *this;
}

Matrix& Matrix::operator-=(Matrix& x){
    *this = *this - x;
    return *this;
}

Matrix& Matrix::operator*=(Matrix& x){
    *this = *this * x;
    return *this;
}

Matrix& Matrix::operator*=(double x){
    *this = *this * x;
    return *this;
}