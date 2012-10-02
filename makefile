CC = g++
CFLAGS = -Wall -lrt -pthread -g -O0
SOURCES_FILES =	exception.cc \
								testing/assertion_exception.cc \
								testing/assert.cc \
								testing/test_run_results.cc \
								testing/test_fixture.cc \
								testing/test_suite.cc
OBJECT_FILES = $(patsubst %.cc,%.o,$(SOURCES_FILES))
TEST_SOURCES_FILES = game_test_suite.cc \
									 	 exception_tests.cc	 
TEST_OBJECT_FILES = $(patsubst %.cc,%.o,$(TEST_SOURCES_FILES))

all: build-prog build-test

build-prog: bin-dir $(OBJECT_FILES) 
	$(CC) $(CFLAGS) $(addprefix obj/,$(OBJECT_FILES)) src/prog.cc -o bin/prog

prog:
	./bin/prog

leak-check-prog:
	valgrind --leak-check=yes ./bin/prog

build-test: bin-dir $(OBJECT_FILES) $(TEST_OBJECT_FILES)
	$(CC) $(CFLAGS) $(addprefix obj/,$(OBJECT_FILES)) $(addprefix obj/,$(TEST_OBJECT_FILES)) tests/test.cc -o bin/test

test:
	./bin/test

leak-check-test:
	valgrind --leak-check=yes ./bin/test

%.o: src/%.cc obj-dir
	$(CC) $(CFLAGS) -c $< -o obj/$@

testing/%.o: src/testing/%.cc obj-dir
	mkdir -p ./obj/testing
	$(CC) $(CFLAGS) -c $< -o obj/$@

%.o: tests/%.cc obj-dir
	mkdir -p ./obj/tests
	$(CC) $(CFLAGS) -c $< -o obj/$@

bin-dir:
	mkdir -p bin

obj-dir:
	mkdir -p obj

clean:
	rm -rf bin
	rm -rf obj
