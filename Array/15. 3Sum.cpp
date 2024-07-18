class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();

        sort(nums.begin(),nums.end());
        int k = 0;

        while(k<n){
            int target = -nums[k];

            int i = k+1, j = n-1;
            while(i<j){
                if(i==k) i++;
                else if(j==k) j--;
                else{
                    if(nums[i] + nums[j] == target){
                      ans.push_back({nums[k],nums[i],nums[j]});  
                      int a = nums[i];
                      int b = nums[j];
                      while(i<n && nums[i]==a) i++;
                      while(j>=0 && nums[j]==b) j--;
                    } 
                    else if(nums[i] + nums[j]>target) j--;
                    else i++;
                }
            }

            while(k<n && nums[k] == -target) k++;
            

        }

        return ans;
    }
};