
// https://leetcode.com/problems/unique-paths-iii/description/
class Solution {

    int solve(int i, int j, vector<vector<int>>&mat, vector<vector<bool>>&visited, int &emptySquares) {
        int n = mat.size(), m = mat[0].size();
        if(i<0 || i==n || j<0 || j==m) return 0;
        if(mat[i][j] == 2) {
            if(emptySquares == 0) return 1;
            else return 0;
        }

        if(mat[i][j] == -1) return 0; //obstacle
        if(visited[i][j]) return 0;

        visited[i][j] = true;
        emptySquares -= 1;
        int paths = solve(i-1, j, mat, visited, emptySquares) + 
                    solve(i, j+1, mat, visited, emptySquares) + 
                    solve(i+1, j, mat, visited, emptySquares) + 
                    solve(i, j-1, mat, visited, emptySquares);


        visited[i][j] = false;
        emptySquares += 1;
        return paths;

    }

public:
    int uniquePathsIII(vector<vector<int>>& mat) {
        int startI = -1, startJ = -1;
        int n = mat.size(), m = mat[0].size();
        int emptySquares = 1; //because we reduce emptySquares by 1 even when it is on the start square
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 1) {
                    startI = i;
                    startJ = j;
                }
                else if(mat[i][j] == 0) {
                    emptySquares++;
                }
            }
        }
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        return solve(startI, startJ, mat, visited, emptySquares);

    }
};
