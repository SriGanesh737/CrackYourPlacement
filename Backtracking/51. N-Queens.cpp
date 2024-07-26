class Solution {
public:

    bool isPossible(int i, int j, vector<string>&brd){
        int n = brd.size();

        // col check
        for(int x = 0;x<i;x++){
            if(brd[x][j] == 'Q') return false;
        }

        // check left diagonal
        int x = i-1, y = j-1;
        while(x>=0 && y>=0){
            if(brd[x][y]=='Q') return false;
            x--;
            y--;
        }

        x = i-1, y = j +1;
        while(x>=0 && y<n){
            if(brd[x][y] == 'Q') return false;
            x--;
            y++;
        }

        return true;
    }

    void solve(int i, int n,vector<string>&brd,vector<vector<string>>&ans){
        if(i == n) {
            ans.push_back(brd);
            return;
        }

        for(int j = 0;j<n;j++){
            if(isPossible(i,j,brd)){
                
                brd[i][j] = 'Q';
                solve(i+1,n,brd,ans);
                brd[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string>brd(n,string(n,'.'));
        // ans.push_back(brd);
        solve(0,n,brd,ans);
        return ans;
        
    }
};