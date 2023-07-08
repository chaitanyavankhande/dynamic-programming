// frog jump
// tabulation
// https://www.codingninjas.com/studio/problems/frog-jump_3621012

int frogJump(int n, vector<int> &arr)
{
    // Write your code here.
    vector<int>tb(n+1, -1);
    tb[0] = INT_MAX;
    tb[1] = 0;

    for(int i=2; i<=n; i++) {
        int oneJump = abs(arr[i-1] - arr[i-2]) + tb[i-1];
        int twoJump = abs(arr[i-1] - arr[i-3]) + tb[i-2];

        if(i-2 >= 1) tb[i] = min(oneJump, twoJump);
        else tb[i] = oneJump;
    }
    return tb[n];
}
