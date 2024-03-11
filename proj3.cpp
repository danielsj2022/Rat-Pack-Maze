#include <iostream>
#include "Stack.h"
using namespace std;
using namespace cop4530;

void reConvert(int val, int &r, int &c);
int convert(int r, int c);
void reduce(int &val,int &ct);
void intBi(int val, int &fal, bool &nor, bool &east, bool &south, bool &west);
int main(){
   int sizer, sizec, startr, startc, goalr, goalc;
   bool N=false, E=false, S=false, W=false;
   cin>>sizer;
   cin>>sizec;
   int arr2d[sizer][sizec];
   for(int i=0;i<sizer;i++)
   {
      for(int j=0;j<sizec;j++)
      {
	 cin>>arr2d[i][j];
      }
   }
   cin>>startr;
   cin>>startc;
   cin>>goalr;
   cin>>goalc;

   int wallc=0, wallr=0;
   int prer=0, prec=0;
   while(prer!=sizer && prec!=goalc)  //find vert wall
   {
      int dud=4;
      intBi(arr2d[prer][prec], dud, N, E, S, W);
      if(E==true)
      {
	 wallc++;
	 prer++;
      }
      else
      {
	 prer=0;
	 prec++;
	 wallc=0;
      }
      N=false;
      E=false;
      S=false;
      W=false;
   }
   if(wallc!=sizer){
   
   prer=0;
   prec=0;
   while(prer!=goalr && prec!=startc)  //find horz wall
   {
      int dud=4;
      intBi(arr2d[prer][prec], dud, N, E, S, W);
      if(S==true)             
      {
         wallr++;         
         prec++;
      }
      else     
      {        
         prec=0;
         prer++;
         wallr=0;
      }                 
      N=false;        
      E=false;
      S=false;
      W=false;
   }
   }
   
   if(wallc==sizer || wallr==sizec)
      cout<<"Abort can't access goal"<<endl;
   else{
   Stack<int> stac;
   while(startr!=goalr || startc!=goalc)
   {
      int num, mark=0, numfal=4, skips, round, loc, rand;
      char direc;
      int str=startr, stc=startc;  //current coord
      
      rand=arr2d[str][stc];
      reduce(arr2d[startr][startc], mark);   //brings back to OG value counting num times
//move push here
      num=arr2d[startr][startc];
      intBi(num, numfal, N, E, S, W);
      
      skips=mark%numfal;      //
      if(skips==0)
	 round=0;
      else 
         round=numfal-skips;   //num times need to rotate direction to go
      for(int i=0; i<round+1;i++)   //finds direction need to go 
      {
	 if(N==false){
	    direc='n';
	    N=true;
	 }
	 else if(E==false){
	    direc='e';
	    E=true;
	 }
	 else if(S==false){
	    direc='s';
	    S=true;
	 }
	 else if(W==false){
	    direc='w';
	    W=true;
	 }
      }
//we have needed direc 
//if statement for direc
//change start val
      
      if(direc=='n')   //change coord to new coord
         startr--;
      else if(direc=='e')
         startc++;
      else if(direc=='s')
         startr++;
      else if(direc=='w')
         startc--;

      arr2d[str][stc]=rand;   //value incr
      arr2d[str][stc]+=16;   //last step, value thats pushed
      if(stac.empty()){
      loc=convert(str, stc);
      stac.push(loc);
      }
      else
      {
	 if(convert(startr, startc)==stac.top())   //if next=top
         {
	    stac.pop();   //remove top
         }
	 else
	    stac.push(convert(str, stc));
      }//else
      N=false;
      E=false;
      S=false;
      W=false;   
   }

   stac.push(convert(startr, startc));
   Stack<int> invert;
   int tran, nr, nc;
   while(stac.empty()==false){
      tran=stac.top();
      stac.pop();
      invert.push(tran);
      //reConvert(tran, nr, nc);
   }
   while(invert.empty()==false){
      tran=invert.top();
      invert.pop();
      reConvert(tran, nr, nc);
      cout<<"("<<nr<<", "<<nc<<")"<<endl;
   }
   
   }//else
}//main
void reConvert(int val, int &r, int &c)
{
   r=val/10;
   c=val%10;
}
int convert(int r, int c)
{
   return ((r*10)+c);
}
void reduce(int &val,int &ct)
{
   while(val>15)
   {
      val-=16;
      ct++;
   }
}
void intBi(int val,int &fal, bool &nor, bool &east, bool &south, bool &west)
{//breaks int into binary parts
//false means its a valid move
      if(val>=8){
	 val-=8;
	 west=true;
	 fal--;
      }
      if(val>=4){
	 val-=4;
	 south=true;
	 fal--;
      }
      if(val>=2){
	 val-=2;
	 east=true;
	 fal--;
      }
      if(val>=1){
	 val-=1;
	 nor=true;
	 fal--;
      }
}
