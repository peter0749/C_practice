#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100000
#define MEMN 5
#define STRL 50
#define __MAX(X,Y) (X) > (Y) ? (X):(Y)
const char names[MEMN][STRL]
=
{
    "TaeYeon","Tiffany","Jessica","Sunny","SeoHyun"
};
const int ordermap[8] = {2,0,1,4,3};
const int dim_score[8] = {4,3,1,0,2,2,1,3};
int gotten_index[MAX];
int scores[MEMN], final_scores[MEMN];

int main(int argc, char *argv[])
{
    FILE *FIN=NULL, *FOUT=NULL;
    int N, i, j, dime_sum, max_dimesum, crr_score;
    char w, temp[STRL], dime, flag;
    if(argc!=3)
    {
        puts("Dafuq!?");
        return -1;
    }
    if((FIN = fopen(argv[1],"r"))==NULL) return -2;
    if((FOUT = fopen(argv[2],"w"))==NULL) return -3;
    memset(final_scores,0x00,sizeof(final_scores));
    fscanf(FIN,"%d\n",&N);
    while(N--)
    {
        memset(scores,0x00,sizeof(scores));
        max_dimesum = -1;
        for(i=0; i<MEMN; i++)
        {
            fscanf(FIN,"%c",&w);
            dime_sum = 0;
            for(j=0; j<6; j++)
            {
                fscanf(FIN," %c",&dime);
                dime_sum += dim_score[dime-'s'];
            }
            fgetc(FIN);//For '\n'
            scores[w-'A'] = dime_sum;
            //printf("%c\n",w);
            max_dimesum = __MAX(max_dimesum, dime_sum);
        }
        for(i=0, crr_score=0; i<MEMN; i++)
        {
            if(scores[i] == max_dimesum)
            {
                gotten_index[crr_score++] = i;
            }
        }

        max_dimesum = (max_dimesum+crr_score-1) / crr_score;//Ceiling
        fprintf(FOUT,"%d",max_dimesum);
        for(i=0; i<crr_score; i++)
        {
            //gotten_index[i][1] = max_dimesum;
            final_scores[gotten_index[i]] += max_dimesum;
            fprintf(FOUT," %s",names[gotten_index[i]]);
        }
        fputc('\n',FOUT);
        //while(1);
        //puts("Safe");
    }

    max_dimesum = -1;
    for(i=0; i<MEMN; i++)
    {
        max_dimesum = __MAX(max_dimesum, final_scores[i]);
        fprintf(FOUT,"%s %d\n", names[ordermap[i]], final_scores[ordermap[i]]);
    }

    for(i=0,flag=1; i<MEMN; i++)
    {
        if(final_scores[i] == max_dimesum)
        {
            if(flag) flag=0;
            else fputc(' ',FOUT);
            fprintf(FOUT,"%s",names[i],FOUT);
        }
    }
    fputc('\n',FOUT);
    return 0;
}
