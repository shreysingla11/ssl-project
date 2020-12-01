#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>


using namespace std;

vector<int> v;

vector<vector <int> > cost_array;

struct for_the_queue
{
    int g;
    int no;

};

queue<for_the_queue> q;

struct node
{
    int num;
    vector <int> cost_label;
    vector <bool> check_if_good;

    node (int n)
    {
        cost_label.resize(4*n+1, INFINITY);
        check_if_good.resize(4*n+1, false);
    }
};

vector<node> temp_node;

int main()
{

    int n;
    scanf("%d", &n);
    v.resize(n,0);
    cost_array.resize(n, v);

    int it=0;
    while(it!=n)
    {
        for (int j=0; j<n; j++)
        {
            scanf("%d", &cost_array[it][j]);
        }
        it++;
    }

    node temp1(n);
    temp1.num = 0;
    temp_node.resize(n, temp1);
    for(int i=0; i<n; i++)
    {
        temp_node[i].num = i;
    }

    for_the_queue elem, front_element;
    elem.no = 0;
    elem.g = 2*n;
    temp_node[0].check_if_good[2*n] = true;
    temp_node[0].cost_label[2*n] = 0;
    q.push(elem);


    while (!q.empty())
    {

        front_element = q.front();
        q.pop();
        int i=0;
        while(i<n)
        {
            if (cost_array[front_element.no][i] < 0)
            {
                if (temp_node[front_element.no].cost_label[front_element.g] - cost_array[front_element.no][i] < temp_node[i].cost_label[front_element.g+1] && front_element.g+1<=4*n)
                {
                    temp_node[i].cost_label[front_element.g+1] = temp_node[front_element.no].cost_label[front_element.g] - cost_array[front_element.no][i];
                    if (temp_node[i].check_if_good[front_element.g+1] != true )
                    {
                        temp_node[i].check_if_good[front_element.g+1] = true;
                        elem.no = i;
                        elem.g = front_element.g+1;
                        q.push(elem);
                    }
                }
            }
            vector<int>::iterator it;
            if (cost_array[front_element.no][i] > 0)
            {
                if (temp_node[front_element.no].cost_label[front_element.g] + cost_array[front_element.no][i] < temp_node[i].cost_label[front_element.g-1] && front_element.g -1 >=0)
                {
                    temp_node[i].cost_label[front_element.g -1] = temp_node[front_element.no].cost_label[front_element.g] + cost_array[front_element.no][i];
                    if (temp_node[i].check_if_good[front_element.g - 1] != true)
                    {
                        temp_node[i].check_if_good[front_element.g - 1] = true;
                        elem.no = i;
                        elem.g = front_element.g -1;
                        q.push(elem);
                    }
                }
            }
            i++;
        }
        temp_node[front_element.no].check_if_good[front_element.g] = false;

    }

    for (int i=0; i<n; i++)
    {
        int mini = INFINITY;
        for (int j = 2*n; j<4*n+1; j++)
        {
            mini = min(mini, temp_node[i].cost_label[j]);
        }
        if (mini >= 900000000)
        {
            printf("infinity\n");
        }
        else
            printf("%d\n", mini);
    }

}
