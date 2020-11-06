/*

KEY: backstepping concept but not actually backtracking
裡面比較進階的概念是左括號總共不可以超過 n / 右括號不可以超過左括號
Time complexity: O(2^(2n))
Space complexity: O(2^(2n))


*/


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n==0) return ans;
        generator(ans, "", 0, 0, n);
        return ans;
    }
private:
    void generator(vector<string>& ans, string s, int left, int right, int n){
        if(s.size()== 2 * n){
            ans.push_back(s);
        }
        
        if(left < n){
            generator(ans, s+"(", left+1, right, n);
        }
        if(right < left){
            generator(ans, s+")", left, right+1, n);
        }      
    }
};