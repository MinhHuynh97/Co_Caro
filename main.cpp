#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <dos.h>
#include <windows.h>
using namespace std;

typedef struct point
{
    int x; // toa do hang
    int y; // toa do cot
} toa_do;

typedef vector<vector<int>> ban_co;

void print_ban_co(ban_co bc)
{
    int kich_thuoc = bc.size();
    cout << "  " ;
    for(int i = 0; i < kich_thuoc; i++)
        cout << i << " ";
    for(int i = 0; i < kich_thuoc; i++)
    {
        cout << endl;
        cout << i << " ";
        for(int j = 0; j < kich_thuoc; j++)
        {
            if(bc[i][j] == 0)
                cout << "- ";
            else if(bc[i][j] == -1)
                cout << "X ";
            else
                cout << "O ";
        }
    }
    cout << endl;
}

ban_co init_ban_co(int _size) // size la so chan
{
    ban_co bc(_size, vector<int>(_size));
    int i = _size/2 - 1;
    bc[i][i] = -1; bc[i][i+1] = 1;
    bc[i+1][i] = 1; bc[i+1][i+1] = -1;
    return bc;
}



vector<toa_do> generate_valid_moves(ban_co bc, int player)
{
    vector<toa_do> kq;
    vector<toa_do> kq3;
    int sizebc=bc.size();
    bool kt=false,trung;
    /* Hang ngang trai qua phai */
    for(int i=0;i<sizebc;i++)
    {
        for(int j=0;j<sizebc;j++)
        {
            if(bc[i][j]==player)
            {
                for(int k=1;k<sizebc;k++)
                {
                    if(j+k<sizebc){
                if(bc[i][j+k]==0)
                {
                    for(int m=1;m<=k-1;m++)
                    {
                        if(bc[i][j+m]==-player)
                        {
                            kt=true;
                        }
                        else
                        {
                        kt=false;
                        break;
                        }

                    }
                    if(kt==true)
                    {

                        toa_do t;t.x=i;t.y=j+k;
                        kq.push_back(t);
                        kt=false;


                    }}
                }}
            }
        }
    }
    for(int i=0;i<sizebc;i++)
    {
        for(int j=sizebc-1;j>=0;j--)
        {
            if(bc[i][j]==player)
            {
                for(int k=1;k<sizebc;k++)
                {if(j-k>=0){
                if(bc[i][j-k]==0)
                {
                    for(int m=1;m<=k-1;m++)
                    {
                        if(bc[i][j-m]==-player)
                        {
                            kt=true;
                        }
                        else
                        {
                        kt=false;
                        break;
                        }

                    }
                    if(kt==true)
                    {

                        toa_do t;t.x=i;t.y=j-k;
                        kq.push_back(t);kt=false;

                    }}
                }}
            }
        }
    }
    for(int j=0;j<sizebc;j++)
    {
        for(int i=0;i<sizebc;i++)
        {
            if(bc[i][j]==player)
            {
                for(int k=1;k<sizebc;k++)
                {if(i+k<sizebc){
                if(bc[i+k][j]==0)
                {
                    for(int m=1;m<=k-1;m++)
                    {
                        if(bc[i+m][j]==-player)
                        {
                            kt=true;
                        }
                        else
                        {
                        kt=false;
                        break;
                        }

                    }
                    if(kt==true)
                    {

                        toa_do t;t.x=i+k;t.y=j;
                        kq.push_back(t);kt=false;

                    }}
                }}
            }
        }
    }
    /* Xet theo chieu doc tu duoi len*/
     for(int j=0;j<sizebc;j++)
    {
        for(int i=sizebc-1;i>=0;i--)
        {
            if(bc[i][j]==player)
            {

                for(int k=1;k<sizebc;k++)
                {if(i-k>=0){
                if(bc[i-k][j]==0)
                {
                    for(int m=1;m<=k-1;m++)
                    {
                        if(bc[i-m][j]==-player)
                        {
                            kt=true;
                        }
                        else
                        {
                        kt=false;
                        break;
                        }

                    }
                    if(kt==true)
                    {

                        toa_do t;t.x=i-k;t.y=j;
                        kq.push_back(t);kt=false;


                    }
                }}}
            }
        }
    }
    /* Xet theo duong cheo tu trai sang tu tren xuong */
     for(int i=0;i<sizebc;i++)
    {
        for(int j=0;j<sizebc;j++)
        {
            if(bc[i][j]==player)
            {

                for(int k=1;k<sizebc;k++)
                {if(i+k<sizebc && j+k<sizebc){
                if(bc[i+k][j+k]==0)
                {
                    for(int m=1;m<=k-1;m++)
                    {
                        if(bc[i+m][j+m]==-player)
                        {
                            kt=true;
                        }
                        else
                        {
                        kt=false;
                        break;
                        }

                    }
                    if(kt==true)
                    {

                        toa_do t;t.x=i+k;t.y=j+k;
                        kq.push_back(t);kt=false;


                    }
                }}}
            }
        }
    }
    /* Xet */
    for(int i=0;i<sizebc;i++)
    {
        for(int j=sizebc-1;j>=0;j--)
        {
            if(bc[i][j]==player)
            {

                for(int k=1;k<sizebc;k++)
                {if(i+k<sizebc && j-k>=0){
                if(bc[i+k][j-k]==0)
                {
                    for(int m=1;m<=k-1;m++)
                    {
                        if(bc[i+m][j-m]==-player)
                        {
                            kt=true;
                        }
                        else
                        {
                        kt=false;
                        break;
                        }

                    }
                    if(kt==true)
                    {

                        toa_do t;t.x=i+k;t.y=j-k;
                        kq.push_back(t);kt=false;


                    }
                }}}
            }
        }
    }
    for(int j=0;j<sizebc;j++)
    {
        for(int i=sizebc-1;i>=0;i--)
        {
            if(bc[i][j]==player)
            {

                for(int k=1;k<sizebc;k++)
                {if(j+k<sizebc && i-k>=0){
                if(bc[i-k][j+k]==0)
                {
                    for(int m=1;m<=k-1;m++)
                    {
                        if(bc[i-m][j+m]==-player)
                        {
                            kt=true;
                        }
                        else
                        {
                        kt=false;
                        break;
                        }

                    }
                    if(kt==true)
                    {

                        toa_do t;t.x=i-k;t.y=j+k;
                        kq.push_back(t);kt=false;


                    }
                }}}
            }
        }
    }
    for(int i=sizebc-1;i>=0;i--)
    {
        for(int j=sizebc-1;j>=0;j--)
        {
            if(bc[i][j]==player)
            {

                for(int k=1;k<sizebc;k++)
                {if(j-k>=0 && i-k>=0){
                if(bc[i-k][j-k]==0)
                {
                    for(int m=1;m<=k-1;m++)
                    {
                        if(bc[i-m][j-m]==-player)
                        {
                            kt=true;
                        }
                        else
                        {
                        kt=false;
                        break;
                        }

                    }
                    if(kt==true)
                    {

                        toa_do t;t.x=i-k;t.y=j-k;
                        kq.push_back(t);kt=false;



                    }
                }}}
            }
        }
    }
    for(toa_do item:kq)
    {
        if(kq3.size()==0)
        {
            kq3.push_back(item);

        }else{

             for(toa_do item1:kq3)
            {
                if(item1.x==item.x && item1.y==item.y)
                {
                    trung=true;
                    break;
                }else trung=false;
            }
                if(trung==false)
                {
                    kq3.push_back(item);
                }
        }

    }



     return kq3;

}

