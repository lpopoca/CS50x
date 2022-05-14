#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_pyramid(int);
void right_align(int, int);
void print_spaces(void);
void left_align(int);

int main(void)
{
    int height; // Declaration
    height = get_height(); // Assignment via user input
    print_pyramid(height); // Draw the the pyramid
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

void print_pyramid(int height)
{
    for (int i = 0; i < height; i++) // for each row
    {
        right_align(height, i);
        print_spaces();
        left_align(i);
        printf("\n");
    }
}

// Print right alignment
void right_align(int height, int iteration)
{
    // Print a space that is on less than the width/height
    for (int j = height - iteration; j > 1; j--) // col
    {
        printf(" ");
    }
    // Print the hashes based on the current width/height
    for (int k = 0; k <= iteration; k++) // col
    {
        printf("#");
    }
}

// Print two spaces
void print_spaces(void)
{
    for (int l = 0; l <= 1; l++)
    {
        printf(" ");
    }
}

// Print left alignment
void left_align(int iteration)
{
    for (int l = 0; l <= iteration; l++)
    {
        printf("#");
    }
}