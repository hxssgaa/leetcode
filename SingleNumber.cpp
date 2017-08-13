//Single Number
/*
	这个题用到了异或表达式来trick，实际上我觉得没有必要，知道hash可以解决就行了
 */
int singleNumber(vector<int>& nums) {
    unordered_map<int,int> m;
    for (int i = 0; i<nums.size(); i++)
    {
        m[nums[i]]++;
    }
    for (auto it = m.begin(); it != m.end(); ++it) {
    	if (it->second == 1) {
    		return it->first;
    	}
    }
    return 0;
}