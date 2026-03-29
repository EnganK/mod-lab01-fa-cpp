// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cstring>


bool isLatinLetter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

unsigned int faStr1(const char* str) {
    unsigned int count = 0;
    bool inWord = false;
    bool hasDigit = false;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (!isspace(str[i])) {
            inWord = true;
            if (isdigit(str[i]))
                hasDigit = true;
        } else {
            if (inWord && !hasDigit)
                count++;
            inWord = false;
            hasDigit = false;
        }
    }

    if (inWord && !hasDigit)
        count++;
    return count;
}

unsigned int faStr2(const char* str) {
    unsigned int count = 0;
    bool inWord = false;
    bool isValid = true;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (!isspace(str[i])) {
            if (!inWord) {
                if (isupper(str[i]) && isLatinLetter(str[i])) {
                    inWord = true;
                    isValid = true;
                } else {
                    inWord = false;
                    isValid = false;
                }
            } else {
                if (!islower(str[i]) || !isLatinLetter(str[i]))
                    isValid = false;
            }
        } else {
            if (inWord && isValid)
                count++;
            inWord = false;
            isValid = true;
        }
    }

    if (inWord && isValid)
        count++;
    return count;
}

unsigned int faStr3(const char* str) {
    unsigned int totalLength = 0;
    unsigned int wordCount = 0;
    bool inWord = false;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (!isspace(str[i])) {
            if (!inWord)
                inWord = true;
            totalLength++;
        } else {
            if (inWord) {
                wordCount++;
                inWord = false;
            }
        }
    }
    if (inWord)
        wordCount++;
    if (wordCount == 0)
        return 0;
    return (totalLength + wordCount / 2) / wordCount;
}
