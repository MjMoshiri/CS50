//link to the problem description
//https://cs50.harvard.edu/x/2021/psets/2/readability/
//lint to the cs50 lib
//https://cs50.readthedocs.io/libraries/cs50/c/
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    string line;
    int letters,sentences,words;
    letters=0;
    sentences=0;
    words=1;
    float cli; //stands for Coleman-Liau index
    line =get_string("Text : ");
    for (size_t i = 0 , n = strlen(line); i < n; i++)
    {
       if ((line[i]<='z' && line[i]>= 'a' )  || (line[i]<='Z' && line[i]>='A'))
       {
           letters+=1;
       }
       else if (line[i]==' ')
       {
           words+=1;
       }
       else if (line[i]=='.' || line[i]=='?' ||line[i]=='!')
       {
           sentences+=1;
       }
    }
    cli = 0.0588 * ((float) letters/ words)*100 - 0.296 *((float) sentences/ words)*100  - 15.8;  
    if (cli < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (cli >=16)
    {
        printf("Grade 16+\n");
    }
    else
    printf("Grade %i\n", (int) round(cli) );
    return 0;
}
