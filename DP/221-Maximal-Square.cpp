/**

DYNAMIC PROGRAMMING

1. 最關鍵的想法，就是一個 current point，是考慮到左、下、左上三個值
一方面你自己本身如果是0 沒什麼好說，直接掛蛋
但如果你是 1，則會跟那三個中的最小值相加

2. 記得 update 最大邊長
3. 記得這是蒜面積 要平方

**/



class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = n > 0? matrix[0].size() : 0;
        if(!n || !m) return 0;
        int maxLen = 0;
        
        vector<vector<int>> dp(n, vector<int>(m,0));
        
        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                if(matrix[j][i] == '0' || !i || !j) dp[j][i] = matrix[j][i] - '0'; 
                else dp[j][i] =  min(dp[j-1][i], min(dp[j][i-1], dp[j-1][i-1])) + 1;
                maxLen = max(dp[j][i], maxLen);
            }
        }
        
        return maxLen * maxLen;
    }
};