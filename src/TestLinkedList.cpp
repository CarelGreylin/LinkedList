/*
 * This file contains the tests for the LinkedList class.
 * All class methods are tested in isolation as far as possible.
 * Integration testing is also performed on some methods that
 * influence each other.
 * 
 * The Catch2 testing suite is used to conduct these tests.
 * Tests are performed on invalid input but not overly large data sets.
 * 
 * Author: Carel Greyling, 2021
 */

#define CATCH_CONFIG_MAIN // This removes the need for a main function.

#include "../include/LinkedList.hpp"
#include "../include/catch.hpp"

TEST_CASE("Simple addFirst test.") {
  LinkedList l;
  
  int32_t e {8};
  int32_t length {100};

  // Tests that the element is both the start and end of the list.
  REQUIRE_NOTHROW(l.addFirst(e));
  REQUIRE(l.getFirst() == e);
  REQUIRE(l.getLast() == e);

  // Tests adding multiple elements.
  for (int i = 0; i < length; i++) {
    l.addFirst(i);
  }

  // Tests that the first element added is still the last element in
  // the list and that the last one added is the first.
  REQUIRE(l.getLength() == length + 1);
  REQUIRE(l.getFirst() == length - 1);
  REQUIRE(l.getLast() == e);
}

TEST_CASE("Simple addLast test.") {
  LinkedList l;
  
  int32_t e{8};
  int32_t length{100};

  // Tests that the element is both the start and end of the list.
  REQUIRE_NOTHROW(l.addLast(e));
  REQUIRE(l.getFirst() == e);
  REQUIRE(l.getLast() == e);

  // Tests adding multiple elements.
  for (int i = 0; i < length; i++) {
    l.addLast(i);
  }

  // Tests that the first element added is still the first element in
  // the list and that the last one added is the last.
  REQUIRE(l.getLength() == length + 1);
  REQUIRE(l.getFirst() == e);
  REQUIRE(l.getLast() == length - 1);
}

TEST_CASE("Simple removeFirst test.") {
  LinkedList l;
  int32_t length{100};

  for (int i = 0; i < length; i++) {
    l.addLast(i);
  }

  // Check that all class members are modified correctly and that
  // removeFirst returns the right value.
  REQUIRE(l.removeFirst() == 0);
  REQUIRE(l.getLength() == length - 1);
  REQUIRE(l.getFirst() == 1);

  // Remove all elements.
  for (int i = 0; i < length - 1; i++) {
    l.removeFirst();
  }

  REQUIRE(l.getLength() == 0);

  // Test that an exception is thrown when removing from an empty list.
  REQUIRE_THROWS_AS(l.removeFirst(), std::range_error);
}

TEST_CASE("Simple removeLast test.") {
  LinkedList l;
  int32_t length{100};

  for (int i = 0; i < length; i++) {
    l.addLast(i);
  }

  // Check that all class members are modified correctly and that
  // removeLast returns the right value.
  REQUIRE(l.removeLast() == length - 1);
  REQUIRE(l.getLength() == length - 1);
  REQUIRE(l.getLast() == length - 2);

  // Remove all elements.
  for (int i = 0; i < length - 1; i++) {
    l.removeLast();
  }

  REQUIRE(l.getLength() == 0);

  // Test that an exception is thrown when removing from an empty list.
  REQUIRE_THROWS_AS(l.removeLast(), std::range_error);
}

TEST_CASE("getFirst and getLast NULL test.") {
  LinkedList l;

  CHECK(l.getFirst() == NULL);
  CHECK(l.getLast() == NULL);
}

TEST_CASE("Test showList standard output format.") {
  // Redirect the stream buffer pointer for standard output to the stream
  // buffer pointer for the stringstream. Keep the old pointer to reset
  // the standard output pointer later.
  std::stringstream buffer;
  std::streambuf *old { std::cout.rdbuf(buffer.rdbuf()) };

  LinkedList l;
  
  // Test empty case
  l.showList();
  CHECK(buffer.str() == "\n");
  buffer.clear();

  // Test one long
  l.addLast(1);
  l.showList();
  CHECK(buffer.str() == "1\n");
  buffer.clear();

  // Test generic case
  for (int i = 2; i <= 5; i++) {
    l.addLast(i);
  }
  l.showList();
  CHECK(buffer.str() == "1 -> 2 -> 3 -> 4 -> 5\n");
  buffer.clear();

  // Reset the stream buffer pointer for standard output.
  std::cout.rdbuf(old);
}

TEST_CASE("Test reverse.") {
  LinkedList l;

  // Check no exceptions are thrown on empty lists.
  CHECK_NOTHROW(l.reverse());

  l.addFirst(1);

  // Check that a list of one length does not change.
  l.reverse();
  CHECK(l.getFirst() == 1);
  CHECK(l.getLast() == 1);

  l.addLast(2);

  // Check that a small list gets flipped.
  l.reverse();
  CHECK(l.getFirst() == 2);
  CHECK(l.getLast() == 1);

  // Redirect the stream buffer pointer for standard output to the stream
  // buffer pointer for the stringstream. Keep the old pointer to reset
  // the standard output pointer later. This is to test for larger lists.
  std::stringstream buffer;
  std::streambuf *old { std::cout.rdbuf(buffer.rdbuf()) };

  for (int i = 3; i <= 5; i++) {
    l.addFirst(i);
  }

  l.showList();
  CHECK(buffer.str() == "5 -> 4 -> 3 -> 2 -> 1\n");
  buffer.clear();

  l.reverse();
  l.showList();
  CHECK(buffer.str() == "1 -> 2 -> 3 -> 4 -> 5\n");

  // Reset the stream buffer pointer for standard output.
  std::cout.rdbuf(old);
}
