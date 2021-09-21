#ifndef __QPDIGITIZERBASE__
#define __QPDIGITIZERBASE__ 1

#include "deque"

class QPSignalBase;
class QPPixelBase;

class QPDigitizerBase{
    public:
    virtual ~QPDigitizerBase();
    virtual void Delete();

    void InjectSignal(QPSignalBase* signal);
    QPSignalBase * GetSignal(int i);
    int GetNSignal();
    void ClearSignal(bool removeall=true);
    
    virtual double GetAnalogSignal(const double& x, const double& y);

    virtual QPPixelBase* GetPixel(const int index);
    virtual QPPixelBase* GetPixel(const int i, const int j);

    std::deque<QPPixelBase*> GetFiredPixel(double threshold);

    int GetNPixel(){return fNpix0;}

    double GetSizeX(){return fSize[0];}
    double GetSizeY(){return fSize[1];}
    double GetNPixelX(){return fNpix[0];}
    double GetNPixelY(){return fNpix[1];}

    protected:
    QPDigitizerBase(int npix);
    double fSize[2];
    int    fNpix[2];

    private:
    int    fNpix0=0;

    std::deque<QPSignalBase*> fSignals;
};

#endif