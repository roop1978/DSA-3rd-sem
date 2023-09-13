#include <stdio.h>
#include <string.h>

// Structure to represent a student's record
struct Student {
    char name[50];
    int rollNo;
    char grade;
    char branch[50];
};

// Function to input student records and write them to a text file
void writeRecordsToFile(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        return;
    }

    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    fflush(stdin);

    struct Student student;

    for (int i = 0; i < numStudents; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", student.name);
        printf("Roll No.: ");
        scanf("%d", &student.rollNo);
        fflush(stdin);
        printf("Grade: ");
        scanf(" %c", &student.grade); // Notice the space before %c to consume newline characters
        fflush(stdin);
        printf("Branch: ");
        scanf("%s", student.branch);

        // Write the student record to the file
        fprintf(file, "%s %d %c %s\n", student.name, student.rollNo, student.grade, student.branch);
    }

    fclose(file);
}

// Function to read the text file and separate records branch-wise into separate files
void separateRecordsByBranch(const char* inputFilename) {
    FILE* inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        printf("Error opening the input file for reading.\n");
        return;
    }

    char branch[50];
    char outputFilename[100];
    struct Student student;

    while (fscanf(inputFile, "%s %d %c %s", student.name, &student.rollNo, &student.grade, student.branch) != EOF) {
        strcpy(branch, student.branch);

        // Create an output file with the branch name
        snprintf(outputFilename, sizeof(outputFilename), "%s.txt", branch);
        FILE* outputFile = fopen(outputFilename, "a");

        // Write the student record to the branch-specific file
        fprintf(outputFile, "%s %d %c\n", student.name, student.rollNo, student.grade);

        fclose(outputFile);
    }

    fclose(inputFile);
}

int main() {
    const char* filename = "student_records.txt";

    // Write student records to the text file
    writeRecordsToFile(filename);

    // Separate records by branch into separate files
    separateRecordsByBranch(filename);

    printf("Student records have been separated by branch into individual files.\n");

    return 0;
}
