/*
Approach 1: Recursive
KEY: 括號的意義。括號就是告訴你一個式子誰先看誰後看，是決定加減乘除順序的東西
所以基本上，把括號加在哪邊，這句話等同於要先做誰後做誰而已

Time complexity:
EX: n=5 -> (1)(4) + (2)(3) + (3)(2) + (4)(1)
Pn = P_1*P_n-1 + P_2*P_n-2 + ... + P_n-1*P_1 -> the sum of P_k * P_n-k
= (1/(n+1))*(2n choose n)

a more consise way to think is n fatorial (n!)

Space complexity: O(n^2)

*/


class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int n = input.size();
        vector<int> ans;
        if(n == 0) return ans;
        
        return breakdown(input, ans);
    }
private:
    vector<int> breakdown(string input, vector<int>& ans){
        vector<int> subans;
        
        for(int i=0; i<input.size(); i++){
            char c = input[i];
            if(c=='+' || c=='-' || c=='*'){
                vector<int> leftSide = breakdown(input.substr(0,i), ans);
                vector<int> rightSide = breakdown(input.substr(i+1), ans);
                for(auto& l : leftSide){
                    for(auto& r : rightSide){
                        if(c=='+') subans.push_back(l+r);
                        else if(c=='-') subans.push_back(l-r);
                        else if(c=='*') subans.push_back(l*r);
                    }
                }
            }
        }
        if(subans.empty()){
            subans.push_back(stoi(input));
        }
        return subans;
    }
};

/*
Approach 2: Space-optimized Approach 1
use the map to store the string that might have run before
*/
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> mymap;
        return breakdown(input, mymap);
    }
private:
    vector<int> breakdown(string input, unordered_map<string, vector<int>>& mymap){
        vector<int> subans;
        
        for(int i=0; i<input.size(); i++){
            char c = input[i];
            if(c=='+' || c=='-' || c=='*'){
                string leftStr = input.substr(0,i);
                string rightStr = input.substr(i+1);
                if(mymap.find(leftStr) == mymap.end()) mymap[leftStr] = breakdown(leftStr, mymap);
                if(mymap.find(rightStr) == mymap.end()) mymap[rightStr] = breakdown(rightStr, mymap);
                for(auto& l : mymap[leftStr]){
                    for(auto& r : mymap[rightStr]){
                        if(c=='+') subans.push_back(l+r);
                        else if(c=='-') subans.push_back(l-r);
                        else if(c=='*') subans.push_back(l*r);
                    }
                }
            }
        }
        if(subans.empty()){
            subans.push_back(stoi(input));
        }
        return subans;
    }
};