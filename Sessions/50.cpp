/*

1. 不要讓次方真的變負，不利於計算，先把 x 變 1/x

2. 這題要講的是：fast power algorithm
===== RECURSIVE VERSION=====
每一個 x^n = (x^(n/2))^2
可以藉由 recursive break down 到最小塊
time complexity 會從 O(n) 到 O(logn)
但 n 有奇數偶數之分，兩種 cases：
我們 let x^(n/2) = A
(1) even: x^n = A*A, obviously
(2) odd: x^n = A*A*x 



*/


class Solution {
public:
    double fastPow(double x, long long n) {
        if (n == 0) {
            return 1.0;
        }
        double half = fastPow(x, n / 2);
        if (n % 2 == 0) { // even
            return half * half;
        } else { // odd
            return half * half * x;
        }
    }
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N; // change to positive value
        }
        return fastPow(x, N);
    }
};