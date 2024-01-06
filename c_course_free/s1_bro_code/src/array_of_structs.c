#include "../header/array_of_structs.h"
#include <stdio.h>
#include <string.h>

short main_array_of_structs ()
{
    struct student s1 = {"Spongebob", 3.0};
    struct student s2 = {"Patric", 2.5};
    struct student s3 = {"Sandy", 4.0};
    struct student s4 = {"Squidward", 2.0};

    struct student students[] = {s1, s2, s3, s4};

    for (unsigned int i = 0; i < sizeof (students) / sizeof (students[0]); i++)
    {
        printf (
            "Name of student: %-12s\tGPA of this student: %.2f\n", students[i].name,
            students[i].gpa);
    }

    return 0;
}
