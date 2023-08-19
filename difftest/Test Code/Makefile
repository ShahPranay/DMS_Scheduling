CC=g++
CFLAGS=-Wall -std=c++17

all: test_1
	nohup ./test_1 1000 200 1000 "A" > test_1A.out 2>&1 & echo $$! > test_1A.pid
	nohup ./test_1 3000 350 3000 "B" > test_1B.out 2>&1 & echo $$! > test_1B.pid
	nohup ./test_1 2000 400 2000 "C" > test_1C.out 2>&1 & echo $$! > test_1C.pid
	nohup ./test_1 1500 200 1500 "D" > test_1D.out 2>&1 & echo $$! > test_1D.pid



test_1: test_1.o
	$(CC) $(CFLAGS) -o test_1 test_1.o

test_1.o: test_1.cpp
	$(CC) $(CFLAGS) -c test_1.cpp

clean:
	rm -f test_1 test_1.o program1 program2 program3 program4

run:
	 ./test_1 100 50 100 "A" & \
	 ./test_1 120 50 120 "B" & \
	 ./test_1 400 50 400 "C"

pcp: program1 program2 program3 program4
	nohup ./program1 120 1000 1000 > test_1A.out 2>&1 & echo $! > test_1A.pid & \
	nohup ./program2 300 2000 2000 > test_1B.out 2>&1 & echo $! > test_1B.pid & \
	nohup ./program3 400 1500 1500 > test_1C.out 2>&1 & echo $! > test_1C.pid & \
	nohup ./program4 650 3000 3000 > test_1D.out 2>&1 & echo $! > test_1D.pid




program1: program1.cpp
	$(CXX) $(CXXFLAGS) -o program1 program1.cpp

program2: program2.cpp
	$(CXX) $(CXXFLAGS) -o program2 program2.cpp

program3: program3.cpp
	$(CXX) $(CXXFLAGS) -o program3 program3.cpp

program4: program4.cpp
	$(CXX) $(CXXFLAGS) -o program4 program4.cpp
