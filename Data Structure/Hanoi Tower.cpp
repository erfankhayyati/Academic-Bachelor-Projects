#include<iostream>
using namespace std;
void hanoi ( int nDisk, char start, char temp, char finish )
{
  if ( nDisk == 1 )
    cout <<start <<" --> " <<finish <<endl;
  else
  {
    hanoi ( nDisk - 1, start, finish, temp );
    cout <<start <<" --> " <<finish <<endl;
    hanoi ( nDisk - 1, temp, start, finish );
  }
}
int main(){
	int n;
	cin >> n;
	hanoi(n,'A','B','C');
	
	return 0;
}

