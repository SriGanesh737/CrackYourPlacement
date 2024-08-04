class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    int m,n;
    
    bool isPossible(int i, int c, bool graph[101][101], vector<int>&color){

        for(int j = 0;j<n;j++){
            if(graph[i][j] && color[j] == c) return false;
        }
        
        return true;
    }
    
    bool solve(int i,bool graph[101][101], vector<int>&color){
        if(i == n) return true;
        
        bool flag = false;
        // try to color present node
        for(int k = 0; k<m; k++){
            if(isPossible(i,k,graph,color)) {
                color[i] = k;
                flag = flag || solve(i+1,graph,color);
                color[i] = -1;
            }
        }
        
        return flag;
    }
    
    bool graphColoring(bool graph[101][101], int M, int N) {
        // your code here
        m = M;
        n = N;
        
        vector<int>color(n,-1);
        
        return solve(0,graph,color);
    }   
};