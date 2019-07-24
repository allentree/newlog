objects = main.o log_process.o

main: $(objects)
#	gcc -o main main.c $(objects)
	gcc -o main  $(objects)

log_process.o:
main.o:

clean :
	rm main  $(objects)
