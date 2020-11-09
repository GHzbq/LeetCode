//
// Created by zhangbaqing on 2020/11/9.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

#if 0
/**
 * 自动机
 */
class Automaton {
    std::string state = "start";
    std::unordered_map<std::string, std::vector<std::string>> table = {
            {"start", {"start", "signed", "in_number", "end"}},
            {"signed", {"end", "end", "in_number", "end"}},
            {"in_number", {"end", "end", "in_number", "end"}},
            {"end", {"end", "end", "end", "end"}}
    };

    static int getCol(char c) {
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        state = table[state][getCol(c)];
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? std::min(ans, (long long)INT_MAX) : std::min(ans, -(long long)INT_MIN);
        } else if (state == "signed") {
            sign = c == '+' ? 1 : -1;
        }

    }
};

class Solution {
public:
    int myAtoi(std::string str) {
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};
#endif

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
