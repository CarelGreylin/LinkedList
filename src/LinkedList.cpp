#include "../include/LinkedList.hpp"

LinkedList::LinkedList() {
  mLength = 0;
  mHead = nullptr;
  mTail = nullptr;
}

void LinkedList::addFirst(const int32_t element) {
  const std::shared_ptr<Node> newNode{new Node{element}};
  
  if (mLength < 1) {
    mHead = newNode;
    mTail = newNode;
  } else {
    newNode->setNext(mHead);
    mHead = newNode;
  }
  mLength++;
}

void LinkedList::addLast(const int32_t element) {
  const std::shared_ptr<Node> newNode{new Node{element}};
  
  if (mLength < 1) {
    mHead = newNode;
    mTail = newNode;
  } else {
    mTail->setNext(newNode);
    mTail = newNode;
  }
  mLength++;
}

int32_t LinkedList::removeFirst() {
  if (mLength == 0) {
    throw std::range_error("The list is empty.");
  }
  auto oldNode = mHead;
  mHead = oldNode->getNext();
  mLength--;
  return oldNode->getData();
}

int32_t LinkedList::removeLast() {
  // Error checking
  if (mLength == 0) {
    throw std::range_error("The list is empty.");
  }
  mLength--;

  // Find the new tail
  std::shared_ptr<Node> prev{nullptr};
  auto current = mHead;
  while (current->getNext() != nullptr) {
    prev = current;
    current = current->getNext();
  }
  mTail = prev;
  // Set the tail to point to nullptr if the tail itself is not nullptr.
  if (prev) { mTail->setNext(nullptr); }
  return current->getData();
}

void LinkedList::showList() const {
  auto current = mHead;
  if (current != nullptr) {
    std::cout << current->getData();
    current = current->getNext();
    while (current != nullptr) {
      std::cout << " -> " << current->getData();
      current = current->getNext();
    }
  }
}


void LinkedList::reverse() {
  std::shared_ptr<Node> prev{nullptr};
  auto current = mHead;

  // Swap the direction of all the Nodes
  while (current != nullptr) {
    auto oldCurrent {*current};
    // Swap direction
    current->setNext(prev);

    // Move along the list
    prev = current;
    current = oldCurrent.getNext();
  }
  // Swap head and tail
  auto headHolder {mHead};
  mHead = mTail;
  mTail = headHolder;
}

int32_t LinkedList::getFirst() const {
  if (mLength == 0) {
    return NULL;
  }
  return mHead->getData();
}

int32_t LinkedList::getLast() const {
  if (mLength == 0) {
    return NULL;
  }
  return mTail->getData();
}

int LinkedList::getLength() const {
  return mLength;
}
