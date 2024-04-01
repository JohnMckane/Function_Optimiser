all: 
	g++ *.h *.cc -g -o run
	./run
compile:
	g++ *.h *.cc -g -o run
run:
	./run
