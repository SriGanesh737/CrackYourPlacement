class Solution {
public:

    int solve(int ind, int n, vector<bool>&vis){
        if(ind == n) return 1;

        int cnt = 0;

        for(int i = 1;i<=n;i++){
            if(vis[i]) continue;

            int pos = ind + 1;
            if(i%pos == 0 || pos%i == 0){
                vis[i] = true;
                cnt += solve(ind + 1, n, vis);
                vis[i] = false;
            }
        }

        return cnt;
    }
    
    int countArrangement(int n) {
        vector<bool>vis(n+1,false);
        return solve(0,n,vis);
    }
};