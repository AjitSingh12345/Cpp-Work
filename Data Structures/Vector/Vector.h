

template<typename T>
class Vector {
Public:
// Constructors and destructor
    Vector();  // Default constructor
    explicit Vector(size_t initialSize);  // Constructor with initial size
    Vector(const Vector<T>& other);  // Copy constructor
    Vector<T>& operator=(const Vector<T>& other);  // Copy assignment operator
    ~Vector();  // Destructor

    // Element access
    T& operator[](size_t index);  // Access element at index (non-const version)
    const T& operator[](size_t index) const;  // Access element at index (const version)
    T& at(size_t index);  // Access element with bounds checking
    const T& at(size_t index) const;  // Access element with bounds checking (const version)

    // Capacity
    size_t getSize() const;  // Get current size of vector
    size_t getCapacity() const;  // Get current capacity of vector
    bool isEmpty() const;  // Check if vector is empty
    void clear();  // Clear the vector

    // Modifiers
    void pushBack(const T& value);  // Add element at the end
    void popBack();  // Remove element from the end
    void resize(size_t newSize);  // Resize vector
    void reserve(size_t newCapacity);  // Reserve capacity

    // Iterator support (optional)
    // T* begin();
    // T* end();
    // const T* begin() const;
    // const T* end() const;
Private:
    T* data; // need to use dynamic array bc we dont know size @ compile time
    size_t size;
    size_t capacity;
};

// Include template implementation
#include "Vector.hpp"