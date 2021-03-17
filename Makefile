hash_table: src/hash_table.c src/hash_table.h
	gcc -lm src/hash_table.c -o hash_table

.PHONY: clean
clean:
	rm -f hash_table