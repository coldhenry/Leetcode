/*

這題的重點不是 Naive 那個作法
而是討論如果我接下來一次問 3,5,7,11,...倍數
條件會寫不完

所以改進的概念就是
這個要加的字串，隨著一個一個 condition check去加上去的

遇到3放fizz進去
遇到5放(或是再放) fuzz進去
...
...


*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret_vec(n);
        for(int i=1; i<=n; ++i)
        {
        	// divided by 3
            if(i % 3 == 0) ret_vec[i-1] += "Fizz";
            // divided by 5
            if(i % 5 == 0) ret_vec[i-1] += "Buzz";
            // if none, put the number in
            if(ret_vec[i-1].empty()) ret_vec[i-1] += to_string(i);
           
        }
        return ret_vec;
    }
};