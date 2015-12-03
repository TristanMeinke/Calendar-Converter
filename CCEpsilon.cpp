/* This project is the continued refinement of the Calendar Converter project.  It allows the conversion of dates from one
 /  fictional calendar to another, designed at primarily as a tool to improve ease of writing.  Since it's original conception,
 /  it has become something of an academic exercise in flow control and error handling.
 /  *************************************************Version History********************************************************
 /  Version Gamma implemented string input and string to int conversion, as well as solving input errors still present version
 /  Beta.
 /  Vesrion Delta was intended to break the program down into separate functions designed to work in concert to achieve their
 /  goal.  Learning experience.
 /  Version Epsilon is intended to streamline the functions and string input.  Epsilon should also be designed to compensate
 /  for rounding errors.
 /  ************************************************************************************************************************
 /  Created by Tristan on 10/20/15.
 /  Copyright © 2015 Tristan. All rights reserved.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <limits>


//***************************Declarations***************************

std::string navInput1 ();
int navInput2 ();
int navInput3 ();

int menu (std::string &navA, std::string &navB, int &navY, int &navZ);
double dateInput ();
int printResults (int navZ, int navY, double date, double newdate, std::string calName1, std::string calName2);

double dateCalc1 (double date, double newdate);
double dateCalc2 (double date, double newdate);
double dateCalc3 (double date, double newdate);
double dateCalc4 (double date, double newdate);
double dateCalc5 (double date, double newdate);
double dateCalc6 (double date, double newdate);

int conversion1 (double date);
int conversion2 (double date);
int conversion3 (double date);
int conversion4 (double date);
int conversion5 (double date);
int conversion6 (double date);

//*******************************MAIN***************************

int main()
{
    std::string navA;
    std::string navB;
    std::string navC;
    int navZ = 0;
    int navY = 0;

    double date = 0.0;
    double newdate = 0.0;
    
    std::string calName1;
    std::string calName2;
    
    
    std::cout << "Welcome to the Terran Calendar Converter. This tool will convert calendar dates to other dating systems, but only those " << std::endl << "used by human societies.  We intend to account for alien calendars at a later time, and thank youfor your patience." << std::endl << "When using this tool, please mind changes in notation, as this converter does not display negative dates." << std::endl;
    
    do
    {
        menu (navA, navB, navY, navZ); //calls the menu function
        

   
        if (navZ == 1 && navY == 1) //if these conditions are met
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert from Aeon Series to the Elbert Era:" << std::endl;
            
            date = dateInput();
            //std::cout<<"DEBUG :::::  Date in Main: "<<date<<std::endl;
            
            newdate = dateCalc1(date, newdate); //calls the first conversion option

            
        }
        if (navZ == 1 && navY == 2)
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert from Aeon Series to the Xix Era:" << std::endl;
            
            date = dateInput();
            
            newdate = dateCalc2(date, newdate);
        
        }
        if (navZ == 2 && navY == 1)
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert from the Elbert Era to Aeon Series:" << std::endl;
            
            date = dateInput();
            
            newdate = dateCalc3(date, newdate);
        }
        if (navZ == 2 && navY == 2)
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert from the Elbert Era to the Xix Era:" << std::endl;
            
            date = dateInput();
            
            newdate = dateCalc4(date, newdate);
        }
        if (navZ == 3 && navY == 1)
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert from Xix Era to Aeon Series:" << std::endl;
            
            date = dateInput();
            
            newdate = dateCalc5(date, newdate);
            
            //conversion5 (date);
        }
        if (navZ == 3 && navY == 2)
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert from the Xix Era to the Elbert Era:" << std::endl;
            
            date = dateInput();
            
            newdate = dateCalc6(date, newdate);
            
            //conversion6 (date);
        }
        //std::cout<<"DEBUG :::::  NewDate passed to printResults: "<<newdate<<std::endl;
        printResults (navZ, navY, date, newdate, calName1, calName2);
        
        std::cout << "Would you like to make another calculation?" << std::endl;
        std::cout << "Enter 'yes' to return to the main menu, enter 'no' to end the program." << std::endl;
        std::cout << " - - - - - - - - - - - - " << std::endl;
        
        navC = navInput1(); //This is the exit or continue input for the do/while loop.
        
        while (navC != "yes" && navC != "y" && navC != "Yes" && navC != "Y"  //conditions for reset-exit error
               && navC != "no" && navC != "n" && navC != "No" && navC != "N")
        {
            std::cout << "Another calculation?" << std::endl; //error message for the exit-continue input
            
            navC = navInput1(); //re-input navC to exit while loop
            
        }
    }
    while (navC == "yes" || navC == "y" || navC == "Yes" || navC == "Y"); //conditions for do/while reset
    
    if (navC == "no" || navC == "n" || navC == "No" || navC == "N") //condtions for program exit
        std::cout << "Goodbye." << std::endl;
    
    
    
    return 0;
}

//*******************************MENUS******************************

int menu (std::string &navA, std::string &navB, int &navY, int &navZ)

{
    
    std::cout << " - - - - - - - - - - - - " << std::endl;
    std::cout << "Which Calendar would you like to convert from?" << std::endl; //Main menu
    std::cout << "Select '1' for Aeon Series." << std::endl;
    std::cout << "Select '2' for Elbert Era." << std::endl;
    std::cout << "Select '3' for Xix Era." << std::endl;
    
    navZ = navInput2();  //inputs the navigator variable as a string and converts it to an int

    while (navZ != 1 && navZ != 2 && navZ != 3)
    {
        
        std::cout << "Please select a valid menu option." << std::endl; //Initial input error message and secondary menu prompt
        std::cout << "Select '1' for Aeon Series." << std::endl;
        std::cout << "Select '2' for Elbert Era." << std::endl;
        std::cout << "Select '3' for Xix Era." << std::endl;
        
         navZ = navInput2();

    }

    if (navZ == 1)
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "Which Calendar would you like to convert to?" << std::endl;
        std::cout << "Select '1' for Elbert Era." << std::endl;
        std::cout << "Select '2' for Xix Era." << std::endl;

        navY = navInput3();

        while (std::cin.fail())
        {
            std::cout << "Please select a valid menu option." << std::endl; //navB error message and secondary menu prompt at A.S. to ?
            std::cout << "Select '1' for Elbert Era." << std::endl;
            std::cout << "Select '2' for Xix Era." << std::endl;
        }
    }
    if (navZ == 2)
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "Which Calendar would you like to convert to?" << std::endl;
        std::cout << "Select '1' for Aeon Series." << std::endl;
        std::cout << "Select '2' for Xix Era." << std::endl;

        navY = navInput3();
        
        while (std::cin.fail())
        {
            std::cout << "Please select a valid menu option." << std::endl; //navB error message and secondary menu prompt at E.S. to ?
            std::cout << "Select '1' for Aeon Series." << std::endl;
            std::cout << "Select '2' for Xix Era." << std::endl;
        }
    }
    if (navZ == 3)
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "Which Calendar would you like to convert to?" << std::endl;
        std::cout << "Select '1' for Aeon Series." << std::endl;
        std::cout << "Select '2' for Elbert Era." << std::endl;
        
        navY = navInput3();

        while (std::cin.fail())
        {
            std::cout << "Please select a valid menu option." << std::endl; //navB error message and secondary menu prompt at X.E. to ?
            std::cout << "Select '1' for Aeon Series." << std::endl;
            std::cout << "Select '2' for Elbert Era." << std::endl;
        }
    }
    while (navY != 1 && navY != 2)
    {
        std::cout << "Please enter '1', '2'." << std::endl; //third error message
      
        navY = navInput3();

    }
    return 0;
}

//********************************INPUT/OUTPUT**************************


std::string navInput1 ()
{
    std::string navC;

    std::cin >> navC;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
 
    return navC;
}

int navInput2 ()
{
    std::string navA;
    int navZ;
    
    std::cin >> navA;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Clears the input buffer preimptively to keep bad input from lurking in the wings.
    std::stringstream convert(navA);
    
    if ( !(convert >> navZ))
    {
        navZ = 0;
    }
    
    return navZ;
}

int navInput3 ()
{
    std::string navB;
    int navY;
    
    std::cin >> navB;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::stringstream convert(navB);
    
    if ( !(convert >> navY))
    {
        navY = 0;
    }
    
    return navY;
}

double dateInput ()
{
    double date;
    
    std::cin >> date;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    while (std::cin.fail())
    {
        std::cout << "Please enter a numeric date." << std::endl;
        std::cin.clear();
        std::cin.ignore(1024, '\n');
        std::cin >> date;
        std::cin.ignore(1024, '\n');
    }

    return date;
}

int printResults (int navZ, int navY, double date, double newdate, std::string calName1, std::string calName2)
{
/*
    double newdate;
    std::string calName1;
    std::string calName2;
 */
    //std::cout<<"DEBUG :::::  Date Inside Print Results: "<<date<<std::endl;
    if (navZ == 1 && navY == 1)
    {
        //newdate = dateCalc1(date, newdate);
        //date = dateInput();
       
        
        if (date > 2183)
        {
            calName1 = "A.S.";
            calName2 = "E.E.";
        }
        if ((date >= 0) && (date < 2183))
        {
            calName1 = "A.S.";
            calName2 = "T.E.";
        }
        if (date < 0)
        {
            calName1 = "E.S.";
            calName2 = "T.E.";
        }
        
        if (date >= 0)
        {
           std::cout << "The year " << date << " in " << calName1 << " is the year " << newdate << " in " << calName2 << std::endl;
        }
        if (date < 0)
        {
            std::cout << "The year " << -date << " in " << calName1 << " is the year " << newdate << " in " << calName2 << std::endl;
        }
            

    }
    
    if (navZ == 1 && navY == 2)
    {
        if (date >= 2574)
        {
            calName1 = "A.S.";
            calName2 = "X.E.";
        }
        if ((date >= 0) && (date < 2574))
        {
            calName1 = "A.S.";
            calName2 = "G.E.";
        }
        if (date < 0 )
        {
            calName1 = "E.S.";
            calName2 = "G.E.";
        }
        if (date >= 0)
        {
            std::cout << "The year " << date << " in " << calName1 << " is the year " << newdate << " in " << calName2 << std::endl;
        }
        if (date < 0)
        {
            std::cout << "The year " << -date << " in " << calName1 << " is the year " << newdate << " in " << calName2 << std::endl;
        }
        
    }
    
    if (navZ == 2 && navY == 1)
    {
        if (date >= 0)
        {
            calName1 = "E.E.";
            calName2 = "A.S.";
        }
        if ((date < 0) && (date > -2182))
        {
            calName1 = "T.E.";
            calName2 = "A.S.";
        }
        if (date <= -2183)
        {
            calName1 = "T.E.";
            calName2 = "E.S.";
        }
        if (date > -2183)
        {
            std::cout << "The year " << date << " in " << calName1 << " is the year " << newdate << " in " << calName2 << std::endl;
        }
        if (date <= -2183)
        {
            std::cout << "The year " << -date << " in " << calName1 << " is the year " << newdate << " in " << calName2 << std::endl;
        }
    }
    if (navZ == 2 && navY == 2)
    {
        if (date >= 143.0813)
        {
            calName1 = "E.E.";
            calName2 = "X.E.";
        }
        if ((date < 143.0813) && (date >= 0))
        {
            calName1 = "E.E.";
            calName2 = "G.E.";
        }
        if (date < 0)
        {
            calName1 = "T.E.";
            calName2 = "G.E.";
        }
       
        if (date >= 0) //This formula requires an additional if statment to account for the possible conditions created by the reality of working with calendars that measure time differently, rather than simply starting at different points.
        {
            std::cout << "The year " << date << " in " << calName1 << " is the year " << newdate << " in " << calName2 << std::endl;
        }
        if ((date < 0) && (date >= -143.0813))
        {
           std::cout << "The year " << -date << " in " << calName1 << " is the year " << newdate << " in " << calName2 << std::endl;
        }
        if (date < -143.0183)
        {
            std::cout << "The year " << -date << " in " << calName1 << " is the year " << newdate << " in " << calName2 << std::endl;
        }
    }
    if (navZ == 3 && navY == 1)
    {
        if (date >= 0)
        {
            calName1 = "X.E.";
            calName2 = "A.S.";
        }
        if ((date < 0) && (date > -939.5189))
        {
            calName1 = "G.E.";
            calName2 = "A.S.";
        }
        if (date <= -939.5189)
        {
            calName1 = "G.E.";
            calName2 = "E.S.";
        }
        
        if (date >= 0)
        {
            std::cout << "The year " << date << " in " << calName1 << " is the year " << newdate << " in " << calName2 << std::endl;
        }
        if ((date < 0) && (date > -939.5189))
        {
            std::cout << "The year " << -date << " in " << calName1 << " is the year " << newdate << " in " << calName2 << std::endl;
        }
        if (date <= -939.5189)
        {
            std::cout << "The year " << -date << " in " << calName1 << " is the year " << newdate << " in " << calName2 << std::endl;
        }
    }
    if (navZ == 3 && navY == 2)
    {
        if (date >= 0)
        {
            calName1 = "X.E.";
            calName2 = "E.E.";
        }
        if ((date < 0) && (date > -143.0813))
        {
            calName1 = "G.E.";
            calName2 = "E.E.";
        }
        if (date <= -143.0813)
        {
            calName1 = "G.E.";
            calName2 = "T.E.";
        }
        if (date >= 0)
        {
            std::cout << "The year " << date << " in " << calName1 << " is the year " << newdate << " in " << calName2 << std::endl;
        }
        if ((date < 0) && (date > -143.0813))
        {
            std::cout << "The year " << -date << " in " << calName1 << " is the year " << newdate << " in " << calName2 << std::endl;
        }
        if (date <= -143.0813)
        {
            std::cout << "The year " << -date << " in " << calName1 << " is the year " << newdate << " in " << calName2 << std::endl;
        }
    }

    
    return 0;
}

