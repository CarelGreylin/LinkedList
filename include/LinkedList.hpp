/*
 * LinkedList class implementing a singly linked list using cpp smart pointers.
 * The list can only hold 32-bit integers.
 * Some basic methods have been implemented.
 * 
 * Author: Carel Greyling, 2021
 */
#pragma once

#include <cstdint>
#include <memory>
#include <stdexcept>
#include <iostream>

// Simple Node class to use inside of the LinkedList class.
class Node {
  public:
    Node(const int32_t data)
    : mData{data}, mNext{NULL} {};

    void setData(const int32_t data) { mData = data; }
    void setNext(const std::shared_ptr<Node> next) { mNext = next; }

    int32_t getData() const { return mData; }
    std::shared_ptr<Node> getNext() const { return mNext; }
  private:
    int32_t mData;
    std::shared_ptr<Node> mNext;
};


class LinkedList {
  public:
    // Default Constructor.
    LinkedList();

    // Constructor for copying another LinkedList.
    LinkedList(const LinkedList &list);

    // Adds the element to the start of the LinkedList.
    void addFirst(const int32_t element);
    // Adds the element to the end of the LinkedList.
    void addLast(const int32_t element);

    // Remove the first element from the LinkedList.
    // Returns: The element that has been removed.
    // Raises: std::range_error when the list is empty.
    int32_t removeFirst();
    // Remove the last element from the LinkedList.
    // Returns: The element that has been removed.
    // Raises: std::range_error when the list is empty.
    int32_t removeLast();

    // Prints the LinkedList to standard output.
    // Prints in the format: 1 -> 5 -> 6 -> 8 \n
    void showList() const;

    // Reverses the order of the LinkedList.
    // Does not copy the list but modifies it statically.
    void reverse();

    ///////////////////// Getters ///////////////////////

    // Returns the first element in the LinkedList.
    // Returns NULL if the LinkedList is empty.
    int32_t getFirst() const;
    // Returns the last element in the LinkedList.
    // Returns NULL if the LinkedList is empty.
    int32_t getLast() const;

    int getLength() const;

    //////////////////// Operators /////////////////////

    // Opperator for getting the value of the data in index i of the
    // LinkedList.
    int32_t operator[](const int i) const;

  private:
    std::shared_ptr<Node> mHead;
    std::shared_ptr<Node> mTail;
    int mLength;

    // Throws a std::range_error when the list is empty.
    void nullCheck() const;
};
