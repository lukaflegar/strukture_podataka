#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE (128)
#define MAX_POINTS (50)

typedef struct _student {
    char name[MAX_SIZE];
    char surname[MAX_SIZE];
    double points;
} Student;

int readNoRowsInFile();
Student* allocateMemoryAndReadStudents(int);
int showStudents(int, Student*);
double calculateRelativePoints(double);

int main() {
    int noRows = 0;
    Student* students = NULL;

    noRows = readNoRowsInFile();
    if (noRows > 0) {
        students = allocateMemoryAndReadStudents(noRows);
        showStudents(noRows, students);

        free(students);
    }
    return EXIT_SUCCESS;
}

int readNoRowsInFile() {
    int counter = 0;
    FILE* filePointer = NULL;
    char buffer[MAX_SIZE];

    filePointer = fopen("Students.txt", "r");
    if (!filePointer) {
        printf("Neuspjesno otvaranje datoteke \n");
        return -1;
    }

    while (fscanf(filePointer, " %s %s %lf", buffer, buffer, &buffer) == 3) {
        counter++;
    }

    fclose(filePointer);
    return counter;
}

Student* allocateMemoryAndReadStudents(int noStudents) {
    int counter = 0;
    FILE* filePointer = NULL;
    Student* students = NULL;

    students = (Student*)malloc(noStudents * sizeof(Student));
    if (!students) {
        printf("Neuspjesna alokacija memorije \n");
        return NULL;
    }

    filePointer = fopen("Students.txt", "r");
    if (!filePointer) {
        printf("Neuspjesno otvaranje datoteke \n");
        return NULL;
    }

    while (fscanf(filePointer, " %s %s %lf", students[counter].name, students[counter].surname, &students[counter].points) == 3) {
        counter++;
    }

    fclose(filePointer);

    return students;
}

int showStudents(int noStudents, Student* students) {
    for (int counter = 0; counter < noStudents; counter++) {
        double relPoints = calculateRelativePoints(students[counter].points);
        printf("Ime: %s\t Prezime: %s\t Bodovi: %lf\t Relativni bodovi: %lf\n", students[counter].name, students[counter].surname, students[counter].points, relPoints);
    }
    return EXIT_SUCCESS;
}

double calculateRelativePoints(double points) {
    return (points / MAX_POINTS) * 100.0;
}