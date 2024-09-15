#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <windows.h>
#define s 12.0
                                    //
                          typedef int I; typedef
                    double P;using namespace std;const
                  I S=s*3;I d[S][S][S]={0};I rd[S][S][S]
              ={0};char c[]="@$#*!=;:~-,.";char get_char(I x
            ,I y,I z){I h[3][3];I D=0;for(I i=x-1; i<=x+1;++i)
          {for(I k=z-1; k<=z+1;++k){I j=y;while(rd[i][j][k]==1&&
        j>0)j--;while(rd[i][j][k]==0&&j<S-1)j++;j--;D+=j-y;h[i-x+1
        ][k-z+1]=abs(y-j);}}I nx=(h[1][0]-h[1][2])/2,ny=(h[1][0]-h
      [1][2])/2,normal_z=1;P slope=atan(sqrt(nx*nx+ny*ny));P depth=(
    cos(slope)+1)/2;I char_index=max(0.0,min((P)strlen(c)-1,strlen(c)*
    (1-depth)));return c[char_index];}P x_angle=M_PI/4,y_angle=M_PI/4;
    I normalize(I x){return round(x+S/2.0);}void rotate(){P cos_y=cos(
  y_angle),sin_y=sin(y_angle);P cos_x =cos(-x_angle),sin_x=sin(-x_angle)
  ;for(I x=0; x<S;++x)for(I y=              0; y<S;++y)for(I z=0; z<S;++
  z)rd[x][y][z]=0;for(I x=0;                  x<S;++x){P abs_x=x-S/ 2.0;
  for(I y=0;y<S;++y){P abs_y                  =y-S/2.0;for(I z=S-1; z>=0
  ;--z) {if(d[x] [y] [z]==0)                  continue;P abs_z=z-S/2.0;I
 new_x= abs_x*cos_y+abs_z*                      sin_y,new_z=-abs_x* sin_y+
  abs_z*cos_y;I new_y=-new_z                  *sin_x+abs_y*cos_x,final_z
  =abs_y*sin_x+new_z *cos_x;                  rd [normalize ( new_x ) ][
  normalize(new_y)][normalize                 (final_z)]=1;}}} x_angle+=
  M_PI* 20.0/ 180.0; y_angle+=              M_PI* 7.0/180.0; if(x_angle>
  M_PI)x_angle-=M_PI; if(y_angle>M_PI  )y_angle -= M_PI; }I cs;I main(){
    ios::sync_with_stdio(false) ;I t=s*0.5;for(I x=-t; x<=t;++x){for(I
    y=-t; y<=t;++y){if(x*x+y*y>(s/2)*(s/2)) continue;P xc=x-s,yc=y;for
    (I i=0;i<3600;++i){P sin_=sin(M_PI*i/1800.0),cos_=cos(M_PI*i/1800)
      ;I rxc=cos_*xc,ryc=yc,rzc=-sin_*xc;rxc+=S*0.5;ryc+=S*0.5;rzc+=
        S*0.5;if(rxc>=0 && rxc<S && ryc>=0 && ryc<S && rzc>=0&&rzc
        <S)d[rxc] [rzc] [ryc]=1; } } } while(true){rotate();string
          repeatedString(25,'\n');cout<<repeatedString;for(I y=0
            ; y<S;++y){for(I x=0; x<S;++x){I z;for(z=S;z>=0;--
              z)if(rd[x][y][z] != 0){cout << get_char(x,y,z)
                  ;break;}cout<<' '; if(z ==-1)cout<<' ';}
                    cout<<'\n'; }cout<<flush;Sleep(150);
                          }}/*--------------------
                                    */