vector<toa_do> generate_valid_moves1(ban_co &bc,int player)
{
    vector<toa_do> kq=generate_valid_moves(bc,player);
    vector<toa_do> kq1;
     for(toa_do item:kq)
    {
        for(toa_do item1:kq1)
        {
            if(item.x!=item1.x && item.y!=item1.y)
            {
                kq1.push_back(item);

            }
        }
    }
    return kq1;
}

void play_moves1(ban_co& bc, int player,vector<toa_do>k)
{
    toa_do vitri;
    bool kt=false;


    for(toa_do vitri :k)
    {

            bc[vitri.x][vitri.y]=player;

    }



    for(int k=1;k<bc.size();k++)
    {
        if(vitri.y+k<bc.size()){
        if(bc[vitri.x][vitri.y+k]==player)
        {
            for(int m=1;m<k;m++)
            {
                if(bc[vitri.x][vitri.y+m]==-player)
                {
                    kt=true;
                }else{kt=false;
                break;}

            }
            if(kt==true)
            {
                for(int m=1;m<k;m++)
                {
                    bc[vitri.x][vitri.y+m]=player;
                }
            }
        }}

        if(vitri.y-k>=0){
        if(bc[vitri.x][vitri.y-k]==player)
        {
            for(int m=1;m<k;m++)
            {
                if(bc[vitri.x][vitri.y-m]==-player)
                {
                    kt=true;
                }else{kt=false;
                break;}

            }
            if(kt==true)
            {
                for(int m=1;m<k;m++)
                {
                    bc[vitri.x][vitri.y-m]=player;
                }
            }
        }}

        if(vitri.x+k<bc.size()){
        if(bc[vitri.x+k][vitri.y]==player)
        {
            for(int m=1;m<k;m++)
            {
                if(bc[vitri.x+m][vitri.y]==-player)
                {
                    kt=true;
                }else{kt=false;
                break;}

            }
            if(kt==true)
            {
                for(int m=1;m<k;m++)
                {
                    bc[vitri.x+m][vitri.y]=player;
                }
            }
        }}

        if(vitri.x-k>=0){
        if(bc[vitri.x-k][vitri.y]==player)
        {
            for(int m=1;m<k;m++)
            {
                if(bc[vitri.x-m][vitri.y]==-player)
                {
                    kt=true;
                }else{kt=false;
                break;}

            }
            if(kt==true)
            {
                for(int m=1;m<k;m++)
                {
                    bc[vitri.x-m][vitri.y]=player;
                }
            }
        }}

         if(vitri.x+k<bc.size() && vitri.y+k<bc.size()){
        if(bc[vitri.x+k][vitri.y+k]==player)
        {
            for(int m=1;m<k;m++)
            {
                if(bc[vitri.x+m][vitri.y+m]==-player)
                {
                    kt=true;
                }else{kt=false;
                break;}

            }
            if(kt==true)
            {
                for(int m=1;m<k;m++)
                {
                    bc[vitri.x+m][vitri.y+m]=player;
                }
            }
        }}

         if(vitri.x+k<bc.size() && vitri.y-k>=0){
        if(bc[vitri.x+k][vitri.y-k]==player)
        {
            for(int m=1;m<k;m++)
            {
                if(bc[vitri.x+m][vitri.y-m]==-player)
                {
                    kt=true;
                }else{kt=false;
                break;}

            }
            if(kt==true)
            {
                for(int m=1;m<k;m++)
                {
                    bc[vitri.x+m][vitri.y-m]=player;
                }
            }
        }}

         if(vitri.x-k>=0 && vitri.y+k<bc.size()){
        if(bc[vitri.x-k][vitri.y+k]==player)
        {
            for(int m=1;m<k;m++)
            {
                if(bc[vitri.x-m][vitri.y+m]==-player)
                {
                    kt=true;
                }else{kt=false;
                break;}

            }
            if(kt==true)
            {
                for(int m=1;m<k;m++)
                {
                    bc[vitri.x-m][vitri.y+m]=player;
                }
            }
        }}

         if(vitri.x-k>=0 && vitri.y-k>=0){
        if(bc[vitri.x-k][vitri.y-k]==player)
        {
            for(int m=1;m<k;m++)
            {
                if(bc[vitri.x-m][vitri.y-m]==-player)
                {
                    kt=true;
                }else{kt=false;
                break;}

            }
            if(kt==true)
            {
                for(int m=1;m<k;m++)
                {
                    bc[vitri.x-m][vitri.y-m]=player;
                }
            }
        }}
    }

    return;

}

