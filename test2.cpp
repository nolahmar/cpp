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