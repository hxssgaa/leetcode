void reverseWords(string &s) {
	if (s == " ") s = "";
	reverse(s.begin(), s.end());
	int before = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			reverse(s.begin() + before, s.begin() + i);
			before = i+1;
		}
	}
	reverse(s.begin() + before, s.end());
}