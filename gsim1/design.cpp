#include "design.h"

using namespace std;

Design::Design(string n)
{
   desname = n;
   //map<string, Net *> designNets;
   //map<string, Gate *> designGates;
}

Design::~Design()
{
   map<string, Net *>::iterator it;
   map<string, Gate *>::iterator jt;
   for (it = designNets.begin(); it != designNets.end(); ++it)
   {
      delete it->second;
   }
   
   for (jt = designGates.begin(); jt != designGates.end(); ++jt)
   {
      delete jt->second;
   }
}

Design::string name()
{
   return desname;
}

void Design::addPI(string n)
{
   //if (findNet(n) == NULL)
   //{
      //Net *newnet = Net(n);
      //designNets.insert(make_pair(n, newnet));
   //}
   pis.push_back(n);
}

void Design::addPO(string n)
{
   //if (findNet(n) == NULL)
   //{
      //Net *newnet = Net(n);
      //designNets.insert(make_pair(n, newnet));
   //}
   pos.push_back(n);  
}

Net* Design::findNet(string net_name)
{
   if (designNets.find(net_name) != designNets.end())
   {
      return designNets.find(net_name);
   }
   else
      return NULL;
}

Gate* Design::findGate(string inst_name)
{
   if (designGates.find(inst_name) != designGates.end())
   {
      return designGates.find(inst_name);
   }
   else
      return NULL;
}

Net* Design::addFindNet(string n)
{
   if(findNet(n)==NULL)
   {
      //Net* newnet = new Net(n);
      Net *newnet = Net(n);
      designNets.insert(make_pair(n, newnet));
      return newnet;
   }
   else
      return findNet(n);
}

Gate* Design::addFindGate(int gtype, string g)
{
   if(findGate(g)==NULL)
   {
      /*gtype *newgate = Gate(g);
      designGates.insert(make_pair(n, newgate));
      return newgate;
      */
      Gate* newgate = new And(g,1);
      switch (gtype) 
      {
         case AND:
            Gate* newgate = new And(g,1);
            break;
         case OR:
            Gate* newgate = new Or(g,1);
            break;
         case NAND:
            Gate* newgate = new Nand(g,1);
            break;
         case NOR:
            Gate* newgate = new Nor(g,1);
            break;
         case XOR:
            Gate* newgate = new Xor(g,1);
            break;
         case NOT:
            Gate* newgate = new Not(g,1);
            break;
         default:
            return NULL;
            break;
            
      }
      designGates.insert(make_pair(g, newgate));
   }
   else
      return findGate(g);
}

Gate* Design::addFindGate(int gtype, string g, int d)
{
   if(findGate(g)==NULL)
   {
      /*gtype *newgate = Gate(g, d);
      designGates.insert(make_pair(n, newgate));
      return newgate;
      */
      
      switch (gtype) 
      {
         case AND:
            Gate* newgate = new And(g,1);
            break;
         case OR:
            Gate* newgate = new Or(g,1);
            break;
         case NAND:
            Gate* newgate = new Nand(g,1);
            break;
         case NOR:
            Gate* newgate = new Nor(g,1);
            break;
         case XOR:
            Gate* newgate = new Xor(g,1);
            break;
         case NOT:
            Gate* newgate = new Not(g,1);
            break;
         default:
            return NULL;
            break;
            
      }
      designGates.insert(make_pair(g, newgate))
   }
   else
      return findGate(g);
}

vector<Net *>* Design::getPINets()
{
   vector<Net *>* pinets = new vector<Net *>;
   
   vector<string>::iterator it;
   for (it = pis.begin(); it != pis.end(); ++it)
   {
      pinets->push_back(addFindNet(*it));
   }
   
   return pinets;
}

vector<Net *>* Design::getPONets()
{
   vector<Net *>* ponets = new vector<Net *>;
   
   vector<string>::iterator it;
   for (it = pos.begin(); it != pos.end(); ++it)
   {
      ponets->push_back(addFindNet(*it));
   }
   
   return ponets;
}

vector<Net *>* Design::getWireNets()
{
   vector<Net *>* wirenets = new vector<Net *>();
   
   map<string, Net *>::iterator it;
         
   for(it = designNets.begin(); it!= designNets.end(); ++it)
   {
      
      //if (pos.find(it->first) == pos.end() && pis.find(it->first) == pis.end)
      if(!isPI(it->second) && !isPO(it->second))
         wirenets->push_back((it->second));
   }
   
   return wirenets;
}

vector<Net *>* Design::allNets()
{
   vector<Net *>* alln = new vector<Net *>;
   /*
   vector<Net *>::iterator it;
   for (it = getPONets->begin(); it != getPONets->end(); ++it)
   {
      alln.push_back(*it);
   }
   
   for (it = getPINets()->begin(); it != getPINets()->end(); ++it)
   {
      alln.push_back(*it);
   }
   
   for (it = getWireNets()->begin(); it != getWireNets()->end(); ++it)
   {
      alln.push_back(*it);
   }
   */
   
   map<string, Net *>::iterator it;
   for(it = designNets.begin(); it!= designNets.end(); ++it)
   {
      alln->push_back(it->second);
   }
   return alln;
}

vector<Gate *>* Design::allGates()
{
   vector<Gate *>* allg = new vector<Gate *>;
   map<string, Gate *>::iterator it;
   for(it = designGates.begin(); it!= designGates.end(); ++it)
   {
      allg->push_back(it->second);
   }
   return allg;
}

vector<Net *>* Design::toposort()
{
   return NULL;
}

void Design::dump(ostream &os)
{
   os << "// Comment - this design is a "<< desname << endl;
   os << "module" << desname << "(";
   
   vector<string>::iterator it;
   for(it = pis.begin(); it != pis.end(); ++it)
   {
      os << *it << ", ";
   }
   for(it = pos.begin(); it != pos.end(); ++it)
   {
      os << *it << ", ";
   }
   os << ");" << endl;
   
   vector<Net *>::iterator pt;
   for (pt = getPINets()->begin(); pt != getPINets()->end(); ++pt)
   {
      os << '\t' << "input" << (*pt)->name() << ';' << endl;
   }
   for (it = getPONets()->begin(); it != getPONets()->end(); ++it)
   {
      os << '\t' << "output" << (*pt)->name() << ';' << endl;
   }
   for (pt = getWireNets()->begin(); pt != getWireNets()->end(); ++pt)
   {
      os << '\t' << "wire" << (*pt)->name() << ';' << endl;
   }
   
   vector<Gate *>::iterator nt;
   for(nt = allGates()->begin(); nt != allGates->end(); ++nt)
   {
      os << '\t' << (*nt)->dump(os) << " ";
      if (nt->getDelay() != 1)
      {
         os << '#' << nt->getDelay() << " ";
      }
      os << (*nt)->name() << "(";
      vector<Net *>::iterator jt;
      for(jt=(nt->getInputs)->begin();jt!=(nt->getInputs)->begin();++jt)
      {
         os << jt->name() << ", ";
      }
      os << ");" << endl;
      
   }
   os << "endmodule" << endl; 
}

bool Design::isPI(Net *n)
{
   if (find(pis.begin(), pis.end(), n) != pis.end())
   {
      return true;
   }
   
   else
   {
      return false;
   }
}

bool Design::isPO(Net *n)
{
   if (find(pos.begin(), pos.end(), n) != pos.end())
   {
      return true;
   }
   
   else
   {
      return false;
   }
}

void Design::dfs_visit(Net *n, vector<Net *> *flist, map<string, int> &colormap)
{
   return;
}
