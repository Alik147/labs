#ifndef COMPLEX_HPP
#define COMPLEX_HPP

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

    void print(){
        std::cout << re << " + i" << im << std::endl;
    }

    ~complex() = default;
};

#endif