#!/bin/bash
echo -n "Enter either question number, or all: "
read n

if [ $n == "all" ]
then
node --test javascript/tests/test_*
else
node --test javascript/tests/test_$n.js
fi
