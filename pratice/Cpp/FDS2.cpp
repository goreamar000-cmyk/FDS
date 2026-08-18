// Assignment 2 A
// a) Create employee/ student database using array of structures.  Implement linear and binary search techniques
// (recursive and iterative) on the created database. Compare time complexity of both.
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct student
{
    int roll;
    string name;
    float marks;
};

int main()
{
    int n, key, choice;
    cout << "Enter number of students: ";
    cin >> n;

    student s[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Roll No: ";
        cin >> s[i].roll;

        cout << "Enter Name: ";
        cin >> s[i].name;

        cout << "Enter Marks: ";
        cin >> s[i].marks;
    }
    cout << "\n\n===== Student Data =====";
    for (int i = 0; i < n; i++)
    {
        cout << "\n\nStudent " << i + 1;
        cout << "\nRoll No: " << s[i].roll;
        cout << "\nName: " << s[i].name;
        cout << "\nMarks: " << s[i].marks;
    }
    cout << "\n\n===== SEARCH MENU =====";
    cout << "\n1. Linear Search";
    cout << "\n2. Binary Search";
    cout << "\nEnter your choice: ";
    cin >> choice;
    cout << "\nEnter Roll No to search: ";
    cin >> key;

    switch (choice)
    {
    case 1:
    {
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (s[i].roll == key)
            {
                cout << "\n===== Linear Search =====";
                cout << "\nStudent Found";
                cout << "\nRoll No: " << s[i].roll;
                cout << "\nName: " << s[i].name;
                cout << "\nMarks: " << s[i].marks;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "\nStudent not found";
        }
        break;
    }

    case 2:
    {
        sort(s, s + n, [](student a, student b)
             { return a.roll < b.roll; });
        int low = 0;
        int high = n - 1;
        bool found = false;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (s[mid].roll == key)
            {
                cout << "\n===== Binary Search =====";
                cout << "\nStudent Found";
                cout << "\nRoll No: " << s[mid].roll;
                cout << "\nName: " << s[mid].name;
                cout << "\nMarks: " << s[mid].marks;
                found = true;
                break;
            }
            else if (key < s[mid].roll)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (!found)
        {
            cout << "\nStudent not found";
        }
        break;
    }
    default:
    {
        cout << "\nInvalid choice";
    }
    }
    return 0;
}

// // Assignment 2 B
// //  Implement a phone contact search: use binary search (recursive and iterative)
// //to find contact names starting with given prefix)

// #include<iostream>
// #include<string>
// #include<algorithm>

// using namespace std;

// struct Contact
// {
//     string name ;
//      string phone;
// };

// bool startwith(string name , string prefix)
// {
//     if(prefix.length()>name.length())
//     {
//       return false;
//     }
//     name.substr(0,prefix.length()) == prefix;
// }
// // Iterative Binary Search

// int iterativeSearch(Contact c[],int n , string prefix)
// {
//     int low = 0, high =  -1;
//     int mid = 0;

//     while(low <= high)
//     {
//        mid = (low + high)/2;

//        if(startwith(c[mid].name,prefix))
//        {
//         return mid;
//        }

//        if(c[mid].name < prefix)
//        {
//         low = mid +1;
//        }
//        else
//        {
//         high = mid - 1;

//        }
//        return -1;
//     }

//     // Recursive Binary search

//     int recursiveSearch(Contact c[],int low, int high, string prefix);
//     {
//         if(low > high)
//         {
//             return -1;
//         }

//         int mid = (low + high)/2;

//         if(startwith(c[mid].name,prefix))
//         {
//             return mid;
//         }
//         if(c[mid].name< prefix)
//         {
//              recursiveSearch(c,mid+1,high,prefix);
//             recursiveSearch(c,low,mid-1,prefix);
//         }
//     }
// }
// int main()
// {
//     int n ;
//     cout<<"Enter number of conacts:";
//     cin>>n;

//     Contact c[n];

//     for(int i = 0; i < n; i++)
//     {
//        cout<<"\nEnter Name :";
//        cin>>c[i].name;

//        cout<<"Enter Phone:";
//        cin>>c[i].phone;
//     }

//     //sort contact

//     sort(c,c + n, [](Contact a, Contact b)
// {
//     return a.name<b.name;
// });
// string prefix;
// cout<<"\nEnter prefix to search:";
// cin>>prefix;

// //Iterative search

// int pos = iterativeSearch(c,n,prefix);
// {
//     cout<<"\n---=== Iterative Binary  search =--------\n";

//     if(pos != -1)
//     {
//         cout<<c[pos].name<<"-"<<c[pos].phone<<endl;
//     }
//     else
//     {
//         cout<<"Conact not found";
//     }

//     // Recursive search

//       pos = recursiveSearch(c,0, n -1, prefix);

//       cout<<"\n====== Recursive Binary search ====\n";

//       if(pos != -1)
//       {
//          cout<<c[pos].name<<"="<<c[pos].phone<<endl;
//       }
//       else
//       {
//         cout<<"Cotact not found";
//       }

//       return 0;
//     }
// }