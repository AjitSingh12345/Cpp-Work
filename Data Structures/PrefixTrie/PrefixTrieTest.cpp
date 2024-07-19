#include <iostream>
#include <vector>
#include <string>
#include "PrefixTrie.h"

// Simple assertion macros for testing
#define ASSERT_TRUE(condition) \
    do { \
        if (!(condition)) { \
            std::cerr << "Assertion failed: " #condition << std::endl; \
            return false; \
        } \
    } while (false)

#define ASSERT_FALSE(condition) ASSERT_TRUE(!(condition))

#define ASSERT_EQ(actual, expected) \
    do { \
        auto _actual = actual; \
        auto _expected = expected; \
        if (!std::equal(_actual.begin(), _actual.end(), _expected.begin(), _expected.end())) { \
            std::cerr << "Assertion failed: " #actual " == " #expected << std::endl; \
            return false; \
        } \
    } while (false)

bool testPrefixTrieInsertAndSearch() {
    PrefixTrie trie;

    trie.insert("cat");
    trie.insert("car");
    trie.insert("dog");
    trie.insert("dock");

    ASSERT_TRUE(trie.search("cat"));
    ASSERT_TRUE(trie.search("car"));
    ASSERT_TRUE(trie.search("dog"));
    ASSERT_TRUE(trie.search("dock"));

    ASSERT_FALSE(trie.search("ca"));   // 'ca' is not a complete word
    ASSERT_FALSE(trie.search("c"));    // 'c' is not a complete word
    ASSERT_FALSE(trie.search("docks")); // 'docks' is not in the trie

    return true;
}

bool testPrefixTrieStartsWith() {
    PrefixTrie trie;

    trie.insert("cat");
    trie.insert("car");
    trie.insert("dog");
    trie.insert("dock");

    ASSERT_TRUE(trie.startsWith("ca"));
    ASSERT_TRUE(trie.startsWith("c"));
    ASSERT_TRUE(trie.startsWith("d"));
    ASSERT_FALSE(trie.startsWith("dockk")); // 'dockk' is not in the trie

    return true;
}

bool testPrefixTrieAutoComplete() {
    PrefixTrie trie;

    trie.insert("cat");
    trie.insert("car");
    trie.insert("dog");
    trie.insert("dock");

    std::vector<std::string> result = trie.autoComplete("do");
    std::vector<std::string> expected = {"dog", "dock"};
    ASSERT_EQ(result, expected);

    result = trie.autoComplete("ca");
    expected = {"cat", "car"};
    ASSERT_EQ(result, expected);

    result = trie.autoComplete("c");
    expected = {"cat", "car"};
    ASSERT_EQ(result, expected);

    result = trie.autoComplete("d");
    expected = {"dog", "dock"};
    ASSERT_EQ(result, expected);

    result = trie.autoComplete("dockk");
    expected = {};
    ASSERT_EQ(result, expected);

    return true;
}

int main() {
    bool success = true;

    std::cout << "Running PrefixTrie tests..." << std::endl;

    // Run each test case and accumulate success/failure
    success &= testPrefixTrieInsertAndSearch();
    success &= testPrefixTrieStartsWith();
    success &= testPrefixTrieAutoComplete();

    if (success) {
        std::cout << "All tests passed!" << std::endl;
    } else {
        std::cerr << "Some tests failed." << std::endl;
    }

    return success ? 0 : 1;
}
