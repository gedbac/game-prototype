CC = g++
CFLAGS = -Wall -lrt -pthread -g -O0
SOURCES_FILES =	exception.cc \
								testing/assertion_exception.cc \
								testing/assert.cc
OBJECT_FILES = $(patsubst %.cc,%.o,$(SOURCES_FILES))

all: build-prog build-test handle_exception
	
build-prog: bin-dir $(OBJECT_FILES) 
	$(CC) $(CFLAGS) $(addprefix obj/,$(OBJECT_FILES)) src/prog.cc -o bin/prog

prog:
	./bin/prog

build-test: bin-dir $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(addprefix obj/,$(OBJECT_FILES)) tests/test.cc -o bin/test

test:
	./bin/test

handle_exception:
	mkdir -p bin/samples
	$(CC) $(CFLAGS) $(addprefix obj/,$(OBJECT_FILES)) samples/handle_exception.cc -o bin/samples/handle_exception

%.o: src/%.cc obj-dir
	$(CC) $(CFLAGS) -c $< -o obj/$@

testing/%.o: src/testing/%.cc obj-dir
	mkdir -p ./obj/testing
	$(CC) $(CFLAGS) -c $< -o obj/$@

bin-dir:
	mkdir -p bin

obj-dir:
	mkdir -p obj

profile:
	valgrind --leak-check=yes ./bin/prog

clean:
	rm -rf bin
	rm -rf obj
