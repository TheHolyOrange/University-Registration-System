#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include"header.h"
#include"globals.h"

void generateCaptcha(char *captcha, int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < length; i++) {
        captcha[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    captcha[length] = '\0';
}