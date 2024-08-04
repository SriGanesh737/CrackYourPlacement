class Solution {
public:

    int ones(int i , int j, int m,int n, vector<vector<int>>&board){
        int cnt = 0;

        // 0 0 -> 0
        // 1 0 -> 2
        // 0 1 -> 1
        // 1 1 -> 3

        if(i!=0 && (board[i-1][j]&1)==1) cnt++;
        if(i!=m-1 && (board[i+1][j]&1)==1) cnt++;
        if(j!=0 && (board[i][j-1]&1)==1) cnt++;
        if(j!=n-1 && (board[i][j+1]&1)==1) cnt++;
        if(i!=0 && j!=0 && (board[i-1][j-1]&1)==1) cnt++;
        if(i!=0 && j!=n-1 && (board[i-1][j+1]&1)==1 ) cnt++;
        if(i!=m-1 && j!=0 && (board[i+1][j-1]&1)==1) cnt++;
        if(i!=m-1 && j!=n-1 && (board[i+1][j+1]&1)==1) cnt++;

        return cnt; 
    }
    void gameOfLife(vector<vector<int>>& board) {

        int m = board.size(), n = board[0].size();

        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                int oc = ones(i,j,m,n,board);
                if(board[i][j]==1){
                    // new 0 old 1 so 01.
                    if(oc<2 || oc>3) board[i][j] = 1;
                    // new 1 old 1 so 11 = 3. 
                    else board[i][j] = 3;
                }
                else{
                    // new 1 old 0 so 10 = 2.
                    if(oc==3) board[i][j] = 2;
                    // new 0 old 0 so 00 = 0.
                    else board[i][j] = 0;
                }
            }
        }


        // Now transform the board values to new values.
        // right shift each value by 1.
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++)
                board[i][j]>>=1;


    }
};