#include <iostream>
class Animal {
    private:
        int _age;
        std::string _name;
        std::string _race;
    public:
        Animal(){}
        Animal(std::string name, int age, std::string race): _age(age),  _name(name), _race(race){}
        Animal(Animal& obj) {
            *this = obj;
            std::cout << "Copyyyyy.........!!!" << std::endl;
        }

        Animal &operator=(Animal& obj) {
            std::cout << "Operator = ......" << std::endl;
            _name = obj._name;
            _age = obj._age;
            _race = obj._race;
            return *this;
        }

        int getAge(void) const {
            return _age;
        }
        std::string getName(void) const {
            return _name;
        }
};

void display_object(Animal obj) {
    std::cout << obj.getName() << std::endl;
}

int get_value() {
    int a = 10;
    return a;
}

int main(void) {
    Animal cat("mimi", 4, "Nimri");
    Animal tigger(cat);
    // tigger = cat;
    display_object(tigger);
    int b = get_value();

}