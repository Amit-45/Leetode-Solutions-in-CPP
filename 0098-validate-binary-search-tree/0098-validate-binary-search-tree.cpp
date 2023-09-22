
class Solution {
 void inorder(TreeNode*root,vector<int> &v){
      if(root==NULL){
           return ;
       }
       inorder(root->left,v);
       v.push_back(root->val);
       inorder(root->right,v);
 }
public:
  bool isValidBST(TreeNode* root) {
        vector<int>v1;
        inorder(root,v1);
        for(int i=1;i<v1.size();i++){
            if(v1[i]<=v1[i-1]){
                return false;
            }
        }
        return true;
    }
};