#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX 8
 
typedef struct stu_info {
    char student_ID[5];
    int score;
} stu_info;
 
typedef struct student_avg {
    char student_ID[5];
    float avg_score;
} student_avg;
 
// Function to compare two student_avg structures based on avg_score for sorting
int compare(const void *a, const void *b) {
    student_avg *studentA = (student_avg *)a;
    student_avg *studentB = (student_avg *)b;
    return (studentB->avg_score - studentA->avg_score) * 1000; // Multiplied for better precision
}
 
int main() {
    stu_info *s;
    s = (stu_info*)malloc(MAX * sizeof(stu_info));
 
    for (int i = 0; i < MAX; i++) {
        printf("Enter the Student ID:\t");
        scanf("%s", (s + i)->student_ID);
 
        printf("Enter the Score:\t");
        scanf("%d", &(s + i)->score);
    }
 
    // Calculate the average score for each student
    student_avg students[MAX];
    int totalScores[MAX] = {0};
    int scoreCounts[MAX] = {0};
 
    for (int i = 0; i < MAX; i++) {
        int found = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(students[j].student_ID, (s + i)->student_ID) == 0) {
                totalScores[j] += (s + i)->score;
                scoreCounts[j]++;
                students[j].avg_score = (float)totalScores[j] / scoreCounts[j];
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(students[i].student_ID, (s + i)->student_ID);
            totalScores[i] = (s + i)->score;
            scoreCounts[i] = 1;
            students[i].avg_score = (float)totalScores[i];
        }
    }
 
    // Sorting students by their average scores in descending order
    qsort(students, MAX, sizeof(student_avg), compare);
 
    // Printing the student IDs with their average scores
    printf("Student IDs with their average scores in descending order:\n");
    for (int i = 0; i < MAX; i++) {
        if (scoreCounts[i] > 0) {
            printf("%s - %.2f\n", students[i].student_ID, students[i].avg_score);
        }
    }
 
    // Free allocated memory
    free(s);
 
    return 0;
}

