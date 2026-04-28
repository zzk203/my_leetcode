# cpp-algo-practice — Agent Guide

Only ONE problem lives in the repo at a time. When adding a new problem, ALL old solution/test files are overwritten.

## File Layout

```
.
├── Makefile                 # wildcard auto-discovery: src/*.cpp + tests/*.cpp
├── .gitignore               # *.ai.h / *.ai.cpp are gitignored (regenerated each time)
├── include/
│   ├── solution.h           # Declarations — agent-generated, user-facing
│   ├── tree.ai.h            # TreeNode (generate on demand)
│   ├── list.ai.h            # ListNode (generate on demand)
│   └── node.ai.h            # Graph/N-ary Node (generate on demand)
├── src/
│   └── solution.cpp         # Stub → user fills in the body
├── tests/
│   └── solution_test.ai.cpp # gtest cases
├── .vscode/
│   ├── tasks.json
│   └── launch.json
└── README.md / README.zh.md
```

Do NOT modify `Makefile`, `.gitignore`, `AGENTS.md`, `README*`, `.vscode/`.

## Naming: `.ai.*` vs plain

| File | Git tracked? | Editable by user |
|---|---|---|
| `solution.h` | Yes | No (reads sig only) |
| `solution.cpp` | Yes | **Yes — implements logic** |
| `*.ai.h` / `*.ai.cpp` | No (gitignored) | No (AI-only, regenerated) |

`solution.h` deliberately omits the `.ai` suffix so it stays git-tracked. The `.ai.*` convention marks files that are fully regenerated and gitignored.

## Mode

- **LeetCode**: `Solution` class with a method in `solution.h`. User fills the body in `solution.cpp`.
- **OJ**: I/O-based problem mapped to a function signature; tests simulate stdin/stdout via stringstream.

## Workflow: Agent Generates a Problem

1. **Identify**: fetch URL or use problem title/number. Read constraints and examples.
2. **Clean**: overwrite `solution.h`, `solution.cpp`, `solution_test.ai.cpp`. Delete old content; generate fresh.
3. **Data structures**: generate only the `.ai.h` files the problem needs (tree / list / node).
4. **`solution.h`**: `#ifndef` guard, `#include` needed headers and `.ai.h` files, declare class/function.
5. **`solution.cpp`**: write the **full correct implementation** (needed to verify tests pass).
6. **`solution_test.ai.cpp`**: ≥5 gtest cases — happy path, edge, boundary, negative, complex. Use `new` for tree/list nodes (leaks OK in tests).
7. **Verify + Reset** (do NOT skip reset):
   a. `make clean && make && ./solution_test` — all tests must pass.
   b. **Immediately** overwrite `solution.cpp` with a stub (`return false / 0 / nullptr / {}`).
   c. Confirm stub still compiles: `make clean && make`.

## Key Constraints

- C++17, `g++`, Google Test (`-lgtest -lgtest_main -pthread`).
- `solution.h` / `solution.cpp` are git-tracked; `*.ai.*` files are gitignored.
- Test `#include` only `"solution.h"`. Use `#include <gtest/gtest.h>`.
- Tests must be self-contained — no external data files.
- Memory leaks from `new` in tests are acceptable.
