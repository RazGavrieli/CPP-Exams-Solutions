CC = clang++-9 -std=c++2a

all: Q1 Q2 Q3 Q4 Q5 Q6 Q7

Q1: Q1.cpp
	$(CC) Q1.cpp -o Q1
Q2: Q2.cpp
	$(CC) Q2.cpp -o Q2
Q3: Q3.cpp
	$(CC) Q3.cpp -o Q3
Q4: Q4.cpp XX.cpp
	$(CC) Q4.cpp XX.cpp -o Q4
Q5: Q5.cpp
	$(CC) Q5.cpp -o Q5
Q6: Q6.cpp
	$(CC) Q6.cpp -o Q6
Q7: Q7.cpp RunningAverage.cpp
	$(CC) Q7.cpp RunningAverage.cpp -o Q7

clean:
	rm -f Q1 Q2 Q3 Q4 Q5 Q6 Q7 a.out