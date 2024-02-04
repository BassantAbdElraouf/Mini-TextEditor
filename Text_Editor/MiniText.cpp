#include "MiniText.h"
#include<iostream>
#include<fstream>
#include<exception>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<utility>
using namespace std;
map<int, string>Lines;
int numline, Count = 0;
string input, temp;
stack<pair<int, pair<int, string>>>undostack;
stack<int>undoreplace;

void MiniText::open()
{
	ifstream myfile;
	myfile.open("..\\Test.txt");
	for (int i = 1; !(myfile.eof()); i++)
	{
		getline(myfile, input);
		if (input != "")
		{
			Lines[i] = input;
			Count++;
		}
	}
	myfile.close();
}
void MiniText::close()
{
	ofstream myfile;
	myfile.clear();
	myfile.open("..\\Test.txt");
	for (int i = 1; i <= Count; i++)
	{
		myfile << Lines[i] << endl;
	}
	myfile.close();
	Lines.clear();
}
void MiniText::add()
{
	Count++;
	cout << "Enter your string" << endl;
	cin.ignore();
	getline(cin, input);
	Lines[Count] = input;
	undostack.push({ 1,{Count,input} });
	cout << endl << "#####################################################################" << endl;
}
void MiniText::insert()
{
	cout << "Enter number of line" << endl;
	cin >> numline;
	if (Lines[numline].empty())
	{
		cout << "Enter your string" << endl;
		Count++;
		for (int  i = Count; i < numline ; i++)
		{
			Lines[i] = " ";
			Count++;
		}
		cin.ignore();
		getline(cin, input);
		Lines[numline] = input;
	}
	else
	{
		Count++;
		for (int i = Count; i > numline; i--)
		{
			temp = Lines[i - 1];
			Lines[i] = temp;

		}
		cout << "Enter your string" << endl;
		cin.ignore();
		getline(cin, input);
		Lines[numline] = input;
	
	}

	undostack.push({ 2,{numline,input} });
	cout << endl << "#####################################################################" << endl;
}
void MiniText::Delete()
{
	cout << "Enter number of line" << endl;
	cin >> numline;
	undostack.push({ 3,{numline,Lines[numline]} });
	if (numline <= Count)
	{
		for (int i = numline; i < Count; i++)
		{
			temp = Lines[i + 1];
			Lines[i] = temp;

		}
		Lines.erase(Count);
		Count--;
	} 
	else if (numline == Count)
	{
		Lines.erase(Count);
		Count--;
	}
	else
		cout << "There is not  number of this line" << endl;
	cout << endl << "#####################################################################" << endl;
}
void MiniText::DeleteRange()
{
	int start, end;
	cout << "Enter the start of rang" << endl;
	cin.ignore();
	cin >> start;
	cout << "Enter  the end of rang" << endl;
	cin.ignore();
	cin >> end;
	 int range = (end - start) + 1;
	 if (start <= Count && end <= Count)
	 {
		 for (int i = start; i <= Count; i++)
		 {
			 undostack.push({ 7,{i,Lines[i]} });
		 }
		 for (int i = start; i <= Count; i++)
		 {
			 int dellines = range;
			 for (int  j = (i+range) ; ; j++)
			 {
				 if (j <= Count && dellines != 0)
				 {
					 Lines[i] = Lines[j];
					 i++, dellines--;
				 }
				 else
					 break;
			 }
		 }
		 while (range--)
		 {
			 Lines.erase(Count);
			 Count--;
		 }
	 }
	else
		cout << "This range is out of boundres";
}
void MiniText::update()
{
	cout << "Enter number of line" << endl;
	cin >> numline;
	if (numline <= Count)
	{
		undostack.push({ 4,{numline,Lines[numline]} });
		cout << "please, Enter your update" << endl;
		cin.ignore();
		getline(cin, input);
		Lines[numline] = input;
	}
	else
		cout << "There is not  number of this line" << endl;
	cout << endl << "#####################################################################" << endl;
}

