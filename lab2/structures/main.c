
#include <stdio.h>
#include <string.h>

// Structure definition
struct student {
    char name[50];
    int rollNo;
    char grade;
};

// Function to read student information
void read(struct student s[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Enter name, roll number, and grade for student %d:\n", i + 1);
        scanf("%s %d %c", s[i].name, &s[i].rollNo, &s[i].grade);
    }
}

// Function to display student information
void display(struct student s[], int numStudents) {
    printf("Student Information:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Name: %s, Roll Number: %d, Grade: %c\n",
               s[i].name, s[i].rollNo, s[i].grade);
    }
}

// Function to sort student information based on roll numbers
void sortStudentInfo(struct student s[], int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (s[j].rollNo > s[j + 1].rollNo) {
                // Swap students[j] and students[j + 1]
                struct student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct student s[numStudents];

    read(s, numStudents);
    printf("\n");

    display(s, numStudents);
    printf("\n");

    sortStudentInfo(s, numStudents);

    printf("After sorting based on roll numbers:\n");
    display(s, numStudents);

    return 0;
}
