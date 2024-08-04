class Solution {
public:

    bool check(unordered_map<char,int>&text, unordered_map<char,int>&pat){
        for(auto it: pat){
            char key = it.first;
            int fre = it.second;
            
            if(text.find(key)==text.end() || text[key]<fre) return 0;
        }
        return 1;
    }

    string minWindow(string s, string p) {
        int i = 0, j = 0;
        
        int n = s.length();
        int len = p.length();
        
        int mini_ind = 0;
        int mini_len = n+1;
        
        unordered_map<char,int>pat;
        unordered_map<char,int>text;
        
        for(auto ch: p) pat[ch]++;
        
        while(j<n){
            text[s[j]]++;
            while(check(text,pat)){
                if(j-i+1<mini_len){
                    mini_ind = i;
                    mini_len = j-i+1;
                }

                // remove from front
                text[s[i]]--;
                i++;
            }
            j++;
        }

        if(mini_len == n+1) return "";
        
        string ans = "";
        for(int i = 0;i<mini_len;i++){
            ans += s[i + mini_ind];
        }
        return ans;
    }
};

