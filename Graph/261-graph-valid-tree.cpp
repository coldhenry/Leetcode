/*

A valid tree properties:
1. 不能有圈圈，#edges = #node - 1
2. all nodes must be visited

*/



class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
  		// circle exists
  		if(edges.size() != n-1) return false;

  		// form an adjacency matrix
  		vector<vector<int>> adjMat(n, vector<int>(n));
  		for(auto& e : edges){
  			adjMat[e[0]].push_back(e[1]);
  			adjMat[e[1]].push_back(e[0]);
  		}

  		// Dijkstra's
  		stack<int> st;
  		vector<bool> visited(n, false);
  		st.push(0);
  		while(!st.empty()){
  			int curr = st.top(); st.pop();
  			visited[curr] = true;
  			for(auto& neighbor : adjMat[curr]){
  				if(!visited[neighbor]) st.push(neighbor);
  			}
  		}
  		// second property
  		for(auto& v : visited) if(!v) return false;
  		return true;
    }
};