void play_moves(ban_co& bc, int player)
{
    toa_do vitri;
    bool kt=false;
    do{
    cin>>vitri.x>>vitri.y;
    for(toa_do item :generate_valid_moves(bc,player))
    {
        if(item.x==vitri.x && item.y==vitri.y && bc[vitri.x][vitri.y]==0)
        {
            kt=true;
            bc[vitri.x][vitri.y]=player;
            break;

        }else kt=false;

    }
    }while(kt!=true);


    for(int k=1;k<bc.size();k++)
    {
        if(vitri.y+k<bc.size()){
        if(bc[vitri.x][vitri.y+k]==player)
        {
            for(int m=1;m<k;m++)
            {
                if(bc[vitri.x][vitri.y+m]==-player)
                {
                    kt=true;
                }else{kt=false;
                break;}

            }
            if(kt==true)
            {
                for(int m=1;m<k;m++)
                {
                    bc[vitri.x][vitri.y+m]=player;
                }
            }
        }}

        if(vitri.y-k>=0){
        if(bc[vitri.x][vitri.y-k]==player)
        {
            for(int m=1;m<k;m++)
            {
                if(bc[vitri.x][vitri.y-m]==-player)
                {
                    kt=true;
                }else{kt=false;
                break;}

            }
            if(kt==true)
            {
                for(int m=1;m<k;m++)
                {
                    bc[vitri.x][vitri.y-m]=player;
                }
            }
        }}

        if(vitri.x+k<bc.size()){
        if(bc[vitri.x+k][vitri.y]==player)
        {
            for(int m=1;m<k;m++)
            {
                if(bc[vitri.x+m][vitri.y]==-player)
                {
                    kt=true;
                }else{kt=false;
                break;}

            }
            if(kt==true)
            {
                for(int m=1;m<k;m++)
                {
                    bc[vitri.x+m][vitri.y]=player;
                }
            }
        }}

        if(vitri.x-k>=0){
        if(bc[vitri.x-k][vitri.y]==player)
        {
            for(int m=1;m<k;m++)
            {
                if(bc[vitri.x-m][vitri.y]==-player)
                {
                    kt=true;
                }else{kt=false;
                break;}

            }
            if(kt==true)
            {
                for(int m=1;m<k;m++)
                {
                    bc[vitri.x-m][vitri.y]=player;
                }
            }
        }}

         if(vitri.x+k<bc.size() && vitri.y+k<bc.size()){
        if(bc[vitri.x+k][vitri.y+k]==player)
        {
            for(int m=1;m<k;m++)
            {
                if(bc[vitri.x+m][vitri.y+m]==-player)
                {
                    kt=true;
                }else{kt=false;
                break;}

            }
            if(kt==true)
            {
                for(int m=1;m<k;m++)
                {
                    bc[vitri.x+m][vitri.y+m]=player;
                }
            }
        }}

         if(vitri.x+k<bc.size() && vitri.y-k>=0){
        if(bc[vitri.x+k][vitri.y-k]==player)
        {
            for(int m=1;m<k;m++)
            {
                if(bc[vitri.x+m][vitri.y-m]==-player)
                {
                    kt=true;
                }else{kt=false;
                break;}

            }
            if(kt==true)
            {
                for(int m=1;m<k;m++)
                {
                    bc[vitri.x+m][vitri.y-m]=player;
                }
            }
        }}

         if(vitri.x-k>=0 && vitri.y+k<bc.size()){
        if(bc[vitri.x-k][vitri.y+k]==player)
        {
            for(int m=1;m<k;m++)
            {
                if(bc[vitri.x-m][vitri.y+m]==-player)
                {
                    kt=true;
                }else{kt=false;
                break;}

            }
            if(kt==true)
            {
                for(int m=1;m<k;m++)
                {
                    bc[vitri.x-m][vitri.y+m]=player;
                }
            }
        }}

         if(vitri.x-k>=0 && vitri.y-k>=0){
        if(bc[vitri.x-k][vitri.y-k]==player)
        {
            for(int m=1;m<k;m++)
            {
                if(bc[vitri.x-m][vitri.y-m]==-player)
                {
                    kt=true;
                }else{kt=false;
                break;}

            }
            if(kt==true)
            {
                for(int m=1;m<k;m++)
                {
                    bc[vitri.x-m][vitri.y-m]=player;
                }
            }
        }}
    }

    return;

}
void Ketqua(int a,int b)
{
    if(a<b)
    {
     cout<<"quan O thang"<<endl;

    }else if(a>b)
    {
        cout<<"quan X thang"<<endl;
    }
}
vector<toa_do>random(ban_co bc,int player)
{
    vector<toa_do>moves2=generate_valid_moves(bc,player);
    vector<toa_do>random;
    int dem=-1;
    do{

    for(toa_do item:moves2)
    {
       dem=rand()%100;
       if(dem==1)
       {
           random.push_back(item);
           break;
       }

    }
    }while(dem!=1);
    return random;
}
int main()
{
    srand (time(NULL));
    ban_co bc = init_ban_co(10);
    int demX=0,demO=0;
    int dem=0;
    bool kt=false;

    do{
    print_ban_co(bc);

    vector<toa_do> moves = generate_valid_moves(bc, -1);

    if(moves.size()!=0){
    cout<<"Nuoc di hop le cua X"<<endl;
    for (toa_do item : moves)
        cout << "(" << item.x << ", " << item.y << ")" << endl;
    play_moves1(bc,-1,random(bc,-1));

    }


    print_ban_co(bc);
    vector<toa_do> moves1 = generate_valid_moves(bc, 1);

    if(moves1.size()!=0){
    cout<<"Nuoc di hop le cua O"<<endl;
    for (toa_do item : moves1)
    cout << "(" << item.x << ", " << item.y << ")" << endl;

    play_moves1(bc,1,random(bc,1));

    }
    if(moves.size()==0 && moves1.size()==0)
    {
        kt=true;
    }
    for(int i=0;i<bc.size();i++)
    {
        for(int j=0;j<bc.size();j++)
        {
            if(bc[i][j]==0)
            {
                dem++;
            }
        }
    }
    }while(dem=!0 && kt==false);

    for(int i =0;i<bc.size();i++)
    {
        for(int j=0;j<bc.size();j++)
        {
            if(bc[i][j]==-1)
            {
                demX=demX+1;
            }
            else
            {
                demO=demO+1;
            }
        }
    }
    cout<<"quan X: "<<demX<<endl;
    cout<<"quan O: "<<demO<<endl;

    Ketqua(demX,demO);
    return 0;
}
