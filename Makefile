all: simulate

simulate: main.o environment.o agent.o q-agent.o
	g++ main.o environment.o agent.o q-agent.o -o bin/simulate

main.o: main.cc
	g++ -std=c++11 -c main.cc

environment.o: environment.cc environment.h
	g++ -std=c++11 -c environment.cc

agent.o: agent.cc agent.h
	g++ -std=c++11 -c agent.cc 

q-agent.o: q-agent.cc q-agent.h
	g++ -std=c++11 -c q-agent.cc
	
clean: 
	rm -f *.o 