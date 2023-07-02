# Formatting

Before uploading your code, please format it with a code formatter.

Definition from [freeCodeCamp](https://www.freecodecamp.org/news/using-prettier-and-jslint/)

> Code formatters are automated tools that help you format source code _automatically_. The main purpose of code formatters is to standardize the formatting of code across a project or team, making it **easier to read and understand code**.

**Note: please keep function signatures as they are on LeetCode**.

## Editor

1. Auto format when you save the file
   ![](figs/format_editor.png)
2. Auto add only 1 newline
   ![](figs/format_newline.png)
3. Can also use keyboard shortcut `shift + option + f` to format file

## C++

`blank` uses Google-style formatting, with a few custom options. A [.clang-format](../cpp/.clang-format) file with said options is provided. A [.clang-tidy](../cpp/.clang-tidy) file is also provided.

See the [Makefile](../cpp/Makefile) for the compilation options. In particular, note that the C++ version is **C++17**.

If you have `clang-format` installed, you can run `make clang_format [optional filename(s) glob here]` to format the files according to the `.clang-format` file. Rules are subject to change.

If you have `clang-tidy` installed, you can run `make clang_tidy [optional filename(s) glob here]` to run the `clang-tidy` linter according to the `.clang-tidy` file. Rules are subject to change. If you want to disable linting for a block of code, add `// NOLINTBEGIN` and `// NOLINTEND` around it.

## Python

`any` uses [black](https://github.com/psf/black).

-   To install, use `pip install black`. VSCode doesn't have black pre-installed, even though it shows black as an option.

-   To run on 1 file, use `shift + option + f`

-   To bulk run, use `python -m black {source_file_or_directory}`.

Output e.g.
![](figs/format_black.png)

## JS, TS, JSON, and Markdown

`annie` uses [prettier](https://prettier.io/).

-   To install, search for prettier in VSCode extension. Then you are all set!
    ![](figs/format_prettier.png)

-   To run on 1 file, use `shift + option + f`

-   To bulk run, use `npx prettier --write {source_file_or_directory}`.

## Test cases JSON

Upload to the `data/testcases` directory. Format:

```
[
    {
        "contributor": ...,
        "comments": ...,
        "input": {
            "input1": ...,
            ...
        },
        "output": ...
    },
    ...
]
```

### Input

Input names should match the argument/example input parameter names. Given test cases (examples) have `"given"` as contributor. Besides given test cases, if you created custom or failed lc's extra test cases, put `"your name"` as contributor.

For JS and TS, if the input is a function

```
fn = function () {
    ...
}
```

-   We need `fn` as a single-line string, to be compatible with JSON, but `fn` is currently multi-line.
-   We can use [tools/format_helpers.js](tools/format_helpers.js). Init the string `s`, and run the script.

```shell
node tools/format_helpers.js
```

-   Copy the string from terminal.
-   Use it like `eval(test_case.input.fn);`

### Comments

The field `"comments"` is an optional field for general comments. It can
include, but is not limited to, a description of the test case or an
explanation on why the input results in such output. For example,

-   `"comments": "this test case checks large inputs"` In this case, the comment describes the test case.
-   `"comments": "\"aba\" is also a valid answer."` in this case, the comment describes why a certain input results in a certain output. This is similar
    to the "explanation" that comes with LeetCode examples.

### Answer

If the problem allows the answer to be returned in any order, or similar:

-   sort each entry in the output list, if necessary (list of lists)
-   sort the entire output list
-   add the **sorted** answer in JSON, and add code to sort the result in the test file. (see [`test_17.cpp`](../cpp/test/test_17.cpp), [`test_17.json`](../data/testcases/test_17.json))

If multiple correct answers:

-   add a **list** of all correct answers in JSON, and add code to check that the result is in said list in the test file. (see [`test_5.cpp`](../cpp/test/test_5.cpp), [`test_5.json`](../data/testcases/test_5.json))
