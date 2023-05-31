# Formatting

Before uploading your code, please format it with a code formatter.

Definition from [freeCodeCamp](https://www.freecodecamp.org/news/using-prettier-and-jslint/)

> Code formatters are automated tools that help you format source code _automatically_. The main purpose of code formatters is to standardize the formatting of code across a project or team, making it **easier to read and understand code**.

## Editor

1. Auto format when you save the file
   ![](/doc/figs/format_editor.png)
2. Auto add only 1 newline
   ![](/doc/figs/format_newline.png)
3. Can also use keyboard shortcut `shift + option + f` to format file

## C++

`blank` uses the following formatting style, in conjunction with VSCode's formatter that ships with the C++ extension by default (add the following to the `C_Cpp: Clang_format_fallback Style` and `C_Cpp: Clang_format_style` settings in VSCode):

```js
{ BasedOnStyle: Google, UseTab: Never, IndentWidth: 4, AllowShortIfStatementsOnASingleLine: AllIfsAndElse, ColumnLimit: 150, DerivePointerAlignment: false, PointerAlignment: Left, AllowShortBlocksOnASingleLine: Always, AllowShortFunctionsOnASingleLine: All, AllowShortLoopsOnASingleLine: true, FixNamespaceComments: false, AccessModifierOffset: -4}
```

## Python

`annie` uses [black](https://github.com/psf/black).

- To install, use `pip install black`. VSCode doesn't have black pre-installed, even though it shows black as an option.

- To run on 1 file, use `shift + option + f`

- To bulk run, use `black {source_file_or_directory}`. Best to do a final check with

```shell
black src/python/
black test/python/
```

Output e.g.
![](/doc/figs/format_black.png)

## JS and Markdown

`annie` uses [prettier](https://prettier.io/).

- To install, search for prettier in VSCode extension. Then you are all set!
  ![](/doc/figs/format_prettier.png)

## Test cases JSON

Upload to the `test/test_json` directory. Format:

```
[
    {
        "contributor": ...,
        "input": {
            "input1": ...,
            ...
        },
        "output": ...
    },
    ...
]
```

Input names should match the argument/example input parameter names. Given test cases (examples) have `"given"` as contributor.

If the problem allows the answer to be returned in any order, or similar:

- sort each entry in the output list, if necessary (list of lists)
- sort the entire output list
- add the **sorted** answer in JSON, and add code to sort the result in the test file. (see [`test/cpp/test_17.cpp`](../test/cpp/test_17.cpp), [`test/test_json/test_17.json`](../test/test_json/test_17.json))

If multiple correct answers:

- add a **list** of all correct answers in JSON, and add code to check that the result is in said list in the test file. (see [`test/cpp/test_5.cpp`](../test/cpp/test_5.cpp), [`test/test_json/test_5.json`](../test/test_json/test_5.json))
