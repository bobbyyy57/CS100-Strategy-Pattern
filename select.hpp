#ifndef __SELECT_HPP__
#define __SELECT_HPP__
#include <string>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;
class Select
{
public:
    virtual ~Select() = default;

    // Return true if the specified row should be selected.
    virtual bool select(const Spreadsheet* sheet, int row) const = 0;
};

// A common type of criterion for selection is to perform a comparison based on
// the contents of one column.  This class contains contains the logic needed
// for dealing with columns. Note that this class is also an abstract base
// class, derived from Select.  It introduces a new select function (taking just
// a string) and implements the original interface in terms of this.  Derived
// classes need only implement the new select function.  You may choose to
// derive from Select or Select_Column at your convenience.
class Select_Column: public Select
{
protected:
    int column;
public:
    Select_Column(const Spreadsheet* sheet, const std::string& name)
    {
      column = sheet->get_column_by_name(name);
    }

    virtual bool select(const Spreadsheet* sheet, int row) const
    {
        return select(sheet->cell_data(row, column));
    }

    // Derived classes can instead implement this simpler interface.
    virtual bool select(const std::string& s) const = 0;
};

class Select_Contains: public Select{
protected: 
	std::string target;
//	Spreadsheet* spread;
	int columnNum;
public:
	Select_Contains(Spreadsheet* sheet, const std::string& columnName, const std::string& value)
	:target(value){
//	this->column = column;
	columnNum = sheet->get_column_by_name(columnName); 
	}
	virtual bool select(const Spreadsheet* sheet, int row) const{
//	virtual bool select(const std::string& s)const{
/*	auto it = std::search(
		s.begin(), s.end(), target.begin(), target.end(),
		[](char ch1, char ch2) {return std::toupper(ch1) == std::toupper(ch2);}
	)
	return (it != s.end());

*/		
//	 column = sheet->get_column_by_name(columnName);
	string row__ = sheet->cell_data(row, columnNum);
	size_t s = row__.find(target);
		if(s != std::string::npos){
			return true;
		}
		else{
	//	std::cout<<"ROHIT";
			return false;
		}
	}

};


class Select_Not: public Select{
protected:
	Select* value1;
public:
	virtual ~Select_Not(){
	delete value1;
	}
	Select_Not(Select* arg1):value1(arg1){}

	virtual bool select(const Spreadsheet* sheet, int row) const{
		if(value1->select(sheet, row) == false){
			return true;	
		}
		else{
			return false;
		}
	}

	
};

class Select_And: public Select{
protected:
	Select* value1;
        Select* value2;
public:
	virtual ~Select_And(){
	delete value1;
	delete value2;
	}
	Select_And(Select* arg1, Select* arg2): value1(arg1), value2(arg2){}

	virtual bool select(const Spreadsheet* sheet, int row)const{
		bool val1 = value1->select(sheet, row);
		bool val2 = value2->select(sheet, row);
		if(val1 == true && val2 == true){return true;}
		else{return false;}
//delete value1;
//delete value2;
	}
};

class Select_Or: public Select{
protected:
	Select* value1;
	Select* value2;
public:
	virtual ~Select_Or(){
	delete value1;
	delete value2;
	}
	Select_Or(Select* arg1, Select* arg2):value1(arg1), value2(arg2){}

	virtual bool select(const Spreadsheet* sheet, int row)const{
		bool val1 = value1->select(sheet, row);
		bool val2 = value2->select(sheet, row);
		if(val1 == true || val2 == true){return true;}
		else{return false;}
	}
};

#endif //__SELECT_HPP__
