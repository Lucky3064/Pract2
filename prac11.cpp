/*a) Write C++ program to draw 2-D object and perform following basic 
transformations, Scaling, Translation c) Rotation. Apply the concept of
operator overloading.
OR
b) Write C++ program to implement translation, rotation and scaling
transformations onequilateral triangle and rhombus. Apply the concept of
operator overloading.*/

#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class transform
{
      int m, a[20][20], c[20][20];
      int i, j, k;
      public:
      void Object();
      void Accept();
      void operator *(float b[20][20]) // matrix multiplication
      {
            for(int i = 0; i<m; i++)
            {
                  for(int j = 0; j<m; j++)
                  {
                       c[i][j] += a[i][k]*b[k][j];
                  }
            }
      }
};

void transform::Object()
{
      int gd,gm;
      gd = DETECT;
      initgraph(&gd,&gm,NULL);
      line(300,0,300,600); //Vertical line
      line(0,300,600,300); //Horizontal line
     
      for(int i = 0; i<m-1; i++)
      {
            line(300+a[i][0],300-a[i][1],300+a[i+1][0],300-a[i+1][1]);
      }
      line(300+a[0][0],300-a[0][1],300+a[i][0],300-a[i][1]);

      for(int i = 0; i<m-1; i++)
      {
            line(300+c[i][0],300-c[i][1],300+c[i+1][0],300-c[i+1][1]);
      }
      line(300+a[0][0],300-a[0][1],300+a[i][0],300-a[i][1]);

      int temp;
      cout<<"Press 1 for continue: ";
      cin>>temp;
      closegraph();
}

void transform::Accept()
{
      cout<<"\n";
      cout<<"Enter the number of edges: ";
      cin>>m;
      cout<<"Enter the Co-ordinates: ";

      for(int i = 0; i<m; i++)
      {
            for(int j = 0; j<m; j++)
            {
                  if(j>=2) a[i][j] = 1;
                  else cin>>a[i][j];
            }
      }
}


int main()
{
      int gd = DETECT, v, gm;
      initgraph(&gd, &gm, NULL);
      int ch, tx, ty, sx, sy;
      float deg, theta, b[20][20];
      transform t;
      t.Accept();

      cout<<"\nEnter your choise: ";
      cout<<"\n1) Translation \n2) Scaling \n3) Rotation";
      cin>>ch;
      switch(ch)
      {
            case 1:
                  cout<<"Translation Operation"<<endl;
                  cout<<"Enter the value of tx and ty: ";
                  cin>>tx>>ty;
                  b[0][0] = b[2][2] = b[1][1] = 1;
                  b[0][1] = b[0][2] = b[1][0] = b[1][2] = 0;
                  b[2][0] = tx;
                  b[2][1] = ty;
                  t*b;
                  t.Object();
                  break;

            case 2:
                  cout<<"\nScaling Operation";
                  cout<<"Enter the value of sx, sy: ";
                  cin>>sx>>sy;
                  b[0][0] = sx;
                  b[1][1] = sy;
                  b[0][1] = b[0][2] = b[1][0] = b[1][2] = b[2][0] = b[2][2] = 0;
                  b[2][2] = 1;
                  t*b;
                  t.Object();
                  break;
            case 3:
                  cout<<"\nRotation Operation"<<endl;
                  cout<<"Enter the value for angle: ";
                  cin>>deg;
                  theta = deg*(3.14/180);
                  b[0][0] = b[1][1] = cos(theta);
                  b[0][1] = sin(theta);
                  b[1][0] = sin(-theta);
                  b[0][2] = b[1][2] = b[2][0] = b[2][1] = 0;
                  b[2][2] = 1;
                  t*b;
                  t.Object();
                  break;
            default:
                  cout<<"Invalid choise";
      }
     
      getch();
      return 0;
}