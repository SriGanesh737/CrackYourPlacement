class Solution {
public:

    int solveTab(int m , int n){
        // vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        vector<int>prevRow(n,0);

        for(int i = m-1;i>=0;i--){
            vector<int>curRow(n,0);
            int prevVal = 0;
            for(int j = n-1;j>=0;j--){
                if(i==m-1 && j==n-1) curRow[j] = 1;
                else curRow[j] = prevVal + prevRow[j];
                prevVal = curRow[j];
            }
            prevRow = curRow;
        }

        return prevRow[0];
    }
    int uniquePaths(int m, int n) {
        return solveTab(m,n);
    }
};