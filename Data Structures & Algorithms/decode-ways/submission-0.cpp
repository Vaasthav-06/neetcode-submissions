class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n,-1);
        int ans = dfs(0,dp,s);
        return ans;
    }
private:
    int dfs(int ind,vector<int>&dp,string s){
        if(ind == s.size()) return 1;
        if(s[ind] == '0') return 0;
        if(dp[ind] != -1) return dp[ind];

        int res = dfs(ind+1,dp,s);

        if(ind + 1 < s.size() && (s[ind] == '1' || s[ind] == '2' && s[ind+1] < '7')){
            res += dfs(ind+2,dp,s);
        }

        return dp[ind] = res;
    }
};
