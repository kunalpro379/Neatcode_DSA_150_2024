#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    unordered_map<int, int> indexMap;
    buildTreehelp(vector<int>& preorder, int preStart, int preEnd,
                              vector<int>& inorder, int inStart, int inEnd){
           if(preStart>preEnd||inStart>inEnd){return NULL;}
int rootVal=preorder[preStart];
TreeNode* root =new TreeNode(rootVal);

int rootInd=indexMap[rootVal];

int leftSize=rootInd-inStart;
root->left=buildTreehelp(preorder,preStart+1,preStart+leftSize,inorder,inStart,rootInd-1);
root->right=buildTreehelp(preorder,preStart+leftSize+1,preEnd,inorder,rootInd+1,inEnd);
                              }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //storing index in the map

        for(int i=0;i<inorder.size();i++){
             indexMap[inorder[i]]=i;
        }
        return buildTreehelp(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);

    }
};

void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        std::cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(TreeNode* root) {
    if (root) {
        std::cout << root->val << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
int main() {
    // Example usage
    std::vector<int> preorder = {3, 9, 20, 15, 7};
    std::vector<int> inorder = {9, 3, 15, 20, 7};

    Solution solution;
    TreeNode* root = solution.buildTree(preorder, inorder);

    // Verify the reconstructed tree by performing an inorder and preorder traversal
    std::cout << "Inorder Traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Preorder Traversal: ";
    preorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
