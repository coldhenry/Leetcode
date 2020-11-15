
/*

這題一開始我把他想得太難，覺得要三個三個看，判斷折線
但去想一下，會發現其實兩個兩個看就好，關聯性並沒有延續到第三個

*/

//兩個兩個判斷版本
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i % 2){
                if(nums[i-1] > nums[i]) swap(nums[i-1], nums[i]);
            }
            else if(i != 0 && nums[i-1] < nums[i]){
                swap(nums[i-1], nums[i]);
            }
        }
    }
};



//三個三個判斷版本(複雜)
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        int n = nums.size();
        if(n<=1) return;
        if(n==2){
            if(nums[0]>nums[1]) swap(nums[0], nums[1]);
            return;
        }
        if(nums[0]>nums[1]) swap(nums[0], nums[1]);
        for(int i=2; i<n; i++){
            checkWiggle(i, nums);
        }
    }
private:
    void checkWiggle(int last, vector<int>& nums){
        bool odd = last % 2;
        int dif1 = nums[last-1] - nums[last-2];
        int dif2 = nums[last] - nums[last-1];
        if(odd){
            if(dif1 * dif2 > 0){
                if(nums[last-2] < nums[last-1]) swap(nums[last-2], nums[last]);
                swap(nums[last-1], nums[last]);
            } else if(dif2 < 0){
                swap(nums[last-1], nums[last]);
            }
        } else {
            if(dif1 * dif2 > 0){
                if(nums[last-2] > nums[last-1]) swap(nums[last-2], nums[last]);
                swap(nums[last-1], nums[last]);
            } else if (dif2 > 0){
                swap(nums[last-1], nums[last]);
            }
        }
    }
};