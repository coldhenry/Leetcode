

// Naive way
class Solution {
public:
    void reverseWords(vector<char>& s) {
        string ans = "";
        string tmp = "";
        for(auto& c : s){
            if(c == ' '){
                ans = ' ' + tmp + ans;
                tmp = "";
            } else {
                tmp += c;
            }
        }
        ans = tmp + ans;
        for(int i = 0; i < s.size(); i++){
            s[i] = ans[i];
        }
    }
};

//Reverse way
class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int n = s.size(), lp = 0, rp = 0;
        while(rp < n){
            while(rp < n && !isspace(s[rp])) rp++;
            reverse(s.begin()+lp, s.begin()+rp);
            lp = ++rp;
        }
    }
};