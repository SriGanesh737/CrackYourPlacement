class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        vector<int>ind(n);
        for(int i=0;i<n;i++) ind[i] = i;

        sort(ind.begin(), ind.end(), [&](int a, int b){return nums[a] < nums[b];});

        int l = 0, r = nums.size() - 1;
        vector<int>ans(2);

        while(l<r){
            if(nums[ind[l]] + nums[ind[r]] == target) {
                ans[0] = ind[l];
                ans[1] = ind[r];
                break;
            }
            else if(target > nums[ind[l]] + nums[ind[r]]) l++;
            else r--;
        }

        return ans;
    }
};