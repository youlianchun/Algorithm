//
//  isTree.cpp
//  Algorithm
//
//  Created by YLCHUN on 2019/4/2.
//  Copyright © 2019 YLCHUN. All rights reserved.
//

#include <stdio.h>
#include <map>
#include <set>

typedef std::map<int, std::set<int>> NodeSides;

static void addNode(NodeSides *ns, int f, int t) {
    NodeSides::iterator iter = ns->find(f);
    if (iter != ns->end()) {
        iter->second.insert(t);
    }else {
        std::set<int> nodes;
        nodes.insert(t);
        ns->insert(std::make_pair(f, nodes));
    }
}

static void delNode(NodeSides *ns, int f, int t) {
    NodeSides::iterator iter = ns->find(f);
    if (iter != ns->end()) {
        iter->second.erase(t);
        if (iter->second.size() == 0) {
            ns->erase(iter);
        }
    }
}


/*
 判断是不是数
 int data0[5][2] = { {0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4} };
 int data1[5][2] = { {0, 1}, {1, 2}, {2, 3}, {1, 5}, {1, 4} };
 bool isTree0 = isTree(data0);
 bool isTree1 = isTree(data1);
 */
bool isTree(int sides[5][2]) {
    NodeSides nodeSides;
    for (int i = 0; i < 5; i++) {
        int a = sides[i][0];
        int b = sides[i][1];
        addNode(&nodeSides, a, b);
        addNode(&nodeSides, b, a);
    }
    while (true) {
        bool mayBe = false;
        NodeSides::iterator iter = nodeSides.begin();
        while (iter != nodeSides.end()) {
            int nodeA = iter->first;
            std::set<int> nodes = iter->second;
            iter ++;
            if (nodes.size() == 1) {
                std::set<int>::iterator it = nodes.begin();
                int nodeB = *it;
                nodes.erase(it);
                delNode(&nodeSides, nodeA, nodeB);
                delNode(&nodeSides, nodeB, nodeA);
                if (nodeSides.size() == 0) break;
                mayBe = true;
            }
        }
        if (!mayBe) break;
    }
    
    return nodeSides.size() == 0;
}
