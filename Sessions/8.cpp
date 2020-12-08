/*

這題的幾個重點
0. 起手式的 string to int

num = 10 * num + s[i] - '0'


1. 有一些比較 tricky 的 test case such as '+-42'
想法是你刪除空白格之後的第一次就做 +/- 檢驗，做了一次之後
下一次就會強調我要看數字了，如果再出現非數字的東西，value的部分直接給0

2. 怎麼避免 overflow, underflow
兩種情況：
(1) 很接近INT_MAX，所以需要在 INT_MAX/10 的時候檢查下一位是否大於 INT_MAX%7
(2) INT_MIN是一樣狀況，在value 裡面計算時是一樣的，return 要檢查你要給 INT_MAX還是 INT_MIN


*/


class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        int result = 0;
        if (s.length() == 0) return 0;

        //Discard whitespaces in the beginning
        while (i < s.length() && s[i] == ' ') i++;

        // Check if optional sign if it exists
        if (i < s.length() && (s[i] == '+' || s[i] == '-')){
        	sign = (s[i++] == '-') ? -1 : 1;
		}
        
        // Build the result and check for overflow/underflow condition
        // NOTE: if the next one isn't digit, the result = 0
        while (i < s.length() && isdigit(s[i])) {
            if (result > INT_MAX / 10 ||
                    (result == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result = result * 10 + (s[i++] - '0');
        }
        return result * sign;
    }
    
};