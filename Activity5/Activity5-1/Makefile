all: send receiver

send: send.c 
	gcc -o send.out send.c -lrt
	
receiver: receiver.c 
	gcc -o receiver.out receiver.c -lrt
	
runreceiver:
	./receiver.out

runsend:
	./send.out

clean:
	rm -rf *.out *.o