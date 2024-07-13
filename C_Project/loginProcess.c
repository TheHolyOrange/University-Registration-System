#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include"header.h"
#include"globals.h"

int adminLogin(Admin admins[],int *adminCount){
    char username[MAX_NAME_LENGTH];
    char password[MAX_PW_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    int authenticated = 0;
    for (int i = 0; i < *adminCount; i++) {
        if (strcmp(admins[i].adminName, username) == 0 && strcmp(admins[i].adminPassword, password) == 0) {
            authenticated = 1;
            break;
        }
    }
    return authenticated;
}

int studentLogin(Student students[],int *studentCount){
    char username[MAX_NAME_LENGTH];
    char password[MAX_PW_LENGTH];
    
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    int authenticated = 0;
    for (int i = 0; i < *studentCount; i++) {
        if (strcmp(students[i].studentName, username) == 0 && strcmp(students[i].studentPassword, password) == 0) {
            authenticated = students[i].studentID;
            break;
        }
    }
    return authenticated;
}