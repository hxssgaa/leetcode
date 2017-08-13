//Distinct Subsequences
/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

*/
//此题非常值得注意，当t为空字符串而s不为空字符的时候，结果是1，因为空字符串同样是s去除一些字符后的结果.
//其实起初规律已经找到了，可由于没有注意这个初始条件导致做题失败，因此dp的初始化条件值得高度注意
//另外注意下vector<vector<int>> dp(M+1, vector<int>(N+1, 0));的用法
//并且要注意M、N与s、t的对应关系，不要行列倒置
//此题可以更高度地优化为1维dp
int numDistinct(string s, string t) {
	int M = t.size(), N = s.size();
	if (M > N) return 0;
	vector<vector<int>> dp(M+1, vector<int>(N+1, 0));
	for (int j = 0; j <= N; j++) {
		dp[0][j] = 1;//initialization
	}
	for (int i = 1; i <= M; i++) {
		for (int j = i; j <= N; j++) {
			dp[i][j] = t[i-1] == s[j-1] ? dp[i][j-1] + dp[i-1][j-1] : dp[i][j-1];
		}
	}
	return dp[M][N];
}

//优化后的numDistinct算法
//这个方法利用了dp的迭代特性，并且dp倒着算以取消dp[i-1]在i>0的时候的对dp[i]的影响
//这个题必须从numDistinct算法中推导到numDistinct2的，可以看得出其中有叠加特性
int numDistinct2(string s, string t) {
    int M = (int)t.size();
    vector<int> dp(M,0);
    for (auto c: s)
        for (int i = M-1;i >= 0;--i)
            if (t[i] == c)
                dp[i] = (i > 0 ? dp[i-1] : 1) + dp[i];
    return dp.back();
}