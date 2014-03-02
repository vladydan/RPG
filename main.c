#include<stdio.h>
#include<stdlib.h>
#include<time.h>




void my_putchar(char c){

  write(1,&c,1);
}
int main()
{
  srand(time(NULL));  
  int i ,j;
  int tailleMAX=20;
  int tailleMIN=10;
  int taillex =(rand()%(tailleMAX-tailleMIN+1))+tailleMIN;
  int tailley=(rand()%(tailleMAX-tailleMIN+1))+tailleMIN;
  char map[taillex][tailley];
  int MAX=taillex-1;
  int MIN=1;
  int tailletotal;
  int a,b;
  int MAXb=tailley-1;
  int MINb=1;
    for(i=0;i<taillex;i++){
      for(j=0;j<tailley;j++)

        {
	  map[i][j]='-';
	  map[0][j]='#';
	  map[i][0]='#';
	  map[i][tailley-1]='#';
	  map[taillex-1][j]='#';
	  
  
 	}
           
    }   
    tailletotal=taillex*tailley;
    tailletotal=tailletotal/3;
     i=0;
    while(i!=tailletotal){
            i++;
      a=(rand()%(MAX-MIN+1))+MIN;
      b=(rand()%(MAXb-MINb+1))+MINb;
      map[a][b]='#';
    }
    for(i=0;i<taillex;i++){
      for(j=0;j<tailley;j++){    
if(map[i][j]=='-'&&map[i-1][j]=='#'&&map[i][j-1]=='#'&&map[i+1][j]=='#'&&map[i][j+1]=='#'){
      map[i+1][j]='-';
 }
 if(map[i][j]=='C'&&map[i-1][j]=='#'&&map[i+1][j]=='#'&&map[i][j-1]=='#'||map[i][j+1]){
   map[i+1][j]=='-';
   map[1-1][j]=='-';
   map[i][j-1]=='-';
   map[i][j+1]=='-';
 }
}}
    a=(rand()%(MAX-MIN+1))+MIN;
    b=(rand()%(MAXb-MINb+1))+MINb;
    map[a][b]='C';
	for(i=0;i<taillex;i++){
	  for(j=0;j<tailley;j++)
	    {
	      my_putchar(map[i][j]);
              my_putstr("  ");	      
	    }
	  my_putstr("\n");
	}
	
	return 0;

      }
