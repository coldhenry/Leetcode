// BFS
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        queue<TreeNode*> myQ;
        myQ.push(root);
        while(!myQ.empty()){
            int n = myQ.size();
            vector<int> tmp;
            for(int i=0; i<n; i++){
                TreeNode* curr = myQ.front(); myQ.pop();
                tmp.push_back(curr->val);
                if(curr->left) myQ.push(curr->left);
                if(curr->right) myQ.push(curr->right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};