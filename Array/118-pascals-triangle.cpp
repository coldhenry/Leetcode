/*

Pascal's Triangle series
1. return the whole triangle
2. return the row-index-th row of this triangle

*/

// Q1: naive approach
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(!numRows) return ans;
        ans.push_back({1});
        while(ans.size() < numRows){
            int n = ans.size() + 1;
            vector<int> newRow(n,1);
            for(int i = 1; i < n-1; i++){
                newRow[i] = ans[n-2][i-1] + ans[n-2][i];
            }
            ans.push_back(newRow);
        }
        return ans;
    }
};


