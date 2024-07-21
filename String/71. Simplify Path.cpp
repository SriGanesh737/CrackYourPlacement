class Solution {
public:

    vector<string> split(string s){
        vector<string>v;
        int n = s.length();
        int i = 1;

        string t = "";
        while(i<n){
            if(s[i]=='/'){
                if(t.length()){

                    // cout<<"---> "<<t<<" <---"<<endl;
                    if(t==".." && v.size()>0) v.pop_back();
                    else if(t=="..") ;
                    else if(t==".") ;
                    else v.push_back(t);
                }
                t = "";
            }
            else t+=s[i];

            i++;
        }
        if(t.length()){
            if(t==".." && v.size()>0) v.pop_back();
            else if(t=="..") ;
            else if(t==".") ;
            else v.push_back(t);
        }
        
        return v;
    }
    string simplifyPath(string path) {
        vector<string>words = split(path);

        string ans = "";

        for(auto x: words){
            ans += "/";
            ans += x;
        }

        if(ans=="") return "/";
        else return ans;
    }
};