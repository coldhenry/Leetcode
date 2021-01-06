"""
KEY: prefix sum
prefixSum[i] = sum of index 0 to index i
to get the sum of a subarray: prefixSum[j] - prefixSum[i]

another key: prefixSum seems to be an array, but it can be reduced to a int value
since that we just need a scan, keeping rest of values is useless

"""


class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return 0;
        
        // create a hashmap
        unordered_map<int, int> mymap;
        
        // loop from the beginning to the last
        // find if there's an index contains sum[j] - k (look left)
        // if so, update the tmpeorary max value
        // at the end, store this value of index j into hashmap
        int tmpMax = 0, currSum = 0;
        for(int i = 0; i < n ; i++){
            
            currSum += nums[i];
            
            if(currSum == k){
                tmpMax = i + 1;
            }
            else if(mymap.count(currSum - k)){
                tmpMax = max(tmpMax, i - mymap[currSum - k]);
            }
            if(!mymap.count(currSum)){
                mymap[currSum] = i;
            }
        }
        
        return tmpMax;
    }
};