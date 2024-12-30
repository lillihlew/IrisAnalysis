

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "iris-header.h"

int main(int argc, char * argv[]){

  //check if user input the correct number of files
  if (argc != 3) {
    printf("Error: input and output files are required. Please try again.\n");
    return EXIT_FAILURE;
  }

  //declare iris_input as a char array, with space for a terminating char
  char iris_input[strlen("iris-data.txt")+1];
  //declare iris_output as a char array, with space for a terminating char
  char iris_output[strlen("iris-results.txt")+1];

  strcpy(iris_input, argv[1]);//copy contents of argv[1] into iris_input
  strcpy(iris_output, argv[2]);//copy contents of argv[2] into iris_output
  
  //check if argv[1] is iris-data.txt
  if (strcmp(argv[1], "iris-data.txt") != 0){
    printf("Your first argument should be iris-data.txt. Please try again.\n");
    return EXIT_FAILURE;
  }

  //check if argv[2] is iris-results.txt
  if (strcmp(argv[2], "iris-results.txt") != 0){
    printf("Your second argument should be iris-results.txt. Please try again.\n");
    return EXIT_FAILURE;
  }

  //Print message about intent of program
   printf("\nThis program will perform the statistical analysis required by "
          "the user on iris-data.txt and print the results to iris-results.txt."
          "\n\n");

  //open iris-data.txt for reading
  FILE * input_file = fopen(argv[1], "r");
  //open iris-results.txt for writing
  FILE * output_file = fopen(argv[2], "w");
  
  //check to make sure input file could be opened
  if (input_file == NULL){
      printf("Error: iris-data.txt could not be opened.\n");
      return EXIT_FAILURE;
  }

  //check to make sure output file could be opened
  if (output_file == NULL){ 
      printf("Error: iris-results.txt could not be opened.\n");
      return EXIT_FAILURE;
  }

  //print header to output file
  fprintf(output_file, "Results of Analysis:\n\n");


  int choice = 0;//declare choice user inputs and initialize to 0

  int end = 1; //use this to end while loop when necessary

  float array[ROWS][COLS]; //array in which to store data
  
  inputToArray(input_file, array);//store data in array

  int selection = 10; //for user input when choosing a type, set it to 10 because that's not an option
  
  
  while(end){ //loop through options and switch statement

    //Print options of analysis for user
    printf("Please select an option:\n"
         "\t 1. Print explanation of dataset and statsistics to terminal.\n"
         "\t 2. Print dataset in array form to the terminal\n"
         "\t 3. Find statistics of all irises' sepal lengths\n"
         "\t 4. Find statistics of a type of irises' sepal lengths\n"
         "\t 5. Find statistics of all irises' sepal widths\n"
         "\t 6. Find statistics of a type of irises' sepal widths\n"
         "\t 7. Find statistics of all irises' petal lengths\n"
         "\t 8. Find statistics of a type of irises' petal lengths\n"
         "\t 9. Find statistics of all irises' petal widths\n"
         "\t 10. Find statistics of a type of irises' petal widths \n"
         "\t 11. Print min, max, mean, and std.dev tables for all iris types\n"
         "\t 12. Quit\n");
         
    //save user choice into choice
    scanf("%d", &choice);

    //switch giving the user the option they want
    switch(choice){
      case 1:
        printf("\nThis dataset contains 150 measurements of irises. There \n"
               "are three types of iris plants in the dataset: setosa, \n" 
               "versicolor, and virginica. There are 50 measurements of each \n"
               "iris type. Each iris has information of sepal length(cm), \n"
               "sepal width(cm), petal length(cm), petal width(cm), and class."
               "\n\n"
               "The statistics that will be collected are minimum, maximum, \n"
               "mean, and standard deviation.\n\n");
        break;
      case 2:
        printArray(array);
        break;
      case 3:
        print_to_results (output_file, array, SEPLEN); 
        break;
      case 4:
        selection = pick_iris_type();
        if (selection == ERROR_ERROR)//to insure proper input
          return EXIT_FAILURE;
        else
          print_to_results_type(output_file, array, SEPLEN, selection);
        break;
      case 5:
        print_to_results (output_file, array, SEPWID);
        break;
      case 6:
        selection = pick_iris_type();
        if (selection == ERROR_ERROR)//to insure proper input
          return EXIT_FAILURE;
        else
          print_to_results_type(output_file, array, SEPWID, selection);
        break;
      case 7:
        print_to_results (output_file, array, PETLEN); 
        break;
       case 8:
        selection = pick_iris_type();
        if (selection == ERROR_ERROR)//to insure proper input
          return EXIT_FAILURE;
        else
          print_to_results_type(output_file, array, PETLEN, selection);
        break;
      case 9:
        print_to_results (output_file, array, PETWID); 
        break;
       case 10:
        selection = pick_iris_type();
        if (selection == ERROR_ERROR)//to insure proper input
          return EXIT_FAILURE;
        else
          print_to_results_type(output_file, array, PETWID, selection);
        break;
      case 11:
        min_table(output_file, array);
        max_table(output_file, array);
        mean_table(output_file, array);
        stddev_table(output_file, array);
        break;
      case 12:
        printf("Thank you for using this program. Your results are in iris-results.txt.\n");
        end=0;
        break;
      default:
        printf("Please try again with a number 1-9: ");
        break;
    }//switch
  }//while

  
  if(fclose(output_file)){//if this is null, then print and return error
    printf("Error closing output file.\n");
    return EXIT_FAILURE;
  }

  if(fclose(input_file)){//if this is null, then print and return error
    printf("Error closing input file.\n");
    return EXIT_FAILURE;
    }
    
  return 0;
}
