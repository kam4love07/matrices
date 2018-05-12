#include <iostream>
using namespace std;

void getData(int m1[][10], int m2[][10], int r1, int c1, int r2, int c2);
void multiply(int m1[][10], int m2[][10], int multResult[][10], int r1, int c1, int r2, int c2);
void display(int mult[][10], int r1, int c2);

int main()
{
	int m1[10][10], m2[10][10], mult[10][10], r1, c1, r2, c2, i, j, k;

	cout << "Enter rows and column for first matrix: ";
	cin >> r1 >> c1;

	cout << "Enter rows and column for second matrix: ";
	cin >> r2 >> c2;

	// If colum of first matrix in not equal to row of second matrix, asking user to enter the size of matrix again.
	while (c1 != r2)
	{
		cout << "Error! column of first matrix not equal to row of second." << endl;
		cout << "Enter rows and column for first matrix: ";
		cin >> r1 >> c1;
		cout << "Enter rows and column for second matrix: ";
		cin >> r2 >> c2;
	}

	// Function to take matrices data
        getData(m1, m2, r1, c1, r2, c2);

        // Function to multiply two matrices.
        multiply(m1, m2, mult, r1, c1, r2, c2);

        // Function to display resultant matrix after multiplication.
        cout << "Multiplication Result";
        display(mult, r1, c2);

	return 0;
}

void getData(int m1[][10], int m2[][10], int r1, int c1, int r2, int c2)
{
	int i, j;
	cout << endl << "Enter elements of Matrix A:" << endl;
	for(i = 0; i < r1; ++i)
	{
		for(j = 0; j < c1; ++j)
		{
			cout << "Enter elements a"<< i + 1 << j + 1 << ": ";
			cin >> m1[i][j];
		}
	}
	
	display(m1, r1, c2);

	cout << endl << "Enter elements of Matrix B:" << endl;
	for(i = 0; i < r2; ++i)
	{
		for(j = 0; j < c2; ++j)
		{
			cout << "Enter elements b" << i + 1 << j + 1 << ": ";
			cin >> m2[i][j];
		}
	}
 	display(m2, r1, c2);
}


void multiply(int m1[][10], int m2[][10], int mult[][10], int r1, int c1, int r2, int c2)
{
	int i, j, k;

	// Initializing elements of matrix mult to 0.
	for(i = 0; i < r1; ++i)
	{
		for(j = 0; j < c2; ++j)
		{
			mult[i][j] = 0;
		}
	}

	// Multiplying matrix m1 and m2 and storing in array mult.
	for(i = 0; i < r1; ++i)
	{
		for(j = 0; j < c2; ++j)
		{
			for(k=0; k<c1; ++k)
			{
				mult[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
}

void display(int mult[][10], int r1, int c2)
{
	int i, j;

	cout << endl;
	for(i = 0; i < r1; ++i)
	{
		for(j = 0; j < c2; ++j)
		{
			cout << mult[i][j] << " ";
			if(j == c2 - 1)
				cout << endl << endl;
		}
	}
}
