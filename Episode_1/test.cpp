#include <iostream>
/*
基础训练，排序
刘华强12303010232
*/
 void swap(int & fir,int & sec)
 {
     int temp;
     temp=fir;
     fir=sec;
     sec=temp;
 }
 void SortHighToLow(int &fir,int &sec,int &third)
 {
     if((third-fir)>0)
     {swap(third,fir);if((fir-sec)<0)swap(sec,fir);if((third-sec)>0)swap(third,sec);}
     else
     {if((sec-fir)>0)swap(sec,fir);if((third-sec)>0)swap(third,sec);}
     std::cout<<"frist:"<<fir<<"second:"<<sec<<"third:"<<third<<std::endl;
 }


 int main()
 {
     int fir =3;
     int sec =-15;
     int third =20 ;
     SortHighToLow(fir,sec,third);
     return 0;
 }