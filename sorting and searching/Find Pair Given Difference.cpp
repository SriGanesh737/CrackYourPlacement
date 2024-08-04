class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        if(n==1) return -1;
        int i = 0, j = 1;
        
        sort(arr.begin(),arr.end());
        
        while(j<n){
            while(arr[j] - arr[i] >x) i++;
            if(j!=i && arr[j]-arr[i]==x) return 1;
            j++;
        }
        
       return -1;
    }
};