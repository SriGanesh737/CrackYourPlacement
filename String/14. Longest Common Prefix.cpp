class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int j = 0;
        string ans = "";
        int n = strs.size();
        while(1){
            for(int i =0;i<n;i++){
                if(j>=strs[i].size() || strs[i][j]!=strs[0][j]) return ans;
            }
            ans+=strs[0][j];
            j++;
        }
        return ans;
    }
};