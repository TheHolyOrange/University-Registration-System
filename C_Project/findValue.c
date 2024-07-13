#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include"header.h"
#include"globals.h"

int findCourse(Course courses[], int courseCount, int courseID) {
    for (int i = 0; i < courseCount; i++) {
        if (courses[i].courseID == courseID) {
            return i;
        }
    }
    return -1;
}

int findStudent(Student students[], int studentCount, int studentID) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == studentID) {
            return i;
        }
    }
    return -1;
}