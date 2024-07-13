#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include"header.h"
#include"globals.h"

void viewRegisteredCourses(Student students[], int studentID, Course courses[], int courseCount, int studentCount){
    for(int i=0;i<studentCount;i++){
        if(students[i].studentID==studentID){
            for(int j=0;j<students[i].registeredCount;j++){
                int courseIndex=findCourse(courses, courseCount, students[i].registeredCourses[j]);
                printf("%d-%s\n", courses[courseIndex].courseID, courses[courseIndex].courseName);
            }
            break;
        }
    }
    sleep(5);
}

void viewCourses(Student students[], int studentID, Course courses[], int courseCount) {
    int choice;
    for (int i = 0; i < courseCount; i++) {
        int excludeCourse=0;
        for(int j=0;j<students[studentID-1].registeredCount;j++){
            if(courses[i].courseID==students[studentID-1].registeredCourses[j]){
                excludeCourse=1;
                break;
            }
        }
        if(!excludeCourse){
            printf("\033[1;32mCourse ID: \033[0m%d\n", courses[i].courseID);
            printf("\033[1;33mCourse Name: \033[0m%s\n", courses[i].courseName);
            printf("\033[1;36mSection 1: \033[0m%s, \033[1;36mSection 2: \033[0m%s, \033[1;36mSection 3: \033[0m%s\n", 
                courses[i].section1, courses[i].section2, courses[i].section3);
            printf("\033[1;35mCourse Outcomes: \033[0m%s\n", courses[i].courseOutcome);
            printf("\033[1;31mCourse Feedback: \033[0m%s\n", courses[i].courseFeedback);
            printf("\033[1;34mMax Students: \033[0m%d, \033[1;34mCurrent Students In Section 1: \033[0m%d, \033[1;34mCurrent Students in Section 2: \033[0m%d, \033[1;34mCurrent Students in Section 3: \033[0m%d\n", 
                courses[i].maxStudents, courses[i].currentStudentsSec1, courses[i].currentStudentsSec2, courses[i].currentStudentsSec3);
            printf("\033[1;37m---------------------------------------------------------------------------------------------------------------------------------\n\033[0m");
        }
    }
    printf("Press [1] when Done: ");
    scanf("%d",&choice);
    if(choice==1){
        return;
    }
}