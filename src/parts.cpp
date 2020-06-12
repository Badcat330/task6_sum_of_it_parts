#include <iostream>
#include "parts.h"

using namespace std;

//**************** Part ****************

void Part::describe(void)
{
    cout << "Part " << name << " subparts:" << "\n";
    auto it = subpart.begin();
    if(it == subpart.end())
    {
        cout << "  " << "It has no subparts" << endl;
        return;
    }
    while (it != subpart.end())
    {
        cout << "  " << it->second << " " << it->first->name << "\n";
        ++it;
    }
}


int Part::count_howmany(const Part  *p) const
{
   auto it = subpart.find(p);
   if(it != subpart.end())
       return it->second;
   if(subpart.empty())
       return 0;
   int sum = 0;
   for(auto i : subpart)
   {
       Part* copyPart = new Part(i.first->name);
       copyPart->subpart = i.first->subpart;
       sum += i.second * copyPart->count_howmany(p);
   }
    return sum;
}

//**************** NameContainer ****************

Part* NameContainer::lookup(string const &name)
{
    auto foundPart = name_map.find(name);
    if(foundPart != name_map.end())
    {
        return foundPart->second;
    }
    Part* newPart = new Part(name);
    name_map[name] = newPart;
    return newPart;
}

NameContainer::~NameContainer()
{
    for(auto part : name_map)
    {
        delete(part.second);
    }
}

void add_part(string const &x, int q, string const &y)
{
    Part* xPart = partContainer.lookup(x);
    Part* yPart = partContainer.lookup(y);
    xPart->subpart[yPart] = q;
}
