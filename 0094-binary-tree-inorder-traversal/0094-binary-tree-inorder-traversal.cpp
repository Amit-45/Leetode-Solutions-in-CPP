class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root)return {};
         stack<TreeNode*>st;
         TreeNode* temp=root;
         while(!st.empty() or temp){
             while(temp){
                 st.push(temp);
                 temp=temp->left;
             }
             temp=st.top();
             ans.push_back(st.top()->val);
             st.pop();
             temp=temp->right;
         }
        return ans;
    }
};