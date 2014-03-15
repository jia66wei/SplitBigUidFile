#include<stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#define splitNUM 4

void ReadFile(char *infile, char *outdir, int nums)
{
    FILE *fp1, *fp2[nums];
    if((fp1=fopen(infile,"r"))==NULL)
    {
        printf("can not open file\n");
        return;
    }
    int i;
    for(i = 0 ; i < nums ; i ++)
    {
        char file[1000];
        sprintf(file,"%s/%d.txt",outdir,i);
    //  printf("%s\n",file);
        if((fp2[i] = fopen(file,"a"))==NULL)
        {
            printf("can't open file: %s",file);
        }
    }
    int64_t key,value;
    int mod;
    while(fscanf(fp1,"%lld,%lld",&key,&value) != EOF)
    {
        mod = key % nums;
        //printf("%lld\t%lld\n",key,value);
        fprintf(fp2[mod],"%lld,%lld\n",key,value);
    }

}

int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        printf("need:exe,inputfile,outputdir\n");
        return 0;
    }
    int splitNum = atoi(argv[3]);
    ReadFile(argv[1],argv[2],splitNum);

    return 0;
}

