hash_table: xmalloc.o hash_table.o prime.o
	gcc -lm xmalloc.o hash_table.o prime.o -o hash_table

hash_table.o: src/hash_table.c src/hash_table.h prime.o
	gcc -lm -c src/hash_table.c -o hash_table.o

prime.o: src/prime.c src/prime.h
	gcc -lm -c src/prime.c -o prime.o

xmalloc.o: src/xmalloc.c src/xmalloc.h
	gcc -lm -c src/xmalloc.c -o xmalloc.o

.PHONY: clean
clean:
	rm -f *.o

.PHONY: src_only
src_only:
	rm -f *.o hash_table