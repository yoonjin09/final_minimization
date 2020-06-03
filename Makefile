main : main.c arraymin.h
	gcc -o main main.c
demain : demain.c arraymin.h
	gcc -o demain demain.c
clean :
	rm main demain
