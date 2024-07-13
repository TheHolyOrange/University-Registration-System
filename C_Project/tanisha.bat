gcc header.h
gcc globals.h
gcc -c globals.c -o globals.o
gcc -c main.c -o main.o
gcc -c findValue.c -o findValue.o
gcc -c date.c -o date.o
gcc -c loginProcess.c -o loginProcess.o
gcc -c load.c -o load.o
gcc -c save.c -o save.o
gcc -c registerCourse.c -o registerCourse.o
gcc -c adminOptions.c -o adminOptions.o
gcc -c captcha.c -o captcha.o
gcc -c checkPrerequisite.c -o checkPrerequisite.o
gcc -c dropCourse.c -o dropCourse.o
gcc -c viewCourse.c -o viewCourse.o
gcc globals.o findValue.o date.o loginProcess.o load.o save.o registerCourse.o adminOptions.o captcha.o checkPrerequisite.o dropCourse.o viewCourse.o main.o -o my_program
my_program