class Solution {
public:
    string reverseWords(string s) {
        string t = "";
        vector<string>v;
        int n = s.length();
        for(int i =0;i<n;i++){
            if(s[i]==' '){
                if(t.length())v.push_back(t);
                t = "";
            }
            else t+= s[i];
        }
        if(t.length())v.push_back(t);

        reverse(v.begin(),v.end());

        string ans = "";
        for(auto x: v) {
            ans+=x;
            ans+=' ';
        }

        ans.pop_back();
        return ans;
    }
};