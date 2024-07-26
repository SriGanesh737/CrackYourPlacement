class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i =0;i<n;i++){
            int to_Node = abs(nums[i]) - 1;

            if(nums[to_Node]<0) ans.push_back(to_Node+1);
            else nums[to_Node] *= -1;
        }

        return ans;
    }
};