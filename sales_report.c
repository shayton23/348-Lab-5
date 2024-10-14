/*
Author: Shayton Wright
Date: 10/13/2024
Input: 12 months worth of sales
Output: Monthly sales report, sales summary report, six-month moving average report, sales report(highest to lowest).
*/
#include <stdio.h>
#define month_count 12

void report(float sales[], int n){ //Initialize report function to print the inputed report neatly
    printf("Sales Report:\n"); //Formatting print
    printf("%-15s %-15s\n", "Month", "Sales"); //Print statement to the user. %-15s is for 15 spaces
    const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; //Initialize the months array.

    for (int i = 0; i < n; i++) { //Lines 15-17. For loop that will iterate over the ith value in both the months and sales array and print them in a neat format for the user.
        printf("%-15s $%-14.2f\n", months[i], sales[i]); //Print statement to the user. %-15s is for 15 spaces and the %-14.2 is for a float with 14 values befor the decimal and 2 after (currency format).
    }
}
void summary(float sales[], int n){ //Initialize sales summary function
    const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; //Initialize array of months.
    printf("Sales Summary Report:\n"); //Formatting print
    float minimum = sales[0]; //Initialize variable that will hold the minimum sales value. Set to the first index by default.
    float maximum = sales[0]; //Initialize variable that will hold the maximum sales value. Set to the first index by default.
    float average = sales[0]; //Initialize variable that will hold the average sales value. Set to the first index by default.
    for (int i = 1; i < n; i++) { //For loop that will iterate over all the values in our sales array.
        if (sales[i] < minimum) { //If statement that compares the index i sales value to the minumum sales value
            minimum = sales[i]; //If the sales value at index i is less than the current minimum. We set the minimum to the value at index i.
        }
        if (sales[i] > maximum) { //If statement that compares the index i sales value to the maximum sales value
            maximum = sales[i]; //If the sales value at index i is greater than the current maximum. We set the maximum to the value at index i.
        }
        average += sales[i]; //As we iterate over sales, we add the value at index i to the average value. We will set the average next.
    }
    average /= n; //Divide the average value by the n (number of months) to get the average sales per month.
    printf("Minimum Sales: $%.2f\n", minimum); //Print the minimum value to the user
    printf("Maximum Sales: $%.2f\n", maximum); //Print the maximum to the user
    printf("Average Sales: $%.2f\n", average); //Print the average to the user.
    printf("Six-Month Moving Averages:\n"); //Move to six-month moving average
    for (int i = 5; i < n; i++) { //Start at index 5 (0-5 is 6 months) and repeat the next steps for each 6 month gap until we reach i = 12 (maximum number of months thus we are at the last 6 month span.)
        float move_average = 0; //Set/initialize the moving average to 0.
        for (int j = i - 5; j <= i; j++) { //For loop that will continue as long as j is less than or equal to i.
            move_average += sales[j]; //Add the sales value at index j to the moving average.
        }
        move_average /= 6; //Divide the moveing average value by 6 (6 month span)
        printf("%-15s-%-15s $%-14.2f\n",months[i-5], months[i],move_average); //Prints the month span to the user and the average sales during that span.
    }
    printf("Monthly Sales Report (Highest to Lowest):\n"); //Moving to the sorting of the sales report.
    printf("%-15s %-15s\n", "Month", "Sales"); //Formatting to show the columns.
    // Create an array of indices and sort it based on sales data
    int index[month_count]; //Create new array to hold the indexes using the month count.
    for (int i = 0; i < month_count; i++) { // Iterate over the length of the month count and add each index value to the index array
        index[i] = i;
    }
    for (int i = 0; i < n - 1; i++) {//Loop iterating i from index 0 to 11.
        for (int j = i + 1; j < n; j++) { // Loop iterating over j as a value relative to i. Continues for all j less than n (12)
            if (sales[index[i]] < sales[index[j]]) { //If statement that will carry out a bubble sort style of functionality. Compare value of sales at index i vs sales at index j.
                int temp = index[i]; //If index i is less than j we will swap them to sort. We must store i as a temp though so as not to lose it.
                index[i] = index[j]; //Set index i to j, moving it up higher in the order ie. towards the greater side.
                index[j] = temp; //Set index j to the temp value
            }
        }
    }
    // Display sorted monthly sales
    for (int i = 0; i < n; i++) { //For loop that will iterate over all indexes possible.
        printf("%-15s $%-14.2f\n",months[index[i]], sales[index[i]]); //Print to the user the month's in order of their sales values from highest to lowest.
    }
}
int main(){ //Initialize main function
    float sales[month_count]; //Initialize an array with the size being the total number of months
    char input[100]; //Initialize an array of characters that will be added to with the values given in the input file
    // Get the filename from the user
    printf("Enter the input file with monthly sales numbers: "); //Prompt the user to enter a filename
    scanf("%s", input); //Store the file as the input variable
    FILE *file = fopen(input, "r"); //Opens the inputed file in read mode from the user
    if (file == NULL) { //Check to see if the file exists
        printf("Error opening file\n"); //Display error if the file cannot be found
        return 1;
    }
    for (int i = 0; i < month_count; i++) { //For each line in the file we read in the value in the line to our sales list.
        if (fscanf(file, "%f", &sales[i]) != 1) { //Check error case in that we are unable to read the data from the file.
            printf("Error in data read.\n");
            fclose(file); //Close the file
            return 1;
        }
    }
    fclose(file); //Close the file.
    report(sales, month_count); //Call the report function to display the sales report.
    summary(sales, month_count); // Call the summary function to carry out all required functionality.
    return 0;
}