/*

除了很直覺的算法外，這題的重點是 bit operation

兩個重要的 bitwise trick:
1. 取得 rightmost 1-bit: x & (-x)
2. set rightmost 1-bit to 0: x & (x-1)

<<負數的值如何變成二進位>>
-x = ~x + 1
為甚麼要這個東西，因為x跟-x就會剛好只差一個位元而已，而且是rightmost 1-bit
所以 x & (-x) 的時候，就會只剩下 rightmost 1-bit

Approach 1 用第一個 bitwise trick
二進位裡面，是2的倍數的數字都會只有一個位元
用上面的方法就會知道只要 x & (-x) == x -> 二的次方倍

Approach 2 用第二個 bitwise trick
To subtract 1 means to change the rightmost 1-bit to 0 and to set all the lower bits to 1
跟上面差不多概念，只有一個bit的值 x & (x-1) 應該要 == 0 
*/


//Approach 1
class Solution {
  public:
  bool isPowerOfTwo(int n) {
    if (n == 0) return false;
    // in case the number is too big
    long x = n;
    return (x & (-x)) == x;
  }
};

// Approach 2
class Solution {
  public:
  bool isPowerOfTwo(int n) {
    if (n == 0) return false;
    long x = n;
    return (x & (x - 1)) == 0;
  }
};