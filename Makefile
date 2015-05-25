all: publisher subscriber

%: %.cc
	g++ -std=c++11 $< -o $@

