class Solution {
public:
    int ans = 0;
    int m,n;

    void solve(int i, int j, vector<vector<int>>&grid, vector<vector<bool>>&vis, int cnt){
        if(grid[i][j] == 2){
            if(cnt == 0) ans++;
            return;
        }

        // right
        if(j<n-1 && !vis[i][j+1] && grid[i][j+1] != -1){
            vis[i][j+1] = true;
            solve(i,j+1,grid,vis,cnt-1);
            vis[i][j+1] = false;
        }

        // left
        if(j>0 && !vis[i][j-1] && grid[i][j-1] != -1){
            vis[i][j-1] = true;
            solve(i,j-1,grid,vis,cnt-1);
            vis[i][j-1] = false;
        }

        // top
        if(i>0 && !vis[i-1][j] && grid[i-1][j] != -1){
            vis[i-1][j] = true;
            solve(i-1,j,grid,vis,cnt-1);
            vis[i-1][j] = false;
        }

        // bottom
        if(i<m-1 && !vis[i+1][j] && grid[i+1][j] != -1){
            vis[i+1][j] = true;
            solve(i+1,j,grid,vis,cnt-1);
            vis[i+1][j] = false;
        }
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int non_obs = 0;
        for(auto row:grid){
            for(auto ele: row){
                if(ele == 0) non_obs++;
            }
        }

        ans = 0;

        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));

        int i = 0, j = 0;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(grid[i][j]==1) goto stop;
            }
        }

        stop:;

        vis[i][j] = true;
        solve(i,j,grid,vis,non_obs+1);

        return ans;
    }
};