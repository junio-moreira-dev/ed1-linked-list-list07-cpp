//
// Created by Junio Moreira on 23/10/26.
// Problem 4: Merge Two Sorted Lists (merge of existing nodes)
//
// Strategy:
//  Two pointers walk the lists at the same time, a (list1) and b (list2).
//  A temporary "dummy" node marks the start of the merged chain, so the first node
//  does not need a special case. At each step the smaller current node is linked to
//  the end of the merged chain and its pointer advances. Only next pointers are
//  changed: the nodes of the lists are not created, copied or deleted.
//  When one list ends, the rest of the other list is already sorted, so it is
//  attached in a single step. At the end, the dummy node is deleted.
//
//  Example: list1 = 1 -> 3 -> 5 -> 7, list2 = 2 -> 4 -> 6 -> 8
//    dummy -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8   (head = dummy->next)
//
//  On a tie the node of list1 goes first, so the merge is stable.
//
//  Since the nodes are moved to the merged list, list1 becomes the result
//  (head, tail and count updated) and list2 is left empty. Otherwise both lists
//  would own the same nodes and their destructors would delete them twice.
//
//  Complexity: O(n + m) time (each node is visited once), O(1) extra space.
//

#include <iostream>
#include <vector>
#include "../include/LinkedList.h"

using namespace std;

// class Solution {
// public:
//     // Merges two ascending-sorted LinkedLists into a single sorted LinkedList
//     // by consuming the elements from both lists via ADT operations.
//     // Time Complexity: O(N + M) since removeFirst and addLast operate in O(1)
//     // Space Complexity: O(1) auxiliary (excluding resulting list container)
//     template <typename T>
//     LinkedList<T> mergeTwoLists(LinkedList<T>& list1, LinkedList<T>& list2) {
//         LinkedList<T> merged;
//
//         // Compare heads and transfer the smaller item to the merged list
//         while (!list1.isEmpty() && !list2.isEmpty()) {
//             if (!(list2.get(0) < list1.get(0))) {
//                 merged.addLast(list1.removeFirst());
//             } else {
//                 merged.addLast(list2.removeFirst());
//             }
//         }
//
//         // Drain remaining elements from list1, if any
//         while (!list1.isEmpty()) {
//             merged.addLast(list1.removeFirst());
//         }
//
//         // Drain remaining elements from list2, if any
//         while (!list2.isEmpty()) {
//             merged.addLast(list2.removeFirst());
//         }
//
//         return merged;
//     }
// };

class Solution {
public:
    // Merges two sorted lists by relinking their existing nodes.
    // The merged list is kept in list1, list2 is left empty.
    // Returns the pointer to the head of the merged list.
    template <typename T>
    typename LinkedList<T>::Node* mergeTwoLists(LinkedList<T>& list1, LinkedList<T>& list2) {
        // TODO: Merge two sorted lists into one
        return nullptr;
    }
};

// Helper: fills a list with the given values (in the given order)
void fill(LinkedList<int>& list, const vector<int>& values) {
    for (int val : values) {
        list.addLast(val);
    }
}

int main() {
    Solution solver;

    // Test Case 1: Specification Example
    {
        cout << "--- Test Case 1: Specification Example ---\n";
        LinkedList<int> list1, list2;
        for (int val : {1, 3, 5, 7}) list1.addLast(val);
        for (int val : {2, 4, 6, 8}) list2.addLast(val);

        cout << "List1:    " << list1.toString() << "\n";
        cout << "List2:    " << list2.toString() << "\n";

        // TODO: Merge list1 and list2 using solver, verify returned head value (Expected: 1), and print merged list (Expected: [1, 2, 3, 4, 5, 6, 7, 8], Size: 8)

    }

    // Test Case 2: First list is empty
    {
        cout << "--- Test Case 2: First List Empty ---\n";
        LinkedList<int> list1, list2;
        for (int val : {1, 2, 3}) list2.addLast(val);

        // TODO: Merge list1 and list2 using solver and print merged list (Expected: [1, 2, 3], Size: 3)

    }

    // Test Case 3: Second list is empty
    {
        cout << "--- Test Case 3: Second List Empty ---\n";
        LinkedList<int> list1, list2;
        for (int val : {1, 2, 3}) list1.addLast(val);

        // TODO: Merge list1 and list2 using solver and print merged list (Expected: [1, 2, 3], Size: 3)

    }

    // Test Case 4: Both lists empty
    {
        cout << "--- Test Case 4: Both Lists Empty ---\n";
        LinkedList<int> list1, list2;

        // TODO: Merge both empty lists, verify returned head is nullptr, and print result (Expected: [], Size: 0)

    }

    // Test Case 5: Lists of different sizes
    {
        cout << "--- Test Case 5: Different Sizes ---\n";
        LinkedList<int> list1, list2;
        for (int val : {1, 2, 3}) list1.addLast(val);
        for (int val : {4, 5, 6, 7}) list2.addLast(val);

        // TODO: Merge list1 and list2 using solver and print result (Expected: [1, 2, 3, 4, 5, 6, 7], Size: 7)

    }

    // Test Case 6: Duplicate values
    {
        cout << "--- Test Case 6: Duplicates ---\n";
        LinkedList<int> list1, list2;
        for (int val : {1, 3, 3, 5}) list1.addLast(val);
        for (int val : {3, 4}) list2.addLast(val);

        // TODO: Merge lists containing duplicate values and print result (Expected: [1, 3, 3, 3, 4, 5], Size: 6)

    }

    // Test Case 7: Tail integrity
    {
        cout << "--- Test Case 7: Tail Integrity ---\n";
        LinkedList<int> list1, list2;
        for (int val : {1, 3, 9}) list1.addLast(val);
        for (int val : {2, 4}) list2.addLast(val);

        // TODO: Merge lists, append 10 to test tail pointer, and print result (Expected: [1, 2, 3, 4, 9, 10])

    }

    return 0;
}