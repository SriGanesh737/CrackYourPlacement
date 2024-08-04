class Solution {
  public:
    // Function to find the number of islands.
    
    void bfs(vector<vector<bool>>&vis,vector<vector<char>>&grid,int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            
            int x = cur.first;
            int y = cur.second;
            
            if(x!=0 && !vis[x-1][y] && grid[x-1][y]=='1'){
                vis[x-1][y] = true;
                q.push({x-1,y});
            }
            
            if(x!=n-1 && !vis[x+1][y]&& grid[x+1][y]=='1'){
                vis[x+1][y] = true;
                q.push({x+1,y});
            }      
            
            if(y!=0 && !vis[x][y-1]&& grid[x][y-1]=='1'){
                vis[x][y-1] = true;
                q.push({x,y-1});
            }
            
            if(y!=m-1 && !vis[x][y+1]&& grid[x][y+1]=='1'){
                vis[x][y+1] = true;
                q.push({x,y+1});
            }
            // ---------------------------Diagonal checks----------------
            
            if(x!=0 && y!=0 && !vis[x-1][y-1] && grid[x-1][y-1]=='1'){
                vis[x-1][y-1] = true;
                q.push({x-1,y-1});
            }
            
            if(x!=n-1 && y!=m-1 && !vis[x+1][y+1]&& grid[x+1][y+1]=='1'){
                vis[x+1][y+1] = true;
                q.push({x+1,y+1});
            }      
            
            if(y!=0&&x!=n-1 && !vis[x+1][y-1]&& grid[x+1][y-1]=='1'){
                vis[x+1][y-1] = true;
                q.push({x+1,y-1});
            }
            
            if(y!=m-1&& x!=0 && !vis[x-1][y+1]&& grid[x-1][y+1]=='1'){
                vis[x-1][y+1] = true;
                q.push({x-1,y+1});
            }
            
        }
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int cnt = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]=='1'){
                    cnt++;
                    vis[i][j] = true;
                    bfs(vis,grid,i,j);
                }
            }
        }
        
        return cnt;
    }
};