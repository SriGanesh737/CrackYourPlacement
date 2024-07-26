class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int>nsi(n,n),psi(n,-1);

        stack<int>st;

        // Finding next smaller elements
        st.push(n-1);
        for(int i = n-2;i>=0;i--){
            while(!st.empty() && heights[i] <= heights[st.top()]) st.pop();

            if(!st.empty()) nsi[i] = st.top();

            st.push(i);
        }

        // clear the stack.
        while(!st.empty()) st.pop();

        // finding previous smaller elements
        st.push(0);

        for(int i = 1;i<n;i++){
            while(!st.empty() && heights[i] <= heights[st.top()]) st.pop();
            if(!st.empty()) psi[i] = st.top();
            st.push(i);
        }

        // iterate each element and use psi, nsi to find the rectangle with that element as min.
        int ans = 0;

        for(int i =0;i<n;i++){
            int width = nsi[i] - psi[i] -1;
            int height = heights[i];

            ans = max(ans,height * width);
        }
        return ans;
    }
};