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
    ts)
        ts
        ;;
    *)
        echo "We don't have tests in $lang yet"
        ;;
    esac
    echo "Completed test"
}

input() {
    read -p "Enter cpp, py, js, or ts: " lang
    read -a ns -p "Enter question numbers (sep by space), or all (slow): "
}

cpp() {
    cd cpp/
    if [ $ns = "all" ]; then
        make run -j8
    else
        for n in "${ns[@]}"; do
            make bin/test_$n
            bin/test_$n
        done
    fi
}

py() {
    if [ $ns = "all" ]; then
        pytest python/tests/ -s
    else
        for n in "${ns[@]}"; do
            pytest python/tests/test_$n.py -s
        done
    fi
}

js() {
    if [ $ns = "all" ]; then
        node --test javascript/test/test_*
    else
        for n in "${ns[@]}"; do
            node --test javascript/test/test_$n.js
        done
    fi
}

ts() {
    if [ $ns = "all" ]; then
        npx ts-node typescript/test/test_*
    else
        for n in "${ns[@]}"; do
            npx ts-node typescript/test/test_$n.ts
        done
    fi
}

main
