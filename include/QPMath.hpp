#ifndef __QPMATH__
#define __QPMATH__ 1

#include "QPVector.hpp"
#include "QPMatrix.hpp"

namespace QPMath{

    const double InvPi        = 0.3183098861837906715377675267450287240689192;
    const double InvSqrtPi    = 0.5641895835477562869480794515607725858440506;
    const double InvSqrt2Pi   = 0.3989422804014326779399460599343818684758586;
    const double Degree       = 0.01745329251994329576923690768488612713442871;    
    const double Pi           = 3.1415926535897932384626433832795028841971693;

    namespace Gaussian{
        // Simplest Gaussian Distribution (General)
        double Simple1D(double x,
                          double integral        =1., 
                          double mean            =0., 
                          double sigma           =1.);
        double Simple2D(double x,
                          double y,
                          double integral      =1.,
                          double meanx         =0,
                          double meany         =0,
                          double sigma         =1.);
        double UniAxis2D(double x,
                           double y,
                           double integral     =1.,
                           double meanx        =0.,
                           double meany        =0.,
                           double sigmax       =1.,
                           double sigmay       =1.);
        double RotAxis2D(double x,
                           double y,
                           double integral     = 1.,
                           double meanx        = 0.,
                           double meany        = 0.,
                           double sigmax       = 1.,
                           double sigmay       = 1.,
                           double rotation     = 0.);
        double Assymetry2D(double x,
                             double y,
                             double integral   = 1.,
                             double meanx      = 0.,
                             double meany      = 0.,
                             double sigmax     = 1.,
                             double sigmay     = 1.,
                             double rotation   = 0.,
                             double length     = 0.,
                             double tilt       = 0.,
                             double dispersion = 1.);
        double MatrixForm2D(QPVector& x, QPVector& x0, QPMatrix& S);
    };

    namespace WoodSaxon{
        double Simple1D(double x,
                          double maximum = 1.0,
                          double mean    = 0.0,
                          double a       = 1.0,
                          double radius  = 1.0);
        double Simple2D(double x,
                          double y,
                          double maximum = 1.0,
                          double meanx   = 0.0,
                          double meany   = 0.0,
                          double a       = 1.0,
                          double radius  = 1.0);
        double UniAxis2D(double x,
                           double y,
                           double maximum = 1.0,
                           double meanx   = 0.0,
                           double meany   = 0.0,
                           double ax      = 1.0,
                           double ay      = 1.0,
                           double radiusX = 1.0,
                           double radiusY = 1.0); //Non-Isometric but same with axis XY
        double RotAxis2D(double x,
                           double y,
                           double maximum  = 1.0,
                           double meanx    = 0.0,
                           double meany    = 0.0,
                           double ax       = 1.0,
                           double ay       = 1.0,
                           double radiusX  = 1.0,
                           double radiusY  = 1.0,
                           double rotation = 0.0); //Non-Isometric but same with axis XY
        double RotAxis2DUnsync(double x,
                                 double y,
                                 double maximum  = 1.0,
                                 double meanx    = 0.0,
                                 double meany    = 0.0,
                                 double ax       = 1.0,
                                 double ay       = 1.0,
                                 double radiusX  = 1.0,
                                 double radiusY  = 1.0,
                                 double rotationA = 0.0,
                                 double rotationR = 0.0); //Non-Isometric but same with axis XY
    };
    
    namespace GeometryCalc{
        double EllipseUniAxis(double x, double y, double lx, double ly); 
        double EllipseRotAxis(double x, double y, double lx, double ly, double theta);
        double Angle(double x, double y, double centx=0., double centy=0.);
    };

    double Sqrt(const double& x);
    double Power(const double& x, const double& exponent);

    double Sin(const double& x);
    double Cos(const double& x);
    double ATan(const double& x);
    double ATan2(const double& y, const double& x);
    double Exp(const double& x);
    double Gaus(const double& x, const double& mean, const double& sigma, const bool& norm);

};

#endif