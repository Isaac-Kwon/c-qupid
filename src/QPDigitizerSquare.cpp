#include "QPPixel.hpp"
#include "QPDigitizerSquare.hpp"

QPDigitizerSquare::QPDigitizerSquare(double sizex, double sizey, int npixx, int npixy): QPDigitizerBase(npixx*npixy){
    fSize[0] = sizex;
    fSize[1] = sizey;

    fNpix[0] = npixx;
    fNpix[1] = npixy;

    return;
}

QPPixel* QPDigitizerSquare::GetPixel(const int i){
    if(i > fNpix[0]*fNpix[1]) return nullptr;

    return GetPixel(i/fNpix[0], i%fNpix[0]);
}

QPPixel* QPDigitizerSquare::GetPixel(const int i, const int j){
    if(i < 0|| fNpix[0] < i) return nullptr;
    if(j < 0|| fNpix[1] < j) return nullptr;

    double xoff = -fSize[0]/2;
    double yoff = -fSize[1]/2;

    return new QPPixel(
        (fSize[0])/(fNpix[0])*i     + xoff,
        (fSize[1])/(fNpix[1])*j     + yoff,
        (fSize[0])/(fNpix[0])*(i+1) + xoff,
        (fSize[1])/(fNpix[1])*(j+1) + yoff, 
        this, i, j
    );
}
