#include "helpers.h"
# include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            float Red = image[a][b].rgbtRed;
            float Green = image[a][b].rgbtGreen;
            float Blue = image[a][b].rgbtBlue;

            int average = round((Red + Green + Blue) /3);

            image[a][b].rgbtRed = average;
            image[a][b].rgbtGreen = average;
            image[a][b].rgbtBlue = average;
        }
    }
    return;
}

int limit (int RGB)
{
    if(RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;

    for (int a = 0; a < height; a++)
    {
        for(int b = 0; b < width; b++)
        {
            sepiaRed = limit(round(0.393 * image[a][b].rgbtRed + 0.769 * image[a][b].rgbtGreen + 0.189 * image[a][b].rgbtBlue));
            sepiaGreen = limit(round(0.349 * image[a][b].rgbtRed + 0.686 * image[a][b].rgbtGreen + 0.168 * image[a][b].rgbtBlue));
            sepiaBlue = limit(round(0.272 * image[a][b].rgbtRed + 0.534 * image[a][b].rgbtGreen + 0.131 * image[a][b].rgbtBlue));

            image[a][b].rgbtRed = sepiaRed;
            image[a][b].rgbtGreen = sepiaGreen;
            image[a][b].rgbtBlue = sepiaBlue;
        }
    }
    return;
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int tmp[3];
    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < (width / 2); b++)
        {
            tmp[0] = image[a][b].rgbtRed;
            tmp[1] = image[a][b].rgbtGreen;
            tmp[2] = image[a][b].rgbtBlue;

            image[a][b].rgbtRed = image[a][width - b - 1].rgbtRed;
            image[a][b].rgbtGreen = image[a][width - b - 1].rgbtGreen;
            image[a][b].rgbtBlue = image[a][width - b - 1].rgbtBlue;

            image[a][width - b - 1].rgbtRed = tmp[0];
            image[a][width - b - 1].rgbtGreen = tmp[1];
            image[a][width - b - 1].rgbtBlue = tmp[2];
        }
    }
    return;
}



// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];

    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            int tmpRed, tmpGreen, tmpBlue;
            tmpRed = tmpGreen = tmpBlue = 0;
            float counter = 0.00;

            for (int c = -1; c < 2; c++)
            {
                for (int d = -1; d < 2; d++)
                {
                    int tmpC = a + c;
                    int tmpD = b + d;

                    if (tmpC < 0 || tmpC > (height - 1) || tmpD < 0 || tmpD > (width -1))
                    {
                        continue;
                    }

                    tmpRed += image[tmpC][tmpD].rgbtRed;
                    tmpGreen += image[tmpC][tmpD].rgbtGreen;
                    tmpBlue += image[tmpC][tmpD].rgbtBlue;

                    counter++;
                }
                tmp[a][b].rgbtRed = round(tmpRed / counter);
                tmp[a][b].rgbtGreen = round(tmpGreen / counter);
                tmp[a][b].rgbtBlue = round(tmpBlue / counter);
            }
        }
    }
    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            image[a][b].rgbtRed = tmp[a][b].rgbtRed;
            image[a][b].rgbtGreen = tmp[a][b].rgbtGreen;
            image[a][b].rgbtBlue = tmp[a][b].rgbtBlue;
        }
    }
    return;
}
