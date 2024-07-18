class Solution {
public:


    int solve(int ind, int op, vector<int>&prices,vector<vector<int>>&dp){
        if(ind == prices.size()) return 0;

        if(dp[ind][op]!=-1) return dp[ind][op]; 

        int case1 = 0, case2=0;

        // skip present day
        case1 = solve(ind+1,op,prices,dp);

        // buy or sell
        if(op==0) case2 = -prices[ind] + solve(ind+1,1,prices,dp);
        else case2 = prices[ind] + solve(ind+1,0,prices,dp);

        return dp[ind][op] = max(case1,case2);

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));

        return solve(0,0,prices,dp);
    }
};