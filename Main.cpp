#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

//Constants
const int SIZE = 3;

//Structures
struct BookInfo
{
	string title;
	double price;
};

struct Author
{
	string name;
	BookInfo info[SIZE];
};

//Function Prototypes
void getInfo(Author a[], int size);
void showInfo(Author a[], int size);

int main()
{
	//Creating/initializing Author array
	Author authorList[SIZE] = {
			"None", {"None", 0.00, "None", 0.00, "None", 0.00},
			"None", {"None", 0.00, "None", 0.00, "None", 0.00},
			"None", {"None", 0.00, "None", 0.00, "None", 0.00}
	};

	//Show initialized authorList
	showInfo(authorList, SIZE);
	cout << endl;

	//Let the end user populate authorList
	getInfo(authorList, SIZE);
	cout << endl;

	//Show the newly populated authorList
	showInfo(authorList, SIZE);
	cout << endl;

	cout << "Done. ";	
	system("pause");
	return 0;
}

//Function Definitions
void getInfo(Author a[], int size)
{
	//Creating a temporary character array with max storage of 50 characters
	//Prevents losing first character of the string input fields.
	char tmp[50];

	for (int x = 0; x < size; x++)
	{
		//Prompt for Author
		cout << "Enter the author's name: ";

		//Only getline for the first iteration
		if(x == 0)
		{
			cin.ignore(0,'\n');
			getline(cin, a[x].name);
		}
		else
		{
			cin.get();
			cin.get(tmp,50);

			//Set the input to the name field of the authorList array
			a[x].name = tmp;
		}

		//Break whenever "none" is an input for the name field
		if (a[x].name == "none" || a[x].name == "None")
			break;

		for (int y = 0; y < size; y++)
		{
			cout << "Enter book title #" << y + 1 << ": ";

			//Only getline for the first iteration
			if(x == 0 && y == 0)
			{
				cin.ignore(0,'\n');
				getline(cin, a[x].info[y].title);
			}
			else
			{
				cin.get();
				cin.get(tmp,50);

				//Set the input to the title field of the info array of the authorList array
				a[x].info[y].title = tmp;
			}

			//Break whenever "none" is an input for the title field
			if(a[x].info[y].title == "none" || a[x].info[y].title == "None")
				break;

			cout << "Enter book price #" << y + 1 << ": $";
			cin >> a[x].info[y].price;
		}
	}
}

void showInfo(Author a[], int size)
{
	for (int x = 0; x < size; x++)
	{
		cout << "Author: " << a[x].name << endl;

		for (int y = 0; y < size; y++)
		{
			cout << fixed << showpoint << setprecision(2);

			//Perfectly align the Price Column
			if(a[x].info[y].title.length() <= 8)
			{
			cout << "\t" << "Title: " << a[x].info[y].title
				<< "\t\tPrice: $" << a[x].info[y].price << endl;
			}
			else
			{
				cout << "\t" << "Title: " << a[x].info[y].title
				<< "\tPrice: $" << a[x].info[y].price << endl;
			}
		}
	}
}
