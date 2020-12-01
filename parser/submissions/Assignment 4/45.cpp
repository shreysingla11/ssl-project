class counter
{
    int n;
    list<list<pair<int,int> >*>ranker;
    list<list<pair<int,int> >*>::iterator it,zero;
    vector<list<list<pair<int,int> >*>::iterator> page;
    int rank;
public:
    counter()
    {
        cin>>n;
        list<pair<int,int> >* new_list = new list<pair<int,int> >;
        ranker.push_back(new_list);
        zero = ranker.begin();
        for(int i=0; i<n; i++)
        {
            new_list->push_back(make_pair(0,(i+1)));
            page.push_back(ranker.begin());
        }

    }
    void increment(int);
    void decrement(int);
    void reset(int);
    int count(int);
    int findMax();
    int numMax();
    void printMax();
};
void counter::increment(int i)
{
    rank = ((*page[i])->begin())->first;
    ++rank;
    //temporary iterator
    it = page[i];
    ++page[i];
    //deleting exactly one element in the list
    (*it)->pop_back();
    //deleting the list<int> for that particular ranker
    if((*it)->empty())
    {
        list<pair<int,int> >* del_list = *it;
        delete del_list;
        ranker.erase(it);
    }
    else
    {
        //do nothing
    }
    //carry on to increment the ranker of the page
    //if the next ranker list exists
    //if the next ranker list does not exist
    if(page[i] == ranker.end() || ((*page[i])->begin())->first != rank)
    {
        cout<<"no\n";
        it = page[i];
        it++;
        list<pair<int,int> >* new_list = new list<pair<int,int> >;
        new_list->push_back(make_pair(rank,1));
        //insert this list in the list of lists according to the ranker value
        ranker.insert(it,new_list);
        page[i] = --it;
    }
    else
    {
        cout<<"yes \n";
        int num = (--(*page[i])->end())->second+1;
        (*page[i])->push_back(make_pair(rank,num));
    }
}
void counter::decrement(int i)
{
    //calculating the frequency of the page
    rank = ((*page[i])->begin())->first;
    if(rank == 0)
    {
        rank -= 1;
        //temporary iterator
        it = page[i];
        --page[i];
        //here all elements are equivalent, so deleting any element in the list is ok
        (*it)->pop_back();
        //if the list becomes empty delete the list in the list of lists
        if((*it)->empty())
        {
            //do nothing
        }
        else
        {
            //do nothing
        }
        //carry on to decrement the rank of the page
        //if the decremented rank exists then push_back
        if((*page[i]) == NULL || ((*page[i])->begin())->first != rank)
        {
            it=page[i];
            list<pair<int,int> >* new_list = new list<pair<int,int> >;
            new_list->push_back(make_pair(rank,1));
            //insert this list in the list of lists according to the value of the ranker
            ranker.insert(it,new_list);
            page[i] = --it;
        }
        else
        {
            int num = (--(*page[i])->end())->second+1;
            (*page[i])->push_back(make_pair(rank,num));
        }
    }
    else
    {
        rank -= 1;
        //temporary iterator
        it = page[i];
        --page[i];
        //here all elements are equivalent, so deleting any element in the list is ok
        (*it)->pop_back();
        //if the list becomes empty delete the list in the list of lists
        if((*it)->empty())
        {
            list<pair<int,int> >* del_list = *it;
            delete del_list;
            ranker.erase(it);
        }
        else
        {
            //do nothing
        }
        //carry on to decrement the rank of the page
        //if the decremented rank exists then push_back
        if(((*page[i])->begin())->first == rank)
        {
            int num = (--(*page[i])->end())->second+1;
            (*page[i])->push_back(make_pair(rank,num));
        }
        //else create a new list having this ranker
        else
        {
            it=page[i];
            list<pair<int,int> >* new_list = new list<pair<int,int> >;
            new_list->push_back(make_pair(rank,1));
            //insert this list in the list of lists according to the value of the ranker
            ranker.insert(it,new_list);
            page[i] = --it;
        }
    }
}
void counter::reset(int i)
{
    if(((*page[i])->begin())->first == 0)
    {
        //do nothing
    }
    else
    {
        it = page[i];
        page[i] = zero;
        int num = ((*zero)->end()--)->second+1;
        (*zero)->push_back(make_pair(0,num));
        (*it)->pop_back();
        if((*it)->empty())
        {
            list<pair<int,int> >* del_list = *it;
            delete del_list;
            ranker.erase(it);
        }
        else
        {
            //do nothing
        }
    }
}
int counter::count(int i)
{
    return ((*page[i])->begin())->first;
}
int counter::findMax()
{
    it = --ranker.end();
    return ((*it)->begin())->first;
}
int counter::numMax()
{
    it = --ranker.end();
    return ((*it)->begin())->second;
}
void counter::printMax()
{
    rank = ((*(--ranker.end()))->begin())->first;
    for(int i=0; i<n; i++)
    {
        if(((*page[i])->begin())->first == rank)
        {
            printf("%d ",(i+1));
        }
    }
}

