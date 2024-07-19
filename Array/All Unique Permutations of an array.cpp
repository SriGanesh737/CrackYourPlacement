class Solution {
  public:
  
    void solve(int ind, vector<int>&arr, int n,vector<vector<int>>&ans, vector<bool>&vis,vector<int>&temp){
        if(ind == n) {
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                temp.push_back(arr[i]);
                vis[i] = true;
                solve(ind+1,arr,n,ans,vis,temp);
                temp.pop_back();
                vis[i] = false;
                
                int cur = arr[i];
                while(arr[i]==cur)i++;
                i--;
            }
        }
        
        
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        
        vector<vector<int>> ans;
        vector<bool>vis(n,false);
        vector<int>temp;
        
        sort(arr.begin(),arr.end());
        
        solve(0,arr,n,ans,vis,temp);
        
        return ans;
    }
};