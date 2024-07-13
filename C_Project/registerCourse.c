#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include"header.h"
#include"globals.h"

int checkNumCourse(){
    int num_courses=0;
    printf("Enter the number of courses you want to register: ");
    scanf("%d",&num_courses);
    if(num_courses<4 || num_courses>6){
        printf("\033[1;31mYou can only choose between 4 and 6 courses per semester.\033[0m\n");
        checkNumCourse();
    }
    else{
        return num_courses;
    }
}

int registerCourse(int studentID, Student students[], int studentCount, Course courses[], int courseCount, Prerequisite prerequisites[], int prerequisiteCount, Section sections[], int sectionCount, Time times[], int timeCount, Waitlist waitlists[], int waitlistNum, char date[], Recommendation recommendations[], int recommendationCount, int i, Workload workloads[], int workloadCount) {
    int courseID, sectionNum, choice;
    int studentIndex = findStudent(students, studentCount, studentID);
    
    printf("\033[1;37m---------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
    printf("\033[0;32mRecommended Courses based on your Previously Selected Courses: \n\033[0m");
    printf("\033[1;37m---------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
    for(int i=0;i<students[studentIndex].registeredCount;i++){
        for(int j=0;j<recommendationCount;j++){
            if(recommendations[j].courseID==students[studentIndex].registeredCourses[i]){
                int courseIndex=findCourse(courses, courseCount, recommendations[j].courseRecID);
                printf("\033[1;32mCourse ID: \033[0m%d\n", courses[courseIndex].courseID);
                printf("\033[1;33mCourse Name: \033[0m%s\n", courses[courseIndex].courseName);
                printf("\033[1;37m---------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
            }
        }
    }
    printf("Enter Course ID: ");
    scanf("%d", &courseID);

    if (!firstCourseRegistered && ((courseID / 10) % 10 != 1)) {
        printf("\033[1;31mFirst course must be an elective.\033[0m\n");
        return 2;
    }

    for(int i=0; i<courseCount; i++){
        if(courses[i].courseID == courseID){
            printf("Course ID: %d\nCourse Name: %s\nSection 1: %s\nSection 2: %s\nSection 3: %s\nCourse Outcomes: %s\nCourse Feedback: %s\nMax Students: %d\nCurrent Students In Section 1: %d\nCurrent Students in Section 2: %d\nCurrent Students in Section 3: %d\n",
            courses[i].courseID, courses[i].courseName, courses[i].section1, courses[i].section2, courses[i].section3, courses[i].courseOutcome, courses[i].courseFeedback, courses[i].maxStudents, courses[i].currentStudentsSec1, courses[i].currentStudentsSec2, courses[i].currentStudentsSec3);
            break;
        }
    }

    printf("Enter the Section: ");
    scanf("%d", &sectionNum);

    int courseIndex = findCourse(courses, courseCount, courseID);
    if (courseIndex == -1) {
        printf("\033[1;31mCourse not found.\033[0m\n");
        return 2;
    }


    for(int i = 0; i < students[studentIndex].registeredCount; i++){
        if (students[studentIndex].registeredCourses[i] == courseID) {
            printf("\033[1;31mCourse already finished.\033[0m\n");
            return 2;
        }
    }

    if (!checkPrerequisites(courseID, studentID, students, studentCount, prerequisites, prerequisiteCount)) {
        printf("Prerequisites not met.\n");
        for(int i=0; i < prerequisiteCount; i++){
            if (prerequisites[i].courseID == courseID){
                printf("Required prerequisite's course ID: %d\n", prerequisites[i].prerequisiteID);
            }
        }
        return 2;
    }

    int secFileIndex = (3 * courseIndex) + sectionNum;
    if(sectionNum == 1){
        if (courses[courseIndex].currentStudentsSec1 >= courses[courseIndex].maxStudents) {
            if(waitlists[secFileIndex].waitlistCount >= courses[courseIndex].maxStudents / 10){
                printf("\033[1;31mSection and Waitlist are full. Please try another section.\033[0m\n");
                return 2;
            }
            else{
                printf("1. Try another section\n2. Join Waitlist\n Enter your choice: ");
                scanf("%d", &choice);
                if(choice == 1){
                    return 2;
                }
                else if(choice == 2){
                    if(waitlists[secFileIndex-1].waitlistCount == courses[courseIndex].maxStudents / 10){
                        printf("\033[1;31mWaitlist is full.\033[0m\n");
                        return 2;
                    }
                    waitlists[secFileIndex-1].waitlistArr[waitlists[secFileIndex-1].waitlistCount] = studentID;
                    waitlists[secFileIndex-1].waitlistCount++;
                    printf("Your waitlist number is: %d\n", waitlists[secFileIndex-1].waitlistCount);
                    saveWaitlist(waitlists, waitlistNum);
                    return 2;
                }
                else{
                    printf("\033[1;31mInvalid Choice\033[0m\n");
                    return 2;
                }
            }
        }
        else{
            courses[courseIndex].currentStudentsSec1++;
            printf("\033[1;32mCourse registered successfully.\033[0m\n");
            courseArr[i]=courseID;
            sum=sum+workloads[courseIndex].time;
            students[studentIndex].registeredCourses[students[studentIndex].registeredCount++] = courseID;
            sections[studentIndex].registeredSections[sections[studentIndex].registeredCount++] = sectionNum;
            strcpy(times[studentIndex].registeredTimes[times[studentIndex].registeredCount++], date);
            saveSections(sections, sectionCount);
            saveCourses(courses, courseCount);
            saveStudents(students, studentCount);
            saveTimes(times, timeCount);
            firstCourseRegistered = 1;
            return 0;
        }
    }
    else if(sectionNum == 2){
        if (courses[courseIndex].currentStudentsSec2 >= courses[courseIndex].maxStudents) {
            if(waitlists[secFileIndex].waitlistCount >= courses[courseIndex].maxStudents / 10){
                printf("\033[1;31mSection and Waitlist are full. Please try another section.\033[0m\n");
                return 2;
            }
            else{
                printf("1. Try another section\n2. Join Waitlist\n Enter your choice: ");
                scanf("%d", &choice);
                if(choice == 1){
                    return 2;
                }
                else if(choice == 2){
                    if(waitlists[secFileIndex-1].waitlistCount == courses[courseIndex].maxStudents / 10){
                        printf("\033[1;31mWaitlist is full.\033[0m\n");
                        return 2;
                    }
                    waitlists[secFileIndex-1].waitlistArr[waitlists[secFileIndex-1].waitlistCount] = studentID;
                    waitlists[secFileIndex-1].waitlistCount++;
                    printf("Your waitlist number is: %d\n", waitlists[secFileIndex-1].waitlistCount);
                    saveWaitlist(waitlists, waitlistNum);
                    return 2;
                }
                else{
                    printf("\033[1;31mInvalid Choice\033[0m\n");
                    return 2;
                }
            }
        }
        else{
            courses[courseIndex].currentStudentsSec2++;
            printf("\033[1;32mCourse registered successfully.\033[0m\n");
            courseArr[i]=courseID;
            sum=sum+workloads[courseIndex].time;
            students[studentIndex].registeredCourses[students[studentIndex].registeredCount++] = courseID;
            sections[studentIndex].registeredSections[sections[studentIndex].registeredCount++] = sectionNum;
            strcpy(times[studentIndex].registeredTimes[times[studentIndex].registeredCount++], date);
            saveSections(sections, sectionCount);
            saveCourses(courses, courseCount);
            saveStudents(students, studentCount);
            saveTimes(times, timeCount);
            firstCourseRegistered = 1;
            return 0;
        }
    }
    else if(sectionNum == 3){
        if (courses[courseIndex].currentStudentsSec3 >= courses[courseIndex].maxStudents) {
            if(waitlists[secFileIndex].waitlistCount >= courses[courseIndex].maxStudents / 10){
                printf("\033[1;31mSection and Waitlist are full. Please try another section.\033[0m\n");
                return 2;
            }
            else{
                printf("1. Try another section\n2. Join Waitlist\n Enter your choice: ");
                scanf("%d", &choice);
                if(choice == 1){
                    return 2;
                }
                else if(choice == 2){
                    if(waitlists[secFileIndex-1].waitlistCount == courses[courseIndex].maxStudents / 10){
                        printf("\033[1;31mWaitlist is full.\033[0m\n");
                        return 2;
                    }
                    waitlists[secFileIndex-1].waitlistArr[waitlists[secFileIndex-1].waitlistCount] = studentID;
                    waitlists[secFileIndex-1].waitlistCount++;
                    printf("Your waitlist number is: %d\n", waitlists[secFileIndex-1].waitlistCount);
                    saveWaitlist(waitlists, waitlistNum);
                    return 2;
                }
                else{
                    printf("\033[1;31mInvalid Choice\033[0m\n");
                    return 2;
                }
            }
        }
        else{
            courses[courseIndex].currentStudentsSec3++;
            printf("\033[1;32mCourse registered successfully.\033[0m\n");
            courseArr[i]=courseID;
            sum=sum+workloads[courseIndex].time;
            students[studentIndex].registeredCourses[students[studentIndex].registeredCount++] = courseID;
            sections[studentIndex].registeredSections[sections[studentIndex].registeredCount++] = sectionNum;
            strcpy(times[studentIndex].registeredTimes[times[studentIndex].registeredCount++], date);
            saveSections(sections, sectionCount);
            saveCourses(courses, courseCount);
            saveStudents(students, studentCount);
            saveTimes(times, timeCount);
            firstCourseRegistered = 1;
            return 0;
        }
    }

    return 0;
}