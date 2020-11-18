/* 
這題用到一個蠻有用的 technique : prefix sum
原本是從 tree: path sum III 那邊看到這裡來的
主要概念就是把 the frequency of the path sum from the beginning 這個data存起來
如果是從最前面，那就是直接+1
但如果是中間的連續 array 那就是(整段-前面)
*/


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> mymap;
        int cur_sum = 0;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            
            cur_sum += nums[i];
            
            // case 1: the subarray starts from the beginning
            if(cur_sum == k) count += 1;
            
            // case 2: the subarray is in the middle
            count += mymap[cur_sum - k];
            
            mymap[cur_sum] += 1;
            
        }
        return count;
    }
};