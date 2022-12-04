#include<iostream>
#include<list>
using namespace std;
class ListOperations
{
  public:
    int find_max(list<int> &list_x);
    int find_min(list<int> &list_x);
    bool compare_lists(list<int> &list_1,list<int> &list_2);
    void add(list<int> &list_x,int element);
    int find_setdifference(list<int> &list_1,list<int> &list2);
    list<int> find_bestset(list<int> universe,list<int> subsets[],int size);
};
int ListOperations::find_max(list<int> &list_x)
{
  list<int>::iterator i = list_x.begin();
  int max = *i;
  for(;i != list_x.end();i++)
  {
    if(*i > max)
    {
      max = *i;
    }
  }
  return max;
}
int ListOperations::find_min(list<int> &list_x)
{
  list<int>::iterator i = list_x.end();
  int min = *i;
  for(;i != list_x.end();i++)
  {
    if(*i < min)
    {
      min = *i;
    }
  }
  return min;
}
bool ListOperations::compare_lists(list<int> &list_1,list<int> &list_2)
{
  list_1.sort();
  list_2.sort();
  if(list_1.size() == list_2.size())
  {
    for(list<int>::iterator i = list_1.begin(),j = list_2.begin();i != list_1.end() && j != list_2.end();i++,j++)
    {
      if(*i != *j)
      {
        return false;
      }
    }
    return true;
  }
  return false;
}

void ListOperations::add(list<int> &list_x, int element)
{
    int found = 0;
    for(list<int>::iterator i = list_x.begin();i != list_x.end();i++)
    {
        if(element == *i)
        {
            found = 1;
        }
    }
    if(found != 1)
    {
        list_x.push_back(element);
    }
}
int ListOperations::find_setdifference(list<int> &list_1,list<int> &list_2)
{
  list_1.sort();
  list_2.sort();
  int size_1 = list_1.size(),size_2 = list_2.size(),ok = 1;
  list<int> result;
  if(size_1 == 0)
  {
    return size_2;
  }
  if(size_2 == 0)
  {
    return size_1;
  }
  list<int>::iterator i,j;
  for(i = list_2.begin();i != list_2.end();i++)
  {
    ok = 1;
    for(j = list_1.begin();j != list_1.end();j++)
    {
      if(*i == *j){
        ok = 0;
      }
    }
    if(ok){
      this->add(result,*i);
    }
  }
  return result.size();
}
list<int> ListOperations::find_bestset(list<int> add_set,list<int> subsets[],int size)
{
  list<int> max_set = subsets[0];
  int max = this->find_setdifference(add_set,subsets[0]);
  for(int i = 0;i < size;i++)
  {
    if(this->find_setdifference(add_set,subsets[i]) > max)
    {
      max = this->find_setdifference(add_set,subsets[i]);
      max_set = subsets[i];
    }
  }
  return max_set;
}
void set_cover(list<int> universe,list<int> subsets[],int size)
{
  ListOperations test_obj;
  list<int> elements;
  for(int i = 0;i < size;i++)
  {
    for(list<int>::iterator j = subsets[i].begin(); j != subsets[i].end();j++)
    {
      test_obj.add(elements,*j);
    }
  }
  if(!(test_obj.compare_lists(universe,elements)))
  {
    cout << "Invalid subsets!!!" << endl;
    return;
  }
  list<int> covered;
  list<int> cover[size];
  int i = 0;
  while(!test_obj.compare_lists(covered,elements))
  {
    list<int> subset = test_obj.find_bestset(covered,subsets,size);
    for(auto i = subset.begin(); i != subset.end();i++)
    {
      cout << *i << " ";
    }
    cout << endl;
    cover[i] = subset;

    i++;
  }
  cout << "\n{";
  for(int i = 0;i < size;i++){
    if(cover[i].size() != 0){
      cout << "{";
      for(auto j = cover[i].begin(); j != cover[i].end();j++)
      {
        cout << *j << ",";
      }
      cout << "},";
    }
  }
  cout << "}" << endl;
}
int main()
{
  list<int> universe = {1,2,3,4,5,6,7,8,9,10,11,12,13};
  list<int> subsets[] = {{1,2},{2,3,4,5},{6,7,8,9,10,11,12,13},{1,3,5,7,9,11,3},{2,4,6,8,10,12,13}};
  set_cover(universe,subsets,5);
  return 0;
}