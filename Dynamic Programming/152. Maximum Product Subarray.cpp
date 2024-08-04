class Solution {
public:
    double global_maxi;
    pair<double,double> solve(int ind, vector<int>& nums, int n){
        if(ind == n-1) return {nums[n-1], nums[n-1]};

        double mini, maxi;

        auto pr = solve(ind+1,nums,n);
        double mi = pr.first;
        double ma = pr.second;
        if(nums[ind]<0) swap(mi,ma);
        mini = min(mi*nums[ind],(double) nums[ind]);
        maxi = max(ma*nums[ind],(double) nums[ind]);
        global_maxi = max(maxi,global_maxi);
        return {mini,maxi};
    }
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        global_maxi = nums[n-1];
        auto ans = solve(0,nums,nums.size());
        return global_maxi;
    }
};