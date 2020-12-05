#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int main(){
	int i;
	for(i = 0; i < 255; ++i){
		printf("Error:%s\n", strerror(i), i);
	}
	return 0;
}