//Palindrome Partitioning II
/*
	此题要打5星，引起高度注意*****

	该题是回文问题的dp解法，一般回文问题就要想到用基数偶数的方式遍历解决
	该问题进一步使用了dp算法来解决该问题
	dp即存放了s的前k个数的最小cut数

	这个题非常的巧妙，我们以 adabba为例，看下dp如何求出
		a b a b b a
	dp首先初始化为i-1，因为这是初始化最简单的cut法，即：
	 -1 0 1 2 3 4 5
	然后遍历整个序列，分为以i为中心的奇数和偶数的情况，分别求出dp[i+j+1]
	其实很简单，此时的dp[i+j+1]就是该子回文串左边的元素所需要的cut数+1与dp[i+j+1]的最小值
	因此，就有：
	 -1 0 1 0 3 4 5
	 -1 0 1 0 1 4 5
	 -1 0 1 0 1 1 5
	 -1 0 1 0 1 1 2

	 一般求解序列通常都是dfs或者bfs，然而求解值都可以用dp进一步优化解决
 */
int minCut(string s) {
    int n = (int)s.size();
    vector<int> dp(n+1, 0);
    for (int i = 0; i <= n; i++) dp[i] = i-1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; i-j >= 0 && i+j < n && (s[i+j] == s[i-j]); j++)//首先更新奇数，更新奇数的同时也更新了第i个数的dp
            dp[i+j+1] = min(dp[i+j+1], 1+dp[i-j]);
        for (int j = 1; i-j+1 >= 0 && i+j < n && (s[i+j] == s[i-j+1]); j++)
            dp[i+j+1] = min(dp[i+j+1], 1+dp[i-j+1]);
    }
    return dp.back();
}