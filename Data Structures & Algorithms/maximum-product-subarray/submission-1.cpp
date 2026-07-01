class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1e18));
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(j-i+1 <= 1){
                    dp[i][j] = nums[i];
                }else{
                    dp[i][j] = dp[i+1][j] * nums[i];
                }
            }
        }

        int ans = -1e9;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans,dp[i][j]);
            }
        }

        return ans;
    }
};
