//  Implement recursive function and analyyse their complexy 
// a) wrie a recursive functionto gererate all permutions of a string (eg. Password generator / anagram tool

#include <iostream>
#include <string>
using namespace std;

void permute(string str, int l, int r)
{
    if (l == r)
    {
        cout << str << endl;
        return;
    }

    for (int i = l; i <= r; i++)
    {
        bool duplicate = false;
        for (int j = l; j < i; j++)
        {
            if (str[j] == str[i])
            {
                duplicate = true;
                break;
            }
        }
        if (duplicate)
            continue;
        swap(str[l], str[i]);
        permute(str, l + 1, r);
        swap(str[l], str[i]);                                         
    }
}

int main()
{
    string str;
    cout << "Enter a String: ";
    cin >> str;
    cout << "\nPermutations are:\n";
    permute(str, 0, str.length() - 1);
    return 0;
}



// Assignment 1 B
// Implement recursive solution to solve Tower of Hanoi and display moves + analyze time complexity.
// #include<iostream>

// using namespace std;

// void towerOfHanoi(int n, char source,char auxiliary,char destination)
// {
//     if(n == 1)
//     {
//         cout<<"Move Disk 1 From "<<source<<" to "<<destination<<endl;
//         return;
//     }

//      towerOfHanoi(n-1,source,destination,auxiliary);
     
//      cout<<"Move Disk "<<n<< " from "<<source<<" to "<<destination<<endl;

//     towerOfHanoi(n-1,auxiliary,source,destination);
// }
// int main()
// {
//     int n = 0;

//     cout<<"Enter number of disks:";
//     cin>>n;

//     towerOfHanoi(n,'A','B','C');

//     return 0;
// }