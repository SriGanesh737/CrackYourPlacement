class Solution {
public:

    void solve(int ind, int n, vector<int>&nums, vector<vector<int>>&ans, vector<int>&cur){
        if(ind == n) {
            ans.push_back(cur);
            return;
        }

        // pick current element
        cur.push_back(nums[ind]);
        solve(ind+1,n,nums,ans,cur);
        cur.pop_back();

        // skip current element
        int ele = nums[ind];
        while(ind<n && nums[ind]==ele) ind++;
        solve(ind,n,nums,ans,cur);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int>cur;
       sort(nums.begin(),nums.end());
       solve(0,nums.size(),nums,ans,cur);
        return ans;
    }
};