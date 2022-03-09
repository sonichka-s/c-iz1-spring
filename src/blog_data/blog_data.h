#pragma once

typedef struct {
    char* name;
    char* content;
    char** tags;
    char** comments;
    int likes;
    int day;
    int month;
    int year;

} Post;

Post* post(char* name, char* content, char** tags, char** comments, int likes, int d, int m, int y);