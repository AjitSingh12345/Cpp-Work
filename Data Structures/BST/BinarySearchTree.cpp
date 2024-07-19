#include "BinarySearchTree.h"
#include <queue>

// Creates an empty binary tree
BinarySearchTree::BinarySearchTree() {
    // root = new Node();
}

// Creates a binary tree with inital data to store
BinarySearchTree::BinarySearchTree(int data) {
    root = new Node(data);
}

// Creates a binary tree by copying an existing tree
BinarySearchTree::BinarySearchTree(const BinarySearchTree &rhs) {
    if (!rhs.root) return;
    root = new Node(rhs.root->data);

    // have q of processed nodes for each tree
    // when u pull from new_tree, set its L, R to vals of rhs 
    std::queue<Node*> new_tree{};
    std::queue<Node*> old_tree{};

    new_tree.push(root);
    old_tree.push(rhs.root);

    while (!new_tree.empty()) {
        Node* new_n = new_tree.front();
        new_tree.pop();

        Node* old_n = old_tree.front();
        old_tree.pop();

        if (old_n->left) {
            new_n->left = new Node(old_n->left->data);
            new_tree.push(new_n->left);
            old_tree.push(old_n->left);
        }
        if (old_n->right) {
            new_n->right = new Node(old_n->right->data);
            new_tree.push(new_n->right);
            old_tree.push(old_n->right);
        }
    }
}

// Destroys (cleans up) the tree
BinarySearchTree::~BinarySearchTree() {
    delete root;
}

// Adds data to the tree
void BinarySearchTree::insert(int data) {
    // std::cout << "insert " << data << std::endl;  
    // find where data fits
    // always insert as a child node
    if (!root) {
        root = new Node(data);
        return;
    }

    Node* curr = root;
    // std::cout << "i1 " << curr << std::endl;  
    while (curr) {
        // std::cout << "i2 " << curr->data << std::endl;  
        if (data >= curr->data) {
            // check if right child exists
            if (curr->right) {
                curr = curr->right;
            } else {
                // make data the right child
                curr->right = new Node(data);
                return;
            }
        } else {
            if (curr->left) {
                curr = curr->left;
            } else {
                // make this left child
                curr->left = new Node(data);
                return;
            }
        }
    }
}

// Removes data from the tree
void BinarySearchTree::remove(int data) {
    // std::cout << "enter rem " << data << std::endl;
    if (!exists(data)) return;

    // find data
    // track parents to invalidate their child thats removed
    Node* parent = nullptr;
    bool par_direc = false; // l = false, r = true
    Node* curr = root;
    while (curr) {
        if (data == curr->data) {
            if (curr->left || curr->right) {
                if (curr->left && curr->right) {
                    // curr->left becomes left child of left most node in curr->right
                    Node* l_child_of_r = curr->right;
                    while (l_child_of_r->left) {
                        l_child_of_r = l_child_of_r->left;
                    } 
                    l_child_of_r->left = curr->left;

                    // curr->right becomes new child of parent 
                    if (par_direc) {
                        parent->right = curr->right;
                    } else {
                        parent->left = curr->right;
                    }

                    // check if root needs reassignment
                    if (root == curr) root = curr->right;
                } else if (curr->left) {
                    // set parents child to curr->left
                    if (par_direc) {
                        parent->right = curr->left;
                    } else {
                        parent->left = curr->left;
                    }

                    // check if root needs reassignment
                    if (root == curr) root = curr->left;
                } else {
                    // set parents child to curr->right
                    if (par_direc) {
                        parent->right = curr->right;
                    } else {
                        parent->left = curr->right;
                    }

                    // check if root needs reassignment
                    if (root == curr) root = curr->right;
                }
            } else {
                if (par_direc) {
                    parent->right = nullptr;
                } else {
                    parent->left = nullptr;
                }
            }
            // done removing 
            delete curr;
            return;
        } else if (data > curr->data) {
            parent = curr;
            par_direc = true;
            curr = curr->right;
        } else {
            parent = curr;
            par_direc = false;
            curr = curr->left;
        }
    }
}

// Checks if data is in the tree
bool BinarySearchTree::exists(int data) const {
    Node* curr = root;
    while (curr) {
        if (data == curr->data) {
            return true;
        } else if (data < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return false;
}

void BinarySearchTree::inorderTraversal(Node* root, std::vector<int>& inorder) const {
    if (!root) return;

    // go left
    inorderTraversal(root->left, inorder);

    // process middle
    inorder.push_back(root->data);

    // go right
    inorderTraversal(root->right, inorder);
}

// Creates a vector representing the tree in alphabetical order
std::vector<int> BinarySearchTree::inorder() const {
    std::vector<int> inorder_;
    inorderTraversal(root, inorder_);
    return inorder_;
}

void BinarySearchTree::preorderTraversal(Node* root, std::vector<int>& preorder) const {
    if (!root) return;

    // process middle
    preorder.push_back(root->data);

    // go left
    preorderTraversal(root->left, preorder);

    // go right
    preorderTraversal(root->right, preorder);
}

// Creates a vector representing the tree in pre-order 
std::vector<int> BinarySearchTree::preorder() const {
    std::vector<int> preorder_;
    preorderTraversal(root, preorder_);
    return preorder_;
}

// Creates a vec representing the tree in post-order
std::vector<int> BinarySearchTree::postorder() const {
    std::vector<int> postorder_;
    postTraversal(root, postorder_);
    return postorder_;
}

void BinarySearchTree::postTraversal(Node* root, std::vector<int>& postorder) const {
    if (!root) return;

    // go left
    postTraversal(root->left, postorder);

    // go right
    postTraversal(root->right, postorder);

        // process middle
    postorder.push_back(root->data);
}

// Checks if two trees are equal
bool BinarySearchTree::operator==(const BinarySearchTree &other) const {
    std::vector<int> curr = inorder();
    std::vector<int> other_ = other.inorder();

    if (curr.size() != other_.size()) return false;
    for (int i = 0; i < curr.size(); ++i) if (curr[i] != other_[i]) return false;
    return true;
}

// Checks if two trees are not equal
bool BinarySearchTree::operator!=(const BinarySearchTree &other) const {
    return !(*this == other);
}

// Reads in ints from an input stream into the tree
std::istream& operator>>(std::istream &in, BinarySearchTree &tree) {
    int num{};
    while (in >> num) {
        tree.insert(num);
    }
    return in;
}

// Writes the ints, in-order, to an output stream
std::ostream& operator<<(std::ostream &out, const BinarySearchTree &tree) {
    std::vector<int> ret { tree.inorder() };
    for (int i : ret) out << i << " ";
    return out;
}
