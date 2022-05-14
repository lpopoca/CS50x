#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_right_align(int height);

int main(void)
{
    int height; // Declaration
    height = get_height(); // Assignment via user input
    print_right_align(height); // Draw the right aligned pyramid
}

int get_height(void)
{
    int h;
    do // repeats if invalid input
    {
        h = get_int("Height: ");
    }
    while (h > 8 || h < 1);
    return h;
}

void print_right_align(int height)
{
    for (int i = 0; i < height; i++) // for each row
    {
        // Print a space that is on less than the width/height
        for (int j = height - i; j > 1; j--) // col
        {
            printf(" ");
        }
        // Print the hashes based on the current width/height
        for (int k = 0; k <= i; k++) // col
        {
            printf("#");
        }
        printf("\n");
    }
}