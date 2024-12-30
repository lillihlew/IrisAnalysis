

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

//Include libraries and files necessary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "iris-header.h"


/*Preconditons: array input is the array the data will be stored in and file 
   is the input file, argv[1] 
  Postconditoins: function stores the text file as an array of floats, turning 
   type of iris into 1, 2, or 3 (depending on type)*/
void inputToArray(FILE * file, float array[ROWS][COLS]) {
  int count = 0;
  
  char line[MAXLINELEN];//place to keep the line
  
  while(fscanf(file, "%s", line) != EOF){
  char * token = strtok(line, " , ");
  float seplen = atof(token);//store first token into seplen
  token = strtok(NULL, " , ");
  float sepwid = atof(token);//store second token into sepwid
  token = strtok(NULL, " , ");
  float petlen = atof(token);//store third token into petlen
  token = strtok(NULL, " , ");
  float petwid = atof(token);//store fourth token into petwid
  char * class = strtok(NULL, " , ");//store fifth token into class

  //use strcmp to convert class to type, the string becomes a float (1 2 or 3)
  float type = 0;
  if (strcmp(class, "Iris-setosa") == 0)
    type = 1; 
  else if(strcmp(class, "Iris-versicolor") == 0)
    type = 2;
  else if(strcmp(class, "Iris-virginica") == 0)
    type = 3;

  //store tokens into appropriate slots in the array
  array[count][0] = seplen;
  array[count][1] = sepwid;
  array[count][2] = petlen;
  array[count][3] = petwid;
  array[count][4] = type;
  
  count++;
  }//while
}//inputToArray


/* Pre-conditions: array input is the dataset array 
   Post-conditions: prints the array dataset to terminal in a  nicely 
    formatted table */
void printArray (float array[ROWS][COLS]){
  printf("Sepal Length  Sepal Width  Petal Length  Petal Width    Class\n");
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      printf("     %.1f     ", array[i][j]);
    }//for (cols)
    printf("\n");
  }//for (rows)
  return;
}//printArray



/*Preconditions: none
  Postconditions: Takes user input returns that same input; it's a helper 
   function to be reused in other more complicated functions where user is 
   only interested in one type of iris*/
int pick_iris_type(void){
  int iris_type;//declare

  //present user options
  printf("\nPlease select which type of iris:\n"
         "\t 1. Iris-setosa\n"
         "\t 2. Iris-versicolor\n"
         "\t 3. Iris-virginica\n");
  scanf("%d", &iris_type);//save user input

  //handle improper input
  if((iris_type != 1) && (iris_type != 2) && (iris_type != 3)){
    printf("Error: improper input. Please try again\n");
    return ERROR_ERROR;
  }//if
  
  return iris_type;
}//pick_iris_type




/* Pre-conditions: array input is the dataset array, col is the column 
    number where the data the user is interested in is stored, and type
    is the integer which corresponds to the type of iris the user is 
    interested in
   Post-conditions: returns the minimum value in the column the user is 
    interested in, of the correct type of iris */
float min_type(float array[ROWS][COLS], int col, int type){
  float min = 100;
  int begin, end;
  if (type == 1){//if it's an Iris-setosa
    begin = 0;
    end = 50;
  }//if
  else if (type == 2){//if it's an Iris-versicolor
    begin = 50;
    end = 100;
  }else{//if it's an Iris-virginica
    begin = 100;
    end = 150;
  }//else
  for(int i = begin; i < end; i++){
    if(array[i][col] < min){
      min = array[i][col];
    }//if
  }//for
  return min;
}//min_type



/* Pre-conditions: array input is the dataset array and col is the column 
    number where the data the user is interested in is stored
   Post-conditions: returns the minimum value in the column the user is 
    interested in */
float min(float array[ROWS][COLS], int col){
  float min = 100;
  for(int i = 0; i < ROWS; i++){
    if(array[i][col] < min)
      min = array[i][col];
  }//for
  return min;
}//min



/* Pre-conditions: array input is the dataset array and col is the column 
    number where the data the user is interested in is stored
   Post-conditions: returns the maximum value in the column the user is 
    interested in */
float max(float array[ROWS][COLS], int col){
  float max = 0;
  for(int i = 0; i < ROWS; i++){
    if(array[i][col] > max)
      max = array[i][col];
  }//for
  return max;
}


/* Pre-conditions: array input is the dataset array, col is the column 
    number where the data the user is interested in is stored, and type
    is the integer which corresponds to the type of iris the user is 
    interested in
   Post-conditions: returns the maximum value in the column the user is 
    interested in, of the correct type of iris */
