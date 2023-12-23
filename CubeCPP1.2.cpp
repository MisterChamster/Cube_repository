//Potrzebne jak zającowi dzwonek
#include <iostream>
#include <stdlib.h>
#include <time.h>

void resetcube(int cube[6][9])
{
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<9; j++)
        {
            cube[i][j] = (i+1)*10 + j; 
        }
    }
}

bool iscubesolved(int cube[6][9])
{
    int comparecube[6][9];
    resetcube(comparecube);
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<9; j++)
        {
            if (cube[i][j] != comparecube[i][j]) return false; 
        }
    }
    return true;
}

void printcube(int cube[6][9])
{
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<9; j++)
        {
            std::cout<<cube[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

void printcolourscube(int cube[6][9])
{
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<9; j++)
        {
            if (cube[i][j]/10 == 1) std::cout<<"W ";
            else if (cube[i][j]/10 == 2) std::cout<<"Y ";
            else if (cube[i][j]/10 == 3) std::cout<<"G ";
            else if (cube[i][j]/10 == 4) std::cout<<"B ";
            else if (cube[i][j]/10 == 5) std::cout<<"O ";
            else if (cube[i][j]/10 == 6) std::cout<<"R ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

void rotatesquareright(int cube[6][9], int n)
{
    int topleft = cube[n][0];
    int topmid = cube[n][1];
    cube[n][0] = cube[n][6];
    cube[n][6] = cube[n][8];
    cube[n][8] = cube[n][2];
    cube[n][2] = topleft;
    cube[n][1] = cube[n][3];
    cube[n][3] = cube[n][7];
    cube[n][7] = cube[n][5];
    cube[n][5] = topmid;
}

void rotatesquareleft(int cube[6][9], int n)
{
    int topleft = cube[n][0];
    int topmid = cube[n][1];
    cube[n][0] = cube[n][2];
    cube[n][2] = cube[n][8];
    cube[n][8] = cube[n][6];
    cube[n][6] = topleft;
    cube[n][1] = cube[n][5];
    cube[n][5] = cube[n][7];
    cube[n][7] = cube[n][3];
    cube[n][3] = topmid;
}

void rotatesquare2(int cube[6][9], int n)
{
    int temp = cube[n][0];
    cube[n][0] = cube[n][8];
    cube[n][8] = temp;
    temp = cube[n][2];
    cube[n][2] = cube[n][6];
    cube[n][6] = temp;
    temp = cube[n][1];
    cube[n][1] = cube[n][7];
    cube[n][7] = temp;
    temp = cube[n][3];
    cube[n][3] = cube[n][5];
    cube[n][5] = temp;
}

void x(int cube[6][9])
{
    int temp;
    for(int i=0; i<9; i++)
    {
        temp = cube[3][8-i];
        cube[3][8-i] = cube[1][i];
        cube[1][i] = cube[2][i];
        cube[2][i] = cube[0][i];
        cube[0][i] = temp;
    }
    rotatesquareright(cube, 4);
    rotatesquareleft(cube, 5);
    std::cout<<"x ";
}

void x2(int cube[6][9])
{
    int temp;
    for(int i=0; i<9; i++)
    {
        temp = cube[0][i];
        cube[0][i] = cube[1][i];
        cube[1][i] = temp;
        temp = cube[3][i];
        cube[3][i] = cube[2][i];
        cube[2][i] = temp;
    }
    rotatesquare2(cube, 4);
    rotatesquare2(cube, 5);
    std::cout<<"x2 ";
}

void xp(int cube[6][9])
{
    int temp;
    for(int i=0; i<9; i++)
    {
        temp = cube[3][8-i];
        cube[3][8-i] = cube[0][i];
        cube[0][i] = cube[2][i];
        cube[2][i] = cube[1][i];
        cube[1][i] = temp;
    }
    rotatesquareright(cube, 5);
    rotatesquareleft(cube, 4);
    std::cout<<"xp ";
}

void y(int cube[6][9])
{
    int temp;
    for(int i=0; i<9; i++)
    {
        temp = cube[3][i];
        cube[3][i] = cube[5][i];
        cube[5][i] = cube[2][i];
        cube[2][i] = cube[4][i];
        cube[4][i] = temp;

    }
    rotatesquareright(cube, 1);
    rotatesquareleft(cube, 0);
    std::cout<<"y ";
}

void y2(int cube[6][9])
{
    int temp;
    for(int i=0; i<9; i++)
    {
        temp = cube[2][i];
        cube[2][i] = cube[3][i];
        cube[3][i] = temp;
        temp = cube[4][i];
        cube[4][i] = cube[5][i];
        cube[5][i] = temp;
    }
    rotatesquare2(cube, 1);
    rotatesquare2(cube, 0);
    std::cout<<"y2 ";
}

void yp(int cube[6][9])
{
    int temp;
    for(int i=0; i<9; i++)
    {
        temp = cube[3][i];
        cube[3][i] = cube[4][i];
        cube[4][i] = cube[2][i];
        cube[2][i] = cube[5][i];
        cube[5][i] = temp;

    }
    rotatesquareright(cube, 0);
    rotatesquareleft(cube, 1);
    std::cout<<"yp ";
}

void z(int cube[6][9])
{
    
    int temp;
    for(int i=0; i<9; i++)
    {
        temp = cube[1][i];
        cube[1][i] = cube[5][i];
        cube[5][i] = cube[0][i];
        cube[0][i] = cube[4][i];
        cube[4][i] = temp;
    }
    rotatesquareright(cube, 0);
    rotatesquareright(cube, 1);
    rotatesquareright(cube, 2);
    rotatesquareright(cube, 4);
    rotatesquareright(cube, 5);
    rotatesquareleft(cube, 3);
    std::cout<<"z ";
}

void z2(int cube[6][9])
{
    int temp;
    for(int i=0; i<9; i++)
    {
        temp = cube[1][i];
        cube[1][i] = cube[0][8-i];
        cube[0][8-i] = temp;
        temp = cube[4][i];
        cube[4][i] = cube[5][8-i];
        cube[5][8-i] = temp;
    }
    rotatesquare2(cube, 2);
    rotatesquare2(cube, 3);
    std::cout<<"z2 ";
}

void zp(int cube[6][9])
{
    int temp;
    for(int i=0; i<9; i++)
    {
        temp = cube[1][i];
        cube[1][i] = cube[4][i];
        cube[4][i] = cube[0][i];
        cube[0][i] = cube[5][i];
        cube[5][i] = temp;
    }
    rotatesquareleft(cube, 0);
    rotatesquareleft(cube, 1);
    rotatesquareleft(cube, 2);
    rotatesquareleft(cube, 4);
    rotatesquareleft(cube, 5);
    rotatesquareright(cube, 3);
    std::cout<<"zp ";
}

void M(int cube[6][9])
{
    int temp;
    for(int i=1; i<8; i=i+3)
    {
        temp = cube[0][i];
        cube[0][i] = cube[2][i];
        cube[2][i] = cube[1][i];
        cube[1][i] = cube[3][8-i];
        cube[3][8-i] = temp;
    }
    std::cout<<"M ";
}

void M2(int cube[6][9])
{
    int temp;
    for(int i=1; i<8; i=i+3)
    {
        temp = cube[0][i];
        cube[0][i] = cube[1][i];
        cube[1][i] = temp;
        temp = cube[3][8-i];
        cube[3][8-i] = cube[2][i];
        cube[2][i] = temp;
    }
    std::cout<<"M2 ";
}

void Mp(int cube[6][9])
{
    int temp;
    for(int i=1; i<8; i=i+3)
    {
        temp = cube[1][i];
        cube[1][i] = cube[2][i];
        cube[2][i] = cube[0][i];
        cube[0][i] = cube[3][8-i];
        cube[3][8-i] = temp;
    }
    std::cout<<"Mp ";
}

void E(int cube[6][9])
{
    int temp;
    for(int i=3; i<6; i++)
    {
        temp = cube[2][i];
        cube[2][i] = cube[5][i];
        cube[5][i] = cube[3][i];
        cube[3][i] = cube[4][i];
        cube[4][i] = temp;
    }
    std::cout<<"E ";
}

void E2(int cube[6][9])
{
    int temp;
    for(int i=3; i<6; i++)
    {
        temp = cube[2][i];
        cube[2][i] = cube[3][i];
        cube[3][i] = temp;
        temp = cube[4][i];
        cube[4][i] = cube[5][i];
        cube[5][i] = temp;
    }
    std::cout<<"E2 ";
}

void Ep(int cube[6][9])
{
    int temp;
    for(int i=3; i<6; i++)
    {
        temp = cube[2][i];
        cube[2][i] = cube[4][i];
        cube[4][i] = cube[3][i];
        cube[3][i] = cube[5][i];
        cube[5][i] = temp;
    }
    std::cout<<"Ep ";
}

void S(int cube[6][9])
{
    int temp;
    for(int i=0; i<3; i++)
    {
        temp = cube[1][i+3];
        cube[1][i+3] = cube[5][7-3*i];
        cube[5][7-3*i] = cube[0][5-i];
        cube[0][5-i] = cube[4][1+3*i];
        cube[4][1+3*i] = temp;
    }
    std::cout<<"S ";
}

void S2(int cube[6][9])
{
    int temp;
    for(int i=0; i<3; i++)
    {
        temp = cube[1][3+i];
        cube[1][3+i] = cube[0][5-i];
        cube[0][5-i] = temp;
        temp = cube[4][1+3*i];
        cube[4][1+3*i] = cube[5][7-3*i];
        cube[5][7-3*i] = temp;
    }
    std::cout<<"S2 ";
}

void Sp(int cube[6][9])
{
    int temp;
    for(int i=0; i<3; i++)
    {
        temp = cube[1][i+3];
        cube[1][i+3] = cube[4][1+3*i];
        cube[4][1+3*i] = cube[0][5-i];
        cube[0][5-i] = cube[5][7-3*i];
        cube[5][7-3*i] = temp;
    }
    std::cout<<"Sp ";
}

void U(int cube[6][9])
{
    int temp;
    for(int i=0; i<3; i++)
    {
        temp = cube[2][i];
        cube[2][i] = cube[4][i];
        cube[4][i] = cube[3][i];
        cube[3][i] = cube[5][i];
        cube[5][i] = temp;
    }
    rotatesquareright(cube, 1);
    std::cout<<"U ";
}

void U2(int cube[6][9])
{
    int temp;
    for(int i=0; i<3; i++)
    {
        temp = cube[2][i];
        cube[2][i] = cube[3][i];
        cube[3][i] = temp;
        temp = cube[4][i];
        cube[4][i] = cube[5][i];
        cube[5][i] = temp;
    }
    rotatesquare2(cube, 1);
    std::cout<<"U2 ";
}

void Up(int cube[6][9])
{
    int temp;
    for(int i=0; i<3; i++)
    {
        temp = cube[2][i];
        cube[2][i] = cube[5][i];
        cube[5][i] = cube[3][i];
        cube[3][i] = cube[4][i];
        cube[4][i] = temp;
    }
    rotatesquareleft(cube, 1);
    std::cout<<"Up ";
}

void D(int cube[6][9])
{
    int temp;
    for(int i=6; i<9; i++)
    {
        temp = cube[2][i];
        cube[2][i] = cube[5][i];
        cube[5][i] = cube[3][i];
        cube[3][i] = cube[4][i];
        cube[4][i] = temp;
    }
    rotatesquareright(cube, 0);
    std::cout<<"D ";
}

void D2(int cube[6][9])
{
    int temp;
    for(int i=6; i<9; i++)
    {
        temp = cube[2][i];
        cube[2][i] = cube[3][i];
        cube[3][i] = temp;
        temp = cube[4][i];
        cube[4][i] = cube[5][i];
        cube[5][i] = temp;
    }
    rotatesquare2(cube, 0);
    std::cout<<"D2 ";
}

void Dp(int cube[6][9])
{
    int temp;
    for(int i=6; i<9; i++)
    {
        temp = cube[2][i];
        cube[2][i] = cube[4][i];
        cube[4][i] = cube[3][i];
        cube[3][i] = cube[5][i];
        cube[5][i] = temp;
    }
    rotatesquareleft(cube, 0);
    std::cout<<"Dp ";
}

void F(int cube[6][9])
{
    int temp;
    for(int i=0; i<3; i++)
    {
        temp = cube[1][6+i];
        cube[1][6+i] = cube[5][2+(2-i)*3];
        cube[5][2+(2-i)*3] = cube[0][2-i];
        cube[0][2-i] = cube[4][3*i];
        cube[4][3*i] = temp;
    }
    rotatesquareright(cube, 2);
    std::cout<<"F ";
}

void F2(int cube[6][9])
{
    int temp;
    for(int i=0; i<3; i++)
    {
        temp = cube[0][i];
        cube[0][i] = cube[1][8-i];
        cube[1][8-i] = temp;
        temp = cube[4][3*i];
        cube[4][3*i] = cube[5][8-3*i];
        cube[5][8-3*i] = temp;
    }
    rotatesquare2(cube, 2);
    std::cout<<"F2 ";
}

void Fp(int cube[6][9])
{
    int temp;
    for(int i=0; i<3; i++)
    {
        temp = cube[1][6+i];
        cube[1][6+i] = cube[4][3*i];
        cube[4][3*i] = cube[0][2-i];
        cube[0][2-i] = cube[5][2+(2-i)*3];
        cube[5][2+(2-i)*3] = temp;
    }
    rotatesquareleft(cube, 2);
    std::cout<<"Fp ";
}

void B(int cube[6][9])
{
    int temp;
    for(int i=0; i<3; i++)
    {
        temp = cube[1][2-i];
        cube[1][2-i] = cube[4][2+(2-i)*3];
        cube[4][2+(2-i)*3] = cube[0][6+i];
        cube[0][6+i] = cube[5][i*3];
        cube[5][i*3] = temp;

    }
    rotatesquareright(cube, 3);
    std::cout<<"B ";
}

void B2(int cube[6][9])
{
    int temp;
    for(int i=0; i<3; i++)
    {
        temp = cube[1][2-i];
        cube[1][2-i] = cube[0][6+i];
        cube[0][6+i] = temp;
        temp = cube[4][2+3*i];
        cube[4][2+3*i] = cube[5][6-3*i];
        cube[5][6-3*i] = temp;
    }
    rotatesquare2(cube, 3);
    std::cout<<"B2 ";
}

void Bp(int cube[6][9])
{
    int temp;
    for(int i=0; i<3; i++)
    {
        temp = cube[1][2-i];
        cube[1][2-i] = cube[5][3*i];
        cube[5][3*i] = cube[0][6+i];
        cube[0][6+i] = cube[4][8-3*i];
        cube[4][8-3*i] = temp;
    }
    rotatesquareleft(cube, 3);
    std::cout<<"Bp ";
}

void R(int cube[6][9])
{
    int temp;
    for(int i=2; i<9; i=i+3)
    {
        temp = cube[1][i];
        cube[1][i] = cube[2][i];
        cube[2][i] = cube[0][i];
        cube[0][i] = cube[3][8-i];
        cube[3][8-i] = temp;
    }
    rotatesquareright(cube, 4);
    std::cout<<"R ";
}

void R2(int cube[6][9])
{
    int temp;
    for(int i=2; i<9; i=i+3)
    {
        temp = cube[1][i];
        cube[1][i] = cube[0][i];
        cube[0][i] = temp;
        temp = cube[2][i];
        cube[2][i] = cube[3][8-i];
        cube[3][8-i] = temp;
    }
    rotatesquare2(cube, 4);
    std::cout<<"R2 ";
}

void Rp(int cube[6][9])
{
    int temp;
    for(int i=2; i<9; i=i+3)
    {
        temp = cube[0][i];
        cube[0][i] = cube[2][i];
        cube[2][i] = cube[1][i];
        cube[1][i] = cube[3][8-i];
        cube[3][8-i] = temp;
    }
    rotatesquareleft(cube, 4);
    std::cout<<"Rp ";
}

void L(int cube[6][9])
{
    int temp;
    for(int i=0; i<7; i=i+3)
    {
        temp = cube[0][i];
        cube[0][i] = cube[2][i];
        cube[2][i] = cube[1][i];
        cube[1][i] = cube[3][8-i];
        cube[3][8-i] = temp;
    }
    rotatesquareright(cube, 5);
    std::cout<<"L ";
}

void L2(int cube[6][9])
{
    int temp;
    for(int i=0; i<7; i=i+3)
    {
        temp = cube[1][i];
        cube[1][i] = cube[0][i];
        cube[0][i] = temp;
        temp = cube[2][i];
        cube[2][i] = cube[3][8-i];
        cube[3][8-i] = temp;
    }
    rotatesquare2(cube, 5);
    std::cout<<"L2 ";
}

void Lp(int cube[6][9])
{
    int temp;
    for(int i=0; i<7; i=i+3)
    {
        temp = cube[1][i];
        cube[1][i] = cube[2][i];
        cube[2][i] = cube[0][i];
        cube[0][i] = cube[3][8-i];
        cube[3][8-i] = temp;
    }
    rotatesquareleft(cube, 5);
    std::cout<<"Lp ";
}

void Uw(int cube[6][9])
{
    Ep(cube);
    U(cube);
    std::cout<<"Uw ";
}

void Uw2(int cube[6][9])
{
    E2(cube);
    U2(cube);
    std::cout<<"Uw2 ";
}

void Uwp(int cube[6][9])
{
    E(cube);
    Up(cube);
    std::cout<<"Uwp ";
}

void Dw(int cube[6][9])
{
    E(cube);
    D(cube);
    std::cout<<"Dw ";
}

void Dw2(int cube[6][9])
{
    E2(cube);
    D2(cube);
    std::cout<<"Dw2 ";
}

void Dwp(int cube[6][9])
{
    Ep(cube);
    Dp(cube);
    std::cout<<"Dwp ";
}

void Rw(int cube[6][9])
{
    Mp(cube);
    R(cube);
    std::cout<<"Rw ";
}

void Rw2(int cube[6][9])
{
    M2(cube);
    R2(cube);
    std::cout<<"Rw2 ";
}

void Rwp(int cube[6][9])
{
    M(cube);
    Rp(cube);
    std::cout<<"Rwp ";
}

void Lw(int cube[6][9])
{
    M(cube);
    L(cube);
    std::cout<<"Lw ";
}

void Lw2(int cube[6][9])
{
    M2(cube);
    L2(cube);
    std::cout<<"Lw2 ";
}

void Lwp(int cube[6][9])
{
    Mp(cube);
    Lp(cube);
    std::cout<<"Lwp ";
}

void Fw(int cube[6][9])
{
    S(cube);
    F(cube);
    std::cout<<"Fw ";
}

void Fw2(int cube[6][9])
{
    S2(cube);
    F2(cube);
    std::cout<<"Fw2 ";
}

void Fwp(int cube[6][9])
{
    Sp(cube);
    Fp(cube);
    std::cout<<"Fwp ";
}

void Bw(int cube[6][9])
{
    Sp(cube);
    B(cube);
    std::cout<<"Bw ";
}

void Bw2(int cube[6][9])
{
    S2(cube);
    B2(cube);
    std::cout<<"Bw2 ";
}

void Bwp(int cube[6][9])
{
    S(cube);
    Bp(cube);
    std::cout<<"Bwp ";
}

void scrambler(int cube[6][9])
{
    std::cout<<"Mieszanie:"<<std::endl;
    srand(time(0));
    int i, n;
    while (true)
    {
        i = rand()%100;
        if (i>12 && i<25) break;        
    }
    i--;
    while (i>=0)
    {
        n = rand()%100;
        if (n<18)
        {
            if (n == 0) U(cube);
            else if (n == 1) Up(cube);
            else if (n == 2) U2(cube);
            else if (n == 3) D(cube);
            else if (n == 4) Dp(cube);
            else if (n == 5) D2(cube);
            else if (n == 6) F(cube);
            else if (n == 7) Fp(cube);
            else if (n == 8) F2(cube);
            else if (n == 9) B(cube);
            else if (n == 10) Bp(cube);
            else if (n == 11) B2(cube);
            else if (n == 12) R(cube);
            else if (n == 13) Rp(cube);
            else if (n == 14) R2(cube);
            else if (n == 15) L(cube);
            else if (n == 16) Lp(cube);
            else if (n == 17) L2(cube);
            i--;
        }
    }
   	std::cout<<std::endl<<std::endl<<std::endl;
}

void WhiteCentreDown(int cube[6][9])                //if cube[0][4] != 14 WhiteCentreDown(cube);
{
    if(cube[1][4] == 14)
    {
        x2(cube);
    }
    else if(cube[2][4] == 14)
    {
        xp(cube);
    }
    else if(cube[3][4] == 14)
    {
        x(cube);
    }
    else if(cube[4][4] == 14)
    {
        z(cube);
    }
    else if(cube[5][4] == 14)
    {
        zp(cube);
    }
}

void WhiteCross(int cube[6][9])
{
    while(true) //if white cross is not solved
    {
        if(cube[2][7]/10 != cube[2][4]/10 || cube[2][7]%10 != 7) 
        //if current front colour's white cross element is wrong; else turn cube
        //wrong element - can't look at down element, must check current layer element 
        {
            int searched_colour = cube[2][4]/10;
            if (cube[0][1]/10 == searched_colour && cube[0][1]%10 == 7)  //search for that element. Searching based on front element
            {
                D(cube);
                R(cube);
                Dp(cube);
                F(cube);
            }
            else if (cube[0][5]/10 == searched_colour && cube[0][5]%10 == 7)
            {
                R(cube);
                F(cube);
            }
            else if (cube[0][7]/10 == searched_colour && cube[0][7]%10 == 7)
            {
                Dp(cube);
                R(cube);
                D(cube);
                F(cube);
            }
            else if (cube[0][3]/10 == searched_colour && cube[0][3]%10 == 7)
            {
                Lp(cube);
                Fp(cube);
            }

            else if (cube[1][1]/10 == searched_colour && cube[1][1]%10 == 7)
            {
                U(cube);
                Rp(cube);
                F(cube);
                R(cube);
            }
            else if (cube[1][3]/10 == searched_colour && cube[1][3]%10 == 7)
            {
                L(cube);
                Fp(cube);
                Lp(cube);
            }
            else if (cube[1][5]/10 == searched_colour && cube[1][5]%10 == 7)
            {
                Rp(cube);
                F(cube);
                R(cube);
            }
            else if (cube[1][7]/10 == searched_colour && cube[1][7]%10 == 7)
            {
                Up(cube);
                Rp(cube);
                F(cube);
                R(cube);
            }

            else if (cube[2][1]/10 == searched_colour && cube[2][1]%10 == 7)
            {
                F2(cube);
            }
            else if (cube[2][3]/10 == searched_colour && cube[2][3]%10 == 7)
            {
                Fp(cube);
            }
            else if (cube[2][5]/10 == searched_colour && cube[2][5]%10 == 7)
            {
                F(cube);
            }

            else if (cube[3][1]/10 == searched_colour && cube[3][1]%10 == 7)
            {
                U2(cube);
                F2(cube);
            }
            else if (cube[3][3]/10 == searched_colour && cube[3][3]%10 == 7)
            {
                R2(cube);
                F(cube);
                R2(cube);
            }
            else if (cube[3][5]/10 == searched_colour && cube[3][5]%10 == 7)
            {
                L2(cube);
                Fp(cube);
                L2(cube);
            }
            else if (cube[3][7]/10 == searched_colour && cube[3][7]%10 == 7)
            {
                D2(cube);
                Fp(cube);
                D2(cube);
                F(cube);
            }

            else if (cube[4][1]/10 == searched_colour && cube[4][1]%10 == 7)
            {
                U(cube);
                F2(cube);
            }
            else if (cube[4][3]/10 == searched_colour && cube[4][3]%10 == 7)
            {
                D(cube);
                Rp(cube);
                Dp(cube);
            }
            else if (cube[4][5]/10 == searched_colour && cube[4][5]%10 == 7)
            {
                D(cube);
                R(cube);
                Dp(cube);
            }
            else if (cube[4][7]/10 == searched_colour && cube[4][7]%10 == 7)
            {
                Dp(cube);
                Fp(cube);
                D(cube);
                F(cube);
            }

            else if (cube[5][1]/10 == searched_colour && cube[5][1]%10 == 7)
            {
                Up(cube);
                F2(cube);
            }
            else if (cube[5][3]/10 == searched_colour && cube[5][3]%10 == 7)
            {
                Dp(cube);
                Lp(cube);
                D(cube);
            }
            else if (cube[5][5]/10 == searched_colour && cube[5][5]%10 == 7)
            {
                Dp(cube);
                L(cube);
                D(cube);
            }
            else if (cube[5][7]/10 == searched_colour && cube[5][7]%10 == 7)
            {
                D(cube);
                Fp(cube);
                Dp(cube);
                F(cube);
            }
            //else {std::cout<<std::endl<<"Kurza twarz. Front to"<<cube[2][4]<<", dol to "<<cube[0][4]<<".\t"<<cube[0][1]/10<<cube[3][1]/10<<cube[0][5]/10<<cube[0][7]/10<<std::endl;}
        }
        if (cube[0][1]/10 == 1 && cube[0][3]/10 == 1 && cube[0][5]/10 == 1 && cube[0][7]/10 == 1 && cube[2][7]/10 == cube[2][4]/10 && cube[3][7]/10 == cube[3][4]/10 && cube[4][7]/10 == cube[4][4]/10 && cube[5][7]/10 == cube[5][4]/10) break;
        y(cube);
        std::cout<<std::endl;
    }
}

void WhiteEdges(int cube[6][9])
{
    while(true)
    {
        int searched_colour = cube[2][4]/10;
        if(cube[2][8]/10 != searched_colour || cube[2][8]%10 != 8)
        {
            if (cube[0][0]/10 == searched_colour && cube[0][0]%10 == 8)
            {
                F(cube);
                U(cube);
                Fp(cube);
                U2(cube);
                R(cube);
                U(cube);
                Rp(cube);
            }
            else if (cube[0][2]/10 == searched_colour && cube[0][2]%10 == 8)
            {
                R(cube);
                U(cube);
                Rp(cube);
                Up(cube);
                R(cube);
                U(cube);
                Rp(cube);
            }
            else if (cube[0][6]/10 == searched_colour && cube[0][6]%10 == 8)
            {
                L(cube);
                U(cube);
                Lp(cube);
                U(cube);
                R(cube);
                U(cube);
                Rp(cube);
            }
            else if (cube[0][8]/10 == searched_colour && cube[0][8]%10 == 8)
            {
                S(cube);
                R(cube);
                Sp(cube);
            }

            else if (cube[1][0]/10 == searched_colour && cube[1][0]%10 == 8)
            {
                R(cube);
                U2(cube);
                Rp(cube);
            }
            else if (cube[1][2]/10 == searched_colour && cube[1][2]%10 == 8)
            {
                U(cube);
                Fp(cube);
                Up(cube);
                F(cube);
            }
            else if (cube[1][6]/10 == searched_colour && cube[1][6]%10 == 8)
            {
                R(cube);
                Up(cube);
                Rp(cube);
            }
            else if (cube[1][8]/10 == searched_colour && cube[1][8]%10 == 8)
            {
                Fp(cube);
                Up(cube);
                F(cube);
            }

            else if (cube[2][0]/10 == searched_colour && cube[2][0]%10 == 8)
            {
                Up(cube);
                R(cube);
                U2(cube);
                Rp(cube);
                Up(cube);
                R(cube);
                U(cube);
                Rp(cube);
            }
            else if (cube[2][2]/10 == searched_colour && cube[2][2]%10 == 8)
            {
                R(cube);
                U(cube);
                Rp(cube);
            }
            else if (cube[2][6]/10 == searched_colour && cube[2][6]%10 == 8)
            {
                M(cube);
                Fp(cube);
                Mp(cube);
            }

            else if (cube[3][0]/10 == searched_colour && cube[3][0]%10 == 8)
            {
                U(cube);
                R(cube);
                U2(cube);
                Rp(cube);
                Up(cube);
                R(cube);
                U(cube);
                Rp(cube);
            }
            else if (cube[3][2]/10 == searched_colour && cube[3][2]%10 == 8)
            {
                U2(cube);
                R(cube);
                U(cube);
                Rp(cube);
            }
            else if (cube[3][6]/10 == searched_colour && cube[3][6]%10 == 8)
            {
                Rp(cube);
                U2(cube);
                R2(cube);
                Up(cube);
                Rp(cube);
            }
            else if (cube[3][8]/10 == searched_colour && cube[3][8]%10 == 8)
            {
                L(cube);
                Up(cube);
                Lp(cube);
                Fp(cube);
                U2(cube);
                F(cube);
            }

            else if (cube[4][0]/10 == searched_colour && cube[4][0]%10 == 8)
            {
                R(cube);
                U2(cube);
                Rp(cube);
                Up(cube);
                R(cube);
                U(cube);
                Rp(cube);
            }
            else if (cube[4][2]/10 == searched_colour && cube[4][2]%10 == 8)
            {
                Fp(cube);
                U(cube);
                F(cube);
            }
            else if (cube[4][6]/10 == searched_colour && cube[4][6]%10 == 8)
            {
                Fp(cube);
                Up(cube);
                F(cube);
                U2(cube);
                R(cube);
                Up(cube);
                Rp(cube);
            }
            else if (cube[4][8]/10 == searched_colour && cube[4][8]%10 == 8)
            {
                B(cube);
                U2(cube);
                Bp(cube);
                R(cube);
                Up(cube);
                Rp(cube);           
            }

            else if (cube[5][0]/10 == searched_colour && cube[5][0]%10 == 8)
            {
                U2(cube);
                R(cube);
                U2(cube);
                Rp(cube);
                Up(cube);
                R(cube);
                U(cube);
                Rp(cube);
            }
            else if (cube[5][2]/10 == searched_colour && cube[5][2]%10 == 8)
            {
                Up(cube);
                R(cube);
                U(cube);
                Rp(cube);
            }
            else if (cube[5][6]/10 == searched_colour && cube[5][6]%10 == 8)
            {
                Bp(cube);
                U2(cube);
                B(cube);
                Fp(cube);
                Up(cube);
                F(cube);
            }
            else if (cube[5][8]/10 == searched_colour && cube[5][8]%10 == 8)
            {
                Lp(cube);
                Up(cube);
                L(cube);
                R(cube);
                U(cube);
                Rp(cube);
            }
        }
        if (cube[0][0]/10 == 1 && cube[0][2]/10 == 1 && cube[0][6]/10 == 1 && cube[0][8]/10 == 1 && cube[2][6]/10 == cube[2][4]/10 && cube[2][8]/10 == cube[2][4]/10 && cube[3][6]/10 == cube[3][4]/10 && cube[3][8]/10 == cube[3][4]/10) break;
        y(cube);
        std::cout<<std::endl;
    }
}

void CentreGoesRight(int cube[6][9])        //inserted piece is in cube[2][1] 
{
    U(cube);
    R(cube);
    Up(cube);
    Rp(cube);
    Up(cube);
    Fp(cube);
    U(cube);
    F(cube);
}

void CentreGoesLeft(int cube[6][9])         //inserted piece in cube[4][1]
{
    Rp(cube);
    Fp(cube);
    R(cube);
    U(cube);
    R(cube);
    Up(cube);
    Rp(cube);
    F(cube);
}

bool LayerTwoIsAlright(int cube[6][9])
{
    if (   cube[2][3]/10 == cube[2][4]/10 && cube[2][5]/10 == cube[2][4]/10 
        && cube[3][3]/10 == cube[3][4]/10 && cube[3][5]/10 == cube[3][4]/10 
        && cube[4][3]/10 == cube[4][4]/10 && cube[4][5]/10 == cube[4][4]/10 
        && cube[5][3]/10 == cube[5][4]/10 && cube[5][5]/10 == cube[5][4]/10)
        return true;
    return false;
}

void TwoLayers(int cube[6][9])
{
    while (true)
    {
        if (cube[1][1]/10 == cube[2][4]/10 && cube[3][1]/10 == cube[4][4]/10)
        {
            U(cube);
            CentreGoesLeft(cube);
        }
        else if (cube[1][3]/10 == cube[2][4]/10 && cube[5][1]/10 == cube[4][4]/10)
        {
            U2(cube);
            CentreGoesLeft(cube);
        }
        else if (cube[1][5]/10 == cube[2][4]/10 && cube[4][1]/10 == cube[4][4]/10)
        {
            CentreGoesLeft(cube);
        }
        else if (cube[1][7]/10 == cube[2][4]/10 && cube[2][1]/10 == cube[4][4]/10)
        {
            Up(cube);
            CentreGoesLeft(cube);
        }
        
        else if (cube[2][1]/10 == cube[2][4]/10 && cube[1][7]/10 == cube[4][4]/10)
        {
            CentreGoesRight(cube);
        }
        else if (cube[2][3]/10 == cube[2][4]/10 && cube[5][5]/10 == cube[4][4]/10)
        {
            yp(cube);
            CentreGoesRight(cube);
            U(cube);
            y(cube);
            CentreGoesRight(cube);
        }

        else if (cube[3][1]/10 == cube[2][4]/10 && cube[1][1]/10 == cube[4][4]/10)
        {
            U2(cube);
            CentreGoesRight(cube);
        }
        else if (cube[3][3]/10 == cube[2][4]/10 && cube[4][5]/10 == cube[4][4]/10)
        {
            y(cube);
            CentreGoesRight(cube);
            yp(cube);
            Up(cube);
            CentreGoesRight(cube);
        }
        else if (cube[3][5]/10 == cube[2][4]/10 && cube[5][3]/10 == cube[4][4]/10)
        {
            y2(cube);
            CentreGoesRight(cube);
            y2(cube);
            Up(cube);
            CentreGoesLeft(cube);
        }

        else if (cube[4][1]/10 == cube[2][4]/10 && cube[1][5]/10 == cube[4][4]/10)
        {
            U(cube);
            CentreGoesRight(cube);
        }
        else if (cube[4][3]/10 == cube[2][4]/10 && cube[2][5]/10 == cube[4][4]/10)
        {
            CentreGoesRight(cube);
            U2(cube);
            CentreGoesRight(cube);
        }
        else if (cube[4][5]/10 == cube[2][4]/10 && cube[3][3]/10 == cube[4][4]/10)
        {
            y(cube);
            CentreGoesRight(cube);
            yp(cube);
            U2(cube);
            CentreGoesLeft(cube);
        }

        else if (cube[5][1]/10 == cube[2][4]/10 && cube[1][3]/10 == cube[4][4]/10)
        {
            Up(cube);
            CentreGoesRight(cube);
        }
        else if (cube[5][3]/10 == cube[2][4]/10 && cube[3][5]/10 == cube[4][4]/10)
        {
            y2(cube);
            CentreGoesRight(cube);
            y2(cube);
            CentreGoesRight(cube);
        }
        else if (cube[5][5]/10 == cube[2][4]/10 && cube[2][3]/10 == cube[4][4]/10)
        {
            yp(cube);
            CentreGoesRight(cube);
            Up(cube);
            CentreGoesLeft(cube);
            y(cube);
        }
    
        if (LayerTwoIsAlright(cube)) break;
        y(cube);
        std::cout<<std::endl;
    }
}

void YellowCrossOp1(int cube[6][9])
{
    F(cube);
    R(cube);
    U(cube);
    Rp(cube);
    Up(cube);
    Fp(cube);
}

void YellowCrossOp2(int cube[6][9])
{
    F(cube);
    R(cube);
    U(cube);
    Rp(cube);
    Up(cube);
    R(cube);
    U(cube);
    Rp(cube);
    Up(cube);
    Fp(cube);
}

void YellowCross(int cube[6][9])
{
    int toplayercolour = cube[1][4]/10;

    if (cube[1][1]/10 == toplayercolour 
        && cube[1][3]/10 == toplayercolour 
        && cube[1][5]/10 == toplayercolour 
        && cube[1][7]/10 == toplayercolour);

    else if (cube[1][1]/10 == toplayercolour && cube[1][5]/10 == toplayercolour)
    {
        yp(cube);
        YellowCrossOp2(cube);
    }
    else if (cube[1][1]/10 == toplayercolour && cube[1][3]/10 == toplayercolour)
    {
        YellowCrossOp2(cube);
    }
    else if (cube[1][5]/10 == toplayercolour && cube[1][7]/10 == toplayercolour)
    {
        U2(cube);
        YellowCrossOp2(cube);
    }
    else if (cube[1][3]/10 == toplayercolour && cube[1][7]/10 == toplayercolour)
    {
        y(cube);
        YellowCrossOp2(cube);
    }


    else if (cube[1][3]/10 == toplayercolour && cube[1][5]/10 == toplayercolour)
    {
        YellowCrossOp1(cube);
    }
    else if (cube[1][1]/10 == toplayercolour && cube[1][7]/10 == toplayercolour)
    {
        yp(cube);
        YellowCrossOp1(cube);
    }

    else 
    {
        YellowCrossOp2(cube);
        yp(cube);
        YellowCrossOp1(cube);
    }
}

void YellowCentresPlacementOp(int cube[6][9])
{
    Up(cube);
    R(cube);
    U2(cube);
    Rp(cube);
    Up(cube);
    R(cube);
    Up(cube);
    Rp(cube);
}

bool YellowCrossColoursAreAlignedWithEachOther(int cube[6][9])
{
    if  ((cube[2][1]/10 == 3 && cube[5][1]/10 == 6 && cube[3][1]/10 == 4 && cube[4][1]/10 == 5)
        || (cube[2][1]/10 == 5 && cube[5][1]/10 == 3 && cube[3][1]/10 == 6 && cube[4][1]/10 == 4)
        || (cube[2][1]/10 == 4 && cube[5][1]/10 == 5 && cube[3][1]/10 == 3 && cube[4][1]/10 == 6)
        || (cube[2][1]/10 == 6 && cube[5][1]/10 == 4 && cube[3][1]/10 == 5 && cube[4][1]/10 == 3))
        {
            return true;
        }
    return false;
}

void YellowCentresPlacement(int cube[6][9])
{  
    if (YellowCrossColoursAreAlignedWithEachOther(cube))
    {
        if (cube[2][1]/10 == cube[4][4]/10) Up(cube);
        else if (cube[2][1]/10 == cube[3][4]/10) U2(cube);
        else if (cube[2][1]/10 == cube[5][4]/10) U(cube);
    }
    else if (cube[2][1]/10 == cube[2][4]/10 && cube[4][1]/10 == cube[4][4]/10)
    {
        yp(cube);
        YellowCentresPlacementOp(cube);
    }
    else if (cube[2][1]/10 == cube[5][4]/10 && cube[4][1]/10 == cube[2][4]/10)
    {
        y2(cube);
        U(cube);
        YellowCentresPlacementOp(cube);
    }
    else if (cube[2][1]/10 == cube[3][4]/10 && cube[4][1]/10 == cube[5][4]/10)
    {
        y(cube);
        U2(cube);
        YellowCentresPlacementOp(cube);
    }
    else if (cube[2][1]/10 == cube[4][4]/10 && cube[4][1]/10 == cube[3][4]/10)
    {
        Up(cube);
        YellowCentresPlacementOp(cube);
    }

    else if (cube[2][1]/10 == cube[2][4]/10 && cube[5][1]/10 == cube[5][4]/10)
    {
        y2(cube);
        YellowCentresPlacementOp(cube);
    }
    else if (cube[2][1]/10 == cube[5][4]/10 && cube[5][1]/10 == cube[3][4]/10)
    {
        y(cube);
        U(cube);
        YellowCentresPlacementOp(cube);
    }
    else if (cube[2][1]/10 == cube[3][4]/10 && cube[5][1]/10 == cube[4][4]/10)
    {
        U2(cube);
        YellowCentresPlacementOp(cube);
    }
    else if (cube[2][1]/10 == cube[4][4]/10 && cube[5][1]/10 == cube[2][4]/10)
    {
        yp(cube);
        Up(cube);
        YellowCentresPlacementOp(cube);
    }

    else if (cube[3][1]/10 == cube[3][4]/10 && cube[4][1]/10 == cube[4][4]/10)
    {
        YellowCentresPlacementOp(cube);
    }
    else if (cube[3][1]/10 == cube[4][4]/10 && cube[4][1]/10 == cube[2][4]/10)
    {
        yp(cube);
        U(cube);
        YellowCentresPlacementOp(cube);
    }
    else if (cube[3][1]/10 == cube[2][4]/10 && cube[4][1]/10 == cube[5][4]/10)
    {
        y2(cube);
        U2(cube);
        YellowCentresPlacementOp(cube);
    }
    else if (cube[3][1]/10 == cube[5][4]/10 && cube[4][1]/10 == cube[3][4]/10)
    {
        y(cube);
        Up(cube);
        YellowCentresPlacementOp(cube);
    }

    else if (cube[5][1]/10 == cube[5][4]/10 && cube[3][1]/10 == cube[3][4]/10)
    {
        y(cube);
        YellowCentresPlacementOp(cube);
    }
    else if (cube[5][1]/10 == cube[3][4]/10 && cube[3][1]/10 == cube[4][4]/10)
    {
        U(cube);
        YellowCentresPlacementOp(cube);
    }
    else if (cube[5][1]/10 == cube[4][4]/10 && cube[3][1]/10 == cube[2][4]/10)
    {
        yp(cube);
        U2(cube);
        YellowCentresPlacementOp(cube);
    }
    else if (cube[5][1]/10 == cube[2][4]/10 && cube[3][1]/10 == cube[5][4]/10)
    {
        y2(cube);
        Up(cube);
        YellowCentresPlacementOp(cube);
    }

    else if (cube[4][1]/10 == cube[4][4]/10 && cube[5][1]/10 == cube[5][4]/10)
    {
        YellowCentresPlacementOp(cube);
        y(cube);
        U(cube);
        YellowCentresPlacementOp(cube);
    }
    else if (cube[4][1]/10 == cube[3][4]/10 && cube[5][1]/10 == cube[2][4]/10)
    {
        y(cube);
        Up(cube);
        YellowCentresPlacementOp(cube);
        y(cube);
        U(cube);
        YellowCentresPlacementOp(cube);
    }
    else if (cube[4][1]/10 == cube[5][4]/10 && cube[5][1]/10 == cube[4][4]/10)
    {
        U2(cube);
        YellowCentresPlacementOp(cube);
        y(cube);
        U(cube);
        YellowCentresPlacementOp(cube);
    }
    else if (cube[4][1]/10 == cube[2][4]/10 && cube[5][1]/10 == cube[3][4]/10)
    {
        yp(cube);
        U(cube);
        YellowCentresPlacementOp(cube);
        y(cube);
        U(cube);
        YellowCentresPlacementOp(cube);
    }

    else if (cube[2][1]/10 == cube[2][4]/10 && cube[3][1]/10 == cube[3][4]/10)
    {
        y(cube);
        YellowCentresPlacementOp(cube);
        y(cube);
        U(cube);
        YellowCentresPlacementOp(cube);
    }
    else if (cube[2][1]/10 == cube[4][4]/10 && cube[3][1]/10 == cube[5][4]/10)
    {
        Up(cube);
        YellowCentresPlacementOp(cube);
        y(cube);
        U(cube);
        YellowCentresPlacementOp(cube);
    }
    else if (cube[2][1]/10 == cube[3][4]/10 && cube[3][1]/10 == cube[2][4]/10)
    {
        y(cube);
        U2(cube);
        YellowCentresPlacementOp(cube);
        y(cube);
        U(cube);
        YellowCentresPlacementOp(cube);
    }
    else if (cube[2][1]/10 == cube[5][4]/10 && cube[3][1]/10 == cube[4][4]/10)
    {
        y(cube);
        U(cube);
        YellowCentresPlacementOp(cube);
        y(cube);
        U(cube);
        YellowCentresPlacementOp(cube);
    }
}

void YellowEdgesPlacementOp(int cube[6][9])
{
    U(cube);
    R(cube);
    Up(cube);
    Lp(cube);
    U(cube);
    Rp(cube);
    Up(cube);
    L(cube);
}

bool IsEdgeInRightPlace(int cube[6][9], int leftlayerindex, int rightlayerindex) //looking from upper perspective
{
    int yellow = cube[1][4]/10;
    int rcolour = cube[rightlayerindex][4]/10;
    int lcolour = cube[leftlayerindex][4]/10;
    if ((cube[leftlayerindex][0]/10 == yellow && cube[rightlayerindex][2]/10 == lcolour) 
        || (cube[leftlayerindex][0]/10 == rcolour && cube[rightlayerindex][2]/10 == yellow) 
        || (cube[leftlayerindex][0]/10 == lcolour && cube[rightlayerindex][2]/10 == rcolour))
    {
        return true;
    }
    return false;
}

void YellowEdgesPlacement(int cube[6][9])
{
    while (true)
    {
        if (IsEdgeInRightPlace(cube, 2, 5))
        {
            if (IsEdgeInRightPlace(cube, 5, 3)) break;
            yp(cube);
        }
        else if (IsEdgeInRightPlace(cube, 5, 3)) y2(cube);
        else if (IsEdgeInRightPlace(cube, 3, 4)) y(cube);
        YellowEdgesPlacementOp(cube);
    }
}

void YellowEdgesRotation(int cube[6][9])
{
    int yellow = cube[0][4]/10;
    while (cube[0][0]/10 != yellow || cube[0][2]/10 != yellow || cube[0][6]/10 != yellow || cube[0][8]/10 != yellow)
    {
        while (cube[0][2]/10 != yellow)
        {
            R(cube);
            U(cube);
            Rp(cube);
            Up(cube);
        }
        Dp(cube);
        std::cout<<std::endl;
    }

    if (cube[5][7]/10 == cube[2][4]/10) D(cube);
    else if (cube[3][7]/10 == cube[2][4]/10) D2(cube);
    else if (cube[4][7]/10 == cube[2][4]/10) Dp(cube);
}

void GreenFrontWhiteDown(int cube[6][9])
{
    if (cube[0][4]/10 == 3) x(cube); 
    else if (cube[1][4]/10 == 3) xp(cube);
    else if (cube[3][4]/10 == 3) x2(cube);
    else if (cube[4][4]/10 == 3) y(cube);
    else if (cube[5][4]/10 == 3) yp(cube);

    if (cube[1][4]/10 == 1) z2(cube);
    else if (cube[4][4]/10 == 1) z(cube);
    else if (cube[5][4]/10 == 1) zp(cube);
}

void intcube(int cube[6][9])
{
    char temp;
    char colours[] = {'W', 'Y', 'G', 'B', 'O', 'R'};
    for(int i=0; i<=5; i++)
    {
        for(int j=0; j<=8; j++) 
        {
            std::cout<<"Cube["<<i<<"]["<<j<<"]:\t";
            std::cin>>temp;
            temp = toupper(temp);
            for(int k=0; k<=5; k++)
            {
                if(temp == colours[k]) cube[i][j] = (cube[i][j]/10)*10 + k + 1;
            }
            std::cout<<std::endl;
        }
        printcube(cube);
    }
}

void intcubeonestring(int cube[6][9])
{
	std::string seq;
	std::cin>>seq;
	//seq = toupper(seq);
	std::string colours[6] = {"W", "Y", "G", "B", "O", "R"};
	short int stringiter = 0;
	
	if(seq.length() != 54) exit;
	
	for(short i=0; i<=5; i++)
	{
		for(short j=0; j<=8; j++)
		{
			for(int k=0; k<=5; k++)
           	{
               	//if(seq[stringiter] == colours[k]) cube[i][j] = (cube[i][j]/10)*10 + k + 1;
               	//stringiter++;
           	}
		}
	}
}

void solve(int cube[6][9])
{
    WhiteCentreDown(cube);
    WhiteCross(cube);
    std::cout<<"\n\n\n";
    WhiteEdges(cube);
    std::cout<<"\n\n\n";
    TwoLayers(cube);
    std::cout<<"\n\n\n";
    YellowCross(cube);
    std::cout<<"\n\n\n";
    YellowCentresPlacement(cube);
    std::cout<<"\n\n\n";
    YellowEdgesPlacement(cube);
    std::cout<<"\n\n\n";
    z2(cube);
    std::cout<<"\n\n\n";
    YellowEdgesRotation(cube);
    std::cout<<"\n\n\n";
    z2(cube);
    std::cout<<"\n\n\n";
    GreenFrontWhiteDown(cube);
}

int main()
{
    int cube[6][9];
    resetcube(cube);
    intcubeonestring(cube);
    printcube(cube);
    //scrambler(cube);
    solve(cube);
    std::cout<<"\n\n\n"; 
    printcolourscube(cube);
    printcube(cube);
	return 0;
}
