#include "net.h"

using namespace std;

Net::Net(string n)
{
   netname = n;
   val = 'X'
   delay = 1;
   drivers = new vector<Gate *>;
   loads = new vector<Gate *>;
}

Net::~Net()
{
   vector<Gate *>::iterator it;
   for (it = drivers->begin; it != drivers->end; ++it)
   {
      delete [] it;
   }
   
   delete drivers;
   
   for (it = loads->begin; it != loads->end; ++it)
   {
      delete [] it;
   }
   
   delete loads;
   
}

string Net::name() const
{
   return netname;
}

void Net::addDriver(Gate *g)
{
   drivers->push_back(g);
}

void Net::addLoad(Gate *g)
{
   loads->push_back(g);
}

vector<Gate *>* Net::getLoads()
{
   return loads;
}

vector<Gate *>* Net::getDrivers()
{
   return drivers;
}

char Net::computeVal()
{
   if (drivers->size() == 0)
   {
      return val;
   }
   else if (drivers->size() > 1)
   {
      return 'X';
   }
   else
   {
      return drivers.begin()->eval();
   }
}

int Net::computeDelay()
{
   //////////////////////////////////////
   return 0;
}

void printDriversLoads()
{
   vector<Gate *>::iterator it;
   cout << "drivers: ";
   for (it = drivers->begin; it != drivers->end; ++it)
   {
      cout << it->name() << endl;
   }
   
   cout << "Loads: ";
   for (it = loads->begin; it != loads->end; ++it)
   {
      cout << it->name() << endl;
   }
}
