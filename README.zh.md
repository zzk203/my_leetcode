# My LeetCode Practice

> [English Version](./README.md)

一个 C++17 项目，用于练习算法题（LeetCode、OJ 等）。

## 工作原理

**你只需要写题解逻辑。** 其余一切——声明、数据结构、测试用例——都由 AI agent（opencode）自动生成。

```
用户: "帮我实现 LeetCode 112 题 路径总和"
Agent: →  include/solution.h    （声明）
       →  include/tree.ai.h    （TreeNode 结构）
       →  src/solution.cpp     （空壳，你来填充）
       →  tests/solution_test.ai.cpp （测试用例）

用户: 编辑 src/solution.cpp → 实现方法
      Ctrl+Shift+B           → 编译并运行测试
      F5                     → 调试
```

## 快速开始

### 1. 告诉 Agent

```bash
# 在 opencode 中：
帮我实现 LeetCode 112 题 路径总和
```

Agent 会自动生成所有必要文件。

### 2. 写题

打开 `src/solution.cpp`，实现你的解法。

### 3. 编译、运行与调试

| 操作 | 快捷键 | 效果 |
|---|---|---|
| **仅编译** | `Ctrl+Shift+B` → 选 "build_lc" | `make` → 生成 `solution_test` |
| **编译并运行** | `Ctrl+Shift+B` → 选 "run_lc" | `make` → `./solution_test` |
| **调试** | `F5` | `make` → 启动 GDB 调试 `solution_test` |

## 文件命名规则

- `*.ai.*` — AI 生成的文件。**请勿手动编辑。** 生成新题目时会被覆盖。
- `solution.h` / `solution.cpp` — 用户接口。声明由 Agent 生成，实现由你完成。
- 其余文件 — 项目基础设施。

## 支持的题目平台

- **LeetCode** — 实现 `Solution` 类方法。Agent 自动生成数据结构（`TreeNode`、`ListNode` 等）和 gtest 测试用例。
- **OJ 平台**（POJ、Codeforces 等）— 将题目的 I/O 映射为函数签名。Agent 生成模拟标准输入输出的 gtest 测试用例。
