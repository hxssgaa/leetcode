
bool isValidStr(string &s) {
	int num = atoi(s.c_str());
	return (num >= 0 && num <= 255);
}

//"010010"
void restoreIpAddresses(string s, vector<string> &vec, vector<string> &v) {
	if (s == "") return;
	if (v.size() >= 4) return;
	if (s.size() <= 3 && isValidStr(s) && (s[0]!='0' || s == "0") && v.size() == 3) {
		v.push_back(s);
		string resStr = "";
		for (int i = 0; i < v.size(); i++) {
			resStr += v[i];
			if (i != v.size() - 1) resStr += ".";
		}
		vec.push_back(resStr);
		v.pop_back();
		return;
	}
	for (int i = 0; i < 3 && i < s.size(); i++) {
		string digit = s.substr(0, i+1);
		if (isValidStr(digit)) {
			v.push_back(digit);
			restoreIpAddresses(s.substr(i+1,s.size()-i-1), vec, v);
			v.pop_back();
		}
		if (atoi(digit.c_str())==0) break;
 	}

}

vector<string> restoreIpAddresses(string s) {
	vector<string> res, temp;
	restoreIpAddresses(s, res, temp);
	return res;
}