#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAME_LEN 20

typedef struct student {
    char name[NAME_LEN];
    int year;
    int month;
    int day;
    int id;
} Student;

int cmpYears(Student *a, Student *b)
{
    if(a -> year != b -> year)
        return a -> year - b -> year;
    if(a -> month != b -> month)
        return a -> month - b -> month;
    if(a -> day != b -> day)
        return a -> day - b -> day;
    return b -> id - a -> id;
}

int main()
{
    int n;
    scanf("%d", &n);
    Student *students = (Student *)malloc(n * sizeof(Student));
    for(int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d", students[i].name, &students[i].year, &students[i].month, &students[i].day);
        students[i].id = i;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(cmpYears(&students[i], &students[j]) > 0)
            {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        printf("%s\n", students[i].name);
    }
    free(students);
    return 0;
}