float max_type(float array[ROWS][COLS], int col, int type){
  float max = 0;
  int begin, end;
  if (type == 1){//if it's an Iris-setosa
    begin = 0;
    end = 50;
  }//if
  else if (type == 2){//if it's an Iris-versicolor
    begin = 50;
    end = 100;
  }else{//if it's an Iris-virginica
    begin = 100;
    end = 150;
  }//else
  for(int i = begin; i < end; i++){
    if(array[i][col] > max){
      max = array[i][col];
    }//if
  }//for
  return max;
}//max_type



/* Pre-conditions: array input is the dataset array and col is the column 
    number where the data the user is interested in is stored
   Post-conditions: returns the maximum value in the column the user is 
    interested in */
float mean(float array[ROWS][COLS], int col){
  float sum = 0;
  for(int i = 0; i < ROWS; i++){
    sum += array[i][col];
  }//for
  float mean = (sum / ROWS);
  return mean;
}//mean



/* Pre-conditions: array input is the dataset array, col is the column 
    number where the data the user is interested in is stored, and type
    is the integer which corresponds to the type of iris the user is 
    interested in
   Post-conditions: returns the mean value in the column the user is 
    interested in, of the correct type of iris */
float mean_type(float array[ROWS][COLS], int col, int type){
  float sum = 0;
  int begin, end;
  if (type == 1){//if it's an Iris-setosa
    begin = 0;
    end = 50;
  }//if
  else if (type == 2){//if it's an Iris-versicolor
    begin = 50;
    end = 100;
  }else{//if it's an Iris-virginica
    begin = 100;
    end = 150;
  }//else
  for(int i = begin; i < end; i++){
    sum += array[i][col];
  }//for
  float mean = sum / ROWS;
  return mean;
}//mean_type



/* Pre-conditions: array input is the dataset array and col is the column 
    number where the data the user is interested in is stored
   Post-conditions: returns the std dev of the values in the column 
    the user is interested in */
float stddev(float array[ROWS][COLS], int col){
  float avg;//would've called mean but its function is called mean
  avg = mean(array, col);//find mean of column
  float stddev=0;//declare
  float sum = 0;//declare and initialize 

  //find sum of each data point's distance from the mean, squared
  for(int i = 0; i<ROWS; i++)
    sum += ((array[i][col] - avg) * (array[i][col] - avg));

  stddev = sqrt(sum/ROWS);
  return stddev;
}//stddev


/* Pre-conditions: array input is the dataset array, col is the column 
    number where the data the user is interested in is stored, and type
    is the corresponding number to type of iris.
   Post-conditions: returns the std dev of the values in the column 
    the user is interested in, of the proper type of iris */
float stddev_type(float array[ROWS][COLS], int col, int type){
  float avg;//would've called mean but its function is called mean
  avg = mean(array, col);//find mean of column
  float stddev=0;//declare
  float sum = 0;//declare and initialize
  int begin, end;//declare

  if (type == 1){//if it's an Iris-setosa
    begin = 0;
    end = 50;
  }//if
  else if (type == 2){//if it's an Iris-versicolor
    begin = 50;
    end = 100;
  }else{//if it's an Iris-virginica
    begin = 100;
    end = 150;
  }//else
  
  //find sum of each data point's distance from the mean, squared
  for(int i = begin; i<end; i++)
    sum += ((array[i][col] - avg) * (array[i][col] - avg));

  stddev = sqrt(sum/ROWS);
  return stddev;
}//stddev_type




/*Pre-conditions: output is the output file and col is the column user is 
   interested in. 
  Post-conditions: prints the correct variable name to the output file*/
void col_to_name(FILE * output, int col){
  switch(col){
  case SEPLEN:
    fprintf(output, "sepal length");
    break;
  case SEPWID:
    fprintf(output, "sepal width");
    break;
  case PETLEN:
    fprintf(output, "petal length");
    break;
  case PETWID:
    fprintf(output, "petal width");
    break;
  default:
    break;
  }//switch
}//col_to_name


/*Pre-conditions: output is the output file and type is the type of iris that
   the user is interested in. 
  Post-conditions: prints the correct iris type name to the output file*/
void type_to_name(FILE * output, int type){
  switch(type){
    case 1:
      fprintf(output, "Iris-setosa");
      break;
    case 2:
      fprintf(output, "Iris-versicolor");
      break;
    case 3:
      fprintf(output, "Iris-virginica");
      break;
    default:
      break;
  }//switch
}//type_to_name



