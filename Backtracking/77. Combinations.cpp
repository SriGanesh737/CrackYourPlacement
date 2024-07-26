class Solution {
public:

    void solve(int num, int n, int k, vector<int>&cur, vector<vector<int>>&ans){
        if(cur.size() == k){
            ans.push_back(cur);
            return;
        }
        if(num>n) return;

        // pick num
        cur.push_back(num);
        solve(num+1,n,k,cur,ans);
        cur.pop_back();

        // skip num
        solve(num+1, n, k, cur, ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>cur;

        solve(1,n,k,cur,ans);
        return ans;
    }
};