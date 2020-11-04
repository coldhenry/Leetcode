```
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<1) return 0;
        
        vector<int> up(nums.size(), 1);
        vector<int> down(nums.size(), 1);
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]){
                up[i] = max(down[i-1] + 1, up[i-1]);
            } else if(nums[i] < nums[i-1]){
                down[i] = max(up[i-1]+1, down[i-1]);
            } else {
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
        }  
        return max(up[nums.size()-1], down[nums.size()-1]);     
    }
};

```

經典 DP 題