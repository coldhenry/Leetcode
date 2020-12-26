// Approach 1: hashmap
// O(n) and O(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto& n : nums){
            freq[n]++;
        }
        int bar = nums.size()/3;
        vector<int> ans;
        for(auto& pair : freq){
            if(pair.second > bar) ans.push_back(pair.first);
        }
        return ans;
    }
};
// Approach 2: voting system
// the idea is that there will only have at most 2 candidates to have more than floor(n/3) votes
// so we just need to keep 2 positions and 2 counters 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int max1 = -1, max2 = -1;
        int count1 = 0, count2 = 0;
        
        for(auto& n : nums){
            if(max1 == n) count1++;
            else if(max2 == n) count2++;
            else if(count1 == 0){
                max1 = n;
                count1++;
            }
            else if(count2 == 0){
                max2 = n;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(auto& n : nums){
            if(n == max1) count1++;
            if(n == max2) count2++;
        }
        if(count1 > nums.size()/3) ans.push_back(max1);
        if(count2 > nums.size()/3 && max2 != max1) ans.push_back(max2);
        
        return ans;
    }
};
