# AGENTS.md

This repository is a personal **competitive-programming practice workspace** for problems on
[Baekjoon Online Judge (BOJ)](https://www.acmicpc.net) (the Korean judge at acmicpc.net).
Each numeric `.cpp` file is named after a BOJ problem ID. There is no application, library, or
build system — each file is a standalone, self-contained solution or placeholder.

## Essential commands

There is no Makefile/CMake. Compile a single solution manually with g++:

```sh
g++ -std=c++17 -O2 -o <problemID> <problemID>.cpp     # e.g. g++ -std=c++17 -O2 -o 1260 1260.cpp
./<problemID>                                            # then type/paste the test input
```

- Use `-std=c++17` (or newer). Solved files rely on `<bits/stdc++.h>`, `tie(...)`, `auto`, range-based
  `for`, and structured bindings — these need C++17.
- `-O2` matches the judge's optimization level and avoids surprising TLE behavior.
- Only g++ is available on this machine (no clang). `gcc` is present but irrelevant here.

## How to tell a real solution from a placeholder (important)

The repo is a mix of finished solutions and empty stubs. **Do not assume every file has logic.**

- **Solved** — starts with `#include <bits/stdc++.h>`, contains real logic, typically >300 bytes.
- **Unsolved stub** — uses `#include <iostream>` and the Korean comment `// 코드 작성` ("write code
  here"). The exact stub body is:
  ```cpp
  #include <iostream>
  using namespace std;

  int main() {
      // 코드 작성
      return 0;
  }
  ```
  ~19 files currently match this stub (e.g. `11047.cpp`, `10890.cpp`, `110250.cpp`, `2345.cpp`,
  `1463.cpp`, `112399.cpp`). They are pre-created empty slots for problems to be solved later —
  treat a stub as "not started", not as broken code.
- A few stubs (e.g. `10998.cpp`) have the `// 코드 작성` marker but then contain real logic below
  it — read the whole file before concluding it's empty.

To list only real solutions, filter by content rather than existence:

```sh
grep -L "코드 작성" *.cpp    # files WITHOUT the stub marker
```

## File-naming conventions and gotchas

- `<problemID>.cpp` — solution to that BOJ problem (e.g. `1260.cpp` = BOJ 1260, DFS/BFS).
- `<problemID>t.cpp` — a **draft/test** variant, stripped down from the main solution. The `t`
  suffix means "test/draft", not a different problem. Example: `14940t.cpp` is a 76-byte skeleton
  that `14940.cpp` is the full version of.
- `<problemID>.py` — Python scratch for the same problem. May be empty (e.g. `10845.py` is 0 bytes).
- **`main.cpp` is a scratch/working copy, NOT a separate solution.** It is byte-identical to
  `1260.cpp`. Don't duplicate or treat it as distinct work.
- **`base.cpp`** — minimal scratch template (just `<bits/stdc++.h>` + empty `main`). Copy-paste
  starting point, not a solution.
- **`dfsBfs.cpp`** — a topic scratch file containing only the headers (46 bytes), not a solution.
- **`class 1.cpp` is special: it is a notebook, not a compilable program.** It contains MULTIPLE
  `#include`/`using`/`int main(){...}` blocks concatenated together (one per problem in BOJ's
  "Class 1" tier). It will **not** compile as a single translation unit due to the duplicate
  `main()`. Edit it block-by-block; don't try to build it whole.
- Filenames contain spaces (`class 1.cpp`) and Korean characters in the PDFs — always quote paths.

## Standard solution pattern (follow this when writing new solutions)

1. `#include <bits/stdc++.h>` then `using namespace std;` (this is the GCC/BOJ-only omnibus header;
   do not split into individual `<iostream>`/`<vector>` includes — it won't match the repo style and
   `<bits/stdc++.h>` is not portable to MSVC/clang-default).
2. Fast I/O at the top of `main`:
   ```cpp
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   // cout.tie(0);   // added in some files when output volume is high
   ```
3. Prefer `"\n"` over `endl` for performance (a few early files like `1001.cpp` still use `endl`;
   new code should not).
4. Declare large arrays / adjacency structures as **globals** (e.g. `vector<int> adj[1001];`,
   `int dist[1001][1001];`) — avoids stack overflow and zero-initialization surprises.
5. Indentation is **tabs** in most solved files (some older files mix 2-space). Match the file
   you're editing; prefer tabs for new files.
6. End `main` with `return 0;`.

## Reference materials (untracked)

Three Korean-language PDFs in the repo root provide background context (currently untracked in git):
`알고리즘 개념교안.pdf` (algorithm concepts), `알고리즘 문제해설.pdf` (problem explanations),
`알고리즘교안.pdf` (lecture notes). They are study material, not code — relevant if a task asks
about the algorithm/topic behind a problem.

## Git / workflow conventions

- Commit messages are minimal and non-descriptive (`add`, `commit`, dates like `add 01 25`). There
  is **no conventional-commit style** — don't impose one unless asked.
- The `.gitignore` is a standard C++ artifact list (`.o`, `.exe`, `.out`, `.pdb`, etc.), which
  implies solutions are compiled locally for testing. Compiled binaries are correctly ignored.
- When adding a new problem file, follow the existing pattern: create `<problemID>.cpp` using the
  stub template (or `<bits/stdc++.h>` if solving immediately).
