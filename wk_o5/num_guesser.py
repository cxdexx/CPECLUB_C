import random

print("Welcome to the Number Guesser Game!")


secret_number = random.randint(1, 20)

attempts = 0

while True:
    try:
        guess = int(input("Guess a number between 1 and 20: "))
        attempts += 1

        if guess < secret_number:
            print("Too low! Try again.\n")

        elif guess > secret_number:
            print("Too high! Try again.\n")

        else:
            print(f" Correct! The number was {secret_number}")
            print(f"You guessed it in {attempts} attempts.")
            break

    except ValueError:
        print("Please enter a valid number.\n")
