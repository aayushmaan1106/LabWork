#include <iostream>
#include <string>
#include <sstream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    Complex(const std::string& str) {
        std::stringstream ss(str);
        ss >> real;
        char op;
        if (ss >> op) {
            if (op == '+' || op == '-') {
                ss >> imag;
                if (op == '-') {
                    imag = -imag;
                }
                // Strip the trailing 'i'
                char i_char;
                ss >> i_char; 
            }
        } else {
            imag = 0.0; 
        }
    }

    // Member function for addition
    Complex add(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    Complex multiply(const Complex& other) const {
        double r = (real * other.real) - (imag * other.imag);
        double i = (real * other.imag) + (imag * other.real);
        return Complex(r, i);
    }

    friend Complex subtract(const Complex& c1, const Complex& c2);
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};
Complex subtract(const Complex& c1, const Complex& c2) {
    return Complex(c1.real - c2.real, c1.imag - c2.imag);
}
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    if (c.imag >= 0)
        os << c.real << "+" << c.imag << "i";
    else
        os << c.real << c.imag << "i";
    return os;
}
std::istream& operator>>(std::istream& is, Complex& c) {
    std::string input;
    is >> input;
    c = Complex(input); 
    return is;
}

int main() {
    Complex num1("4+3i"); 
    Complex num2("2-1i");

    std::cout << "First Number: " << num1 << std::endl;
    std::cout << "Second Number: " << num2 << std::endl;

    // Operations
    Complex sum = num1.add(num2);
    Complex diff = subtract(num1, num2);
    Complex prod = num1.multiply(num2);

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << diff << std::endl;
    std::cout << "Product: " << prod << std::endl;

    // Dynamic runtime user input matching your requested format
    Complex userNum;
    std::cout << "\nEnter a complex number (e.g., 5+2i): ";
    std::cin >> userNum;
    std::cout << "You entered: " << userNum << std::endl;

    return 0;
}
