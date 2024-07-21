class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& strs) {
        //code here
        
        vector<vector<string>>ans;

        map<string,vector<string>>mp;

        for(auto s: strs){
            string str = s;
            sort(str.begin(),str.end());
            if(mp.find(str)!=mp.end()) {
                mp[str].push_back(s);
            }
            else {
                vector<string>v;
                v.push_back(s);
                mp[str] = v;
            }
        }

        for(auto pr: mp){
            ans.push_back(pr.second);
        }

        return ans;
    }
};