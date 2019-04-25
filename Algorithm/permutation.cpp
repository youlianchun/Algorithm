//
//  permutation.cpp
//  Algorithm
//
//  Created by YLCHUN on 2019/4/2.
//  Copyright © 2019 YLCHUN. All rights reserved.
//

#include <stdio.h>

static void pArr(int data[4]) {
    for (int i = 0; i < 4; i ++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

static  void exchange(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
//全排列组合
static  void permSub(int data[4], int idx, void(^callback)(int data[4])) {
    if (idx == 0) {
        callback(data);
    }
    for (int i = idx; i < 4; i++) {
        if (i != idx) {
            exchange(&data[i], &data[idx]);
            callback(data);
        }
        permSub(data, idx + 1, callback);
        if (i != idx) {
            exchange(&data[i], &data[idx]);
        }
    }
}


/*
  全排列组合
 */
void perm(int data[4]) {
    permSub(data, 0, ^(int data[4]) {
        pArr(data);
    });
}
