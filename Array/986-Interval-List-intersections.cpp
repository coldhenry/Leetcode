/*
KEY: 基本概念差不多，這種interval問題如果有 disjoint 的性質，可以把重點放在 endpoint (每個interval右邊)
因為既然 disjoint，右邊以前的事情就會是固定的，不會再變動
Time complexity: O(m + n)
Space complexity: O(1)

*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int n = A.size(), m = B.size();
        if(n == 0 || m == 0) return ans;
        int pA = 0;
        int pB = 0;
        
        while(pA < n && pB < m){
            int left = max(A[pA][0], B[pB][0]);
            int right = min(A[pA][1], B[pB][1]);
            if(left <= right){
                ans.push_back(vector<int>({left, right}));
            }
            
            if(A[pA][1] < B[pB][1]) pA++;
            else pB++;   
        }
        return ans;
    }
};