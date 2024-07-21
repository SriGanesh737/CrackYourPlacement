class Solution {
public:
    bool validPalindrome(string s) {
        
        int n = s.length();
        int l = 0, r = n-1;

        while(l<=r){
            if(s[l]!=s[r]){
                int i1 = l+1, j1 = r, i2 = l, j2 = r-1;

                while(i1<=j1 && s[i1] == s[j1]) {
                    i1++;
                    j1--;
                } 
                while(i2<=j2 && s[i2] == s[j2]) {
                    i2++;
                    j2--;
                } 

                return i1>j1 || i2>j2;
            }
            else{
                l++;
                r--;
            }
        }

        return true;
    }
};