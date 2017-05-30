#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <bits/stdc++.h>

using namespace std;

class Matrix {

public:

    vector<vector<int> > m_matrix;
    int m_line, m_collum;

    Matrix();
    Matrix(int line, int collum);

    ~Matrix();

    Matrix sumMatrix(Matrix matrix);
    
    Matrix subMatrix(Matrix matrix);
    
    Matrix multMatrix(Matrix matrix);

    void printMatrix();

    void setLineCollum(int line, int collum);

    void setMatrix(int i, int j, int value);

    vector< vector<int> >& getMatrix();

    int getSize();
    






};

#endif