/*  This program prints a report with the average hurricane category          */
/*  using the data in the data file storms2.txt.                              */

#include <stdio.h>
#define FILENAME "storms2.txt"

/*  Define structure to represent a hurricane.  */
struct hurricane
{
   char name[10];
   int year, category;
};

int main(void)
{
   /*  Define and initialize variables.  */
   struct hurricane h1;
   FILE* storms;
   double numberHurricanes = 0;
   double sumCategory = 0;

   /*  Read and process information from file.  */
   storms = fopen (FILENAME, "r");
   if (storms == NULL)
      printf("Error opening file\n");
   else
   {
      while ( fscanf(storms, "%s %d %d", h1.name, &h1.year, &h1.category) == 3 )
      {
         numberHurricanes++;
         sumCategory += h1.category;
      }

      printf("Hurricane Summary for the Strongest Hurricanes in 1950 - 2002\n");
      printf("Average Category: %.1f\n", sumCategory/numberHurricanes);
	
      fclose(storms);
   }

   /*  Exit program.  */
   return 0;
}
