#ifndef __SELECT_CONTAINS_TEST__
#define __SELECT_CONTAINS_TEST__

#include "gtest/gtest.h"
#include "select.hpp"
#include "spreadsheet.hpp"

TEST(ContainsTest, ContainsFound){
	Spreadsheet sheet;
	sheet.set_column_names({"First","Last","Age","Major"});
	sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    sheet.add_row({"Carol","Conners","21","computer science"});
    sheet.add_row({"Joe","Jackson","21","mathematics"});
    sheet.add_row({"Sarah","Summers","21","computer science"});
    sheet.add_row({"Diane","Dole","20","computer engineering"});
    sheet.add_row({"David","Dole","22","electrical engineering"});
    sheet.add_row({"Dominick","Dole","22","communications"});
    sheet.add_row({"George","Genius","9","astrophysics"});
	
	Select_Contains* key = new Select_Contains(&sheet, "Last", "Dole");
	sheet.set_selection(key);
EXPECT_EQ(key->select(&sheet, 7), true);
}


TEST(ContainsTest, ContainsNotFound){
	Spreadsheet sheet;
	sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    sheet.add_row({"Carol","Conners","21","computer science"});
    sheet.add_row({"Joe","Jackson","21","mathematics"});
    sheet.add_row({"Sarah","Summers","21","computer science"});
    sheet.add_row({"Diane","Dole","20","computer engineering"});
    sheet.add_row({"David","Dole","22","electrical engineering"});
    sheet.add_row({"Dominick","Dole","22","communications"});
    sheet.add_row({"George","Genius","9","astrophysics"});

        Select_Contains* key = new Select_Contains(&sheet, "Last", "Guadalupe");
        sheet.set_selection(key);
EXPECT_EQ(key->select(&sheet, 2), false);	
}

TEST(ContainsTest, ContainsEmptStr){
        Spreadsheet sheet;
	sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    sheet.add_row({"Carol","Conners","21","computer science"});
    sheet.add_row({"Joe","Jackson","21","mathematics"});
    sheet.add_row({"Sarah","Summers","21","computer science"});
    sheet.add_row({"Diane","Dole","20","computer engineering"});
    sheet.add_row({"David","Dole","22","electrical engineering"});
    sheet.add_row({"Dominick","Dole","22","communications"});
    sheet.add_row({"George","Genius","9","astrophysics"});

        Select_Contains* key = new Select_Contains(&sheet, "Last", "");
        sheet.set_selection(key);
EXPECT_EQ(key->select(&sheet, 2), true);
}

TEST(ContainsTest, Sub_Str){
        Spreadsheet sheet;
	sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    sheet.add_row({"Carol","Conners","21","computer science"});
    sheet.add_row({"Joe","Snapple","21","mathematics"});
    sheet.add_row({"Sarah","Summers","21","computer science"});
    sheet.add_row({"Diane","Dole","20","computer engineering"});
    sheet.add_row({"David","Dole","22","electrical engineering"});
    sheet.add_row({"Dominick","Dole","22","communications"});
    sheet.add_row({"George","Genius","9","astrophysics"});

        Select_Contains* key = new Select_Contains(&sheet, "Last", "apple");
        sheet.set_selection(key);
EXPECT_EQ(key->select(&sheet, 3), true);
}

TEST(ContainsTest, No_Sub_Str){
        Spreadsheet sheet;
	sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    sheet.add_row({"Carol","Conners","21","computer science"});
    sheet.add_row({"Joe","aPPLE","21","mathematics"});
    sheet.add_row({"Sarah","Summers","21","computer science"});
    sheet.add_row({"Diane","Dole","20","computer engineering"});
    sheet.add_row({"David","Dole","22","electrical engineering"});
    sheet.add_row({"Dominick","Dole","22","communications"});
    sheet.add_row({"George","Genius","9","astrophysics"});

        Select_Contains* key = new Select_Contains(&sheet, "Last", "apple");
        sheet.set_selection(key);
EXPECT_EQ(key->select(&sheet, 3), false);
}

TEST(ContainsTest,No_Num_To_Str){                                                                                                                                       Spreadsheet sheet;
        sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    sheet.add_row({"Carol","Conners","21","computer science"});
    sheet.add_row({"Joe","aPPLE","21","mathematics"});
    sheet.add_row({"Sarah","Summers","21","computer science"});
    sheet.add_row({"Diane","Dole","20","computer engineering"});
    sheet.add_row({"David","Dole","22","electrical engineering"});
    sheet.add_row({"Dominick","Dole","22","communications"});
    sheet.add_row({"George","Genius","9","astrophysics"});

        Select_Contains* key = new Select_Contains(&sheet, "Last", "21");
        sheet.set_selection(key);
EXPECT_EQ(key->select(&sheet, 3), false);
}

TEST(ContainsTest, Num_To_Str){                                                                                                                                       Spreadsheet sheet;
        sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    sheet.add_row({"Carol","Conners","21","computer science"});
    sheet.add_row({"Joe","aPPLE","21","mathematics"});
    sheet.add_row({"Sarah","Summers","21","computer science"});
    sheet.add_row({"Diane","Dole","20","computer engineering"});
    sheet.add_row({"David","Dole","22","electrical engineering"});
    sheet.add_row({"Dominick","Dole","22","communications"});
    sheet.add_row({"George","Genius","9","astrophysics"});

        Select_Contains* key = new Select_Contains(&sheet, "Age", "22");
        sheet.set_selection(key);
EXPECT_EQ(key->select(&sheet, 0), true);
}


#endif //__SELECT_CONTAINS__
