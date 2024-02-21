#include <iostream>
using namespace std;


class ABase {
    private:
        int _a;
    public:
        ABase(int a): _a(a){}
        virtual void print() = 0;
        int getA() const {
            return _a;
        }
};

class Child: public ABase {
    public:
        Child(int a): ABase(a) {}
        void print() {
            cout << "child " << endl;
        }
};


int main() {
    Child a(10);

    cout << a.getA() << endl;
    return 0;
}