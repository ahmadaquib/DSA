# DSA

C++ DSA practice repo — Striver's A2Z Sheet + LeetCode solutions.

## LeetCode

[![LeetCode Stats](https://leetcard.jacoblin.cool/IronSyntax)](https://leetcode.com/u/IronSyntax/)

*18 problems solved on-platform so far. The `LeetCode/` folder here is currently empty — problems get added as they're re-solved in C++ and committed via the manual workflow (see [Sub-repos](#-sub-repos) below), not auto-synced from the cards above.*

## Striver's A2Z Sheet

![Overall](https://img.shields.io/badge/Overall-54%2F474_(11.4%25)-3b82f6?style=for-the-badge)

![Easy](https://img.shields.io/badge/Easy-51%2F151_(33.8%25)-22c55e?style=for-the-badge)
![Medium](https://img.shields.io/badge/Medium-3%2F187_(1.6%25)-eab308?style=for-the-badge)
![Hard](https://img.shields.io/badge/Hard-0%2F136_(0.0%25)-f4506e?style=for-the-badge)

*Full section-wise breakdown: [Strivers_A2Z_Sheet/README.md](./Strivers_A2Z_Sheet/README.md).*

---

## 📁 Project Structure

```
DSA/
│
├── .gitignore
├── .vscode/
│   ├── tasks.json
│   └── c_cpp_properties.json
│
├── Strivers_A2Z_Sheet/
│   ├── README.md
│   ├── input.txt
│   ├── output.txt
│   └── 1.Learn_the_basics/ ... 18.Strings_Advanced/
│
└── LeetCode/
    ├── Arrays/
    ├── Two_Pointers/
    ├── DP/
    └── ... (topic folders, added as problems are solved)
```

### 📍 Important Locations

| File / Folder | Location |
|---|---|
| Git ignore rules | `DSA\.gitignore` |
| VS Code configuration | `DSA\.vscode\` |
| Striver's sheet + progress | `DSA\Strivers_A2Z_Sheet\README.md` |
| LeetCode solutions | `DSA\LeetCode\` |

---

## ⚙️ Requirements

| | |
|---|---|
| **OS** | Windows |
| **Editor** | Visual Studio Code |
| **Compiler** | MinGW-w64 / GCC, expected at `C:\mingw64\bin\g++.exe` |
| **Standard** | C++17 |

---

## 🛠️ Setup

1. Clone the repo so the local structure becomes `DSA/`.
2. Verify `C:\mingw64\bin\g++.exe` exists — the VS Code config points here.
3. Open the `DSA` folder in VS Code (so `${workspaceFolder}` resolves correctly for both tasks below).

---

## ▶️ How to Run

Two shared VS Code tasks, usable from either `Strivers_A2Z_Sheet/` or `LeetCode/`:

**`compile and run`**
Builds the open `.cpp` file, feeds it `Strivers_A2Z_Sheet\input.txt`, writes to `Strivers_A2Z_Sheet\output.txt`. Use for Striver problems that take stdin input.

**`compile and run live`**
Builds and runs the open `.cpp` file directly, no I/O redirection. Use for LeetCode problems (no stdin/stdout — LeetCode calls your function directly, so this is just for local ad-hoc testing with your own `main()`) and any Striver problem without file-based input.

---

## 🗂️ Sub-repos

- **[Strivers_A2Z_Sheet/README.md](./Strivers_A2Z_Sheet/README.md)** — full topic breakdown and progress tracker for the 474-problem sheet.
- **LeetCode/** — solved problems, committed manually per problem (topic-folder per problem, no auto-sync tooling).

---

## 🎯 Goal

Build a strong DSA foundation through consistent, trackable C++ practice.