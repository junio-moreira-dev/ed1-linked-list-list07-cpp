//
// Created by Junio Moreira on 23/10/26.
// Problem 5: Remove Nth Node From End (Fast/Slow Pointers, one pass)
//
// Strategy:
//  The distance between the two pointers is kept equal to n. When fast reaches the
//  end of the list, slow is right before the node to be removed.
//    1. fast advances n positions from the head (slow stays at the head).
//    2. fast and slow advance together until fast reaches the last node.
//    3. slow->next is the n-th node from the end: slow->next = slow->next->next
//       and the removed node is deleted.
//
//  Example: 1 -> 2 -> 3 -> 4 -> 5, n = 2
//    step 1: fast at 3, slow at 1
//    step 2: fast at 5, slow at 3
//    step 3: remove slow->next (4)  =>  1 -> 2 -> 3 -> 5
//
//  Special case: if fast becomes null right after step 1, then n equals the size of
//  the list and the node to remove is the head (it has no node before it).
//
//  The size of the list is never used to locate the node (no counting pass): the list
//  is walked only once. The count attribute is only decremented after the removal.
//
//  Complexity: O(N) time (one pass), O(1) space.
//

#include <iostream>
#include <vector>
#include "../include/LinkedList.h"

using namespace std;

// class Solution {
// public:
//     // Removes the n-th node from the end of the list using ADT operations
//     // Time Complexity: O(N) due to list traversal in removeAt
//     // Space Complexity: O(1) auxiliary space
//     template <typename T>
//     void removeNthFromEnd(LinkedList<T>& list, int n) {
//         if (list.isEmpty() || n <= 0 || n > list.size()) {
//             return;
//         }
//
//         // Calculate 0-based index from the start
//         int targetIndex = list.size() - n;
//         list.removeAt(targetIndex);
//     }
// };

class Solution {
public:
    // Removes the n-th node counted from the end of the list.
    // If n is invalid (n <= 0 or n greater than the size), the list is not changed.
    // Returns the pointer to the (updated) head of the list.
    template <typename T>
    typename LinkedList<T>::Node* removeNthFromEnd(LinkedList<T>& list, int n) {
        // TODO: Remove n-th node from end in a single pass
        return list.head;
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
    LinkedList<int> list;

    for (int v : {1, 2, 3, 4, 5}) list.addLast(v);

    // TODO: Add test calls for removeNthFromEnd
    solver.removeNthFromEnd(list, 2);
    cout << list.toString() << "\n";

    return 0;
}