//Word Ladder II
/*
	此题用到了及其难用的双端bfs算法，真的非常难，超出范围了

    本题只能使用双端bfs，因为如果使用普通bfs的话
    构建的map的宽度会非常宽，非常容易超时，而双端队列就解决了构建的map宽度过宽的问题

    所谓的双端bfs算法，核心数据结构就是用两个unordered_set来完成
    这两个set分别存放着当前level下的所有节点，每一次递归的时候轮询递进这两个set
    可以采用一个word1IsBegin的bool辅助变量来在递归的时候实现这个功能
    每一次递归，word1IsBegin都取反
    另外由于两端遍历是对称的，因此优先遍历长度较短的set，这样就可以减少遍历的宽度
 */

bool findLaddersHelper(unordered_set<std::string> &words1,
                       unordered_set<std::string> &words2,
                       unordered_set<std::string> &dict,
                       unordered_map<std::string,
                       vector<std::string> > &nexts,
                       bool &words1IsBegin) {
    words1IsBegin = !words1IsBegin;
    if (words1.empty())
        return false;
    if (words1.size() > words2.size())
        return findLaddersHelper(words2, words1, dict, nexts, words1IsBegin);
    for (auto it = words1.begin(); it != words1.end(); ++it)
        dict.erase(*it);
    for (auto it = words2.begin(); it != words2.end(); ++it)
        dict.erase(*it);
    unordered_set<std::string> words3;
    bool reach = false;
    for (auto it = words1.begin(); it != words1.end(); ++it) {
        string word = *it;
        for (int i = 0; i < word.size(); i++) {
            char tmp = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
                if (ch != tmp) {
                    word[i] = ch;
                    if (words2.find(word) != words2.end()) {
                        reach = true;
                        words1IsBegin ? nexts[*it].push_back(word) : nexts[word].push_back(*it);
                    }
                    else if (!reach && dict.find(word) != dict.end()) {
                        words3.insert(word);
                        words1IsBegin ? nexts[*it].push_back(word) : nexts[word].push_back(*it);
                    }
                }
        }
    }
    return reach || findLaddersHelper(words2, words3, dict, nexts, words1IsBegin);
}
void getPath(string beginWord,
             string &endWord,
             unordered_map<string, vector<string> > &nexts,
             vector<string> &path,
             vector<vector<string> > &paths) {
    if (beginWord == endWord)
        paths.push_back(path);
    else
        for (auto it = nexts[beginWord].begin(); it != nexts[beginWord].end(); ++it) {
            path.push_back(*it);
            getPath(*it, endWord, nexts, path, paths);
            path.pop_back();
        }
}

vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
    vector<vector<string>>res;
    vector<string> ladder(1, beginWord);
    if (beginWord == endWord) {
        res.push_back(ladder);
        return res;
    }
    unordered_set<string> words1, words2;
    words1.insert(beginWord);
    words2.insert(endWord);
    unordered_map<string, vector<string> > nexts;
    bool words1IsBegin = false;
    if (findLaddersHelper(words1, words2, wordList, nexts, words1IsBegin))
        getPath(beginWord, endWord, nexts, ladder, res);
    return res;
}
