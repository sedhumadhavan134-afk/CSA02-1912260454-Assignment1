# C Programming Assignment 1 – CO1

**Student:** Sedhu Madhavan V  
**Register number:** 1912260454  
**Institution:** SIMATS, Chennai  
**Programme:** Electronics and Communication Engineering  
**Repository:** https://github.com/sedhumadhavan134-afk/CSA02-1912260454-Assignment1

## Compiler
Use GCC. Record the actual version with `gcc --version`; do not assume a version number.

## Compile and run (from repository root)
```sh
gcc -std=c11 -Wall -Wextra -Wpedantic Task01/task01_analysis.c -o task01 && ./task01
gcc -std=c11 -Wall -Wextra -Wpedantic Task02/task02_types.c -o task02 && ./task02
gcc -std=c11 -Wall -Wextra -Wpedantic Task03/task03_constants.c -o task03 && ./task03
gcc -std=c11 -Wall -Wextra -Wpedantic Task04/task04_macros.c -o task04 && ./task04
gcc -std=c11 -Wall -Wextra -Wpedantic Task05/task05_debug.c -o task05 && ./task05
gcc -std=c11 -Wall -Wextra -DDEBUG Task05/task05_debug.c -o task05_debug && ./task05_debug
gcc -std=c11 -Wall -Wextra -Wpedantic Task06/task06_input.c -o task06 && echo "1200 1530" | ./task06
gcc -std=c11 -Wall -Wextra -Wpedantic Task07/task07_precision.c -o task07 && ./task07
gcc -std=c11 -Wall -Wextra -Wpedantic Task08/task08_build_demo.c -o task08 && ./task08
gcc -std=c11 -Wall -Wextra -Wpedantic Task09/task09_billing.c -o task09 && echo "1000 1350" | ./task09
gcc -std=c11 -Wall -Wextra -Wpedantic Task10/task10_scale.c -o task10 && ./task10
gcc -std=c11 -Wall -Wextra -Wpedantic Task11/task11_recommend.c -o task11 && ./task11
gcc -std=c11 -Wall -Wextra -Wpedantic Task12/task12_smart_meter.c -o task12 && (cd Task12 && ../task12 <<< "1500 1200")
```

## Task index
- Task01: problem analysis and data identification.
- Task02: data types, limits, rollover TODO.
- Task03: centralized tariff constants and slab calculation TODO.
- Task04: safe macros and inline functions.
- Task05: header file, include guards and DEBUG compilation.
- Task06: formatted input and validation.
- Task07: type conversion and precision.
- Task08: preprocessing, assembly, object and linking stages.
- Task09: complete billing implementation and tests.
- Task10: district-scale totals and numeric limits.
- Task11: final type/tariff design recommendation.
- Task12: smart-meter, peak tariff and runtime configuration redesign.

## Evidence still to add
Add genuine terminal screenshots and any required input/output files to each task folder. Record the real compiler version, sizeof/ranges, floating-point measurements and object sizes in the report. Source files uploaded to GitHub are not proof that they were executed on your own computer.
