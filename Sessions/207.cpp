/*

GRAPH

1. Topological ordering:
可以做出一個現象是：把一排nodes排一值線，所有點都會指向右邊
基本性質就是無環，而 Topological sort 可以在 O(V+E) 找到這個 Ordering

2. Directed Acyclic Graphs (DAG)
no cycle + directed -> only type for topological ordering
NOTE: Tree 就是一種，從leaf開始放就可以找到 t. ordering

3. Topological sort:
(1) pick an unvisited node
(2) do a DFS
(3) backtrack to the previous node if the node is an end
(4) if no more nodes to backtrack, pick another unvisited node, repeat from(2)




*/




bool canFinish(int n, vector<pair<int, int>>& pre) {
    vector<vector<int>> adj(n, vector<int>());
    vector<int> degree(n, 0);
    for (auto &p: pre) {
        adj[p.second].push_back(p.first);
        degree[p.first]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (degree[i] == 0) q.push(i);
    while (!q.empty()) {
        int curr = q.front(); q.pop(); n--;
        for (auto next: adj[curr])
            if (--degree[next] == 0) q.push(next);
    }
    return n == 0;
}