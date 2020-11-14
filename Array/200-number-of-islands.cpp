/*
經典 BFS/DFS 題
需要注意的是，每次寫的時候，座標都蠻容易寫錯，須注意，其他還好

Time Complexity: O(|V| + |E|) no matter DFS or BFS
Space complexity: O(|V|)

*/


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = rows == 0 ? 0 : grid[0].size();
        if(rows==0 || cols==0) return 0;
        
        int count = 0;
        for(int i=0; i<cols; i++){
            for(int j=0; j<rows; j++){
                if(grid[j][i] == '1'){
                    BFS(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
private:
    int rows, cols;
    vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
    void BFS(int i, int j, vector<vector<char>>& grid){
        
        grid[j][i] = '0';
        queue<pair<int,int>> queued;
        queued.push(make_pair(i,j));
        while(!queued.empty()){
            int n = queued.size();
            for(int idx=0; idx<n; idx++){
                pair<int, int> point = queued.front(); queued.pop();
                for(auto& d : dir){
                    int nb_x = point.first + d[0];
                    int nb_y = point.second + d[1];
                    if(nb_x >=0 && nb_x < cols && nb_y >= 0 && nb_y < rows &&　grid[nb_y][nb_x] == '1'){     
                        queued.push(make_pair(nb_x, nb_y));
                        grid[nb_y][nb_x] = '0';
                    }
                }
            }
        }
    }
};