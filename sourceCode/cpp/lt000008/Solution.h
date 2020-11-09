//
// Created by zhangbaqing on 2020/11/9.
//
// https://leetcode-cn.com/problems/string-to-integer-atoi/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    int myAtoi(std::string str) {
        int size = str.size();

        // 去除前导空格
        int index = 0;
        while (index < size) {
            if (str[index] != ' ') {
                break;
            }
            ++index;
        }

        if (index == size) {
            return 0;
        }

        int sign = 1;
        // 处理第 1 个非空字符为正负符号，这两个判断需要写在一起
        if (str[index] == '+') {
            ++index;
        } else if (str[index] == '-') {
            sign = -1;
            ++index;
        }

        // 根据题目限制，只能使用 int 类型
        int res = 0;
        while (index < size) {
            char curChar = str[index];
            if (curChar < '0' || curChar > '9') {
                break;
            }

            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && (curChar - '0') > INT_MAX % 10)) {
                return INT_MAX;
            }
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && (curChar - '0') > -(INT_MIN % 10))) {
                return INT_MIN;
            }

            res = res * 10 + sign * (curChar - '0');
            ++index;
        }
        return res;
    }
};


#if 0
enum State {
    START, SIGNED, IN, END
};

/**
 * FSM(Finite State Machine, 有限状态机)
 */
class FSM {
private:
    State state = START;
    std::unordered_map<State, std::vector<State>> table = {
            {START,  {START, SIGNED, IN,  END}},
            {SIGNED, {END,   END,    IN,  END}},
            {IN,     {END,   END,    IN,  END}},
            {END,    {END,   END,    END, END}}
    };

    static int transition(char ch) {
        if (isspace(ch)) {
            return 0;
        } else if (ch == '+' || ch == '-') {
            return 1;
        } else if (isdigit(ch)) {
            return 2;
        } else {
            return 3;
        }
    }

    int sign = 1;
    long long result = 0;

public:
    void deal(char ch) {
        state = table[state][transition(ch)];
        if (state == IN) {
            result = result * 10 + ch - '0';
            if (sign == 1) {
                result = std::min(result, (long long) INT_MAX);
            } else {
                result = std::min(result, -(long long) INT_MIN);
            }
        } else if (state == SIGNED) {
            sign = (ch == '+') ? 1 : -1;
        }
    }

    int getResult() {
        return sign * result;
    }
};


class Solution {
public:
    int myAtoi(std::string s) {
        if (s.empty()) {
            return 0;
        }
        FSM fsm = FSM();
        for (auto ch : s) {
            fsm.deal(ch);
        }
        return fsm.getResult();
    }
};
#endif // 有限状态机


#endif //LEETCODE_SOLUTION_H
