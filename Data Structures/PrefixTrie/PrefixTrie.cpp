#include "PrefixTrie.h"

PrefixTrie::PrefixTrie(): isRoot(true) {} 

PrefixTrie::PrefixTrie(char data_): isRoot(true), data(data_) {} 

PrefixTrie::~PrefixTrie() {
    // for (auto& entry : children) {
    //     delete entry.second;   
    // }
    // delete this;
}

void PrefixTrie::insert(const std::string& word) {
    PrefixTrie* curr = this;
    for (char c : word) {
        if (curr->children.count(c) == 0) {
            curr->children[c] = new PrefixTrie(c);
        }
        curr = children[c];
    }
    curr->isEndOfWord = true;
}

bool PrefixTrie::search(const std::string& word) {
    PrefixTrie* curr = this;
    for (char c : word) {
        if (curr->children.find(c) == curr->children.end()) {
            return false;
        }
        curr = children[c];
    }
    return curr->isEndOfWord;
}

bool PrefixTrie::startsWith(const std::string& prefix) {
    PrefixTrie* curr = this;
    for (char c : prefix) {
        if (curr->children.find(c) == curr->children.end()) {
            return false;
        }
        curr = children[c];
    }
    return true;
}

std::vector<std::string> PrefixTrie::autoComplete(const std::string& prefix) {
    std::vector<std::string> ret{};
    PrefixTrie* curr = this;
    for (char c : prefix) curr = children[c]; 
    makeWords(curr, prefix, ret);
    return ret;
}

void PrefixTrie::makeWords(PrefixTrie* root, const std::string& prefix, std::vector<std::string>& ret) {
    if (root->isEndOfWord) ret.push_back(prefix);
    
    for (auto& entry : root->children) {
        std::string mod {prefix};
        mod.push_back(entry.first);
        makeWords(entry.second, mod, ret);
    }
}