#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include"header.h"
#include"globals.h"

int checkPrerequisites(int courseID, int studentID, Student students[], int studentCount, Prerequisite prerequisites[], int prerequisiteCount) {
    int studentIndex = findStudent(students, studentCount, studentID);
    if (studentIndex == -1) {
        printf("\033[1;31mStudent not found.\033[0m\n");
        return 0;
    }

    for (int i = 0; i < prerequisiteCount; i++) {
        if (prerequisites[i].courseID == courseID) {
            int prerequisiteID = prerequisites[i].prerequisiteID;
            int hasPrerequisite = 0;
            for (int j = 0; j < students[studentIndex].registeredCount; j++) {
                if (students[studentIndex].registeredCourses[j] == prerequisiteID) {
                    hasPrerequisite = 1;
                    break;
                }
            }
            if (!hasPrerequisite) {
                return 0;
            }
        }
    }
    return 1;
}