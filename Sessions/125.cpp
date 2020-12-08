/*
palindrome: 回文
回文特質：
1. 顛倒過來也是相同的
2. 由外向內剛好對稱

補充：
1. c++ function: isalnum() 檢查是否為字母數字 (alphanumeric characters)
2. c++ function: tolower() 大寫轉小寫
3. reverse_copy(要翻轉字串的head position, 從來源字串的第一個位置，來源字串的最後一個位置)

*/


// Approach 1: 整個翻轉，比對是否相投
// 裡面會有標點符號要跳過，使用 isalnum()
// O(N) / O(N)
class Solution {
 public:
  bool isPalindrome(string s) {
    string filtered_string, reversed_string;

    for (auto ch : s) {
      // 只有字母數字可以放進 filtered_string
      if (isalnum(ch))
        filtered_string += tolower(ch);
    }

    // 一開始沒有定義 reversed_string 的size
    reversed_string.resize(filtered_string.size());
    // 使用 built-in function 來翻轉
    reverse_copy(filtered_string.begin(), filtered_string.end(),
                 reversed_string.begin());

    return filtered_string == reversed_string;
  }
};

// Approach 2: 2 pointers 由外而內
// O(N) / O(1)
class Solution {
 public:
  bool isPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
      // 兩個while 把裡面的標點符號跳過
      while (i < j && !isalnum(s[i]))
        i++;
      while (i < j && !isalnum(s[j]))
        j--;

    //大小寫要轉換一下才能比較
    //有一個不對就不是回文
      if (i < j && tolower(s[i]) != tolower(s[j]))
        return false;
    }

    return true;
  }
};

