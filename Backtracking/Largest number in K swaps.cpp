class Solution
{
    public:
    //Function to find the largest number after k swaps.
    
    
    void solve(int ind, int n, int k, string &str, string &ans){
        if(ind == n || k==0){
            ans = max(ans,str);
            return;
        }
        
        // no swap
        solve(ind+1,n,k,str,ans);
        
        // swap
        for(int j = ind+1;j<n;j++){
            
            if(str[j]>str[ind]){
            swap(str[ind],str[j]);
            solve(ind+1,n,k-1,str,ans);
            swap(str[ind],str[j]);  
            }

        }
        
    }
    
    string findMaximumNum(string str, int k)
    {
       // code here.
       int n = str.length();
       string ans;
       solve(0,n,k,str,ans);
       return ans;
    }
};