//此题由于只能在邻接节点中移动，可能很容易想到用dfs
//但实际上是没有必要的，我们看下一下例子
/*
		0		(k = 0)
	   / \   
	  0   1     (k = 1)
	 / \ / \
	0   1   2   (k = 2)
   / \ / \ / \ 
  0   1   2   3 (k = 3)
实际上我们先可以计算三角的第k排的累积sum值
那么如何选取第k排第i个元素的sum值呢？
分为两种情况：i == 0 或者 i == k，此时该sum值即为上一排的第一个元素或者最后一个元素的值
否则的话，我们可以选取第i-1个元素与第i个元素的最小值即可

C++小技巧：利用*min_element(vec.begin(), vec.end())可以快速计算最小值或者最大值
 */
int minimumTotal(vector<vector<int>>& triangle) {
	if (triangle.size() == 0) return 0;
	for (int i = 1; i < triangle.size(); i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				triangle[i][j] += triangle[i-1][j == 0 ? 0 : j-1];
			} else {
				triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
			}
		}
	}
	int cur = triangle.size() - 1;
	return *min_element(triangle[cur].begin(), triangle[cur].end());      
}