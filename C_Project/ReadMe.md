
# University Registration System using C

  
## Table of Contents

- [University Registration System using C](#university-registration-system-using-c)

- [Table of Contents](#table-of-contents)

- [Introduction](#introduction)

- [Features](#features)

- [Prerequisites](#prerequisites)

-  [Execution](#execution)

- [File Management](#file-management)

- [Contributors](#contributors)


  
  

## Introduction

Welcome to the University Registration System, developed using C. This project represents a simple university registration system for CSE course. The goal is to register a student to various courses, checking for pre-requisites, alloting them to waitlists if necessary and dropping a course within a time period of 2 weeks.

  

## Features

- User-Friendly Interface

- Admin Menu with Add Student/Add Course Function

- Captcha Verification

- Course Recommendation based on Previously Selected Course

- Success Rate for Completion of Selected Courses

  

## Prerequisites

- C Compiler (e.g., GCC)

 ## Execution
```sh

tanisha.bat

```

  

## File Management

### main.c

Contains the main() function which acts as the menu driver for the program.

  

### registerCourse.c
Contains the checkNumCourse() function and the registerCourse() function. checkNumCourse() allows the user to register for only 4 to 6 courses per semester. registerCourse() function allows the user to register for the course.


  

### globals.c

This file consists the declaration of each global variables used.

  

### viewCourse.c

Consists of viewRegisteredCourses() function and viewCourses() function. viewRegisteredCourses allows the students the view the already registered courses. viewCourses function allows the student to view all the courses that is still available for the student to register.

  

### dropCourse.c
It consists of the dropCourse() function which allows the user to drop a course within a time period of 2 weeks.


### checkPrerequisite.c
It consists of the checkPrerequisites() function which checks if the student had finished the respective pre-requisite course for the given selected course.


### captcha.c
It consists of generateCaptcha() function which generates a random sequence of characters and numbers.


### adminOptions.c
It consists of the addCourse(), hasDigit(), viewStudentCourses() and add Student() function. addCourse function lets the admin to add a course to the courses.txt database. hasDigit() checks if the given string has a digit. addStudent() function allows the admin to add a student to the students.txt database. viewStudentCourses() function allows the admin to view the courses selected by the respective students.


### save.c
This file has all the functions that lets us to update the .txt files after a change has been done.


### load.c
This file has all the functions that lets us to read all the .txt files and store in structures.


### date.c
This file has all the functions that checks whether the difference between two dates is more than 14 days or not.


### findValue.c
This file has the findCourse function which returns the course index for the repective courseID given and similarly findStudent function returns the student index for the respective studentID given.


### loginProcess.c
It consists of the adminLogin() function and the studentLogin() function which authenticates the username and password given by the admin and student respectively.



### admins.txt
adminID adminName adminPassword


### students.txt
studentID studentName studentPassword registeredCount registeredCourses 


### section.txt
studentID registeredCount registeredSections[]


### time.txt
studentID registeredCount registeredTimes[]


### courses.txt
courseID;courseName;section1[];section2[];section3[];courseOutcome;courseFeedback;maxStudents;currentStudentsSec1;currentStudentsSec2;currentStudentsSec3


### waitlist.txt
courseID sectionID waitlistCount waitlistArr[]


### workload.txt
courseID time


## Contributors

-  **Tanisha Sriram-3122235001144**

-  **Teja Sree-3122235001145**

-  **V.Yadushree-3122235001165**