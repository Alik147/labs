#ifndef complex_HPP
#define complex_HPP
#include <cmath>
class complex {
private:
    double re;
    double im;
public:
    complex(double re, double im = 0){
        this->re = re;
        this->im = im;
    }

    complex(){
        this->re = 0;
        this->im = 0;
    }
    double abs() const{
        return sqrt(re*re + im*im);
    }
    complex operator+(complex z){
        return complex(re + z.re, im + z.im);
    }

    complex operator-(complex z){
        return complex(re - z.re, im - z.im);
    }

    complex operator*(complex z){
        return complex(this->re * z.re - im * z.im, im * z.re + re * z.im);
    }

    complex operator/(complex z) {
         return complex((re * z.re + im * z.im) / (z.re * z.re + z.im * z.im),(im * z.re - re * z.im) / (z.re * z.re + z.im * z.im));
    }
    friend std::ostream& operator<<(std::ostream& os, const complex& z){
         os << z.re << '+' << z.im << 'i';
         return os;
    }
    void print(){
        std::cout << re << " + i" << im << std::endl;
    }
    friend bool operator>(const complex &z1, const complex &z2) {
    return (z1.abs() > z2.abs());
    }
    friend bool operator<(const complex &z1, const complex &z2) {
    return (z1.abs() < z2.abs());
    }
    friend bool operator==(const complex &z1, const complex &z2) {
    return (z1.im == z2.im && z1.re == z2.re);
    }
    friend bool operator!=(const complex &z1, const complex &z2) {
    return !(z1 == z2);
    }
    ~complex() = default;
};

#endif