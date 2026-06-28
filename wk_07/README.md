# CPE Club Python Projects

A collection of Python projects completed as part of the Computer Engineering (CPE) Club practical assignments. These projects focus on strengthening problem-solving skills, programming logic, functions, loops, conditionals, list comprehensions, and the connection between software and hardware concepts.

---

## Projects Included

### 1. Command Line Expense Tracker

A terminal-based expense management application that allows users to track and summarize their spending while the program is running.

#### Features

* Add new expenses
* View all recorded expenses
* Update existing expenses
* Delete expenses
* View total spending summary
* View monthly spending summary
* Uses list comprehensions for fast financial calculations
* Menu-driven terminal interface

#### Concepts Practiced

* Functions
* Lists and nested lists
* Loops
* Conditionals
* CRUD operations
* List comprehensions
* User input validation

#### Sample Expense Structure

```python
expenses = [
    [1, "05", "Data Subscription", 2500],
    [2, "06", "Lunch", 1200],
    [3, "06", "Transport", 800]
]
```

---

### 2. Logic Gate Simulator

A software simulation of fundamental digital logic gates used in computer hardware.

The project demonstrates how physical logic circuits can be represented using Python functions.

#### Implemented Gates

* AND Gate
* OR Gate
* NOT Gate
* XOR Gate

#### Half-Adder Circuit

The project combines logic gates to build a Half-Adder, a fundamental digital circuit used for binary addition.

Formula:

```text
SUM   = A XOR B
CARRY = A AND B
```

#### Features

* Logic gate simulation
* Truth table generation
* Half-Adder implementation
* Interactive terminal menu
* User input validation
* Test cases for all binary input combinations
* List comprehension usage for circuit testing

#### Example Half-Adder Output

```text
A B | SUM CARRY
---------------
0 0 |  0    0
0 1 |  1    0
1 0 |  1    0
1 1 |  0    1
```

#### Concepts Practiced

* Functions
* Boolean logic
* Binary arithmetic
* Digital electronics fundamentals
* List comprehensions
* Software simulation of hardware concepts

---

## Learning Outcomes

Through these projects, I gained hands-on experience with:

* Writing reusable Python functions
* Organizing code into logical modules
* Working with lists and nested data structures
* Using loops and conditionals effectively
* Applying list comprehensions for data processing
* Building menu-driven command line applications
* Connecting software concepts to computer hardware fundamentals

---

## Technologies Used

* Python 3

No external libraries were required.

---


Run either project:

```bash
python expense_tracker.py
```

or

```bash
python logic_gate_simulator.py
```

---

## Future Improvements

### Expense Tracker

* File storage
* SQLite database integration
* Expense categories
* Budget tracking
* Monthly reports

### Logic Gate Simulator

* Full-Adder implementation
* Binary calculator
* 4-bit adder
* Logic gate visualizer
* Circuit builder

---
