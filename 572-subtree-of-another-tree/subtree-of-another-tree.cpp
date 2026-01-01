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
    void preorder(TreeNode* root,vector<int>& ans){
        if(root==NULL) {
            ans.push_back(INT_MAX);
            return;
        }
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<int> a;
        vector<int> b;

        preorder(root,a);
        preorder(subRoot,b);
        int i = 0, j = 0;
        int start = 0;

        while (i < a.size()) {
            if (a[i] == b[j]) {
                i++;
                j++;
                if (j == b.size()) return true; // full match found
            } else {
                start++;        
                i = start;     j=0;
            }
        }
        return false;
            }
};