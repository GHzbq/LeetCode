#include <vector>
#include <string>
#include <algorithm>

use std::vector;
use std::string;

#if 0
// 解法一：暴力枚举
// 1. 生成所有括号序列；
// 2. 判断括号序列是否合法；
// 3. 统计合法括号序列；
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> ret;
        // 参数检查
        if (n <= 0) {
            return ret;
        }
        std::string s;
        s.resize(2*n);
        for (int i = 0; i < 2*n; i += 2) {
            s[i] = '(';
            s[i+1] = ')';
        }
        // 这里sort的原因是让输出的结果和标准答案一样
        // 不知道判题会不会有顺序不同而导致结果不同，所以这里排序了一下
        std::sort(s.begin(), s.end());
        // 这里借助算法库里的std::next_permutation来生成下一个序列
        do {
            // 判断是否合法
            if (isValid(s)) {
                ret.push_back(s);
            }
        } while(std::next_permutation(s.begin(), s.end()));
        return ret;
    }
private:
    bool isValid(const std::string& s) {
        // ()()()
        // 发现用这种方法来判断括号匹配要比用栈来判断括号匹配简单
        int balance = 0;
        for (auto c : s) {
            if (c == '(') {
                ++balance;
            } else {
                --balance;
            }
            if (balance < 0) {
                return false;
            }
        }
        return (balance == 0);
    }
};
#endif

#if 1
#endif 
