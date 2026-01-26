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
    void inorder(TreeNode* root,vector<int>& a){
        if(root==NULL) return;
        inorder(root->left,a);
        a.push_back(root->val);
        inorder(root->right,a);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> in1;
        vector<int> in2;
        inorder(root1,in1);
        inorder(root2,in2);
        vector<int> ans;
        int i=0; int j=0;
        while(i<in1.size() && j<in2.size()){
            if(in1[i]>in2[j]){
                ans.push_back(in2[j]);
                j++;
            }
            else{
                ans.push_back(in1[i]); i++;
            }
        }
        while(i<in1.size()){
            ans.push_back(in1[i]); i++;
        }
        while(j<in2.size()){
            ans.push_back(in2[j]);
            j++;
        }
        return ans;
    }
};