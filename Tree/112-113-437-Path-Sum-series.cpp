/**************************
Path Sum series
1. Basic path sum
2. 
***************************/


// Recursive
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        else if(!root->left && !root->right && root->val==sum) return true;
        else if(!root->left && !root->right && root->val!=sum) return false;
        
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};
// Iterative using DFS
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        stack<pair<TreeNode*,int>> st;
        st.push(make_pair(root, sum-root->val));
        while(!st.empty()){
            TreeNode* curr = st.top().first; 
            int value = st.top().second;
            st.pop();
            
            if(!curr->left && !curr->right && !value) return true;
            else{
                if(curr->left) st.push(make_pair(curr->left, value-curr->left->val));
                if(curr->right) st.push(make_pair(curr->right, value-curr->right->val));    
            }
        }
        return false;
    }
};

///// 113: Return a list of all paths that has the given sum
// KEY: backtracking
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> p; 
        recursion(root, sum, p, ans);
        return ans;
    }
private:
    void recursion(TreeNode* ptr, int leftVal, vector<int>& path, vector<vector<int>>& lists){
        
        if(!ptr) return;
        
        // Backtracking: put it in 
        path.push_back(ptr->val);
        
        if(!ptr->left && !ptr->right && ptr->val == leftVal){
            lists.push_back(path);
        } else {
            recursion(ptr->left, leftVal-ptr->val, path, lists);
            recursion(ptr->right, leftVal-ptr->val, path, lists);
        }
        
        // Backtracking: pull it out
        path.pop_back();
        
    }
};


////437: a path with the given sum, but not limited from root to leaf, only from parent to child

// Approach 1: Recursion
// 這裡有個注意的點是，我一開始很想直接用說 total answer = recursive(左/扣上面值) + recursive(左/不扣上面值) + recursive(右/扣上面值) + recursive(右/不扣上面值)
// 但其實這樣會少算，不如想成我就是用一個 recursion 走過全部的點，裡面都要做一個一般的 path sum，只是剛好這個也是 recursive function
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return getSum(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
private:
    int getSum(TreeNode* ptr, int currVal, int target){
        if(!ptr) return 0;
        currVal += ptr->val;
        return (currVal == target) + getSum(ptr->left, currVal, target) + getSum(ptr->right, currVal, target);
    }
};

// Approach 2: Prefix sum
// 這題可以借鏡 560 ，是個tree version。基本上就是存取從root到curr的總和直出現頻率
// 兩種case，一種是從頭到尾加起來剛好 sum，跟一般題目一樣
// 第二種case是中間才有符合的，那他的count會等於，整條 - 前面的
// 再講明確一點，妳要獲得一個中間的頻率值，是靠著妳前面的人的頻率來決定的，前面出現幾次，你就會出現幾次
// 我們紀錄的都是從頭的，所以要這樣去反推中間的頻率

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        target = sum;
        int count = 0;
        traversal(root, 0, count);
        return count;
    }
private:
    int target;
    unordered_map<int,int> mymap;
    void traversal(TreeNode* ptr, int currSum, int& count){
        if(!ptr) return;
        
        currSum += ptr->val;
        // case 1: from root
        if(currSum == target) count++;
        // case 2: in the middle
        if(mymap.find(currSum-target) != mymap.end()) count += mymap[currSum-target];
        
        
        mymap[currSum]++;
        
        traversal(ptr->left, currSum, count);
        traversal(ptr->right, currSum, count);
        
        // during tree traversal, keep the mymap value in the right layer
        mymap[currSum]--;
        
    }
};