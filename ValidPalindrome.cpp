//Valid Palindrome

/*
	注意：
	这个题用到了C++的辅助函数
	tolower(char) 转化为小写字母
	toupper(char) 转化为大写字母
 */
string filterStr(string s) {
    string res = "";
    for (char ch : s) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            if (ch >= 'A' && ch <= 'Z') ch = tolower(ch);
            res += ch;
        }
    }
    return res;
}
bool isPalindrome(string s) {
    s = filterStr(s);
    if (s == "") return true;
    for (int i = 0, j = s.size() - 1; i<j; i++, j--) {
        if (s[i] != s[j]) return false;
    }
    return true;
}