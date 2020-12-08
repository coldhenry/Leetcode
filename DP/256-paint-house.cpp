
// DYNAMIC PROGRAMMING 中經典的 minimum path sum + 一些額外限制條件


class Solution {
public:
  int minCost(vector<vector<int>>& costs) {
    int rows = costs.size();
    int colors = costs[0].size();

    vector<int> dp(costs.front());
    for(int row=1; row<rows; row++){
      vector<int> tmp(dp);
      for(int col = 0; col < colors; col++){
        if(col == 0) tmp[col] = min(dp[1], dp[2]) + costs[row][0];
        else if (col == 1) tmp[col] = min(dp[0], dp[2]) + costs[row][1];
        else tmp[col] = min(dp[1], dp[0]) + costs[row][2];
      }
      dp = tmp;
    }
    return min(min(dp[0], dp[1]), dp[2]);
  }
};