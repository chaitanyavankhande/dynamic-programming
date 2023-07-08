// house robber 2
// https://www.codingninjas.com/studio/problems/house-robber_839733

#include <bits/stdc++.h> 
//solution 1: tabulation space optimization
long long solve(int start, int end, vector<int>&valueInHouse) {

    long long first=0, second = valueInHouse[start], current=valueInHouse[start];

    for(int i=start+1; i<=end; i++) {
        long long pick = valueInHouse[i];
        if(i-2 >= start) pick += first;
        long long notPick = second;
        current = max(pick, notPick);

        first = second;
        second = current;
    }
    return current;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];

    return 
    max(
        solve(1, n-1, valueInHouse), 
        solve(0, n-2, valueInHouse)
    );
}


/*solution 2: tabulation
long long solve(int start, int end, vector<int>&valueInHouse) {

    int n = valueInHouse.size();
    vector<long long> tb(n, -1);
    tb[start] = valueInHouse[start];

    for(int i=start+1; i<=end; i++) {
        long long pick = valueInHouse[i];
        if(i-2 >= start) pick += tb[i-2];
        long long notPick = tb[i-1];
        tb[i] = max(pick, notPick);
    }
    return tb[end];
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];

    return 
    max(
        solve(1, n-1, valueInHouse), 
        solve(0, n-2, valueInHouse)
    );
}
*/

/*solution 3: memoization
long long solve(int start, int current, vector<int>&valueInHouse, vector<long long> &dp) {
    
    if(current < start) return 0;
    if(current == start) return valueInHouse[start];
    if(dp[current] != -1) return dp[current];
    long long pick = valueInHouse[current] + solve(start, current-2, valueInHouse, dp);
    long long notPick = solve(start, current-1, valueInHouse, dp);
    return dp[current] = max(pick, notPick);
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];

    vector<long long>dp1(n, -1), dp2(n, -1);
    return max(solve(1, n-1, valueInHouse, dp1), 
                solve(0, n-2, valueInHouse, dp2)
            );
    
}
*/


/*solution 4: recursion
long long solve(int start, int current, vector<int>&valueInHouse) {
    
    if(current < start) return 0;
    if(current == start) return valueInHouse[start];
    
    long long pick = valueInHouse[current] + solve(start, current-2, valueInHouse);
    long long notPick = solve(start, current-1, valueInHouse);
    return max(pick, notPick);
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];
    return max(solve(1, n-1, valueInHouse), solve(0, n-2, valueInHouse));
    
}
*/
