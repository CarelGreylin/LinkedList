/*
 * LinkedList class implementing a singly linked list using cpp smart pointers.
 * The list can only hold 32-bit integers.
 * Some basic methods have been implemented.
 * 
 * Author: Carel Greyling 2021
 */
#pragma once

#include <cstdint>
#include <memory>

typedef struct node Node;

class LinkedList {
  public:
    LinkedList();

    // Adds the @element to the start of the LinkedList.
    void addFirst(const int32_t element);
    // Adds the @element to the end of the LinkedList.
    void addLast(const int32_t element);

    // Remove the first element from the LinkedList.
    // Returns: The element that has been removed.
    // Raises: std::range_error when the list is empty.
    int32_t removeFirst();
    // Remove the last element from the LinkedList.
    // Returns: The element that has been removed.
    // Raises: std::range_error when the list is empty.
    int32_t removeLast();

    // Returns the first element in the LinkedList.
    // Returns NULL if the LinkedList is empty.
    auto getFirst() const;
    // Returns the last element in the LinkedList.
    // Returns NULL if the LinkedList is empty.
    auto getLast() const;

    // Prints the LinkedList to standard output.
    // Prints in the format: 1 -> 5 -> 6 -> 8 \n
    void showList() const;

    // Reverses the order of the LinkedList.
    // Does not copy the list but modifies it statically.
    void reverse();

  private:
    Node mHead;
    Node mTail;
};

struct node {
  int32_t data;
  std::unique_ptr<Node> next;
};