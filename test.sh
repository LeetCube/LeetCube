#!/bin/bash

main() {
    input
    case $lang in
    cpp)
        cpp
        ;;
    py)
        py
        ;;
    js)
        js
        ;;
    *)
        echo we don\'t have tests in $lang yet
        ;;
    esac
}

input() {
    read -p "Enter cpp, js, or py: " lang
    read -p "Enter question number, or all: " n
}

cpp() {
    cd cpp/
    if [ $n = "all" ]; then
        make run -j8
    else
        make bin/test_$n
        bin/test_$n
    fi
}

py() {
    if [ $n = "all" ]; then
        pytest python/tests/ -s
    else
        pytest python/tests/test_$n.py -s
    fi
}

js() {
    if [ $n = "all" ]; then
        node --test javascript/tests/test_*
    else
        node --test javascript/tests/test_$n.js
    fi
}

main
