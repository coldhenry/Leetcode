
//Approach 1: graph intepretation (TLE)
int findCelebrity(int n) {
    vector<vector<int>> graph(n, vector<int>(n,0));
    unordered_map<int, pair<int,int>> nodeMap;
    
    // construct the graph, node i knows node j: i->j
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(knows(j,i)){
                graph[j][i] = 1;
                nodeMap[j].second++;
                nodeMap[i].first++;
            }
        }
    }
    
    for(auto& node : nodeMap){
        if(node.second.first == n && node.second.second == 1) return node.first;
    }
    return -1;   
}

//Appraoch 2: brute force
class Solution {
public:
    int findCelebrity(int n) {
        for(int node = 0; node < n; node++){
          if(isCelebrity(node, n)) return node;   
        }
        return -1;
    }
private:
    bool isCelebrity(int node, int n){
        for(int k = 0; k < n; k++){
            if(k == node) continue;
            else{
                if(knows(node, k) || !knows(k, node)) return false;
            }
        }
        return true;
    }
};



//Approach 3: logical Deduction
class Solution {
public:
    int findCelebrity(int n) {
        int node_check = 0;
        for(int i = 1; i < n; i++){
            // if node_check knows, node_check isn't a celebrity
            if(knows(node_check, i)) node_check = i;
            // if node_check doesn't, node i isn't a celebrity (continue)
        }
        // we only do logical deduction previously, have to check if it is really a celebrity
        return isCelebrity(node_check, n)? node_check : -1;
    }
private:
    bool isCelebrity(int node, int n){
        for(int i = 0; i < n; i++){
            if(i == node) continue;
            else{
                if(knows(node, i) || !knows(i, node)) return false;
            }
        }
        return true;
    }
};