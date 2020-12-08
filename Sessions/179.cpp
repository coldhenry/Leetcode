
/*

關於字串的sorting
對於這題，都會希望 Digit 最大越好，但 default string sorting
裡面會產生出 30 > 3 這種其實我們不想要的結果
所以需要稍微調整一下： customized sorting

我們需要的是，倆倆結合起來的時候， s1 + s2 > s2 + s1
不是單純的 s1 > s2
上個例子就會變成：330 > 303

有趣的是，這題證明用數學寫比較順手
https://leetcode.com/problems/largest-number/discuss/291988/A-Proof-of-the-Concatenation-Comparator's-Transtivity


*/



class Solution {
    struct comp {
        bool operator() (int a, int b) {
            string comb1 = to_string(a) + to_string(b);
            string comb2 = to_string(b) + to_string(a);
            return comb1 > comb2;
        }
    } mycomp;
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), mycomp);
        if (nums[0] == 0) return "0";
        string res = "";
        for (auto num : nums) {
            res = res + to_string(num);
        }
        return res;
    }
};

// comparator還可以有下面這種寫法
// let arr = vector<string>
sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1+s2>s2+s1; });