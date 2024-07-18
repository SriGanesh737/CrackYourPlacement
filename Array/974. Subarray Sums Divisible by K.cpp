class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>mp(k,0);
        int sum = 0;
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>0)
                mp[sum%k]++;
            else if(sum%k==0) mp[0]++;
            else mp[sum%k + k]++;
        }

        

        int ans = mp[0];
        for(int i=0;i<k;i++){
            cout<<mp[i]<<endl;
            ans += mp[i] * (mp[i] -1) /2;
        }

        return ans;
    }
};