class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>pq;
        int n = points.size();

        pq.push({points[0][1] - points[0][0],points[0][0]});

        int ans = INT_MIN;

        for(int i =1;i<n;i++){
            while(!pq.empty()){
                auto tp = pq.top();
                if(points[i][0] - tp.second > k) pq.pop();
                else{
                    ans = max(ans, tp.first + points[i][0] + points[i][1]);
                    break;
                }
            }
            pq.push({points[i][1] - points[i][0], points[i][0]});
        }

        return ans;
    }
};