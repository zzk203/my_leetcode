# LeetCode C++ Practice

My personal LeetCode practice project using C++17 and gtest.

## Project Structure

```
leetcode/
├── include/           # Headers (tree.h, solution.h)
├── src/              # Solution implementations
├── tests/            # gtest test cases
├── .vscode/          # VSCode config
└── .gitignore
```

## Build & Test

```bash
g++ -std=c++17 -g -I include src/solution.cpp tests/solution_test.cpp -o solution_test -lgtest -lgtest_main -pthread
./solution_test
```

Or use VSCode:
- Ctrl+Shift+B → Build & Run
- F5 → Debug

## Current Problem

- LeetCode 101: Symmetric Tree