//Word Ladder
/*
	此题非常经典，值得注意
	优化点：我们可以不必每次都遍历所有的wordList来求出与某个词相差一个字母的序列
	反而，可以遍历这个词的所有相差一个字母的序列，反而求出在wordList里面的序列，
	这样会高效很多
	该题同时教会了我们如何使用unordered_set以及unordered_map等数据结构，实际上
	与map和set的用法是一模一样的
	另外对于iterator的写法，可以采用auto的方式来简化一大堆iterator的声明代码

	该题我直接采用了BFS来解决，比起双端BFS速度稍慢，但容易一些.只要知道双端BFS可以优化这个问题即可

 */
void differOneLetter(string s, unordered_set<string> &res, unordered_set<string> &wordList) {
    res.clear();
    for (int i = 0; i < s.size(); i++) {
        string newStr = s;
        for (int j = 'a'; j <= 'z'; j++) {
            if (j == s[i]) continue;
            newStr[i] = j;
            if (wordList.find(newStr) != wordList.end())
                res.insert(newStr);
        }
    }
}

bool diffOneLetter(string s1, string s2) {
    int cnt = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (cnt > 1) return false;
        if (s1[i] != s2[i]) cnt++;
    }
    return cnt == 1;
}

//此题可以用双端bfs进行进一步地优化
int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    queue<string> q;
    q.push(beginWord);
    int level = 0;
    unordered_set<string> usedWords;
    while (!q.empty()) {
        int n = (int)q.size();
        for (int i = 0; i < n; i++) {
            string top = q.front();
            if (diffOneLetter(top, endWord))
                return level + 2;
            q.pop();
            unordered_set<string> res;
            differOneLetter(top, res, wordList);
            for (auto it = res.begin(); it != res.end(); ++it) {
                if (usedWords.find(*it) != usedWords.end()) continue;
                q.push(*it);
                usedWords.insert(*it);
            }
        }
        level++;
    }
    return 0;
}