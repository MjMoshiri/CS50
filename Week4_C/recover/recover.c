//link to the problem description
//https://cs50.harvard.edu/x/2021/psets/4/recover/

// Recover all the jpeg files in a lost memory

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#define BLOCKSIZE 512

typedef uint8_t BYTE;

//will find the start of the first picture
bool first_pic(FILE *memory, BYTE *buffer)
{
    while (fread(buffer, sizeof(BYTE), BLOCKSIZE, memory))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3]<0x100 & buffer[3]> 0xdf)
        {
            return true;
        }
    }
}
int main(int argc, char *argv[])
{
    BYTE buffer[BLOCKSIZE];
    bool searching = true;
    int counter = 0;
    char name[8];
    // Check usage
    if (argc != 2)
    {
        printf("Usage : ./recover image");
        return 1;
    }

    // Open file
    FILE *memory = fopen(argv[1], "r");
    if (!memory)
    {
        return 1;
    }
    if (first_pic(memory, buffer))
    {
        sprintf(name, "%03d.jpg", counter);
        FILE *pic = fopen(name, "w");
        fwrite(buffer, sizeof(BYTE), 512, pic);
        while (fread(buffer, sizeof(BYTE), BLOCKSIZE, memory))
        {
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3]<0x100 & buffer[3]> 0xdf)
            {
                counter++;
                fclose(pic);
                sprintf(name, "%03d.jpg", counter);
                FILE *pic = fopen(name, "w");
                fwrite(buffer, sizeof(BYTE), 512, pic);
            }
            else
            {
                fwrite(buffer, sizeof(BYTE), 512, pic);
            }
        }
    }
    else
        printf("NO JPEG picture found");
    // Close file
    fclose(memory);
}
