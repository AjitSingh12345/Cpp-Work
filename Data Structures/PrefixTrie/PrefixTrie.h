#include <unordered_map>
#include <string>
#include <vector>

class PrefixTrie {
public:
    PrefixTrie();
    ~PrefixTrie();
    PrefixTrie(char data);

    void insert(const std::string& word);
    bool search(const std::string& word);
    bool startsWith(const std::string& prefix);
    std::vector<std::string> autoComplete(const std::string& prefix);
private:
    bool isRoot{ false };
    bool isEndOfWord{ false };
    char data{};
    std::unordered_map<char, PrefixTrie*> children;

    void makeWords(PrefixTrie* root, const std::string& prefix, std::vector<std::string>& ret);
};