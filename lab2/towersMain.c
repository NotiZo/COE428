#include <stdlib.h>
#include <stdio.h>
#include "towers.h"

int main(int argc, char **argv)
{
	int n = 3;
	int from = 1, dest = 2;
    int x;
	if(argc == 2){
		n = atoi(argv[1]);
    }
    else if(argc==3){
        printf("you need to input a destination");
        exit(0);
    }
	else if(argc == 4){
		n=atoi(argv[1]);
		from=atoi(argv[2]);
		dest=atoi(argv[3]);
		if(dest>3||from>3){
			printf("the two towers have to be from 1-3");
			exit(0);}
		else if(dest==from){
			printf("the destination and previous tower have to be different");
			exit(0);
		}
	}
	towers(n, from, dest);
    	exit(0);
}

