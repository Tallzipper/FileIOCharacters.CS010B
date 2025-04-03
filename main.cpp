#include <fstream>
#include <iostream>
#include <cstdlib>
#include <limits.h>

using namespace std;

int charCnt(const string& fileName, char cha);

int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   

   if(chCnt != INT_MAX)
   {
      cout << "# of " << ch << "'s: " << chCnt << endl;
   }
   
   return 0;
}

int charCnt(const string& fileName, char cha){

   ifstream inFS;

   inFS.open(fileName);

   if(!inFS.is_open())
   {

      cout << "Error opening " << fileName << endl;
      return INT_MAX;

   }

   string temp;
   
   int total = 0;

      while(getline(inFS, temp))
      {
         for(unsigned int i = 0; i < temp.size() ; i++)
         {

            if(temp[i] == cha)
            {
               total++;
            
            }

         }
      }  

   inFS.close();

   return total;

}