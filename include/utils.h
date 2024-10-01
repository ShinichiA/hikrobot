#include <unistd.h>
#include <sys/time.h>
#include <cstring>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <bits/stdc++.h>

#include "include.h"

LogConsole logUtils = LogConsole("utils");

unsigned int microsecond = 1000000;
unsigned int millisecond = 1000;


long getDiffMilliTime(struct timeval startTime, struct timeval endTime) {
    return (endTime.tv_sec - startTime.tv_sec) * 1000 + (endTime.tv_usec - startTime.tv_usec) / 1000.0;
}

void GetDateTime(char *currentTime) {
    memset(currentTime, 0, sizeof currentTime);
    timeval curTime{};
    gettimeofday(&curTime, nullptr);
    int milli = curTime.tv_usec / 1000;

    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", localtime(&curTime.tv_sec));
    sprintf(currentTime, "%s:%03d", buffer, milli);
}

string GetPath(string mac, vector<string> readerBarcode) {
    time_t now = time(0);
    int check = mkdir(PATH_IMAGE, 1);
    if (!check)
        logUtils.info("Image directory created\n");

    string filename = to_string(now) + "_" + mac;

    for (string barcode: readerBarcode) {
        filename += "_";
        filename += barcode;
    }
    filename += ".jpg";
    string path = PATH_IMAGE + filename;
    return path;
}

int GB2312ToUTF8(char *szSrc, size_t iSrcLen, char *szDst, size_t iDstLen) {
    iconv_t cd = iconv_open("utf-8//IGNORE", "gb2312//IGNORE");
    if (0 == cd) {
        return -2;
    }

    memset(szDst, 0, iDstLen);
    char **src = &szSrc;
    char **dst = &szDst;
    if (-1 == (int) iconv(cd, src, &iSrcLen, dst, &iDstLen)) {
        return -1;
    }

    iconv_close(cd);
    return 0;
}


string decToHex(int number) {
    // ans string to store hexadecimal number
    string ans = "";

    while (number != 0) {
        // remainder variable to store remainder
        int rem = 0;

        // ch variable to store each character
        char ch;
        // storing remainder in rem variable.
        rem = number % 16;

        // check if temp < 10
        if (rem < 10) {
            ch = rem + 48;
        } else {
            ch = rem + 55;
        }

        // updating the ans string with the character variable
        ans += ch;
        number = number / 16;
    }

    // reversing the ans string to get the final result
    int i = 0, j = ans.size() - 1;
    while (i <= j) {
        swap(ans[i], ans[j]);
        i++;
        j--;
    }
    return ans;
}

string getLastNumber(string barcode) {
    stringstream streamBarcode(barcode);
    string T, output;

    while (getline(streamBarcode, T, '/')) {
        output = T;
    }
    return output;
}

bool is_number(const std::string &s) {
    return !s.empty() && std::find_if(s.begin(),
                                      s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}