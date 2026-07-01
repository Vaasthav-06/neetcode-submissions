class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string>mp;
        for(auto it: wordDict){
            mp.insert(it);
        }

        vector<int>dp(s.size(),-1);
        bool res = dfs(0,s,mp,dp);
        return res;
    }
private:
    bool dfs(int ind,string &s,unordered_set<string>&mp,vector<int>&dp){
        if(ind >= s.size()) return true;

        if(dp[ind] != -1) return dp[ind];

        for(int i = ind; i<s.size(); i++){
            string curr = s.substr(ind,(i-ind+1));
            
            if(mp.find(curr) != mp.end()){
                if(dfs(i+1,s,mp,dp) == true){
                    return dp[ind] = true;
                }
            }
        }

        return dp[ind] = false;
    }
};
