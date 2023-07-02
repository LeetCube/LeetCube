#!/bin/bash

main() {
    input
    case $lang in
    py)
        format_black
        ;;
    js)
        format_prettier "javascript"
        ;;
    ts)
        format_prettier "typescript"
        ;;
    *)
        echo We don\'t have format in $lang yet
        ;;
    esac
    testcases
}

input() {
    read -p "Enter py, js, or ts: " lang
    read -a ns -p "Enter question numbers (sep by space), or all (slow): "
}

format_black() {
    if [ $ns = "all" ]; then
        python -m black python/
    else
        for n in "${ns[@]}"; do
            python -m black python/src/code_$n.py
            python -m black python/tests/test_$n.py
        done
    fi
}

format_prettier() {
    if [ $ns = "all" ]; then
        npx prettier --write $1
    else
        for n in "${ns[@]}"; do
            npx prettier --write $1/src/code_$n.$lang
            npx prettier --write $1/test/test_$n.$lang
        done
    fi
}

testcases() {
    if [ $ns = "all" ]; then
        npx prettier --write data/testcases/
    else
        for n in "${ns[@]}"; do
            npx prettier --write data/testcases/test_$n.json
        done
    fi
}

main
