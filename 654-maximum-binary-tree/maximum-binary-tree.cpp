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
    int maxnode(vector<int>& nums,int i,int j){
        int m=INT_MIN; int id=-1;
        for(int k=i;k<=j;k++){
            if(m<nums[k]){
                m=nums[k]; id=k;
            }
        }
        return id;
    }
    TreeNode* solve(vector<int>& nums,int i,int j){
        if (i > j) return NULL;

      
        int position=maxnode(nums,i,j);
        TreeNode* root=new TreeNode(nums[position]);

        root->left=solve(nums,i,position-1);
        root->right=solve(nums,position+1,j);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root=NULL;
        root=solve(nums,0,nums.size()-1);
        return root;
    }
};