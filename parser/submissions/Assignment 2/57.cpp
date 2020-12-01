#include<iostream>
#include<vector>
using namespace std;
int cnt = 0;
struct Point
{
    int x, y;
    int index;
    public:
    Point()
    {
        x = y = 0;
    }
    Point(int a, int b, int ind)
    {
        x = a;
        y = b;
        index = ind;
    }
};
int computeIntersection(Point comp, Point first, Point second)
{
    long long res = (long long)(comp.y-first.y)*(second.x-first.x) - (second.y-first.y)*(comp.x-first.x);
    if (res < 0)
    {
        return -1;
    }
    else if (res > 0)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
int noOfPositiveReds(vector<Point> &red, vector<Point> &newReds, Point first, Point second)
{
    vector<Point> :: iterator it;
    int count = 0;
    for (it = red.begin(); it != red.end(); ++it)
    {
        // cout<<first.x<<" "<<first.y<<endl;
        // cout<<second.x<<" "<<second.y<<endl;
        if (computeIntersection(*it, first, second) == 1)
        {
            newReds.push_back(*it);
            ++count;
        }
    }
    return count;
}
int noOfNegativeBlues(vector<Point> &blue, vector<Point> &newBlues, Point first, Point second)
{
    vector<Point> :: iterator it;
    int count = 0;
    for (it = blue.begin(); it != blue.end(); ++it)
    {
        if (computeIntersection(*it, first, second) == -1)
        {
            newBlues.push_back(*it);
            ++count;
        }
    }
    return count;
}
int noOfPositiveBlues(vector<Point> &blue, vector<Point> &newBlues, Point first, Point second)
{
    vector<Point> :: iterator it;
    int count = 0;
    for (it = blue.begin(); it != blue.end(); ++it)
    {
        if (computeIntersection(*it, first, second) == 1)
        {
            newBlues.push_back(*it);
            ++count;
        }
    }
    return count;
}
int noOfNegativeReds(vector<Point> &red, vector<Point> &newReds, Point first, Point second)
{
    vector<Point> :: iterator it;
    int count = 0;
    for (it = red.begin(); it != red.end(); ++it)
    {
        if (computeIntersection(*it, first, second) == -1)
        {
            newReds.push_back(*it);
            ++count;
        }
    }
    return count;
}
void computePairing(vector<Point> &red, vector<Point> &blue, vector<int> &res)
{
    if (red.empty() || blue.empty())
    {
        return;
    }
    vector<Point> :: iterator it1 = red.begin();
    vector<Point> :: iterator it2 = blue.begin();
    if (red.size() == 1)
    {
        res[((*it1).index)] = ((*it2).index);
    }
    vector<Point> newRedsP;
    vector<Point> newBluesP;
    vector<Point> newRedsN;
    vector<Point> newBluesN;
    int flag = 0;
    for (; it2 != blue.end(); ++it2)
    {
        newRedsP.clear();
        newBluesP.clear();
        newRedsN.clear();
        newBluesN.clear();
        if (noOfPositiveReds(red, newRedsP, *it1, *it2) == noOfPositiveBlues(blue, newBluesP, *it1, *it2))
        {
            if (noOfNegativeReds(red, newRedsN, *it1, *it2) == noOfNegativeBlues(blue, newBluesN, *it1, *it2))
            {
                ++flag;
                res[((*it1).index)] = ((*it2).index);
                ++cnt;
                break;
            }
        }
    }
    if (flag == 0)
    {
        vector<Point> :: iterator it3 = red.begin();
        ++it3;
        for (; it3 != red.end(); ++it3)
        {
            newRedsP.clear();
            newBluesP.clear();
            newRedsN.clear();
            newBluesN.clear();
            if (noOfPositiveReds(red, newRedsP, *it1, *it3) == noOfPositiveBlues(blue, newBluesP, *it1, *it3))
            {
               newRedsN.push_back(*it1);
               newRedsN.push_back(*it3);
               break;
            }
            if (noOfNegativeReds(red, newRedsN, *it1, *it3) == noOfNegativeBlues(blue, newBluesN, *it1, *it3))
            {
               newRedsP.push_back(*it1);
               newRedsP.push_back(*it3);
               break;
            }
        }
    }
    computePairing(newRedsP, newBluesP, res);
    computePairing(newRedsN, newBluesN, res);
}
int main()
{
    vector<Point> red, blue;
    vector<int> res(5000);
    vector<Point> :: iterator it;
    vector<int> :: iterator it2;
    int i, N, x, y;
    cin >> N;
    for (i = 0; i < N/2; ++i)
    {
        cin >> x >> y;
        red.push_back(Point(x, y, i));
    }
    for (i = 0; i < N/2; ++i)
    {
        cin >> x >> y;
        blue.push_back(Point(x, y, i));
    }
    computePairing(red, blue, res);
    for (i = 0; i < cnt; ++i)
    {
        cout<<i<<" "<<res[i]<<endl;
    }
    return 0;
}
