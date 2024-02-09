#include <iostream>

/*class Fixed {
private:
    int _fixed_value;
    static const int _fract_bits = 16; // Nombre de bits réservés pour la partie fractionnaire

public:
    Fixed(const int n);
    int getFixedValue() const { return _fixed_value; }
};

Fixed::Fixed(const int n)
{
    std::cout << "Fixed Int Constructor called" << std::endl;
    this->_fixed_value = n << this->_fract_bits;
}

int main() {
    Fixed fixedObject(5);
    std::cout << "Fixed Value: " << fixedObject.getFixedValue() << std::endl;

    return 0;
}*/

#include <iostream>
#include <cmath>

int main() {
    float number = 3.14;
    float roundedNumber = roundf(number);

    std::cout << "Original Number: " << number << std::endl;
    std::cout << "Rounded Number: " << roundedNumber << std::endl;

    return 0;
} 

#include <iostream>
#include <sstream>
#include <limits>
#include <cctype>

class ScalarConverter {
public:
    static bool isValidNumber(const std::string& str) {
        if (str.empty()) return false;
        
        size_t f_count = 0;
        for (size_t i = 0; i < str.size(); ++i) {
            if (!isdigit(str[i])) {
                if (str[i] == 'f') {
                    // Check if 'f' is at the end and it's the only one
                    if (i != str.size() - 1 || f_count > 0) {
                        return false;
                    }
                    f_count++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }

    static void convert(const std::string& literal) {
        if (!isValidNumber(literal)) {
            std::cout << "Invalid number format" << std::endl;
            return;
        }
        
        std::istringstream iss(literal);

        if (literal.find('.') != std::string::npos) {
            // Float or double
            double d;
            if (iss >> d) {
                float f = static_cast<float>(d);
                int i = static_cast<int>(d);
                char c = static_cast<char>(d);

                std::cout << "char: ";
                if (std::isprint(c))
                    std::cout << "'" << c << "'" << std::endl;
                else
                    std::cout << "impossible" << std::endl;

                std::cout << "int: " << i << std::endl;
                std::cout << "float: " << f << "f" << std::endl;
                std::cout << "double: " << d << std::endl;
            } else {
                std::cout << "Conversion impossible" << std::endl;
            }
        } else {
            // Int or char
            int i;
            if (iss >> i) {
                char c = static_cast<char>(i);

                std::cout << "char: ";
                if (std::isprint(c))
                    std::cout << "'" << c << "'" << std::endl;
                else
                    std::cout << "impossible" << std::endl;

                std::cout << "int: " << i << std::endl;
                std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
                std::cout << "double: " << static_cast<double>(i) << std::endl;
            } else {
                std::cout << "Conversion impossible" << std::endl;
            }
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

    ScalarConverter::convert(argv[1]);

    return 0;
}
