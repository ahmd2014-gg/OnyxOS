#ifndef STRING_H
#define STRING_H

int strlen(const char* str);
int strcmp(const char* str1, const char* str2);
void strcpy(char* dest, const char* src);
void strcat(char* dest, const char* src);
int strncmp(const char* str1, const char* str2, int n);

#endif
