class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (!st.count(endWord)) return 0;

        unordered_set<string> beginSet, endSet;
        beginSet.insert(beginWord);
        endSet.insert(endWord);

        int level = 1;
        int len = beginWord.length();

        while (!beginSet.empty() && !endSet.empty()) {
            // Always expand smaller set
            if (beginSet.size() > endSet.size())
                swap(beginSet, endSet);

            unordered_set<string> nextSet;

            for (string word : beginSet) {
                for (int i = 0; i < len; i++) {
                    char original = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == original) continue;
                        word[i] = ch;

                        if (endSet.count(word))
                            return level + 1;

                        if (st.count(word)) {
                            nextSet.insert(word);
                            st.erase(word);
                        }
                    }
                    word[i] = original;
                }
            }

            beginSet = nextSet;
            level++;
        }

        return 0;
    }
};
