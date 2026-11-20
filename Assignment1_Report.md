# C Programming – Assignment 1 (CO1)
## Reliable Electricity Billing System – Tasks 1 to 12

**Student:** Sedhu Madhavan V  
**Register number:** 1912260454  
**Institution:** SIMATS, Chennai  
**Programme:** Electronics and Communication Engineering  
**GitHub:** https://github.com/sedhumadhavan134-afk/CSA02-1912260454-Assignment1

> Important evidence note: the source files and hand-calculated expected results are supplied. Actual compiler-dependent measurements and terminal screenshots must be captured by running the programs on the student's GCC installation. Do not present illustrative results as personally measured output.

## Scenario and assumptions
Monthly tariff: first 100 units free, units 101–200 at 225 paise/unit, above 200 at 450 paise/unit, plus fixed 5000 paise. Meter is a 16-bit unsigned register with modulus 65536. Assume at most one rollover between readings and a common tariff unless category-specific rates are configured.

## Task 1 – Problem analysis and data
Inputs: household ID (string to preserve leading zeroes), previous/current readings (0–65535), category (enum), and tariff. Outputs: units, energy charge, fixed charge and total. IDs are not numeric quantities; readings and units are non-negative integers; currency must be exact to a paise; district totals may be large. Invariants: total = energy + fixed; bill >= 0; each slab charged only at its rate; invalid inputs rejected.
Constants: modulus 65536, limits 100/200, rates 0/225/450 paise and fixed 5000 paise.
Text-reading alternative: parse strings such as "01530"; conversion/comparison takes O(d) time for d digits and storage is d+1 bytes including NUL. Integer storage is typically 2 bytes for this register and arithmetic is O(1).
Pseudocode: read and validate ID/category/readings → compute modular difference → calculate slab charge → add fixed charge → print bill. UML-style flow: Start → Input → Validate? (No: error/end; Yes: units) → slab calculation → total → report → End.

## Task 2 – Data types and rollover
Use unsigned short for the 16-bit register (verify USHRT_MAX), unsigned int for units, char[] for ID, enum for category, and long long/int64_t for money and accumulated totals after proving maximum bounds. Use sizeof, limits.h and float.h to measure the actual system; sizes are not identical on every platform. Use integer paise because binary floating point cannot represent every decimal fraction exactly.
Completed TODO: `return (unsigned int)(meter_t)(current - previous);`. For 65400→120, modular subtraction gives 120−65400 ≡ 256 (mod 65536). Expected output on a system with 16-bit unsigned short: sizeof meter_t = 2, maximum 65535; consumption 330 and 256 units.
Double rupees and integer paise additions are both O(1); double typically uses 8 bytes but has approximate decimal precision. Integer paise is exact within range.

## Task 3 – Central tariff constants
Task03 defines slab limits/rates/fixed charge in one macro block. #define is preprocessor substitution without type checking; const has type/scope and is debugger-visible; enum is appropriate for integral choices. Runtime complexity is effectively unchanged.
Expected bills: 0→Rs50.00; 100→Rs50.00; 150→Rs162.50; 200→Rs275.00; 350→Rs950.00. Changing RATE2_PAISE from 225 to 230 updates all second-slab calculations centrally.

## Task 4 – Safe macros
Task04 provides parenthesised RUPEES_TO_PAISE, SQUARE and MAX macros plus static inline alternatives. SQUARE(x) without parentheses fails for SQUARE(a+1) because expansion follows operator precedence. MAX(i++,j) can evaluate an argument more than once; avoid side effects in macro arguments. Inspect expansion with `gcc -E Task04/task04_macros.c -o macros.i`. Both approaches are O(1) per use; macros may duplicate code at k sites, while inline functions may be shared or inlined by the compiler.

## Task 5 – Header files and conditional compilation
Task05/billing.h has include guards and declarations. Angle-bracket includes search system paths; quoted includes search local/project paths first. #ifdef DEBUG removes diagnostic code from non-debug builds; a runtime debug flag keeps the branch and code in the executable. Compile with `gcc -std=c11 -Wall -Wextra -DDEBUG Task05/task05_debug.c -o task05_debug`.

## Task 6 – Formatted I/O
Use %d int, %u unsigned, %ld long, %lld long long, %f in printf for float/double, %f in scanf for float*, %lf in scanf for double*, %c char, %s string, %zu size_t. Check scanf's conversion count. A mismatched format such as %d for long is undefined behaviour. fgets plus strtol processes a line of length L in O(L) time and O(L) buffer space and makes malformed-line recovery easier than scanf. Task06 demonstrates line-oriented input parsing.

