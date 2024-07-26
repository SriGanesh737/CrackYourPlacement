class Solution {
public:

    bool isPalindrome(string s){
        int n = s.length();
        for(int i = 0; i<n/2; i++){
            if(s[i]!=s[n-i-1]) return false;
        }
        return true;
    }

    void solve(int ind, int n, string s, vector<vector<string>>&ans, vector<string>&cur)
    {
        if(ind == n ){
            ans.push_back(cur);
            return;
        }

        string t = "";

        for(int i = ind;i<n;i++){
            t+=s[i];
            if(isPalindrome(t)) {
                cur.push_back(t);
                solve(i+1,n,s,ans,cur);
                cur.pop_back();
            } 
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>cur;
        solve(0,s.length(),s,ans,cur);
        return ans;
    }
};