#ifndef __COUNTFILE_H
#define __COUNTFILE_H
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

void count();

int lineCount();

int charCount();

int wordCount();
