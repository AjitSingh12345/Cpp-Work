#include <iostream>
#include <sstream>
#include <vector>
#include "BinarySearchTree.h"  // Replace with your actual header file name

// Function to compare two vectors for equality
template<typename T>
bool vectorsEqual(const std::vector<T>& v1, const std::vector<T>& v2) {
    return v1.size() == v2.size() && std::equal(v1.begin(), v1.end(), v2.begin());
}

// Test function for BinarySearchTree class
void testBinarySearchTree() {
    // Test Case 1: Insertion and existence check
    std::cout << "Test 1: Insertion and existence check" << std::endl;
    {
        BinarySearchTree tree;
        tree.insert(50);
        tree.insert(30);
        tree.insert(70);
        tree.insert(20);
        tree.insert(40);
        tree.insert(60);
        tree.insert(80);

        std::vector<int> expectedExists = {20, 30, 40, 50, 60, 70, 80};
        for (int num : expectedExists) {
            if (!tree.exists(num)) {
                std::cerr << "Test Case 1 failed: Number " << num << " should exist." << std::endl;
                return;
            }
        }
    }

    // Test Case 2: Removal and existence check
    std::cout << "Test 2: Removal and existence check" << std::endl;
    {
        BinarySearchTree tree;
        tree.insert(50);
        tree.insert(30);
        tree.insert(70);
        tree.insert(20);
        tree.insert(40);
        tree.insert(60);
        tree.insert(80);

        tree.remove(20);
        tree.remove(70);
        tree.remove(30);

        std::vector<int> expectedNotExists = {20, 30, 70};
        for (int num : expectedNotExists) {
            if (tree.exists(num)) {
                std::cerr << "Test Case 2 failed: Number " << num << " should not exist." << std::endl;
                return;
            }
        }
    }

    // Test Case 3: In-order traversal
    std::cout << "Test 3: In-order traversal" << std::endl;
    {
        BinarySearchTree tree;
        tree.insert(50);
        tree.insert(30);
        tree.insert(70);
        tree.insert(20);
        tree.insert(40);
        tree.insert(60);
        tree.insert(80);

        std::vector<int> expectedInorder = {20, 30, 40, 50, 60, 70, 80};
        if (!vectorsEqual(tree.inorder(), expectedInorder)) {
            std::cerr << "Test Case 3 failed: In-order traversal incorrect." << std::endl;
            return;
        }
    }

    // Test Case 4: Pre-order traversal
    std::cout << "Test 4: Pre-order traversal" << std::endl;
    {
        BinarySearchTree tree;
        tree.insert(50);
        tree.insert(30);
        tree.insert(70);
        tree.insert(20);
        tree.insert(40);
        tree.insert(60);
        tree.insert(80);

        std::vector<int> expectedPreorder = {50, 30, 20, 40, 70, 60, 80};
        if (!vectorsEqual(tree.preorder(), expectedPreorder)) {
            std::cerr << "Test Case 4 failed: Pre-order traversal incorrect." << std::endl;
            return;
        }
    }

    // Test Case 5: Post-order traversal
    std::cout << "Test 5: Post-order traversal" << std::endl;
    {
        BinarySearchTree tree;
        tree.insert(50);
        tree.insert(30);
        tree.insert(70);
        tree.insert(20);
        tree.insert(40);
        tree.insert(60);
        tree.insert(80);

        std::vector<int> expectedPostorder = {20, 40, 30, 60, 80, 70, 50};
        if (!vectorsEqual(tree.postorder(), expectedPostorder)) {
            std::cerr << "Test Case 5 failed: Post-order traversal incorrect." << std::endl;
            return;
        }
    }

    // Test Case 6: Equality operator and copy constructor
    std::cout << "Test 6: Equality operator and copy constructor" << std::endl;
    {
        BinarySearchTree tree1;
        tree1.insert(50);
        tree1.insert(30);
        tree1.insert(70);

        BinarySearchTree tree2 = tree1;  // Test copy constructor
        BinarySearchTree tree3;
        tree3.insert(50);
        tree3.insert(30);

        if (!(tree1 == tree2) || (tree1 == tree3)) {
            std::cerr << "Test Case 6 failed: Equality operator or copy constructor incorrect." << std::endl;
            return;
        }
    }

    // Test Case 7: Input/Output stream operators
    std::cout << "Test 7: Input/Output stream operators" << std::endl;
    {
        std::stringstream ss("50 30 70 20 40 60 80");
        BinarySearchTree tree;
        ss >> tree;

        std::stringstream ssExpected("20 30 40 50 60 70 80 ");
        BinarySearchTree expectedTree;
        ssExpected >> expectedTree;

        if (!(tree == expectedTree)) {
            std::cout << ssExpected.str() << std::endl;
            std::cerr << "Test Case 7 failed: Input stream operator incorrect." << std::endl;
            return;
        }

        std::stringstream ssOut;
        ssOut << tree;

        if (ssOut.str() != "20 30 40 50 60 70 80 ") {
            std::cout << ssOut.str() << std::endl;
            std::cerr << "Test Case 7 failed: Output stream operator incorrect." << std::endl;
            return;
        }
    }

    std::cout << "All test cases passed!" << std::endl;
}

// Main function to run the test suite
// int main() {
//     testBinarySearchTree();
//     return 0;
// }