## Task 7 – Type conversion and precision
Examples: 5/2 prints 2 (integer division); (double)5/2 prints 2.50; (int)3.9 becomes 3 (truncation toward zero); converting a difference to 16-bit unsigned wraps modulo 65536. Integer promotions and usual arithmetic conversions apply when types mix; avoid narrowing large long values to int. Define one rounding rule when fractional paise arises. Both integer and float addition are O(1); float commonly 4 bytes and long long 8 bytes. Measure float accumulation error on the actual compiler instead of assuming a universal value.

## Task 8 – Compilation process
Run: `gcc -E file.c -o file.i` (preprocessing), `gcc -S file.c -o file.s` (assembly), `gcc -c file.c -o file.o` (object), and `gcc file.o -o app` (link). Preprocessing expands macros/includes. Compile error: syntax/type error; link error: undefined function; runtime error: invalid input or division by zero. Use -Wall -Wextra -Wpedantic and resolve warnings. With multiple .c files, unchanged translation units need not be recompiled after a local source edit; relinking is still required. Object storage is the sum of object files.

## Task 9 – Billing implementation and tests
Task09 implements rollover-safe units and integer-paise slab billing:
- units <= 100: energy 0
- 100 < units <= 200: (units−100)×225 paise
- units > 200: 100×225 + (units−200)×450 paise
- total = energy + 5000 paise.

| Previous→Current | Units | Expected bill |
|---|---:|---:|
| 1200→1200 | 0 | Rs 50.00 |
| 1000→1100 | 100 | Rs 50.00 |
| 1000→1150 | 150 | Rs 162.50 |
| 1000→1200 | 200 | Rs 275.00 |
| 1000→1350 | 350 | Rs 950.00 |
| 65400→120 | 256 | Rs 752.00 |

Five-bill total for 0,100,150,200,350 units = 148750 paise = Rs1,487.50. Also test letters, negative and out-of-range values. A table-driven tariff uses O(s) time and O(s) tariff storage for s slabs; fixed branches are O(1), simpler for three fixed slabs.

## Task 10 – Scale and numeric limits
Task10 compares integer paise and double rupees for 4,000, 60,000 and 800,000 bills using an illustrative Rs950 bill. Exact totals: Rs3,800,000; Rs57,000,000; Rs760,000,000 respectively. These figures are example calculations, not runtime measurements. int commonly 32-bit; long may be 32 or 64-bit; long long is at least 64-bit. Check maximum bill × maximum households against LLONG_MAX before deployment. Integer overflow is a hard range failure; double has wider range but gradual precision loss. Both additions are O(1), typically 8 bytes for long long/double.

## Task 11 – Final recommendation
Use unsigned short for the verified 16-bit register, unsigned units after bounding, strings for IDs, integer paise for currency, and 64-bit totals only after a maximum-value proof. Centralize tariff values and validate all inputs/arithmetic. For frequent tariff changes, read t validated entries from a configuration file in O(t) startup time and O(t) storage; this avoids recompilation but requires validation, versioning, secure access and error handling.

## Task 12 – Day-4 smart-meter redesign
**Decision: modify/redesign.** Smart meters report Wh every 15 minutes: 96 intervals/day and 35,040/year/household. Peak is 18:00 inclusive to 22:00 exclusive at 20% uplift. Yearly totals exceed the original 16-bit register; use 64-bit energy/paise accumulators, timestamps and runtime tariff configuration.
Annual record counts: 4,000 houses = 140,160,000; 60,000 = 2,102,400,000; 800,000 = 28,032,000,000.
Example normal rate 225 paise/kWh, peak 270 paise/kWh. For 1500 Wh at peak: 1500×270/1000 = 405 paise (Rs4.05). Task12 reads rates from tariff.cfg and chooses rate from minute-of-day. Production code must check multiplication overflow, timezone, missing/duplicate intervals, config version/permissions, and split intervals crossing 18:00/22:00.
Pseudocode: load/validate tariffs → read Wh and timestamp → split interval at tariff boundaries → select rate per segment → calculate rounded paise → checked accumulation → report.
Each interval calculation is O(1) time and O(1) working space. Streaming aggregation needs O(1) working memory plus persistent records; retaining all annual readings requires O(35,040) per household. At district scale, use a database/batch pipeline.

## Final evidence checklist
- Run every task with GCC; capture real screenshots in each Task folder.
- Record actual gcc --version, sizeof/type limits, float-vs-paise measurements and object sizes.
- Validate normal, boundary, invalid and rollover cases; record actual outputs.
- Test Task12 at 17:59, 18:00, 21:59 and 22:00, and test tariff-file errors.
- Understand the source and calculations for the viva.
