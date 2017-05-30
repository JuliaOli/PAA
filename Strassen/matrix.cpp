#include "matrix.hpp"

using namespace std;

Matrix::Matrix(){


}

Matrix::~Matrix(){


}

Matrix::Matrix(int line, int collum){

    m_line = line;
    m_collum = collum;
    vector<int> aux (collum);
    m_matrix.resize(line,aux);
    
}

Matrix Matrix::sumMatrix(Matrix matrix){
    
    Matrix result(m_line,m_collum);

    for(int i = 0; i < m_line; ++i){

        for(int j = 0; j < m_collum; ++j){

            result.setMatrix(i,j,(m_matrix[i][j] + matrix.getMatrix()[i][j]));
        }
    }
    return result;
}

Matrix Matrix::subMatrix(Matrix matrix){

    Matrix result(m_line,m_collum);

    for(int i = 0; i < m_line; ++i){

        for(int j = 0; j < m_collum; ++j){

            result.setMatrix(i,j,(m_matrix[i][j] - matrix.getMatrix()[i][j]));
        }
    }
    return result;
}

Matrix Matrix::multMatrix(Matrix matrix){
    
    Matrix result(m_line,m_collum);

    for (int i = 0; i < m_line; i++)
    {
        for (int j = 0; j < m_line; j++)
        {
            int soma = 0;
            for (int k = 0; k < m_line; k++)
            {
                soma += m_matrix[i][k] * matrix.getMatrix()[k][j];
                
            }
            result.setMatrix(i,j,soma);                
        }
    }

    return result;
}


void Matrix::printMatrix() {
    
    for (int i=0; i < m_line; i++) {
        for (int j=0; j < m_line; j++) {
            if (j != 0) {
                cout << "\t";
            }
            cout << m_matrix[i][j];
        }
        cout << endl;
    }
}

void Matrix::setLineCollum(int line, int collum){
    
    m_line = line;
    m_collum = collum;
}

void Matrix::setMatrix(int i, int j, int value){

    m_matrix[i][j] = value;
}

vector< vector<int> >& Matrix::getMatrix(){

    return m_matrix;
}

int Matrix::getSize(){

    return m_line;
}