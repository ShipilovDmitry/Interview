#pragma once

#include <iostream>

void reverseStringBuffer(char *szBuffer, char endSymbol = '\0') {
    char *pEnd = szBuffer;
    while (*pEnd != endSymbol) {
        ++pEnd;
    }

    while (szBuffer < --pEnd) {
        char temp = *szBuffer;
        *szBuffer = *pEnd;
        *pEnd = temp;

        ++szBuffer;
    }
}

size_t countWords(char *buffer) {
    size_t count = 0;
    while (true) {
        bool nullTerminate = false;
        while (*buffer != ' ') {
            if (*buffer == '\0') {
                nullTerminate = true;
                break;
            }
            ++buffer;
        }
        ++count;

        if (nullTerminate) {
            break;
        }

        while (*buffer == ' ') {
            ++buffer;
        }
    }

    return count;
}

void reverseWordsOrder(char *buffer) {
    reverseStringBuffer(buffer);
    size_t const wordsCount = countWords(buffer);
    if (wordsCount == 0) {
        return;
    }

    size_t currentWord = 0;
    while (true) {
        ++currentWord;
        while (*buffer == ' ') {
            ++buffer;
        }

        char const endSymbol = currentWord == wordsCount ? '\0' : ' ';
        reverseStringBuffer(buffer, endSymbol);

        bool endOfString = false;
        while (*buffer != ' ') {
            if (*buffer == '\0') {
                endOfString = true;
                break;
            }
            ++buffer;
        }

        if (endOfString) {
            break;
        }
    }
}

void reverseBuffer(std::string &buffer, size_t fromIndex, size_t toIndex) {
    for (size_t index = 0; fromIndex + index < (fromIndex + toIndex) / 2; ++index) {
        std::swap(buffer[fromIndex + index], buffer[toIndex - 1 - index]);
    }
}

void reverseWordsOrder(std::string &buffer) {
    if (buffer.empty()) {
        return;
    }

    reverseBuffer(buffer, 0, buffer.size());
    size_t begin = 0;
    while (begin < buffer.size()) {
        size_t end = buffer.find(' ', begin);
        if (end == std::string::npos) {
            end = buffer.size();
        }

        reverseBuffer(buffer, begin, end);
        begin = ++end;
    }
}

void testReorder() {
    char *str = new char[15];
    str[0] = 'd';
    str[1] = 'i';
    str[2] = 'm';
    str[3] = 'a';
    str[4] = ' ';
    str[5] = 'l';
    str[6] = 'o';
    str[7] = 'v';
    str[8] = 'e';
    str[9] = 's';
    str[10] = ' ';
    str[11] = 'c';
    str[12] = '+';
    str[13] = '+';
    str[14] = '\0';


    std::string buffer{"dima loves c++"};
//    reverseBuffer(buffer, 0, buffer.size());
//    std::cout << buffer;

    reverseWordsOrder(buffer);
    std::cout << buffer;

//    std::cout << str << std::endl;
//    reverseWordsOrder(str);
//    std::cout << str << std::endl;
    delete[] str;
}
