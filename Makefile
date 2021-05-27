all:
a.exe: all.h  arr.c bs.c linklist.c BST.c hash.c main.c
	gcc -o a.exe all.h  arr.c bs.c linklist.c BST.c hash.c main.c
clean:
	rm -f a.exe