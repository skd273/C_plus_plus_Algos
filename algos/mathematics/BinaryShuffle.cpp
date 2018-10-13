#include <iostream>
#include <sstream>
using namespace std;

#define INT unsigned long long


//=====================================================================


void countBits( INT A, int &ones, int &endZeroes )         // Returns: the number of 1's
{                                                          //          the number of 0's at the end;
   ones = endZeroes = 0;
   bool inZeroes = true;

   if ( A == 0 )
   {
      endZeroes = 1;
      return;
   }

   for ( ; A; A /= 2 )
   {
      int digit = A % 2;
      ones += digit;
      if ( inZeroes )
      {
         if ( !digit ) endZeroes++;
         else inZeroes = false;
      }

   }
}


//=====================================================================


int countOperations( INT A, INT B )
{
   // Special cases
        if ( A == B ) return 0;
   else if ( B == 0 ) return -1;
   else if ( B == 1 ) return ( A == 0 ? 1 : -1 );

   int onesA, onesB, endZeroesA, endZeroesB;
   
   countBits( A, onesA, endZeroesA );
   countBits( B, onesB, endZeroesB );

   int ops = onesB - onesA + endZeroesB;
   return ops > 0 ? ops : 2;
}


//=====================================================================


int main()
{
// istream &in = cin;                  // Use this for actual input
// stringstream in( "2\n"              // Alternative version for testing
//                  "2 4\n"
//                  "1 5\n" );
  

   int N;
   INT A, B;

   cin >> N;

   for ( int i = 0; i < N; i++ )
   {
      cin >> A >> B;
      cout << countOperations( A, B ) << '\n';
   }
}