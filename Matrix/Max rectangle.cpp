class Solution{
  public:
  
    vector<vector<int>> nsi_psi(vector<int>&v){
        int n = v.size();
        
        vector<int>nsi(n,n);
        vector<int>psi(n,-1);
        stack<int>st;
        
        // find the previous smaller indexes
        st.push(0);
        for(int i = 1;i<n;i++){
            while(!st.empty() && v[i]<=v[st.top()]) st.pop();
            if(!st.empty()) psi[i] = st.top();
            st.push(i);
        }
        
        // clear the stack.
        while(!st.empty()) st.pop();
        
        // find the next smaller indexes.
        st.push(n-1);
        for(int i = n-2;i>=0;i--){
            while(!st.empty() && v[i]<=v[st.top()]) st.pop();
            if(!st.empty()) nsi[i] = st.top();
            st.push(i);
        }
        
        vector<vector<int>>ans;
        ans.push_back(nsi);
        ans.push_back(psi);
        return ans;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        
        vector<int>heights(m,0);
        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0; j<m; j++){
                if(M[i][j]==0) heights[j] = 0;
                else heights[j] += 1;
            }
            
            auto ns_ps = nsi_psi(heights);
            
            // Now find out the max area of rectangle with the ith row as base.
            for(int k = 0;k<m;k++){
                // consider heights[k] as the small one.
                int ri = ns_ps[0][k];
                int li = ns_ps[1][k];
                int width = ri - li -1;
                ans = max(ans, width * heights[k]);
            }
        }
        
        return ans;
        
    }
};
