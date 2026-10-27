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

    // Test Case 1: Specification Example ([20 -> 4 -> 5 -> 19 -> 47])
    {
        cout << "--- Test Case 1: Specification Example ---\n";
        LinkedList<int> list;
        for (int val : {20, 4, 5, 19, 47}) {
            list.addLast(val);
        }

        cout << "Before:   " << list.toString() << "\n";

        // TODO: Reverse list using solver, print results (Expected: [47, 19, 5, 4, 20], Size: 5), append 99 to validate tail (Expected: [47, 19, 5, 4, 20, 99])

    }

    // Test Case 2: Two Elements ([1 -> 2])
    {
        cout << "--- Test Case 2: Two Elements ---\n";
        LinkedList<int> list;
        list.addLast(1);
        list.addLast(2);

        cout << "Before:   " << list.toString() << "\n";

        // TODO: Reverse list using solver and print results (Expected: [2, 1], Size: 2)

    }

    // Test Case 3: Single Element ([10])
    {
        cout << "--- Test Case 3: Single Element ---\n";
        LinkedList<int> list;
        list.addLast(10);

        cout << "Before:   " << list.toString() << "\n";

        // TODO: Reverse list using solver and print results (Expected: [10], Size: 1)

    }

    // Test Case 4: Empty List
    {
        cout << "--- Test Case 4: Empty List ---\n";
        LinkedList<int> list;

        cout << "Before:   " << list.toString() << "\n";

        // TODO: Reverse empty list using solver and print results (Expected: [], Size: 0)

    }

    return 0;
}