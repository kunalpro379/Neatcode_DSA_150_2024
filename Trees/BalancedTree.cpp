#include<iostream>
#include<algorithm>
using namespace std;
 /*The height of the left and right tree for any node does not differ by more than 1.
The left subtree of that node is also balanced.
The right subtree of that node is also balanced.*/
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d)
    {
        int data = d;
        left = right = NULL;
    }
};
class Solution {
public:
int max(int a, int b){
    if(a>b)
    return a;
    else
    return b;
}
int height(TreeNode* node)
{
    if (node == NULL)
        return 0;
 
 
    return 1 + max(height(node->left), height(node->right));
}
    bool isBalanced(TreeNode* root) {
        int lh,rh;
        if(root==NULL){return 1;}
        lh=height(root->left);
        rh=height(root->right);

        if(abs(lh-rh)<=1&&isBalanced(root->left)&&isBalanced(root->right))
            return 1;
    
    return 0;
    }
};