#include<iostream>
using namespace std;
class Solution2 {
public:

    bool isSubtree(TreeNode* p, TreeNode* q) {
        if(!p&&!q){return true;}
        if(!p||!q){return false;}
        if(p->val!=q->val){return false;}

        return isSubtree(p->left,q->left)&&isSubtree(p->right,q->right); 
    }

};
class Solution5 {
public:
    bool isSameTreeDP(TreeNode* p, TreeNode*q,unordered_map<std::pair<TreeNode*, TreeNode*>, bool>& memo){
        
    }
    bool isSubtree(TreeNode* p, TreeNode* q) {
        unordered_map<pair<TreeNode*, TreeNode*>, bool> memo;

        return isSameTreeDP(p, q, memo);
    }


};