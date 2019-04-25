//
//  treeSpin2.cpp
//  Algorithm
//
//  Created by YLCHUN on 2019/4/2.
//  Copyright © 2019 YLCHUN. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Tree2 {
    int val;
    Tree2 *left;
    Tree2 *right;
} Tree2;


//二叉树画左右旋转
void spinTree(Tree2 *tree) {
    if (!tree) return;
    spinTree(tree->left);
    spinTree(tree->right);
    Tree2 *tmp = tree->left;
    tree->left = tree->right;
    tree->right = tmp;
}

Tree2* createTree(int val, int deep) {
    if (deep == 0) {
        return nullptr;
    }
    Tree2 *t = (Tree2*)malloc(sizeof(Tree2));
    t->val = val;
    t->left = createTree(val-deep, deep-1);
    t->right = createTree(val+deep, deep-1);
    return t;
}

void testSpinTree() {
    Tree2 *t = createTree(17, 3);
    spinTree(t);
    printf("");
    
}
