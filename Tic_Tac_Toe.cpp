#include <iostream>
#include<windows.h>
using namespace std;

char turn=' ';
int box;
char block[3][3]={' ',' ',' ',
                  ' ',' ',' ',
                  ' ',' ',' '};
void printBlock()
{
    cout<<"\nBlock Diagram with Position : \n";
    cout<<"\t\t\t\t\t\t "<<'1'<<" | "<<'2'<<" | "<<'3';
    cout<<"\n\t\t\t\t\t\t-----------\n";
    cout<<"\t\t\t\t\t\t "<<'4'<<" | "<<'5'<<" | "<<'6';
    cout<<"\n\t\t\t\t\t\t-----------\n";
    cout<<"\t\t\t\t\t\t "<<'7'<<" | "<<'8'<<" | "<<'9';
    cout<<endl<<"------------------------------------------------------------------------------------------------------------------------";
    cout<<"Your Playing Board : \n";
    cout<<"\t\t\t\t\t\t "<<block[0][0]<<" | "<<block[0][1]<<" | "<<block[0][2];
    cout<<"\n\t\t\t\t\t\t-----------\n";
    cout<<"\t\t\t\t\t\t "<<block[1][0]<<" | "<<block[1][1]<<" | "<<block[1][2];
    cout<<"\n\t\t\t\t\t\t-----------\n";
    cout<<"\t\t\t\t\t\t "<<block[2][0]<<" | "<<block[2][1]<<" | "<<block[2][2];
    cout<<endl<<"------------------------------------------------------------------------------------------------------------------------";
}
int updateBlock(int x,char c)
{
    int val=1;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++,val++)
        {
            if(val==x)
            {
                if(block[i][j]==' ')
                {
                    block[i][j]=c;
                    return 1;
                }

                else
                {
                    cout<<"\nInvalid Input";
                    Sleep(500);
                    return 0;
                }
            }
        }
    }
}
int checkWin()
{
    //checking rows
    if((block[0][0]=='X' && block[0][1]=='X' && block[0][2]=='X')||
       (block[1][0]=='X' && block[1][1]=='X' && block[1][2]=='X')||
       (block[2][0]=='X' && block[2][1]=='X' && block[2][2]=='X'))
        return 1;
    else if((block[0][0]=='O' && block[0][1]=='O' && block[0][2]=='O')||
            (block[1][0]=='O' && block[1][1]=='O' && block[1][2]=='O')||
            (block[2][0]=='O' && block[2][1]=='O' && block[2][2]=='O'))
        return 2;
    //checking columns
    if((block[0][0]=='X' && block[1][0]=='X' && block[2][0]=='X')||
       (block[0][1]=='X' && block[1][1]=='X' && block[2][1]=='X')||
       (block[0][2]=='X' && block[1][2]=='X' && block[2][2]=='X'))
        return 1;
    else if((block[0][0]=='O' && block[1][0]=='O' && block[2][0]=='O')||
            (block[0][1]=='O' && block[1][1]=='O' && block[2][1]=='O')||
            (block[0][2]=='O' && block[1][2]=='O' && block[2][2]=='O'))
        return 2;
    //checking diagonals
    if((block[0][0]=='X' && block[1][1]=='X' && block[2][2]=='X')||
       (block[0][2]=='X' && block[1][1]=='X' && block[2][0]=='X'))
        return 1;
    else if((block[0][0]=='O' && block[1][1]=='O' && block[2][2]=='O')||
            (block[0][2]=='O' && block[1][1]=='O' && block[2][0]=='O'))
        return 2;

}
int main()
{
    SetConsoleTitle("Tic-Tac-Toe : TheCyberAtom");
    //player 1 -> 1
    //player 2 -> 0
    for(int i=0;i<9;i++)
    {
        system("cls");
        printBlock();
        if(i%2==0)
        {
           turn='X';
        }
        else
        {
           turn='O';
        }
        cout<<"\n\t\t\t\t\t Player --- "<<turn<<" --- turn";
        cout<<"\nEnter Box Number To Make Your Move : ";
        cin>>box;
        if(!updateBlock(box,turn))
            i--;
        if(checkWin()==1)
        {
            system("cls");
            printBlock();
            cout<<"\n\n\t\t\t\t\t Player --- X --- Won";
            Sleep(1000);
            break;
        }
        if(checkWin()==2)
        {
            system("cls");
            printBlock();
            cout<<"\n\n\t\t\t\t\t Player --- O --- Won";
            Sleep(1000);
            break;
        }
    }
    return 0;
}
