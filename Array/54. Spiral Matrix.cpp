class Solution {
public:

    pair<int,int> next(int i, int j, int dir){

        
        if(dir == 0) return {i-1,j};
        
        if(dir == 1) return {i,j+1};

        if(dir == 2) return {i+1,j};

        if(dir == 3) return {i,j-1};

        return {-1,-1};
    }

    bool isValid(int i, int j, int m,int n, vector<vector<int>>&matrix){
        if(i<0||j<0||i>=m||j>=n) return false;

        if(matrix[i][j] == 777) return false;
        return true; 
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dir = 1;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int>ans;

        int i = 0, j = -1, cnt = m*n;

        while(cnt){
            auto v = next(i,j,dir);
            int x = v.first, y = v.second;
            if(isValid(x,y,m,n,matrix)){
                cnt--;
                i = x;
                j = y;
                ans.push_back(matrix[i][j]);
                matrix[i][j] = 777;
            }
            else{
                dir = (dir+1)%4;
            }
        }

        return ans;
    }
};