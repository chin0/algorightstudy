#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10

#define MAX_ROW 3
#define MAX_COL 3
#define DIGIT_SPACING 2
#define MAX_DIGITS_SPACE (MAX_DIGITS * (MAX_ROW + DIGIT_SPACING)) - DIGIT_SPACING


char digits[MAX_COL][MAX_DIGITS * MAX_ROW];
const int digit_segment[10][7] = {
    {1,1,1,1,1,1,0},
    {0,1,1,0,0,0,0},
    {1,1,0,1,1,0,1},
    {1,1,1,1,0,0,1},
    {0,1,1,0,0,1,1},
    {1,0,1,1,0,1,1},
    {1,0,1,1,1,1,1},
    {1,1,1,0,0,0,0},
    {1,1,1,1,1,1,1},
    {1,1,1,0,0,1,1}};


//each segment's row,col data.
const int grid_pos[7][2] = {
    /* row, col */
    {0,1}, /* 0 */
    {1,2},
    {2,2},
    {2,1},
    {2,0},
    {1,0},
    {1,1}};

void clear_digits_array(void);
void process_digit(int digit,int position);
void print_digits_array(void);

int main(void)
{
    int pos=0;
    char ch;

    clear_digits_array();
    printf("Enter a number: ");
    while((ch = getchar()) != '\n' && pos < MAX_DIGITS_SPACE)
    {
        if(isdigit(ch)){
            process_digit(ch - '0',pos);
            pos += MAX_ROW + DIGIT_SPACING;
        }
    }
    print_digits_array();
}

void clear_digits_array(void)
{
    int row,col;
    for(row = 0;row < MAX_COL;row++){
        for(col = 0; col < MAX_DIGITS_SPACE; col++)
            digits[row][col] = ' ';
    }
}

//문자열 배열 구성
void process_digit(int digit,int starting_col)
{
    int segment,segment_row_pos,segment_col_pos;

    for(segment = 0; segment < 7;segment++){
        if(digit_segment[digit][segment]){
            segment_row_pos = grid_pos[segment][0];
            segment_col_pos = grid_pos[segment][1] + starting_col;
            digits[segment_row_pos][segment_col_pos] = segment % 3 == 0 ? '_' : '|';
        }
    }
}

void print_digits_array(void)
{
    int row,col;
    for(row = 0; row < MAX_ROW; row++){
        for(col = 0; col < MAX_DIGITS_SPACE;col++)
            printf("%c",digits[row][col]);
        printf("\n");
    }
}

    

    
    
