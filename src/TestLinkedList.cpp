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
  std::cout << "Testing addFirst..." << std::endl;
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
  std::cout << "Testing addLast..." << std::endl;
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
  std::cout << "Testing removeFirst..." << std::endl;
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
  std::cout << "Testing removeLast..." << std::endl;
  LinkedList l;
  int32_t length{100};

  for (int i = 0; i < length; i++) {
    l.addLast(i);
  }

  // Check that all class members are modified correctly and that
  // removeLast returns the right value.
  REQUIRE(l.removeLast() == length - 1);
  REQUIRE(l.getLast() == length - 2);
  REQUIRE(l.getLength() == length - 1);
  // Remove all elements.
  for (int i = 0; i < length - 1; i++) {
    REQUIRE(l.removeLast() == length - i - 2);
  }

  REQUIRE(l.getLength() == 0);

  // Test that an exception is thrown when removing from an empty list.
  REQUIRE_THROWS_AS(l.removeLast(), std::range_error);
}

TEST_CASE("getFirst and getLast NULL test.") {
  std::cout << "Testing getFirst and getLast..." << std::endl;
  LinkedList l;

  REQUIRE_THROWS_AS(l.getFirst(), std::range_error);
  REQUIRE_THROWS_AS(l.getLast(), std::range_error);
}

TEST_CASE("Test showList standard output format.") {
  std::cout << "Testing showList..." << std::endl;
  // Redirect the stream buffer pointer for standard output to the stream
  // buffer pointer for the stringstream. Keep the old pointer to reset
  // the standard output pointer later.
  std::stringstream buffer;
  std::streambuf *old { std::cout.rdbuf(buffer.rdbuf()) };

  LinkedList l;
  
  // Test empty case
  l.showList();
  CHECK(buffer.str() == "");
  buffer.str(""); // Reset the buffer.

  // Test one long
  l.addLast(1);
  l.showList();
  CHECK(buffer.str() == "1");
  buffer.str("");

  // Test generic case
  for (int i = 2; i <= 5; i++) {
    l.addLast(i);
  }
  l.showList();
  CHECK(buffer.str() == "1 -> 2 -> 3 -> 4 -> 5");
  buffer.str("");

  // Reset the stream buffer pointer for standard output.
  std::cout.rdbuf(old);
}

TEST_CASE("Test reverse.") {
  std::cout << "Testing reverse..." << std::endl;
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
  CHECK(buffer.str() == "5 -> 4 -> 3 -> 2 -> 1");
  buffer.str("");

  l.reverse();
  l.showList();
  CHECK(buffer.str() == "1 -> 2 -> 3 -> 4 -> 5");

  // Reset the stream buffer pointer for standard output.
  std::cout.rdbuf(old);
}

TEST_CASE("Test copy constructor.") {
  std::cout << "Testing copy constructor..." << std::endl;
  LinkedList l;

  for (int i = 0; i < 10; i++) {
    l.addLast(i);
  }

  LinkedList lCopy{l};

  REQUIRE(l.getLength() == lCopy.getLength());

  for (int i = 0; i < 10; i++) {
    CHECK(l.removeLast() == lCopy.removeLast());
  }

  REQUIRE(l.getLength() == lCopy.getLength());

  // Test that they are independent.
  l.addLast(1);
  lCopy.addLast(2);
  REQUIRE(l.getLast() != lCopy.getLast());
}

TEST_CASE("Test get operator") {
  std::cout << "Testing index operator..." << std::endl;
  LinkedList l;

  for (int i = 0; i < 10; i++) {
    l.addLast(i);
  }

  for (int i = 0; i < 10; i++) {
    CHECK(l[i] == i);
  }

  REQUIRE_THROWS_AS(l[10], std::range_error);
}
