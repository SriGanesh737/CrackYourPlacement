class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int cur = 1;

       for(int i =1; i<nums.size(); i++){
           if(nums[i]!=nums[cur-1]){
            swap(nums[i],nums[cur]);
            cur++;
           }
       }

       return cur;
    }
};