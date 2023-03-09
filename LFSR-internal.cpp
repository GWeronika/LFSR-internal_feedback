#include <iostream>
#include <math.h>			//for exponentation

using namespace std;

int main()
{
	int n, r;			//n - register length (integer); r - initial state {0,1}
	cout << "Program generuje liczby losowe ze sprzezeniem wewnetrznym" << endl;
	cout << "Podaj dlugosc rejestru ze zbioru liczb calkowitych {2,20} " << endl;
	cin >> n;

	cout << "Podaj stan poczatkowy o dlugosci " << n << " zlozony z cyfr ze zbioru {0,1} " << endl;
	cin >> r;

	int rozmiar = pow(2, n) - 1;			//maximum length of the binary sequence
	int* tab = new int[n];					//contains initial state - shortens over time
	int* wynik = new int[rozmiar];			//contains successive elements of the register
	int* bufor = new int[n];				//ancillary array - contains not used parts of the initial state

	do
	{
		for (int i = n - 1; i >= 0; i--)			//extracts all digits of the initial state
		{
			tab[i] = r % 10;
			r /= 10;
		}
	} while (r > 1);

	for (int i = 0; i < rozmiar; i++)
	{
		wynik[i] = tab[n - 1];			//saves the last digit, already in the final result
		if ((tab[n - 2] == 0) && (tab[n - 1] == 0) || (tab[n - 2] == 1) && (tab[n - 1] == 1)) {				//XOR gate if false
			for (int j = 0; j < n - 1; j++) {
				bufor[j] = tab[j];				//saves the last content of tab[]
			}
			tab[0] = tab[n - 1];			//assigns the value of the last tab[] element to the first element
			for (int k = 1; k <= n - 2; k++) {
				tab[k] = bufor[k - 1];			//tab[] receives the initial state (without the first element)
			}
			tab[n - 1] = 0;				//result of the XOR gate passes to the last element
		}
		else {																								//XOR gate if true
			for (int j = 0; j < n - 1; j++) {
				bufor[j] = tab[j];				//saves the last content of tab[]
			}
			tab[0] = tab[n - 1];			//assigns the value of the last tab[] element to the first element
			for (int k = 1; k <= n - 2; k++) {
				tab[k] = bufor[k - 1];			//tab[] receives the initial state (without the first element)
			}
			tab[n - 1] = 1;				//result of the XOR gate passes to the last element
		}
	}
	for (int i = 0; i < rozmiar; i++)
	{
		cout << wynik[i];			//output
	}
	return 0;
}