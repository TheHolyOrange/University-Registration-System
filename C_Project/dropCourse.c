#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include"header.h"
#include"globals.h"

void dropCourse(int studentID, int courseID, Student* students, int studentCount, Section* sections, int sectionCount, Course courses[], int courseCount, Time times[], int timeCount, Waitlist waitlists[], int waitlistNum) {
    char date[MAX_TIME_LENGTH];
    char registeredTime[MAX_TIME_LENGTH];
    int firstWaitlistedStudentID;
    printf("Enter Today's Date (dd/mm/yyyy): ");
    scanf("%s", &date);
    int registeredSection;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == studentID) {
            int found = 0;
            for (int j = 0; j < students[i].registeredCount; j++) {
                if (students[i].registeredCourses[j] == courseID) {
                    registeredSection=sections[i].registeredSections[j];
                    strcpy(registeredTime,times[i].registeredTimes[j]);
                    if(checkDateDiff(registeredTime, date)==0){
                        printf("\033[1;31mYou can only drop a course within two weeks of registering!\033[0m\n");
                        sleep(3);
                        return;
                    }
                    found = 1;
                }
                if (found && j < students[i].registeredCount - 1) {
                    students[i].registeredCourses[j] = students[i].registeredCourses[j + 1];
                    sections[i].registeredSections[j] = sections[i].registeredSections[j + 1];
                    strcpy(times[i].registeredTimes[j],times[i].registeredTimes[j + 1]);
                }
            }
            if (found) {
                students[i].registeredCount--;
                sections[i].registeredCount--;
                times[i].registeredCount--;

                saveSections(sections, sectionCount);
                saveStudents(students, studentCount);
                saveTimes(times, timeCount);
                printf("Course %d dropped successfully for student %d.\n", courseID, studentID);
                sleep(3);

                if(registeredSection==1){
                    for(int k=0; k<courseCount;k++){
                        if(courses[k].courseID==courseID){
                            courses[k].currentStudentsSec1-=1;
                        }
                    }
                }
                if(registeredSection==2){
                    for(int k=0; k<courseCount;k++){
                        if(courses[k].courseID==courseID){
                            courses[k].currentStudentsSec2-=1;
                        }
                    }
                }
                if(registeredSection==3){
                    for(int k=0; k<courseCount;k++){
                        if(courses[k].courseID==courseID){
                            courses[k].currentStudentsSec3-=1;
                        }
                    }
                }
                saveCourses(courses,courseCount);

                for(int i=0;i<waitlistNum;i++){
                    if(waitlists[i].courseID==courseID && waitlists[i].sectionID==registeredSection && waitlists[i].waitlistCount!=0){
                        firstWaitlistedStudentID=waitlists[i].waitlistArr[0];
                        for(int j=0;j<waitlists[i].waitlistCount;j++){
                            waitlists[i].waitlistArr[j]=waitlists[i].waitlistArr[j+1];
                        }
                        waitlists[i].waitlistCount=waitlists[i].waitlistCount-1;
                        for(int k=0;k<studentCount;k++){
                            if(students[k].studentID==firstWaitlistedStudentID){
                                students[k].registeredCourses[students[k].registeredCount]=courseID;
                                students[k].registeredCount=students[k].registeredCount+1;
                                sections[k].registeredSections[sections[k].registeredCount]=registeredSection;
                                sections[k].registeredCount=sections[k].registeredCount+1;
                                strcpy(times[k].registeredTimes[times[k].registeredCount],date);
                                times[k].registeredCount=students[k].registeredCount+1;
                                break;
                            }
                        }
                        for(int a=0;a<courseCount;a++){
                            if(courses[a].courseID==courseID){
                                if(registeredSection==1){
                                    courses[a].currentStudentsSec1++;
                                    break;
                                }
                                else if(registeredSection==2){
                                    courses[a].currentStudentsSec2++;
                                    break;
                                }
                                else if(registeredSection==3){
                                    courses[a].currentStudentsSec3++;
                                    break;
                                }
                            }
                        }
                    }

                }
                saveWaitlist(waitlists, waitlistNum);
                saveStudents(students, studentCount);
                saveSections(sections, sectionCount);
                saveTimes(times, timeCount);
                saveCourses(courses, courseCount);
            } 
            else {
                printf("Course %d not found for student %d.\n", courseID, studentID);
                sleep(3);
            }
            return;
        }
    }
    printf("Student %d not found.\n", studentID);
    sleep(3);
}