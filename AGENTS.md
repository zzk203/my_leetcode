# LeetCode Practice

## 项目结构

```
leetcode/
├── include/
│   ├── tree.ai.h    # AI 生成（TreeNode）
│   └── solution.h  # 解法声明（用户修改）
├── src/
│   └── solution.cpp  # 解法实现（用户修改）
├── tests/
│   └── solution_test.ai.cpp  # AI 生成（测试用例）
└── .vscode/
```

## 命令 (VSCode)

- Ctrl+Shift+B → 编译 + 运行测试
- F5 → 调试测试

## 添加新题目

1. 在 `include/solution.h` 添加解法声明
2. 在 `src/solution.cpp` 添加空实现
3. 在 `tests/solution_test.ai.cpp` 添加 gtest 用例
4. 旧题目的接口删除

## 测试用例验证流程

1. 先实现正确解法
2. 编译运行，确认所有测试通过
3. 删除正确解法，保留空实现
4. 用户实现解法后验证

## Notes

- C++17 + gtest
- 编译: `g++ -std=c++17 -g -I include src/solution.cpp tests/solution_test.ai.cpp -o solution_test -lgtest -lgtest_main -pthread`