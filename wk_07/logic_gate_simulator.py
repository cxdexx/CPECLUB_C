def validate_bit(value: str) -> int:
    """Validate that the user entered either 0 or 1."""
    while value not in {"0", "1"}:
        print("Invalid input. Please enter only 0 or 1.")
        value = input("Enter a bit value: ").strip()

    return int(value)


def and_gate(a: int, b: int) -> int:
    """Return 1 only if both inputs are 1."""
    return 1 if a == 1 and b == 1 else 0


def or_gate(a: int, b: int) -> int:
    """Return 1 if at least one input is 1."""
    return 1 if a == 1 or b == 1 else 0


def not_gate(a: int) -> int:
    """Flip the input bit."""
    return 1 if a == 0 else 0


def xor_gate(a: int, b: int) -> int:
    """Return 1 only if both inputs are different."""
    return 1 if a != b else 0


def half_adder(a: int, b: int) -> tuple[int, int]:
    """Simulate a half-adder circuit using XOR and AND gates."""
    sum_bit = xor_gate(a, b)
    carry_bit = and_gate(a, b)

    return sum_bit, carry_bit


def display_basic_gates_truth_table() -> None:
    """Display truth table for AND, OR, and XOR gates."""
    test_cases = [(0, 0), (0, 1), (1, 0), (1, 1)]

    results = [
        [a, b, and_gate(a, b), or_gate(a, b), xor_gate(a, b)]
        for a, b in test_cases
    ]

    print("\n========== BASIC LOGIC GATES ==========")
    print(" A | B | AND | OR | XOR")
    print("------------------------")

    for row in results:
        print(f" {row[0]} | {row[1]} |  {row[2]}  | {row[3]}  |  {row[4]}")


def display_not_gate_truth_table() -> None:
    """Display truth table for NOT gate."""
    test_cases = [0, 1]

    results = [[a, not_gate(a)] for a in test_cases]

    print("\n========== NOT GATE ==========")
    print(" A | NOT")
    print("---------")

    for row in results:
        print(f" {row[0]} |  {row[1]}")


def display_half_adder_truth_table() -> None:
    """Display truth table for the half-adder circuit."""
    test_cases = [(0, 0), (0, 1), (1, 0), (1, 1)]

    results = [
        [a, b, *half_adder(a, b)]
        for a, b in test_cases
    ]

    print("\n========== HALF-ADDER CIRCUIT ==========")
    print(" A | B | SUM | CARRY")
    print("---------------------")

    for row in results:
        print(f" {row[0]} | {row[1]} |  {row[2]}  |   {row[3]}")


def simulate_custom_half_adder() -> None:
    """Allow the user to test the half-adder with custom input."""
    print("\n========== CUSTOM HALF-ADDER TEST ==========")

    a = validate_bit(input("Enter first bit A: ").strip())
    b = validate_bit(input("Enter second bit B: ").strip())

    sum_bit, carry_bit = half_adder(a, b)

    print("\nResult:")
    print(f"{a} + {b} = Sum: {sum_bit}, Carry: {carry_bit}")

    if carry_bit == 1:
        print(f"Binary meaning: {a} + {b} = 10")
    else:
        print(f"Binary meaning: {a} + {b} = {sum_bit}")


def explain_half_adder() -> None:
    """Explain how the half-adder works."""
    print("\n========== HOW THE HALF-ADDER WORKS ==========")
    print("A half-adder adds two binary bits: A and B.")
    print("It produces two outputs:")
    print("1. SUM   -> calculated using XOR gate")
    print("2. CARRY -> calculated using AND gate")
    print()
    print("Formula:")
    print("SUM   = A XOR B")
    print("CARRY = A AND B")
    print()
    print("Example:")
    print("1 + 1 gives SUM = 0 and CARRY = 1")
    print("That means binary 10, which is decimal 2.")


def main() -> None:
    """Run the Logic Gate Simulator."""
    while True:
        print("\n======================================")
        print("        LOGIC GATE SIMULATOR")
        print("======================================")
        print("1. View basic logic gates truth table")
        print("2. View NOT gate truth table")
        print("3. View half-adder truth table")
        print("4. Test half-adder manually")
        print("5. Explain half-adder")
        print("6. Exit")

        choice = input("Choose an option: ").strip()

        if choice == "1":
            display_basic_gates_truth_table()

        elif choice == "2":
            display_not_gate_truth_table()

        elif choice == "3":
            display_half_adder_truth_table()

        elif choice == "4":
            simulate_custom_half_adder()

        elif choice == "5":
            explain_half_adder()

        elif choice == "6":
            print("Exiting Logic Gate Simulator. Goodbye!")
            break

        else:
            print("Invalid option. Please choose from 1 to 6.")


if __name__ == "__main__":
    main()