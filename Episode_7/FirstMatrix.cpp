// #include <iostream>
// #include <vector>
// #define Log(x) std::cout<<x



// void printOut(std::vector<std::vector<int>>& Graphic)
// {
//     for(int i=0;i<Graphic.size();i++)
//     {
//         for(int j=0;j<Graphic[i].size();j++)
//         {
//             Log(Graphic[i][j]);
//         }
//         Log(" ");
//         std::cout<<std::endl;
//     }
// }

// int main()
// {
//     std::vector<std::vector<int>> Graphic(5, std::vector<int>(5, 0));
//     Graphic[0][1]=1;Graphic[1][0]=1;
//     Graphic[2][0]=1;Graphic[0][2]=1;
//     Graphic[1][2]=1;Graphic[2][1]=1;
//     Graphic[0][3]=1;Graphic[3][0]=1;
//     Graphic[2][3]=1;Graphic[3][2]=1;
//     Graphic[2][4]=1;Graphic[4][2]=1;
//     Graphic[1][4]=1;Graphic[4][1]=1;
//     printOut(Graphic);
// }