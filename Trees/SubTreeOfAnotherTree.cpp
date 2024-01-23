#include<iostream>
#include<unordered_map>
#include <string>
#include <sstream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;


    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//   *****************Approach 1*****************************
class Solution1 {
public:
    string treeToString(TreeNode* root, unordered_map<TreeNode*, string>& subtreeRep){
        if(!root)
        return "0";

        string StrRepr=to_string(root->val)+treeToString(root->left,subtreeRep)+treeToString(root->right,subtreeRep);
        subtreeRep[root]=StrRepr;
        return StrRepr;

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        unordered_map<TreeNode*, string>subtreeRep;
        string Rrep=treeToString(root, subtreeRep);
        string Srep=treeToString(subRoot, subtreeRep);

        return Rrep.find(Srep)!=string::npos;
    }
};
//time complexity=O(m*n)
//space complexity=O(m+n)

//   *****************Approach 2*****************************
class Solution2 {
public:
    bool isSubtreeDP(TreeNode* root, TreeNode* subRoot, unordered_map<pair<TreeNode*, TreeNode*>, bool>& memo) {
        if (!root && !subRoot)
            return true;
        if (!root || !subRoot)
            return false;

        //cheak if our need is already memorized
        if(memo.find({root,subRoot})!=memo.end()){
return memo[{root,subRoot}];
        }

        bool result =isSubtreeDP(root->left, subRoot, memo) || isSubtreeDP(root->right, subRoot, memo);
        //memorize the resutlt
        memo[{root,subRoot}]=result;
        return result;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        unordered_map<std::pair<TreeNode*, TreeNode*>, bool> memo;
        return isSubtreeDP(root, subRoot, memo);
    }

}

//   *****************Approach 3*****************************
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        if (!p || !q) {
            return false;
        }

        return (p->val == q->val) &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }

        bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }

        if (isSameTree(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }


/*
//   *****************Approach 4*****************************

class Solution4 {
public:

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    }

};
*/
int main() {
 
    TreeNode* s = new TreeNode(3);
    s->left = new TreeNode(4);
    s->right = new TreeNode(5);
    s->left->left = new TreeNode(1);
    s->left->right = new TreeNode(2);
    s->left->right->left = new TreeNode(0);

    TreeNode* t = new TreeNode(4);
    t->left = new TreeNode(1);
    t->right = new TreeNode(2);

    Solution1 solution1;
    bool result1 = solution1.isSubtree(s, t);

   cout << (result1 ? "Subtree found." : "Subtree not found.") << endl;

    Solution2 solution2;
    bool result2 = solution2.isSubtree(s, t);

   cout << (result2 ? "Subtree found." : "Subtree not found.") << endl;

    return 0;
}