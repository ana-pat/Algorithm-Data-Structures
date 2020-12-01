#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point Point;

struct Point{
    int x,y;
};

float min(float x, float y)
{
    if(x < y){
        return x;
    }
    else{
        return y;
    }

}

float dist(Point p1,Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}


float bruteForce(Point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

int comX(const void* a,const void* b)
{
     Point *p1 = ( Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int comY(const void* a,const void* b)
{
     Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}


float closestPair(Point* p,int n)
{
        if (n <= 3)
        {
            return bruteForce(p, n);
        }
    int m = n/2;
    Point midp = p[m];

    float dleft = closestPair(p,m);
    float dright = closestPair(p+m,n-m);

    float mind = min(dleft, dright);

    Point landr[n];
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(abs(p[i].x - midp.x) < mind)
        {
            landr[k] = p[i],k++;

        }
    }
    float q = mind;
    qsort(landr ,k,sizeof(Point),comY);

    for(int i=0;i<k;++i)
    {
        for(int j=i+1;j<k && (landr[j].y - landr[i].y)<q;++j)
        {
            if (dist(landr[i],landr[j]) < q)
            {
                q = dist(landr[i],landr[j]);
            }
        }
    }
    return min(mind,q);
}

float closest(Point p[],int n)
{
    qsort(p, n, sizeof(Point), comX);
    return closestPair(p,n);
}





int main()
{
    Point p[] = {{5, 6}, {19, 13}, {6, 2}, {2, 1}, {21, 34}, {2, 3}};
    float min = closest(p,6);
    printf("%f",min);
    return 0;
}

