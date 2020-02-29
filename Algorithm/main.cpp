//
//  main.cpp
//  Algorithm
//
//  Created by YLCHUN on 2019/4/2.
//  Copyright © 2019 YLCHUN. All rights reserved.
//

#include <iostream>
#include <stdlib.h>

extern bool isTree(int sides[5][2]);
extern void perm(int data[4]);
extern void edgeArr(int xCount, int yCount, void(^index)(int x, int y));
extern void testSpinTree();
extern void testGather();
extern void testTreeNode();
extern void testToInt();
int main(int argc, const char * argv[]) {
//    testSpinTree();
//    int data0[5][2] = { {0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4} };
//    int data1[5][2] = { {0, 1}, {1, 2}, {2, 3}, {1, 5}, {1, 4} };
//    bool isTree0 = isTree(data0);
//    bool isTree1 = isTree(data1);
//    int data[4] = {1,2,3,4};
//    perm(data);
//    edgeArr(10, 10, ^(int x, int y) {
//        printf("%d, %d", x, y);
//    });

//    testTreeNode();
    testToInt();
    return 0;
}

