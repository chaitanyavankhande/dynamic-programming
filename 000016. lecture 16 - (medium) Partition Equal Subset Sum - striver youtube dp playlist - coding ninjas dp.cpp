

/* solution 4: recursion */
bool solve(vector<int>&arr, int n, int target) {
	if(target == 0) return true;
	if(n == 0) return false;
	
	bool pick = false;
	if(target >= arr[n-1]) pick = solve(arr, n-1, target - arr[n-1]);
	if(pick) return true;
	
	bool notPick = solve(arr, n-1, target);
	return notPick;
}

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	int allSum = 0;
	for(int i=0; i<n; i++) allSum += arr[i];
	if(allSum % 2 == 1) return false;
	return solve(arr, n, allSum / 2);
}
