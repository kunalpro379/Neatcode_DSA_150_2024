#include<iostream>
using namespace std;
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* newNode(int data)
{
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return (newNode);
}

int max(int a, int b){
    if(a>b)
    return a;
    else
    return b;
}
int helper(Node* root,int &SUM){
if(root==NULL)
return 0;

int l=helper(root->left,SUM);
int r=helper(root->right,SUM);

int maxy=max(max(l,r)+root->data,root->data);
int maxtop=max(maxy,l+r+root->data);
SUM=max(SUM,maxtop);

return SUM;
}
int MaxBTpathSum(Node* root){
    int SUM=0;
    helper(root,SUM);
    return SUM;
}

int main()
{
    struct Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(10);
    root->left->left = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left = newNode(3);
    root->right->right->right = newNode(4);
 
    // Function call
    cout << "Max path sum is " << MaxBTpathSum(root);
    return 0;
}