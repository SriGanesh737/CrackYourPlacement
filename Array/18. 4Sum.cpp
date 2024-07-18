class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        long i = 0, n = nums.size();

        while(i<n){
            long a = nums[i];

            long j = i+1;
            while(j<n){
                long b = nums[j];

                long t = target - a-b;

                long l = j+1, r = n-1;
                while(l<r){
                    long c = nums[l], d = nums[r];
                    if(c + d == t) {

                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});

                        while(l<n && nums[l] == c) l++;
                        while(r>=0 && nums[r] == d) r--;
                    }
                    else if(c+d > t) r--;
                    else l++;
                }

                while(j<n && nums[j] == b) j++;
            }

            while(i<n && nums[i] == a) i++;
        }  

        return ans;      
    }

};