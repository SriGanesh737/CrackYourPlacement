class Solution {
public:

    void solve(int ind, int n, vector<int>&arr, int target, vector<vector<int>>&ans,vector<int>&cur){
        if(target == 0) {
            ans.push_back(cur);
            return;
        }
        if(ind == n || target<0) return;
        if(arr[ind]>target) return;

        // pick case
        cur.push_back(arr[ind]);
        solve(ind+1,n,arr,target-arr[ind],ans,cur);
        cur.pop_back();

        int ele = arr[ind];
        while(ind<n && arr[ind]==ele) ind++;

        // not pick case
        solve(ind,n,arr,target,ans,cur);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>>ans;
        vector<int>cur;

        sort(candidates.begin(),candidates.end());

        solve(0,candidates.size(),candidates,target,ans,cur);

        return ans;
    }
};