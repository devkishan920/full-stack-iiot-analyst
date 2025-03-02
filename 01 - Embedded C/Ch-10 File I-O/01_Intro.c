// Since, processing takes place in RAM & it is volatile. Hence to persist data foe longer time & more than  RAM size, "FILES" are used.

// FILE is a data stored in Storage Device.

// Using c, one can read or write a file

/*---FILE POINTER---*/
// - "FILE" is a "STRUCTURE POINTER" used for accessing a file from a c program.

// Syntax - FILE *ptr;

// before reading or writing a file, it must be opened, which can be done as follows :

/*  
    FILE *ptr;
    ptr = fopen("filename.extension","mode");
*/

/*
    MODES are as follows : 

    r   -   reading mode(For text file, reads character by character). If file does not exist, (fopen) returns NULL

    rb   -   reading (in binary) mode. If file does not exist, (fopen) returns NULL

    w   -   writing mode(For text file, writes character by character). If file exists, content will be overwrited, else it will be created

    wb   -   writing (in binary) mode. If file exists, content will be overwrited, else it will be created

    a   -   append mode (adds new content at end of file content). If file does not exist, it will be created
*/
