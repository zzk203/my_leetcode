# cpp-algo-practice — Agent Guide

## Project Overview

A generic C++ practice project supporting two problem modes:

- **LeetCode mode**: user implements a `Solution` class method; agent generates data structures (`*.ai.h`) and gtest cases.
- **OJ mode**: user implements a function/method; agent generates gtest cases that simulate I/O (stringstream → parse → call → serialize → compare).

**Key rule**: only ONE problem lives in the repo at any time. When adding a new problem, all old solution/test files must be replaced.

## File Structure

```
leetcode/
├── Makefile                 # Auto-discovers src/*.cpp + tests/*.cpp
├── include/
│   ├── solution.h           # Agent-generated declarations
│   ├── tree.ai.h            # Agent-generated TreeNode
│   ├── list.ai.h            # Agent-generated ListNode
│   └── node.ai.h            # Agent-generated graph/N-ary Node
├── src/
│   └── solution.cpp         # Agent-generated stub → user fills in
├── tests/
│   └── solution_test.ai.cpp # Agent-generated gtest cases
├── .vscode/
│   ├── tasks.json           # Build (make) & run tasks
│   └── launch.json          # F5 debug
├── AGENTS.md                # This file
├── README.md                # English user docs
└── README.zh.md             # Chinese user docs
```

## When User Says "Implement problem X" (Agent Workflow)

Follow these steps **in order**:

### Step 1: Identify Problem

- If user provides a URL, fetch it to read the problem description.
- If user provides a problem title/number, determine the source platform (LeetCode / OJ).
- Read the problem statement carefully: constraints, input format, output format, examples.

### Step 2: Determine Mode

- **LeetCode**: problem provides a class API (`Solution` with method signature). The user only writes the method body.
- **OJ**: problem expects a full program reading stdin and writing stdout. Map the I/O format to a function signature for `solution.cpp`.

### Step 3: Clean Old Files

Remove all existing declarations and implementations:

```bash
# Overwrite include/solution.h with new content
# Overwrite src/solution.cpp with new stub
# Overwrite tests/solution_test.ai.cpp with new test cases
```

Do NOT delete `Makefile`, `.gitignore`, `AGENTS.md`, `README.md`, `README.zh.md`, `.vscode/`.

### Step 4: Generate Data Structures (if needed)

For LeetCode problems, check which data structures the problem uses:

| Structure | File | Content |
|---|---|---|
| Binary tree node | `include/tree.ai.h` | `struct TreeNode { int val; TreeNode *left, *right; }` |
| Linked list node | `include/list.ai.h` | `struct ListNode { int val; ListNode *next; }` |
| Graph / N-ary node | `include/node.ai.h` | `struct Node { int val; vector<Node*> neighbors; }` |

Only generate the `.ai.h` files that the current problem actually needs. Do not generate unused files.

For OJ problems, data structures are typically not needed (or should be defined in `solution.h` directly if internal).

### Step 5: Generate `include/solution.h`

- Write the `#ifndef` guard, `#include` necessary headers.
- Declare the class/function.
- Include `tree.ai.h`, `list.ai.h`, `node.ai.h` only if the signature uses those types.

```cpp
#ifndef CPP_ALGO_SOLUTION_H
#define CPP_ALGO_SOLUTION_H

#include <vector>
#include "tree.ai.h"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum);
};

#endif
```

### Step 6: Generate `src/solution.cpp`

- Include `"solution.h"`.
- Implement each method with a **stub body** that compiles but returns a default value (`return {}` / `return false` / `return 0` / `return nullptr`).

```cpp
#include "solution.h"

bool Solution::hasPathSum(TreeNode* root, int targetSum) {
    return false;
}
```

### Step 7: Generate `tests/solution_test.ai.cpp`

- Use Google Test framework.
- Include `"solution.h"`.
- Write **at least 5 test cases** covering:

| Test type | Example |
|---|---|
| Basic happy path | Example 1 from problem |
| Edge case | Empty input, single element, extreme values |
| Boundary | Minimum/maximum constraints |
| Negative case | Not found, false condition |
| Complex case | Larger input, stress within constraints |

- **Must respect problem constraints**: do not create inputs that violate the problem's node count, value range, or structure requirements.
- For **LeetCode mode**: construct inputs and assert return values directly.
- For **OJ mode**: construct input strings, parse via a helper similar to the problem's I/O, call the solution, serialize result, and compare with expected output string.

```cpp
#include <gtest/gtest.h>
#include "solution.h"

TEST(HasPathSumTest, BasicCase) {
    // Build tree [5,4,8,11,null,13,4,null,null,null,null,null,1]
    TreeNode n1(5);
    // ... build tree ...
    Solution s;
    EXPECT_TRUE(s.hasPathSum(&n1, 22));
}

TEST(HasPathSumTest, EmptyTree) {
    Solution s;
    EXPECT_FALSE(s.hasPathSum(nullptr, 0));
}
```

### Step 8: Verify

1. Run `make clean && make && ./solution_test` — all tests must pass.
2. If tests fail, debug the generated test code (not the stub — the stub is intentionally empty).
3. Once all tests pass, **delete the correct implementation** from `solution.cpp` and leave only the stub. The user will fill it in.

## Notes

- **Never** modify `Makefile`, `.vscode/`, `README*`, `AGENTS.md` unless explicitly asked.
- **Never** delete `*.ai.h` files that other problems might need — but since we keep only one problem at a time, it's safe to overwrite. If a data structure is no longer needed, it should still remain (it doesn't hurt).
- **Test files must be self-contained**: no external test data files.
- **Compilation**: `make clean && make && ./solution_test`
- **Formatting**: use consistent indentation (2 or 4 spaces). No trailing whitespace.
- **C++ standard**: C++17.
- **Memory**: when building trees/lists in test cases, allocate with `new`. Tests are short-lived so leaks are acceptable in test code.