void MiniText::Find()
{
	string word;
	cout << "Enter your word to find" << endl;
	cin.ignore();
	getline(cin, word);
	queue<int>finds;
	string strlower, wordlower = word;

	for (int i = 0; i < word.size(); i++)
	{
		wordlower[i] = tolower(word[i]);
	}

	for (int i = 1; i <= Count; i++)
	{

		strlower = Lines[i];
		for (int i = 0; i < strlower.size(); i++)
		{
			strlower[i] = tolower(strlower[i]);
		}

		if (strlower.find(wordlower) != -1)
		{
			finds.push(i);
		}
	}

	if (finds.empty())
		cout << "This word does not  found in text" << endl;
	else
	{
		while (!finds.empty())
		{
			cout << "This word " << word << " is found in line number " << finds.front() << endl;
			finds.pop();
		}
	}
	cout << endl << "#####################################################################" << endl;
}
void MiniText::Replace()
{
	string word, replace;
	cout << "Enter the old word" << endl;
	cin.ignore();
	getline(cin, word);
	cout << "Enter the new word" << endl;
	getline(cin, replace);
	string strlower, wordlower = word;
	bool found = false;

	for (int i = 0; i < word.size(); i++)
	{
		wordlower[i] = tolower(wordlower[i]);
	}

	for (int i = 1; i <= Count; i++)
	{
		strlower = Lines[i];
		for (int i = 0; i < strlower.size(); i++)
		{
			strlower[i] = tolower(strlower[i]);
		}
		while (strlower.find(wordlower) != -1)
		{
			found = true;
			int index = strlower.find(wordlower);
			word = Lines[i].substr(index, word.size());
			Lines[i].replace(index, wordlower.size(), replace);
			strlower.replace(index, wordlower.size(), replace);
			undostack.push({ 5,{i,word} });
			undostack.push({ 6,{i,replace} });
			undoreplace.push(index);
		}
	}
	if (!found)
		cout << "The old word doesn’t  exist in text" << endl;
	cout << endl << "#####################################################################" << endl;
}
void MiniText::getLine()
{
	cout << "Enter number of line" << endl;
	cin >> numline;
	if (numline <= Count)
	{
		cout << Lines[numline] << endl;
	}
	else
		cout << "There is not  number of this line" << endl;
	cout << endl << "#####################################################################" << endl;
}
void MiniText::show()
{
	cout << "==============================File Content======================="<<endl;
	for (int i = 1; i <= Count; i++)
	{
		cout << i << " " << Lines[i] << endl;
	}
	cout << "================================END=============================="<<endl;
	cout << endl << "#####################################################################" << endl;
}
void MiniText::undo()
{
	if (!undostack.empty())
	{
		if (undostack.top().first == 1)
		{
			Lines.erase(Count);
			Count--;
			undostack.pop();
		}
		else if (undostack.top().first == 2)
		{
			numline = undostack.top().second.first;
			if (Lines[numline - 1] == " " && numline - 1 != 0)
			{
				Lines.erase(numline);
				numline--;
				Count--;
				while (Lines[numline] == " ")
				{
					Lines.erase(numline);
					numline--;
					Count--;
				}
			}
			else
			{
				for (int i = undostack.top().second.first; i < Count; i++)
				{
					temp = Lines[i + 1];
					Lines[i] = temp;
				}
				Lines.erase(Count);
				Count--;
			}
			undostack.pop();
		}
		else if (undostack.top().first == 3)
		{
			numline = undostack.top().second.first;
			if (numline == (Count + 1))
			{
				Lines[numline] = undostack.top().second.second;
			}
			else
			{
				for (int i = Count + 1; i > numline; i--)
				{
					temp = Lines[i - 1];
					Lines[i] = temp;
				}
				Lines[numline] = undostack.top().second.second;
				Count++;
			}
			undostack.pop();
		}
		else if (undostack.top().first == 4)
		{
			Lines[undostack.top().second.first] = undostack.top().second.second;
			undostack.pop();
		}
		else if (undostack.top().first == 6)
		{
			while (!(undostack.empty()) &&undostack.top().first == 6)
			{
				string word = undostack.top().second.second;
				undostack.pop();
				string replace = undostack.top().second.second;
				numline = undostack.top().second.first;
				undostack.pop();
				int ind = undoreplace.top();
				undoreplace.pop();
				Lines[numline].replace(ind, word.size(), replace);
			}
		}
		else if (undostack.top().first == 7)
		{
			for (int i = 1; !(undostack.empty())&& undostack.top().first == 7; i++)
			{
				numline = undostack.top().second.first;
				Lines[numline] = undostack.top().second.second;
				undostack.pop();
			}
			Count = Lines.size();
		}
		show();
	}
	else
	{
	cout << "The undostack is empty";
	}
	cout << endl << "#####################################################################" << endl;
}
