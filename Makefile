build:
	 mkdir build && cd build && cmake --build .. && make

run:
	./build/src/main

run-tests:
	./build/tests

valgrind-install:
	sudo apt-get install valgrind

valgrind-check:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --undef-value-errors=no --verbose --log-file=$(filename)  $(directory)

valgrind:
	mkdir valgrind_output && make valgrind-check directory=./build/tests filename=valgrind_output/report

valgrind-check-tests:
	make valgrind-check directory=./build/tests filename=valgrind_output/storage_report

valgrind-check-all:
	mkdir valgrind_output && make valgrind-check-tests