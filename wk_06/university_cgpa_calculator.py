def grade_to_points(letter_grade: str) -> int:
    """Convert a letter grade to a 5-point grade value."""
    grade_map = {
        'A': 5,
        'B': 4,
        'C': 3,
        'D': 2,
        'E': 1,
        'F': 0,
    }
    return grade_map.get(letter_grade.upper(), -1)


def get_positive_integer(prompt: str) -> int:
    """Prompt the user until a positive integer is entered."""
    while True:
        value = input(prompt).strip()
        if not value.isdigit() or int(value) <= 0:
            print("Please enter a valid positive integer.")
            continue
        return int(value)


def get_credit_unit(course_number: int) -> int:
    """Prompt for course credit unit."""
    return get_positive_integer(f"Enter credit units for course {course_number}: ")


def get_course_code(course_number: int) -> str:
    """Prompt for a non-empty course code."""
    while True:
        course_code = input(f"Enter course code for course {course_number} (e.g. CPE204): ").strip()
        if not course_code:
            print("Course code cannot be empty.")
            continue
        return course_code.upper()


def get_letter_grade(course_number: int) -> str:
    """Prompt for a valid letter grade for a course."""
    while True:
        grade = input(f"Enter letter grade for course {course_number} (A, B, C, D, E, F): ").strip().upper()
        if grade_to_points(grade) == -1:
            print("Invalid grade. Please enter A, B, C, D, E, or F.")
            continue
        return grade


def save_gpa_report(total_courses: int, total_credits: int, total_quality_points: int, final_gpa: float, course_codes: list[str]) -> None:
    """Save the GPA summary to a text file."""
    filename = "cgpa_report.txt"
    with open(filename, "w", encoding="utf-8") as report_file:
        report_file.write("University CGPA Calculator Report\n")
        report_file.write("=================================\n")
        report_file.write(f"Courses offered: {total_courses}\n")
        report_file.write("Course codes:\n")
        for code in course_codes:
            report_file.write(f" - {code}\n")
        report_file.write(f"Total credit units: {total_credits}\n")
        report_file.write(f"Total quality points: {total_quality_points}\n")
        report_file.write(f"Final GPA: {final_gpa:.2f}\n")
    print(f"Result saved to {filename}")


def main() -> None:
    print("==================================================================")
    print("                                                                   ")
    print("  Welcome to the University CGPA Calculator    ")
    print("                                                                   ")
    print("==================================================================")
    print("                                                                   ")

    total_courses = get_positive_integer("How many courses did you offer this semester? ")
    total_credits = 0
    total_quality_points = 0
    course_codes: list[str] = []

    for course_index in range(1, total_courses + 1):
        course_code = get_course_code(course_index)
        credits = get_credit_unit(course_index)
        letter_grade = get_letter_grade(course_index)
        grade_points = grade_to_points(letter_grade)

        course_codes.append(course_code)
        total_credits += credits
        total_quality_points += credits * grade_points

    if total_credits == 0:
        print("Total credit units cannot be zero. GPA cannot be calculated.")
        return

    final_gpa = total_quality_points / total_credits
    print("\n----- Semester GPA Report -----")
    print(f"Total credit units: {total_credits}")
    print(f"Total quality points: {total_quality_points}")
    print(f"Final GPA: {final_gpa:.2f}")

    save_option = input("Would you like to save this result to a file? (yes/no): ").strip().lower()
    if save_option in {"yes", "y"}:
        save_gpa_report(total_courses, total_credits, total_quality_points, final_gpa, course_codes)


if __name__ == "__main__":
    main()
