/**

這題不難，但是一開始想清楚在下筆
找的是當前的 node 跟上一個的關係
如果有連續，暫時 tmp length 就持續加，有不符合的就回到 1
然後每次都要與最後答案更新

**/


class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        traversal(root, 0, 0);
        return maxLen;
    }
private:
    int maxLen = 0;
    void traversal(TreeNode* ptr, int parent, int tmpLen){
        if(parent+1 == ptr->val) tmpLen++;
        else tmpLen = 1;
        if(ptr->left) traversal(ptr->left, ptr->val, tmpLen);
        if(ptr->right) traversal(ptr->right, ptr->val, tmpLen);
        maxLen = max(maxLen, tmpLen);
    }
};