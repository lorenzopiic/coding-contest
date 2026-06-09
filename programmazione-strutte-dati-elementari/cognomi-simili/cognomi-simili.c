#include<stdio.h>
#include<string.h>
#define TASKS 100

int main(void)
{

FILE* fp = fopen("input.txt", "r");
FILE* out = fopen("output1.txt", "w");
if(fp == NULL){ return 1; }
if(out	== NULL) { return 1; }
int K = 0; 

char c1[20];
char c2[20];
char c3[20];


for(unsigned i = 0; i<TASKS; i++) {
	fscanf(fp, "%d %s %s %s", &K, c1, c2, c3);
//	printf("%d >>> %s %s %s \n",K,c1,c2,c3); 
//  
//	0 1 2 3 K = 3; n = 4
//	n i c o l 
//  n i c o s
	if(strncmp(c1,c2,K) == 0 && c1[K] != c2[K]) {
		if(strncmp(c2,c3,K) == 0 && c2[K] != c3[K] && c1[K] != c3[K]){
			fprintf(out, "%s %s %s\n",c1,c2,c3); 
		} else {
			fprintf(out, "%s %s\n",c1,c2); 
			}
	} else {
		if(strncmp(c1,c3,K) == 0 && c1[K] != c3[K]){
			fprintf(out, "%s %s\n",c1,c3); 
		}else{
		   	if(strncmp(c2,c3,K) == 0 && c2[K] != c3[K]){
			fprintf(out, "%s %s\n",c2,c3); 
			}
			else
			{
			fprintf(out, "\n");
			}
		}	
	}
}

fclose(fp);
fclose(out);
return 0; 

}
