class Solution {
public:


    int solve(int ind, vector<int>&nums, int k, vector<int>&dp){
        if(ind == nums.size()) return -1;
        if(dp[ind] != -2) return dp[ind];
        
        int sum = nums[ind];
        
        int ans;
        
        int cur = solve(ind+1,nums,k,dp);
        if(cur == -1) ans = 0;
        else ans = (k-sum)*(k-sum) + cur;
        
        
        for(int i = ind+1;i<nums.size();i++){
            if(sum + nums[i] + 1<=k) {
                sum += nums[i] + 1;
                int cur = solve(i + 1, nums, k, dp);
                if(cur == -1) ans = 0;
                else ans = min(ans, (k-sum)*(k-sum) + cur);
            }
            else break;
        }
        
        // cout<<"ind: "<<ind<<"  ans: "<< ans<<endl;
        
        return dp[ind] = ans;
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n = nums.size();
        vector<int>dp(n,-2);
        return solve(0,nums,k,dp);
    } 
};



