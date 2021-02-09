#ifndef __SELECT_HPP__
#define __SELECT_HPP__

#include <cstring>

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
	const std::string& target;
	const Spreadsheet* spread;
	const std::string& columnName;
public:
	Select_Contains(const Spreadsheet* sheet, const std::string& column, const std::string& value)
		: spread(sheet),columnName(column), target(value) {}

	virtual bool select(const Spreadsheet* sheet, int row)const{
		int columnVal = sheet->get_column_by_name(columnName);
		std::string search = sheet->cell_data(row, columnVal);
		std::size_t found = search.find(target);
		if(found!=std::string::npos){
			return true;
		}
		else{
			return false;
		}
	}
};


class Select_Not: public Select{
protected:
	Select* value;
public:
	Select_Not(Select* value1):value(value1){}
	
	virtual bool select(const Spreadsheet* sheet, int row) const{
		if(value->select(sheet, row)  == std::string::npos){
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
	Select_And(Select* arg1, Select* arg2): value1(arg1), value2(arg2){}

	virtual bool select(const Spreadsheet* sheet, int row)const{
		bool val1 = value1->select(sheet, row);
		bool val2 = value2->select(sheet, row);
		if(val1 == true && val2 == true){return true;}
		else{return false;}
	}
};

class Select_Or: public Select{
protected:
	Select* value1;
	Select* value2;
public:
	Select_Or(Select* arg1, Select* arg2):value1(arg1), value2(arg2){}

	virtual bool select(const Spreadsheet* sheet, int row)const{
		bool val1 = value1->select(sheet, row);
		bool val2 = value2->select(sheet, row);
		if(val1 == true || val2 == true){return true;}
		else{return false;}
	}
};

#endif //__SELECT_HPP__
