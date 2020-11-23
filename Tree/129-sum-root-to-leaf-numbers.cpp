/*

唯一注意的點就是 container 的使用，vector 或 stack 都可以
我之前用 queue有點麻煩，因為在 backtracking 那邊會有點卡，記起來不要用

*/



class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        stack<int> nums;
        traversal(root, nums, ans);
        return ans;
    }
private:
    int stackToint(stack<int> st){
        int ans=0;
        int i = 0;
        while(!st.empty()){
            ans = ans + st.top() * pow(10,i++);
            st.pop();
        }
        return ans;
    }
    void traversal(TreeNode* ptr, stack<int>& st, int& ans){

        st.push(ptr->val);
        if(!ptr->left && !ptr->right){
            ans += stackToint(st);
        } else {
            if(ptr->left) traversal(ptr->left, st, ans);
            if(ptr->right) traversal(ptr->right, st, ans);
        }
        st.pop();
        
    }
};