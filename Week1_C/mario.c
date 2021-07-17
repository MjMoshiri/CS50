//link to the problem description
//https://cs50.harvard.edu/x/2021/psets/1/mario/more/
#include <stdio.h>
void hashtag_printer(int width)
{
    // print a block using # char with the desired width

    for (size_t i = 0; i < width; i++)
    {
            printf("#");
    }

}
void space_printer(int width)
{
    // print a blank space using space char with the desired width

    for (size_t i = 0; i < width; i++)
    {
            printf(" ");
    }
}
void row_printer(int width, int height)
{
    // print a row of mario blocks with specfic width in a specfic depth
    space_printer(height-width);
    hashtag_printer(width);
    printf("  ");
    hashtag_printer(width);
    printf("\n");
}
int main ()
{
    int height ;
    do
    {
        scanf("%d",&height);
    } while ( height <  1 || height >  8);

    for (size_t i = 1; i < height+1 ; i++)
    {
      row_printer(i,height);
    }

}
