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


#endif //LEETCODE_SOLUTION_H
