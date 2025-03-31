#include <iostream>
/*基础训练3 矩阵操作，使用了C++进行的编写并且使用了C++的特性
刘华强12303010232*/

struct Result {
    int NonZero;
    int Sum;
    Result() : NonZero(0), Sum(0) {}
};

template <int N>
Result NonZeroAndSum(int Row, int Column, int (*Arr)[N]) {
    Result res;  
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Column; j++) {
            if (Arr[i][j] != 0) {
                res.NonZero++;
                res.Sum+=Arr[i][j];
            }
        }
    }
    return res;
}
template <int M>
void ConverArr(int Row, int Column, int (*Arr)[M])
{
    int temp;
    for(int i=0;i<Row;i++)
        for(int j=i+1;j<Column;j++)
        {
            temp=Arr[i][j];
            Arr[i][j]=Arr[j][i];
            Arr[j][i]=temp;
        }
}

template<int N>
void Show(int Row, int Column, int (*Arr)[N])
{
    int count =0;
    for(int i=0;i<Row;i++)
        for(int j=0;j<Column;j++)
        {
            std::cout<<Arr[i][j];
            count++;
            if(count%3==0)
            std::cout<<" "<<std::endl;
        }
}


// int main()
// {
//     int test[3][3] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8} };
//     std::cout<<test[1][1]<<std::endl;
//     std::cout<<*(*(test+1)+1)<<std::endl;
//     auto res = NonZeroAndSum(3,3,test);
//     std::cout<<"the Nunbers of NO zero:"<< res.NonZero<<" the sum :"<<res.Sum<<std::endl;
//     ConverArr<3>(3,3,test);
//     Show<3>(3,3,test);
//     return 0;
// }
