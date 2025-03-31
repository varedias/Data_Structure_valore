#include <iostream>
/*3进阶训练1 复数的运算以及输出
刘华强 12303010232
*/

struct complex{
    int exist;
    int virtuals;
    complex(){}
    complex(int a,int b):exist(a),virtuals(b){}
};

std::ostream& operator<<(std::ostream& os ,complex v)
{
    os<<"exist:"<<v.exist<<"   virtual: "<<v.virtuals<<std::endl;
    return os;
}


complex ComplexSum(complex& com1,complex& com2)
{
    complex comSum;
    comSum.exist=com1.exist+com2.exist;
    comSum.virtuals =com1.virtuals+com2.virtuals;
    return comSum;
}

complex ComplexSub(complex& com1,complex& com2)
{
    complex comSub;
    comSub.exist=com1.exist-com2.exist;
    comSub.virtuals =com1.virtuals-com2.virtuals;
    return comSub;
}


complex ComplexMul(complex& com1,complex& com2)
{
    complex comMul;
    comMul.exist=com1.exist*com2.exist+(-(com1.virtuals*com2.virtuals));
    comMul.virtuals=com1.exist*com2.virtuals+com1.virtuals*com2.exist;
    return  comMul;
}

int ApartExsit(complex& com)
{
    return com.exist;
}

int ApartVirtuals(complex& com)
{
    return com.virtuals;
}


int main()
{
    complex com1(1,1);
    complex com2(1,-1);
    std::cout<<ComplexSum(com1,com2)<<std::endl;
    std::cout<<ComplexSub(com1,com2)<<std::endl;
    std::cout<<ComplexSum(com1,com2)<<std::endl;
    std::cout<<ApartExsit(com1)<<std::endl;
    std::cout<<ApartVirtuals(com2)<<std::endl;
}