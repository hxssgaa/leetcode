vector<vector<int>> generate(int numRows) {
	vector<vector<int>> res;
	vector<int> v;
	for (int j = 0; j < numRows; j++) {
		v.clear();
		for (int i = 0; i <= j; i++) {
			if (i == 0 || i == j) v.push_back(1);
			else v.push_back(res.back()[i-1]+res.back()[i]);
		}
		res.push_back(v);
	}
	return res;
}