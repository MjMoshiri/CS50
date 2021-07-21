//link to the problem description
//https://cs50.harvard.edu/x/2021/psets/2/readability/
//link to the cs50 lib
//https://cs50.harvard.edu/x/2021/psets/2/substitution/
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
bool isInputValid(char (*argv)[])
{
    bool switch1 = false; // a switch1 to determine whether a char is in the key or not r(remains ON if a char is not in the key)
    if (strlen((*argv)) == 26)
    {
        for (char c = 65; c < 91 && !switch1; c++)
        {
            switch1 = !switch1;
            for (size_t i = 0; i < 26 && switch1; i++)
            {
                if (c == (*argv)[i])
                    switch1 = !switch1; //turn off the switch if found the alphabet in the key
            }
        }
    }
    else
        return false;

    if (switch1)
        return false;
    else
        return true;
}
string cipher(string line, char (*upKey)[])
{
    for (size_t i = 0 ,n=strlen(line); i < n; i++)
    {
        if(line[i]>64 && line[i]<91)
        line[i]=(*upKey)[line[i]-65];//this will swap a Uppercase char with the equivalent char in the key
        else if(line[i]>96 && line[i]<123)
        line[i]=(*upKey)[line[i]-97]+32;//this will swap a Lowercase char with the Lowercase equivalent char in the key (+32 is for shifting the ascii code of char to Lowercase)
    }
    return line;
    
}
int main(int argc, char const *argv[])
{
    char upKey[] = "12345678912345678912345678"; // this will change to Uppercase-only version of key
    if (argc == 2)
    {
        for (size_t i = 0, n = strlen(argv[1]); i < n; i++)
        {
            upKey[i] = toupper(argv[1][i]);
        }
        if (isInputValid(&upKey))
        {
            string input_line = get_string("plaintext:");
            string test;
            printf("ciphertext:%s",cipher(input_line,&upKey));
            return 0;
        }
        else
        {
            printf("Invalid Input\n");
            return 1;
        }
    }
    else
    {
        printf("Invalid Input\n");
        return 1;
    }

    return 0;
}
