#build the static library
gcc -c src/*.c 
ar rcs libGDS.a *.o

#build tests
gcc tests/test_linked_list.c tests/common.c -Isrc -L. -lGDS -o test_linked_list
gcc tests/test_stack.c tests/common.c -Isrc -L. -lGDS -o test_stack
