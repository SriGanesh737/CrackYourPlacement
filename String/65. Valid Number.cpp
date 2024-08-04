class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        int n = s.length();

        // skip first - or +
        if(s[i]=='-' || s[i]=='+') i++;
        if(i==n) return false;

        // skip all numeric characters.
        while(i<n && s[i]>='0' && s[i]<='9') i++;

        // skip if . is present
        if(i<n && s[i]=='.') {
            if(i!=0 && (s[i-1]>='0' && s[i-1]<='9')) i++;
            else if(i!=n-1 && s[i+1]>='0' && s[i+1]<='9') i++;
            else return false;
        }

        // skip all the numbers after '.'
        while(i<n && s[i]<='9' && s[i]>='0') i++;

        // check and skip if e.
        if(i<n && (s[i]=='e'||s[i]=='E')) {
            if(i==0 || (s[i-1]!='.' && (s[i-1]<'0'|| s[i-1]>'9'))) return false;
            // skip the e character
            else {
                i++;
                if(i==n) return false;
                while(i<n && s[i]<='9' && s[i]>='0') i++;
            }
        }

        // if now symbol is  '-' or '+' check left side e there or not.
        if(i<n && s[i]=='-' || s[i]=='+'){
            if(i==0 || (s[i-1]!='e'&&s[i-1]!='E')) return false;
            else {
                i++;
                if(i==n) return false;
                while(i<n && s[i]<='9' && s[i]>='0') i++;
            }
        }

        return i==n;
    }
};