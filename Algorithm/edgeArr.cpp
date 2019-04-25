//
//  edgeArr.cpp
//  Algorithm
//
//  Created by YLCHUN on 2019/4/2.
//  Copyright © 2019 YLCHUN. All rights reserved.
//

#include <stdio.h>

/*
 顺边界由外向内循环打印二维数组
 */
void edgeArr(int xCount, int yCount, void(^index)(int x, int y)) {
    if (xCount <= 0 || yCount <= 0) {
        return;
    }
    int x0 = 0, x1 = xCount, y0 = 0, y1 = yCount;
    int x = 0, y = 0;
    while (x0 != x1 || y0 != y1) {
        for (int i = x0; i < x1; i++) {
            x = i;
            index(x, y);
        }
        y0++;
        for (int i = y0; i < y1; i++) {
            y = i;
            index(x, y);
        }
        x1--;
        for (int i = x1-1; i >= x0; i--) {
            x = i;
            index(x, y);
        }
        y1--;
        for (int i = y1-1; i >= y0 ; i--) {
            y = i;
            index(x, y);
        }
        x0++;
    }
}
