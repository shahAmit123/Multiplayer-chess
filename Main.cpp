#include<iostream>
using namespace std;
char ar[9][9];
bool quality=true;
int score1=0,score2=0;
bool pos[9][9];
void draw();
void setup();
void design();
void kill_benifit(int x, int y);
void kill_benifitw(int x, int y);
void kill_chance_pown(char *x)
{
    if(*x=='P'){
        *x='1';
    }
    else if(*x=='Q')
    {
        *x='9';
    }
    else if(*x=='K')
    {
        *x='W';
    }
    else if(*x=='B')
    {
        *x='3';
    }
    else if(*x=='H')
    {
        *x='4';
    }
    else if(*x=='R')
    {
        *x='5';
    }
}
void kill_chance_pownw(char *x)
{
    if(*x=='p'){
        *x='1';
    }
    else if(*x=='q')
    {
        *x='9';
    }
    else if(*x=='k')
    {
        *x='w';
    }
    else if(*x=='b')
    {
        *x='3';
    }
    else if(*x=='h')
    {
        *x='4';
    }
    else if(*x=='r')
    {
        *x='5';
    }
}
bool is_possible_pown(char x)
{
    if(x=='.'||x=='P'||x=='R'||x=='Q'||x=='B'||x=='K'||x=='H'||x=='1'||x=='3'||x=='4'||x=='5'||x=='9'||x=='W')
    {
        return true;
    }
    else {
        return false;
    }
}
bool is_possible_pownw(char x)
{
    if(x=='.'||x=='p'||x=='r'||x=='q'||x=='b'||x=='k'||x=='h'||x=='1'||x=='3'||x=='4'||x=='5'||x=='9'||x=='w')
    {
        return true;
    }
    else {
        return false;
    }
}
void kill_chancehw(char *x)  //after selecting horse this function set it's possition's values 
{
    if(*x==' ')
    {
        *x='.';
    }
    else if(*x=='p')
    {
        *x='1';
    }
    else if(*x=='b')
    {
        *x='3';
    }
    else if(*x=='h')
    {
        *x='4';
    }
    else if(*x=='r')
    {
        *x='5';
    }
    else if(*x=='q')
    {
        *x='9';
    }
    else if(*x=='k')
    {
        *x='w';
    }
}
bool is_possiblehw(char x)  //this function give which possition horse can move 
{
    if(x==' '||x=='p'||x=='r'||x=='b'||x=='h'||x=='q'||x=='k')
    {
        return true;
    }
    else 
    {
        return false;
    }
}
void kill_chancew(char* x) //this function set values for moving position
{
    if(*x=='p')
    {
        *x='1';
    }
    else if(*x=='b')
    {
        *x='3';
    }
    else if(*x=='h')
    {
        *x='4';
    }
    else if(*x=='r')
    {
        *x='5';
    }
    else if(*x=='q')
    {
        *x='9';
    }
    else if(*x=='k')
    {
        *x='w';
    }
}
bool is_possiblew(char x) //this function give true for movable position
{
    if(x=='.'||x=='1'||x=='3'||x=='4'||x=='5'||x=='9'||x=='w')
    {
        return true;
    }
    else 
    {
        return false;
    }
}
void kill_chanceh(char *x)  //after selecting horse this function set it's possition's values 
{
    if(*x==' ')
    {
        *x='.';
    }
    else if(*x=='P')
    {
        *x='1';
    }
    else if(*x=='B')
    {
        *x='3';
    }
    else if(*x=='H')
    {
        *x='4';
    }
    else if(*x=='R')
    {
        *x='5';
    }
    else if(*x=='Q')
    {
        *x='9';
    }
    else if(*x=='K')
    {
        *x='W';
    }
}
bool is_possibleh(char x)  //this function give which possition horse can move 
{
    if(x==' '||x=='P'||x=='R'||x=='B'||x=='H'||x=='Q'||x=='K')
    {
        return true;
    }
    else 
    {
        return false;
    }
}
void kill_chance(char* x) //this function set values for moving position
{
    if(*x=='P')
    {
        *x='1';
    }
    else if(*x=='B')
    {
        *x='3';
    }
    else if(*x=='H')
    {
        *x='4';
    }
    else if(*x=='R')
    {
        *x='5';
    }
    else if(*x=='Q')
    {
        *x='9';
    }
    else if(*x=='K')
    {
        *x='W';
    }
}
bool is_possible(char x) //this function give true for movable position
{
    if(x=='.'||x=='1'||x=='3'||x=='4'||x=='5'||x=='9'||x=='W')
    {
        return true;
    }
    else 
    {
        false;
    }
}
class pown // class for pown lower pown 
{
    private :
    bool status;
    public :
    int i,j;
    pown()
    {
        status=true;
    }
    void dead()
    {
        status=false;
    }
    bool get_status()
    {
        return status;
    }
    void movable_pos()
    {
        if(ar[i-1][j]==' ')
        {
            ar[i-1][j]='.';
            if(i==7&&ar[i-2][j]==' ')
            {
                ar[i-2][j]='.';
            }
        }
         if(is_possible_pown(ar[i-1][j-1]))
        {
            kill_chance_pown(&ar[i-1][j-1]);
        }
         if(is_possible_pown(ar[i-1][j+1]))
        {
            kill_chance_pown(&ar[i-1][j+1]);
        }
        
    }
    void move(int dir, int step)
    {
        if(is_possible_pown(ar[i-step][j+dir]))
        {
            kill_benifit(i-step,j+dir);
            i=i-step;
            j=j+dir;
        }
        else 
        {
            cout<<" wrong choice "<<endl;
            quality=true;
        }
    }
}p1,p2,p3,p4,p5,p6,p7,p8,p;
class rocks 
{
    private :
    bool status;
    public :
    int i,j;
    rocks()
    {
        status=true;
    }
    void dead(){
        status=false;
    }
    bool get_status(){
        return status;
    }
    void movable_pos() //this function give information about movable position
    {
        int c=1;
        while(pos[i-c][j])
        {
            ar[i-c][j]='.';
            c++;
        }
        kill_chance(&ar[i-c][j]);
        c=1;
        while(pos[i+c][j])
        {
            ar[i+c][j]='.';
            c++;
        }
        kill_chance(&ar[i+c][j]);
        c=1;
        while(pos[i][j-c])
        {
            ar[i][j-c]='.';
            c++;
        }
        kill_chance(&ar[i][j-c]);
        c=1;
        while(pos[i][j+c])
        {
            ar[i][j+c]='.';
            c++;
        }
        kill_chance(&ar[i][j+c]);
    }
    void move(int dir, int step) //this function can change position of elemetnt
    {
        if(dir==1&&is_possible(ar[i][j+step]))
        {
            kill_benifit(i,j+step);
            j=j+step;
        }
        else if(dir==2&&is_possible(ar[i-step][j]))
        {
            kill_benifit(i-step,j);
            i=i-step;
        }
        else if(dir==3&&is_possible(ar[i][j-step]))
        {
            kill_benifit(i,j-step);
            j=j-step;
        }
        else if(dir==4&&is_possible(ar[i+step][j]))
        {
            kill_benifit(i+step,j);
            i=i+step;
        }
        else
        {
            cout<<"wrong choice "<<endl;
            quality=true;
        }
    }
}r1,r2,r;
class bishops  //class for bishops of black
{
    private :
    bool status;
    public :
    int i,j;
    bishops()
    {
        status=true;
    }
    void dead()
    {
        status=false;
    }
    bool get_status()
    {
        return status;
    }
    void movable_pos()
    {
        int c=1;
        while(pos[i-c][j-c])
        {
            ar[i-c][j-c]='.';
            c++;
        }
        kill_chance(&ar[i-c][j-c]);
        c=1;
        while(pos[i+c][j+c])
        {
            ar[i+c][j+c]='.';
            c++;
        }
        kill_chance(&ar[i+c][j+c]);
        c=1;
        while(pos[i-c][j+c])
        {
            ar[i-c][j+c]='.';
            c++;
        }
        kill_chance(&ar[i-c][j+c]);
        c=1;
        while(pos[i+c][j-c])
        {
            ar[i+c][j-c]='.';
            c++;
        }
        kill_chance(&ar[i+c][j-c]);
    }
    void move(int dir, int step)
    {
        if(dir==1&&is_possible(ar[i-step][j+step]))
        {
            kill_benifit(i-step,j+step);
            i=i-step;
            j=j+step;
        }
        else if(dir==2&&is_possible(ar[i-step][j-step]))
        {
            kill_benifit(i-step,j-step);
            i=i-step;
            j=j-step;
        }
        else if(dir==3&&is_possible(ar[i+step][j-step]))
        {
            kill_benifit(i+step,j-step);
            i=i+step;
            j=j-step;
        }
        else if(dir==4&&is_possible(ar[i+step][j-step]))
        {
            kill_benifit(i+step,j-step);
            i=i+step;
            j=j-step;
        }
        else 
        {
            cout<<"wrong choic "<<endl;
            quality=true;
        }
    }
}b1,b2,b;
class horse  // class for horse of black
{
    private :
    bool status;
    public :
    int i,j;
    horse(){
        status=true;
    }
    void dead(){
        status=false;
    }
    bool get_status(){
        return status;
    }
    void movable_pos()
    {
       if(is_possibleh(ar[i-2][j-1]))
        {
            kill_chanceh(&ar[i-2][j-1]);
        }
        if(is_possibleh(ar[i-2][j+1]))
        {
            kill_chanceh(&ar[i-2][j+1]);
        }
        if(is_possibleh(ar[i+2][j-1]))
        {
            kill_chanceh(&ar[i+2][j-1]);
        }
        if(is_possibleh(ar[i+2][j+1]))
        {
            kill_chanceh(&ar[i+2][j+1]);
        }
        if(is_possibleh(ar[i-1][j-2]))
        {
            kill_chanceh(&ar[i-1][j-2]);
        }
        if(is_possibleh(ar[i+1][j-2]))
        {
            kill_chanceh(&ar[i+1][j-2]);
        }
        if(is_possibleh(ar[i-1][j+2]))
        {
            kill_chanceh(&ar[i-1][j+2]);
        }
        if(is_possibleh(ar[i+1][j+2]))
        {
            kill_chanceh(&ar[i+1][j+2]);
        }
    }
    void move(int dir1,int dir2)
    {
        if(dir1==1&&is_possible(ar[i+dir2][j+2]))
        {
            kill_benifit(i+dir2,j+2);
            j=j+2;
            i=i+dir2;
        }
        else if(dir1==2&&is_possible(ar[i-2][j+dir2]))
        {
            kill_benifit(i-2,j+dir2);
            i=i-2;
            j=j+dir2;
        }
        else if(dir1==3&&is_possible(ar[i+dir2][j-2]))
        {
            kill_benifit(i+dir2,j-2);
            j=j-2;
            i=i+dir2;
        }
        else if(dir1==4&&is_possible(ar[i+2][j+dir2]))
        {
            kill_benifit(i+2,j+dir2);
            i=i+2;
            j=j+dir2;
        }
        else
        {
            cout<<"wrong choice "<<endl;
            quality=true;
        }
    }
}h1,h2,h;
class queen   // class for queen of black
{
    private :
    bool status;
    public :
    int i,j;
    queen(){
        status=true;
    }
    void dead()
    {
        status=false;
    }
    bool get_status(){
        return status;
    }
    void move(int dir, int step)
    {
        if(dir==2&&is_possible(ar[i-step][j+step]))
        {
            kill_benifit(i-step,j+step);
            draw();
            i=i-step;
            j=j+step;
        }
        else if(dir==4&&is_possible(ar[i-step][j-step]))
        {
            kill_benifit(i-step,j-step);
            i=i-step;
            j=j-step;
        }
        else if(dir==6&&is_possible(ar[i+step][j-step]))
        {
            kill_benifit(i+step,j-step);
            i=i+step;
            j=j-step;
        }
        else if(dir==8&&is_possible(ar[i+step][j+step]))
        {
            kill_benifit(i+step,j+step);
            i=i+step;
            j=j-step;
        }
        else if(dir==1&&is_possible(ar[i][j+step]))
        {
            kill_benifit(i,j+step);
            j=j+step;
        }
        else if(dir==3&&is_possible(ar[i-step][j]))
        {
            kill_benifit(i-step,j);
            i=i-step;
        }
        else if(dir==5&&is_possible(ar[i][j-step]))
        {
            kill_benifit(i,j-step);
            j=j-step;
        }
        else if(dir==7&&is_possible(ar[i+step][j]))
        {
            kill_benifit(i+step,j);
            i=i+step;
        }
        else
        {
            cout<<"wrong choice "<<endl;
            quality=true;
        }
    }
    void movable_pos()
    {
        int c=1;
        while(pos[i-c][j-c])
        {
            ar[i-c][j-c]='.';
            c++;
        }
        kill_chance(&ar[i-c][j-c]);
        c=1;
        while(pos[i+c][j+c])
        {
            ar[i+c][j+c]='.';
            c++;
        }
        kill_chance(&ar[i+c][j+c]);
        c=1;
        while(pos[i-c][j+c])
        {
            ar[i-c][j+c]='.';
            c++;
        }
        kill_chance(&ar[i-c][j+c]);
        c=1;
        while(pos[i+c][j-c])
        {
            ar[i+c][j-c]='.';
            c++;
        }
        kill_chance(&ar[i+c][j-c]);
        c=1;
        while(pos[i-c][j])
        {
            ar[i-c][j]='.';
            c++;
        }
        kill_chance(&ar[i-c][j]);
        c=1;
        while(pos[i+c][j])
        {
            ar[i+c][j]='.';
            c++;
        }
        kill_chance(&ar[i+c][j]);
        c=1;
        while(pos[i][j-c])
        {
            ar[i][j-c]='.';
            c++;
        }
        kill_chance(&ar[i][j-c]);
        c=1;
        while(pos[i][j+c])
        {
            ar[i][j+c]='.';
            c++;
        }
        kill_chance(&ar[i][j+c]);
    }
}q,q1;
class king 
{
    private :
    bool status;
    public :
    int i,j;
    king(){
        status=true;
    }
    void dead(){
        status=false;
    }
    bool get_status(){
        return status;
    }
    void movable_pos()
    {
        if(is_possibleh(ar[i][j-1]))
        {
            kill_chanceh(&ar[i][j-1]);
        }
        if(is_possibleh(ar[i][j+1]))
        {
            kill_chanceh(&ar[i][j+1]);
        }
        if(is_possibleh(ar[i-1][j]))
        {
            kill_chanceh(&ar[i-1][j]);
        }
        if(is_possibleh(ar[i+1][j]))
        {
            kill_chanceh(&ar[i+1][j]);
        }
        if(is_possibleh(ar[i-1][j-1]))
        {
            kill_chanceh(&ar[i-1][j-1]);
        }
        if(is_possibleh(ar[i+1][j-1]))
        {
            kill_chanceh(&ar[i+1][j-1]);
        }
        if(is_possibleh(ar[i-1][j+1]))
        {
            kill_chanceh(&ar[i-1][j+1]);
        }
        if(is_possibleh(ar[i+1][j+1]))
        {
            kill_chanceh(&ar[i+1][j+1]);
        }
    }
    void move(int dir)
    {
        if(dir==1){kill_benifit(i,j+1);
            j++;
        }
        else if(dir==3){kill_benifit(i-1,j);
            i--;
        }
        else if(dir==5){kill_benifit(i,j-1);
            j--;
        }
        else if(dir==7){kill_benifit(i+1,j);
            i++;
        }
        else if(dir==2){kill_benifit(i-1,j+1);
            i--;j++;
        }
        else if(dir==4){kill_benifit(i-1,j-1);
            i--;j--;
        }
        else if(dir==6){kill_benifit(i+1,j-1);
            i++;j--;
        }
        else if(dir==8){kill_benifit(i+1,j+1);
            i++;j++;
        }
        else 
        {
            cout<<"wrong choice "<<endl;
            quality=true;
        }
    }
}k;
class Powns  // class for pawns of white
{
    private:
    bool status;
    public :
    int i,j;
    Powns(){
        status=true;
    }
    void dead(){
        status=false;
    }
    bool get_status(){
        return status;
    }
    void movable_pos()
    {
        if(ar[i+1][j]==' ')
        {
            ar[i+1][j]='.';
            if(i==2&&ar[i+2][j]==' ')
            {
                ar[i+2][j]='.';
            }
        }
         if(is_possible_pownw(ar[i+1][j-1]))
        {
            kill_chance_pownw(&ar[i+1][j-1]);
        }
         if(is_possible_pownw(ar[i+1][j+1]))
        {
            kill_chance_pownw(&ar[i+1][j+1]);
        }
        
    }
    void move(int dir, int step)
    {
        if(is_possible_pown(ar[i+step][j+dir]))
        {
            kill_benifitw(i+step,j+dir);
            i=i+step;
            j=j+dir;
        }
        else 
        {
            cout<<" wrong choice "<<endl;
            quality=true;
        }
    }
    
}P1,P2,P3,P4,P5,P6,P7,P8;
class Bishops   //class for bishops of white
{
    private:
    bool status;
    public :
    int i,j;
    Bishops(){
        status=true;
    }
    void dead(){
        status=false;
    }
    bool get_status(){
        return status;
    }
    void movable_pos()
    {
        int c=1;
        while(pos[i-c][j-c])
        {
            ar[i-c][j-c]='.';
            c++;
        }
        kill_chancew(&ar[i-c][j-c]);
        c=1;
        while(pos[i+c][j+c])
        {
            ar[i+c][j+c]='.';
            c++;
        }
        kill_chancew(&ar[i+c][j+c]);
        c=1;
        while(pos[i-c][j+c])
        {
            ar[i-c][j+c]='.';
            c++;
        }
        kill_chancew(&ar[i-c][j+c]);
        c=1;
        while(pos[i+c][j-c])
        {
            ar[i+c][j-c]='.';
            c++;
        }
        kill_chancew(&ar[i+c][j-c]);
    }
    void move(int dir, int step)
    {
        if(dir==1&&is_possiblew(ar[i-step][j+step]))
        {
            kill_benifitw(i-step,j+step);
            i=i-step;
            j=j+step;
        }
        else if(dir==2&&is_possiblew(ar[i-step][j-step]))
        {
            kill_benifitw(i-step,j-step);
            i=i-step;
            j=j-step;
        }
        else if(dir==3&&is_possiblew(ar[i+step][j-step]))
        {
            kill_benifitw(i+step,j-step);
            i=i+step;
            j=j-step;
        }
        else if(dir==4&&is_possiblew(ar[i+step][j-step]))
        {
            kill_benifitw(i+step,j-step);
            i=i+step;
            j=j-step;
        }
        else 
        {
            cout<<"wrong choic "<<endl;
            quality=true;
        }
    }
}B1,B2;
class Horses
{
    private:
    bool status;
    public :
    int i,j;
    Horses(){
        status=true;
    }
    void dead(){
        status=false;
    }
    bool get_status(){
        return status;
    }
    void movable_pos()
    {
       if(is_possiblehw(ar[i-2][j-1]))
        {
            kill_chancehw(&ar[i-2][j-1]);
        }
        if(is_possiblehw(ar[i-2][j+1]))
        {
            kill_chancehw(&ar[i-2][j+1]);
        }
        if(is_possiblehw(ar[i+2][j-1]))
        {
            kill_chancehw(&ar[i+2][j-1]);
        }
        if(is_possiblehw(ar[i+2][j+1]))
        {
            kill_chancehw(&ar[i+2][j+1]);
        }
        if(is_possiblehw(ar[i-1][j-2]))
        {
            kill_chancehw(&ar[i-1][j-2]);
        }
        if(is_possiblehw(ar[i+1][j-2]))
        {
            kill_chancehw(&ar[i+1][j-2]);
        }
        if(is_possiblehw(ar[i-1][j+2]))
        {
            kill_chancehw(&ar[i-1][j+2]);
        }
        if(is_possiblehw(ar[i+1][j+2]))
        {
            kill_chancehw(&ar[i+1][j+2]);
        }
    }
    void move(int dir1,int dir2)
    {
        if(dir1==1&&is_possiblew(ar[i+dir2][j+2]))
        {
            kill_benifitw(i+dir2,j+2);
            j=j+2;
            i=i+dir2;
        }
        else if(dir1==2&&is_possiblew(ar[i-2][j+dir2]))
        {
            kill_benifitw(i-2,j+dir2);
            i=i-2;
            j=j+dir2;
        }
        else if(dir1==3&&is_possiblew(ar[i+dir2][j-2]))
        {
            kill_benifitw(i+dir2,j-2);
            j=j-2;
            i=i+dir2;
        }
        else if(dir1==4&&is_possiblew(ar[i+2][j+dir2]))
        {
            kill_benifitw(i+2,j+dir2);
            i=i+2;
            j=j+dir2;
        }
        else
        {
            cout<<"wrong choice "<<endl;
            quality=true;
        }
    }
}H1,H2;
class King 
{
    private :
    bool status;
    public :
    int i,j;
    King()
    {
        status=true;
    }
    void dead(){
        status=false;
    }
    bool get_status(){
        return status;
    }
    void movable_pos()
    {
        if(is_possiblehw(ar[i][j-1]))
        {
            kill_chancehw(&ar[i][j-1]);
        }
        if(is_possiblehw(ar[i][j+1]))
        {
            kill_chancehw(&ar[i][j+1]);
        }
        if(is_possiblehw(ar[i-1][j]))
        {
            kill_chancehw(&ar[i-1][j]);
        }
        if(is_possiblehw(ar[i+1][j]))
        {
            kill_chancehw(&ar[i+1][j]);
        }
        if(is_possiblehw(ar[i-1][j-1]))
        {
            kill_chancehw(&ar[i-1][j-1]);
        }
        if(is_possiblehw(ar[i+1][j-1]))
        {
            kill_chancehw(&ar[i+1][j-1]);
        }
        if(is_possiblehw(ar[i-1][j+1]))
        {
            kill_chancehw(&ar[i-1][j+1]);
        }
        if(is_possiblehw(ar[i+1][j+1]))
        {
            kill_chancehw(&ar[i+1][j+1]);
        }
    }
    void move(int dir)
    {
        if(dir==1){kill_benifitw(i,j+1);
            j++;
        }
        else if(dir==3){kill_benifitw(i-1,j);
            i--;
        }
        else if(dir==5){kill_benifitw(i,j-1);
            j--;
        }
        else if(dir==7){kill_benifitw(i+1,j);
            i++;
        }
        else if(dir==2){kill_benifitw(i-1,j+1);
            i--;j++;
        }
        else if(dir==4){kill_benifitw(i-1,j-1);
            i--;j--;
        }
        else if(dir==6){kill_benifitw(i+1,j-1);
            i++;j--;
        }
        else if(dir==8){kill_benifitw(i+1,j+1);
            i++;j++;
        }
        else 
        {
            cout<<" wrong choice "<<endl;
            quality=true;
        }
    }
}K;
class Queen  // class for queen of white
{
    private:
    bool status;
    public :
    int i,j;
    Queen(){
        status=true;
    }
    void dead(){
        status=false;
    }
    bool get_status(){
        return status;
    }
   void move(int dir, int step)
    {
        if(dir==2&&is_possiblew(ar[i-step][j+step]))
        {
            kill_benifitw(i-step,j+step);
            i=i-step;
            j=j+step;
        }
        else if(dir==4&&is_possiblew(ar[i-step][j-step]))
        {
            kill_benifitw(i-step,j-step);
            i=i-step;
            j=j-step;
        }
        else if(dir==6&&is_possiblew(ar[i+step][j-step]))
        {
            kill_benifitw(i+step,j-step);
            i=i+step;
            j=j-step;
        }
        else if(dir==8&&is_possiblew(ar[i+step][j+step]))
        {
            kill_benifitw(i+step,j+step);
            i=i+step;
            j=j+step;
        }
        else if(dir==1&&is_possiblew(ar[i][j+step]))
        {
            kill_benifitw(i,j+step);
            j=j+step;
        }
        else if(dir==3&&is_possiblew(ar[i-step][j]))
        {
            kill_benifitw(i-step,j);
            i=i-step;
        }
        else if(dir==5&&is_possiblew(ar[i][j-step]))
        {
            kill_benifitw(i,j-step);
            j=j-step;
        }
        else if(dir==7&&is_possiblew(ar[i+step][j]))
        {
            kill_benifitw(i+step,j);
            i=i+step;
        }
        else
        {
            cout<<"wrong choice "<<endl;
            quality=true;
        }
    }
    void movable_pos()
    {
        int c=1;
        while(pos[i-c][j-c])
        {
            ar[i-c][j-c]='.';
            c++;
        }
        kill_chancew(&ar[i-c][j-c]);
        c=1;
        while(pos[i+c][j+c])
        {
            ar[i+c][j+c]='.';
            c++;
        }
        kill_chancew(&ar[i+c][j+c]);
        c=1;
        while(pos[i-c][j+c])
        {
            ar[i-c][j+c]='.';
            c++;
        }
        kill_chancew(&ar[i-c][j+c]);
        c=1;
        while(pos[i+c][j-c])
        {
            ar[i+c][j-c]='.';
            c++;
        }
        kill_chancew(&ar[i+c][j-c]);
        c=1;
        while(pos[i-c][j])
        {
            ar[i-c][j]='.';
            c++;
        }
        kill_chancew(&ar[i-c][j]);
        c=1;
        while(pos[i+c][j])
        {
            ar[i+c][j]='.';
            c++;
        }
        kill_chancew(&ar[i+c][j]);
        c=1;
        while(pos[i][j-c])
        {
            ar[i][j-c]='.';
            c++;
        }
        kill_chancew(&ar[i][j-c]);
        c=1;
        while(pos[i][j+c])
        {
            ar[i][j+c]='.';
            c++;
        }
        kill_chancew(&ar[i][j+c]);
    }
}Q;
class Rocks  // class for rocks of white
{
    private :
    bool status;
    public :
    int i,j;
    Rocks()
    {
        status=true;
    }
    void dead(){
        status=false;
    }
    bool get_status(){
        return status;
    }
    void movable_pos() //this function give information about movable position
    {
        int c=1;
        while(pos[i-c][j])
        {
            ar[i-c][j]='.';
            c++;
        }
        kill_chancew(&ar[i-c][j]);
        c=1;
        while(pos[i+c][j])
        {
            ar[i+c][j]='.';
            c++;
        }
        kill_chancew(&ar[i+c][j]);
        c=1;
        while(pos[i][j-c])
        {
            ar[i][j-c]='.';
            c++;
        }
        kill_chancew(&ar[i][j-c]);
        c=1;
        while(pos[i][j+c])
        {
            ar[i][j+c]='.';
            c++;
        }
        kill_chancew(&ar[i][j+c]);
    }
    void move(int dir, int step) //this function can change position of elemetnt
    {
        if(dir==1&&is_possiblew(ar[i][j+step]))
        {
            kill_benifitw(i,j+step);
            j=j+step;
        }
        else if(dir==2&&is_possiblew(ar[i-step][j]))
        {
            kill_benifitw(i-step,j);
            i=i-step;
        }
        else if(dir==3&&is_possiblew(ar[i][j-step]))
        {
            kill_benifitw(i,j-step);
            j=j-step;
        }
        else if(dir==4&&is_possiblew(ar[i+step][j]))
        {
            kill_benifitw(i+step,j);
            i=i+step;
        }
        else
        {
            cout<<"wrong choice "<<endl;
            quality=true;
        }
    }
}R1,R2;
void kill_benifit(int x, int y) //this function gives score and make pieces die for black i guess
{
    if(x==P1.i&&y==P1.j&&P1.get_status())
    {
        P1.dead();
        score2++;
    }
    else if(x==P2.i&&y==P2.j&&P2.get_status())
    {
        P2.dead();
        score2++;
    }
    else if(x==P3.i&&y==P3.j&&P3.get_status())
    {
        P3.dead();
        score2++;
    }
    else if(x==P4.i&&y==P4.j&&P4.get_status())
    {
        P4.dead();
        score2++;
    }
    else if(x==P5.i&&y==P5.j&&P5.get_status())
    {
        P5.dead();
        score2++;
    }
    else if(x==P6.i&&y==P6.j&&P6.get_status())
    {
        P6.dead();
        score2++;
    }
    else if(x==P7.i&&y==P7.j&&P7.get_status())
    {
        P7.dead();
        score2++;
    }
    else if(x==P8.i&&y==P8.j&&P8.get_status())
    {
        P8.dead();
        score2++;
    }    else if(x==B1.i&&y==B1.j&&B1.get_status())
    {
        B1.dead();
        score2+=3;
    }
    else if(x==B2.i&&y==B2.j&&B2.get_status())
    {
        B2.dead();
        score2+=3;
    }
    else if(x==H1.i&&y==H1.j&&H1.get_status())
    {
        H1.dead();
        score2+=4;
    }
    else if(x==H2.i&&y==H2.j&&H2.get_status())
    {
        H2.dead();
        score2+=4;
    }
    else if(x==R1.i&&y==R1.j&&R1.get_status())
    {
        R1.dead();
        score2+=5;
    }
    else if(x==R2.i&&y==R2.j&&R2.get_status())
    {
        R2.dead();
        score2+=5;
    }
    else if(x==Q.i&&y==Q.j&&Q.get_status())
    {
        Q.dead();
        score2+=9;
    }
    else if(x==K.i&&y==K.j&&K.get_status())
    {
        K.dead();
        score2+=15;
    }
}
void kill_benifitw(int x, int y) //this function gives score and makes pieces die for white i guess
{
    if(x==p1.i&&y==p1.j&&p1.get_status())
    {
        p1.dead();
        score1++;
    }
    else if(x==p2.i&&y==p2.j&&p2.get_status())
    {
        p2.dead();
        score1++;
    }
    else if(x==p3.i&&y==p3.j&&p3.get_status())
    {
        p3.dead();
        score1++;
    }
    else if(x==p4.i&&y==p4.j&&p4.get_status())
    {
        p4.dead();
        score1++;
    }
    else if(x==p5.i&&y==p5.j&&p5.get_status())
    {
        p5.dead();
        score1++;
    }
    else if(x==p6.i&&y==p6.j&&p6.get_status())
    {
        p6.dead();
        score1++;
    }
    else if(x==p7.i&&y==p7.j&&p7.get_status())
    {
        p7.dead();
        score1++;
    }
    else if(x==p8.i&&y==p8.j&&p8.get_status())
    {
        p8.dead();
        score1++;
    }    else if(x==b1.i&&y==b1.j&&b1.get_status())
    {
        b1.dead();
        score1+=3;
    }
    else if(x==b2.i&&y==b2.j&&b2.get_status())
    {
        b2.dead();
        score1+=3;
    }
    else if(x==h1.i&&y==h1.j&&h1.get_status())
    {
        h1.dead();
        score1+=4;
    }
    else if(x==h2.i&&y==h2.j&&h2.get_status())
    {
        h2.dead();
        score1+=4;
    }
    else if(x==r1.i&&y==r1.j&&r1.get_status())
    {
        r1.dead();
        score1+=5;
    }
    else if(x==r2.i&&y==r2.j&&r2.get_status())
    {
        r2.dead();
        score1+=5;
    }
    else if(x==q.i&&y==q.j&&q.get_status())
    {
        q.dead();
        score1+=9;
    }
    else if(x==k.i&&y==k.j&&k.get_status())
    {
        k.dead();
        score1+=15;
    }
}
void playtime_black() //this function is essential for play game
{
    int c=1;
    string ele;
    int step;
    int dir;
    av:
    cout<<endl<<"enter your element "<<endl;
    cin>>ele;
    
    if(ele=="p1")
    {
        if(p1.get_status())
        {
            p1.movable_pos();
            draw();
            cout<<"enter your dir "<<endl;
            cout<<"                     0 for stright, -1 for left , 1 for right "<<endl;
            cin>>dir;
            cout<<endl<<"enter your steps "<<endl;
            cin>>step;
            if(step>2||dir<-1||dir>1){
                cout<<" wrong choic "<<endl;quality=true;
                
            }
            else{
                p1.move(dir,step);
            }
        }
        else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="p2")
    {
        if(p2.get_status())
        {
            p2.movable_pos();
            draw();
            cout<<"enter your dir "<<endl;
            cout<<"                     0 for stright, -1 for left , 1 for right "<<endl;
            cin>>dir;
            cout<<endl<<"enter your steps "<<endl;
            cin>>step;
            if(step>2||dir<-1||dir>1){
                cout<<" wrong choic "<<endl;quality=true;
            }
            else p2.move(dir,step);
        }
        else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="p3")
    {
        if(p3.get_status())
        {
            p3.movable_pos();
            draw();
            cout<<"enter your dir "<<endl;
            cout<<"                     0 for stright, -1 for left , 1 for right "<<endl;
            cin>>dir;
            cout<<endl<<"enter your steps "<<endl;
            cin>>step;
            if(step>2||dir<-1||dir>1){
                cout<<" wrong choic "<<endl;quality=true;
            }
            else p3.move(dir,step);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="p4")
    {
        if(p4.get_status())
        {
            p4.movable_pos();
            draw();
            cout<<"enter your dir "<<endl;
            cout<<"                     0 for stright, -1 for left , 1 for right "<<endl;
            cin>>dir;
            cout<<endl<<"enter your steps "<<endl;
            cin>>step;
            if(step>2||dir<-1||dir>1){
                cout<<" wrong choic "<<endl;quality=true;
            }
            else p4.move(dir,step);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="p5")
    {
        if(p5.get_status())
        {
            p5.movable_pos();
            draw();
            cout<<"enter your dir "<<endl;
            cout<<"                     0 for stright, -1 for left , 1 for right "<<endl;
            cin>>dir;
            cout<<endl<<"enter your steps "<<endl;
            cin>>step;
            if(step>2||dir<-1||dir>1){
                cout<<" wrong choic "<<endl;quality=true;
            }
            else p5.move(dir,step);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="p6")
    {
        if(p6.get_status())
        {
            p6.movable_pos();
            draw();
            cout<<"enter your dir "<<endl;
            cout<<"                     0 for stright, -1 for left , 1 for right "<<endl;
            cin>>dir;
            cout<<endl<<"enter your steps "<<endl;
            cin>>step;
            if(step>2||dir<-1||dir>1){
                cout<<" wrong choic "<<endl;quality=true;
            }
            else p6.move(dir,step);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="p7")
    {
        if(p7.get_status())
        {
            p7.movable_pos();
            draw();
            cout<<"enter your dir "<<endl;
            cout<<"                     0 for stright, -1 for left , 1 for right "<<endl;
            cin>>dir;
            cout<<endl<<"enter your steps "<<endl;
            cin>>step;
            if(step>2||dir<-1||dir>1){
                cout<<" wrong choic "<<endl;quality=true;
            }
            else p7.move(dir,step);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="p8")
    {
        if(p8.get_status())
        {
            p8.movable_pos();
            draw();
            cout<<"enter your dir "<<endl;
            cout<<"                     0 for stright, -1 for left , 1 for right "<<endl;
            cin>>dir;
            cout<<endl<<"enter your steps "<<endl;
            cin>>step;
            if(step>2||dir<-1||dir>1){
                cout<<" wrong choic "<<endl;quality=true;
            }
            else p8.move(dir,step);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="b1")
    {
        if(b1.get_status())
        {
            b1.movable_pos(); 
            draw();
            cout<<"enter your dir "<<endl;
            cout<<"                     1 for up-right and increase 1 for each anti-clockwise possible move "<<endl;
            cin>>dir;
            cout<<endl<<"enter your steps "<<endl;
            cin>>step;
            b1.move(dir,step);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="b2")
    {
        if(b2.get_status())
        {
            b2.movable_pos(); 
            draw();
            cout<<"enter your dir "<<endl;
            cout<<"                     1 for up-right and increase 1 for each anti-clockwise possible move "<<endl;
            cin>>dir;
            cout<<endl<<"enter your steps "<<endl;
            cin>>step;
            b2.move(dir,step);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="h1")
    {
        if(h1.get_status())
        {
            int dir1,dir2;
            h1.movable_pos();
            draw();
            cout<<"enter direction1 "<<endl;
            cout<<"                     1 for right and increase 1 for each anti-clockwise possible move "<<endl;
            cin>>dir1;
            cout<<"enter direction2 "<<endl;
            cout<<"                     -1 for left of the direction-1 , 1 for right of the direction-1  "<<endl;
            cin>>dir2;
            h1.move(dir1,dir2);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="h2")
    {
        if(h2.get_status())
        {
            int dir1,dir2;
            h2.movable_pos();
            draw();
            cout<<"enter direction1 "<<endl;
            cout<<"                     1 for right and increase 1 for each anti-clockwise possible move "<<endl;
            cin>>dir1;
            cout<<"enter direction2 "<<endl;
            cout<<"                     -1 for left of the direction-1 , 1 for right of the direction-1  "<<endl;
            cin>>dir2;
            h2.move(dir1,dir2);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="r1")
    {
        if(r1.get_status())
        {
            int dir,step;
            r1.movable_pos();
            draw();
            cout<<"enter direction "<<endl;
            cout<<"                     1 for right and increase 1 for each anti-clockwise possible move "<<endl;
            cin>>dir;
            cout<<"enter steps"<<endl;
            cin>>step;
            r1.move(dir,step);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="r2")
    {
        if(r2.get_status())
        {
            int dir,step;
            r2.movable_pos();
            draw();
            cout<<"enter direction "<<endl;
            cout<<"                     1 for right and increase 1 for each anti-clockwise possible move  "<<endl;
            cin>>dir;
            cout<<"enter steps"<<endl;
            cin>>step;
            r2.move(dir,step);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="q")
    {
        if(q.get_status())
        {
            int dir1,dir2,step;
            q.movable_pos();
            draw();
            cout<<"enter direction "<<endl;
            cout<<"                     1 for right and increase 1 for each anti-clockwise possible move "<<endl;
            cin>>dir;
            cout<<"enter steps "<<endl;
            cin>>step;
            q.move(dir,step);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="k")
    {
        if(k.get_status())
        {
            int dir;
            k.movable_pos();
            draw();
            cout<<"enter directon "<<endl;
            cout<<"                     1 for right and increase 1 for each anti-clockwise possible move "<<endl;
            cin>>dir;
            k.move(dir);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
}
void playtime_white()
{
    int c=1;
    string ele;
    int step;
    int dir;
    cout<<endl<<"enter your element "<<endl;
    cin>>ele;
    if(ele=="p1")
    {
        if(P1.get_status())
        {
            P1.movable_pos();
            draw();
            cout<<"enter your dir "<<endl;
            cout<<"                     0 for stright, -1 for left , 1 for right "<<endl;
            cin>>dir;
            cout<<endl<<"enter your steps "<<endl;
            cin>>step;
            if(step>2||dir<-1||dir>1){
                cout<<" wrong choic "<<endl;quality=true;
            }
            else P1.move(dir,step);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="p2")
    {
        if(P2.get_status())
        {
            P2.movable_pos();
            draw();
            cout<<"enter your dir "<<endl;
            cout<<"                     0 for stright, -1 for left , 1 for right "<<endl;
            cin>>dir;
            cout<<endl<<"enter your steps "<<endl;
            cin>>step;
            if(step>2||dir<-1||dir>1){
                cout<<" wrong choic "<<endl;quality=true;
            }
            else P2.move(dir,step);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="p3")
    {
        if(P3.get_status())
        {
            P3.movable_pos();
            draw();
            cout<<"enter your dir "<<endl;
            cout<<"                     0 for stright, -1 for left , 1 for right "<<endl;
            cin>>dir;
            cout<<endl<<"enter your steps "<<endl;
            cin>>step;
            if(step>2||dir<-1||dir>1){
                cout<<" wrong choic "<<endl;quality=true;
            }
            else P3.move(dir,step);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="p4")
    {
        if(P4.get_status())
        {
            P4.movable_pos();
            draw();
            cout<<"enter your dir "<<endl;
            cout<<"                     0 for stright, -1 for left , 1 for right "<<endl;
            cin>>dir;
            cout<<endl<<"enter your steps "<<endl;
            cin>>step;
            if(step>2||dir<-1||dir>1){
                cout<<" wrong choic "<<endl;quality=true;
            }
            else P4.move(dir,step);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="p5")
    {
        if(P5.get_status())
        {
            P5.movable_pos();
            draw();
            cout<<"enter your dir "<<endl;
            cout<<"                     0 for stright, -1 for left , 1 for right "<<endl;
            cin>>dir;
            cout<<endl<<"enter your steps "<<endl;
            cin>>step;
            if(step>2||dir<-1||dir>1){
                cout<<" wrong choic "<<endl;quality=true;
            }
            else P5.move(dir,step);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="p6")
    {
        if(P6.get_status())
        {
            P6.movable_pos();
            draw();
            cout<<"enter your dir "<<endl;
            cout<<"                     0 for stright, -1 for left , 1 for right "<<endl;
            cin>>dir;
            cout<<endl<<"enter your steps "<<endl;
            cin>>step;
            if(step>2||dir<-1||dir>1){
                cout<<" wrong choic "<<endl;quality=true;
            }
            else P6.move(dir,step);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="p7")
    {
        if(P7.get_status())
        {
            P7.movable_pos();
            draw();
            cout<<"enter your dir "<<endl;
            cout<<"                     0 for stright, -1 for left , 1 for right "<<endl;
            cin>>dir;
            cout<<endl<<"enter your steps "<<endl;
            cin>>step;
            if(step>2||dir<-1||dir>1){
                cout<<" wrong choic "<<endl;quality=true;
            }
            else P7.move(dir,step);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="p8")
    {
        if(P8.get_status())
        {
            P8.movable_pos();
            draw();
            cout<<"enter your dir "<<endl;
            cout<<"                     0 for stright, -1 for left , 1 for right "<<endl;
            cin>>dir;
            cout<<endl<<"enter your steps "<<endl;
            cin>>step;
            if(step>2||dir<-1||dir>1){
                cout<<" wrong choic "<<endl;quality=true;
            }
            else P8.move(dir,step);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="b1")
    {
        if(B1.get_status())
        {
            B1.movable_pos(); 
            draw();
            cout<<"enter your dir "<<endl;
            cout<<"                     1 for up-right and increase 1 for each anti-clockwise possible move "<<endl;
            cin>>dir;
            cout<<endl<<"enter your steps "<<endl;
            cin>>step;
            B1.move(dir,step);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="b2")
    {
        if(B2.get_status())
        {
            B2.movable_pos(); 
            draw();
            cout<<"enter your dir "<<endl;
            cout<<"                     1 for up-right and increase 1 for each anti-clockwise possible move "<<endl;
            cin>>dir;
            cout<<endl<<"enter your steps "<<endl;
            cin>>step;
            B2.move(dir,step);
        }
    }
    if(ele=="h1")
    {
        if(H1.get_status())
        {
            int dir1,dir2;
            H1.movable_pos();
            draw();
            cout<<"enter direction1 "<<endl;
            cout<<"                     1 for right and increase 1 for each anti-clockwise possible move "<<endl;
            cin>>dir1;
            cout<<"enter direction2 "<<endl;
            cout<<"                     -1 for left of the direction-1 , 1 for right of the direction-1  "<<endl;
            cin>>dir2;
            H1.move(dir1,dir2);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="h2")
    {
        if(H2.get_status())
        {
            int dir1,dir2;
            H2.movable_pos();
            draw();
            cout<<"enter direction1 "<<endl;
            cout<<"                     1 for right and increase 1 for each anti-clockwise possible move "<<endl;
            cin>>dir1;
            cout<<"enter direction2 "<<endl;
            cout<<"                     -1 for left of the direction-1 , 1 for right of the direction-1  "<<endl;
            cin>>dir2;
            H2.move(dir1,dir2);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="r1")
    {
        if(R1.get_status())
        {
            int dir,step;
            R1.movable_pos();
            draw();
            cout<<"enter direction "<<endl;
            cout<<"                     1 for right and increase 1 for each anti-clockwise possible move "<<endl;
            cin>>dir;
            cout<<"enter steps"<<endl;
            cin>>step;
            R1.move(dir,step);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="r2")
    {
        if(R2.get_status())
        {
            int dir,step;
            R2.movable_pos();
            draw();
            cout<<"enter direction "<<endl;
            cout<<"                     1 for right and increase 1 for each anti-clockwise possible move"<<endl;
            cin>>dir;
            cout<<"enter steps"<<endl;
            cin>>step;
            R2.move(dir,step);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="q")
    {
        if(Q.get_status())
        {
            Q.movable_pos();
            draw();
            cout<<"enter direction "<<endl;
            cout<<"                     1 for right and increase 1 for each anti-clockwise possible move"<<endl;
            cin>>dir;
            cout<<"enter steps "<<endl;
            cin>>step;
            Q.move(dir,step);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
    if(ele=="k")
    {
        if(K.get_status())
        {
            int dir;
            K.movable_pos();
            draw();
            cout<<"enter direction "<<endl;
            cout<<"                     1 for right and increase 1 for each anti-clockwise possible move "<<endl;
            cin>>dir;
            K.move(dir);
        }else { cout<<" wrong choic "<<endl;quality=true;}
    }
}
void design()  //this function give values to the pos array and i want to remove it 
{
    int i,j;
    for(i=0;i<=8;i++)
    {
        pos[i][0]=false;
        pos[0][i]=false;
    }
    for(i=1;i<=8;i++)
    {
        for(j=1;j<=8;j++)
        {  
            if(ar[i][j]==' ')
            {
                pos[i][j]=true;
            }
            else
            {
                pos[i][j]=false;
            }
        }
    }
}
void initialise() // this function set pieses in starting position
{
    p1.i=7;p1.j=1;p2.i=7; p2.j=2;p3.i=7;p3.j=3;p4.i=7;    p4.j=4;    p5.i=7;p5.j=5;p6.i=7;    p6.j=6;    
    p7.i=7;    p7.j=7;p8.i=7;p8.j=8;r1.i=8;r1.j=1;r2.i=8;r2.j=8;h1.i=8;h1.j=2;h2.i=8;h2.j=7;
    b1.i=8;b1.j=3;b2.i=8;b2.j=6;k.i=8;k.j=4;q.i=8;q.j=5;
    
    P1.i=2;P1.j=1;P2.i=2;P2.j=2;P3.i=2;P3.j=3;P4.i=2;P4.j=4;P5.i=2;P5.j=5;P6.i=2;  P6.j=6;    
    P7.i=2;    P7.j=7;P8.i=2;P8.j=8;R1.i=1;R1.j=1;R2.i=1;R2.j=8;H1.i=1;H1.j=2;H2.i=1;H2.j=7;
    B1.i=1;B1.j=3;B2.i=1;B2.j=6;K.i=1;K.j=4;Q.i=1;Q.j=5;
}
void setup() // this function can implement new position of element and i want to remove this functon too
{
    int i,j;
    for(i=1;i<=8;i++)
    {
        for(j=1;j<=8;j++)
        {
            if(i==p1.i&&j==p1.j&&p1.get_status())
            {
                ar[i][j]='p';
            }
            else if(i==p2.i&&j==p2.j&&p2.get_status())
            {
                ar[i][j]='p';
            }
            else if(i==p3.i&&j==p3.j&&p3.get_status())
            {
                ar[i][j]='p';
            }
            else if(i==p4.i&&j==p4.j&&p4.get_status())
            {
                ar[i][j]='p';
            }
            else if(i==p5.i&&j==p5.j&&p5.get_status())
            {
                ar[i][j]='p';
            }
            else if(i==p6.i&&j==p6.j&&p6.get_status())
            {
                ar[i][j]='p';
            }
            else if(i==p7.i&&j==p7.j&&p7.get_status())
            {
                ar[i][j]='p';
            }
            else if(i==p8.i&&j==p8.j&&p8.get_status())
            {
                ar[i][j]='p';
            }
            else if(i==h1.i&&j==h1.j&&h1.get_status())
            {
                ar[i][j]='h';
            }
            else if(i==h2.i&&j==h2.j&&h2.get_status())
            {
                ar[i][j]='h';
            }
            else if(i==b1.i&&j==b1.j&&b1.get_status())
            {
                ar[i][j]='b';
            }
            else if(i==b2.i&&j==b2.j&&b2.get_status())
            {
                ar[i][j]='b';
            }
            else if(i==r1.i&&j==r1.j&&r1.get_status())
            {
                ar[i][j]='r';
            }
            else if(i==r2.i&&j==r2.j&&r2.get_status())
            {
                ar[i][j]='r';
            }
            else if(i==k.i&&j==k.j&&k.get_status())
            {
                ar[i][j]='k';
            }
            else if(i==q.i&&j==q.j&&q.get_status())
            {
                ar[i][j]='q';
            }
            else if(i==P1.i&&j==P1.j&&P1.get_status())
            {
                ar[i][j]='P';
            }
            else if(i==P2.i&&j==P2.j&&P2.get_status())
            {
                ar[i][j]='P';
            }
            else if(i==P3.i&&j==P3.j&&P3.get_status())
            {
                ar[i][j]='P';
            }
            else if(i==P4.i&&j==P4.j&&P4.get_status())
            {
                ar[i][j]='P';
            }
            else if(i==P5.i&&j==P5.j&&P5.get_status())
            {
                ar[i][j]='P';
            }
            else if(i==P6.i&&j==P6.j&&P6.get_status())
            {
                ar[i][j]='P';
            }
            else if(i==P7.i&&j==P7.j&&P7.get_status())
            {
                ar[i][j]='P';
            }
            else if(i==P8.i&&j==P8.j&&P8.get_status())
            {
                ar[i][j]='P';
            }
            else if(i==H1.i&&j==H1.j&&H1.get_status())
            {
                ar[i][j]='H';
            }
            else if(i==H2.i&&j==H2.j&&H2.get_status())
            {
                ar[i][j]='H';
            }
            else if(i==B1.i&&j==B1.j&&B1.get_status())
            {
                ar[i][j]='B';
            }
            else if(i==B2.i&&j==B2.j&&B2.get_status())
            {
                ar[i][j]='B';
            }
            else if(i==R1.i&&j==R1.j&&R1.get_status())
            {
                ar[i][j]='R';
            }
            else if(i==R2.i&&j==R2.j&&R2.get_status())
            {
                ar[i][j]='R';
            }
            else if(i==K.i&&j==K.j&&K.get_status())
            {
                ar[i][j]='K';
            }
            else if(i== Q.i&&j==Q.j&&Q.get_status())
            {
                ar[i][j]='Q';
            }
            else 
            {
                ar[i][j]=' ';
            }
        }
    }
}
void draw() // this is very important function in this game this function draws the chess boart after each moves
{
    cout<<"                                            WE ARE MAKING CHESS BETTER  ";
    cout<<endl<<endl<<endl<<endl;
    cout<<"   WHITE-SCORE  "<<score1<<endl;
    int i,j;
    for(i=1;i<=8;i++)
    {
        for(j=0;j<7;j++)
        {
            cout<<"      ";
        }
        for(j=1;j<=8;j++)
        {
            if(j==8)
            {
                cout<<"+---+";
            }
            else
            {
                cout<<"+---";
            }
        }
        cout<<endl;
        for(j=0;j<7;j++)
        {
            cout<<"      ";
        }
        for(j=1;j<=8;j++)
        {
            if(j==8)
            {
                cout<<"| "<<ar[i][j]<<" |";    
            }
            else
            {
                cout<<"| "<<ar[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    for(j=0;j<7;j++)
    {
        cout<<"      ";
    }
    for(j=1;j<=8;j++)
    {
        if(j==8)
        {
            cout<<"+---+";
        }
        else
        {
            cout<<"+---";
        }
    }
    cout<<endl;
    cout<<"  BLACK-SCORE  "<<score2;
    cout<<endl;
}
void lets_play()
{
    initialise();
    setup();
    draw();
    while(k.get_status()&&K.get_status())
    {
        while(quality)
        {
            quality=false;
            cout<<"    WHITE'S TURN "<<endl;
            design();
            playtime_white();
            setup();
            draw();
        }
        quality=true;
        while(quality)
        {
            quality=false;
            cout<<"     BLACK'S TURN "<<endl;
            design();
            playtime_black();
            setup();
            draw();
         }
        quality=true;
    }
    if(k.get_status())
    {
        cout<<"                   ------------------------BLACK WON !--------------------------   "<<endl;
    }
    else
    {
        cout<<"                   ------------------------WHITE WON !--------------------------  "<<endl;
    }
}
int main() //this is main function where programme begines
{
    lets_play();
    return 0;
}
