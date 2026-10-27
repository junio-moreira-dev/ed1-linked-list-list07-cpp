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
    LinkedList<int> list;

    // TODO: Add test calls for addSorted
    solver.testSortedInsertion(list, {10, 5, 20});
    cout << list.toString() << "\n";

    return 0;
}