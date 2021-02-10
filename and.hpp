#ifndef __AND_HPP__
#define __AND_HPP__

#include "gtest/gtest.h"
#include "select.hpp"
#include "spreadsheet.hpp"

//Both In Test
TEST(AndTest, BothInTest) {
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

    Select_And* key = new Select_And(new Select_Contains(&sheet, "Last", "Conners"), new Select_Contains(&sheet, "Age", "21"));
    sheet.set_selection(key);

    EXPECT_TRUE(key->select(&sheet, 2));
}

//Both Out Test
TEST(AndTest, BothOutTest) {
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

    Select_And* key = new Select_And(new Select_Contains(&sheet, "First", "Bobby"), new Select_Contains(&sheet, "Last", "Lerias"));
    sheet.set_selection(key);

    EXPECT_FALSE(key->select(&sheet, 0));
}

//One In and One Out
TEST(AndTest, InAndOutTest) {
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

    Select_And* key = new Select_And(new Select_Contains(&sheet, "First", "David"), new Select_Contains(&sheet, "Last", "Malig"));
    sheet.set_selection(key);

    EXPECT_FALSE(key->select(&sheet, 6));
}

//Empty String
TEST(AndTest, EmptyTest) {
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

    Select_And* key = new Select_And(new Select_Contains(&sheet, "First", ""), new Select_Contains(&sheet, "Last", ""));
    sheet.set_selection(key);

    EXPECT_TRUE(key->select(&sheet, 6));
}

//Not and Not
TEST(AndTest, NotNotTest) {
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

    Select_And* key = new Select_And(new Select_Not(new Select_Contains(&sheet, "First", "Rodrigo")), new Select_Not(new Select_Contains(&sheet, "Last", "Lamas")));
    sheet.set_selection(key);

    EXPECT_TRUE(key->select(&sheet, 6));
}

//And and Or False
TEST(AndTest, AndOrFalseTest) {
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

    Select_And* arg1 = new Select_And(/*MAKES IT FALSE HERE */new Select_Contains(&sheet, "First", "Rodrigo"), new Select_Not(new Select_Contains(&sheet, "Last", "Lamas")));
    Select_Or* arg2 = new Select_Or(new Select_Contains(&sheet, "First", "Diane"), new Select_Contains(&sheet, "Last", "Kho"));   
    Select_And* key = new Select_And(arg1, arg2);
    sheet.set_selection(key);

    EXPECT_FALSE(key->select(&sheet,5));
}

//AndOrTrue
TEST(AndTest, AndOrTrueTest) {
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

    Select_And* arg1 = new Select_And(new Select_Not(new Select_Contains(&sheet, "First", "Rodrigo")), new Select_Not(new Select_Contains(&sheet, "Last", "Lamas")));
    Select_Or* arg2 = new Select_Or(new Select_Contains(&sheet, "First", "Diane"), new Select_Contains(&sheet, "Last", "Kho"));
    Select_And* key = new Select_And(arg1, arg2);
    sheet.set_selection(key);

    EXPECT_TRUE(key->select(&sheet,5));
}

#endif
