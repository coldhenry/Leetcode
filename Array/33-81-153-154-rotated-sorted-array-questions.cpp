/*
<<Rotated Sorted Array Series>>
33. Search in Rotated Sorted Array
81. Search in Rotated Sorted Array II
153. Find Minimum in Rotated Sorted Array
154. Find Minimum in Rotated Sorted Array II
*/



/*
33. - no duplicate case

==== One-pass approach ====
KEY: 目標是對正確的 range 做 binary search
所以要額外寫的條件是： mid 究竟是在 左range 還是 右range
特別注意的是 bianry search 的結束條件是 left > right

Time complexity: O(logN)
Space complexity: O(1)

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1) return nums[0] == target? 0 : -1;
        if(target < nums[0] && target > nums[n-1]) return -1;
        
        int left = 0, right = n-1;
        while(left <= right){
            
            int mid = left + (right-left)/2;
            
            if(target == nums[mid]) return mid;
            else if(nums[mid] >= nums[left]){
                if(target >= nums[left] && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            } else { // nums[mid] < nums[left]
                // 這裡是 key point：因為我知道 left--mid--right 中間有個窟窿
                // 所以如果比 left 跟 mid 是有問題的，拿 mid 跟 right 才不會出事
                // 這才是有沒有 rotated 的差別 
                if(target > nums[mid] && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};


/*
81. duplicate case
KEY: 與 33 的一個重要差別是，我怎麼避免一種edge case: [1,1,1,3,1,1,1,1,1,1]，這種left / mid / right 有可能一樣的情況?
因為只要一出現，就會有 no in order 的情況，binary search 就會爆掉
這裡有個最簡單的方法就是，把一半section中的 duplicate先砍，就可以避免上述情況
*/

//多這一操作即可
int left = 0, right = n-1;
while(left != n-1 && nums[left]==nums[right]) left++;



/*
153. Find Minimum in Rotated Sorted Array - no duplicates
與前面題目有個很重要的差別是:這裡我們並不知道 target 是什麼，所以需要用條件定義

先定義一下左三角形右三角形方便我們後面討論，rotated sorted array代表有一部分的數列被移到後面，
若按照數值的 histogram排列，應該會是兩個三角形

找到最小值 (上兩題的 pivot) 有兩種可能性
(1.) 左右pointer一起掉到後面的三角形 i.e. 這時候 nums[left]<nums[right]，那很明顯 left 會是最小的 index
(2.) left right 在兩個三角形最終相疊，left = mid + 1 之後與 right 相等 -> break while loop

*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return -1;
        
        
        int left = 0, right = n-1;
        while(left < right){
            // subarray is in order
            if(nums[left] < nums[right]) return nums[left];
            
            int mid = left + (right-left)/2;
            if(nums[mid] >= nums[left]) left = mid + 1;
            else right = mid;
        }
        return nums[left]
    }
};

/*===================153跟154整合之後版本=================*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return -1;
        
        
        int left = 0, right = n-1;
        while(left < right){
            
            int mid = left + (right-left)/2;
            if(nums[mid] > nums[right]) left = mid + 1;
            else if(nums[mid] <= nums[right]) right = mid;
        }
        return nums[left];
    }
};


/*
154
consider the duplicates
與上面整合版本的差異就是，nums[mid] == nums[right] 再也不是trivial case，需要被額外討論
他可以在左三角或是右三角，沒有duplicate的時候可以確定是右三角
所以下面多了特別確定的部分，基本上是以一次一步的方式，避免跳過答案
而多一個 if 條件式是因為不要去回傳到同個 duplicate 值但事實上不是 idx of minimum -> 多準備的
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return -1;
        
        int left = 0, right = n-1;
        while(left < right){
            int mid = left + (right-left)/2;
            
            if(nums[mid] < nums[right]) right = mid;
            else if (nums[mid] > nums[right]) left = mid + 1;
            else{ // nums[mid] == nums[right]
                // rigth idx is the first element in the right section (minimum)
                if(nums[right-1] > nums[right]){
                    left = right;
                    break;
                }
                right--;
            }
        }
        return nums[left];
    }
};



/*
ABOUT Binary serach's "while" condition

You use while (start <= end) if you are returning the match from inside the loop.

You use while (start < end) if you want to exit out of the loop first, and then use the result of start or end to return the match.

*/
