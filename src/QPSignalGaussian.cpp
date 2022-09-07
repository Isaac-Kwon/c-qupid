#include "QPSignalGaussian.hpp"
#include "QPMatrix.hpp"
#include "QPMath.hpp"
#include "QPVector.hpp"

QPSignalGaussian::QPSignalGaussian(const QPVector& x0, const double& amplitude, const QPMatrix& S): QPSignalBase(amplitude), fx0(x0),fS(S){;}

QPSignalGaussian::QPSignalGaussian(const double& x0, const double& y0, const double& amplitude, const double& sx, const double& sy, const double& srad): QPSignalBase(amplitude){
    fx0 = QPVector(x0,y0);
    fS  = QPMatrix(2,2,4,sx,0,0,sy)*QPMath::RotationMatrix(srad);
}

double QPSignalGaussian::GetPDF(const double& x, const double& y){
    QPVector X = QPVector(x,y);
    return QPMath::Gaussian::MatrixForm2D(X, fx0, fS);
}