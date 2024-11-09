// txcmd.cpp:  Program to control RTS and DTS output lines
// Author: Martin Dittrich
// Creation Date: 2024-11-02

#include <cstdio>
#include <iostream>
#include <conio.h>
#include "windows.h"

int main(int argc, char* argv[])
{
    int count = 0;

    while(argv[++ count] != NULL);

    if (-- count != 2 || argv[1] == NULL)
    {
        printf("Error wrong Arguments! Getting %i of 2 needed\n", count);
        printf("Syntax: txcmd <port> <function>\n");
        printf("1       set DTR\n");
        printf("2       reset DTR\n");
        printf("3       set CTS\n");
        printf("4       reset CTS\n");
        return -1;
    }

    long funcComm = strtol(argv[2], NULL, 10);

    HANDLE hComm = CreateFileA(
        argv[1],
        GENERIC_READ | GENERIC_WRITE,
        0,
        0,
        OPEN_EXISTING,
        0,
        NULL
    );

    if (hComm == INVALID_HANDLE_VALUE)
    {
        printf("Cannot open %s\n", argv[1]);
        return -1;
    }

    switch (funcComm)
    {
        case 1:
            if(EscapeCommFunction(hComm, SETDTR))
                printf("Setting DTR\n");
            else
                printf("Error Setting DTR\n");
            break;
        case 2:
            if(EscapeCommFunction(hComm, CLRDTR))
                printf("Clearing DTR\n");
            else
                printf("Error Clearing DTR\n");
            break;
        case 3:
            if(EscapeCommFunction(hComm, SETRTS))
                printf("Setting CTS\n");
            else
                printf("Error Setting CTS\n");
            break;
        case 4:
            if(EscapeCommFunction(hComm, CLRRTS))
                printf("Clearing CTS\n");
            else
                printf("Error Clearing CTS\n");
            break;
    }

    return 0;
}
