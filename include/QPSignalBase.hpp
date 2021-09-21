#ifndef __QPSIGNALBASE__
#define __QPSIGNALBASE__ 1

class QPSignalBase{
    public:
    virtual ~QPSignalBase();
    virtual void   Delete();
    double GetSignal(const double& x, const double& y);
    double Integral(const double& x0, const double& x1, const double& y0, const double& y1);
    
    virtual double GetPDF(const double& x, const double& y);

    protected:
    QPSignalBase(const double& amplitude);

    private:
    double fAmplitude;
};

#endif