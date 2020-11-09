#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

class Trie {
public:
    Trie* next[26] = {nullptr};
    bool isEnd = false;

    Trie() : isEnd(false) {}

    void insert(const std::string& str) {
        Trie* curPos = this;
        int pos = 0;
        for (int i = str.size()-1; i >= 0; --i) {
            pos = str[i]-'a';
            if (curPos->next[pos] == nullptr) {
                curPos->next[pos] = new Trie();
            }
            curPos = curPos->next[pos];
        }
        curPos->isEnd = true;
    }
};

class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        int n = sentence.size(), pos = 0, i = 0, j = 0;
        if (n == 0) {
            return 0;
        }
        if (dictionary.size() == 0) {
            return 1;
        }

        Trie* root = new Trie(), *curPos = nullptr;
        for (auto& word : dictionary) {
            root->insert(word);
        }
        std::vector<int> dp(n+1, 0x7fff);
        dp[0] = 0;

        for (i = 1; i <= n; ++i) {
            dp[i] = dp[i-1] + 1;
            curPos = root;
            for (j = i; j >= 1; --j) {
                pos = sentence[j-1] - 'a';
                if (curPos->next[pos] == nullptr) {
                    break; // 字典树中没有这个单词
                } else if (curPos->next[pos]->isEnd) {
                    dp[i] = std::min(dp[i], dp[j-1]); // 找到一个单词
                }
                if (dp[i] == 0) {
                    break;
                }
                curPos = curPos->next[pos];
            }
        }

        return dp[n];
    }
};
