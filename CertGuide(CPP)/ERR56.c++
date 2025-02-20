#include <iostream>
#include <stdexcept>

class SafeContainer {
    int* data;
    size_t size;

public:
    SafeContainer(size_t s) : size(s), data(new int[s]) {
        std::cout << "Resource allocated\n";
    }

    // Copy Constructor with exception safety
    SafeContainer(const SafeContainer& other) : size(other.size), data(nullptr) {
        std::cout << "Copy constructor called\n";

        int* temp = new int[other.size];  // Step 1: Allocate new memory (safety net)
        for (size_t i = 0; i < other.size; ++i) {
            temp[i] = other.data[i];  // Step 2: Copy elements safely
        }

        data = temp;  // Step 3: Assign the new resource only after successful copying
    }

    ~SafeContainer() {
        delete[] data;
        std::cout << "Resource deallocated\n";
    }
};

int main() {
    try {
        SafeContainer obj1(5);
        SafeContainer obj2 = obj1;  // Calls exception-safe copy constructor
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
