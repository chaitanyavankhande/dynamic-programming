
// https://leetcode.com/problems/minimum-falling-path-sum/
// difficulty level: medium
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int>current(m,0), previous(m,0);

        for(int j=0; j<m; j++) previous[j] = current[j] = matrix[0][j];
        // if we dont consider current[j] in above statement, test cases having 1 row fail
        //eg: t=1, n=1, matrix[1][1] = {{-1000}}; o/p: 0 which should be -1000
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<m; j++) {
                int up = INT_MAX, upLeft = INT_MAX, upRight = INT_MAX;
                up = previous[j];
                if(j-1 >= 0) upLeft = previous[j-1];
                if(j+1 < m) upRight = previous[j+1];
                current[j] = matrix[i][j] + min(up, min(upLeft, upRight));
            }
            previous = current;
        }
        
        int minSum = INT_MAX;
        for(int j=0; j<m; j++) {
            int sum = current[j];
            minSum = min(minSum, sum);
        }
        return minSum;
    }
