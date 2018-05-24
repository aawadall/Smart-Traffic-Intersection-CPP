all: simulate

simulate: main.o environment.o agent.o q-agent.o
	g++ main.o environment.o agent.o q-agent.o -o bin/simulate

main.o: main.cc
	g++ -std=c++11 -c main.cc

environment.o: environment.cc
	g++ -std=c++11 -c environment.cc

agent.o: agent.cc
	g++ -std=c++11 -c agent.cc

q-agent.o: q-agent.cc
	g++ -std=c++11 -c q-agent.cc