//Best Time to Buy and Sell Stock
/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */
//这个题考察的是数组最大差值的子区间，比如6,1,3,2,4,7的最大差值子区间是6
//题目规定交易次数只有1次，千万不要想成可以有多次交易
int maxProfit(vector<int>& prices) {
	int mp = 0;
	int before = 0;
	int i = 0, j = 0;
	while (i < prices.size()) {
		before = prices[i];
		j = i + 1;
		int maxP = 0;
		while (j < prices.size() && prices[j] >= before) {
			maxP = max(prices[j] - before, maxP);
			j++;
		}
		mp = max(maxP, mp);
		i = j;
	}
	return mp;
}

//这个版本是允许多次交易的
int maxProfit2(vector<int>& prices) {
	int mp = 0;
	int before = 0;
	int i = 0, j = 0;
	while (i < prices.size()) {
		before = prices[i];
		j = i + 1;
		while (j < prices.size() && prices[j] >= prices[j-1]) j++;
		if (j > i+1) {
			mp += (prices[j-1] - before);
		}
		i = j;
	}
	return mp;
}

//这个版本是只允许最多2次交易的
/*
	这种解法可能非常难以理解
	但实际上则可以用非常简单的思想来解决:
	对于每一天的股票有8种选择，要么买/卖第一支股票或者买/卖第二支股票，或者直接忽略这两只股票的买/卖
	因此只要我们计算出买/卖第一支股票或者买/卖第二支股票的获得的最大收益即可，我们有如下公式：
	buy1 = max(buy1, -prices[i]);
    sell1 = max(sell1, buy1 + prices[i]);
    buy2 = max(buy2, sell1 - prices[i]);
    sell2 = max(sell2, buy2 + prices[i]);
    实际上对于第二支股票而言，我们假设其为卖掉第一支股票再买第二支股票所获得的收益，因此最终的最大收益
    就是sell2

    这个题实际上就是dp线性优化的概念，实际上buy1、sell1就是当天买/卖第一支股票最优收益，
    而buy2、sell2就是在有可能卖了第二支股票下买/卖第二支股票的最优收益.
 */
int maxProfit3(vector<int> &prices) {
    int n = (int)prices.size();
    if (n < 2) return 0;
    int sell1 = 0, sell2 = 0, buy1 = INT_MIN, buy2 = INT_MIN;
    for(int i = 0; i < n; i++) {
        buy1 = max(buy1, -prices[i]);
        sell1 = max(sell1, buy1 + prices[i]);
        buy2 = max(buy2, sell1 - prices[i]);
        sell2 = max(sell2, buy2 + prices[i]);
    }
    return sell2;
}