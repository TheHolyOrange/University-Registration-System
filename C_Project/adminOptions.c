#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include"header.h"
#include"globals.h"

void addCourse(Course courses[], int *courseCount, Prerequisite prerequisites[], int *prerequisiteCount, Waitlist waitlists[], int *waitlistNum, Workload workloads[], int *workloadCount, Recommendation recommendations[], int *recommendationCount) {
    int choice;
    int newWorkload;
    int recCourse;
    if (*courseCount >= MAX_COURSES) {
        printf("\033[1;31mCannot add more courses.\033[0m\n");
        return;
    }
    int newCourseID;
    printf("Enter Course ID: ");
    scanf("%d", &newCourseID);
    while(findCourse(courses, *courseCount, newCourseID)!=-1) {
        printf("\033[1;31mCourse ID already present. Please enter another ID.\033[0m\n");
        printf("Enter Course ID: ");
        scanf("%d", &newCourseID);
    }

    courses[*courseCount].courseID = newCourseID;

    printf("Enter Course Name: ");
    scanf(" %[^\n]", courses[*courseCount].courseName);
    printf("Enter Section-1 Details: ");
    scanf("%s", courses[*courseCount].section1);
    printf("Enter Section-2 Details: ");
    scanf("%s", courses[*courseCount].section2);
    printf("Enter Section-3 Details: ");
    scanf("%s", courses[*courseCount].section3);
    printf("Enter Course Outcomes: ");
    scanf(" %[^\n]", courses[*courseCount].courseOutcome);
    printf("Enter Course Feedback: ");
    scanf(" %[^\n]", courses[*courseCount].courseFeedback); 
    printf("Enter Maximum Students: ");
    scanf("%d", &courses[*courseCount].maxStudents);
    courses[*courseCount].currentStudentsSec1 = 0;
    courses[*courseCount].currentStudentsSec2 = 0;
    courses[*courseCount].currentStudentsSec3 = 0;
    (*courseCount)++;

    int x=*waitlistNum;
    waitlists[x].courseID = newCourseID;
    waitlists[x].sectionID = 1;
    waitlists[x].waitlistCount = 0;
    x=x+1;
    waitlists[x].courseID = newCourseID;
    waitlists[x].sectionID = 2;
    waitlists[x].waitlistCount = 0;
    x=x+1;
    waitlists[x].courseID = newCourseID;
    waitlists[x].sectionID = 3;
    waitlists[x].waitlistCount = 0;
    x=x+1;
    *waitlistNum=x;
    saveWaitlist(waitlists, *waitlistNum);

    printf("1. Prerequisite\n2. No Prerequisite\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if (choice == 1) {
        prerequisites[*prerequisiteCount].courseID=newCourseID;
        printf("Enter the course ID of the prerequisite: ");
        scanf("%d", &prerequisites[*prerequisiteCount].prerequisiteID);
        (*prerequisiteCount)++;
        savePrerequisites(prerequisites, *prerequisiteCount);
    }

    printf("Enter the workload for the couse: ");
    scanf("%d",&newWorkload);
    workloads[*workloadCount].courseID=newCourseID;
    workloads[*workloadCount].time=newWorkload;
    (*workloadCount)++;
    saveWorkload(workloads, *workloadCount);

    printf("Enter the course ID for recommended future courses if this course is completed: ");
    scanf("%d",&recCourse);
    recommendations[*recommendationCount].courseID=newCourseID;
    recommendations[*recommendationCount].courseRecID=recCourse;
    (*recommendationCount)++;
    saveCourseRec(recommendations, *recommendationCount);

    printf("\x1b[32mCourse Added Successfully!\x1b[0m\n");
    sleep(3);
    saveCourses(courses, *courseCount);
}

int hasDigit(const char* str) {
    while (*str) {
        if (isdigit(*str)) {
            return 1;
        }
        str++;
    }
    return 0;
}

void addStudent(Student students[], int *studentCount, Section sections[], int *sectionCount, Time times[], int *timeCount) {
    if (*studentCount >= MAX_STUDENTS) {
        printf("\033[1;31mCannot add more students.\033[0m\n");
        return;
    }

    int newStudentID;
    printf("Enter Student ID: ");
    scanf("%d", &newStudentID);
    while(findStudent(students, *studentCount, newStudentID) != -1) {
        printf("\033[1;31mStudent ID already present. Please enter another ID.\033[0m\n");
        printf("Enter Student ID: ");
        scanf("%d", &newStudentID);
    }

    times[*studentCount].studentID = newStudentID;
    sections[*studentCount].studentID = newStudentID;
    students[*studentCount].studentID = newStudentID;

    printf("Enter Student Name: ");
    scanf("%s", students[*studentCount].studentName);

    char password[100];
    int validPassword = 0;
    while (!validPassword) {
        printf("Enter Student Password: ");
        scanf("%s", password);
        if (strlen(password) > 4 && hasDigit(password)) {
            validPassword = 1;
        } else {
            printf("\033[1;31mPassword must contain digits and be more than 4 letters. Please try again.\033[0m\n");
        }
    }
    strcpy(students[*studentCount].studentPassword, password);

    students[*studentCount].registeredCount = 0;
    (*studentCount)++;
    (*sectionCount)++;
    (*timeCount)++;
    saveStudents(students, *studentCount);
    saveSections(sections, *sectionCount);
    saveTimes(times, *timeCount);
    printf("\x1b[32mStudent Added Successfully!\x1b[0m\n");
    sleep(3);
}

void viewStudentCourses(Student students[], int studentCount) {
    int studentID;
    printf("Enter Student ID: ");
    scanf("%d", &studentID);
    int studentIndex = findStudent(students, studentCount, studentID);
    if (studentIndex == -1) {
        printf("\033[1;31mStudent not Found\033[0m\n");
        return;
    }
    printf("Student Name: %s\n", students[studentIndex].studentName);
    printf("Registered Courses: ");
    for (int i = 0; i < students[studentIndex].registeredCount; i++) {
        printf("%d ", students[studentIndex].registeredCourses[i]);
    }
    printf("\n");
    sleep(5);
}