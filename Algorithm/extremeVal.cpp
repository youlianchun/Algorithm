//
//  extremeVal.cpp
//  Algorithm
//
//  Created by YLCHUN on 2019/4/2.
//  Copyright © 2019 YLCHUN. All rights reserved.
//

#include <stdio.h>
// 极值
void extreme(int datas[5]) {
    int l = 0, r = 5 - 1;
    int min = 0, max = __INT_MAX__, tmin, tmax ;
    while (l < r) {
        tmin = datas[l];
        tmax = datas[r];
        if (tmin > tmax) {
            int t = tmin;
            tmin = tmax;
            tmax = t;
        }
        if (tmin < min) {
            min = tmin;
        }
        if (tmax > max) {
            max = tmax;
        }
        l++;
        r--;
    }
}
