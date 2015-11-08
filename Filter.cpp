#include <iostream>
#include "Filter.h"
#include <queue>

using namespace std;


Filter::Filter(vector<Employee *> *pEmpVector, DATA_FIELDS field, SELECTION_CRITERIA selectCrit, pair<string, string> dataLimit):
field_(field), firstField_(field), selectCrit_(selectCrit)
{
   // TODO: Part 3. Modify or add code to perform the filtering based on the parameters given. Even the next line!
string userinput1 = dataLimit.first;
string userinput2 = dataLimit.second;
replace(userinput1.begin(), userinput1.end(), '_', ' ');
replace(userinput2.begin(), userinput2.end(), '_', ' ');
pEmpVector_ = new vector<Employee *>;
for(int i = 0; i < pEmpVector -> size(); i = i+1) {
    Employee *e = pEmpVector->at(i);
    string name = e->name_;
    string status = e->status_;
    double salary = e->salary_;
    string payBasis = e->payBasis_;
    string positionTitle = e->positionTitle_;
    std::queue <int> hit;
    hit.
if(field == 0){
     if(selectCrit == 0){
       if(name == userinput1){
           pEmpVector_->push_back(e);}
}
    if(selectCrit == 1) {
        if(name >= userinput1 && name <= userinput2) {
            pEmpVector_->push_back(e);
        }
    }
    if(selectCrit == 2) {
        if(name >= userinput1) {
            pEmpVector_->push_back(e);
        }
    }
    if(selectCrit == 3) {
        if(name <= userinput1) {
            pEmpVector_->push_back(e);
        }
    }
}
if(field == 1){
     if(selectCrit == 0){
       if(status == userinput1){
           pEmpVector_->push_back(e);}
}
    if(selectCrit == 1) {
        if(status >= userinput1 && status <= userinput2) {
            pEmpVector_->push_back(e);
        }
    }
    if(selectCrit == 2) {
        if(status >= userinput1) {
            pEmpVector_->push_back(e);
        }
    }
    if(selectCrit == 3) {
        if(status <= userinput1) {
            pEmpVector_->push_back(e);
        }
    }
}
if(field == 2){
     if(selectCrit == 0){
       if(fabs(salary - atof(userinput1.c_str())) <= 0.001){
           pEmpVector_->push_back(e);}
}
    if(selectCrit == 1) {
        if(salary >= atof(userinput1.c_str()) && salary <= atof(userinput2.c_str())) {
            pEmpVector_->push_back(e);
        }
    }
    if(selectCrit == 2) {
        if(salary >= atof(userinput1.c_str())) {
            pEmpVector_->push_back(e);
        }
    }
    if(selectCrit == 3) {
        if(salary <= atof(userinput1.c_str())) {
            pEmpVector_->push_back(e);
        }
    }
}
if(field == 3){
     if(selectCrit == 0){
       if(payBasis == userinput1){
           pEmpVector_->push_back(e);}
}
    if(selectCrit == 1) {
        if(payBasis >= userinput1 && payBasis <= userinput2) {
            pEmpVector_->push_back(e);
        }
    }
    if(selectCrit == 2) {
        if(payBasis >= userinput1) {
            pEmpVector_->push_back(e);
        }
    }
    if(selectCrit == 3) {
        if(payBasis <= userinput1) {
            pEmpVector_->push_back(e);
        }
    }
}
if(field == 4){
     if(selectCrit == 0){
       if(positionTitle == userinput1){
           pEmpVector_->push_back(e);}
}
    if(selectCrit == 1) {
        if(positionTitle >= userinput1 && positionTitle <= userinput2) {
            pEmpVector_->push_back(e);
        }
    }
    if(selectCrit == 2) {
        if(positionTitle >= userinput1) {
            pEmpVector_->push_back(e);
        }
    }
    if(selectCrit == 3) {
        if(positionTitle <= userinput1) {
            pEmpVector_->push_back(e);
        }
    }
}
}}
void Filter::printFilter()
{
   cout << getEmployeeFileHeader();
   size_t length = pEmpVector_->size();
   //cout << "print filter" <<  endl;
	for (size_t i = 0; i < length; i++)
	{
		cout << *(pEmpVector_->at(i));
	}
}

void Filter::addFilter(vector<Employee *> *pEmpVector, DATA_FIELDS field, SELECTION_CRITERIA selectCrit, pair<string, string> dataLimit, FILTER_TYPE filterType)
{
CompareClass compare(field, 1);
Filter *filter = new Filter(pEmpVector, field, selectCrit, dataLimit);
vector<Employee *> *newvector, *filtervector;
newvector = filter -> pEmpVector_;
size_t size1 = pEmpVector_->size(), size2 = newvector-> size();
filtervector = new vector<Employee *>(size1 + size2);
std::sort(newvector->begin(), newvector->end(),compare);
std::sort(this->pEmpVector_->begin(), pEmpVector_->end(),compare);
std::vector<Employee *>::iterator it;
it = (static_cast<int>(filterType) == 1)? std::set_union(newvector->begin(), newvector->end(), pEmpVector_->begin(), pEmpVector_->end(), filtervector->begin(), compare) : std::set_intersection(pEmpVector_->begin(), pEmpVector_->end(), newvector->begin(), newvector->end(), filtervector->begin(), compare);
            filtervector->resize(it - filtervector->begin());
            std::sort(filtervector->begin(), filtervector->end(), CompareClass(NAME, 1));
            pEmpVector_ = filtervector;
}

