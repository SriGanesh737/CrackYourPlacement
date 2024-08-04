class Solution {
public:

    vector<int> nextt(int i, int j){
        if(j==8) return {i+1,0};
        else return {i,j+1};
    }

    bool isPossible(int i, int j, char num, vector<vector<char>>&board){
        // row check
        for(int y = 0;y<9;y++) if(board[i][y]==num) return false;
        
        // col check
        for(int x = 0;x<9;x++) if(board[x][j]==num) return false;

        // square check
        int m = i/3;
        int n = j/3;

        for(int x = 0;x<3;x++){
            for(int y = 0;y<3;y++){
                if(board[x+3*m][y+3*n] == num) return false;
            }
        }

        return true;
    }

    void solve(int i, int j, vector<vector<char>>&board,vector<vector<char>>&ans){
        if(i == 9){
            // cout<<"here"<<endl;
            ans = board;
            return;
        }

        // fill pos i,j with possible char
        if(board[i][j]!='.'){
            auto v = nextt(i,j);
            solve(v[0],v[1],board,ans);
        }
        else{
            for(int num = 1; num<=9;num++){
                if(isPossible(i,j,num+'0',board)){
                    board[i][j] = num + '0';
                    auto v = nextt(i,j);
                    solve(v[0],v[1],board,ans);
                    board[i][j] = '.';
                }
            }
        }

    }
    

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>>ans;
        solve(0,0,board,ans);
        board = ans;
    }
};