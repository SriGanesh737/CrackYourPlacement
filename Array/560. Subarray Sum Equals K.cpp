class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int i = 0, j = 0, sum=0;
        int n = nums.size();

        map<int,int>mp;
        for(int i = 0;i<n;i++){
            sum += nums[i];
            if(sum == k) cnt++;

            int target = sum - k;
            if(mp.find(target)!=mp.end()) cnt+=mp[target];

            mp[sum]++;
        }
       
        return cnt;
    }
};