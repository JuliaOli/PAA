#include <bits/stdc++.h>
#include "matrix.hpp"
#define DEBUG if(1)
#define LAST_SIZE 1

using namespace std;



void readFile(Matrix &first, Matrix &second){
    
    int aux;

    for(int i = 0; i < first.getSize(); ++i){
        
        for(int j = 0; j < first.getSize(); ++j){
            cin >> aux;
            first.setMatrix(i,j,aux);
        }
    }

    for(int i = 0; i < second.getSize(); ++i){
        
        for(int j = 0; j<second.getSize(); ++j){
            cin >> aux;
            second.setMatrix(i,j,aux);
        }
    }

}


Matrix strassen(Matrix A, Matrix B, int size){

    if(size <= LAST_SIZE){
        return A.multMatrix(B);
    }

    int newSize = size/2;
    
    Matrix a11(newSize,newSize), a12(newSize,newSize), a21(newSize,newSize), a22(newSize,newSize),
    b11(newSize,newSize), b12(newSize,newSize), b21(newSize,newSize), b22(newSize,newSize),
    c11(newSize,newSize), c12(newSize,newSize), c21(newSize,newSize), c22(newSize,newSize),
    m1(newSize,newSize), m2(newSize,newSize), m3(newSize,newSize), m4(newSize,newSize), 
    m5(newSize,newSize), m6(newSize,newSize), m7(newSize,newSize),
    aResult(newSize,newSize), bResult(newSize,newSize);
    
    for (int i = 0; i < newSize; i++) {
            for (int j = 0; j < newSize; j++) {
                
                a11.setMatrix(i,j,A.getMatrix()[i][j]);
                a12.setMatrix(i,j,A.getMatrix()[i][j + newSize]);
                a21.setMatrix(i,j,A.getMatrix()[i + newSize][j]);
                a22.setMatrix(i,j,A.getMatrix()[i + newSize][j+ newSize]);


                b11.setMatrix(i,j,B.getMatrix()[i][j]);
                b12.setMatrix(i,j,B.getMatrix()[i][j + newSize]);
                b21.setMatrix(i,j,B.getMatrix()[i + newSize][j]);
                b22.setMatrix(i,j,B.getMatrix()[i + newSize][j+ newSize]);    
                
            }
        }

        aResult = a11.sumMatrix(a22);
        bResult = b11.sumMatrix(b22);
        m1 = strassen(aResult,bResult,newSize);

        aResult = a21.sumMatrix(a22);
        m2 =strassen(aResult,b11,newSize);

        bResult = b12.subMatrix(b22);
        m3 = strassen(a11,bResult,newSize);

        bResult = b21.subMatrix(b11);
        m4 = strassen(a22,bResult,newSize);

        aResult = a11.sumMatrix(a12);
        m5 = strassen(aResult,b22,newSize);   

        aResult = a21.subMatrix(a11);
        bResult = b11.sumMatrix(b12);
        m6 = strassen(aResult,bResult,newSize);

        aResult = a12.subMatrix(a22);
        bResult = b21.sumMatrix(b22);
        m7 = strassen(aResult,bResult,newSize);

        Matrix aux1(newSize,newSize),aux2(newSize,newSize);
        
        aux1 = m1.sumMatrix(m4);
        aux2 = aux1.sumMatrix(m7);
        c11 = aux2.subMatrix(m5);
        
        c12 = m3.sumMatrix(m5);
        c21 = m2.sumMatrix(m4);

        aux1 = m1.sumMatrix(m3);
        aux2 = aux1.sumMatrix(m6);
        c22 = aux2.subMatrix(m2);

        Matrix result(size,size);

        for (int i = 0; i < newSize; i++) {
            for (int j = 0 ; j < newSize ; j++) {
                result.setMatrix(i,j,c11.getMatrix()[i][j]);
                result.setMatrix(i,j + newSize, c12.getMatrix()[i][j]);
                result.setMatrix(i + newSize,j, c21.getMatrix()[i][j]);
                result.setMatrix(i + newSize,j + newSize,c22.getMatrix()[i][j]);
   
            }
            
        }

        return result;
}


int main(){

    int m,n;
    cin >> m >> n;

    Matrix first(m,n);
    Matrix second(m,n);
    Matrix result(m,n);

    readFile(first,second);

    result = strassen(first,second,m);

    DEBUG{

        result.printMatrix();
        
    }
    
    return 0;
}