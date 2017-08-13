vector<int> getRow(int rowIndex) {
	vector<int> v(rowIndex+1, 0);
	for (int j = 0; j < rowIndex+1; j++) {
		int pre = 1;
		for (int i = 0; i <= j; i++) {
			if (i == 0 || i == j) v[i] = 1;
			else {
				v[i] += pre;
				pre = v[i]-pre;
			}
		}
	}
	return v;
}