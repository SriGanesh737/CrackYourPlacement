class Solution {
public:

    bool find(int i, int j, int ind,vector<vector<char>>& board,string word ){
        if(ind == word.size()) return true;
        if(board[i][j] != word[ind]) return false;
        if(ind == word.size() - 1) return true;

        int m = board.size();
        int n = board[0].size();

        char ch = board[i][j];
        board[i][j] = '.';
        bool f1 = false,f2 = false,f3 = false,f4 = false;

        if(i!=0){
            f1 = find(i-1,j,ind+1,board,word);
        }

        if(i!=m-1){
            f2 = find(i+1,j,ind+1,board,word);
        }

        if(j!=0){
            f3 = find(i,j-1,ind+1,board,word);
        }

        if(j!=n-1){
            f4 = find(i,j+1,ind+1,board,word);
        }
        board[i][j] = ch;
        return f1 || f2 || f3 || f4;
    }
    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(find(i,j,0,board, word)) return true;
            }
        }

        return false;
    }
};