class Solution {
public:

    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int>pre(n,0);
        vector<int>suf(n,0);
        int ans = 0;

        pre[0] = cardPoints[0];
        for(int i=1;i<n;i++) pre[i] = pre[i-1] + cardPoints[i];

        suf[n-1] = cardPoints[n-1];
        for(int i = n-2;i>=0;i--) suf[i] = suf[i+1] + cardPoints[i];

        ans = max(pre[k-1], suf[n-k]);

        for(int i=1;i<k;i++){
            ans = max(ans,pre[i-1] + suf[n-k+i]);
        }

        return ans;
    }
};