#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void encryption(string, fstream &);
char returnDecrypt(char);
int main()
{
	ifstream decrypted;
	string decrypt="text.txt";
	
	ofstream encrypt("encrypted.txt");

	char letter;

	decrypted.open(decrypt);

	decrypted.seekg(0L, ios::beg);
	decrypted.get(letter);
	while(!decrypted.eof())
	{
		encrypt.put(returnDecrypt(letter));
		decrypted.get(letter);
	}

	decrypted.close();
	system("Pause");
	return 0;
}

void encryption(string decrypt,fstream &decrypted )
{
	fstream encrypted;
	string encrypt="encrypted.txt";
	char let;

	encrypted.open(encrypt, ios::out);
	decrypted.open(decrypt, ios::in);

	if (decrypted.fail())
		cout << "Error in opening file " << decrypt << " !!!\n";

	decrypted.seekg(0L, ios::beg);

	decrypted.get(let);
	while(!decrypted.eof())
	{
		decrypted>>let;
		encrypted.put(returnDecrypt(let));
	}
	encrypted << endl;
	decrypted.close();
	encrypted.close();
	cout << "File " << decrypt << " encrypted sugessfully. \n";
}
char returnDecrypt(char let)
{
	return let + 10;
}
