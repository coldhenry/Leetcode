bool compareIntervals(const vector<int> &s1, const vector<int> &s2)
{
    return s1[0]<s2[0];
}

class Solution {
public:
    
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size()<2) return intervals;
        sort(intervals.begin(), intervals.end(), compareIntervals);
        ans.push_back(intervals[0]);
        
        for(int i=1; i<intervals.size(); i++){
            int left = intervals[i][0];
            if(left <= ans.back()[1]){
                ans.back()[1] = max(intervals[i][1],ans.back()[1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};

/**
Key: 
這題 sort 部分可以注意一下，自己寫的版本會快很多
其餘就是很正常，有重疊拿出來更新右值

Time Complexity:
O(N)

Space complexity:
O(1)

**/