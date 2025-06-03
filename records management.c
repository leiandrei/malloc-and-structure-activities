#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Database { // proper struct padding
    int id;
    float grade;
    char name[50];
    char course[10];
};

void display_records(struct Database *student_records, int n);
void update_grades(struct Database *student_records, int n);

int main() 
{
    int num;

    printf("How many students do you want to enter: ");
    scanf("%d", &num);

    struct Database records[num];

    for (int i = 0; i < num; i++) {
        printf("\nEnter details for student #%d:\n", i + 1);
        printf("Enter Student ID: ");
        scanf("%d", &records[i].id);
        printf("Enter Student Name: ");
        while (getchar() != '\n'); // Input Handling for Newline
        fgets(records[i].name, sizeof(records[i].name), stdin);
        records[i].name[strcspn(records[i].name, "\n")] = '\0';
        printf("Enter Course: ");
        scanf("%s", records[i].course);
        printf("Enter Grade: ");
        scanf("%f", &records[i].grade);
    }

    update_grades(records, num); 
    display_records(records, num);

    return 0;
}

void display_records(struct Database *student_records, int n)
{
    printf("\n=== All Student Records ===\n");
    for (int i = 0; i < n; i++) {
        printf("--- Student Info ---\n");
        printf("ID: %d\n", student_records[i].id);
        printf("Student Name: %s\n", student_records[i].name);
        printf("Course: %s\n", student_records[i].course);
        printf("Grade: %.2f\n", student_records[i].grade);
    }
}

void update_grades(struct Database *student_records, int n)
{
    int id;
    float grade;
    
    printf("\nEnter the ID of the Student to update grade: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++) {
        if (id == student_records[i].id) {
            printf("Enter new grade: ");
            scanf("%f", &grade);
            student_records[i].grade = grade;
            break;
        } 
    }
    printf("\n");
}
