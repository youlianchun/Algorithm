//
//  trees.cpp
//  Algorithm
//
//  Created by YLCHUN on 2019/4/26.
//  Copyright © 2019 YLCHUN. All rights reserved.
//

#include <stdio.h>
#include <string>

typedef struct TreeNode {
    char* val;
    TreeNode *left;
    TreeNode *right;
} TreeNode;
typedef struct TreeListNode {
    TreeNode *node;
    TreeListNode *nextY;
    TreeListNode *nextX;
} TreeListNode;

TreeListNode *newEmptyTreeListNode() {
    TreeListNode *node = (TreeListNode *)malloc(sizeof(TreeListNode));
    node->node = nullptr;
    node->nextX = nullptr;
    node->nextY = nullptr;
    return node;
}

typedef struct NodeVal {
    char* val;
    int deep;
    NodeVal *next;
} NodeVal;

TreeNode *newEmptyTreeNode() {
    TreeNode *tree = (TreeNode *)malloc(sizeof(TreeNode));
    tree->val = nullptr;
    tree->left = nullptr;
    tree->right = nullptr;
    return tree;
}

NodeVal *newEmptyNodeVal() {
    NodeVal *node = (NodeVal *)malloc(sizeof(NodeVal));
    node->deep = -1;
    node->val = nullptr;
    node->next = nullptr;
    return node;
}


int nextValLen(char *cs, int index, bool *isDeep) {
    int len = 0;
    int idx = index;
    char c = cs[idx];
    if (c == '\0') {
        return 0;
    }
    if (isDeep) *isDeep = c == '-';
    while (true) {
        if (cs[idx] == '\0') {
            break;
        }
        if (c == '-') {
            if (cs[idx] != '-') {
                break;
            }
        }else {
            if (cs[idx] == '-') {
                break;
            }
        }
        idx ++;
        len ++;
    }
    return len;
}


void setNodes(TreeNode *root, int deep, NodeVal **valPtr) {
    NodeVal *val = *valPtr;
    if (deep != val->deep) return;
    
    TreeNode *node = newEmptyTreeNode();
    root->left = node;
    node->val = val->val;
    if (val->next == nullptr)  return;
    
    *valPtr = val->next;
    setNodes(node, deep+1, valPtr);
    val = *valPtr;
    if (deep != val->deep) return;
    
    node = newEmptyTreeNode();
    node->val = val->val;
    root->right = node;
    if (val->next == nullptr) return;
    
    *valPtr = val->next;
    setNodes(node, deep+1, valPtr);
}

NodeVal *nodeValList(char *cs) {
    int deep = 0;
    int idx = 0;
    NodeVal *root = nullptr;
    NodeVal *last = nullptr;
    while (true) {
        bool isDeep = false;
        int len = nextValLen(cs, idx, &isDeep);
        if (len == 0) {
            break;
        }
        if (isDeep) {
            deep = len;
        }else {
            char * val = (char *)malloc(sizeof(char) * len);
            strncpy(val, cs+idx, len);
            NodeVal *node = newEmptyNodeVal();
            node->val = val;
            node->deep = deep;
            if (root == nullptr) {
                root = node;
            }
            if (last != nullptr) {
                last->next = node;
                last = node;
            }else {
                last = node;
            }
        }
        idx += len;
    }
    return root;
}

TreeNode *createTree(char *cs) {
    NodeVal *node = nodeValList(cs);
    TreeNode *tree = newEmptyTreeNode();
    setNodes(tree, 0, &node);
    return tree->left;
}

void printTree(TreeNode *tree) {
    TreeListNode *node = newEmptyTreeListNode();
    node->node = tree;
    if (node->node) {
        printf("%s, ", node->node->val);
    }else {
        printf("null, ");
    }
    
    TreeListNode *nodeX = node;
    while (nodeX != nullptr) {
        TreeListNode *nodeY = nodeX;
        TreeListNode *nodeY2 = nullptr;
        while (nodeY != nullptr) {
            if (nodeY->node == nullptr || (nodeY->node->left == nullptr && nodeY->node->right == nullptr)) {
                nodeY = nodeY->nextY;
                continue;
            }
            TreeListNode *tmp = newEmptyTreeListNode();
            tmp->node = nodeY->node->left;
            if (nodeX->nextX == nullptr) {
                nodeX->nextX = tmp;
                nodeY2 = tmp;
            }else {
                nodeY2->nextY = tmp;
                nodeY2 = nodeY2->nextY;
            }
            if (tmp->node) {
                printf("%s, ", tmp->node->val);
            }else {
                printf("null, ");
            }
            
            tmp = newEmptyTreeListNode();
            tmp->node = nodeY->node->right;
            nodeY2->nextY = tmp;
            if (tmp->node) {
                printf("%s, ", tmp->node->val);
            }else {
                printf("null, ");
            }

            nodeY2 = nodeY2->nextY;
            nodeY = nodeY->nextY;
        }
        nodeX = nodeX->nextX;
    }
}
void trees(char *cs) {
    printf("%s \n", cs);
    TreeNode *tree = createTree(cs);
    printTree(tree);
    printf("\n\n");
}
//https://leetcode-cn.com/problems/recover-a-tree-from-preorder-traversal/
void testTreeNode() {
    trees("1-2--3--4-5--6--7");
    trees("1-2--3---4-5--6---7");
    trees("1-401--349---90--88");
    printf("");
}
