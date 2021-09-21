#ifndef __QPVECTOR__
#define __QPVECTOR__ 1

#include "string"
#include "iostream"

class QPVector{
    public:
    QPVector();
    QPVector(double x, double y);
    QPVector(double x, double y, double z);
    QPVector(const QPVector& other);

    //Get
    double    X();
    double    Y();
    double    Z();
    void      Get(double& x, double& y, double& z);
    QPVector  Unit();

    //Operator, returning result
    inline double    Dot(QPVector other) const;
    inline QPVector  Cross(QPVector other) const;
    QPVector  Scale(double& number);
    double    Norm();
    double    Norm2();

    //Operator, Self operation 
    void      AddThis(const QPVector& other);
    void      SubstractThis(const QPVector& other);
    void      CrossThis(const QPVector& other);
    void      ScaleThis(const double& number);

    //Operator, Coveniences
    // QPVector& operator+(const QPVector& other); //Add
    // QPVector& operator-(const QPVector& other); //Substract
    // double    operator*(const QPVector& other); //Dot product
    // QPVector& operator*(const double&   other); //Scaling
    // QPVector& operator^(const QPVector& other); //Cross product

    inline QPVector & operator=(const QPVector& other);

    friend QPVector operator+(QPVector& a, QPVector& b);
    friend QPVector operator+(QPVector  a, QPVector  b);
    // friend QPVector operator-(QPVector& a, QPVector& b);
    friend QPVector operator-(QPVector  a, QPVector  b);
    // friend QPVector operator^(QPVector& a, QPVector& b);
    friend QPVector operator^(QPVector  a, QPVector  b);
    // friend QPVector operator* (QPVector &vec,   double  other);
    // friend QPVector operator* (double    other, QPVector& vec);
    friend QPVector operator* (QPVector vec,   double  other);
    friend QPVector operator* (double    other, QPVector vec);
    // friend double   operator* (QPVector& other, QPVector& vec);
    friend double   operator* (QPVector other, QPVector vec);

    inline QPVector& operator+=(const QPVector& other); //Add
    inline QPVector& operator-=(const QPVector& other); //Substract
    inline QPVector& operator*=(const double&   other); //Scaling
    inline QPVector& operator^=(const QPVector& other); //Cross product

    inline double& operator()(const int& i);
    inline double& operator[](const int& i);

    double    GetAngle(QPVector other);
    double    GetAngleDegree(QPVector other);

    std::string Print(bool quite=false);

    protected:
    private:
    double fX=0., fY=0., fZ=0;

};

inline QPVector& QPVector::operator=(const QPVector& other){
    fX = other.fX;
    fY = other.fY;
    fZ = other.fZ;
    return *this;
}

inline QPVector& QPVector::operator+=(const QPVector& other){
    fX += other.fX;
    fY += other.fY;
    fZ += other.fX;
    return (*this);
}

inline QPVector& QPVector::operator-=(const QPVector& other){
    fX -= other.fX;
    fY -= other.fY;
    fZ -= other.fX;
    return (*this);
}

inline QPVector& QPVector::operator*=(const double&   other){
    fX *= other;
    fY *= other;
    fZ *= other;
    return (*this);
}

inline QPVector& QPVector::operator^=(const QPVector& other){
    fX = fY*other.fZ-fY*other.fZ;
    fY = fZ*other.fX-fX*other.fZ;
    fZ = fX*other.fY-fY*other.fX;
    return (*this);
}

inline double& QPVector::operator()(const int& i){
    if(i>2) std::cout<<"QPVector::operator() - Index is over 3\t:\t" << i <<std::endl;
    double * val[3] = {&fX, &fY, &fZ};
    return *(val[i]);
}

inline double& QPVector::operator[](const int& i){
    if(i>2) std::cout<<"QPVector::operator[] - Index is over 3\t:\t" << i <<std::endl;
    double * val[3] = {&fX, &fY, &fZ};
    return *(val[i]);
}


inline double    QPVector::Dot(QPVector other) const{
    return fX*other.fX + fY*other.fY + fZ*other.fZ;
}

inline QPVector  QPVector::Cross(QPVector other) const{
    return QPVector(fY*other.fZ-other.fY*fZ, fZ*other.fX-other.fZ*fX, fX*other.fY-other.fX*fY);
}

// QPVector operator+ ( QPVector &, QPVector & );
QPVector operator+ ( QPVector  , QPVector   );
// QPVector operator- ( QPVector &, QPVector & );
QPVector operator- ( QPVector  , QPVector   );
// QPVector operator^ ( QPVector &, QPVector & );
QPVector operator^ ( QPVector  , QPVector   );

// QPVector operator* ( QPVector & ,  double  a );
// QPVector operator* ( double   a ,  QPVector & );
// double   operator* ( QPVector & ,  QPVector & );

QPVector operator* ( QPVector  ,  double  a );
QPVector operator* ( double   a ,  QPVector  );
double   operator* ( QPVector  ,  QPVector  );

#endif