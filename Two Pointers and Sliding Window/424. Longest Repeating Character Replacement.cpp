class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, n = s.length();

        for(int x = 0;x<26;x++){
            char target = 'A'+x;
            int i = 0, j=0;
            int cnt = 0;
            while(j<n){
                if(s[j]!=target) cnt++;
                while(cnt==k+1){
                    if(s[i]!=target) cnt--;
                    i++;
                }
                ans = max(ans,j-i+1);
                j++;
            }
        }

        return ans;
    }
};