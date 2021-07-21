//link to the problem description
//https://cs50.harvard.edu/x/2021/psets/2/readability/
//link to the cs50 lib
//https://cs50.readthedocs.io/libraries/cs50/c/
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>

//cli stands for Coleman-Liau index and vars stands for variable
typedef struct
{
    int letters;
    int words;
    int sentences;
} cli_vars;

//this function calculates the words ,letters and sentences in paragraph
cli_vars calculator(string line)

{
    cli_vars temp;
    temp.letters = 0;
    temp.sentences = 0;
    temp.words = 1;
    for (size_t i = 0, n = strlen(line); i < n; i++)
    {
        if ((line[i] <= 'z' && line[i] >= 'a') || (line[i] <= 'Z' && line[i] >= 'A'))
        {
            temp.letters += 1;
        }
        else if (line[i] == ' ')
        {
            temp.words += 1;
        }
        else if (line[i] == '.' || line[i] == '?' || line[i] == '!')
        {
            temp.sentences += 1;
        }
    }
    return temp;
}
//this function grades the paragraph
float grader(cli_vars cli)
{
    return 0.0588 * ((float)cli.letters / cli.words) * 100 - 0.296 * ((float)cli.sentences / cli.words) * 100 - 15.8;
}

void result_printer(float result)
{
    if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (result >= 16)
    {
        printf("Grade 16+\n");
    }
    else
        printf("Grade %i\n", (int)round(result));
}

int main(int argc, char const *argv[])
{
    float final_result;
    cli_vars input;
    string input_line = get_string("Text : ");
    input = calculator(input_line);
    final_result = grader(input);
    result_printer(final_result);
    return 0;
}
