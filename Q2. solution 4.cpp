// frog jump
// tabulation space optimized
// https://www.codingninjas.com/studio/problems/frog-jump_3621012

#include <bits/stdc++.h> 
using namespace std;

/*space optimization*/
int frogJump(int n, vector<int> &arr)
{
    // Write your code here.
    int two = INT_MAX;
    int one = 0;
    int current = 0;

    for(int i=2; i<=n; i++) {
        int oneJump = abs(arr[i-1] - arr[i-2]) + one;
        int twoJump = abs(arr[i-1] - arr[i-3]) + two;

        if(i-2 >= 1) current = min(oneJump, twoJump);
        else current = oneJump;

        two = one;
        one = current;
    }
    return current;
}
