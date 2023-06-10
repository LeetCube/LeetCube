SRCS_DIR = src
SRCS = $(wildcard $(SRCS_DIR)/code_*.cpp)
TESTS_DIR = test
TESTS = $(subst $(SRCS_DIR)/code, $(TESTS_DIR)/test, $(SRCS))
BUILD_DIR = build
BIN_DIR = bin
OUT = $(subst $(TESTS_DIR)/, $(BIN_DIR)/, $(basename $(TESTS)))
ALL_FILES = $(SRCS)
ALL_FILES += $(TESTS)

CXX = clang++
CXXFLAGS = -std=c++17 -g -O2 -march=native -Wall -Wextra -Werror -pedantic -fsanitize=address -fsanitize=undefined
DOCTEST_CXXFLAGS = -std=c++17 -c -g -Ofast -march=native -Wall -Wextra -Werror -pedantic -fsanitize=address -fsanitize=undefined

all: $(OUT)

run: $(OUT)
	@for t in $(OUT); do ./$$t; done

$(BUILD_DIR)/doctest_config.o: $(TESTS_DIR)/cpp_deps/doctest_config.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(DOCTEST_CXXFLAGS) $^ -o $@

$(OUT): $(BIN_DIR)/test_%: $(SRCS_DIR)/code_%.cpp $(TESTS_DIR)/test_%.cpp $(BUILD_DIR)/doctest_config.o
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

ifeq (clang_tidy, $(firstword $(MAKECMDGOALS)))
    ifeq (1, $(words $(MAKECMDGOALS)))
        TIDY_COMMAND = find . -iname *.cpp -exec sh -c 'clang-tidy --config="" "$$1"' -- {} \;
    else
        TIDY_RUN_ARGS = $(wordlist 2, $(words $(MAKECMDGOALS)), $(MAKECMDGOALS))
        $(eval $(TIDY_RUN_ARGS):;@:)
        TIDY_COMMAND = find . -iname $(TIDY_RUN_ARGS) -exec sh -c 'clang-tidy --config="" "$$1"' -- {} \;
    endif
endif

clang_tidy:
	$(TIDY_COMMAND)

ifeq (clang_format, $(firstword $(MAKECMDGOALS)))
    ifeq (1, $(words $(MAKECMDGOALS)))
        FORMAT_COMMAND = find . -iname *.cpp | xargs clang-format -style=file -i
    else
        FORMAT_RUN_ARGS = $(wordlist 2, $(words $(MAKECMDGOALS)), $(MAKECMDGOALS))
        $(eval $(FORMAT_RUN_ARGS):;@:)
        FORMAT_COMMAND = find . -iname $(FORMAT_RUN_ARGS) | xargs clang-format -style=file -i
    endif
endif

clang_format:
	$(FORMAT_COMMAND)

.PHONY: all clean clang_tidy clang_format
