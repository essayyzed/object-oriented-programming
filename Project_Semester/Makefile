CC = g++
ss = ./

CFLAGS = -c 

all : prog

prog: main.o compressHuffman.o compressRle.o createtree.o decompressHuffman.o decompressRle.o inorder.o print_list.o push.o selectTechnique.o constructor.o
	$(CC) main.o compressHuffman.o compressRle.o createtree.o decompressHuffman.o decompressRle.o inorder.o print_list.o push.o selectTechnique.o constructor.o -o project

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

compressHuffman.o : compressHuffman.cpp
	$(CC) $(CFLAGS) compressHuffman.cpp

compressRle.o : compressRle.cpp
	$(CC) $(CFLAGS) compressRle.cpp

createtree.o : createtree.cpp
	$(CC) $(CFLAGS) createtree.cpp

decompressHuffman.o : decompressHuffman.cpp
	$(CC) $(CFLAGS) decompressHuffman.cpp

decompressRle.o : decompressRle.cpp
	$(CC) $(CFLAGS) decompressRle.cpp

inorder.o : inorder.cpp
	$(CC) $(CFLAGS) inorder.cpp

print_list.o : print_list.cpp
	$(CC) $(CFLAGS) print_list.cpp

push.o : push.cpp
	$(CC) $(CFLAGS) push.cpp

selectTechnique.o : selectTechnique.cpp
	$(CC) $(CFLAGS) selectTechnique.cpp

constructor.o : constructor.cpp
	$(CC) $(CFLAGS) constructor.cpp


run:
	$(ss)project

clean:
	rm -rf *.o



