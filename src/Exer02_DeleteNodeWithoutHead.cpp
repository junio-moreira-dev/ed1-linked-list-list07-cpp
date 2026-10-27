//
// Created by Junio Moreira on 23/10/26.
// Problem 2: Delete Node Without Predecessor (Node Copy + delete)
//
// Strategy:
//  In a singly linked list, removing a node normally requires its PREDECESSOR,
//  because it is the predecessor's next pointer that must "skip" the removed node.
//  Here we only have P, so we cannot unlink P itself. Instead, we remove the node
//  AFTER P, after taking its content:
//    1. nextNode = P->next          (the node that will be physically removed)
//    2. P->item  = nextNode->item   (P now holds the next value; value 5 is gone)
//    3. P->next  = nextNode->next   (the chain skips nextNode)
//    4. delete nextNode             (frees the memory: no memory leak)
//    5. count--                     (and tail is fixed when nextNode was the tail)
//
//  Example: 20 -> 4 -> 5 -> 19 -> 47, P points to 5
//    after step 2: 20 -> 4 -> 19 -> 19 -> 47   (P holds 19, nextNode still holds 19)
//    after step 3: 20 -> 4 -> 19 -> 47         (nextNode is out of the chain)
//    after step 4: the old node of 19 is released
//
//  Why it does NOT work when P is the last node:
//  there is no next node to copy from (P->next == nullptr). The only way to remove
//  the last node is to change the next pointer of its predecessor to nullptr, and
//  we do not have the predecessor. Copying "nothing" over P would leave the node
//  in the list. So the function rejects this case.
//
//  Complexity: O(1) time, O(1) space.
//

#include <iostream>
#include <vector>
#include "../include/LinkedList.h"

using namespace std;

class Solution {
public:
    // Deletes an intermediate element logically without predecessor traversal
    // Matches the O(1) time and space logic: after locating P, no traversal is needed
    template <typename T>
    void deleteNode(LinkedList<T>& list, int index) {
        // TODO: Implement node deletion without predecessor in O(1)
    }
};

int main() {
    Solution solver;
    LinkedList<int> list;

    for (int v : {20, 4, 5, 19, 47}) list.addLast(v);

    // TODO: Add test calls for deleteNode
    solver.deleteNode(list, 2);
    cout << list.toString() << "\n";

    return 0;
}