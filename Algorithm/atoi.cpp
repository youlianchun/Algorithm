//
//  atoi.cpp
//  Algorithm
//
//  Created by YLCHUN on 2020/2/29.
//  Copyright © 2020 YLCHUN. All rights reserved.
//

#include <stdio.h>
#include <map>

static int ctoi(char c) {
    static std::map<char, int> ci_map;
    if (ci_map.size() == 0) {
        char ic_arr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for (int i = 0; i < sizeof(ic_arr); i ++) {
            ci_map.insert(std::pair<char, int>(ic_arr[i], i));
        }
    }
    std::map<char, int>::iterator iter = ci_map.find(c);
    if (iter == ci_map.end()) {
        return -1;
    }
    else {
        return iter->second;
    }
}


long toInt(char* c_str) {
    long sum = 0;
    bool is_empty = true;
    bool has_unint_val = false;
    char *c_ptr = c_str;
    while (*c_ptr != '\0') {
        is_empty = false;
        int i = ctoi(*c_ptr);
        if (i >= 0) {
            sum += i;
        }
        else {
            has_unint_val = true;
            break;
        }
        c_ptr++;
        if (*c_ptr != '\0') {
            sum = (sum << 3) + (sum << 1);//乘10
        }
    }
    
    if (!is_empty && !has_unint_val) {
        return sum;
    }
    else {
        return -1;
    }
}


void testToInt() {
    bool has_err = false;
    if (toInt("0123") != 123) {
        printf("**0");
        has_err = true;
    }
    if (toInt(" 123") != -1) {
        printf("**1");
        has_err = true;
    }
    if (toInt("1 23") != -1) {
        printf("**2");
        has_err = true;
    }
    if (toInt("") != -1) {
        printf("**3");
        has_err = true;
    }
    if (!has_err) {
        printf("success\n");
    }
}
