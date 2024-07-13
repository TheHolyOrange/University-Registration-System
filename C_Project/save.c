#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include"header.h"
#include"globals.h"

void saveCourses(Course courses[], int courseCount) {
    FILE *file = fopen("courses.txt", "w");
    if (file == NULL) {
        printf("Could not open courses.txt\n");
        return;
    }
    for (int i = 0; i < courseCount; i++) {
        fprintf(file, "%d;%s;%s;%s;%s;%s;%s;%d;%d;%d;%d;\n", courses[i].courseID, courses[i].courseName,
                courses[i].section1, courses[i].section2, courses[i].section3,
                courses[i].courseOutcome, courses[i].courseFeedback,
                courses[i].maxStudents, courses[i].currentStudentsSec1,
                courses[i].currentStudentsSec2,courses[i].currentStudentsSec3);
    }
    fclose(file);
}

void saveWorkload(Workload workloads[], int workloadCount){
    FILE *file = fopen("workload.txt", "w");
    if (file == NULL) {
        printf("Could not open workload.txt\n");
        return;
    }
    for (int i = 0; i < workloadCount; i++) {
        fprintf(file, "%d %d\n", workloads[i].courseID, workloads[i].time);
    }
    fclose(file);
}

void saveStudents(Student students[], int studentCount) {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Could not open students.txt\n");
        return;
    }
    for (int i = 0; i < studentCount; i++) {
        fprintf(file, "%d %s %s %d", students[i].studentID, students[i].studentName, students[i].studentPassword, students[i].registeredCount);
        for (int j = 0; j < students[i].registeredCount; j++) {
            fprintf(file, " %d", students[i].registeredCourses[j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

void saveSections(Section sections[],int sectionCount){
    FILE *file = fopen("section.txt", "w");
    if (file == NULL) {
        printf("Could not open students.txt\n");
        return;
    }
    for (int i = 0; i < sectionCount; i++) {
        fprintf(file, "%d %d", sections[i].studentID, sections[i].registeredCount);
        for (int j = 0; j < sections[i].registeredCount; j++) {
            fprintf(file, " %d", sections[i].registeredSections[j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

void saveTimes(Time times[], int timeCount){
    FILE *file = fopen("time.txt", "w");
    if (file == NULL) {
        printf("Could not open time.txt\n");
        return;
    }
    for (int i=0; i < timeCount; i++){
        fprintf(file, "%d %d", times[i].studentID, times[i].registeredCount);
        for (int j=0; j < times[i].registeredCount; j++){
            fprintf(file, " %s", times[i].registeredTimes[j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

void saveWaitlist(Waitlist waitlists[], int waitlistNum){
    FILE *file = fopen("waitlist.txt", "w");
    if (file == NULL) {
        printf("Could not open waitlist.txt\n");
        return;
    }
    for (int i=0; i < waitlistNum; i++){
        fprintf(file, "%d %d %d", waitlists[i].courseID, waitlists[i].sectionID, waitlists[i].waitlistCount);
        for (int j=0; j < waitlists[i].waitlistCount; j++){
            fprintf(file, " %d", waitlists[i].waitlistArr[j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

void savePrerequisites(Prerequisite prerequisites[], int prerequisiteCount) {
    FILE *file = fopen("prerequisites.txt", "w");
    if (file == NULL) {
        printf("Could not open prerequisites.txt\n");
        return;
    }
    for (int i = 0; i < prerequisiteCount; i++) {
        fprintf(file, "%d %d\n", prerequisites[i].courseID, prerequisites[i].prerequisiteID);
    }
    fclose(file);
}

void saveCourseRec(Recommendation recommendations[], int recommendationCount){
    FILE *file = fopen("recommendations.txt", "w");
    if (file == NULL) {
        printf("Could not open recommendations.txt\n");
        return;
    }
    for (int i = 0; i < recommendationCount; i++) {
        fprintf(file, "%d %d\n", recommendations[i].courseID, recommendations[i].courseRecID);
    }
    fclose(file);
}

