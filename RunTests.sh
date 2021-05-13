#!/bin/bash

g++ src/TestLinkedList.cpp src/LinkedList.cpp -o tests.exe

./tests.exe

rm tests.exe