#ifndef __QPPIXEL__
#define __QPPIXEL__ 1

#include "QPPixelBase.hpp"

class QPSignalBase;
class QPDigitizerSquare;

class QPPixel: public QPPixelBase{
    public:
    QPPixel(const double & x0,  const double & y0,
            const double & x1,  const double & y1,
            QPDigitizerBase* digitizer=nullptr,
            const int    & i=0, const int   & j=0);
    virtual ~QPPixel();
    virtual void    Delete();
    virtual double  GetDigitalSignalOne(QPSignalBase * signal);

    int GetPixX(){return fIndX;}
    int GetPixY(){return fIndY;}
    int GetPixelSizeX(){return fx1-fx0;}
    int GetPixelSizeY(){return fy1-fy0;}
    protected:
    private:
    double fx0=0.;
    double fy0=0.;
    double fx1=1.;
    double fy1=1.;

    int    fIndX = 0;
    int    fIndY = 0;
};

#endif