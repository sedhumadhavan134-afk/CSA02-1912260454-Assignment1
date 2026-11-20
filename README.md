# C Programming Assignment 1 – CO1
**Student:** Sedhu Madhavan V  
**Register number:** 1912260454  
**Institution:** SIMATS, Chennai  
**Programme:** Electronics and Communication Engineering  
**Repository:** https://github.com/sedhumadhavan134-afk/CSA02-1912260454-Assignment1

Use GCC and record the actual version with `gcc --version`.

## Compile and run from repository root
```sh
gcc -std=c11 -Wall -Wextra -Wpedantic Task01/task01_analysis.c -o task01 && ./task01
gcc -std=c11 -Wall -Wextra -Wpedantic Task02/task02_types.c -o task02 && ./task02
gcc -std=c11 -Wall -Wextra -Wpedantic Task03/task03_constants.c -o task03 && ./task03
gcc -std=c11 -Wall -Wextra -Wpedantic Task04/task04_macros.c -o task04 && ./task04
gcc -std=c11 -Wall -Wextra -Wpedantic Task05/main.c Task05/billing.c -o task05 && ./task05
gcc -std=c11 -Wall -Wextra -DDEBUG Task05/main.c Task05/billing.c -o task05_debug && ./task05_debug
gcc -std=c11 -Wall -Wextra -Wpedantic Task06/task06_input.c -o task06 && printf "1200 1530\n" | ./task06
gcc -std=c11 -Wall -Wextra -Wpedantic Task07/task07_precision.c -o task07 && ./task07
sh Task08/build_stages.sh
gcc -std=c11 -Wall -Wextra -Wpedantic Task09/task09_billing.c -o task09 && printf "1000 1350\n" | ./task09
gcc -std=c11 -Wall -Wextra -Wpedantic Task10/task10_scale.c -o task10 && ./task10
gcc -std=c11 -Wall -Wextra -Wpedantic Task11/task11_recommend.c -o task11 && ./task11
gcc -std=c11 -Wall -Wextra -Wpedantic Task12/task12_smart_meter.c -o task12
(cd Task12 && printf "1500 1075 15\n1500 1080 15\n1500 1315 15\n1500 1320 15\n" | ../task12)
```

## Task index
- Task01: problem analysis and complete household billing example.
- Task02: data types, limits and 16-bit rollover.
- Task03: central tariff constants and slab billing.
- Task04: safe macros and inline alternatives.
- Task05: header-based modular billing, plus DEBUG build.
- Task06: robust line-based two-reading input validation.
- Task07: type conversion and same-unit precision experiment.
- Task08: preprocessing, assembly, object and executable build stages.
- Task09: validated billing input and exact integer-paise output.
- Task10: scale test using the same five-bill pattern and integer/double totals.
- Task11: measured type sizes and design recommendations.
- Task12: 15-minute interval splitting at peak tariff boundaries and checked year-to-date total.

## Evidence still required
Run all programs on the college/lab compiler. Add genuine terminal screenshots and test inputs to each Task folder. Record actual GCC version, compiler-dependent type sizes and measurements in Assignment1_Report.md. Do not present unrun results as execution evidence.
