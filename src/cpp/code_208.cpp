// 208. Implement Trie (Prefix Tree) (Medium)

#include <string>

using namespace std;

/**
    A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

    Implement the Trie class:
        - Trie() Initializes the trie object.
        - void insert(String word) Inserts the string word into the trie.
        - boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
        - boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

    @pre 1 <= word.length, prefix.length <= 2000
    @pre word and prefix consist only of lowercase English letters.
    @pre At most 3 * 10^4 calls in total will be made to insert, search, and startsWith.
*/
class Trie {
    struct TrieNode {
        bool is_word;
        TrieNode* children[26];

        TrieNode(bool iw) : is_word(iw), children{} {}
    };

    TrieNode* root;

public:
    void clear(TrieNode*& node) {
        if (node) {
            for (TrieNode* child : node->children) clear(child);

            delete node;
            node = nullptr;
        }
    }

    ~Trie() {
        clear(root);
    }

    Trie() {
        root = new TrieNode(false);
    }

    void insert(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            TrieNode*& child = curr->children[c - 'a'];

            if (!child) child = new TrieNode(false);

            curr = child;
        }

        curr->is_word = true;
    }

    bool search(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            curr = curr->children[c - 'a'];

            if (!curr) return false;
        }

        return curr->is_word;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for (char c : prefix) {
            curr = curr->children[c - 'a'];

            if (!curr) return false;
        }

        return true;
    }
};