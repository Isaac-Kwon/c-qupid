#include "QPDigitizerSquare.hpp"
#include "QPSignalGaussian.hpp"
#include "QPVector.hpp"
#include "QPMatrix.hpp"
#include "deque"

void test3_digitizer(){
    QPVector mu = QPVector(0,0);

    double sigma = 0.83*900;
    QPMatrix S = QPMatrix(2, 2, 4, sigma, 0., 0., sigma);
    
    QPDigitizerSquare * dig = new QPDigitizerSquare(292.4*2, 268.8*2, 20, 20);
    QPSignalGaussian  * sig = new QPSignalGaussian(mu, 537280, S);
    dig->InjectSignal(sig);

    std::deque<QPPixelBase*> pixels = dig->GetFiredPixel(250);

    std::cout<<"Fired pixels"<<std::endl;
    for(QPPixelBase* pixx : pixels){
        QPPixel* pix = (QPPixel*)pixx;
        std::cout<< "[x,y] = [" << pix->GetPixX() <<","<<pix->GetPixY()<<"], signal= " << pix->GetDigitalSignal() <<std::endl; 
    }
    std::cout<<"Total "<<pixels.size()<<" pixels"<<std::endl;
}

int main(){
    return 0;
}