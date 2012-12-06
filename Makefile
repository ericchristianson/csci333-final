CPP =  g++
CFLAGS = -Wall -Werror -Wextra

make: clean nn twitter

nn: nn.cpp
	$(CPP) $(CFLAGS) -o nn nn.cpp

twitter: twitter.cpp
	$(CPP) $(CFLAGS) -o twitter twitter.cpp

clean:
	rm -f *~;
	rm -f nn;
	rm -f twitter;
	rm -f orderedWords;
	rm -f analysis;
