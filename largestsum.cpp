#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <iostream>

#include <vector>
#include <math.h>

//Function to calculate fibonacci sequence PART 1A
int fibSeq(int n)
{
   if (n == 0)
   {
       return 0;
   }
   else if (n == 1)
   {
       return 1;
   }
   else
   {
       return fibSeq(n-1) + fibSeq(n-2);
   }
}

//Function to calculate fibonacci sequence EQUATION 4
float fibSeqEqu4(int n, float p)
{
  float n_p = n - p;
  float equation_fp = (((pow((1 + sqrt(5)), p)) - (pow((1 - sqrt(5)), p))) / (pow(2, p) * sqrt(5)));
  float equation_fn = equation_fp * pow(1.61803, n_p);
  return equation_fn;
}

//Function to calculate fibonacci sequence EQUATION 5
float fibSeqEqu5(int n)
{
  float equation_fn = (((pow((1 + sqrt(5)), (n - 1))) - (pow((1 - sqrt(5)), (n - 1)))) / (pow(2, (n - 1)) * sqrt(5)));
  float equation_fn1 = equation_fn * 1.61803;
  return equation_fn1;
}

int main(int argc, char* argv[])
{

  //Part 1a Fibbonacci Exhaustive Pattern
  //
  //

  int nTerm;
  std::cout << "PART 1A\nEnter the nth term of the sequence: ";
  std::cin >> nTerm;
  std::cout << "The nth term of the sequence is: " << fibSeq(nTerm) << "\n";
  int sequenceLength = 15;
  std::cout << "The Fibonacci sequence for " << sequenceLength << " terms is: " << "\n";
  for(int i = 0; i < sequenceLength; i++)
  {
    if (i == (sequenceLength - 1))
    {
      std::cout << fibSeq(i) << "\n";
    }
    else
    {
      std::cout << fibSeq(i) << ", ";
    }
  }


  //Part 1b Fibonnacci Golden Ratio
  //
  //

  //Equation 4

  float p;
  int n;
  int check = 0;

  std::cout << "\nPART 1B\nEQUATION 4\n";
  std::cout << "Please input n: ";
  std::cin >> n;
  std::cout << "Please input p: ";
  std::cin >> p;

  //Check if p is non-negative, non-decimal integer
  while ((p < 0) || p != int(p))
  {
    std::cout << "Invalid input, please reinput p: ";
    std::cin >> p;
  }

  //Output fn based on user input
  std::cout << "fn = " << fibSeqEqu4(n, p) << "\n";
  std::cout << "First 20 terms of sequence using equation 4:\n";

  //Output first 20 terms of sequence using equation 4
  for (int a = 0; a < 21; a++)
  {
    if (a == 0)
    {
      std::cout << "0, ";
    }
    else if (a == 1)
    {
      std::cout << "1, ";
    }
    else
    {
      std::cout << fibSeqEqu4(a, p);
      if (a != 20)
      {
        std::cout << ", ";
      }
    }
  }


  //Equation 5

  std::cout << "\n\nEQUATION 5\nPlease input n: ";
  std::cin >> n;
  float temp_fn = (((pow((1 + sqrt(5)), n)) - (pow((1 - sqrt(5)), n))) / (pow(2, n) * sqrt(5)));

  //Output fn based on user input
  std::cout << "fn = " << temp_fn << "\n";
  std::cout << "First 20 terms of sequence using equation 5:\n";

  //Output first 20 terms of sequence using equation 5
  for (int b = 0; b < 21; b++)
  {
    if (b == 0)
    {
      std::cout << "0, ";
    }
    else if (b == 1)
    {
      std::cout << "1, ";
    }
    else
    {
      std::cout << fibSeqEqu5(b);
      if (b != 20)
      {
        std::cout << ", ";
      }
    }
  }

  std::cout << "\n\nEquation 4 is more accurate to the actual Fibonacci";
  std::cout << "\nsequence in the early terms, while Equation 5 is more";
  std::cout << "\naccurate in the later terms of the sequence.";
  float f3, f2, f30, f29;
  f3 = fibSeqEqu5(3);
  f2 = fibSeqEqu5(2);
  f30 = fibSeqEqu5(30);
  f29 = fibSeqEqu5(29);
  float f3_2 = f3 / f2;
  float f30_29 = f30 / f29;
  std::cout << "\nEquation 5\nRatio of f3 : f2 = " << f3_2 << "\n";
  std::cout << "Ratio of f30 : f29 = " << f30_29 << "\n";


  //Part 2 Largest Sub Subbaray
  //
  //

  std::vector<int> vector;

  std::cout << "\n\nPART 2\n";
  std::cout << "Calculating largest sum subarray for each given array:\n";

  for (int array_id = 1; array_id < 5; array_id++)
  {
    //Determine which array is being used
    if (array_id == 1)
    {
      std::cout << "Array 1: [10, 2, -5, 1, 9, 0, -4, 2, -2]\n";
      vector.insert(vector.end(), {10, 2, -5, 1, 9, 0, -4, 2, -2});
    }
    else if (array_id == 2)
    {
      std::cout << "Array 2: [-7, 1, 8, 2, -3, 1]\n";
      vector.insert(vector.end(), {-7, 1, 8, 2, -3, 1});
    }
    else if (array_id == 3)
    {
      std::cout << "Array 3: [9, 7, 2, 16, -22, 11]\n";
      vector.insert(vector.end(), {9, 7, 2, 16, -22, 11});
    }
    else if (array_id == 4)
    {
      std::cout << "Array 4: [6, 1, 9, -33, 7, 2, 9, 1, -3, 8, -2, 9, 12, -4]\n";
      vector.insert(vector.end(), {6, 1, 9, -33, 7, 2, 9, 1, -3, 8, -2, 9, 12, -4});
    }

    int max = 0;
    int indice_b = 0;
    int indice_e = 0;
    int vect_length = vector.size();

    //Find default max; sum of all values in array
    for (int x = 0; x < vect_length; x++)
    {
      max += vector.at(x);
    }

    //Calculate sum of every possible subarray
    for (int i = 0; i < (vect_length - 1); i++)
    {
      for (int j = 1; j < vect_length; j++)
      {
        int current_index = i;
        int sum = 0;

        //Sum values in subarray
        while (current_index < j)
        {
          sum += vector.at(current_index);
          current_index++;
        }

        //New max if sum > previous max
        if (sum > max)
        {
          max = sum;
          indice_b = i;
          indice_e = (j - 1);
        }
      }
    }

    //Output largest sum subarray of current array
    std::cout << "Largest sum subbaray of array "<< array_id << ": (";

    for (int y = indice_b; y < (indice_e + 1); y++)
    {
      if (y != indice_e)
      {
        std::cout << vector.at(y) << ", ";
      }
      else
      {
        std::cout << vector.at(y);
      }
    }

    //Output indexes of largest sum subarray
    std::cout << ")\n";
    std::cout << "Indice b: " << indice_b << "\n";
    std::cout << "Indice e: " << indice_e << "\n";

    vector.clear();
  }

  return 0;
}
