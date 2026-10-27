//
// Created by Junio Moreira on 22/10/26.
// Problem 3: Reverse Linked List (High-Level ADT Approach)
//

#include <iostream>
#include <vector>
#include "../include/LinkedList.h"

using namespace std;

// class Solution {
// public:
//     // Reverses a LinkedList by moving elements from the front of the original
//     // list directly to the front of the reversed list (matching the Python approach).
//     // Time Complexity: O(N) since removeFirst() and addFirst() run in O(1)
//     // Space Complexity: O(1) auxiliary space (nodes are recycled)
//     template <typename T>
//     void reverseList(LinkedList<T>& list) {
//         LinkedList<T> reversed;
//
//         // While list still has elements:
//         // Pop the first item and prepend it to the new list
//         while (!list.isEmpty()) {
//             reversed.addFirst(list.removeFirst());
//         }
//
//         // Move the accumulated reversed chain back to the original list
//         while (!reversed.isEmpty()) {
//             list.addLast(reversed.removeFirst());
//         }
//     }
// };

class Solution {
public:
    // Inverts the pointers directly in-place (O(N) time, O(1) auxiliary space)
    // Matches the exact variable naming from the Python LeetCode 206 solution
    template <typename T>
    void reverseList(LinkedList<T>& list) {
        // TODO: Reverse the linked list in-place
    }
};

int main() {
    Solution solver;
    LinkedList<int> list;

    for (int v : {1, 2, 3, 4, 5}) list.addLast(v);

    // TODO: Add test calls for reverseList
    solver.reverseList(list);
    cout << list.toString() << "\n";

    return 0;
}