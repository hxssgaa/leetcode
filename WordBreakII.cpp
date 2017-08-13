/*
    这个题我觉得能想到这一步已经非常OK了，但是没有AC，因为worst case还是回到O(N^3)
 */
vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    int n = s.size();
    vector<vector<string> > dp(n+1, vector<string>());
    dp[0].push_back("");
    for (int i = 1; i <= n; i++) {
        for (int j = i-1; j >= 0; j--) {
            if (dp[j].size() > 0) {
                string sub = s.substr(j,i-j);
                if (wordDict.find(sub) != wordDict.end()) {
                    for (auto e : dp[j]) {
                        dp[i].push_back(e + " " + sub);
                    }
                }
            }
        }
    }
    for (auto &e : dp[n]) {
        e = e.substr(1, e.size()-1);
    }
    return dp[n];
}
