all: simulate

simulate: main.o environment.o agent.o
	g++ main.o environment.o agent.o -o bin/simulate

environment.o: environment.cc
	g++ -std=c++11 -c environment.cc

agent.o: agent.cc
	g++ -std=c++11 -c agent.cc

main.o: main.cc
	g++ -std=c++11 -c main.cc