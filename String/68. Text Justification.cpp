class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        int n = words.size();
        for(int i =0;i<n;i++){
            int cur = words[i].length();
            int j = i+1;
            while(j<n){
                if(words[j].length()+cur+1<=maxWidth) {
                    cur += 1 + words[j].length();
                    j++;
                }
                else break;
            }

            int line_cnt = j - i;
            int actual_word_length = cur - line_cnt +1;
            int total_spaces = maxWidth - actual_word_length;
            string temp = words[i];
            string spaces = "";
            if(j == n || line_cnt == 1){
                spaces = " ";
            }
            else {
                for(int x = 0; x<total_spaces/(line_cnt-1);x++){
                    spaces += ' ';
                }
            }

            for(int k = i+1;k<j;k++){
                temp += spaces;
                if(j!=n && k-i-1 < total_spaces%(line_cnt-1)) temp += ' ';
                temp += words[k];
            }
            while((j==n||line_cnt==1) && temp.size()!=maxWidth) temp+=' ';
            ans.push_back(temp);    
            i = j - 1;
        }
        return ans;
    }
};