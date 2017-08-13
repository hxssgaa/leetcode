//Palindrome Partitioning

bool isPalindrome(string &s) {
	if (s.size() == 0) return false;
	for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
		if (s[i] != s[j]) return false;
	}
	return true;
}

void partition(string s, vector<string> &cur, vector<vector<string>> &res) {
	if (s == "") return;
	if (s.size() == 1) {
		cur.push_back(s);
		res.push_back(cur);
		return;
	}
	for (int i = 0; i < s.size(); i++) {
		string subStr = s.substr(0,i+1);
		if (isPalindrome(subStr)) {
			cur.push_back(subStr);
			partition(subStr, cur, res);
			cur.pop_back();
		}
	}
}

vector<vector<string>> partition(string s) {
	vector<vector<string>> res;
	vector<string> cur;
	partition(s, cur, res);
	return res;
}