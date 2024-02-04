#include<iostream>
#include "MiniText.h"
#include<Windows.h>
#include<stdlib.h>
#include<conio.h>

using namespace std;

int main()
{
	//HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);

	//SetConsoleTextAttribute(hc, );
	system("color 5");
	MiniText t;
	cout << "\t\t0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
	cout << endl<<"\t\t0\t\t                                                                          0";
	cout << endl;
	cout << "\t\t0\t\t###         ###   #########    ###     ##  #########                      0 "<<endl;
	cout << "\t\t0\t\t## #       # ##       ##       ## #    ##      ##                         0"<<endl;
	cout << "\t\t0\t\t##  #     #  ##       ##       ##  #   ##      ##                         0"<<endl;
	cout << "\t\t0\t\t##   #   #   ##       ##       ##   #  ##      ##                         0"<<endl;
	cout << "\t\t0\t\t##    # #    ##       ##       ##    # ##      ##                         0 "<<endl;
	cout << "\t\t0\t\t##     #     ##   #########    ##     ###  #########                      0"<<endl<<"\t\t0\t\t\t\t\t\t\t\t\t\t\t  0";
	cout << endl <<"\t\t0\t\t                                                                          0";
	cout << endl;
	cout << "\t\t0\t\t######    ## #    #########   ##########      #######    #####            0" <<  endl;
	cout << "\t\t0\t\t##        ##   #      ##          ##        ##      ##   ##   ##          0"<<endl;
	cout << "\t\t0\t\t##        ##    #     ##          ##       ##        ##  ##  ##           0"<<endl;
	cout << "\t\t0\t\t######    ##    #     ##          ##        ##      ##   ####             0"<<endl;
	cout << "\t\t0\t\t##        ##   #      ##          ##         ##    ##    ## ##            0"<<endl;
	cout << "\t\t0\t\t##        ##  #       ##          ##          ##  ##     ##  ##           0"<<endl;  
	cout << "\t\t0\t\t######    ###     #########       ##           ####      ##   ##          0"<<endl << "\t\t0\t\t\t\t\t\t\t\t\t\t\t  0";
	cout << endl;
	cout << "\t\t0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
	cout << endl;
	cout << endl;
	Sleep(6000);
	system("CLS");
	system("color B");

	t.open();
	while (true)
	{   
		int choise;
		cout << "\t\t\t###########################"<<endl<<"\t\t\t(\t\t\t  )";
		cout << endl;
		cout << "\t\t\t##\t1.add line       ##" << endl;
		cout << "\t\t\t##\t2.insert line    ##" << endl;
		cout << "\t\t\t##\t3.delete line    ##" << endl;
		cout << "\t\t\t##\t4.delete range   ##" << endl;
		cout << "\t\t\t##\t5.update line    ##" << endl;
		cout << "\t\t\t##\t6.Find Word      ##" << endl;
		cout << "\t\t\t##\t7.Replace Word   ##" << endl;
		cout << "\t\t\t##\t8.Get line       ##" << endl;
		cout << "\t\t\t##\t9.show lines     ##" << endl;
		cout << "\t\t\t##\t10.undo line     ##" << endl;
		cout << "\t\t\t##\t11.exit          ##" << endl << "\t\t\t(\t\t\t  )";
		cout << endl << "\t\t\t###########################" << endl;
		cout << "My Choice : ";
		cin >> choise;
		cout << endl;
		if (choise == 1)
		
			t.add();
		
		else if (choise == 2)

			t.insert();
		else if (choise == 3)
		
			t.Delete();
		
		else if (choise == 4)
			
			t.DeleteRange();
		
		else if (choise == 5)
			t.update();
		else if (choise == 6)
			t.Find();
		else if (choise == 7)
			t.Replace();
		else if (choise == 8)
		
			t.getLine();
		
		else if (choise == 9) {
			
			t.show();
		}
		else if (choise == 10)
			t.undo();
		else if (choise == 11)
		{
			t.close();
			break;
		}
		
	}
}

