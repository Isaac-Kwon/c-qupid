#include "QPPixel.hpp"
#include "QPDigitizerSquare.hpp"
#include "QPSignalBase.hpp"

QPPixel::QPPixel(const double & x0,  const double & y0,
                 const double & x1,  const double & y1,
                 QPDigitizerBase* digitizer,
                 const int    & i, const int    & j): QPPixelBase(digitizer),
                                                      fx0(x0), fy0(y0),
                                                      fx1(x1), fy1(y1),
                                                      fIndX(i), fIndY(j) {
}

QPPixel::~QPPixel(){;}

void QPPixel::Delete(){;}

double QPPixel::GetDigitalSignalOne(QPSignalBase * signal){
    return signal->Integral(fx0, fx1, fy0, fy1);
}
