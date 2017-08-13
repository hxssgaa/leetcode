//Longest Consecutive Sequence

//这种方法采用unordered_set来解决，只要存放数字的unordered_set，其find方法可以认为就是O(1)
int longestConsecutive(vector<int>& nums) {
	int longest = 0;
    unordered_set<int> numSet;
    unordered_set<int> visited;
    for (auto it = nums.begin(); it != nums.end(); ++it) {
    	numSet.insert(*it);
    }
    for (auto it = nums.begin(); it != nums.end(); ++it) {
    	if (visited.find(*it) != visited.end()) continue;
    	int cur = 1;
    	int num = *it - 1;
    	visited.insert(*it);
    	while (numSet.find(num) != numSet.end()) {
    		num--;
    		cur++;
    		visited.insert(num);
    	}
    	num = *it + 1;
    	while (numSet.find(num) != numSet.end()) {
    		num++;
    		cur++;
    		visited.insert(num);
    	}
    	if (cur > longest) longest = cur;
    }
    return longest;
}

//这种方法利用unordered_map来解决，该方法存放的map表示边界数字对应的长度
//比如 [1,2,3]的2,1,3的映射value都是长度3，该map可以通过在遍历的时候获取m[n-1]与m[n+1]的值
//假如找不到的话边界值就为0，left+right再加1就是该遍历数字n对应的长度
int longestConsecutive2(vector<int>& nums) {
	int res = 0;
    unordered_map<int, int> m;
    for (int n : nums) {
        if (m.find(n) == m.end()) {
            int left = m.find(n-1) != m.end() ? m[n-1] : 0;
            int right = m.find(n+1) != m.end() ? m[n+1] : 0;
            // sum: length of the sequence n is in
            int sum = left + right + 1;
            m[n] = sum;

            // keep track of the max length 
            res = max(res, sum);

            // extend the length to the boundary(s)
            // of the sequence
            // will do nothing if n has no neighbors
            m[n - left] = sum;
            m[n + right] = sum;
        }
        else {
            // duplicates
            continue;
        }
    }
    return res;
}