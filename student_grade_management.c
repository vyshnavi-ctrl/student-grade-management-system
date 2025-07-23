#include <stdio.h>

// Define a structure to store student data
struct Student {
    char name[50];
    int rollNo;
    float marks;
    char grade;
};

// Function to calculate grade based on marks
char calculateGrade(float marks) {
    if (marks >= 90) return 'A';
    else if (marks >= 80) return 'B';
    else if (marks >= 70) return 'C';
    else if (marks >= 60) return 'D';
    else return 'F';
}

int main() {
    struct Student students[100]; // Array to store students
    int choice, count = 0;

    while (1) {
        printf("\n===== Student Grade Management System =====\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Add student record
            printf("\nEnter student name: ");
            scanf(" %[^\n]", students[count].name); // read string with spaces
            printf("Enter roll number: ");
            scanf("%d", &students[count].rollNo);
            printf("Enter marks: ");
            scanf("%f", &students[count].marks);

            // Calculate grade
            students[count].grade = calculateGrade(students[count].marks);
            printf("Grade calculated: %c\n", students[count].grade);

            count++; // increment student count
        }
        else if (choice == 2) {
            // Display all student records
            printf("\n--- All Student Records ---\n");
            for (int i = 0; i < count; i++) {
                printf("Name: %s | Roll No: %d | Marks: %.2f | Grade: %c\n",
                       students[i].name, students[i].rollNo, students[i].marks, students[i].grade);
            }
            if (count == 0) {
                printf("No records found.\n");
            }
        }
        else if (choice == 3) {
            // Exit the program
            printf("Exiting program. Goodbye!\n");
            break;
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
