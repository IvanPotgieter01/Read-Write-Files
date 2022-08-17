#include <iostream>
#include <stdio.h>

using namespace std;

int ReadFiles(int*, char*);
void SortArrays(int*, char*, int); //Function declaration
void WriteFiles(char*, int*, int);

int main()
{
    int intArr[50];  //Array declaration
    char charArr[50];

    int n = ReadFiles(intArr, charArr); //Calling ReadFiles() function

    SortArrays(intArr, charArr, n);//Calling SortArrays() function

    WriteFiles(charArr, intArr, n);//Calling WriteFiles() function

    cout << "Check the output files for the result";

    return 0;
}

int ReadFiles(int* intArr, char* charArr)//Creating ReadFiles() function
{
    FILE *INPUT1 = fopen("Data1.bin", "rb"); //Opening Data1.bin
    int counter = 0; //Variable declaration
    if (INPUT1 == NULL) //Case if unable to read file
    {
        cout << "Unable to read from file 1." << endl;
        exit(1); //Exit with error code
    }
    else
    {
        int num; //Variable declaration

        while (fread(&num, sizeof(int),1, INPUT1)) //Reading characters in text file

        {
           if (feof(INPUT1))
           {
               break;//Exiting the while loop upon EOF
           }
           else
           {
                *(intArr + counter) = num; //Assigning characters in the binary file to elements in the array
                counter += 1; //Incrementing counter
           }

        }
        fclose(INPUT1);//Closing binary file
    }


    FILE *INPUT2 = fopen("Data2.bin", "rb"); //Opening Data2.bin

    if (INPUT2 == NULL) //Case if unable to read file
    {
        cout << "Unable to read from file." << endl;
        exit(1); //Exit with error code
    }
    else
    {
        char c; //Variable declaration
        int counter = 0; //Variable declaration
        while (fscanf(INPUT2, "%c", &c) != EOF) //Reading characters in binary file until the end of the file
        {
           *(charArr + counter) = c; //Assigning characters in the binary file to elements in the array
           counter += 1; //Incrementing counter
        }
        fclose(INPUT2);

        return (counter); //returing length of the array
    }
}


void SortArrays(int* intArr, char* charArr, int len)//Creating SortArrays() function
{
    int temp1;
    char temp2;
    for(int i = 0;i < len; i++) //Loop iteration through the array from element 0
	{
		for(int j = i + 1; j < len; j++) //Loop iteration through the array from element 1 (i + 1)
		{
			if(intArr[i] > intArr[j])//Case if element i is bigger than element j in the array
			{
				temp1 = intArr[i];
				temp2 = charArr[i];

				intArr[i] = intArr[j]; //Swtiching values if the element on the right is larger
				charArr[i] = charArr[j];//Switching the same values in the char array

				intArr[j] = temp1;
				charArr[j] = temp2;
			}
		}
	}
}


void WriteFiles(char* charArr, int* intArr, int len)//Creating WriteFiles() function
{
    FILE *OUTPUT = fopen("Output.txt", "w"); //Creating the output text file

    for (int i = 0; i < len; i++)
    {
        fprintf(OUTPUT, "%c" , charArr[i]);//Printing characters to text files
    }

    fclose(OUTPUT);//Closing output text file



    FILE *OUTPUT2 = fopen("Output.bin", "wb"); //Creating the output binary file

    for (int i = 0; i < len; i++)
    {
        fwrite(intArr + i, sizeof(int), 1, OUTPUT2);//Writing numbers to the binary file
    }

    fclose(OUTPUT2);//Closing output text file
}