/*Pre-conditions: file is output file, array is array with data in it, and 
   col is the column user is interested in
  Postcondition: min, max, mean, and stddev of specified col are 
   printed to the output file */
void print_to_results (FILE * output, float array[ROWS][COLS], int col){
  //Header for the section
  fprintf(output, "\n\n\n");
  fprintf(output, "********************** Type of iris selected: all");
  fprintf(output, " **********************\n");

  //Min info
  fprintf(output, "\nMin of ");
  col_to_name(output, col);
  fprintf(output, ": %.1f\n", min(array, col));

  //Max info
  fprintf(output, "Max of ");
  col_to_name(output, col);
  fprintf(output, ": %.1f\n", max(array, col));

  //Mean info
  fprintf(output, "Mean of ");
  col_to_name(output, col);
  fprintf(output, ": %.2f\n", mean(array, col));

  //Stddev info
  fprintf(output, "Standard deviation of ");
  col_to_name(output, col);
  fprintf(output, ": %.2f\n", stddev(array, col));

  fprintf(output, "\n\n");
  return;
}//print_to_results



/*Pre-conditions: file is output file, array is array with data in it, col is 
   the column user is interested in, and selection is the type of iris the user 
   is interested in
  Postcondition: min, max, mean, and stddev of specified type and col are 
   printed to the output file */
void print_to_results_type (FILE * output, float array[ROWS][COLS], int col, int selection){
  //Header for the section
  fprintf(output, "\n\n\n");
  fprintf(output, "******************* Type of iris selected: ");
  type_to_name(output, selection);
  fprintf(output, " *******************\n");

  //Min info
  fprintf(output, "\nMin of ");
  col_to_name(output, col);
  fprintf(output, ": %.1f\n", min_type(array, col, selection));

  //Max info
  fprintf(output, "Max of ");
  col_to_name(output, col);
  fprintf(output, ": %.1f\n", max_type(array, col, selection));

  //Mean info
  fprintf(output, "Mean of ");
  col_to_name(output, col);
  fprintf(output, ": %.1f\n", mean_type(array, col, selection));

  //Stddev info
  fprintf(output, "Standard deviation of ");
  col_to_name(output, col);
  fprintf(output, ": %.1f\n", stddev_type(array, col, selection));

  return;
}//print_to_results_type


/*Preconditions: file is output file and array is the data-storing array
  Postconditions: prints a table with all minimum values to output file*/
void min_table(FILE * output, float array[ROWS][COLS]){
  fprintf(output, "\n\n");
  fprintf(output, "**************Table of Minimum Values *****************\n");
  fprintf(output, "Type\t Sepal Length\t Sepal Width\t Petal Length\t Petal Width\n");
  fprintf(output, "All\t\t %.1f\t\t %.1f\t\t %.1f\t\t %.1f\t\n",
          min(array, SEPLEN),  min(array, SEPWID), min(array, PETLEN),
          min(array, PETWID));
  fprintf(output, "Iris-Setosa\t %.1f\t\t %.1f\t\t %.1f\t\t %.1f\t\n",
          min_type(array, SEPLEN, 1), min_type(array, SEPWID, 1),
          min_type(array, PETLEN, 1), min_type(array, PETWID, 1));
  fprintf(output, "Iris-Versicolor\t %.1f\t\t %.1f\t\t %.1f\t\t %.1f\t\n",
          min_type(array, SEPLEN, 2), min_type(array, SEPWID, 2),
          min_type(array, PETLEN, 2), min_type(array, PETWID, 2));
  fprintf(output, "Iris-Virginica\t %.1f\t\t %.1f\t\t %.1f\t\t %.1f\t\n",
          min_type(array, SEPLEN, 3), min_type(array, SEPWID, 3),
          min_type(array, PETLEN, 3), min_type(array, PETWID, 3));
  fprintf(output, "\n");
  
  return; 
}//min_table


/*Preconditions: file is output file and array is the data-storing array
  Postconditions: prints a table with all maximum values to output file*/
