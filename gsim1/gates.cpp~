#include "gates.h"

using namespace std;
Gate::Gate(string n)
{
   inst_name = n;
   delay = 1;
   inputs = new vector<Net *>;
}

Gate::Gate(string n, int d)
{
   inst_name = n;
   delay = d;
   inputs = new vector<Net *>;
}

Gate::~Gate()
{
   vector<Net *>::iterator it;
   for (it = inputs->begin; it != inputs->end; ++it)
   {
      delete [] it;
   }
}

string Gate::name() const
{
   return inst_name;
}


int Gate::getDelay() const
{
   return delay;
}

void Gate::addInput(Net *n)
{
   inputs->push_back(n);
}

vector<Net *>* Gate::getInputs()
{
    return inputs;
}

void Gate::addOutput(Net *n)
{
   output = n;
}

Net* Gate::getOutput() const
{
   return output;
}

int Gate::getNumInputs() const
{
   return inputs->size();
}

And::And(string n, int d) :
Gate(n, d)
{
}

And::~And()
{
   vector<Net *>::iterator it;
   for (it = inputs->begin; it != inputs->end; ++it)
   {
      delete [] it;
   }
}

char And::eval()
{
   int val = 0;
   vector<Net *>::iterator it;
   for (it = getInputs->begin(); it != getInputs->end(); ++it)
   {
      if ((*it)->computeVal != 'X')
      {
         val += atoi((*it)->computeVal);
      }
      else
      {
         return 'X';
      }
   }
   
   if (val == getNumInputs())
   {
      return '1';
   }
   else
   {
      return '0';
   }
}

void And::dump(ostream &os)
{
   os << "and";
}

Or::Or(string n, int d) :
Gate(n, d)
{
}

Or::~Or()
{
   vector<Net *>::iterator it;
   for (it = inputs->begin; it != inputs->end; ++it)
   {
      delete [] it;
   }
}

char Or::eval()
{
   int val = 0;
   vector<Net *>::iterator it;
   for (it = getInputs->begin(); it != getInputs->end(); ++it)
   {
      if ((*it)->computeVal != 'X')
      {
         val += atoi((*it)->getVal);
      }
      else
      {
         return 'X';
      }
   }
   
   if (val > 0)
   {
      return '1';
   }
   else
   {
      return '0';
   }
}

void Or::dump(ostream &os)
{
   os << "or";
}


Nor::Nor(string n, int d) :
Gate(n, d)
{
}

Nor::~Nor()
{
   vector<Net *>::iterator it;
   for (it = inputs->begin; it != inputs->end; ++it)
   {
      delete [] it;
   }
}

char Nor::eval()
{
   int val = 0;
   vector<Net *>::iterator it;
   for (it = getInputs->begin(); it != getInputs->end(); ++it)
   {
      if ((*it)->computeVal != 'X')
      {
         val += atoi((*it)->getVal);
      }
      else
      {
         return 'X';
      }
   }
   
   if (val > 0)
   {
      return '0';
   }
   else
   {
      return '1';
   }
}

void Nor::dump(ostream &os)
{
   os << "nor";
}


Nand::Nand(string n, int d) :
Gate(n, d)
{
}

Nand::~Nand()
{
   vector<Net *>::iterator it;
   for (it = inputs->begin; it != inputs->end; ++it)
   {
      delete [] it;
   }
}

char Nand::eval()
{
   int val = 0;
   vector<Net *>::iterator it;
   for (it = getInputs->begin(); it != getInputs->end(); ++it)
   {
      if ((*it)->computeVal != 'X')
      {
         val += atoi((*it)->getVal);
      }
      else
      {
         return 'X';
      }
   }
   
   if (val == getNumInputs())
   {
      return '0';
   }
   else
   {
      return '1';
   }
}

void Nand::dump(ostream &os)
{
   os << "nand";
}


Xor::Xor(string n, int d) :
Gate(n, d)
{
}

Xor::~Xor()
{
   vector<Net *>::iterator it;
   for (it = inputs->begin; it != inputs->end; ++it)
   {
      delete [] it;
   }
}

char Xor::eval()
{
   int val = 0;
   vector<Net *>::iterator it;
   for (it = getInputs->begin(); it != getInputs->end(); ++it)
   {
      if ((*it)->computeVal != 'X')
      {
         val += atoi((*it)->getVal);
      }
      else
      {
         return 'X';
      }
   }
   
   if (val == 1)
   {
      return '1';
   }
   else
   {
      return '0';
   }
}

void Xor::dump(ostream &os)
{
   os << "xor";
}


Not::Not(string n, int d) :
Gate(n, d)
{
}

Not::~Not()
{
   vector<Net *>::iterator it;
   for (it = inputs->begin; it != inputs->end; ++it)
   {
      delete [] it;
   }
}

char Not::eval()
{
   int val = 0;
   vector<Net *>::iterator it;
   for (it = getInputs->begin(); it != getInputs->end(); ++it)
   {
      if ((*it)->computeVal != 'X')
      {
         val += atoi((*it)->getVal);
      }
      else
      {
         return 'X';
      }
   }
   
   if (val == getNumInputs())
   {
      return '0';
   }
   else if (val == 0)
   {
      return '1';
   }
   else
   {
      return 'X';
   }
}

void Not::dump(ostream &os)
{
   os << "not";
}

