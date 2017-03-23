//
// Created by 王青龙 on 2017/3/23.
//

#include <iostream>
#include "solution.h"

void Solution::Print1ToMaxOfDigits(int n) {
    if (n < 1) {
        return;
    }
    std::vector<char> number(n, '0');
    while (!(Increment(number))) {
        int flag = 0;
        for (auto i = 0; i < number.size(); ++i) {
            if (number[i] != '0') {//这个判断要注意，不是0而是'0'
                flag = 1;
            }
            if (flag == 1) {
                std::cout << number[i];
            }
        }
        std::cout << std::endl;
    }
}

bool Solution::Increment(std::vector<char> &number) {
    bool isOverflow = false;
    int carry = 0;
    auto len = number.size();
    for (int i = len - 1; i >= 0; --i) {
        int curNum = number[i] - '0' + carry;
        if (i == len - 1) {
            ++curNum;
        }
        if (curNum < 10) {
            number[i] += 1;
            break;
        } else {
            if (i == 0) {
                isOverflow = true;
            } else {
                number[i] = '0';
                carry = 1;
            }
        }
    }
    return isOverflow;
}


