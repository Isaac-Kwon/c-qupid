#ifndef __QPSIGNALGAUSSIAN__
#define __QPSIGNALGAUSSIAN__ 1

#include "QPVector.hpp"
#include "QPMatrix.hpp"
#include "QPSignalBase.hpp"

class QPSignalGaussian: public QPSignalBase{
    public:
    QPSignalGaussian(const QPVector& x0, const double& amplitude, const QPMatrix& S);
    QPSignalGaussian(const double& x0, const double& y0, const double& amplitude, const double& sx, const double& sy, const double& srad);

    virtual double GetPDF(const double& x, const double& y);

    protected:
    private:
    QPVector fx0;
    QPMatrix fS;
};

#endif