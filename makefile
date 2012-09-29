CC = g++
CFLAGS = -Wall -lrt -pthread -g -O0
SOURCES_FILES =	exception.cc
OBJECT_FILES := $(patsubst %.cc,%.o,$(SOURCES_FILES))

all: prog handle_exception
	
prog: $(OBJECT_FILES) 
	mkdir -p bin
	$(CC) $(CFLAGS) $(addprefix obj/,$(OBJECT_FILES)) src/prog.cc -o bin/prog

handle_exception:
	mkdir -p bin/samples
	$(CC) $(CFLAGS) $(addprefix obj/,$(OBJECT_FILES)) samples/handle_exception.cc -o bin/samples/handle_exception

%.o: src/%.cc
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o obj/$@

test:
	valgrind --leak-check=yes ./bin/prog

clean:
	rm -rf bin
	rm -rf obj
