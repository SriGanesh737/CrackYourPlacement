class Solution {
public:
    int ans = 0;

    void merge(int l, int r, int m, vector<int>&nums){
        vector<int>temp;

        int p1 = l;
        int p2 = m+1;

        int k = m+1;
        


        while(p1<=m && p2<=r){
            if(nums[p1]<nums[p2]) {
                while(k<=r && nums[p1]>1LL*2*nums[k]) k++;
                ans += k-m-1;
                temp.push_back(nums[p1++]);
            }
            else{
                temp.push_back(nums[p2++]);
            }
        }

        while(p1<=m){
            while(k<=r && nums[p1]>1LL*2*nums[k]) k++;
            ans += k-m-1;
            temp.push_back(nums[p1++]);
        } 
        while(p2<=r) temp.push_back(nums[p2++]);

        for(int i =l;i<=r;i++){
            nums[i] = temp[i-l];
        }
    }


    void merge_sort(int l,int r, vector<int>&nums){
        if(l>=r) return;

        int mid = (l+r)/2;
        merge_sort(l,mid,nums);
        merge_sort(mid+1,r,nums);
        merge(l,r,mid,nums);
    }

    int reversePairs(vector<int>& nums) {
        ans = 0;
        merge_sort(0,nums.size()-1,nums);

        return ans;
    }
};