//***************************Calculations***************************

double dateCalc1 (double date, double newdate)
{
    
//    std::cout << " - - - - - - - - - - - - " << std::endl;
//    std::cout << "Please enter the date you wish to convert from Aeon Series to the Elbert Era:" << std::endl;
    
    //date = dateInput();
    
    
    if (date >= 2183)
    {
        newdate = date - 2182;
    }
    if ((date >= 0) && (date < 2183))
    {
        newdate = -date + 2182;
    }
    if (date < 0)
    {
        newdate = -date + 2182;
    }
    
    return newdate;
}

double dateCalc2 (double date, double newdate)
{
    if (date >= 2574)
    {
        newdate = (date / 2.7397) - 939.5189;
    }
    if ((date >= 0) && (date < 2574))
    {
        newdate = (-date / 2.7397) + 939.5189;
    }
    if (date < 0 )
    {
        newdate = (-date / 2.7397) + 939.5189;
    }
    
    return newdate;
}

double dateCalc3 (double date, double newdate)
{
    if (date >= 0)
    {
        newdate = date + 2182;
    }
    if ((date < 0) && (date > -2182))
    {
        newdate = 2182 - -date;
    }
    if (date <= -2183)
    {
        newdate = 2181 - -date;
    }

    return newdate;
}

double dateCalc4 (double date, double newdate)
{
    if (date >= 0)
    {
        newdate = (date / 2.7397);// - 143.0813;
    }
    if ((date < 0) && (date >= -143.0813))
    {
        newdate = (-date/2.7397);// + 143.0813;
    }
    if (date < -143.0813)
    {
        newdate = (-date /2.7397);// + 143.0813;
    }
    
    return newdate;
}

