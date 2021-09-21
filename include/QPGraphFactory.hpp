#ifndef __QPGRAPHFACTORY__
#define __QPGRAPHFACTORY__ 1

#include "string"

class QPDigitizerBase;
class TH2D;

class QPGraphFactory{
    public:
    QPGraphFactory(QPDigitizerBase* digitizer, std::string name);

    TH2D * AnalogSignal(int ndiv=100);
    TH2D * DigitalSignal();
    TH2D * DigitizedSignal(double threshold=0.1);

    void   DrawDigitalSignalText(TH2D* h=nullptr);
    void   DrawPixelLinse(TH2D* h=nullptr);

    QPDigitizerBase* GetDigitizer(){return fDigitizer;}

    protected:

    private:
    QPDigitizerBase* fDigitizer = nullptr;
    std::string fName = "fac1";

};



#endif