all: program

%: %.cc
	g++ -std=c++11 $< -o $@

