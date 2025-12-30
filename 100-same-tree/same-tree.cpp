/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void preorder(TreeNode* p,vector<int>& a){
        if(p==NULL){
            a.push_back(INT_MAX); return;
        }
        a.push_back(p->val);
        preorder(p->left,a);
        preorder(p->right,a);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> a;
        vector<int> b;
        preorder(p,a);
        preorder(q,b);
        return a==b;
    }
};