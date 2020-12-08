/*

Approach 1: Hash map for frequency
這個很直覺，用好的容器裝


Approach 2: observation
一個關鍵是，他會需要超過容量一半，所以他的這個值在一個有序的array裡面一定是在中間的
在明確一點，會是在中間或中間偏左

補充
C++ function: nth_element(array.begin(), array.begin()+n, array.end())
: 排序第 nth 個元素，其他都不管


*/


//Approach 1: 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (int num : nums) {
            if (++counter[num] > nums.size() / 2) {
                return num;
            }
        }
        return 0;
    }
};

//Approach 2:
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        return nums[nums.size() / 2];
    }
};