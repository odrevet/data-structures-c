LIB_NAME=DataStruct
OUT_DIR=./bin

mkdir -p $OUT_DIR

#build the static library
gcc -c src/*.c
ar rcs $OUT_DIR/lib$LIB_NAME.a *.o

#build tests
gcc tests/test_linked_list.c tests/common.c -Isrc -L$OUT_DIR -l$LIB_NAME -o $OUT_DIR/test_linked_list
gcc tests/test_stack.c tests/common.c -Isrc -L$OUT_DIR -l$LIB_NAME -o $OUT_DIR/test_stack
