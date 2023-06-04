# How to run

Let $n$ be the question number

## C++

```shell
cd cpp/
make bin/test_n
bin/test_n
```

To compile and run all tests:

```shell
cd cpp/
make run -jc # c is number of cores to run in parallel, speeds up significantly
```

## Python

## Shell

`-s` flag is optional, it shows timing for each individual test.

```shell
pytest python/tests/test_n.py -s
```

To run all tests:

```shell
pytest python/tests -s
```

## JetBrains (PyCharm, IntelliJ IDEA, etc)

Follow steps outlined [here](https://www.jetbrains.com/help/pycharm/pytest.html#create-pytest-test).

## JavaScript

```shell
node --test javascript/test/test_n.js
```

To run all tests:

```shell
node --test javascript/test
```
