# LinkedList
* Linked list implementation using C++ for the 2021 Startmate engineering task.
* Catch2 is used as a testing suite.
* The linked list is implemented using object oriented programming. All required features are implemented as methods of a class.
* Smart pointers are used to link the list and automate memory management.

# Instructions For Use

**On Linux run:**
```
sh RunTests.sh
```
It may take a while to run. This is because of the Catch2 testing suite being very slow to compile not my code :)

**On Windows, run:**
```
g++ src/TestLinkedList.cpp src/LinkedList.cpp -o tests.exe
```
from the root directory. Finally run the executable generated with:
```
./tests.exe
```

Feel free to test the code using any other methods.

**Having trouble?**

If you are getting tons of errors when running the above commands, it's likely that your g++ is outdated and not compatible with `<cstdint>`. Update it by running the following commands:
```
$ sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
$ sudo apt-get update
$ sudo apt-get install gcc-8 g++-8
$ sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-6 20 --slave /usr/bin/g++ g++ /usr/bin/g++-6
```

You can check that you have version 8 installed correctly by running:
```
$ g++ --version
```
Try running the tests again.

**If you are still having issues** and you have been trying to use the script just run the commands in the script individually:

```
$ g++ src/TestLinkedList.cpp src/LinkedList.cpp -o tests.exe
$ ./tests.exe
$ rm tests.exe
```

# Features
Given:
```C++
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
`LinkedList listCopy{l}` <br>Constructor for a LinkedList that copies the list `l`. | `LinkedList` | None
`l[index]` <br>Gets the element `e` at the position `index` in the LinkedList. | `int e` | `std::range_error` when the `index` is out of bounds.
`l.reverse()`<br>Modifies the list `l` to reverse it's order.  | `void` | None
`l.getLength()`<br>Returns the length of the list `l`. | `int` | None

# Assumptions

* All data elements of the list will be 32 bit integers.
