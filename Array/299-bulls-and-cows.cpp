#include <iostream>

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,unordered_set<int>> ans;
        for(int i = 0; i < secret.size(); i++){
            char c = secret[i];
            ans[c].insert(i);
        }
        int A = 0, B = 0;
        for(int j = 0; j < guess.size(); j++){
            char c = guess[j];
            if(ans.find(c) != ans.end() && ans[c].find(j) != ans[c].end()){
                A++;
                ans[c].erase(j);
                if(ans[c].empty()) ans.erase(c);
            }
        }
        for(int j = 0; j < guess.size(); j++){
            char c = guess[j];
            if(ans.find(c) != ans.end()){
                if(c == secret[j]) continue;
                if(!ans[c].empty()){
                    B++;
                    ans[c].erase(ans[c].begin());
                    if(ans[c].empty()) ans.erase(c);
                }
            }
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};