double dateCalc5 (double date, double newdate)
{
    if (date >= 0)
    {
        newdate = (2.7397 * date) + 2574;
    }
    if ((date < 0) && (date > -939.5189))
    {
        newdate = (2.7397 * date) + 2574;
    }
    if (date <= -939.5189)
    {
        newdate = (2.7397 * -date) - 2574;
    }
    return newdate;
}

double dateCalc6 (double date, double newdate)
{
    if (date >= 0)
    {
        newdate = (2.7397 * date) + 392.0;
    }
    if ((date < 0) && (date > -143.0813))
    {
        newdate = (2.7397 * date) + 392.0;
    }
    if (date <= -143.0813)
    {
        newdate = (2.7397 * -date) - 392.0;
    }
    return newdate;
}


//***************************CONVERSIONS***************************

/* int conversion1 (double date)
{
    
    std::cout << " - - - - - - - - - - - - " << std::endl;
    std::cout << "Please enter the date you wish to convert from Aeon Series to the Elbert Era:" << std::endl;
    
    date = dateInput(); // This function SHOULD theoretically perform the same task the code did before, and streamline the program.
    
    if (date > 2183)
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "The year " << date << " A.S. is equivalent to: " << date - 2182 << " E.E." << std::endl; //This formula converts Aeon Series into Elbert Era.
        std::cout << " - - - - - - - - - - - - " << std::endl;
    }
    if ((date >= 0) && (date < 2183))
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "The year " << date << " A.S. is equivalent to: " << -date + 2182 << " T.E." << std::endl; //This accounts for the overlap period between A.S. and T.E.
        std::cout << " - - - - - - - - - - - - " << std::endl;
    }
    if (date < 0)
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "The year " << -date << " E.S. is equivalent to: " << -date + 2182 << " T.E." << std::endl;  //This formula reverses the dates to their opposite scales, and converts ?? to Terran Era.
        std::cout << " - - - - - - - - - - - - " << std::endl;
    }
    
    
    return 0;
}

int conversion2 (double date)
{
    
    std::cout << " - - - - - - - - - - - - " << std::endl;
    std::cout << "Please enter the date you wish to convert from Aeon Series to the Xix Era:" << std::endl;
    
    date = dateInput();
    
    if (date >= 2574)
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "The year " << date << " A.S. is equivalent to: " << (date / 2.7397) - 939.5189 << " X.E." << std::endl; //Primary calendar formula 2
        std::cout << " - - - - - - - - - - - - " << std::endl;
    }
    if ((date >= 0) && (date < 2574))
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "The year " << date << " A.S. is equivalent to: " << (-date / 2.7397) + 939.5189 << " G.E." << std::endl; //Overlap formula 2
        std::cout << " - - - - - - - - - - - - " << std::endl;
    }
    if (date < 0 )
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "The year " << -date << " E.S. is equivalent to: " << (-date / 2.7397) + 939.5189 << " G.E." << std::endl; //Reversal formula 2
        std::cout << " - - - - - - - - - - - - " << std::endl;
    }
    
    
    return 0;

}

int conversion3 (double date)
{
    
    std::cout << " - - - - - - - - - - - - " << std::endl;
    std::cout << "Please enter the date you wish to convert from the Elbert Era to Aeon Series:" << std::endl;
    
    date = dateInput();
    
    if (date >= 0)
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "The year " << date << " E.E. is equivalent to: " << date + 2182 << " A.S." << std::endl; //Primary calendar formula 3
        std::cout << " - - - - - - - - - - - - " << std::endl;
    }
    if ((date < 0) && (date > -2182))
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "The year " << -date << " T.E. is equivalent to: " << 2182 - -date << " A.S." << std::endl; //Overlap formula 3
        std::cout << " - - - - - - - - - - - - " << std::endl;
    }
    if (date <= -2183)
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "The year " << -date << " T.E. is equivalent to: " << 2182 - -date << " E.S." << std::endl; //Reversal formula 3
        std::cout << " - - - - - - - - - - - - " << std::endl;
    }
    
    
    return 0;
}

int conversion4 (double date)
{
    
    std::cout << " - - - - - - - - - - - - " << std::endl;
    std::cout << "Please enter the date you wish to convert from the Elbert Era to the Xix Era:" << std::endl;
    
    date = dateInput();
    
    if (date >= 0)
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "The year " << date << " E.E. is equivalent to: " << (date / 2.7397) - 143.0813 << " X.E." << std::endl; //Primary calendar formula 4
        std::cout << " - - - - - - - - - - - - " << std::endl;
    }
    if ((date < 0) && (date > -143.0813))
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "The year " << -date << " E.E. is equivalent to: " << (-date/2.7397) + 143.0813 << " G.E." << std::endl; //Overlap formula 4
        std::cout << " - - - - - - - - - - - - " << std::endl;
    }
    if (date <= -143.0813)
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "The year " << -date - 143.0813 << " T.E. is equivalent to: " << (-date /2.7397) + 143.0813 << " G.E." << std::endl; //Reversal formula 4; this formula has an ugly hole patched in it - the subtraction of 143.0813 on the input variable.  It does work, though.
        std::cout << " - - - - - - - - - - - - " << std::endl;
    }
    
    
    return 0;
}

int conversion5 (double date)
{
    
    std::cout << " - - - - - - - - - - - - " << std::endl;
    std::cout << "Please enter the date you wish to convert from the Xix Era to Aeon Series:" << std::endl;
    
    date = dateInput();
    
    if (date >= 0)
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "The year " << date << " X.E. is equivalent to: " << (2.7397 * date) + 2574 << " A.S." << std::endl; //Primary calendar formula 5
        std::cout << " - - - - - - - - - - - - " << std::endl;
    }
    if ((date < 0) && (date > -939.5189))
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "The year " << -date << " G.E. is equivalent to: " << (2.7397 * date) + 2574 << " A.S." << std::endl; //Overlap formula 5
        std::cout << " - - - - - - - - - - - - " << std::endl;
    }
    if (date <= -939.5189)
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "The year " << -date << " G.E. is equivalent to: " << (2.7397 * -date) - 2574 << " E.S." << std::endl; //Reversal 5
        std::cout << " - - - - - - - - - - - - " << std::endl;
    }
    
    
    return 0;
}

int conversion6 (double date)
{
    std::cout << " - - - - - - - - - - - - " << std::endl;
    std::cout << "Please enter the date you wish to convert from the Xix Era to the Elbert Era:" << std::endl;
    
    date = dateInput();
    
    if (date >= 0)
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "The year " << date << " X.E. is equivalent to: " << (2.7397 * date) + 392.0 << " E.E." << std::endl; //Formula 6
        std::cout << " - - - - - - - - - - - - " << std::endl;
    }
    if ((date < 0) && (date > -143.0813))
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "The year " << -date << " G.E. is equivalent to: " << (2.7397 * date) + 392.0 << " E.E." << std::endl; //Formula 6
        std::cout << " - - - - - - - - - - - - " << std::endl;
    }
    if (date <= -143.0813)
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "The year " << -date << " G.E. is equivalent to: " << (2.7397 * -date) - 392.0 << " T.E." << std::endl; //Reversal 6
        std::cout << " - - - - - - - - - - - - " << std::endl;
    }
    
    
    return 0;
}

*/

/*  The function 'input' should link into the conversion functions, not the main function.
 /
 /  Function definitions need to be AFTER the main.  Declarations come before.
 /
 */
