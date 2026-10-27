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
        using Node = typename LinkedList<T>::Node;

        // Only locates P (simulates "we have a pointer P"); the removal itself uses just P
        if (index < 0 || index >= list.size()) {
            return;
        }
        Node* P = list.searchNode(index);

        // Validation: P must exist and cannot be the last node (tail)
        if (P->next == nullptr) {
            return;
        }

        // Identifies the node that will be physically removed
        Node* nextNode = P->next;

        // Transfers the element of the next node to the current one (P)
        P->item = nextNode->item;

        // Relinks the list, "skipping" nextNode
        P->next = nextNode->next;

        // If the removed node was the tail, P is now the last node
        if (nextNode == list.tail) {
            list.tail = P;
        }

        delete nextNode;  // Releases memory (replaces the reference cleanup of the TAD)
        list.count--;     // Updates the logical size of the list
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

        // Finding position of element 5 (index 2)
        int targetIndex = list.find(5);
        if (targetIndex != -1) {
            solver.deleteNode(list, targetIndex);
        }

        cout << "Output:   " << list.toString() << " (Expected: [20, 4, 19, 47])\n";
        cout << "Size:     " << list.size() << " (Expected: 4)\n\n";
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
        int targetIndex = list.find(2);
        if (targetIndex != -1) {
            solver.deleteNode(list, targetIndex);
        }

        cout << "Output:   " << list.toString() << " (Expected: [1, 3, 4])\n";
        cout << "Size:     " << list.size() << " (Expected: 3)\n\n";
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
        int targetIndex = list.find(20);
        if (targetIndex != -1) {
            solver.deleteNode(list, targetIndex);
        }

        cout << "Output:   " << list.toString() << " (Expected: [10, 30])\n";
        cout << "Size:     " << list.size() << " (Expected: 2)\n\n";
    }

    // Test Case 4: Tail integrity after deleting the penultimate node
    {
        cout << "--- Test Case 4: Tail Integrity ---\n";
        LinkedList<int> list;
        vector<int> initialValues = {10, 20, 30};
        for (int val : initialValues) {
            list.addLast(val);
        }

        solver.deleteNode(list, 1);
        list.addLast(40);  // a stale tail would corrupt the list here

        cout << "Output:   " << list.toString() << " (Expected: [10, 30, 40])\n";
        cout << "Size:     " << list.size() << " (Expected: 3)\n\n";
    }

    // Test Case 5: Not applicable cases (P is the last node, or invalid position)
    {
        cout << "--- Test Case 5: Last Node and Invalid Position ---\n";
        LinkedList<int> list;
        vector<int> initialValues = {10, 20, 30};
        for (int val : initialValues) {
            list.addLast(val);
        }

        solver.deleteNode(list, list.size() - 1);  // last node: technique does not apply
        solver.deleteNode(list, -1);
        solver.deleteNode(list, 10);

        cout << "Output:   " << list.toString() << " (Expected: [10, 20, 30])\n";
        cout << "Size:     " << list.size() << " (Expected: 3)\n";
    }

    return 0;
}