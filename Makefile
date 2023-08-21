CC = g++ -std=c++17 -g
CFLAGS = -Wall -Werror -Wextra
TESTSFLAGS_MAC = -lgtest -lgtest_main
SOURCE = Model/*.cc View/*.cc Controller/*.cc View/Form/*.cc View/MSEgraph/*.cc View/Statuswindow/*.cc View/Worker/*.cc
SOURCE_H = Model/*.h View/*.h Controller/*.h View/Form/*.h View/MSEgraph/*.h View/Statuswindow/*.h View/Worker/*.h
SOURCE_UI = View/*.ui View/Statuswindow/*.ui View/MSEgraph/*.ui
DOCUMENTATION = ../documentation
UNAME = $(shell uname)

OPEN :=

ifeq ($(UNAME), Linux)
	OPEN += xdg-open
endif

ifeq ($(UNAME), Darwin)
	OPEN += open
endif

all: install

clang-format:
	@clang-format -style=google -i $(SOURCE) $(SOURCE_H)

style:
	@clang-format -style=google -n $(SOURCE) $(SOURCE_H)

check-time:
	@g++ Model/test_main.cc Model/model.cc Model/fastmatrix.cc Model/reader.cc Model/matrixnetwork.cc Model/graphnetwork.cc Model/neuralnetwork.cc   -Ofast -march=native -flto
	@time ./a.out
	@rm a.out

dvi:
	@doxygen Doxyfile
	@$(OPEN) $(DOCUMENTATION)/html/index.html


install:
	@cmake -S . -B build && cd build/ && make -j3

open:
	@cd build/ && ./CPP7_MLP-2

uninstall:
	@rm -rf build/

dist:
	mkdir MLP
	@cp -r $(SOURCE) $(SOURCE_H) $(SOURCE_UI) Makefile Tests/ Doxyfile MLP
	tar -cvzf dist.tar.gz MLP
	@-rm -rf MLP



tests:
	@g++ Tests/test.cc Controller/*.cc Model/*.cc $(TESTSFLAGS_MAC)  -Ofast -flto  -o test
	@./test
	@rm test

main:
	@$(CC) Controller/*.cc Model/*.cc Model/*.h -Ofast -flto -o test
	@lea ./test
	@rm test

clean:
	@rm -rf *.o test *.a *.gcno *.gcda *.gcov *.html *.css *.out *.info report build html dist.tar.gz test.dSYM MLP

rebuild: clean all

.PHONY: tests clang-format install
