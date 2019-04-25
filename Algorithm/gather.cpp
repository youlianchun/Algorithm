//
//  gather.cpp
//  Algorithm
//
//  Created by YLCHUN on 2019/4/2.
//  Copyright © 2019 YLCHUN. All rights reserved.
//

#include <stdio.h>

//same //disparity
//typedef enum : int {
//    GatherSame  = 1<<0,
//    GatherDisparity = 1<<1,
//} GatherOption;

static const int GatherSame  = 1<<0;
static const int GatherDisparity  = 1<<1;
//并交差集合
void gather(int a[5], int b[5], int op) {
    for (int i = 0; i < 5; i ++) {
        for (int j = 0; j < 5; j ++) {
            if (b[j] == a[i]) {
                if (op & GatherSame) {
                    printf("%d ", b[j]);
                }
                i ++;
            } else if (b[j] > a[i]) {
                if (op & GatherDisparity) {
                    printf("%d ", a[i]);
                }
                i ++;
                j --;
            } else {
                if (op & GatherDisparity) {
                    printf("%d ", b[j]);
                }
            }
        }
    }
}

void testGather() {
    int d0[5] = { 1, 2, 4, 5, 9 };
    int d1[5] = { 0, 2, 3, 5, 9 };
    int op = GatherSame | GatherDisparity;
    gather(d0, d1, op);
}
