#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include"header.h"
#include"globals.h"

int main() {
    Course courses[MAX_COURSES];
    Student students[MAX_STUDENTS];
    Prerequisite prerequisites[MAX_PREREQUISITES];
    Admin admins[MAX_ADMINS];
    Section sections[MAX_STUDENTS];
    Time times[100];
    Waitlist waitlists[MAX_WAITLIST_COUNT];
    Recommendation recommendations[MAX_COURSEREC_COUNT];
    Workload workloads[MAX_WORKLOAD_COUNT];

    int courseCount = 0, studentCount = 0, prerequisiteCount = 0; 
    int adminCount = 0;
    int sectionCount = 0;
    int timeCount = 0;
    int waitlistNum = 0;
    int courserecCount = 0;
    int recommendationCount = 0;
    int workloadCount = 0;
    int loginChoice=0, choice, num_courses=0, studentID;
    char date[MAX_TIME_LENGTH];
    int marks;
    int workTime;
    int workChoice;

    loadCourses(courses, &courseCount);
    loadStudents(students, &studentCount);
    loadPrerequisites(prerequisites, &prerequisiteCount, students);
    loadAdmin(admins, &adminCount);
    loadSection(sections, &sectionCount);
    loadTime(times, &timeCount);
    loadWaitlist(waitlists, &waitlistNum);
    loadCourseRec(recommendations, &recommendationCount);
    loadWorkload(workloads, &workloadCount);

    system("cls");
    while(captchaFlag==0){
        srand(time(0));
        int captchaLength = 6;
        char captcha[captchaLength + 1];
        generateCaptcha(captcha, captchaLength);
        printf("CAPTCHA: %s\n", captcha);
        char userInput[captchaLength + 1];
        printf("Enter the CAPTCHA: ");
        scanf("%s", userInput);
        if (strcmp(captcha, userInput) == 0) {
            printf("\033[1;32mCAPTCHA verified successfully!\033[0m\n");
            captchaFlag=1;
            sleep(2);
        } else {
            printf("\033[1;31mCAPTCHA verification failed. Please try again.\033[0m\n");
            sleep(2);
            main();
        }
    }
    

    system("cls");
    printf("\033[1;33m===========================================\n\033[0m");
    printf("\033[1;34m%15sMENU\033[0m\n", "");
    printf("\033[1;33m===========================================\n\033[0m");
    printf("%10s1.Admin Login\n", "");
    printf("%10s2.Student Login\n", "");
    printf("\033[1;33m===========================================\n\033[0m");
    printf("Enter your choice: ");
    scanf("%d",&loginChoice);
    if(loginChoice==1){
        if(adminLogin(admins, &adminCount)==1){
            do{
            system("cls");
            printf("\033[1;33m===========================================\n\033[0m");
            printf("\033[1;34m%15sADMIN MENU\033[0m\n", "");
            printf("\033[1;33m===========================================\n\033[0m");
            printf("%10s1. Add Course\n", "");
            printf("%10s2. Add Student\n", "");
            printf("%10s3. View Student Courses\n", "");
            printf("%10s4. Exit\n", "");
            printf("\033[1;33m===========================================\n\033[0m");
            printf("Enter your choice: ");
            scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        addCourse(courses, &courseCount, prerequisites, &prerequisiteCount, waitlists, &waitlistNum, workloads, &workloadCount, recommendations, &recommendationCount);
                        break;
                    case 2:
                        addStudent(students, &studentCount, sections, &sectionCount, times, &timeCount);
                        break;
                    case 3:
                        viewStudentCourses(students, studentCount);
                        break;
                    case 4:
                        main();
                        break;
                    default:
                        printf("\033[1;31mInvalid choice.\033[0m\n");
                }
            } while (choice != 5);
        }
        else{
            printf("\033[1;31mInvalid credentials.\033[0m\n");
            sleep(2);
            main();
        }
    }
    if(loginChoice==2){
        studentID=studentLogin(students, &studentCount);
        if(studentID){
            do { 
            system("cls");
            printf("\033[1;33m===========================================\n\033[0m");
            printf("\033[1;34m%15sSTUDENT MENU\033[0m\n", "");
            printf("\033[1;33m===========================================\n\033[0m");
            printf("%10s1. Register Course\n", "");
            printf("%10s2. View Registered Courses\n", "");
            printf("%10s3. View Available Courses\n", "");
            printf("%10s4. Drop Course\n", "");
            printf("%10s5. Exit\n", "");
            printf("\033[1;33m===========================================\n\033[0m");

            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    printf("Enter your academic score (out of 100): ");
                    scanf("%d",&marks);
                    printf("Enter how many hours per week you'd like to engage: ");
                    scanf("%d",&workTime);
                    num_courses=checkNumCourse();
                    printf("Enter Today's Date (dd/mm/yyyy): ");
                    scanf("%s", &date);
                    for(int i = 0; i < num_courses; i++){
                        if(registerCourse(studentID, students, studentCount, courses, courseCount, prerequisites, prerequisiteCount, sections, sectionCount, times, timeCount, waitlists, waitlistNum, date, recommendations, recommendationCount, i, workloads, workloadCount) == 2){
                        i = i - 1;
                        }
                    }
                    
                    if ((float)workTime + ((float)marks / 2) > 2.0f * (float)sum){
                        printf("Success Rate=100 percent");
                    }

                    if ((float)workTime + ((float)marks / 2) < 2.0f * (float)sum) {
                        printf("Success Rate= %f", (((float)workTime + ((float)marks / 2))*100) / (2.0f * (float)sum));
                    }


                    for(int i=0;i<6;i++){
                        courseArr[i]=0;
                    }
                    sum=0;
                    sleep(5);
                    break;
                case 2:
                    viewRegisteredCourses(students, studentID, courses, courseCount, studentCount);
                    break;
                case 3:
                    viewCourses(students, studentID, courses, courseCount);
                    break;
                case 4:
                    printf("Enter the course ID to drop: ");
                    int courseID;
                    scanf("%d", &courseID);
                    dropCourse(studentID, courseID, students, studentCount, sections, sectionCount, courses, courseCount, times, timeCount, waitlists, waitlistNum);
                    break;
                case 5:
                    main();
                    break;
                default:
                    printf("\033[1;31mInvalid choice.\033[0m\n");
                }
            } while (choice != 6);
        }
        else{
            printf("\033[1;31mInvalid credentials.\033[0m\n");
            sleep(2);
            main();
        }
    }
    else{
        printf("\033[1;31mInvalid choice.\033[0m\n");
    }
    return 0;
}