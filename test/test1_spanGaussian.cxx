#include "QPMath.hpp"
#include "QPMath.hpp"
#include "QPVector.hpp"
#include "QPMatrix.hpp"

#include "iostream"

#include "TH2D.h"

void test1_spanGaussian(){

    QPVector mu = QPVector(0,0);
    QPMatrix S = QPMatrix(2,2, 4, 3., 0., 0., 6.);


    TH2D* h1 = new TH2D("h1", "h1", 1000, -10, 10, 1000, -10, 10);

    for(int i=0; i<h1->GetXaxis()->GetNbins(); i++){
        for(int j=0; j<h1->GetYaxis()->GetNbins(); j++){
            double x = h1->GetXaxis()->GetBinCenter(i);
            double y = h1->GetYaxis()->GetBinCenter(j);
            QPVector X = QPVector(x,y);
            // std::cout<<"[i,j] = ["<<i<<","<<j<<"]"<<std::endl;
            double val = QPMath::Gaussian::MatrixForm2D(X,mu,S);
            h1->SetBinContent(i,j,val);

            // std::cout<<val<<std::endl;
            // break;
        }
        // break;
    }

    h1->Draw("COLZ");
    std::cout<<h1->Integral("width")<<std::endl;
    


}

int main(){
    return 0;
}