class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        
        int n = points.size();
        int sp_cnt = 0;
        vector<double>angles;
        int x1 = location[0], y1 = location[1];
        for(auto point: points){
            int y2 = point[1];
            int x2 = point[0];
            if(x1==x2 && y1==y2){
                sp_cnt++;
                continue;
            }
            if(x1==x2) angles.push_back(y2<y1?270:90);
            else angles.push_back(atan2(y2-y1,x2-x1)*180/M_PI);
        }


        int sz = angles.size();
        for(int i =0;i<sz;i++) {
            if(angles[i]<0) angles[i]+=360;
            angles.push_back(angles[i]+360);
        }
        sort(angles.begin(),angles.end());
        // modify n to angles size.
        n = angles.size();
        int i =0, j=0;
        int ans = 0;
        while(j<n){
            while(i<j && angles[j]-angles[i]>angle) i++;
            ans = max(ans,j-i+1);
            j++;
        }

        return ans+sp_cnt;
    }
};