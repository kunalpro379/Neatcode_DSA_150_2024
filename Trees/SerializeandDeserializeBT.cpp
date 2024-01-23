/*
Serialization is to store the tree in a file so that it can be later restored. The structure of the tree must be maintained. Deserialization is reading the tree back from a file.
*/
#include<iostream>
using namespace std;
struct TreeNode {
    int key;
    struct TreeNode *left, *right;
};
 

struct TreeNode* newNode(int key)
{
    struct TreeNode* temp = new TreeNode();
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        if (!root) {
            return "null";
        }
        std::string left = serialize(root->left);
        std::string right = serialize(root->right);
        return left + "," + right + "," + std::to_string(root->key);
    }

   vector<string> split(string & s, char delimitor){
    vector<string>tokens;
    std::istringstream tokenStream(s);
   }
    TreeNode* deserialize(string data) {
 
        
    }