

// O(N * log N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        
        // remove duplicate elements: sort -> unique -> erase
        sort(nums.begin(), nums.end());
        auto last = unique(nums.begin(), nums.end());
        nums.erase(last, nums.end());
        
        // update the size of new array
        n = nums.size();
        int idx = 0, currMax = 1;
        while(idx < n){
            int curr = nums[idx];
            int tmp = idx, tmpMax = 1;
            while(tmp + 1 < n && nums[tmp+1] == curr+1){
                curr++;
                tmp++;
                tmpMax++;
            }
            currMax = max(currMax, tmpMax);
            idx = tmp == idx? tmp+1 : tmp;
        }
        return currMax;
    }
};

// O(N)
// 使用一個 unordered_set 去記得還剩甚麼元素，進行 find 跟 erase
// 最後的長度計算是 back - front - 1，-1的原因是因為，去算長度總共有三種cases(左右，左，右)
// 不管怎樣，其實 pointer 都在 要計算長度的兩側，所以真實長度都要 -1
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        
        unordered_set<int> myset(nums.begin(), nums.end());
        int maxLen = 1;
        for(auto& curr : nums){
            if(myset.find(curr) == myset.end()) continue;
            myset.erase(curr);
            int front = curr - 1, back = curr + 1;
            while(myset.find(front) != myset.end()) myset.erase(front--);
            while(myset.find(back) != myset.end()) myset.erase(back++);
            // the deduction of two numbers is actually the length, no need to store extra information
            maxLen = max(maxLen, back - front - 1);
        }
        return maxLen;
    }
};