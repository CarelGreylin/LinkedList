# LinkedList
* Linked list implementation using C++ for the 2021 Startmate engineering task.
* Catch2 is used as a testing suite.
* The linked list is implemented using object oriented programming. All required features are implemented as methods of a class.

# Instructions For Use

To run the tests simply run:
```
sh RunTests.sh
```
in a Linux terminal
# Features
Given:
```
l = LinkedList();
```
## Required Features
Function | Returns | Raises
--- | --- | ---
`l.addFirst(e)`<br>Adds the element `e` to the front of list `l`.  | `void` | None.
`l.addLast(e)`<br>Adds the element `e` to the end of list `l`.  | `void` | None.
`l.removeFirst()`<br>Removes element `e` from the start of the list `l`.  | `int` element `e` | `std::range_error` when `l` is empty.
`l.removeLast()`<br>Removes element `e` from the end of the list `l`.  | `int` element `e` | `std::range_error` when `l` is empty.
`l.getFirst()`<br>Returns the first element `e` from the list `l`.  | `int` element `e`. | `std::range_error` when `l` is empty.
`l.getLast()`<br>Returns the last element `e` from the list `l`.  | `int` element `e`. | `std::range_error` when `l` is empty.
`l.showList()`<br>Prints the list `l` to standard output in the format: **1 -> 5 -> 6 -> 8**  | `void` | None.

## Additional Features
Function | Returns | Raises
--- | --- | ---
`l.reverse()`<br>Modifies the list `l` to reverse it's order.  | `void` | None
`l.getLength()`<br>Returns the length of the list `l`. | `int` | None

# Assumptions

* All data elements of the list will be 32 bit integers.
