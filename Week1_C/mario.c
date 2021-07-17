#include <stdio.h>
void hashtag_printer(int width)
{
    // print a block using # char with the desired width
    printf(" ");
    
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
    hashtag_printer(width);
    printf("\n");
}
int main ()
{
    int height ;
    scanf("%d",&height);
    for (size_t i = 1; i < height+1 ; i++)
    {
      row_printer(i,height);   
    }
    
}