void max_table(FILE * output, float array[ROWS][COLS]){
  fprintf(output, "\n\n");
  fprintf(output, "**************Table of Maximum Values *****************\n");
  fprintf(output, "Type\t Sepal Length\t Sepal Width\t Petal Length\t Petal Width\n");
  fprintf(output, "All\t\t %.1f\t\t %.1f\t\t %.1f\t\t %.1f\t\n",
          max(array, SEPLEN),  max(array, SEPWID), max(array, PETLEN),
          max(array, PETWID));
  fprintf(output, "Iris-Setosa\t %.1f\t\t %.1f\t\t %.1f\t\t %.1f\t\n",
          max_type(array, SEPLEN, 1), max_type(array, SEPWID, 1),
          max_type(array, PETLEN, 1), max_type(array, PETWID, 1));
  fprintf(output, "Iris-Versicolor\t %.1f\t\t %.1f\t\t %.1f\t\t %.1f\t\n",
          max_type(array, SEPLEN, 2), max_type(array, SEPWID, 2),
          max_type(array, PETLEN, 2), max_type(array, PETWID, 2));
  fprintf(output, "Iris-Virginica\t %.1f\t\t %.1f\t\t %.1f\t\t %.1f\t\n",
          max_type(array, SEPLEN, 3), max_type(array, SEPWID, 3),
          max_type(array, PETLEN, 3), max_type(array, PETWID, 3));
  fprintf(output, "\n");
  
  return;
}//max_table


/*Preconditions: file is output file and array is the data-storing array
  Postconditions: prints a table with all mean values to outputfile*/
void mean_table(FILE * output, float array[ROWS][COLS]){
  fprintf(output, "\n\n");
  fprintf(output, "**************Table of Mean Values *****************\n");

  fprintf(output, "Type\t Sepal Length\t Sepal Width\t Petal Length\t Petal Width\n");
  fprintf(output, "All\t\t %.2f\t\t %.2f\t\t %.2f\t\t %.2f\t\n",
          mean(array, SEPLEN),  mean(array, SEPWID), mean(array, PETLEN),
          mean(array, PETWID));
  fprintf(output, "Iris-Setosa\t %.2f\t\t %.2f\t\t %.2f\t\t %.2f\t\n",
          mean_type(array, SEPLEN, 1), mean_type(array, SEPWID, 1),
          mean_type(array, PETLEN, 1), mean_type(array, PETWID, 1));
  fprintf(output, "Iris-Versicolor\t %.2f\t\t %.2f\t\t %.2f\t\t %.2f\t\n",
          mean_type(array, SEPLEN, 2), mean_type(array, SEPWID, 2),
          mean_type(array, PETLEN, 2), mean_type(array, PETWID, 2));
  fprintf(output, "Iris-Virginica\t %.2f\t\t %.2f\t\t %.2f\t\t %.2f\t\n",
          mean_type(array, SEPLEN, 3), mean_type(array, SEPWID, 3),
          mean_type(array, PETLEN, 3), mean_type(array, PETWID, 3));
  fprintf(output, "\n");
  
  return;
}//mean_table


/*Preconditions: file is output file and array is the data-storing array
  Postconditions: prints a table with all stddev values to outputfile*/
void stddev_table(FILE * output, float array[ROWS][COLS]){
  fprintf(output, "\n\n");
  fprintf(output, "*********Table of Standard Deviation Values ************\n");

  fprintf(output, "Type\t Sepal Length\t Sepal Width\t Petal Length\t Petal Width\n");
  fprintf(output, "All\t\t %.2f\t\t %.2f\t\t %.2f\t\t %.2f\t\n",
          stddev(array, SEPLEN),  stddev(array, SEPWID), stddev(array, PETLEN),
          stddev(array, PETWID));
  fprintf(output, "Iris-Setosa\t %.2f\t\t %.2f\t\t %.2f\t\t %.2f\t\n",
          stddev_type(array, SEPLEN, 1), stddev_type(array, SEPWID, 1),
          stddev_type(array, PETLEN, 1), stddev_type(array, PETWID, 1));
  fprintf(output, "Iris-Versicolor\t %.2f\t\t %.2f\t\t %.2f\t\t %.2f\t\n",
          stddev_type(array, SEPLEN, 2), stddev_type(array, SEPWID, 2),
          stddev_type(array, PETLEN, 2), stddev_type(array, PETWID, 2));
  fprintf(output, "Iris-Virginica\t %.2f\t\t %.2f\t\t %.2f\t\t %.2f\t\n",
          stddev_type(array, SEPLEN, 3), stddev_type(array, SEPWID, 3),
          stddev_type(array, PETLEN, 3), stddev_type(array, PETWID, 3));
  fprintf(output, "\n");

  return;
}//stddev_table



