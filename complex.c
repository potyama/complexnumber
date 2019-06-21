#include <stdio.h>
typedef struct com com;

struct com{
      double Re;
      double Im;
};
com Add_com(com x,com y);
com Sub_com(com x,com y);
com Mul_com(com x,com y);
com Div_com(com x,com y);
void show_com(char name[],com z);

com Add_com(com x,com y){

      com z;

      z.Re = x.Re + y.Re;
      z.Im = x.Im + y.Im;

      return z;
}

com Sub_com(com x,com y){
      com z;

      z.Re = x.Re - y.Re;
      z.Im = x.Im - y.Im;

      return z;
      
}


com Mul_com(com x,com y){
      com z;

      z.Re = x.Re * y.Re - x.Im * y.Im;
      z.Im = x.Re * y.Im + y.Re * x.Im;
      
      return z;
      
}
com Div_com(com x,com y){
      com z;

      z.Re = ((x.Re * y.Re) + (x.Im * y.Im))/(x.Re * x.Re) + (y.Re * y.Re);
      z.Im = (x.Re * y.Im) - (y.Re * x.Im)/(x.Re * x.Re) + (y.Re * y.Re);

      return z;
      
}
void show_com(char name[],com z){
      printf("%s = %3.1lf + %3.1lfi\n",name,z.Re,z.Im);
}
int main(){
      com x,y,z;

      x.Re = 3.0;
      x.Im = 2.0;

      y.Re = 5.0;
      y.Im = -6.0;

      show_com("x=",x);
      show_com("y=",y);
      z = Add_com(x, y);
      show_com("x + y",z);
      z = Sub_com(x,y);
      show_com("x - y",z);
      z = Mul_com(x,y);
      show_com("x * y",z);
      z = Div_com(x,y);
      show_com("x / y",z);
}
