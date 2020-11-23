/**

DYNAMIC PROGRAMMING

第一點：每個node i當頭都是一個類別-> let result = F(i,n)  -> 最後會相加 F(1,n) + F(2,n) + ... + F(n,n) = G(n)
        G(n) defined as the number of unique BST of a sequence of length n
第二點：given 1 node 當 head ，都是兩個 G 相乘，G(i-1) * G(n-i)
合在一起，會需要先把一個一個 F算出來，進而把 G 一個一個算出來


**/



class Solution {
public:
    int numTrees(int n) {
        
        vector<int> subNum(n+1, 0);
        subNum[0] = 1; 
        subNum[1] = 1;
        
        for(int i=2; i<=n; i++){
            for(int j=1; j<=i; j++){
                subNum[i] += subNum[j-1] * subNum[i-j];
            }
        }
        
        return subNum[n];
        
    
    
    }
};


// Approach 2
public:
int numTrees(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i / 2; j++) {
            dp[i] += 2 * dp[j] * dp[i - j - 1];
        }
        if (i % 2 == 1) {
            dp[i] += dp[i / 2] * dp[i / 2];
        }
    }
    return dp[n];
}
};