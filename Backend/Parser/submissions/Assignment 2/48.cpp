    #include<iostream>
    #include<vector>
    using namespace std;
    class point
    {
    public:
        int x,y;
    };
    class line
    {
    public:
        point red,blue;

        double distance(point p)
        {
            double a,b,c;
            a=blue.y-red.y;
            b=red.x-blue.x;
            c=red.y*blue.x-red.x*blue.y;
            double dis=(a*p.x)+(b*p.y)+c;
            return dis;
        }
    };
    class correct
    {
    public:
        vector<int> redPoint;
        vector<int> bluePoint;
    };

    int main()
    {
        vector<line> a;
        vector<int> redX;
        vector<int> redY;
        vector<int> blueX;
        vector<int> blueY;
        int numberOfPoints;
        cin>>numberOfPoints;
        int n = numberOfPoints/2;
        int value=0;
        for(int i=0; i<n; i++)
        {
            cin>>value;
            redX.push_back(value);

            cin>>value;
            redY.push_back(value);
        }
        for(int i=0; i<n; i++)
        {
            cin>>value;
            blueX.push_back(value);

            cin>>value;
            blueY.push_back(value);
        }
        correct answer;
        int m=0;
        a[0].red.x=redX[0];
        a[0].red.y=redY[0];
        a[0].blue.x=blueX[0];
        a[0].blue.y=blueY[0];
        answer.redPoint.push_back(0);
        answer.bluePoint.push_back(0);
        m=1;
        for(int i=1; i<n; i++)
        {
            a[m].red.x=redX[i];
            a[m].red.y=redY[i];
            for(int j=1; j<n; j++)
            {
                point Red,Blue;
                Red.x=redX[j];
                Red.y=redY[j];
                Blue.x=blueX[j];
                Blue.y=blueY[j];
                bool t=true;
                for(int k=0; k<m; k++)
                {
                    if(((a[k].distance(Red))*(a[k].distance(Blue)))<=0)
                    {
                        t=false;
                        break;
                    }
                }
                if(t=true)
                {
                    a[m].blue.x=blueX[j];
                    a[m].blue.y=blueY[j];
                    answer.redPoint.push_back(i);
                    answer.bluePoint.push_back(j);
                    m++;
                    break;
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            cout<<answer.redPoint[i]<<" "<<answer.bluePoint[i]<<endl;
        }
        return 0;
    }
