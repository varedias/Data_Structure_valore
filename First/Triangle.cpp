#include <iostream>
#include <math.h>
#include <fstream>
#define Log(X)  std::cout<<X<<std::endl;
struct TriangleVertex {
    double m_x ;
    double m_y ;
    TriangleVertex():m_x(0),m_y(0){}
};

struct Triangle{
    TriangleVertex m_Fir;
    TriangleVertex m_Sec;
    TriangleVertex m_thi;
};

struct TriangleType{
    bool equilateral ;
    bool isosceles;
    bool rightAngle;
    TriangleType():equilateral(false),isosceles(false),rightAngle(false){}

};

Triangle load(std::ifstream& in )
{
    Triangle triangles;
    for(int i=0;i<3;i++)
    {
        if(i==0){in>>triangles.m_Fir.m_x;in>>triangles.m_Fir.m_y;}
        if(i==1){in>>triangles.m_Sec.m_x;in>>triangles.m_Sec.m_y;}
        if(i==2){in>>triangles.m_thi.m_x;in>>triangles.m_thi.m_y;}
    }
    return triangles;
}

double CalEdge(TriangleVertex* v1, TriangleVertex* v2)
{
    return(sqrt(pow(v2->m_x - v1->m_x, 2) + pow(v2->m_y - v1->m_y, 2)));
}

TriangleType judge(double* EdgeSave)
{
    TriangleType type;
    double temp=EdgeSave[0],count=1,max=EdgeSave[0],sum=0;
    int maxloca=0;
    for(int i=1;i<3;i++)
    {
        if(temp==EdgeSave[i]) count++;
        if(EdgeSave[i]>max){max=EdgeSave[i];maxloca=i;}
    }
    if(count==2)type.isosceles=true;
    if(count==3){type.isosceles=true;type.equilateral=true;}
    for(int i=0;i<3;i++)
    {
        if(i!=maxloca)sum+=pow(EdgeSave[i],2);
    }
    if(pow(EdgeSave[maxloca],2)==sum)
    type.rightAngle=true;
    return type;
}


double CompuArea(double* EdgeSave)
{
    double p=0;
    for (int i=0;i<3;i++)p+=EdgeSave[i];
    p=p/2;
    return sqrt(p*(p-EdgeSave[0])*(p-EdgeSave[1])*(p-EdgeSave[2]));
   
}

bool JudgeInside(Triangle* tri,TriangleVertex* v1,double  *EdgeSave)
{
    double temp,tempArea=0;
    temp = CompuArea(EdgeSave);
    double NewEdgeSave[3];
    NewEdgeSave[0]=CalEdge(&(tri->m_Fir),v1);
    NewEdgeSave[1]=CalEdge(&(tri->m_Sec),v1);
    NewEdgeSave[2]=CalEdge(&(tri->m_thi),v1);
    double tempEdgeSave[3]={EdgeSave[0],NewEdgeSave[0],NewEdgeSave[1]};
    tempArea+=CompuArea(tempEdgeSave);
    tempEdgeSave[0]=EdgeSave[1];
    tempEdgeSave[2]=NewEdgeSave[2];
    tempArea+=CompuArea(tempEdgeSave);
    tempEdgeSave[0]=EdgeSave[2];
    tempEdgeSave[1]=NewEdgeSave[1];
    tempArea+=CompuArea(tempEdgeSave);
    double epison = 1e-6;
    if(abs(tempArea-temp)<epison)
    return true;
    return false;
}

bool isValidTriangle(double* EdgeSave) {
    return (EdgeSave[0] + EdgeSave[1] > EdgeSave[2]) &&
           (EdgeSave[0] + EdgeSave[2] > EdgeSave[1]) &&
           (EdgeSave[1] + EdgeSave[2] > EdgeSave[0]);
}


int main()
{
    Triangle tri;
    TriangleType type;
    TriangleVertex Mor;
    Mor.m_x=3.0;
    Mor.m_y=4.0;
    double EdgeSave[3];
    std::ifstream in ("inputfile.txt");
    tri = load(in);
    EdgeSave[0]=CalEdge(&tri.m_Fir,&tri.m_Sec);
    EdgeSave[1]=CalEdge(&tri.m_Fir,&tri.m_thi);
    EdgeSave[2]=CalEdge(&tri.m_Sec,&tri.m_thi);

    if (!isValidTriangle(EdgeSave)) {
        Log("this is no valid triangle");
        return 1;
    }

    type = judge(EdgeSave);
    Log("the area of that triangle is :");
    Log(CompuArea(EdgeSave));
    Log("type is : ")
    if(type.equilateral==true){Log("equilateral triangle");}
    if(type.isosceles==true){Log("isosceles triangle");}
    if(type.rightAngle==true){Log("rightAngle triangle");}
    
     if(JudgeInside(&tri,&Mor,EdgeSave)==true){Log("the site is inside the triangle");}
     else Log("the side is not inside the triangle");
 
}


