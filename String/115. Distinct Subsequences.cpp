class Solution {
public:

    int m,n;
    int solve(int i, int j, string s, string t, vector<vector<int>>&dp){
        if(j == n) return 1;
        
        if(m - i < n- j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int ways = 0;

        // skip current i
        ways += solve(i+1,j,s,t,dp);

        if(s[i]==t[j]) ways += solve(i+1,j+1,s,t,dp);

        return dp[i][j] = ways;
    }

    int solveTab(string s, string t){
        vector<vector<unsigned int>>dp(m+1,vector<unsigned int>(n+1,0));

        for(int i=0;i<=m;i++) dp[i][n] = 1;

        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                if(m-i < n-j) continue;
                int ways = 0;
                ways += dp[i+1][j];
                if(s[i]==t[j]) ways += dp[i+1][j+1];

                dp[i][j] = ways;
            }
        }
        return dp[0][0];
    }
    int numDistinct(string s, string t) {
        m = s.length();
        n = t.length();

        vector<vector<int>>dp(m,vector<int>(n,-1));
        // return  solve(0,0,s,t,dp);

        return solveTab(s,t);
    }
};