// #include <iostream>
// #include "Vector.h"  // Include the header file for Vector

// // Function to compare two vectors for equality
// template<typename T>
// bool vectorsEqual(const Vector<T>& v1, const Vector<T>& v2) {
//     if (v1.getSize() != v2.getSize()) {
//         return false;
//     }
//     for (size_t i = 0; i < v1.getSize(); ++i) {
//         if (v1[i] != v2[i]) {
//             return false;
//         }
//     }
//     return true;
// }

// // Test function for Vector class
// void testVector() {
//     // Test Case 1: Default constructor and size check
//     Vector<int> v1;
//     if (v1.getSize() != 0 || !v1.isEmpty()) {
//         std::cerr << "Test Case 1 failed: Default constructor issue." << std::endl;
//         return;
//     }

//     // Test Case 2: Constructor with initial size and element access
//     Vector<int> v2(5);
//     for (size_t i = 0; i < v2.getSize(); ++i) {
//         v2[i] = static_cast<int>(i);
//     }
//     for (size_t i = 0; i < v2.getSize(); ++i) {
//         if (v2[i] != static_cast<int>(i)) {
//             std::cerr << "Test Case 2 failed: Constructor with initial size or element access issue." << std::endl;
//             return;
//         }
//     }

//     // Test Case 3: Copy constructor and equality check
//     Vector<int> v3(v2);
//     if (!vectorsEqual(v2, v3)) {
//         std::cerr << "Test Case 3 failed: Copy constructor issue." << std::endl;
//         return;
//     }

//     // Test Case 4: Modify original after copy and validate no changes in copy
//     v2[0] = 100;
//     if (v2[0] == v3[0]) {
//         std::cerr << "Test Case 4 failed: Copy constructor does not maintain deep copy." << std::endl;
//         return;
//     }

//     // Test Case 5: Copy of empty vector should also be empty
//     Vector<int> v4;
//     Vector<int> v5 = v4;
//     if (!vectorsEqual(v4, v5) || v5.getSize() != 0 || !v5.isEmpty()) {
//         std::cerr << "Test Case 5 failed: Copy constructor for empty vector issue." << std::endl;
//         return;
//     }

//     // Test Case 6: Copy self-assignment should result in an identical vector
//     v2 = v2;
//     if (!vectorsEqual(v2, v2)) {
//         std::cerr << "Test Case 6 failed: Self-assignment issue." << std::endl;
//         return;
//     }

//     // Test Case 7: Copy constructor with resizing
//     v2.resize(10);
//     Vector<int> v6 = v2;
//     if (!vectorsEqual(v2, v6) || v6.getSize() != 10) {
//         std::cerr << "Test Case 7 failed: Copy constructor with resizing issue." << std::endl;
//         return;
//     }

//     std::cout << "All test cases passed!" << std::endl;
// }

// // Main function to run the test suite
// // int main() {
// //     testVector();
// //     return 0;
// // }
