#include<iostream>
#include<set>
using namespace std;
template <class T>
class SetOperations
{
  public:
    T find_max(set<T> &set_x);
    T find_min(set<T> &set_x);
    int compare_sets(set<T> &set_1,set<T> &set_2);
    int find_setdifference(set<T> &set_1,set<T> &set_2);
    set<T> find_bestset(set<T> universe,set<T> subsets[],int size);
};
template <class T>
T SetOperations<T>::find_max(set<T> &set_x)
{
  typename set<T>::iterator i = set_x.begin();
  T max = *i;
  for(;i != set_x.end();i++){
    if(*i > max){
      max = *i;
    }
  }
  return max;
}
template <class T>
T SetOperations<T>::find_min(set<T> &set_x)
{
  typename set<T>::iterator i = set_x.begin();
  T min = *i;
  for(;i != set_x.end();i++){
    if(*i < min){
      min = *i;
    }
  }
  return min;
}
template <class T>
int SetOperations<T>::compare_sets(set<T> &set_1,set<T> &set_2)
{
  if(set_1.size() == set_2.size())
  {
    for(typename set<T>::iterator i = set_1.begin(),j = set_2.begin(); i != set_1.end() && j != set_2.end();i++,j++)
    {
      if(*i != *j)
      {
        return 0;
      }
    }
    return 1;
  }
  return 0;
}
template <class T>
int SetOperations<T>::find_setdifference(set<T> &set_1,set<T> &set_2)
{
      int size_1 = set_1.size(),size_2 = set_2.size(),ok = 1;
      set<T> result{};
      if(size_1 == 0){
        return size_2;
      }
      if(size_2 == 0){
        return size_1;
      }
      typename set<T>::iterator i,j;
      if(size_1 < size_2)
      {
          for(i = set_1.begin(); i != set_1.end();i++)
          {
              ok = 1;
              for(j = set_2.begin();j != set_2.end();j++)
              {
                  if(*i == *j){
                      ok = 0;
                  }
              }
              if(ok){
                  result.insert(*i);
              }
          }
        
      }
      else
      {
          for(i = set_2.begin(); i != set_2.end();i++)
          {
              ok = 1;
              for(j = set_1.begin();j != set_1.end();j++)
              {
                  if(*i == *j){
                      ok = 0;
                  }
              }
              if(ok){
                  result.insert(*i);
              }
          }

      }
      return result.size();

}
template <class T>
set<T> SetOperations<T>::find_bestset(set<T> add_set,set<T> subsets[],int size)
{
  set<T> max_set = subsets[0];
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
template <class T>
void set_cover(set<T> universe,set<T> subsets[],int size)
{
  SetOperations<T> test_obj;
  set<T> elements;
  for(int i = 0;i < size;i++)
  {
    for(auto j = subsets[i].begin(); j != subsets[i].end();j++)
    {
      elements.emplace(*j);
    }
  }
  if(!(test_obj.compare_sets(universe,elements)))
  {
    cout << "Invalid subsets!!!" << endl;
    return;
  }
  set<T> covered;
  set<T> cover[size];
  int i = 0;
  while(test_obj.compare_sets(covered,elements) != 1)
  {
    set<T> subset = test_obj.find_bestset(covered,subsets,size);
    i++;
    cover[i] = subset;
    for(auto j = subset.begin();j != subset.end();j++){
      covered.emplace(*j);
    }
  }
  cout << "\n{";
  for(int i = 0;i < size;i++){
    if(cover[i].size() != 0){
      cout << "{";
      for(auto j = cover[i].begin(); j != cover[i].end();j++){
        cout << *j << ",";
      }
      cout << "},";
    }
  }
  cout << "}" << endl;
}
int main()
{
  SetOperations<int> test_obj;
  set<int> universe = {1,2,3,4,5};
  set<int> subsets[] = {{4,1,3},{2,5},{1,4,3,2}};
  set_cover(universe,subsets,3);
  
  return 0;
}