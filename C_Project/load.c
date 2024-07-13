#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include"header.h"
#include"globals.h"

void loadCourses(Course courses[], int *courseCount) {
    FILE *file = fopen("courses.txt", "r");
    if (file == NULL) {
        printf("Could not open courses.txt\n");
        return;
    }
    *courseCount = 0;
    while (fscanf(file, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%d;%d;%d;%d;\n", 
                  &courses[*courseCount].courseID, courses[*courseCount].courseName,
                  courses[*courseCount].section1, courses[*courseCount].section2,
                  courses[*courseCount].section3, courses[*courseCount].courseOutcome,
                  courses[*courseCount].courseFeedback, &courses[*courseCount].maxStudents,
                  &courses[*courseCount].currentStudentsSec1,
                  &courses[*courseCount].currentStudentsSec2,
                  &courses[*courseCount].currentStudentsSec3) != EOF) {
        (*courseCount)++;
    }
    fclose(file);
}

void loadStudents(Student students[], int *studentCount) {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Could not open students.txt\n");
        return;
    }
    int i = 0;
    while (fscanf(file, "%d %s %s %d", &students[i].studentID, students[i].studentName, students[i].studentPassword, &students[i].registeredCount) == 4) {
        for (int j = 0; j < students[i].registeredCount; j++) {
            fscanf(file, " %d", &students[i].registeredCourses[j]);
        }
        i++;
    }
    *studentCount = i;
    fclose(file);
}

void loadAdmin(Admin admins[], int *adminCount){
    FILE *file=fopen("admins.txt","r");
    if (file == NULL) {
        printf("Could not open students.txt\n");
        return;
    }
    *adminCount=0;
    while (fscanf(file, "%d %s %s", &admins[*adminCount].adminID, admins[*adminCount].adminName,admins[*adminCount].adminPassword)!= EOF) {
        (*adminCount)++;
    }
    fclose(file);
}

void loadSection(Section sections[], int *sectionCount){
    FILE *file = fopen("section.txt", "r");
    if (file == NULL) {
        printf("Could not open sections.txt\n");
        return;
    }
    int i = 0;
    while (fscanf(file, "%d %d", &sections[i].studentID, &sections[i].registeredCount) == 2) {
        for (int j = 0; j < sections[i].registeredCount; j++) {
            fscanf(file, " %d", &sections[i].registeredSections[j]);
        }
        i++;
    }
    *sectionCount=i;
    fclose(file);
}

void loadTime(Time times[], int *timeCount){
    FILE *file = fopen("time.txt", "r");
    if (file == NULL) {
        printf("Could not open time.txt\n");
        return;
    }
    int i = 0;
    while (fscanf(file, "%d %d", &times[i].studentID, &times[i].registeredCount) == 2) {
        for (int j = 0; j < times[i].registeredCount; j++) {
            fscanf(file, "%s", times[i].registeredTimes[j]);
        }
        i++;
    }
    *timeCount = i;
    fclose(file);
}

void loadWaitlist(Waitlist waitlists[], int *waitlistNum){
    FILE *file = fopen("waitlist.txt", "r");
    if (file == NULL) {
        printf("Could not open waitlist.txt\n");
        return;
    }
    int i = 0;
    while (fscanf(file, "%d %d %d", &waitlists[i].courseID, &waitlists[i].sectionID, &waitlists[i].waitlistCount) == 3) {
        for (int j = 0; j < waitlists[i].waitlistCount; j++) {
            fscanf(file, " %d", &waitlists[i].waitlistArr[j]);
        }
        i++;
    }
    *waitlistNum = i;
    fclose(file);
}

void loadWorkload(Workload workloads[], int *workloadCount){
    FILE *file = fopen("workload.txt", "r");
    if (file == NULL) {
        printf("Could not open workload.txt\n");
        return;
    }
    *workloadCount = 0;
    while (fscanf(file, "%d %d", &workloads[*workloadCount].courseID, &workloads[*workloadCount].time) != EOF) {
        (*workloadCount)++;
    }
    fclose(file);
}

void loadPrerequisites(Prerequisite prerequisites[], int *prerequisiteCount, Student students[]) {
    FILE *file = fopen("prerequisites.txt", "r");
    if (file == NULL) {
        printf("Could not open prerequisites.txt\n");
        return;
    }
    *prerequisiteCount = 0;
    while (fscanf(file, "%d %d", &prerequisites[*prerequisiteCount].courseID, &prerequisites[*prerequisiteCount].prerequisiteID) != EOF) {
        (*prerequisiteCount)++;
    }
    fclose(file);
}

void loadCourseRec(Recommendation recommendations[], int *recommendationCount){
    FILE *file = fopen("recommendations.txt", "r");
    if (file == NULL) {
        printf("Could not open recommendations.txt\n");
        return;
    }
    *recommendationCount = 0;
    while (fscanf(file, "%d %d", &recommendations[*recommendationCount].courseID, &recommendations[*recommendationCount].courseRecID) != EOF) {
        (*recommendationCount)++;
    }
    fclose(file);
}

