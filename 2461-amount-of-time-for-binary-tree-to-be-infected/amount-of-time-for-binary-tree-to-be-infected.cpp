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
    void travel(unordered_map<TreeNode*,TreeNode*>& m,TreeNode* root,TreeNode*& starting,int start){
        if(root==NULL) return;
        if(root->left!=NULL) m[root->left]=root;
        if(root->right!=NULL) m[root->right]=root;
        if(root->val==start) starting=root;
        travel(m,root->left,starting,start);
        travel(m,root->right,starting,start);
    }
    void solve(unordered_map<TreeNode*,TreeNode*>& m,unordered_map<TreeNode*,bool>& visit,TreeNode* aim,int& t){
        queue<TreeNode*> q;
        q.push(aim);
        visit[aim]=1;
        while(!q.empty()){
            int s=q.size();
            int mark=0;
            for(int i=0;i<s;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && visit[temp->left]==0){
                    mark=1;
                    visit[temp->left]=1;
                    q.push(temp->left);
                }
                if(temp->right && visit[temp->right]==0){
                    mark=1;
                    visit[temp->right]=1;
                    q.push(temp->right);
                }
                if(m[temp]!=NULL && visit[m[temp]]==0 ){
                     mark=1;
                    visit[m[temp]]=1;
                    q.push(m[temp]);
                }
            }
            if(mark==1) t++;
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> m;
        TreeNode* starting=NULL;
        m[root]=NULL;
        travel(m,root,starting,start);

        if(starting==NULL) return 0;
        int t=0;
        unordered_map<TreeNode*,bool> visit;
        solve(m,visit,starting,t);
        return t;
    }
};