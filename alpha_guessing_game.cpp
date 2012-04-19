//Dean Rather's: guessing game
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

string th(int num);
void testRandomNumbers();
void testTh();

int main()
{ 
    srand(time(0));
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    cout << "Welcome to Dean's letter gussing game!\nHave Fun!!\n\n";
    
    char again = 'y';
    while (again == 'y' || again == 'Y')
    {
        string guess = "";
        int number = (rand()%26)+1;
        char answer = alphabet[number];
        
        while (guess[0] != '0')
        {
            cout << "What is the " << number << th(number) << " letter  of the alphabet?\n";
            cin >> guess;
            
            cout << "\nYour Guess, " << guess[0];
            bool valid = false;
            for (int i = 0; i < alphabet.length(); i++)
                if (toupper(guess[0]) == alphabet[i])
                   valid = true;
            if (!valid)
               cout << " is not a letter A - Z\n";
            else
            {
                if (toupper(guess[0]) == alphabet[number-1])
                {
                    cout << " is correct! Congratulations!\n\n\n";
                    break;                      
                }
                
                if (toupper(guess[0]) > alphabet[number-1])
                   cout << " is to High!\n";
                else
                   cout << " is Too Low!\n";
            }//end if valid
        }//end while guess
        
        cout << "\n\nPlay again?(y/n):";
        cin >> again;
    }
    
    /*
    //Useless Info
    int numA = (rand()%4)+1;
    int numB = (rand()%4)+1;
    
    cout << "What is " << numA << " multiplied by " << numB << "?\n";
    cout << "What is " << alphabet[numA-1] << " multiplied by " << alphabet[numB-1] << "?\n";
    
    cout << "It's " << numA * numB << ".\n";
    cout << "It's " << alphabet[(numA * numB)-1] << ".\n";
    */    
    
    system("pause");
}

string th(int num)
{
   for (int i = 2; i < 100000000; i ++)
   {
       if (num > 10*i && num < 10*(i+1))
       {
          num -= 10*i;
          break;
       }
       else if (num < 20)
          break;
       else if (num == 10*i)
          break;
   }
       
   switch (num)
   {
   case 0:
        return "";
        break;
   case 1:
        return "st";
        break;
   case 2:
        return "nd";
        break;
   case 3:
        return "rd";
        break;
   default:
        return "th";
   }
   
   return "";
}

void testRandomNumbers()
{
    for (int i = 0; i < 1000; i++)
    {
        int x = (rand()%26) + 1;
        cout << x;
        if (x > 26)
           cout << "ERROR";
        if (x < 1)
           cout << "ERROR";
        if (x == 26)
           cout << "TWENTY SIX";
        cout << endl;        
    }
}

void testTh()
{
    //test th();
    for (int i = 0; i < 1000; i ++)
        cout << i << th(i) << ", ";
}
