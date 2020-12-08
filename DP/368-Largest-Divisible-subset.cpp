/*

這題的 DP 比較難想
找出不用連續的最大subset，使用DP裡面需要紀錄兩個東西
1. 這是不是最大的 (紀錄最大長度 given 現在這個元素為底)
2. 他依序往前是誰 (紀錄 parent (previous) element)

所以因為是同時記錄兩組東西
更新也會是更新兩組
每次都要先更新現在一組 node (i,j) 會不會 dp[j] + 1 > dp[i] 了
有的話就更新，如果更新玩得 dp[i] 還大於現在暫時最長的 subset，再更新

而最後，就是要依照著最長subset的最後index，然後用 parent() 依序往前推，裝進要 return 的 vector
*/


// Appraoch 1: Backtracking (TLE)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        vector<int> tmp;
        backtrack(nums, ans, tmp, 0, 1);
        return ans;
    }
private:
    void backtrack(vector<int>& nums, vector<int>& ans, vector<int>& tmp, int start, int prev){
        // update the final answer
        if(tmp.size() > ans.size()){
            ans = tmp;
        }
        
        for(int i = start; i < nums.size(); i++){
            // if this could pass, the result number in the tmp could == 0 too
            if(nums[i] % prev ==0){
                tmp.push_back(nums[i]);
                backtrack(nums, ans, tmp, i+1, nums[i]);
                tmp.pop_back();
            }
        }
    }
};


// Approach 2: Dynamic Programming
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        // dp[i]: the maximal length of subset ending with nums[i]
        vector<int> dp(nums.size(), 0);
        // parent[i]: the previous element that is divisible with nums[i] 
        vector<int> parent(nums.size(), 0);
        
        int maxLength = 0;
        int maxIndex = 0;
        
       
        for(int i = nums.size() - 1; i >= 0; --i) 
        {
           
            for(int j = i; j < nums.size(); ++j)
            {

                // check every a[j] that is larger than a[i]
                if(nums[j] % nums[i] == 0 && dp[i] < 1 + dp[j])
                {

                    dp[i] = 1 + dp[j];
                    parent[i] = j;
                    
                    if(dp[i] > maxLength)
                    {
                        maxLength = dp[i];
                        maxIndex = i;
                    }
                }
            }
        }
        
        vector<int> ret;
        
        for(int i = 0; i < maxLength; ++i)
        {
            ret.push_back(nums[maxIndex]);
            maxIndex = parent[maxIndex];
        } 
        
        return ret;
    }
};