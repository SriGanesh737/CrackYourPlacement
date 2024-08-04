class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        long long int nzp = 1;
        int zc = 0;
        int n = nums.size();
        vector<long long int>ans(n,0);
        for(auto x: nums) {
            if(x==0) zc++;
            else nzp*=x;
        }
        
        if(zc>1) return ans;
        
        for(int i=0;i<n;i++){
            if(nums[i]!=0) ans[i] = (zc==0)? nzp/nums[i]: 0;
            else ans[i] = nzp;
        }
        
        return ans;
    }
};
