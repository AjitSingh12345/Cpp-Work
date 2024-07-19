// make sure this file can only be included once
#pragma once

#include <iostream>
#include <string>
#include <vector>

// store nodes in the tree
struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    int data;

    Node(int d): data{ d } {}
    Node() {}
};

class BinarySearchTree {
public:
    // Creates an empty binary tree
    BinarySearchTree();
    // Creates a binary tree with an inital word to store
    BinarySearchTree(int data);
    // Creates a binary tree by copying an existing tree
    BinarySearchTree(const BinarySearchTree &rhs);
    // Destroys (cleans up) the tree
    ~BinarySearchTree();
    // Adds data to the tree
    void insert(int data);
    // Removes data from the tree
    void remove(int data);
    // Checks if data is in the tree
    bool exists(int data) const;
    // Creates a vector representing the tree in alphabetical order
    std::vector<int> inorder() const;
    // Creates a vector representing the tree in pre-order
    std::vector<int> preorder() const;
    // Creates a vec representing the tree in post-order
    std::vector<int> postorder() const;
    // Checks if two trees are equal
    bool operator==(const BinarySearchTree &other) const;
    // Checks if two trees are not equal
    bool operator!=(const BinarySearchTree &other) const;
    // Reads in ints from an input stream into the tree
    friend std::istream& operator>>(std::istream &in, BinarySearchTree &tree);
    // Writes the ints, in-order, to an output stream
    friend std::ostream& operator<<(std::ostream &out, const BinarySearchTree &tree);

    // helpers
    void inorderTraversal(Node* root, std::vector<int>& inorder) const;
    void preorderTraversal(Node* root, std::vector<int>& preorder) const;
    void postTraversal(Node* root, std::vector<int>& postorder) const;
private:
    Node* root = nullptr;
};