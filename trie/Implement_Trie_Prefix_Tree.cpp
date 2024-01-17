
/*
If we store keys in a binary search tree, a well balanced BST will need time proportional to M * log N, 
where M is the maximum string length and N is the number of keys in the tree. Using Trie,
the key can be searched in O(M) time.
 */
#include<iostream>
#include <unordered_map>
using namespace std;

const int SIZE = 26;

struct TrieNode {
    struct TrieNode* children[SIZE];
    bool isEndOfWord;
};

struct TrieNodeUsingMap {
    unordered_map<char, TrieNodeUsingMap*> children;
    bool isEndOfWord;
};

struct TrieNode* getNode(void) {
    struct TrieNode* trinode = new TrieNode;
    trinode->isEndOfWord = false;
    for (int i = 0; i < SIZE; i++) {
        trinode->children[i] = NULL;
    }
    return trinode;
}

struct TrieNodeUsingMap* getNodeMap(void) {
    struct TrieNodeUsingMap* trinode = new TrieNodeUsingMap;
    trinode->isEndOfWord = false;
    return trinode;
}

void insert(struct TrieNode* root, string key) {
    struct TrieNode* ptr = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';

        if (!ptr->children[index]) {
            ptr->children[index] = getNode();
        }
        ptr = ptr->children[index];
    }
    ptr->isEndOfWord = true;
}

bool search(struct TrieNode* root, string key) {
    struct TrieNode* ptr = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!ptr->children[index])
            return false;
        ptr = ptr->children[index];
    }
    return (ptr->isEndOfWord);
}

void insertUsingMap(struct TrieNodeUsingMap* root, string key) {
    struct TrieNodeUsingMap* ptr = root;
    for (int i = 0; i < key.length(); i++) {
        char ch = key[i];

        if (ptr->children.find(ch) == ptr->children.end()) {
            ptr->children[ch] = getNodeMap();
        }
        ptr = ptr->children[ch];
    }
    ptr->isEndOfWord = true;
}

bool searchUsingMap(struct TrieNodeUsingMap* root, string key) {
    struct TrieNodeUsingMap* ptr = root;
    for (int i = 0; i < key.length(); i++) {
        char ch = key[i];
        if (ptr->children.find(ch) == ptr->children.end())
            return false;
        ptr = ptr->children[ch];
    }
    return (ptr->isEndOfWord);
}

int main() {
    string keys[] = { "kunal", "deepak", "patil", "my", "name" };
    int n = sizeof(keys) / sizeof(keys[0]);
    struct TrieNode* root = getNode();
    for (int i = 0; i < n; i++) {
        insert(root, keys[i]);
    }
    if (search(root, "kunal"))
        cout << "present ";
    else
        cout << "not present";

    // unordered map op
    struct TrieNodeUsingMap* rootMap = getNodeMap();
    for (int i = 0; i < n; i++) {
        insertUsingMap(rootMap, keys[i]);
    }
    if (searchUsingMap(rootMap, "kunal"))
        cout << "present ";
    else
        cout << "not present";

    return 0;
}




//leetcode qn
    class TrieNodeMap{
        unordered_map<char,TrieNodeMap*>children;
        bool isEndOfWord;
    };

class Trie {
    public:
    const int SIZE=26;



    Trie() {
        root=getrootnode();
    }
    
    void insert(string word) {
        TrieNodeMap* ptr=root;
        for(char ch: word){
//char c ind=ch
            if(ptr->children.find(ch)==ptr->children.end()){
                    ptr->children[ch]=getrootnode();
            }
            ptr=ptr->children[ch];
        }
    ptr->isEndOfWord=true;  
    }
    
    bool search(string word) {
        TrieNodeMap* ptr=root;
        for (char ch: word){if(ptr->children.find(ch)==ptr->children.end()){
            return false;
        }
        ptr=ptr->children[ch];
        }
        return ptr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNodeMap* ptr=root;
        for(char ch: prefix){if(ptr->children.find(ch)==ptr->children.end()){
            return false;
        }
       ptr= ptr-> children[ch];
        }
        return true;
    }

    private:

    TriNodeMap* root;
    TriNodeMap* getNode(){

        TriNodeMap* node=new TriNodeMap();
        node->isEndOfWord=false;
        return node;
    }
};
int main() {
    Trie trie;
    trie.insert("kunal");
    trie.insert("deepak");
    trie.insert("patil");

    cout << "Search 'kunal': " << (trie.search("kunal") ? "present" : "not present") << endl;
    cout << "Search 'deep': " << (trie.search("deep") ? "present" : "not present") << endl;
    cout << "StartsWith 'de': " << (trie.startsWith("de") ? "present" : "not present") << endl;

    return 0;
}
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 * 
 */