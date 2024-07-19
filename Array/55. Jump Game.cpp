class Solution {
public:
    bool canJump(vector<int>& nums) {
        int range = nums[0];

        for(int i = 1;i<nums.size();i++){
            if(i>range) return false;
            range = max(range,i+nums[i]);
        }

        return true;
    }
};