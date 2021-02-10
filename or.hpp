#ifndef __SELECT_OR_TEST__
#define __SELECT_OR_TEST__

#include "gtest/gtest.h"

#include "select.hpp"
//#include "spreadsheet.cpp"
#include "spreadsheet.hpp"

TEST(OrTest, OR_Two_Match){
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

	Select_Or* key = new Select_Or(
	new Select_Contains(&sheet, "Last", "Andrews"),
	new Select_Contains(&sheet, "Age", "22")
	);
	sheet.set_selection(key);
EXPECT_TRUE(key->select(&sheet, 0));
}

TEST(OrTest, OR_One_Match){
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

        Select_Or* key = new Select_Or(
        new Select_Contains(&sheet, "Last", "Andrews"),
        new Select_Contains(&sheet, "Age", "0")
        );
        sheet.set_selection(key);
EXPECT_TRUE(key->select(&sheet, 0));
}

TEST(OrTest, OR_No_Match){
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

        Select_Or* key = new Select_Or(
        new Select_Contains(&sheet, "Last", "Lopez"),
        new Select_Contains(&sheet, "Age", "9")
        );
        sheet.set_selection(key);
EXPECT_FALSE(key->select(&sheet, 0));
}

TEST(OrTest, OR_Empt_Str){
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

        Select_Or* key = new Select_Or(
        new Select_Contains(&sheet, "Last", ""),
        new Select_Contains(&sheet, "Age", "")
        );
        sheet.set_selection(key);
EXPECT_TRUE(key->select(&sheet, 0));
}

TEST(OrTest, OR_SubStr){
        Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Snapple","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    sheet.add_row({"Carol","Conners","21","computer science"});
    sheet.add_row({"Joe","Jackson","21","mathematics"});
    sheet.add_row({"Sarah","Summers","21","computer science"});
    sheet.add_row({"Diane","Dole","20","computer engineering"});
    sheet.add_row({"David","Dole","22","electrical engineering"});
    sheet.add_row({"Dominick","Dole","22","communications"});
    sheet.add_row({"George","Genius","9","astrophysics"});

        Select_Or* key = new Select_Or(
        new Select_Contains(&sheet, "Last", "apple"),
        new Select_Contains(&sheet, "Age", "1")
        );
        sheet.set_selection(key);
EXPECT_TRUE(key->select(&sheet, 0));
}

TEST(OrTest, OR_Not){
        Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","aPPle","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    sheet.add_row({"Carol","Conners","21","computer science"});
    sheet.add_row({"Joe","Jackson","21","mathematics"});
    sheet.add_row({"Sarah","Summers","21","computer science"});
    sheet.add_row({"Diane","Dole","20","computer engineering"});
    sheet.add_row({"David","Dole","22","electrical engineering"});
    sheet.add_row({"Dominick","Dole","22","communications"});
    sheet.add_row({"George","Genius","9","astrophysics"});

        Select_Or* key = new Select_Or(
        new Select_Contains(&sheet, "Last", "apple"),
       new Select_Not( new Select_Contains(&sheet, "Age", "22"))
        );
        sheet.set_selection(key);
EXPECT_FALSE(key->select(&sheet, 0));
}

TEST(OrTest, OR_And){
        Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Snapple","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    sheet.add_row({"Carol","Conners","21","computer science"});
    sheet.add_row({"Joe","Jackson","21","mathematics"});
    sheet.add_row({"Sarah","Summers","21","computer science"});
    sheet.add_row({"Diane","Dole","20","computer engineering"});
    sheet.add_row({"David","Dole","22","electrical engineering"});
    sheet.add_row({"Dominick","Dole","22","communications"});
    sheet.add_row({"George","Genius","9","astrophysics"});

        Select_Or* key = new Select_Or(
       		new Select_And( new Select_Contains(&sheet, "Last", "apple"),
				new Select_Contains(&sheet, "Major", "business")),
        new Select_Contains(&sheet, "Age", "1")
        );
        sheet.set_selection(key);
EXPECT_TRUE(key->select(&sheet, 0));
}

#endif //__SELECT_OR_TEST__
