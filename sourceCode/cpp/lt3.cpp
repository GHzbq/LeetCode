#include <string>
#include <unordered_set>
#include <unordered_map>
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

#if 0

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

#if 0

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = static_cast<int>(s.size());
        if (size <= 0) {
            return 0;
        }
        std::unordered_map<char, int> unorderedMap;
        int maxLen = 0;
        auto it = unorderedMap.begin();
        for (int j = 0, i = 0; j < size; ++j) {
            it = unorderedMap.find(s[j]);
            if (it != unorderedMap.end()) {
                i = std::max(unorderedMap[s[j]], i);
            }
            maxLen = std::max(maxLen, j-i+1);
            unorderedMap.insert(std::make_pair(s[j], j+1));
        }

        return maxLen;
    }
};

#endif

#if 1

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        //s[start,end) 前面包含 后面不包含
        int start(0), end(0), length(0), result(0);
        int sSize = int(s.size());
        std::unordered_map<char, int> hash;
        while (end < sSize)
        {
            char tmpChar = s[end];
            //仅当s[start,end) 中存在s[end]时更新start
            if (hash.find(tmpChar) != hash.end() && hash[tmpChar] >= start)
            {
                start = hash[tmpChar] + 1;
                length = end - start;
            }
            hash[tmpChar] = end;

            end++;
            length++;
            result = std::max(result, length);
        }
        return result;
    }
};

#endif
