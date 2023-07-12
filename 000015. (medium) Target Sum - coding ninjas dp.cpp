




// https://leetcode.com/problems/target-sum/


//solution 4: recursion
class Solution {

int solve(int n, vector<int>&nums, int currentSum, int allSum, int target) {
    
    if(n == 0) {
        if( (allSum - currentSum) - currentSum == target ) return 1; //nums=2,3,5; target=0;
        return 0;
    }
    int pick = solve(n-1, nums, currentSum + nums[n-1], allSum, target);
    int notPick = solve(n-1, nums, currentSum, allSum, target);
    return pick + notPick;
}

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int allElementsSum = 0;
        for(int i=0; i<n; i++) allElementsSum += nums[i];
        return solve(n, nums, 0, allElementsSum, target);
    }
};

/*********************************************************************************************************************************/

// memoization solution:
class Solution {
    int solve(int n, vector<int>&nums, int target, vector<unordered_map<int,int>> &dp) {
        
        if(n == 0) {
            return target==0;
            // if(target == 0) return 1;
            // else return 0;
        }

        if(dp[n-1].find(target) != dp[n-1].end()) return dp[n-1][target];

        int count = 0;  
        int plus = solve(n-1, nums, target - nums[n-1], dp);
        count += plus;
        int minus = solve(n-1, nums, target + nums[n-1], dp);
        count += minus;
        return dp[n-1][target] = count;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n);
        return solve(n, nums, target, dp);
    }
};

//recursion solution:
class Solution {
    int solve(int n, vector<int>&nums, int target) {
        
        if(n == 0) {
            return target==0;
            // if(target == 0) return 1;
            // else return 0;
        }
        int count = 0;  
        int plus = solve(n-1, nums, target - nums[n-1]);
        count += plus;
        int minus = solve(n-1, nums, target + nums[n-1]);
        count += minus;
        return count;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(n, nums, target);
    }
};
