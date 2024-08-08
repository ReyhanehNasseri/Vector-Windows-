#include <iostream>
#include <array>
class Cube {

public:
    Cube(){}
    Cube(double _A, double _B, double _C): A(_A), B(_B), C(_C){
    }
public:
    double EvalVolume(){
        return A * B * C;
    }
    std::array<double, 3> GetAll(){
        auto tmp {std::array<double, 3>()};
        tmp[0]=A;
        tmp[1]=B;
        tmp[2]=C;
        return tmp;
    }
    void SetAll(double _A, double _B, double _C){
        A=_A;
        B=_B;
        C=_C;
    }
    void SetA(double x){
        A=x;
    }
    void SetB(double x){
        B=x;
    }
    void SetC(double x){
        C=x;
    }
    const double& GetA(){
        return A;
    }
    const double& GetB(){
        return B;
    }
    const double& GetC(){
        return C;
    }

    void getdensity(double _density){
        density=_density;
    }
    double evalmass(){
        return (density)*(EvalVolume());

    }
     double evalsurface(){
        return 2*(A*B + B*C + A*C);
    }
    
private:
    double A, B, C, Volume , density;
};

class sphere
{
public:
    sphere()
    {R = 0;}

    sphere(double a)
    {R = a;}

    double EvalVolume()
    {
        return (4/3) * pi * (R*R*R);
    }

    void getR(double a)
    {
        R = a;
    }
    void getdensity(double _density){
        density=_density;
    }
    double evalmass(){
        return (density)*(EvalVolume());

    }
     double evalsurface(){
        return 4*pi*R*R;
    }
   
private:
    double R;
    float pi = 3.14159;
    double density;
};


class pyramid
{
public:
    pyramid(){
         A = 0;
         H = 0;
    }
    pyramid(double a , double b)
    {
       A = a;
       H = b;
    }
    double EvalVolume()
    {
        return (1/3) * H * A * A;
    }
    void getA_H(double a , double b)
    {
        A = a;
        H = b;
    }
    void getdensity(double _density){
        density=_density;
    }
    double evalmass(){
        return (density)*(EvalVolume());

    }

private:
    double A , H , density;
};




class cylinder
{
public:
    cylinder(){
        A = 0;
        H = 0;
    }
    cylinder(double a , double b)
    {
        A = a;
        H = b;
    }
    double EvalVolume()
    {
        return H * (pi * A * A);
    }
    void getA_H(double a , double b)
    {
        A = a;
        H = b;
    }
    void getdensity(double _density){
        density=_density;
    }
    double evalmass(){
        return (density)*(EvalVolume());

    }

private:
    double A , H , density;
    float pi = 3.14159;
};
