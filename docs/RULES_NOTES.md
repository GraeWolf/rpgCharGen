# Rules notes — what we implement

Source: Basic Fantasy RPG free rules (user’s PDF).  
**Verify every number against your book** before treating this as final.  
Edition / PDF title: _TBD (fill in)_

## MVP scope (Phase 2)

### Races (core four)

| Race | Ability adjustments | Allowed classes (core four only) |
|------|---------------------|----------------------------------|
| Human | none | Fighter, Cleric, Magic-User, Thief |
| Elf | +1 INT, −1 CON | Fighter, Magic-User, Thief _(not Cleric in standard BFRPG)_ |
| Dwarf | +1 CON, −1 CHA | Fighter, Cleric, Thief _(not Magic-User)_ |
| Halfling | +1 DEX, −1 STR | Fighter, Thief _(not Cleric, not Magic-User)_ |

Optional later (not MVP): Elf Fighter/Magic-User multiclass, racial min/max scores, infravision text, etc.

### Classes (core four)

| Class | Minimum ability (typical BFRPG) | Hit die (for later phases) |
|-------|----------------------------------|----------------------------|
| Fighter | STR 9+ | d8 |
| Cleric | WIS 9+ | d6 |
| Magic-User | INT 9+ | d4 |
| Thief | DEX 9+ | d4 |

Prime requisite / XP bonus can wait until after MVP validation works.

### Ability modifiers

Already implemented in Phase 1 (3→−3 … 18→+3). See PDF ability score table if anything disagrees.

### Generation policy (Phase 2 CLI)

Document the policy you code (pick one and stick to it):

**Recommended for random generator:**

1. Roll 3d6 down the line (base scores).
2. Pick a random **race**, apply racial adjustments (clamp scores to 3–18 if you want a safety rail).
3. Build the list of classes that are **allowed for that race** and whose **minimums** the adjusted scores meet.
4. If that list is empty: re-roll scores (and optionally race) and try again — cap attempts (e.g. 100) so a bug can’t loop forever.
5. Pick a random class from the valid list.
6. Print base scores, race, adjusted scores, class, and whether requirements passed.

Alternative (stricter “old school”): fix race/class first and re-roll scores until legal. Either is fine if written here.

**Policy chosen:** _recommended random race → adjust → valid classes → random class (fill in when coded)_

---

## Checked against PDF

- [ ] Racial ability adjustments match my PDF
- [ ] Race → allowed classes match my PDF
- [ ] Class minimums match my PDF
- [ ] Notes above updated if my edition differs
