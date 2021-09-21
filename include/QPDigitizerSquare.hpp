#ifndef __QPDIGITIZERSQUARE__
#define __QPDIGITIZERSQUARE__ 1

#include "QPDigitizerBase.hpp"
#include "QPPixel.hpp"

#include "TH2D.h"

class QPGraphFactory;

class QPDigitizerSquare: public QPDigitizerBase{
    public:
    QPDigitizerSquare(double sizex=1, double sizey=1, int npixx=1, int npixy=1);

    // virtual double GetAnalogSignal(const double& x, const double& y);

    virtual QPPixel* GetPixel(const int index);
    virtual QPPixel* GetPixel(const int i, const int j);

    protected:

    private:

    friend class QPGraphFactory;
};

#endif