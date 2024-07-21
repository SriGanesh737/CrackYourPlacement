class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
    int n = needle.length(); 

    for(int i = 0;i<=m-n;i++){

        bool flag = true;
        for(int j =0;j<n;j++){
            if(haystack[i+j]!=needle[j]) {
                flag = false;
                break;
            }
        }

        if(flag) return i;
    }

    return -1;
    }
};