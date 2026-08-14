# Basic Fantasy RPG — Character Generator

A **C++ learning project**: a command-line character generator for [Basic Fantasy RPG](https://basicfantasy.org/).

You write the code. Project coaching rules for AI assistants live in [`AGENTS.md`](AGENTS.md). The step-by-step learning plan is in [`docs/ROADMAP.md`](docs/ROADMAP.md).

## Status

**Phase 0 complete** — CMake toolchain works; hello-world binary `bf_chargen`.  
**Next:** Phase 1 (dice and ability scores) — see [`docs/ROADMAP.md`](docs/ROADMAP.md).

## Requirements

- C++ compiler with C++23 support (`g++` 14+ works)
- CMake 3.16+
- Ninja (recommended) or Make

## Build & run

From the repository root:

```bash
cmake -S . -B build -G Ninja
cmake --build build
./build/bf_chargen
```

Reconfigure only when `CMakeLists.txt` changes. After editing `.cpp` files, `cmake --build build` is enough.

With Make instead of Ninja:

```bash
cmake -S . -B build -G "Unix Makefiles"
cmake --build build
./build/bf_chargen
```

## License / rules

Game mechanics should follow the Basic Fantasy RPG free rules you choose to implement.  
This software project’s license is TBD (add one when you are ready to share the code).
