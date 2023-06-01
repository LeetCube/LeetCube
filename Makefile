SRCS_DIR = src/cpp
TESTS_DIR = test/cpp
TESTS = $(subst src/cpp/code, test/cpp/test, $(wildcard $(SRCS_DIR)/code_*.cpp))
BUILD_DIR = build
BIN_DIR = bin
OUT = $(subst $(TESTS_DIR), $(BIN_DIR), $(basename $(TESTS)))

CXX = clang++
CXXFLAGS = -std=c++17 -g -O2 -march=native -Wall -Wextra -Werror -pedantic -fsanitize=address -fsanitize=undefined
DOCTEST_CXXFLAGS = -std=c++17 -c -g -Ofast -march=native -Wall -Wextra -Werror -pedantic -fsanitize=address -fsanitize=undefined

all: $(OUT)

run: $(OUT)
	@for t in $(OUT); do ./$$t; done

$(BUILD_DIR)/doctest_config.o: $(TESTS_DIR)/cpp_deps/doctest_config.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(DOCTEST_CXXFLAGS) $^ -o $@

$(OUT): $(BIN_DIR)/test_%: $(SRCS_DIR)/code_%.cpp $(TESTS_DIR)/test_%.cpp $(TESTS_DIR)/cpp_deps/boilerplate.cpp $(BUILD_DIR)/doctest_config.o
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean