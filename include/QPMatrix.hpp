#ifndef __QPMATRIX__
#define __QPMATRIX__ 1

#include "string"
#include "vector"
#include "QPVector.hpp"

class QPMatrix{
    public:
    QPMatrix(); //Null Matrix
    QPMatrix(const int n); //n x n Unit Matrix
    // QPMatrix(const int m, const int n); //Arb matrix of n x m, zero matrix
    QPMatrix(const int m, const int n);  //Arb matrix of n x m, selected number, Zero Matrix
    QPMatrix(const int m, const int n, const int npassed, ...); //Arb matrix of n x m
    QPMatrix(QPVector& vec); // GSVector (3) -> QPMatrix (1x4)
    QPMatrix(const QPMatrix& other); //Copy Construction
    QPMatrix(QPVector& vec, int ncomp);

    QPMatrix& operator=(const QPMatrix&);

    ~QPMatrix();
    QPMatrix Transpose();
    double   Det();
    double   Trace();
    QPMatrix SubMatrix(const int i, const int j);
    double   Cofactor(const int i, const int j);
    QPMatrix Inverse();
    double   At(int i);
    double   At(int i, int j);
    double&  operator[](int i);
    double&  operator()(int i);
    double&  operator()(int i, int j);
    bool     IsInside(int i);
    bool     IsInside(int i, int j);
    bool     IsSameShape(QPMatrix & other);
    bool     IsTransShape(QPMatrix & other);
    std::string Print(bool quite=false);

    friend QPMatrix operator*(QPMatrix , double  );
    friend QPMatrix operator*(double  , QPMatrix );
    friend QPMatrix operator*(QPMatrix   , QPMatrix   );
    friend QPMatrix operator+(QPMatrix &  , QPMatrix  & );
    friend QPMatrix operator-(QPMatrix &  , QPMatrix  & );

    inline QPMatrix& operator*=(const double& other); //Scaling


    protected:
    void     Freeing();

    private:
    void Init();
    double * fElement;
    int fM=1;
    int fN=1;

    double nval=-1;
};

QPMatrix operator*(QPMatrix , double   );
QPMatrix operator*(double   , QPMatrix );
QPMatrix operator*(QPMatrix , QPMatrix );
QPMatrix operator+(QPMatrix & , QPMatrix & );
QPMatrix operator-(QPMatrix & , QPMatrix & );

inline QPMatrix& QPMatrix::operator*=(const double&   other){
    for(int i=0; i<fM*fN; i++){
        fElement[i] *= other;
    }
    return (*this);
}

#endif