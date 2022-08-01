dev:fonction.c main.c fonction.h
	gcc -o dev main.c fonction.c
run:
	./dev
clean:
	rm dev