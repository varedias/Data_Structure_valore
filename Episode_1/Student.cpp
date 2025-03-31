#include <iostream>
/*
2 基础训练5 学生信息输出以及数据的计算  
刘华强 12303010232

*/
struct Student{
    long Number;
    char* name;
    int Course1;
    int Cousre2;
    int Cousre3;
    Student():Number(123030102),name("coke"),Course1(100),Cousre2(50),Cousre3(40){}
};

std::ostream& operator<<(std::ostream&os,const Student& v)
{
    os<<"number: "<<v.Number<<" name "<<v.name<<" course1 "<<v.Course1<<" course2 "<<v.Cousre2<<" course3 "<<v.Cousre3;
    return os;
}

void outPutall(Student& stu)
{
    std::cout<<stu<<std::endl;
}

float sum1(Student* stu,int n)
{
    int sum=0;
   for(int i=0;i<n;i++)
    sum+=stu[i].Course1;
    return sum/n;
}
float sum2(Student* stu, int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
     sum+=stu[i].Cousre2;
     return sum/n;

}

float sum3(Student* stu,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
     sum+=stu[i].Cousre3;
     return sum/n;

}


int locateMax1(Student* stu,int n)
{
    int max=stu[0].Course1;
    int maxLoca;
    for(int i=0;i<n;i++)
    {
        if(stu[i].Course1>max)
        {max=stu[i].Course1;
            maxLoca=i;
        }
    }
    return maxLoca;

}

int locateMax2(Student* stu,int n)
{
    int max=stu[0].Course1;
    int maxLoca;
    for(int i=0;i<n;i++)
    {
        if(stu[i].Course1>max)
        {max=stu[i].Cousre2;
            maxLoca=i;
        }
    }
    return maxLoca;

}

int locateMax3(Student* stu,int n)
{
    int max=stu[0].Course1;
    int maxLoca;
    for(int i=0;i<n;i++)
    {
        if(stu[i].Course1>max)
        {max=stu[i].Cousre3;
            maxLoca=i;
        }
    }
    return maxLoca;
}


int main()
{
    Student stu[2];
    stu[1].Number=123030103;
    stu[1].name="valore";
    stu[1].Course1=90;
    stu[1].Cousre2=89;
    stu[1].Cousre3=95;

    outPutall(stu[0]);
    outPutall(stu[1]);
    std::cout<<sum1(stu,2)<<std::endl;
    std::cout<<sum3(stu,2)<<std::endl;
    std::cout<<sum2(stu,2)<<std::endl;
    std::cout<<locateMax1(stu,2)<<std::endl;
    std::cout<<locateMax2(stu,2)<<std::endl;
    std::cout<<locateMax3(stu,2)<<std::endl;

}



