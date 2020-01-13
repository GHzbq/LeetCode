#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    int myAtoi(std::string str) {
        // 当发生正溢出时，返回INTMAX_MAX
        if ((sign == '+') && (c > INTMAX_MAX - n * 10))
        {
            n = INTMAX_MAX;
            break;
        }
        // 当发生负溢出时，返回INTMAX_MIN
        else if( (sign == '-') && (c-1 > INTMAX_MAX - n * 10))
        {
            n = INTMAX_MAX;
            break;
        }
    }
};
