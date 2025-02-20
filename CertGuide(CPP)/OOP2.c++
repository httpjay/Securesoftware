#include <iostream>

class Base {
public:
    Base() { std::cout << "Base Constructor\n"; }
    virtual ~Base() { std::cout << "Base Destructor\n"; }  // Fix: Virtual Destructor

    virtual void show() { std::cout << "Base class show\n"; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived Constructor\n"; }
    ~Derived() { std::cout << "Derived Destructor\n"; }  // Ensures proper cleanup

    void show() override { std::cout << "Derived class show\n"; }
};

int main() {
    Base* obj = new Derived();  // Polymorphic object
    obj->show();
    delete obj;  // Correctly calls both destructors due to virtual keyword

    return 0;
}
