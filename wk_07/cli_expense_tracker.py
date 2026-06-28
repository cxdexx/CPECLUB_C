expenses = [
    [1, "05", "Data Subscription", 2500],
    [2, "06", "Lunch", 1200],
    [3, "06", "Transport", 800]
]


def add_expense(month, description, amount):
    new_id = len(expenses) + 1
    expenses.append([new_id, month, description, amount])
    print("Expense added successfully.")


def view_expenses():
    if not expenses:
        print("No expenses found.")
        return

    print("\nID | Month | Description | Amount")
    print("----------------------------------")
    for expense in expenses:
        print(f"{expense[0]} | {expense[1]} | {expense[2]} | ₦{expense[3]}")


def update_expense(expense_id, new_description, new_amount):
    for expense in expenses:
        if expense[0] == expense_id:
            expense[2] = new_description
            expense[3] = new_amount
            print("Expense updated successfully.")
            return

    print("Expense not found.")


def delete_expense(expense_id):
    for expense in expenses:
        if expense[0] == expense_id:
            expenses.remove(expense)
            print("Expense deleted successfully.")
            return

    print("Expense not found.")


def summary_all():
    amounts = [expense[3] for expense in expenses]
    total = sum(amounts)
    print(f"Total amount spent: ₦{total}")


def summary_by_month(month):
    amounts = [expense[3] for expense in expenses if expense[1] == month]
    total = sum(amounts)
    print(f"Total amount spent in month {month}: ₦{total}")


def main():
    while True:
        print("\n===== Command Line Expense Tracker =====")
        print("1. Add expense")
        print("2. View all expenses")
        print("3. Update expense")
        print("4. Delete expense")
        print("5. View total summary")
        print("6. View monthly summary")
        print("7. Exit")

        choice = input("Choose an option: ")

        if choice == "1":
            month = input("Enter month: ")
            description = input("Enter description: ")
            amount = int(input("Enter amount: "))
            add_expense(month, description, amount)

        elif choice == "2":
            view_expenses()

        elif choice == "3":
            expense_id = int(input("Enter expense ID to update: "))
            description = input("Enter new description: ")
            amount = int(input("Enter new amount: "))
            update_expense(expense_id, description, amount)

        elif choice == "4":
            expense_id = int(input("Enter expense ID to delete: "))
            delete_expense(expense_id)

        elif choice == "5":
            summary_all()

        elif choice == "6":
            month = input("Enter month: ")
            summary_by_month(month)

        elif choice == "7":
            print("Goodbye.")
            break

        else:
            print("Invalid option. Try again.")


main()