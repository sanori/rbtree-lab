.PHONY: test

CFLAGS=-I ../src

test: test-rbtree
	./test-rbtree

test-rbtree: test-rbtree.o ../src/rbtree.o

../src/rbtree.o:
	$(MAKE) -C ../src rbtree.o