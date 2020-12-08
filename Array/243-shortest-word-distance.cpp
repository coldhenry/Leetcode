

// 243: try finding a shortest distance b/t 2 words
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int i = 0, pos1 = 2*words.size(), pos2 = 3*words.size(), tmp = words.size()-1;
        for(auto& word : words){
            if(word == word1) pos1 = i;
            else if(word == word2) pos2 = i;
            tmp = min(tmp, abs(pos1- pos2));
            i++;
        }
        return tmp;
    }
};


// 244: if the operation would be used multiple times
// KEY: use a map to store all occurances for future use
class WordDistance {
public:

    unordered_map<string, vector<int>> posMap;
    WordDistance(vector<string>& words) {
        for(int i = 0; i < words.size(); i++){
            posMap[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int tmp = INT_MAX;
        for(auto& l1 : posMap[word1]){
            for(auto& l2 : posMap[word2]){
                tmp = min(tmp, abs(l1-l2));
            }
        }
        return tmp;
    }
};

// 245: 243 + word1 can as same as word2
// approach 1
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        
        unordered_map<string, vector<int>> posMap;
        for(int i = 0; i < words.size(); i++){
            posMap[words[i]].push_back(i);
        }
        
        if(word1 == word2){
            int tmp = INT_MAX;
            vector<int> idx = posMap[word1];
            for(int i = 0; i < idx.size(); i++){
                for(int j = 0; j < idx.size(); j++){
                    if(i == j) continue;
                    else{
                        tmp = min(tmp, abs(idx[i] - idx[j]));
                    }
                }
            }
            return tmp == INT_MAX? 0 : tmp;
        } else {
            int tmp = INT_MAX;
            for(auto& i : posMap[word1]){
                for(auto& j : posMap[word2]){
                    tmp = min(tmp, abs(i - j));
                }
            }
            return tmp;
        }
        
    }
};

// approach 2: a small trick on same words positon---> swap
class Solution {
public:
int shortestWordDistance(vector<string>& words, string word1, string word2) {
    long long dist = INT_MAX, i1 = dist, i2 = -dist;
    bool same = word1 == word2;
    for (int i=0; i<words.size(); i++) {
        if (words[i] == word1) {
            i1 = i;
            if (same)
                // since word2 is as same as word1 but this condition would meet before the other one
                // change the value to i2 so that i1 could be filled with the next position of the same value
                swap(i1, i2);
        } else if (words[i] == word2) {
            i2 = i;
        }
        dist = min(dist, abs(i1 - i2));
    }
    return dist;
}
};

