//link to the problem description
//https://cs50.harvard.edu/x/2021/psets/2/readability/
//link to the cs50 lib
//https://cs50.readthedocs.io/libraries/cs50/c/
#include "helpers.h"
#include <stdlib.h>
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //this will assign an average of red , blue and green average to each pixel
            image[i][j].rgbtBlue = image[i][j].rgbtRed = image[i][j].rgbtGreen = round((float)(image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_pixel;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp_pixel = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp_pixel;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int red, blue, green;
    red = blue = green = 0;
    int counter = 0;
    //temp initialisation
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = blue = green = 0;
            counter = 0;
            // this next nested for-loop is for actually bluring each pixel
            // also I know this part could be wrote to have better performances but it wasn't as readable as it is now
            for (int t = i - 1; t < i + 2; t++)
            {
                if (t >= 0 && t < height)
                {
                    for (int h = j - 1; h < j + 2; h++)
                    {
                        if (h >= 0 && h < width)
                        {
                            red += temp[t][h].rgbtRed;
                            blue += temp[t][h].rgbtBlue;
                            green += temp[t][h].rgbtGreen;
                            counter++;
                        }
                    }
                }
            }
            image[i][j].rgbtRed = round((float)red / counter);
            image[i][j].rgbtBlue = round((float)blue / counter);
            image[i][j].rgbtGreen = round((float)green / counter);
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    int gx[3], gy[3];
    //temp initialisation
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            gx[0] = gx[1] = gx[2] = 0;
            gy[0] = gy[1] = gy[2] = 0;
            // this next nested for-loop is for actually measuring edges
            for (int t = i - 1; t < i + 2; t++)
            {
                if (t >= 0 && t < height)
                {
                    for (int h = j - 1; h < j + 2; h++)
                    {
                        if (h >= 0 && h < width)
                        {
                            gx[2] += (t - i) * (2 - abs(h - j)) * temp[t][h].rgbtBlue;
                            gx[1] += (t - i) * (2 - abs(h - j)) * temp[t][h].rgbtGreen;
                            gx[0] += (t - i) * (2 - abs(h - j)) * temp[t][h].rgbtRed;
                            gy[2] += (h - j) * (2 - abs(t - i)) * temp[t][h].rgbtBlue;
                            gy[0] += (h - j) * (2 - abs(t - i)) * temp[t][h].rgbtRed;
                            gy[1] += (h - j) * (2 - abs(t - i)) * temp[t][h].rgbtGreen;
                        }
                    }
                }
            }
            image[i][j].rgbtGreen = sqrt(gy[1] * gy[1] + gx[1] * gx[1]) < 255 ? round(sqrt(gy[1] * gy[1] + gx[1] * gx[1])) : 255;
            image[i][j].rgbtBlue = sqrt(gy[2] * gy[2] + gx[2] * gx[2]) < 255 ? round(sqrt(gy[2] * gy[2] + gx[2] * gx[2])) : 255;
            image[i][j].rgbtRed = sqrt(gy[0] * gy[0] + gx[0] * gx[0]) < 255 ? round(sqrt(gy[0] * gy[0] + gx[0] * gx[0])) : 255;
        }
    }
}
