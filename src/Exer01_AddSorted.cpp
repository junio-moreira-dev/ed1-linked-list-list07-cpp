//
// Created by Junio Moreira on 22/10/26.
// Problem 1: Sorted Insertion (addSorted)
//

#include <iostream>
#include <vector>
#include "../include/LinkedList.h"

using namespace std;

class Solution {
public:
    // Same logic as LinkedList<T>::addSorted, written outside the class
    // (Solution is a friend of LinkedList, so it can read head/tail and update count)
    template <typename T>
    void addSorted(LinkedList<T>& list, const T& item) {
        // Node is a private type nested in LinkedList, so it is named through the class
        using NodeT = typename LinkedList<T>::Node;

        if (list.count == 0 || !(list.head->item < item)) {
            list.addFirst(item);
        } else if (!(item < list.tail->item)) {
            list.addLast(item);
        } else {
            NodeT* current = list.head;
            while (current->next != nullptr && current->next->item < item) {
                current = current->next;
            }
            NodeT* newNode = new NodeT(item, current->next);
            current->next = newNode;
            list.count++;
        }
    }

    // Takes a linked list and a vector of values, inserting each in ascending sorted order
    template <typename T>
    void testSortedInsertion(LinkedList<T>& list, const vector<T>& itemsToInsert) {
        for (const T& item : itemsToInsert) {
            addSorted(list, item); // Calls Solution::addSorted
            // list.addSorted(item); // Would call LinkedList::addSorted
        }
    }
};

int main() {
    Solution solver;

    // Test Case 1: Insertion into an empty list
    {
        cout << "--- Test Case 1: Empty List Insertion ---\n";
        LinkedList<int> list;
        solver.testSortedInsertion(list, {10});
        cout << "Output:   " << list.toString() << " (Expected: [10])\n";
        cout << "Size:     " << list.size() << " (Expected: 1)\n\n";
    }

    // Test Case 2: Insertion at the beginning (minimum element)
    {
        cout << "--- Test Case 2: Insertion at Head ---\n";
        LinkedList<int> list;
        list.addLast(10);
        list.addLast(20);
        list.addLast(30);

        cout << "Before:   " << list.toString() << "\n";
        solver.testSortedInsertion(list, {5});
        cout << "Output:   " << list.toString() << " (Expected: [5, 10, 20, 30])\n";
        cout << "Size:     " << list.size() << " (Expected: 4)\n\n";
    }

    // Test Case 3: Insertion in the middle
    {
        cout << "--- Test Case 3: Insertion in Middle ---\n";
        LinkedList<int> list;
        list.addLast(10);
        list.addLast(20);
        list.addLast(30);

        cout << "Before:   " << list.toString() << "\n";
        solver.testSortedInsertion(list, {25});
        cout << "Output:   " << list.toString() << " (Expected: [10, 20, 25, 30])\n";
        cout << "Size:     " << list.size() << " (Expected: 4)\n\n";
    }

    // Test Case 4: Insertion at the end (maximum element)
    {
        cout << "--- Test Case 4: Insertion at Tail ---\n";
        LinkedList<int> list;
        list.addLast(10);
        list.addLast(20);
        list.addLast(30);

        cout << "Before:   " << list.toString() << "\n";
        solver.testSortedInsertion(list, {40});
        cout << "Output:   " << list.toString() << " (Expected: [10, 20, 30, 40])\n";
        cout << "Size:     " << list.size() << " (Expected: 4)\n\n";
    }

    // Test Case 5: Full build from scratch with unordered items
    {
        cout << "--- Test Case 5: Build From Unordered Stream ---\n";
        LinkedList<int> list;
        solver.testSortedInsertion(list, {30, 10, 50, 20, 40});
        cout << "Output:   " << list.toString() << " (Expected: [10, 20, 30, 40, 50])\n";
        cout << "Size:     " << list.size() << " (Expected: 5)\n";
    }

    return 0;
}