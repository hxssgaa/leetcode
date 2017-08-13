
//leetle    le  leet
/*
	这个题可以利用dp来优化dfs算法的O(2^n)复杂度
	dp的量可以取s长度的bool数组来表示前n个s子串是否可以用wordDict来组成
 */
bool wordBreak(string s, unordered_set<string>& wordDict) {
	int n = s.size();
	vector<bool> dp(n+1, 0);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i-1; j >= 0; j--) {
			if (dp[j]) {
				string sub = s.substr(j,i-j);
				if (wordDict.find(sub) != wordDict.end()) {
					dp[i] = 1;
					break;
				}
			}
		}
	}
	return dp[n];
}