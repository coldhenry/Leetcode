// Preorder Traversal

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        helper(root, ans);
        return ans;
    }
private:
    void helper(TreeNode* ptr, vector<int>& ans){
        if(!ptr) return;
        
        ans.push_back(ptr->val);
        helper(ptr->left, ans);
        helper(ptr->right, ans);
        
    }
};


// Postorder Traversal
void helper(TreeNode* ptr, vector<int>& ans){
    if(!ptr) return;
    
    helper(ptr->left, ans);
    helper(ptr->right, ans);
    ans.push_back(ptr->val);
}


// Inorder Traversal
void helper(TreeNode* ptr, vector<int>& ans){
    if(!ptr) return;
    
    helper(ptr->left, ans);
    ans.push_back(ptr->val);
    helper(ptr->right, ans);
}