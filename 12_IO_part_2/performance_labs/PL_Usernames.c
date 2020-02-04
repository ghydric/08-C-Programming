/*
Author: Mitch Hydrick
Date: 1/27/2020
Title: Performance Lab: Usernames
Synopsis:
    1. Prompt the user for the number of students.
    2. Read the first, middle, and last name for each student.
    3. Remove any newline characters from all strings.
    4. Append each name to a “class roster” file in the following format:
        - For George Herbert Dubya Bush, write the following to the the file...George H. Dubya Bush has a username of ghdbush.
    Note: BUILD THOSE SAFETY CHECKS!!!!!
*/

// import necessary libraries
#include <stdio.h>

int flush_buffer(void){
    // flush all of the input buffer so no erroneous characters will be part of the input
	int c = getchar();  // random variable declared to be a placeholder for any erroneous characters in the input buffer to be processed
	while (c != '\n' && c != '\r' && c != EOF){
        c = getchar();
    }
    return 0;
}

int main(void){

    int num_students = 0;
    char * students[9] = {0};
    printf("Enter the number of students (max=9):\n");
    scanf("%1d", &num_students);

    flush_buffer();
    
    for (int i = 0; i <= num_students; i++){
        char student_name[61] = {0};
        printf("Enter the first, middle, and last name for the student separated by spaces (' '):\n");
        scanf("%60s", &student_name);
        students[i] = student_name;
        flush_buffer();
    }

    return 0;
}