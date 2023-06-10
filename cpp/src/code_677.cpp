#include <string>
#include <unordered_map>

using namespace std;

/**
    Design a map that allows you to do the following:
        - Maps a string key to a given value.
        - Returns the sum of the values that have a key with a prefix equal to a given string.

    Implement the MapSum class:
        - MapSum() Initializes the MapSum object.
        - void insert(String key, int val) Inserts the key-val pair into the map. If the key already existed, the original key-value pair will be overridden to the new one.
        - int sum(string prefix) Returns the sum of all the pairs' value whose key starts with the prefix.

    @pre 1 <= key.length, prefix.length <= 50
    @pre key and prefix consist of only lowercase English letters.
    @pre 1 <= val <= 1000
    @pre At most 50 calls will be made to insert and sum.
*/
// asdf
class MapSum {
    struct TrieNode {
        TrieNode* children[26]{};
        int sum;

        explicit TrieNode(int s = 0) : sum(s) {}
    };

    TrieNode* root;
    unordered_map<string, int> map;

public:
    void clear(TrieNode*& node) {
        if (node) {
            for (auto& child : node->children) clear(child);

            delete node;
            node = nullptr;
        }
    }

    TrieNode* copy(const TrieNode* other) {
        if (!other) return nullptr;

        auto* node = new TrieNode(other->sum);

        for (int i = 0; i < 26; ++i) node->children[i] = copy(other->children[i]);

        return node;
    }

    ~MapSum() {
        clear(root);
    }

    MapSum() : root(new TrieNode()) {}

    MapSum(const MapSum& other) : root(copy(other.root)) {}

    MapSum(MapSum&& other) = default;

    MapSum& operator=(MapSum&& other) = default;

    MapSum& operator=(const MapSum& other) {
        if (this != &other) {
            clear(root);
            root = copy(other.root);
        }

        return *this;
    }

    void insert(string key, int val) {
        TrieNode* curr = root;

        for (char c : key) {
            if (!curr->children[c - 'a']) curr->children[c - 'a'] = new TrieNode();

            curr = curr->children[c - 'a'];
            curr->sum += val - map[key];
        }

        map[key] = val;
    }

    int sum(string prefix) {
        TrieNode* curr = root;

        for (size_t i = 0; curr && i < prefix.length(); ++i) curr = curr->children[prefix[i] - 'a'];

        return curr ? curr->sum : 0;
    }
};