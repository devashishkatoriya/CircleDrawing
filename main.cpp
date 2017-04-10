//Program to draw a Circle using Bresenhem and DDA Algorithms.

/*
 * Created by Devashish Katoriya on 10-04-2017
 */

#include <math.h>
#include <iostream>
#include <graphics.h>

using namespace std;

void DDACircle(int xc,int yc,int r)
{
    int i;
    double start_x,start_y,x1,y1,x2,y2;
    double e;
    for(i=1;i<9;i++)
    {
        if(pow(2,i-1)<=r && r<pow(2,i))
        {
            e = pow(2,-i);
            break;
        }
    }
    start_x = 0;
    start_y = r;
    x1 = start_x;
    y1 = start_y;

    do
    {
        x2 = x1 + (e*y1);
        y2 = y1 - (e*x2);
        putpixel(xc+int(x2),yc+int(y2),WHITE);

        delay(7);
        x1 = x2;
        y1 = y2;
    }while((y1-start_y)<e || (start_x-x1)>e);
}

void BresenhemCircle(int xc,int yc,int r)
{
    int x,y;
    int d;
    d = 3 - (2*r);
    x = 0;
    y = r;
    do
    {
        putpixel(xc+x,yc+y,WHITE);
        putpixel(xc+x,yc-y,WHITE);
        putpixel(xc-x,yc+y,WHITE);
        putpixel(xc-x,yc-y,WHITE);

        putpixel(xc+y,yc+x,WHITE);
        putpixel(xc+y,yc-x,WHITE);
        putpixel(xc-y,yc+x,WHITE);
        putpixel(xc-y,yc-x,WHITE);
        delay(100);
        if(d<0)
        {
            d = d + (4 * x) + 6;
        }
        else
        {
            d = d + (4*(x-y)) + 10;
            y = y - 1;
        }
        x = x + 1;
    }while(x<y);
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    int ch,xc,yc,radius;

    cout<<"\nProgram to draw a Circle using Bresenhem and DDA Algorithms.";
    do
    {
        ch = 0;
        cout<<"\n\n-------------------------------------";
        cout<<"\n 1 for Bresenhem Circle";
        cout<<"\n 2 for DDA Circle";
        cout<<"\n 0  to Exit";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        cout<<"-------------------------------------\n";
        switch(ch)
        {
            case 1: cout<<"\nEnter Center and Radius :- \n";
                    cin>>xc>>yc>>radius;
                    BresenhemCircle(xc,yc,radius);
                    cout<<"\nCircle drawn Successfully!";
                    break;
            case 2: cout<<"\nEnter Center and Radius :- \n";
                    cin>>xc>>yc>>radius;
                    DDACircle(xc,yc,radius);
                    cout<<"\nCircle drawn Successfully!";
                    break;
            case 0: break;
            default:cout<<"\nInvalid Option!";
        }
    }while(ch!=0);

    closegraph();
    cout<<"\nThank you for using this program :) \n\n";
    return 0;
}