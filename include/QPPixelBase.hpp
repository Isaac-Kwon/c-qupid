#ifndef __QPPIXELBASE__
#define __QPPIXELBASE__ 1

class QPSignalBase;
class QPDigitizerBase;

class QPPixelBase{
    public:
    virtual ~QPPixelBase();
    virtual void Delete();
    double GetDigitalSignal();
    QPDigitizerBase* GetDigitizer(){return fDigitizer;}
    
    virtual double GetDigitalSignalOne(QPSignalBase* signal);

    protected:
    QPPixelBase(QPDigitizerBase* digitizer);
    private:
    QPDigitizerBase* fDigitizer=nullptr;
};

#endif