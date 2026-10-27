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

    // Test Case 1: Specification Example (Delete intermediate node with value 5)
    {
        cout << "--- Test Case 1: Delete Intermediate Node ---\n";
        LinkedList<int> list;
        vector<int> initialValues = {20, 4, 5, 19, 47};
        for (int val : initialValues) {
            list.addLast(val);
        }

        cout << "Before:   " << list.toString() << "\n";
        cout << "Size:     " << list.size() << "\n";

        // TODO: Find index of element 5, delete it using solver, and print results (Expected: [20, 4, 19, 47], Size: 4)

    }

    // Test Case 2: Delete Second Node in small chain
    {
        cout << "--- Test Case 2: Delete Second Node ---\n";
        LinkedList<int> list;
        vector<int> initialValues = {1, 2, 3, 4};
        for (int val : initialValues) {
            list.addLast(val);
        }

        cout << "Before:   " << list.toString() << "\n";

        // TODO: Find index of element 2, delete it using solver, and print results (Expected: [1, 3, 4], Size: 3)

    }

    // Test Case 3: Delete Penultimate Node
    {
        cout << "--- Test Case 3: Delete Penultimate Node ---\n";
        LinkedList<int> list;
        vector<int> initialValues = {10, 20, 30};
        for (int val : initialValues) {
            list.addLast(val);
        }

        cout << "Before:   " << list.toString() << "\n";

        // TODO: Find index of element 20, delete it using solver, and print results (Expected: [10, 30], Size: 2)

    }

    // Test Case 4: Tail integrity after deleting penultimate node
    {
        cout << "--- Test Case 4: Tail Integrity ---\n";
        LinkedList<int> list;
        vector<int> initialValues = {10, 20, 30};
        for (int val : initialValues) {
            list.addLast(val);
        }

        // TODO: Delete index 1, append 40 to test tail pointer, and print results (Expected: [10, 30, 40], Size: 3)

    }

    // Test Case 5: Not applicable cases (Last node and out of bounds)
    {
        cout << "--- Test Case 5: Last Node and Invalid Position ---\n";
        LinkedList<int> list;
        vector<int> initialValues = {10, 20, 30};
        for (int val : initialValues) {
            list.addLast(val);
        }

        // TODO: Attempt to delete last node (size - 1) and invalid indices (-1, 10), then verify list remains unchanged (Expected: [10, 20, 30], Size: 3)

    }

    return 0;
}