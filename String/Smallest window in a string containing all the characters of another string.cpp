class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    
    bool check(vector<int>&text, vector<int>&pat){
        for(int i=0;i<26;i++){
            if(text[i]<pat[i]) return false;
        }
        return true;
    }
    string smallestWindow (string s, string p)
    {
        // Your code here
        
        int i = 0, j = 0;
        
        int n = s.length();
        int len = p.length();
        
        int mini_ind = 0;
        int mini_len = n+1;
        
        vector<int>pat(26,0);
        vector<int>text(26,0);
        
        for(auto ch: p) pat[ch-'a']++;
        
        while(j<n){
            text[s[j]-'a']++;
            while(check(text,pat)){
                if(j-i+1<mini_len){
                    mini_ind = i;
                    mini_len = j-i+1;
                }

                // remove from front
                text[s[i]-'a']--;
                i++;
            }
            j++;
        }
        
        if(mini_len == n+1) return "-1";
        // cout<<mini_ind<<" .."<<mini_len<<endl;
        string ans = "";
        for(int i = 0;i<mini_len;i++){
            ans += s[i + mini_ind];
        }
        return ans;
    }
};