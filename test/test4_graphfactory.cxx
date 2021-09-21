#include "QPDigitizerSquare.hpp"
#include "QPSignalGaussian.hpp"
#include "QPVector.hpp"
#include "QPMatrix.hpp"
#include "QPGraphFactory.hpp"
#include "deque"
#include "TCanvas.h"

void test4_graphfactory(){
    QPVector mu = QPVector(29.24*0.5, 26.88*0.5);
    // QPVector mu = QPVector(0, 0);

    // double sigma = 0.83*900;
    double sigma = 0.83*900;
    QPMatrix S = QPMatrix(2, 2, 4, sigma, 0., 0., sigma);
    
    QPDigitizerSquare * dig = new QPDigitizerSquare(292.4, 268.8, 10, 10);
    QPSignalGaussian  * sig = new QPSignalGaussian(mu, 537280, S);
    dig->InjectSignal(sig);

    QPGraphFactory* factory = new QPGraphFactory(dig, "one");

    TCanvas * c1 = new TCanvas("c1", "c1", 1800, 1800);
    c1->Divide(2,2);
    c1->cd(1);
    factory->AnalogSignal()->Draw("COLZ");
    c1->cd(2);
    TH2D* h2 = factory->DigitalSignal();
    h2->Draw("COLZ");
    factory->DrawDigitalSignalText(h2);
    c1->cd(3);
    TH2D* h3 = factory->DigitizedSignal(250);
    h3->Draw("COLZ");
    factory->DrawDigitalSignalText(h3);

    std::cout<<"Total "<<dig->GetFiredPixel(250).size()<<" Pixel "<<std::endl;



    
}

int main(){
    return 0;
}