# LeetCode Practice

## 项目结构

```
leetcode/
├── include/
│   ├── tree.h      # 通用依赖
│   └── solution.h # 当前题目解法声明
├── src/
│   └── solution.cpp  # 当前题目解法实现（空）
├── tests/
│   └── solution_test.cpp  # gtest 测试用例
└── .vscode/
```

## 命令 (VSCode)

- Ctrl+Shift+B → 编译 + 运行测试
- F5 → 调试测试

## 添加新题目

1. 在 `include/solution.h` 添加解法声明
2. 在 `src/solution.cpp` 添加空实现（用户自己实现）
3. 在 `tests/solution_test.cpp` 添加 gtest 用例
4. 旧题目的接口删除

## Notes

- C++17 + gtest
- 依赖: `tree.h` (TreeNode)
- 编译: `g++ -std=c++17 -g -I include src/solution.cpp tests/solution_test.cpp -o solution_test -lgtest -lgtest_main -pthread`