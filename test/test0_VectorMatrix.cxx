#include "QPMath.hpp"
#include "QPMath.hpp"
#include "QPVector.hpp"
#include "QPMatrix.hpp"

#include "iostream"

void test0_VectorMatrix(){
    std::cout<<"Step1"<<std::endl;
    QPVector a(1,1);
    std::cout<<a.Print(true)<<std::endl;
    std::cout<<"Step2"<<std::endl;
    QPVector x0(1,0);
    QPMatrix(x0, 2).Print();
    std::cout<<"Step3"<<std::endl;
    QPMatrix S(2,2);
    std::cout<<"Step4"<<std::endl;
    S[0] = 1;S[1] = 0;S[2] = 0;S[3] = 1;
    std::cout<<S.Print(true)<<std::endl;
    std::cout<<(S*QPMatrix(x0,2)).Print(true)<<std::endl;
}

int main(){
    return 0;
}