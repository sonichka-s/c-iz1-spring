build:
	 mkdir build && cd build && cmake .. && cmake --build . && make

run:
	./build/src/main

run-tests:
	./build/tests

generate-lcov:
	lcov --coverage --directory=coverage --output-file=coverage.info

generate-coverage-html:
	genhtml coverage.info --output-directory=coverage-output

get-coverage:
	mkdir coverage && mkdir coverage_output && make generate-lcov && make generate-coverage-html

get-all-coverage:
	make get-coverage

