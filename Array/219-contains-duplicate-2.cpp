
// Approach 1: Brute force (TLE)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()<2) return false;    
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i] == nums[j] && abs(i-j) <= k) return true;
            }
        }
        return false;
    }
};


// Approach 2: Hashmap
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()<2) return false;    
        
        unordered_map<int,int> mapping; // <num, last_index>
        
        for(int i = 0; i < nums.size(); i++){
            if(mapping.count(nums[i]) == 0){ // equivalent to "mapping.find(nums[i]) == mapping.end()"
                mapping[nums[i]] = i;
            }
            else if(i - mapping[nums[i]] <= k){
                return true;
            }
            else{
                mapping[nums[i]] = i;
            }
        }
        return false;
    }
};