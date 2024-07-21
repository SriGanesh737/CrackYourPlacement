class Solution {
public:

    void solve(int ind, int len, string &s, int left_count,vector<string>&ans){
        if(ind == len) {
            if(left_count == 0)
                ans.push_back(s);
            return;
        }

        // if left_count > 0 we can add a right paranthesis.
        if(left_count>0){
            s += ')';
            solve(ind+1,len,s,left_count - 1, ans);
            s.pop_back();
        }

        // add a left paranthesis 
        s+='(';
        solve(ind+1,len,s,left_count + 1, ans);
        s.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s="";
        solve(0,2*n,s,0,ans);

        return ans;
    }
};