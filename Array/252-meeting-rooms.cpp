/*

觀念上，這題就是要確保每一個 interval是 disjointed
所以要麻走 O(n^2) 的方式倆倆確定
要嘛走 sorted 過的 O(n*logn) 來一一確定
那麼重點就在 sorted 要怎麼寫的好

寫sort comparator兩個重點：
1. 需要將 comparator 定義為 static ，或是放到全域(class外) 以供 sort 使用
2. comparator 裡面的 arguments 可以 defined as const and use the reference to speed up

*/



class Solution {
    static bool myCompare(const vector<int>& a, const vector<int>& b){return a[0]<b[0];};
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), myCompare);
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] < intervals[i-1][1]) return false;
        }
        return true;
    }
};