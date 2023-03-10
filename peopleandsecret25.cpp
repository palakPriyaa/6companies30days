class Solution {
public:
    int mod= 1e9 + 7;
    int solve(int start, int delay, int forget, int n, vector<int> &dp)
    {
        if(delay==forget) return 1;
        if(dp[start] != -1) return dp[start];
        
		// to check current person will forget before n days or not
        int mul = (start+forget) > n;
        int ans = 1*mul;
        for(int day=start+delay; day < min(start+forget, n+1); day++)
            ans = ( ans + solve(day, delay, forget, n, dp) ) % mod;
        
        return dp[start] = ans;
    }
    int peopleAwareOfSecret(int n, int d, int f) {
        vector<int> dp(n+1, -1);
        return solve(1, d, f, n, dp);
    }
};      
