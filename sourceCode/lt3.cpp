#include <string>
#include <unordered_set>
using std::string;

#if 0

// 解法一：暴利枚举
// 暴力枚举导致时间超限
// 923 / 987 个通过测试用例
// "aniewqmoxkjwpymqorluxedvywhcoghotpusfgiestckrpaigocfufbubiyrrffmwaeeimidfnnzcphkflpbqsvtdwludsg"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> temp;
        int size = static_cast<int>(s.size());
        if (size <= 0) {
            return 0;
        }
        int maxLen = 0;
        int sub = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = i+1; j <= size; ++j) {
                if (allUnique(s, i, j, temp)) {
                    sub = j - i;
                    if (sub > maxLen) {
                        maxLen = sub;
                    }
                }
            }
        }

        return maxLen;
    }

private:
    bool allUnique(const std::string& s, int start, int end, std::unordered_set<char>& unorderedSet) {
        unorderedSet.clear();
        auto it = unorderedSet.begin();
        for (int i = start; i < end; ++i) {
            it = unorderedSet.find(s[i]);
            if (it != unorderedSet.end()) {
                return false;
            } else {
                unorderedSet.insert(s[i]);
            }
        }

        return true;
    }
};

#endif

#if 1

// 解法二：滑动窗口

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = static_cast<int>(s.size());
        if (size <= 0) {
            return 0;
        }
        bool hashTable[128] = { false };
        int maxLen = 0;
        int start = 0;
        int i = 0;
        int temp = 0;
        int sub = 0;
        while (start < size && i < size) {
            temp = s[start];
            if (hashTable[temp] == false) {
                hashTable[temp] = true;
                ++start;
                sub = start - i;
                if (maxLen < sub) {
                    maxLen = sub;
                }
            } else {
                temp = s[i];
                hashTable[temp] = false;
                ++i;
            }
        }
        return maxLen;
    }
};

#endif
