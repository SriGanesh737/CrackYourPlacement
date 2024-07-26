class Solution {
public:

    void solve(int ind, int n, vector<int>&nums, vector<vector<int>>&ans,vector<bool>&vis,vector<int>&cur){
        if(ind == n){
            ans.push_back(cur);
            return;
        }

        for(int i = 0;i<n;i++){

            if(!vis[i]){
            cur.push_back(nums[i]);
            vis[i] = true;
            solve(ind+1,n,nums,ans,vis,cur);
            cur.pop_back();
            vis[i] = false;

            int ele = nums[i];
            while(i<n && nums[i] == ele) i++;
            i--;
            }


        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>cur;
        int n = nums.size();
        vector<bool>vis(n,false);
        sort(nums.begin(),nums.end());
        solve(0,n,nums,ans,vis,cur);

        return ans;
    }
};


