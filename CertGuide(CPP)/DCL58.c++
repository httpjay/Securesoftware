#include <iostream>

// Unsafe Example (DO NOT DO THIS)
namespace std {
    void myFunction() {  // Modifying the std namespace - Not Allowed
        std::cout << "Modifying std namespace" << std::endl;
    }
}

// Safe Example (Use your own namespace)
namespace MyNamespace {
    void myFunction() {
        std::cout << "Using a custom namespace safely" << std::endl;
    }
}

int main() {
    // MyNamespace::myFunction();  // Safe usage
    MyNamespace::myFunction();

    return 0;
}
