#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_COURSES 60
#define MAX_STUDENTS 15
#define MAX_NAME_LENGTH 50
#define MAX_REGISTERED_COURSES 100
#define MAX_PREREQUISITES 10
#define MAX_PW_LENGTH 50
#define MAX_ADMINS 10
#define MAX_SECTION_LENGTH 50
#define MAX_COURSEOUTCOME_LENGTH 50
#define MAX_COURSEFEEDBACK_LENGTH 50
#define MAX_TIME_LENGTH 11
#define MAX_WAITLIST_COUNT 100
#define MAX_COURSEREC_COUNT 100
#define MAX_WORKLOAD_COUNT 100

typedef struct {
    int courseID;
    char courseName[MAX_NAME_LENGTH];
    char section1[MAX_SECTION_LENGTH];
    char section2[MAX_SECTION_LENGTH];
    char section3[MAX_SECTION_LENGTH];
    char courseOutcome[MAX_COURSEOUTCOME_LENGTH];
    char courseFeedback[MAX_COURSEFEEDBACK_LENGTH];
    int maxStudents;
    int currentStudentsSec1;
    int currentStudentsSec2;
    int currentStudentsSec3;
} Course;

typedef struct {
    int studentID;
    char studentName[MAX_NAME_LENGTH];
    char studentPassword[MAX_PW_LENGTH];
    int registeredCourses[MAX_REGISTERED_COURSES];
    int registeredCount;
} Student;

typedef struct {
    int courseID;
    int prerequisiteID;
} Prerequisite;

typedef struct {
    int adminID;
    char adminName[MAX_NAME_LENGTH];
    char adminPassword[MAX_PW_LENGTH];
} Admin;

typedef struct {
    int courseID;
    int sectionID;
    int waitlistCount;
    int waitlistArr[100];
}Waitlist;

typedef struct{
    int studentID;
    int registeredCount;
    int registeredSections[100];
}Section;

typedef struct{
    int studentID;
    int registeredCount;
    char registeredTimes[MAX_STUDENTS][MAX_TIME_LENGTH];
}Time;

typedef struct{
    int courseID;
    int courseRecID;
}Recommendation;

typedef struct{
    int courseID;
    int time;
}Workload;

int findCourse(Course courses[], int courseCount, int courseID);
int findStudent(Student students[], int studentCount, int studentID);
int checkNumCourse();
int is_leap_year(int year);
int days_in_month(int month, int year);
int date_to_days(int day, int month, int year);
int abs(int x);
int checkDateDiff(char *date1, char *date2);
int adminLogin(Admin admins[],int *adminCount);
int studentLogin(Student students[],int *studentCount);
void loadCourses(Course courses[], int *courseCount);
void saveCourses(Course courses[], int courseCount);
void loadStudents(Student students[], int *studentCount);
void loadAdmin(Admin admins[], int *adminCount);
void loadSection(Section sections[], int *sectionCount);
void loadTime(Time times[], int *timeCount);
void loadWaitlist(Waitlist waitlists[], int *waitlistNum);
void loadWorkload(Workload workloads[], int *workloadCount);
void saveWorkload(Workload workloads[], int workloadCount);
void saveStudents(Student students[], int studentCount);
void saveSections(Section sections[],int sectionCount);
void saveTimes(Time times[], int timeCount);
void saveWaitlist(Waitlist waitlists[], int waitlistNum);
void loadPrerequisites(Prerequisite prerequisites[], int *prerequisiteCount, Student students[]);
void savePrerequisites(Prerequisite prerequisites[], int prerequisiteCount);
void loadCourseRec(Recommendation recommendations[], int *recommendationCount);
void saveCourseRec(Recommendation recommendations[], int recommendationCount);
void addCourse(Course courses[], int *courseCount, Prerequisite prerequisites[], int *prerequisiteCount, Waitlist waitlists[], int *waitlistNum, Workload workloads[], int *workloadCount, Recommendation recommendations[], int *recommendationCount);
int hasDigit(const char* str);
void addStudent(Student students[], int *studentCount, Section sections[], int *sectionCount, Time times[], int *timeCount);
int checkPrerequisites(int courseID, int studentID, Student students[], int studentCount, Prerequisite prerequisites[], int prerequisiteCount);
int registerCourse(int studentID, Student students[], int studentCount, Course courses[], int courseCount, Prerequisite prerequisites[], int prerequisiteCount, Section sections[], int sectionCount, Time times[], int timeCount, Waitlist waitlists[], int waitlistNum, char date[], Recommendation recommendations[], int recommendationCount, int i, Workload workloads[], int workloadCount);
void viewCourses(Student students[], int studentID, Course courses[], int courseCount);
void viewStudentCourses(Student students[], int studentCount);
void dropCourse(int studentID, int courseID, Student* students, int studentCount, Section* sections, int sectionCount, Course courses[], int courseCount, Time times[], int timeCount, Waitlist waitlists[], int waitlistNum);
void viewRegisteredCourses(Student students[], int studentID, Course courses[], int courseCount, int studentCount);
void generateCaptcha(char *captcha, int length);
#endif