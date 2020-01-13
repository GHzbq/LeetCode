/**
 * 9.回文数
 * https://leetcode-cn.com/problems/palindrome-number/submissions/
 * */
#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;

        if (x >= 0)
        {
            std::string number = std::to_string(x);


            int n = static_cast<int>(number.length());
            int end = n-1;
            int begin = 0;
            while(begin < end)
            {
                if(number[begin] != number[end])
                    return false;

                ++begin;
                --end;
            }
        }

        return true;
    }
};
