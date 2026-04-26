> Three C programs that translate pseudocode blueprints into compiling, executable software.

---

## Programs

### 1. `Linear_Algebra.c` — Cramer's Rule Linear System Solver

Solves a 2×2 system of linear equations of the form:

```
ax + by = e
cx + dy = f
```

The user supplies the six coefficients (`a, b, c, d, e, f`). The program computes the main determinant **D = ad − bc**. If D is zero, there is no unique solution. Otherwise it applies Cramer's Rule to compute and display **x** and **y** to two decimal places.

**Build & run:**
```bash
gcc Linear_Algebra.c -o solver
./solver
```

---

### 2. `calculator.c` — Mini Command-Line Calculator

An interactive calculator that accepts two floating-point numbers and one of four operators (`+`, `-`, `*`, `/`). Results are printed to two decimal places. Division by zero is caught and reported without crashing.

**Build & run:**
```bash
gcc calculator.c -o calculator
./calculator
```

**Example input:**
```
10 / 4   →  Result: 2.50
10 / 0   →  Error: Division by zero is undefined.
```

---

### 3. `even_odd.c` — Even/Odd Logic Gate

Prompts the user for any whole number and uses the modulo operator (`%`) to determine whether it is **Even** or **Odd**.

**Build & run:**
```bash
gcc even_odd.c -o even_odd
./even_odd
```

---

## Requirements

- GCC (or any C99-compatible compiler)
- Standard C library (`<stdio.h>`) — no external dependencies

## Compile All at Once

```bash
gcc Linear_Algebra.c   -o solver
gcc calculator.c -o calculator
gcc even_odd.c -o even_odd
```
