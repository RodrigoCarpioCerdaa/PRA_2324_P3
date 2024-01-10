bin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry.cpp

bin/testHashTable: HashTable.h testHashTable.cpp
	mkdir -p bin 
	g++ -o bin/testHashTable testHashTable.cpp

bin/testBSTree: BSTree.h testBSTree.cpp
	mkdir -p bin
	g++ -o bin/testBSTree testBSTree.cpp


clean:
	rm -rf *.o *.gch bin
