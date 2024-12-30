

    /***********************************************************************
     * Name:  Lilli Lewis                                                  *
     * Assignment name ( Homework  2)                                      *
     *                                                                     *
     * Assignment for 5/12/23                                              *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   My signature below confirms that the above list of sources        *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *     I copied the academic honesty certification from the            *
     *      "Submitting Work" reading.                                     *
     *     I recycled some switch and printf code from the array queue     *
     *      lab I worked on with Amen and Maritza.                         *
     *     I modified and cited the Makefile from ticket_tracker, which    *
     *      I worked on with Maritza.                                      *
     *     I used the very famous iris dataset from this link              *
     *      https://archive.ics.uci.edu/ml/datasets/iris, and used         *
     *      the corrections they mentioned in "iris.names". This file      *
     *      also contains summary statistics I will use to check my work.  *
     *     Link to dataset (iris.data) is below:                           *
     *      https://archive.ics.uci.edu/ml/machine-learning-databases/     *
     *      iris/                                                          *
     *                                                                     *
     *   Signature: Lilli Lewis                                            *
     ***********************************************************************/

//including libraries if necessary
#ifndef __STDIO_H__
#define __STDIO_H__
#endif
#ifndef __STRING_H__
#define __STRING_H__
#endif
#ifndef __STDLIB_H__
#define __STDLIB_H__
#endif
#ifndef __MATH_H__
#define __MATH_H__
#endif
#ifndef __IRIS_HEADER_H__
#define __IRIS_HEADER_H__
#endif


//Macros

//iris-versicolor is the longest iris name
#define MAXTYPELEN (strlen("Iris-versicolor") +1)

//the length of the longest line, which contains iris-versicolor
#define MAXLINELEN (strlen("7.0,3.2,4.7,1.4,Iris-versicolor") + 1)

//number of rows in dataset
#define ROWS 150

//number of columns in dataset
#define COLS 5

//column names
#define SEPLEN 0
#define SEPWID 1
#define PETLEN 2
#define PETWID 3
#define TYPE 4

//in case of error
#define ERROR_ERROR 369

//Declaring functions--names are evident

void inputToArray(FILE * file, float array[ROWS][COLS]);
/*Preconditons: array input is the array the data will be stored in and file 
   is the input file, argv[1] 
  Postconditoins: function stores the text file as an array of floats, turning 
   type of iris into 1, 2, or 3 (depending on type)*/

void printArray (float array[ROWS][COLS]);
/* Pre-conditions: array input is the dataset array 
   Post-conditions: prints the array dataset to terminal in a  nicely 
    formatted table */

int pick_iris_type(void);
/*Preconditions: none
  Postconditions: Takes user input returns that same input; it's a helper 
   function to be reused in other more complicated functions where user is only 
   interested in one type of iris*/

float min(float array[ROWS][COLS], int col);
/* Pre-conditions: array input is the dataset array and col is the column 
    number where the data the user is interested in is stored
   Post-conditions: returns the minimum value in the column the user is 
    interested in */

float min_type(float array[ROWS][COLS], int col, int type);
/* Pre-conditions: array input is the dataset array, col is the column 
    number where the data the user is interested in is stored, and type
    is the integer which corresponds to the type of iris the user is interested 
    in
   Post-conditions: returns the minimum value in the column the user is 
    interested in, of the correct type of iris */

float max(float array[ROWS][COLS], int col);
/* Pre-conditions: array input is the dataset array and col is the column 
    number where the data the user is interested in is stored
   Post-conditions: returns the maximum value in the column the user is 
    interested in */

float max_type(float array[ROWS][COLS], int col, int type);
/* Pre-conditions: array input is the dataset array, col is the column 
    number where the data the user is interested in is stored, and type
    is the integer which corresponds to the type of iris the user is interested 
    in
   Post-conditions: returns the maximum value in the column the user is 
    interested in, of the correct type of iris */

float mean(float array[ROWS][COLS], int col);
/* Pre-conditions: array input is the dataset array and col is the column 
    number where the data the user is interested in is stored
   Post-conditions: returns the mean of the values in the column the user 
    is interested in */

float stddev(float array[ROWS][COLS], int col);
/* Pre-conditions: array input is the dataset array and col is the column 
    number where the data the user is interested in is stored
   Post-conditions: returns the std dev of the values in the column 
    the user is interested in */

float stddev_type(float array[ROWS][COLS], int col, int type);
/* Pre-conditions: array input is the dataset array, col is the column 
    number where the data the user is interested in is stored, and type
    is the corresponding number to type of iris.
   Post-conditions: returns the std dev of the values in the column 
    the user is interested in, of the proper type of iris */

void col_to_name(FILE * output, int col);
/*Pre-conditions: output is the output file and col is the column user is 
   interested in. 
  Post-conditions: prints the correct variable name to the output file*/

void type_to_name(FILE * output, int type);
/*Pre-conditions: output is the output file and type is the type of iris that
   the user is interested in. 
  Post-conditions: prints the correct iris type name to the output file*/

void print_to_results (FILE * output, float array[ROWS][COLS], int col);
/*Pre-conditions: file is output file, array is array with data in it, and 
   col is the column user is interested in
  Postcondition: min, max, mean, and stddev of specified col are 
   printed to the output file */
  
void print_to_results_type (FILE * output, float array[ROWS][COLS], int col, int selection);
/*Pre-conditions: file is output file, array is array with data in it, col is 
   the column user is interested in, and selection is the type of iris the user 
   is interested in
  Postconddition: min, max, mean, and stddev of specified type and col are 
   printed to the output file */

void min_table(FILE * output, float array[ROWS][COLS]);
/*Preconditions: file is output file and array is the data-storing array
  Postconditions: prints a table with all minimum values to output file*/

void max_table(FILE * output, float array[ROWS][COLS]);
/*Preconditions: file is output file and array is the data-storing array
  Postconditions: prints a table with all maximum values to output file*/

void mean_table(FILE * output, float array[ROWS][COLS]);
/*Preconditions: file is output file and array is the data-storing array
  Postconditions: prints a table with all mean values to outputfile*/

void stddev_table(FILE * output, float array[ROWS][COLS]);
/*Preconditions: file is output file and array is the data-storing array
  Postconditions: prints a table with all stddev values to outputfile*/
