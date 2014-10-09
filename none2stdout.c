#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int i = 0;
    
//  fputs(argc, stdout);
    for(i =0; i < argc; i++){
        fputs(argv[i], stdout);
        fputs(", ", stdout);
    }
    fputs("\n", stdout);
}
