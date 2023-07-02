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
    json)
        format_prettier "data"
        ;;
    *)
        echo We don\'t have format in $lang yet
        ;;
    esac
}

input() {
    read -p "Enter py, js, ts, or json: " lang
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
        if [ $lang != "json" ]; then
            files = ("src/code" "test/test")
        else
            files = ("testcases/test")
        fi
        for f in "${files[@]}"; do
            for n in "${ns[@]}"; do
                npx prettier --write --tab-width 4 $1/$f_$n.$lang
            done
        done
    fi
}

main
