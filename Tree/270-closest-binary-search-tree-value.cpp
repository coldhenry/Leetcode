class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        if(!root) return -1;
        pair<int, double> mypair(-1,DBL_MAX);
        traversal(root, target, mypair);
        return mypair.first;
    }
private:
    void traversal(TreeNode* ptr, double& target, pair<int, double>& mypair){
        if(!ptr) return;
        double dis = abs(target - ptr->val);
        if(mypair.second > dis){
            mypair.first = ptr->val;
            mypair.second = dis;
        }
        if(target >= ptr->val){
            traversal(ptr->right, target, mypair);
        } else {
            traversal(ptr->left, target, mypair);
        }
    }
};