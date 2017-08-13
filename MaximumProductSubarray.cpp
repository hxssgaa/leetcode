/*

	这个题自己去想可能永远都想不到那么简单的办法，甚至会出现O(N)的空间复杂度，实际上这是一个典型问题
	这个题需要打4星去记住※※※※
	实际上可以发现本题会被一个负数将整个序列分为两半，因此我们要做的就是比较这两个序列乘积哪个大
	注意到，这两个序列同时还会被0给影响，当为0的时候，就将当前序列乘积设置为1即可
	实际上res就是max(res与max(front,back))的最大值

	注意，凡是遇到什么连续序列的最大值最小值这种问题，可以想到用辅助变量res或者前后序列的乘积比较
	的方式来进行，实际上也是迭代dp的过程，一定要想到辅助变量max()这种方式来迭代.
 */
int maxProduct(vector<int>& A) {
	int res = INT_MIN;
	int front = 1;
	int back = 1;
	for (int i = 0; i < A.size(); i++) {
		front *= A[i];
		back *= A[A.size()-1-i];
		res = max(res, max(front, back));
		if (front == 0) front = 1;
		if (back == 0) back = 1;
	}
    return res;
}