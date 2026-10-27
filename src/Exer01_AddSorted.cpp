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
        // TODO: Implement sorted insertion into the LinkedList
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

        // TODO: Insert value 10 into 'list' using solver and print result (Expected: [10], Size: 1)

    }

    // Test Case 2: Insertion at the beginning (minimum element)
    {
        cout << "--- Test Case 2: Insertion at Head ---\n";
        LinkedList<int> list;
        list.addLast(10);
        list.addLast(20);
        list.addLast(30);

        cout << "Before:   " << list.toString() << "\n";

        // TODO: Insert value 5 into 'list' using solver and print result (Expected: [5, 10, 20, 30], Size: 4)

    }

    // Test Case 3: Insertion in the middle
    {
        cout << "--- Test Case 3: Insertion in Middle ---\n";
        LinkedList<int> list;
        list.addLast(10);
        list.addLast(20);
        list.addLast(30);

        cout << "Before:   " << list.toString() << "\n";

        // TODO: Insert value 25 into 'list' using solver and print result (Expected: [10, 20, 25, 30], Size: 4)

    }

    // Test Case 4: Insertion at the end (maximum element)
    {
        cout << "--- Test Case 4: Insertion at Tail ---\n";
        LinkedList<int> list;
        list.addLast(10);
        list.addLast(20);
        list.addLast(30);

        cout << "Before:   " << list.toString() << "\n";

        // TODO: Insert value 40 into 'list' using solver and print result (Expected: [10, 20, 30, 40], Size: 4)

    }

    // Test Case 5: Full build from scratch with unordered items
    {
        cout << "--- Test Case 5: Build From Unordered Stream ---\n";
        LinkedList<int> list;

        // TODO: Insert stream {30, 10, 50, 20, 40} using solver and print result (Expected: [10, 20, 30, 40, 50], Size: 5)

    }

    return 0;
}