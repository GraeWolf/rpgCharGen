# Learning roadmap — Basic Fantasy Character Generator

This is the **human’s checklist**. Work top to bottom. Check items off as you finish them.  
Grok coaches; **you write the code** unless you explicitly ask for a solution.

**Status key:** `[ ]` todo · `[~]` in progress · `[x]` done

---

## Phase 0 — Project literacy (no game logic yet)

**Goal:** You can create a tiny C++ program, build it with CMake, and run it.

- [x] Confirm tools installed: `g++` (or clang++), `cmake`, and a generator (`ninja` or `make`)
- [x] Create a minimal repo layout: `src/main.cpp`, root `CMakeLists.txt`, `README.md`
- [x] CMake: C++ standard set, one executable target (`bf_chargen`), out-of-source `build/`
- [x] Program prints a hello / placeholder line (proves the toolchain)
- [x] Mental model: source file → object file → executable (covered in coaching)
- [x] `.gitignore` ignores `build/`; first git commit done

**Success:** `cmake -S . -B build && cmake --build build` produces a binary you can run. **Done.**

**Concepts:** translation unit, linker, build directory, project vs target in CMake.

**Notes:** Project currently uses **C++23** in `CMakeLists.txt` (fine with GCC 14). Generator: Ninja recommended.

---

## Phase 1 — Dice and ability scores

**Goal:** Reliable randomness for classic rolls; model six abilities.

- [x] Decide ability roll method for MVP: **3d6 down the line**
- [x] Implement `d6` / `roll_3d6` as free functions (`std::mt19937` + `<random>`)
- [x] Represent abilities with `struct AbilityScores` (named members)
- [x] Compute ability **modifiers** per BFRPG table
- [x] CLI: print scores and modifiers
- [x] Design choice: struct + free functions (not class, not six loose vars)

**Success:** Running the program shows six scores and their modifiers; re-runs differ. **Done.**

**Concepts:** functions, `<random>` vs `rand()`, data grouping with struct, pass-by-value vs reference for simple ints.

**Notes:** Seed from `std::random_device` each run. C++23 `std::println` used for output.

---

## Phase 2 — Rules data: races and classes (hardcoded)  ← **current**

**Goal:** Encode enough BFRPG race/class rules to validate a character.

- [ ] List races and classes you will support in MVP (subset OK if documented)
- [ ] Hardcode race data: ability adjustments, restrictions, any special notes you need
- [ ] Hardcode class data: prime requisite / minimums, hit die, allowed races if applicable
- [ ] Use `enum class` for race/class ids where it helps
- [ ] Functions: “does this score block meet class requirements?”, apply racial adjustments
- [ ] CLI: roll scores → pick or random race/class → print accept/reject and final scores

**Success:** Invalid combos are rejected or re-rolled according to a rule you chose and wrote down in `docs/RULES_NOTES.md`.

**Concepts:** tables of data, enum class, const correctness, separation of “rules data” vs “one character instance.”

---

## Phase 3 — A full MVP character sheet (derived stats)

**Goal:** One random playable-enough character printed cleanly.

- [ ] Name (random from a small list or user input—your choice)
- [ ] Hit points (class hit die + CON mod; handle minimums per your rules notes)
- [ ] Saving throws / attack bonus (as appropriate for level 1 BFRPG)
- [ ] Alignment if you want it on the sheet (can be random simple table)
- [ ] `print_character_sheet` (or similar) formats readable output
- [ ] End-to-end: one command → one complete random level-1 character

**Success:** A friend could copy the printout onto a paper sheet without asking you questions.

**Concepts:** “pure data” character struct vs functions that fill/print it; keeping `main` thin.

---

## Phase 4 — Project structure upgrade

**Goal:** Multi-file layout you understand and can extend.

- [ ] Split into sensible files (e.g. dice, abilities, race/class data, character, sheet print, main)
- [ ] Update CMake for multiple sources
- [ ] Headers: include guards or `#pragma once`; what belongs in `.h` vs `.cpp`
- [ ] Namespaces for your library code vs `main`
- [ ] README: exact build/run steps

**Success:** Someone else clones the repo and runs it using only the README.

**Concepts:** linkage, ODR (high level), interface vs implementation.

---

## Phase 5 — Equipment and money

**Goal:** Starting gold and a simple equipment loadout.

- [ ] Starting gold rules for class
- [ ] Hardcoded weapon/armor/gear tables (minimal set)
- [ ] Purchase or random starting kit (your design; keep it small)
- [ ] Armor class / encumbrance basics if you want them on the sheet
- [ ] Print equipment on the sheet

**Success:** Sheet shows gold remaining and gear that matches BFRPG-ish starting expectations.

---

## Phase 6 — Spells and class features

**Goal:** Casters and thieves look correct at level 1.

- [ ] Spell lists / slots for classes you support
- [ ] Starting spells selection (random or fixed starter sets)
- [ ] Thief skills (if thief supported)
- [ ] Other level-1 class features you care about
- [ ] Sheet sections for spells/skills

**Success:** A level-1 Magic-User/Cleric/Thief printout is usable at the table.

---

## Phase 7 — Usability upgrades

**Goal:** Less pure-random, more player agency.

- [ ] Interactive prompts (choose race/class, keep/re-roll scores)
- [ ] Alternate ability gen methods (4d6 drop lowest, etc.) if desired
- [ ] Save/load character to a text or JSON file
- [ ] Seed control for reproducible “random” characters (debug/learning)

---

## Phase 8 — External rules data

**Goal:** Move hardcoded tables toward data files without rewriting everything.

- [ ] Choose a format (JSON/TOML/CSV/custom text)
- [ ] Load races/classes/items from files
- [ ] Fallback or clear errors if files missing
- [ ] Document file schema in `docs/`

**Success:** You can add a house-ruled item or tweak a number without recompiling (or with minimal recompile—your design).

---

## Phase 9 — Optional polish (pick any)

- [ ] Simple unit tests for modifiers, requirements, HP
- [ ] Party generator (N characters)
- [ ] Better formatting / color terminal output
- [ ] Level-up helper (later levels)
- [ ] C++20 features exploration if you upgraded the standard

---

## Suggested “this week” focus

**Start at Phase 0.**  
When you open a session, say: *“Continue from the roadmap”* or name a phase.  
Grok should only advance phases when you check off the success criteria (or you explicitly skip).

---

## Design journal (optional)

Use this space for your own notes:

| Date | Decision | Why |
|------|----------|-----|
| | | |
