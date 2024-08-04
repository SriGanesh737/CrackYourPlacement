class Solution{
public:

    int dfs(int i, int j, int n, int m, vector<vector<char>>&mat){
        mat[i][j]='.';
        if(i!=0&&mat[i-1][j]=='O'){
            dfs(i-1,j,n,m,mat);
        }
        if(i!=n-1 && mat[i+1][j]=='O'){
            dfs(i+1,j,n,m,mat);
        }
        if(j!=0 && mat[i][j-1]=='O'){
            dfs(i,j-1,n,m,mat);
        }
        if(j!=m-1 && mat[i][j+1]=='O'){
            dfs(i,j+1,n,m,mat);
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        for(int i = 0;i<n;i++){
            if(mat[i][0]=='O') dfs(i,0,n,m,mat);
            if(mat[i][m-1]=='O') dfs(i,m-1,n,m,mat);
        }
        
        for(int j = 0;j<m;j++){
            if(mat[0][j]=='O') dfs(0,j,n,m,mat);
            if(mat[n-1][j]=='O') dfs(n-1,j,n,m,mat);
        }
        
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j]=='.') mat[i][j] = 'O';
                else if(mat[i][j]=='O') mat[i][j] = 'X';
            }
        }
        
        return mat;
    }
};