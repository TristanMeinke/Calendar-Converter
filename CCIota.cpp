/* This project is the continued refinement of the Calendar Converter project.  It allows the conversion of dates from one
 /  fictional calendar to another, designed at primarily as a tool to improve ease of writing.  Since it's original
 /  conception, it has become something of an academic exercise in flow control and error handling.
 /  *************************************************Version History********************************************************
 /  - Version Alpha was an initial attempt at designing and implementing the conversion formulas, as well as a first design of
 /  the flow control to necessary to take the input from the user and display the output.
 /  - Version Beta implemented superior flow control and the first experiments in error handling.
 /  - Version Gamma implemented string input and string to int conversion, as well as solving input errors still present
 /  in version Beta.  Additionally, this version allowed implemented a dual variable menu, anticipating a reasonable expansion
 /  of the calendars available in later versions.
 /  - Vesrion Delta was intended to break the program down into separate functions designed to work in concert to achieve their
 /  goal.  Learning experience.
 /  -Version Epsilon was intended to streamline the lesser functions and string input.  Epsilon was also be designed to
 /  compensate for rounding errors.
 /  - Version Zeta was created in order to remove dead code (while preserving it in version epsilon), and rework the conversion
 /  formulas for accuracy and cleanliness.  Variable and function names are also altered in the interest of clarity.
 /  - Versrion Eta implemented new functionality.  The main new feature included is the option to calculate one calendar into
 /  all the others.  At present, it only converts to two others, but in theory, it might one day spit out quite a list.  In
 /  order to accomplish this goal, variable 'newdate' removed and supplemented with six more specific replacements, which
 /  ultimately is better anyway, rather than having six functions return the same variable.  With the addition of the
 /  'printResultsOneToAll' function, the 'printResults' function was renamed 'printSingleResults' in the interest of clarity.
 /  Somewhat secondary to the very useful printAll, the function getSnarky was added for this version.  It gets snarky with
 /  the user, particularly over failed input.
 /  - Version Theta added conversions for the Carnon Time  calendar, and completes the functionality of getSnarky 
 /  (though leaving room for further development).  Additionally, this version compressed
 /  the code of the major print functions by implementing individual print functions for each calculation.
 /  - Version Iota implements a new menu option to the first calendar selector, allowing for more
 /  versatile multiple-conversion options.  Better commenting, and an expansion of the getSnarky responses will be
 /  programmed for this version as well.  Like certain versions, dead code has been removed, and preserved in archived
 /  versions.  As usual, there have been some changes to names of functions and variables to keep up with the times.
 /  Another goal for this version is to fully implement the snarky messages in getSnarky, rather than just the code.
 /  Additionally, getSnarkyImTooDumbForThat might be fun, for reminding the user to use simple input. functions 
 /  datecalcXEtoCT and outputXEtoCT have both been repaired.  Finally, version Iota adds the early prototypes of full date 
 /  conversion, which is to say that it can now convert the decimal remainder of two calendars into 'months' and 'weeks' and 
 /  'days' of sorts. The original was based on user input, but it can now do so automatically. Eventually, it is the goal to 
 /  implement this for all calendars, correct for negative input error, and make the action reversible, so that the program can 
 /  take input in full calendar dates.
 /  ************************************************************************************************************************
 /  Created by Tristan Meinke on 10/30/15.
 /  Copyright © 2015 Tristan Meinke. All rights reserved.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cmath>



//********************Function Declarations********************

int menu (std::string &selectCalA, std::string &selectCalB, int &navCalY, int &navCalZ);  //this function implements the main menu, taking string input fromt the user and converting it to integers so that they can more easily activate and interact with the other functions.

int calSelect1 ();
int calSelect2 ();

std::string exitInput1 ();

std::string LoopInput1 (std::string &navLoopD);
std::string LoopInput2 (std::string &navLoopE);
std::string LoopInput3 (std::string &navLoopF);
std::string LoopInput4 (std::string &navLoopG);
std::string LoopInput5 (std::string &navLoopH);
std::string LoopInput6 (std::string &navLoopI);
std::string LoopInput7 (std::string &navLoopJ);
std::string LoopInput8 (std::string &navLoopK);
std::string LoopInput9 (std::string &navLoopL);
std::string LoopInput10 (std::string &navLoopM);

double dateInput (); //function takes input of date in double floating point, and saves it for later use.

double fractionInput1 (); //function saves input data for converting decimals to calendar fractions in Carnon Time 
double fractionInput2 (); //function saves input data for converting decimals to calendar fractions in Xix Era , and calendars which don't require a special conversion.

double dateCalcAStoCT (double &date, double &newdateAStoCT);
double dateCalcAStoEE (double &date, double &newdateAStoEE);
double dateCalcAStoXE (double &date, double &newdateAStoXE);
double dateCalcCTtoAS (double &date, double &newdateCTtoAS);
double dateCalcCTtoEE (double &date, double &newdateCTtoEE);
double dateCalcCTtoXE (double &date, double &newdateCTtoXE);
double dateCalcEEtoAS (double &date, double &newdateEEtoAS);
double dateCalcEEtoCT (double &date, double &newdateEEtoCT);
double dateCalcEEtoXE (double &date, double &newdateEEtoXE);
double dateCalcXEtoAS (double &date, double &newdateXEtoAS);
double dateCalcXEtoCT (double &date, double &newdateXEtoCT);
double dateCalcXEtoEE (double &date, double &newdateXEtoEE);

int outCalcRemainderXE (double &newdateAStoXE);
void outCalcWeeksDaysXE(int remainingDays, int daysInWeekXE);

int outCalcRemainderCT (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateAStoCT);
void outCalcWeeksDaysCT(int remainingDays, int daysInWeekCT);

int outputAStoCT (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateAStoCT);
int outputAStoEE (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateAStoEE);
int outputAStoXE (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateAStoXE);
int outputCTtoAS (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateCTtoAS);
int outputCTtoEE (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateCTtoEE);
int outputCTtoXE (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateCTtoXE);
int outputEEtoAS (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateEEtoAS);
int outputEEtoCT (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateEEtoCT);
int outputEEtoXE (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateEEtoXE);
int outputXEtoAS (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateXEtoAS);
int outputXEtoCT (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateXEtoCT);
int outputXEtoEE (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateXEtoCT);

int printSingleResults (int navCalZ, int navCalY, double date, double newdateAStoCT, double newdateAStoEE, double newdateAStoXE, double newdateEEtoAS, double newdateEEtoCT, double newdateEEtoXE, double newdateXEtoAS, double newdateXEtoCT, double newdateXEtoEE, double newdateCTtoAS, double newdateCTtoEE, double newdateCTtoXE, std::string calName1, std::string calName2); //Prints the results

int printResultsOneToAll (int navCalZ, int navCalY, double date, double newdateAStoCT, double newdateAStoEE, double newdateAStoXE, double newdateEEtoAS, double newdateEEtoCT, double newdateEEtoXE, double newdateXEtoAS, double newdateXEtoCT, double newdateXEtoEE, double newdateCTtoAS, double newdateCTtoEE, double newdateCTtoXE, std::string calName1, std::string calName2); //Prints all conversions from one calendar

int printResultsAllToOne (int navCalZ, int navCalY, double date, double newdateAStoCT, double newdateAStoEE, double newdateAStoXE, double newdateEEtoAS, double newdateEEtoCT, double newdateEEtoXE, double newdateXEtoAS, double newdateXEtoCT, double newdateXEtoEE, double newdateCTtoAS, double newdateCTtoEE, double newdateCTtoXE, std::string calName1, std::string calName2);

int printAllResults (int navCalZ, int navCalY, double date, double newdateAStoCT, double newdateAStoEE, double newdateAStoXE, double newdateEEtoAS, double newdateEEtoCT, double newdateEEtoXE, double newdateXEtoAS, double newdateXEtoCT, double newdateXEtoEE, double newdateCTtoAS, double newdateCTtoEE, double newdateCTtoXE, std::string calName1, std::string calName2);

std::string getSnarky (std::string &navLoopC, std::string &navLoopD, int &n, int &i);
std::string getSnarkyGrammar (std::string &navLoopC);
std::string getSnarkyTone (std::string &navLoopC);

//double modf (double newdateAStoXE, double* &wholeYearsXE); //Very uncertain if this is necessary...  Seems like it's defined in <cmath>

//****************************MAIN*****************************

int main()
{
    std::string selectCalA;  //First calendar navigator, which is later converted to navCalZ (an int) for ease of manipulation.
    std::string selectCalB;  //Second calendar navigator, which is later converted to navCalY (an int) for ease of manipulation.
    std::string navLoopC;//Final calendar navigator to be input; left as a string so that it can terminate the program or loop with words in addition to characters.
    
    int navCalZ = 0;  //Secondary navigator for the first calendar.
    int navCalY = 0;  //Secondary navigator for the second calendar.
    
    double date = 0.0;
    
    double newdateAStoEE = 0.0;
    double newdateAStoXE = 0.0;
    double newdateAStoCT = 0.0;
    double newdateEEtoAS = 0.0;
    double newdateEEtoXE = 0.0;
    double newdateEEtoCT = 0.0;
    double newdateXEtoAS = 0.0;
    double newdateXEtoEE = 0.0;
    double newdateXEtoCT = 0.0;
    double newdateCTtoAS = 0.0;
    double newdateCTtoEE = 0.0;
    double newdateCTtoXE = 0.0;
    
    std::string calName1;
    std::string calName2;
    
    int irritation = 0;
    int i = 0;
    std::string navLoopD; //A navigator variable used for controlling the function getSnarky.
    std::string navLoopE;
    std::string navLoopF;
    std::string navLoopG;
    std::string navLoopH;
    std::string navLoopI;
    std::string navLoopJ;
    std::string navLoopK;
    std::string navLoopL;
    std::string navLoopM;
    std::string navLoopN;
    
    std::cout << "Welcome to the Terran Calendar Converter. This tool will convert calendar dates to other dating systems, but only those " << std::endl << "used by human societies.  We intend to account for alien calendars at a later time, and thank youfor your patience." << std::endl << "When using this tool, please mind changes in notation, as this converter does not display negative dates." << std::endl;
    
    do
    {
        menu (selectCalA, selectCalB, navCalY, navCalZ); //calls the menu function
        
//Below are the conditions and navigations which lead to the varied calculator functions.  Each if statement
//contains an input function and at least one calculator function.
        
        if (navCalZ == 1 && navCalY == 1) //if these conditions are met
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert from Aeon Series to Carnon Time :" << std::endl;
            
            date = dateInput(); //Calls a function which allows the user to input the numeric date they wish to convert
            
            newdateAStoCT = dateCalcAStoCT(date, newdateAStoCT); //Calls the first calculator for Aeon Series to Carnon Time 
        }
        if (navCalZ == 1 && navCalY == 2) //if these conditions are met
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert from Aeon Series to the Elbert Era :" << std::endl;
            
            date = dateInput(); //Calls a function which allows the user to input the numeric date they wish to convert
            
            newdateAStoEE = dateCalcAStoEE(date, newdateAStoEE); //Calls the first calculator for Aeon Series to Elbert Era 
        }
        if (navCalZ == 1 && navCalY == 3)
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert from Aeon Series to the Xix Era :" << std::endl;
            
            date = dateInput();
            
            newdateAStoXE = dateCalcAStoXE(date, newdateAStoXE); //Calls the calculator for Aeon Series to Xix Era 
            
        }
        if (navCalZ == 1 && navCalY == 4)
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert from Aeon Series:" << std::endl;
            
            date = dateInput();
            
            newdateAStoCT = dateCalcAStoCT(date, newdateAStoCT); //Calls the conversion AS to CT to be printed in a list
            newdateAStoEE = dateCalcAStoEE(date, newdateAStoEE); //Calls the conversion AS to EE to be printed in a list
            newdateAStoXE = dateCalcAStoXE(date, newdateAStoXE); //Calls the conversion AS to XE to be printed in a list
        }
        if (navCalZ == 2 && navCalY == 1)
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert from Carnon Time  to Aeon Series:" << std::endl;
            
            date = dateInput();
            
            newdateCTtoAS = dateCalcCTtoAS(date, newdateCTtoAS);
        }
        if (navCalZ == 2 && navCalY == 2)
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert from Carnon Time  to the Elbert Era :" << std::endl;
            
            date = dateInput();
            
            newdateCTtoEE = dateCalcCTtoEE(date, newdateCTtoEE);
        }
        if (navCalZ == 2 && navCalY == 3)
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert from Carnon Time  to the Xix Era :" << std::endl;
            
            date = dateInput();
            
            newdateCTtoXE = dateCalcCTtoXE(date, newdateCTtoXE);
        }
        if (navCalZ == 2 && navCalY == 4)
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert from Carnon Time :" << std::endl;
            
            date = dateInput();
            
            newdateCTtoAS = dateCalcCTtoAS(date, newdateCTtoAS); //Calls the conversion CT to AS to be printed in a list
            newdateCTtoEE = dateCalcCTtoEE(date, newdateCTtoEE); //Calls the conversion CT to EE to be printed in a list
            newdateCTtoXE = dateCalcCTtoXE(date, newdateCTtoXE); //Calls the conversion CT to XE to be printed in a list
        }
        if (navCalZ == 3 && navCalY == 1)
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert from the Elbert Era  to Aeon Series:" << std::endl;
            
            date = dateInput();
            
            newdateEEtoAS = dateCalcEEtoAS(date, newdateEEtoAS);
        }
        if (navCalZ == 3 && navCalY == 2)
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert from the Elbert Era  to Carnon Time :" << std::endl;
            
            date = dateInput();
            
            newdateEEtoCT = dateCalcEEtoCT(date, newdateEEtoCT); //Calls the fourth conversion option
        }
        if (navCalZ == 3 && navCalY == 3)
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert from the Elbert Era  to the Xix Era :" << std::endl;
            
            date = dateInput();
            
            newdateEEtoXE = dateCalcEEtoXE(date, newdateEEtoXE); //Calls the fourth conversion option
        }
        if (navCalZ == 3 && navCalY ==4)
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert from the Elbert Era :" << std::endl;
            
            date = dateInput();
            
            newdateEEtoAS = dateCalcEEtoAS(date, newdateEEtoAS); //Calls the conversion EE to AS to be printed in a list
            newdateEEtoCT = dateCalcEEtoCT(date, newdateEEtoCT); //Calls the conversion EE to CT to be printed in a list
            newdateEEtoXE = dateCalcEEtoXE(date, newdateEEtoXE); //Calls the conversion EE to XE to be printed in a list
        }
        if (navCalZ == 4 && navCalY == 1)
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert from Xix Era  to Aeon Series:" << std::endl;
            
            date = dateInput();
            
            newdateXEtoAS = dateCalcXEtoAS(date, newdateXEtoAS); //Calls the fifth conversion option
            
        }
        if (navCalZ == 4 && navCalY == 2)
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert from the Xix Era  to Carnon Time ." << std::endl;
            
            date = dateInput();
            
            newdateXEtoCT = dateCalcXEtoCT(date, newdateXEtoCT); //Calls the sixth conversion option
        }
        if (navCalZ == 4 && navCalY == 3)
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert from the Xix Era  to the Elbert Era :" << std::endl;
            
            date = dateInput();
            
            newdateXEtoEE = dateCalcXEtoEE(date, newdateXEtoEE); //Calls the sixth conversion option
        }
        if (navCalZ == 4 && navCalY == 4)
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert from the Xix Era :" << std::endl;
            
            date = dateInput();
            
            newdateXEtoAS = dateCalcXEtoAS(date, newdateXEtoAS); //Calls the conversion XE to AS to be printed in a list
            newdateXEtoCT = dateCalcXEtoCT(date, newdateXEtoCT); //Calls the conversion XE to CT to be printed in a list
            newdateXEtoEE = dateCalcXEtoEE(date, newdateXEtoEE); //Calls the conversion XE to EE to be printed in a list
        }
        if (navCalZ == 5 && navCalY == 1)
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert to Aeon Series:" << std::endl;
            
            date = dateInput();
            
            newdateCTtoAS = dateCalcCTtoAS(date, newdateCTtoAS); //Calls the conversion CT to AS to be printed in a list
            newdateEEtoAS = dateCalcEEtoAS(date, newdateEEtoAS); //Calls the conversion EE to AS to be printed in a list
            newdateXEtoAS = dateCalcXEtoAS(date, newdateXEtoAS); //Calls the conversion XE to AS to be printed in a list

        }
        if (navCalZ ==5 && navCalY == 2)
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert to Carnon Time :" << std::endl;
        
            date = dateInput();
            
            newdateAStoCT = dateCalcAStoCT(date, newdateAStoCT); //Calls the conversion AS to CT to be printed in a list
            newdateEEtoCT = dateCalcEEtoCT(date, newdateEEtoCT); //Calls the conversion EE to CT to be printed in a list
            newdateXEtoCT = dateCalcXEtoCT(date, newdateXEtoCT); //Calls the conversion XE to CT to be printed in a list

        }
        if (navCalZ == 5 && navCalY == 3)
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert to the Elbert Era :" << std::endl;
            
            date = dateInput();
            
            newdateAStoEE = dateCalcAStoEE(date, newdateAStoEE); //Calls the conversion AS to EE to be printed in a list
            newdateCTtoEE = dateCalcCTtoEE(date, newdateCTtoEE); //Calls the conversion CT to EE to be printed in a list
            newdateXEtoEE = dateCalcXEtoEE(date, newdateXEtoEE); //Calls the conversion XE to EE to be printed in a list
            
        }
        if (navCalZ == 5 && navCalY == 4)
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert to the Xix Era :" << std::endl;
            
            date = dateInput();
            
            newdateAStoXE = dateCalcAStoXE(date, newdateAStoXE); //Calls the conversion AS to XE to be printed in a list
            newdateCTtoXE = dateCalcCTtoXE(date, newdateCTtoXE); //Calls the conversion CT to XE to be printed in a list
            newdateEEtoXE = dateCalcEEtoXE(date, newdateEEtoXE); //Calls the conversion EE to XE to be printed in a list
        }
        if (navCalZ == 5 && navCalY == 5)
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "Please enter the date you wish to convert:" << std::endl;
            
            date = dateInput();
            
            newdateAStoCT = dateCalcAStoCT(date, newdateAStoCT); //Calls the conversion AS to CT to be printed in a list
            newdateAStoEE = dateCalcAStoEE(date, newdateAStoEE); //Calls the conversion AS to EE to be printed in a list
            newdateAStoXE = dateCalcAStoXE(date, newdateAStoXE); //Calls the conversion AS to XE to be printed in a list
            newdateCTtoAS = dateCalcCTtoAS(date, newdateCTtoAS); //Calls the conversion CT to AS to be printed in a list
            newdateCTtoEE = dateCalcCTtoEE(date, newdateCTtoEE); //Calls the conversion CT to EE to be printed in a list
            newdateCTtoXE = dateCalcCTtoXE(date, newdateCTtoXE); //Calls the conversion CT to XE to be printed in a list
            newdateEEtoAS = dateCalcEEtoAS(date, newdateEEtoAS); //Calls the conversion EE to AS to be printed in a list
            newdateEEtoCT = dateCalcEEtoCT(date, newdateEEtoCT); //Calls the conversion EE to CT to be printed in a list
            newdateEEtoXE = dateCalcEEtoXE(date, newdateEEtoXE); //Calls the conversion EE to XE to be printed in a list
            newdateXEtoAS = dateCalcXEtoAS(date, newdateXEtoAS); //Calls the conversion XE to AS to be printed in a list
            newdateXEtoCT = dateCalcXEtoCT(date, newdateXEtoCT); //Calls the conversion XE to CT to be printed in a list
            newdateXEtoEE = dateCalcXEtoEE(date, newdateXEtoEE); //Calls the conversion XE to EE to be printed in a list
        }
// Below are the print functions, which use the output functions as intermediaries to run between
//them and the calculator functions.
        
        if (navCalZ < 5 && navCalY < 4)
        {
            printSingleResults (navCalZ, navCalY, date, newdateAStoCT, newdateAStoEE, newdateAStoXE, newdateEEtoAS, newdateEEtoCT, newdateEEtoXE, newdateXEtoAS, newdateXEtoCT, newdateXEtoEE, newdateCTtoAS, newdateCTtoEE, newdateCTtoXE, calName1, calName2);
        }
        if (navCalZ < 5 && navCalY == 4 )
        {
            printResultsOneToAll (navCalZ, navCalY, date, newdateAStoCT, newdateAStoEE, newdateAStoXE, newdateEEtoAS, newdateEEtoCT, newdateEEtoXE,newdateXEtoAS, newdateXEtoCT,newdateXEtoEE, newdateCTtoAS, newdateCTtoEE, newdateCTtoXE, calName1, calName2);
        }
        if (navCalZ == 5 && navCalY < 5)
        {
            printResultsAllToOne (navCalZ, navCalY, date, newdateAStoCT, newdateAStoEE, newdateAStoXE, newdateEEtoAS, newdateEEtoCT, newdateEEtoXE,newdateXEtoAS, newdateXEtoCT,newdateXEtoEE, newdateCTtoAS, newdateCTtoEE, newdateCTtoXE, calName1, calName2);
        }
        if (navCalZ == 5 && navCalY == 5)
        {
            printAllResults (navCalZ, navCalY, date, newdateAStoCT, newdateAStoEE, newdateAStoXE, newdateEEtoAS, newdateEEtoCT, newdateEEtoXE,newdateXEtoAS, newdateXEtoCT,newdateXEtoEE, newdateCTtoAS, newdateCTtoEE, newdateCTtoXE, calName1, calName2);
        }
            
            
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "Would you like to make another calculation?" << std::endl;
        std::cout << "Enter 'yes' to return to the main menu, enter 'no' to end the program." << std::endl;
        std::cout << " - - - - - - - - - - - - " << std::endl;
        
        navLoopC = exitInput1(); //This is the exit or continue input for the do/while loop.
        
        while (navLoopC == "no." || navLoopC == "nO." || navLoopC == "yes." || navLoopC == "yeS." || navLoopC == "yES." || navLoopC == "YEs." || navLoopC == "YeS." || navLoopC == "yEs.")
        {
            getSnarkyGrammar(navLoopC);
        }
        while (navLoopC == "NO!" || navLoopC == "YES!" || navLoopC == "Yes!" || navLoopC == "No!" || navLoopC == "No?" || navLoopC == "Yes?")
        {
            getSnarkyTone(navLoopC);
        }
        while (navLoopC != "yes" && navLoopC != "y" && navLoopC != "Yes" && navLoopC != "Y" && navLoopC != "YES" && navLoopC != "YES." && navLoopC != "Yes." && navLoopC != "no" && navLoopC != "n" && navLoopC != "No" && navLoopC != "N" && navLoopC != "NO" && navLoopC != "NO." && navLoopC != "No.")
        {
            getSnarky(navLoopC, navLoopD, irritation, i); //getSnarky is deployed whenever bad input is entered to a loop.
            //This function demands proper input with increasingly agitated and sarcastic messages.
            
        }
    }
    while (navLoopC == "yes" || navLoopC == "y" || navLoopC == "Yes" || navLoopC == "Y" || navLoopC == "YES" || navLoopC == "YES." || navLoopC == "Yes."); //conditions for do/while reset
    
    if (navLoopC == "no" || navLoopC == "n" || navLoopC == "No" || navLoopC == "N" || navLoopC == "NO" || navLoopC == "NO." || navLoopC == "No.") //condtions for program exit
        std::cout << "Goodbye." << std::endl;
    
    
    return 0;
}

//*******************************MENUS******************************

int menu (std::string &selectCalA, std::string &selectCalB, int &navCalY, int &navCalZ)

{
    
    std::cout << " - - - - - - - - - - - - " << std::endl;
    std::cout << "Which Calendar would you like to convert from?" << std::endl; //Main menu
    std::cout << "Select '1' for Aeon Series." << std::endl;
    std::cout << "Select '2' for Carnon Time ." << std::endl;
    std::cout << "Select '3' for Elbert Era ." << std::endl;
    std::cout << "Select '4' for Xix Era ." << std::endl;
    std::cout << "Or select '5' to convert from all calendars." << std::endl;
    
    navCalZ = calSelect1();  //This function inputs the first navigator variable as a string and converts it to an int.
    
    while (navCalZ != 1 && navCalZ != 2 && navCalZ != 3 && navCalZ != 4 && navCalZ != 5)
    {
        
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "¡¡Error!!  ¡¡Error!! ¡¡Error Encountered!! - Please select a valid menu option." << std::endl; //Initial input error message and secondary menu prompt
        std::cout << "Select '1' for Aeon Series." << std::endl;
        std::cout << "Select '2' for Carnon Time ." << std::endl;
        std::cout << "Select '3' for Elbert Era ." << std::endl;
        std::cout << "Select '4' for Xix Era ." << std::endl;
        std::cout << "Or select '5' to convert from all calendars." << std::endl;
        
        
        navCalZ = calSelect1();
        
    }
    
    if (navCalZ == 1)
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "You have selected Aeon Series. Which calendar would you like to convert to?" << std::endl;
        std::cout << "Select '1' for Carnon Time ." << std::endl;
        std::cout << "Select '2' for Elbert Era ." << std::endl;
        std::cout << "Select '3' for Xix Era ." << std::endl;
        std::cout << "Select '4' for All." << std::endl;
        
        navCalY = calSelect2(); //Calls a function to input the second navigator variable, converting string to int.
        
        while (std::cin.fail())
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "¡¡Error!!  ¡¡Error!! ¡¡Error Encountered!! - Please select a valid calendar option to convert to." << std::endl; //selectCalB error message and secondary menu prompt at A.S. to ??
            std::cout << "Select '1' for Carnon Time ." << std::endl;
            std::cout << "Select '2' for Elbert Era ." << std::endl;
            std::cout << "Select '3' for Xix Era ." << std::endl;
            std::cout << "Select '4' for All." << std::endl;
        }
    }
    if (navCalZ == 2)
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "You have selected Carnon Time . Which calendar would you like to convert to?" << std::endl;
        std::cout << "Select '1' for Aeon Series." << std::endl;
        std::cout << "Select '2' for Elbert Era ." << std::endl;
        std::cout << "Select '3' for Xix Era ." << std::endl;
        std::cout << "Select '4' for All." << std::endl;
        
        navCalY = calSelect2(); //Re-inputs the second navigator.
        
        while (std::cin.fail())
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "¡¡Error!!  ¡¡Error!! ¡¡Error Encountered!! - Please select a valid calendar option to convert to." << std::endl; //selectCalB error message and secondary menu prompt at E.E. to ??
            std::cout << "Select '1' for Aeon Series." << std::endl;
            std::cout << "Select '2' for Elbert Era ." << std::endl;
            std::cout << "Select '3' for Xix Era ." << std::endl;
            std::cout << "Select '4' for All." << std::endl;
        }
    }
    if (navCalZ == 3)
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "You have selected the Elbert Era . Which calendar would you like to convert to?" << std::endl;
        std::cout << "Select '1' for Aeon Series." << std::endl;
        std::cout << "Select '2' for Carnon Time ." << std::endl;
        std::cout << "Select '3' for Xix Era ." << std::endl;
        std::cout << "Select '4' for All." << std::endl;
        
        navCalY = calSelect2(); //Re-inputs the second navigator.
        
        while (std::cin.fail())
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "¡¡Error!!  ¡¡Error!! ¡¡Error Encountered!! - Please select a valid calendar option to convert to." << std::endl; //selectCalB error message and secondary menu prompt at X.E. to ??
            std::cout << "Select '1' for Aeon Series." << std::endl;
            std::cout << "Select '2' for Cybernetic Era." << std::endl;
            std::cout << "Select '3' for Xix Era ." << std::endl;
            std::cout << "Select '4' for All." << std::endl;
        }
    }
    if (navCalZ == 4)
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "You have selected the Xix Era . Which calendar would you like to convert to?" << std::endl;
        std::cout << "Select '1' for Aeon Series." << std::endl;
        std::cout << "Select '2' for Carnon Time ." << std::endl;
        std::cout << "Select '3' for Elbert Era ." << std::endl;
        std::cout << "Select '4' for All." << std::endl;
        
        navCalY = calSelect2(); //Re-inputs the second navigator.
        
        while (std::cin.fail())
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "¡¡Error!!  ¡¡Error!! ¡¡Error Encountered!! - Please select a valid calendar option to convert to." << std::endl; //selectCalB error message and secondary menu prompt at X.E. to ??
            std::cout << "Select '1' for Aeon Series." << std::endl;
            std::cout << "Select '2' for Carnon Time ." << std::endl;
            std::cout << "Select '3' for Elbert Era ." << std::endl;
            std::cout << "Select '4' for All." << std::endl;
        }
    }
    if (navCalZ == 5)
    {
        std::cout << " - - - - - - - - - - - - " << std::endl;
        std::cout << "You have elected to convert from all calendars. Which calendar would you like to convert to?" << std::endl;
        std::cout << "Select '1' for Aeon Series." << std::endl;
        std::cout << "Select '2' for Carnon Time ." << std::endl;
        std::cout << "Select '3' for Elbert Era ." << std::endl;
        std::cout << "Select '4' for Xix Era ." << std::endl;
        std::cout << "Select '5' to enter the date into all calculators." << std::endl;
        
        navCalY = calSelect2(); //Re-inputs the second navigator.
        
        while (std::cin.fail())
        {
            std::cout << " - - - - - - - - - - - - " << std::endl;
            std::cout << "¡¡Error!!  ¡¡Error!! ¡¡Error Encountered!! - Please select a valid calendar option to convert to." << std::endl; //selectCalB error message and secondary menu prompt at X.E. to ??
            std::cout << "Select '1' for Aeon Series." << std::endl;
            std::cout << "Select '2' for Carnon Time ." << std::endl;
            std::cout << "Select '3' for Elbert Era ." << std::endl;
            std::cout << "Select '4' for Xix Era ." << std::endl;
            std::cout << "Select '5' to enter the date into all calculators." << std::endl;
            
        }
    }
    
    while (navCalY != 1 && navCalY != 2 && navCalY != 3 && navCalY != 4 && navCalY != 5)
    {
        
        std::cout << "¡¡Error!!  ¡¡Error!! ¡¡Error Encountered!! - Please enter a valid selection ('1', '2', '3' '4' or '5')." << std::endl; //third error message
        
        navCalY = calSelect2(); //Re-inputs the second navigator.
        
    }
    return 0;
}

//********************************INPUT**********************************


std::string exitInput1 ()  //This function either repeats the do/while loop or exits the program.
{
    std::string navLoopC;
    
    std::cin >> navLoopC;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Clears the input buffer preimptively to keep bad input from lurking in the wings.
    
    return navLoopC;
}

std::string LoopInput1 (std::string &navLoopD)
{
    // std::string navLoopD;
    
    std::cin >> navLoopD;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Clears the input buffer preimptively to keep bad input from lurking in the wings.
    
    return navLoopD;
}

std::string LoopInput2 (std::string &navLoopE)
{
    
    std::cin >> navLoopE;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Clears the input buffer preimptively to keep bad input from lurking in the wings.
    
    return navLoopE;
}

std::string LoopInput3 (std::string &navLoopF)
{
    
    std::cin >> navLoopF;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Clears the input buffer preimptively to keep bad input from lurking in the wings.
    
    return navLoopF;
}
std::string LoopInput4 (std::string &navLoopG)
{
    
    std::cin >> navLoopG;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Clears the input buffer preimptively to keep bad input from lurking in the wings.
    
    return navLoopG;
}
std::string LoopInput5 (std::string &navLoopH)
{
    
    std::cin >> navLoopH;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Clears the input buffer preimptively to keep bad input from lurking in the wings.
    
    return navLoopH;
}
std::string LoopInput6 (std::string &navLoopI)
{
    
    std::cin >> navLoopI;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Clears the input buffer preimptively to keep bad input from lurking in the wings.
    
    return navLoopI;
}
std::string LoopInput7 (std::string &navLoopJ)
{
    
    std::cin >> navLoopJ;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Clears the input buffer preimptively to keep bad input from lurking in the wings.
    
    return navLoopJ;
}
std::string LoopInput8 (std::string &navLoopK)
{
    
    std::cin >> navLoopK;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Clears the input buffer preimptively to keep bad input from lurking in the wings.
    
    return navLoopK;
}
std::string LoopInput9 (std::string &navLoopL)
{
    
    std::cin >> navLoopL;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Clears the input buffer preimptively to keep bad input from lurking in the wings.
    
    return navLoopL;
}
std::string LoopInput10 (std::string &navLoopM)
{
    
    std::cin >> navLoopM;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Clears the input buffer preimptively to keep bad input from lurking in the wings.
    
    return navLoopM;
}

int calSelect1 ()  //This function takes input from the user, allowing them to select the calendar they wish to convert from.
{
    std::string selectCalA;
    int navCalZ;
    
    std::cin >> selectCalA;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::stringstream convert(selectCalA);
    
    if ( !(convert >> navCalZ))
    {
        navCalZ = 0;
    }
    
    return navCalZ;
}

int calSelect2 () //This function takes input from the user, allowing them to select the calendar they wish to convert to.
{
    std::string selectCalB;
    int navCalY;
    
    std::cin >> selectCalB;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::stringstream convert(selectCalB);
    
    if ( !(convert >> navCalY))
    {
        navCalY = 0;
    }
    
    return navCalY;
}

double dateInput () //This function takes input from the user, allowing them to enter the numeric date they wish to convert.
{
    double date;
    
    std::cin >> date;
    
    while (std::cin.fail())
    {
        std::cout << "¡Error Encountered! - Please enter a numeric date." << std::endl;
        std::cin.clear();
        std::cin.ignore(1024, '\n');
        std::cin >> date;
        std::cin.ignore(1024, '\n');
    }
    
    return date;
}

double fractionInput1 () //This function takes input from the user, allowing them to enter the decimal of the numeric date they wish to convert to calendar fractions in Carnon Time .
{
    double fractionCT;
    
    std::cin >> fractionCT;
    
    while (std::cin.fail())
    {
        std::cout << "¡Error Encountered! - Please enter a numeric date." << std::endl;
        std::cin.clear();
        std::cin.ignore(1024, '\n');
        std::cin >> fractionCT;
        std::cin.ignore(1024, '\n');
    }
    
    fractionCT = fractionCT * 1.024;

    
    
    return fractionCT;
}

double fractionInput2 () //This function takes input from the user, allowing them to enter the decimal of the numeric
                         //date they wish to convert to calendar fractions in XE (or theoretically any calendar that
                         //does not require an adjustment, though a minor change in variable name would be in order).
{
    double fractionXE;
    
    std::cin >> fractionXE;
    
    while (std::cin.fail())
    {
        std::cout << "¡Error Encountered! - Please enter a numeric date." << std::endl;
        std::cin.clear();
        std::cin.ignore(1024, '\n');
        std::cin >> fractionXE;
        std::cin.ignore(1024, '\n');
    }
    
    return fractionXE;
}
//********************************OUTPUT*******************************

int printSingleResults (int navCalZ, int navCalY, double date, double newdateAStoCT, double newdateAStoEE, double newdateAStoXE, double newdateEEtoAS, double newdateEEtoCT, double newdateEEtoXE, double newdateXEtoAS, double newdateXEtoCT, double newdateXEtoEE, double newdateCTtoAS, double newdateCTtoEE, double newdateCTtoXE, std::string calName1, std::string calName2)
//This function prints the results of the last conversion entered, but since the do/while loop repeats the menu function, only
//one conversion is printed when this function is called, regardless of how many have been made during the run of the program.
{
    
    
    if (navCalZ == 1 && navCalY == 1) //This section prints the results for dateCalcAStoCT.
    {
        outputAStoCT(calName1, calName2, navCalZ, navCalY, date, newdateAStoCT);
        outCalcRemainderCT(calName1, calName2, navCalZ, navCalY, date, newdateAStoCT);

    }
    
    if (navCalZ == 1 && navCalY == 2) //This section prints the results for dateCalcAStoEE.
    {
        outputAStoEE(calName1, calName2, navCalZ, navCalY, date, newdateAStoEE);

    }
    
    if (navCalZ == 1 && navCalY == 3) //This section prints the results for dateCalcAStoXE.
    {
        outputAStoXE(calName1, calName2, navCalZ, navCalY, date, newdateAStoXE);
        outCalcRemainderXE (newdateAStoXE);

    }
    
    if (navCalZ == 2 && navCalY == 1) //This section prints the results for dateCalcCTtoAS.
    {
        outputCTtoAS(calName1, calName2, navCalZ, navCalY, date, newdateCTtoAS);

    }
    
    if (navCalZ == 2 && navCalY == 2) //This section prints the results for dateCalcCTtoEE.
    {
        outputCTtoEE(calName1, calName2, navCalZ, navCalY, date, newdateCTtoEE);

    }
    
    if (navCalZ == 2 && navCalY == 3) //This section prints the results for dateCalcCTtoXE.
    {
        outputCTtoXE(calName1, calName2, navCalZ, navCalY, date, newdateCTtoXE);
        //outCalcRemainderXE (newdateAStoXE);
 
    }
    
    if (navCalZ == 3 && navCalY == 1) //This section prints the results for dateCalcEEtoAS.
    {
        outputEEtoAS(calName1, calName2, navCalZ, navCalY, date, newdateEEtoAS);
        
    }
    
    if (navCalZ == 3 && navCalY == 2) //This section prints the results for dateCalcEEtoCT.
    {
        outputEEtoCT(calName1, calName2, navCalZ, navCalY, date, newdateEEtoCT);
        outCalcRemainderCT(calName1, calName2, navCalZ, navCalY, date, newdateAStoCT);

    }
    
    if (navCalZ == 3 && navCalY == 3) //This section prints the results for dateCalcEEtoXE.
    {
        outputEEtoXE(calName1, calName2, navCalZ, navCalY, date, newdateEEtoXE);
        //outCalcRemainderXE (newdateAStoXE);
        
    }
    
    if (navCalZ == 4 && navCalY == 1) //This section prints the results for dateCalcXEtoAS.
    {
        outputXEtoAS(calName1, calName2, navCalZ, navCalY, date, newdateXEtoAS);

    }
    
    if (navCalZ == 4 && navCalY == 2) //This section prints the results for dateCalcXEtoCT.
    {
        outputXEtoCT(calName1, calName2, navCalZ, navCalY, date, newdateXEtoCT);
        outCalcRemainderCT(calName1, calName2, navCalZ, navCalY, date, newdateAStoCT);
        
    }
    if (navCalZ == 4 && navCalY == 3) //This section prints the results for dateCalcXEtoEE.
    {
        outputXEtoEE(calName1, calName2, navCalZ, navCalY, date, newdateXEtoEE);

    }
    
    return 0;
}


int printResultsOneToAll (int navCalZ, int navCalY, double date, double newdateAStoCT, double newdateAStoEE, double newdateAStoXE, double newdateEEtoAS, double newdateEEtoCT, double newdateEEtoXE, double newdateXEtoAS, double newdateXEtoCT, double newdateXEtoEE, double newdateCTtoAS, double newdateCTtoEE, double newdateCTtoXE, std::string calName1, std::string calName2)
{
    if (navCalZ == 1 && navCalY == 4) //This section prints the results for dateCalcAStoCT.
    {
        outputAStoCT(calName1, calName2, navCalZ, navCalY, date, newdateAStoCT);
        outputAStoEE(calName1, calName2, navCalZ, navCalY, date, newdateAStoEE);
        outputAStoXE(calName1, calName2, navCalZ, navCalY, date, newdateAStoXE);
        
    }

    if (navCalZ == 2 && navCalY == 4) //This section prints the results for dateCalcCTtoAS.
    {
        outputCTtoAS(calName1, calName2, navCalZ, navCalY, date, newdateCTtoAS);
        outputCTtoEE(calName1, calName2, navCalZ, navCalY, date, newdateCTtoEE);
        outputCTtoXE(calName1, calName2, navCalZ, navCalY, date, newdateCTtoXE);

    }

    if (navCalZ == 3 && navCalY == 4) //This section prints the results for dateCalcEEtoAS.
    {
        outputEEtoAS(calName1, calName2, navCalZ, navCalY, date, newdateEEtoAS);
        outputEEtoCT(calName1, calName2, navCalZ, navCalY, date, newdateEEtoCT);
        outputEEtoXE(calName1, calName2, navCalZ, navCalY, date, newdateEEtoXE);

    }

    if (navCalZ == 4 && navCalY == 4) //This section prints the results for dateCalcXEtoAS.
    {
       
        outputXEtoAS(calName1, calName2, navCalZ, navCalY, date, newdateXEtoAS);
        outputXEtoCT(calName1, calName2, navCalZ, navCalY, date, newdateXEtoCT);
        outputXEtoEE(calName1, calName2, navCalZ, navCalY, date, newdateXEtoEE);

    }
    
    return 0;
}

int printResultsAllToOne (int navCalZ, int navCalY, double date, double newdateAStoCT, double newdateAStoEE, double newdateAStoXE, double newdateEEtoAS, double newdateEEtoCT, double newdateEEtoXE, double newdateXEtoAS, double newdateXEtoCT, double newdateXEtoEE, double newdateCTtoAS, double newdateCTtoEE, double newdateCTtoXE, std::string calName1, std::string calName2)
{
    if (navCalZ == 5 && navCalY == 1) //This section prints the results for dateCalcCTtoAS, dateCalcEEtoAS, and dateCalcXEtoAS.
    {
        outputCTtoAS(calName1, calName2, navCalZ, navCalY, date, newdateCTtoAS);
        outputEEtoAS(calName1, calName2, navCalZ, navCalY, date, newdateEEtoAS);
        outputXEtoAS(calName1, calName2, navCalZ, navCalY, date, newdateXEtoAS);
        
    }
    
    if (navCalZ == 5 && navCalY == 2) //This section prints the results for dateCalcAStoCT, datecalcEEtoCt, and dateCalcXEtoCT.
    {
        outputAStoCT(calName1, calName2, navCalZ, navCalY, date, newdateAStoCT);
        outputEEtoCT(calName1, calName2, navCalZ, navCalY, date, newdateEEtoCT);
        outputXEtoCT(calName1, calName2, navCalZ, navCalY, date, newdateXEtoCT);
        
    }
    
    if (navCalZ == 5 && navCalY == 3) //This section prints the results for dateCalcAStoEE, dateCalcCTtoEE, and dateCalcXEtoEE.
    {
        outputAStoEE(calName1, calName2, navCalZ, navCalY, date, newdateAStoEE);
        outputCTtoEE(calName1, calName2, navCalZ, navCalY, date, newdateCTtoEE);
        outputXEtoEE(calName1, calName2, navCalZ, navCalY, date, newdateXEtoEE);
        
    }
    
    if (navCalZ == 5 && navCalY == 4) //This section prints the results for dateCalcAStoXE, dateCalcCTtoXE, and dateCalcEEtoXE.
    {
        outputAStoXE(calName1, calName2, navCalZ, navCalY, date, newdateAStoXE);
        outputCTtoXE(calName1, calName2, navCalZ, navCalY, date, newdateCTtoXE);
        outputEEtoXE(calName1, calName2, navCalZ, navCalY, date, newdateEEtoXE);
        
    }
    
    return 0;
}

int printAllResults (int navCalZ, int navCalY, double date, double newdateAStoCT, double newdateAStoEE, double newdateAStoXE, double newdateEEtoAS, double newdateEEtoCT, double newdateEEtoXE, double newdateXEtoAS, double newdateXEtoCT, double newdateXEtoEE, double newdateCTtoAS, double newdateCTtoEE, double newdateCTtoXE, std::string calName1, std::string calName2)
{
    if (navCalZ == 5 && navCalY == 5)
    {
        outputAStoCT(calName1, calName2, navCalZ, navCalY, date, newdateAStoCT);
        outputAStoEE(calName1, calName2, navCalZ, navCalY, date, newdateAStoEE);
        outputAStoXE(calName1, calName2, navCalZ, navCalY, date, newdateAStoXE);
        std::cout << std::endl;
        outputCTtoAS(calName1, calName2, navCalZ, navCalY, date, newdateCTtoAS);
        outputCTtoEE(calName1, calName2, navCalZ, navCalY, date, newdateCTtoEE);
        outputCTtoXE(calName1, calName2, navCalZ, navCalY, date, newdateCTtoXE);
        std::cout << std::endl;
        outputEEtoAS(calName1, calName2, navCalZ, navCalY, date, newdateEEtoAS);
        outputEEtoCT(calName1, calName2, navCalZ, navCalY, date, newdateEEtoCT);
        outputEEtoXE(calName1, calName2, navCalZ, navCalY, date, newdateEEtoXE);
        std::cout << std::endl;
        outputXEtoAS(calName1, calName2, navCalZ, navCalY, date, newdateXEtoAS);
        outputXEtoCT(calName1, calName2, navCalZ, navCalY, date, newdateXEtoCT);
        outputXEtoEE(calName1, calName2, navCalZ, navCalY, date, newdateXEtoEE);
        
    }
    
    return 0;
    
}

// * * * * * * * Output/Calculator Functions * * * * * * *

void outCalcWeeksDaysCT(int remainingDays, int daysInWeekCT)
{
    int weeks;
    int days;
    
    weeks = (int) remainingDays / daysInWeekCT;
    days = (int) remainingDays % daysInWeekCT;
    
    std::cout << "Week: " << weeks << " Day: " << days << std::endl;
    
    
    return;
}
void outCalcWeeksDaysXE(int remainingDays, int daysInWeekXE)  //As of now, this function is printing the entire year's
    //remainder in weeks and days, which technically means the result in days is fine, but the entire problem needs solving...
    //This error occurs in the 200 range, 400 range, 600 range, and 800 range.  This testing has revealed that it's likely a
    //problem with the code following the second deciyear determination.
    //...Well, it was one of the deciyears.  Score one for learnin'.
{
    int weeks;
    int days;
    
    weeks = (int) remainingDays / daysInWeekXE;
    days = (int) remainingDays % daysInWeekXE;
    
    std::cout << "Week: " << weeks << " Day: " << days << std::endl;
    
    
    return;
}

int outCalcRemainderCT (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateAStoCT)

{
    double wholeYearsCT = 0.0;
    double fractionCT = 0.0;
    
    double dYearsCT = 0.0;
    double qYearsCT = 0.0;
    double oYearsCT = 0.0;
    double weeksCT = 0.0;
    
   
    // double i  = 0;
    int demiyear = 0;
    int quasiyear = 0;
    int octoyear = 0;
    
    int remainingDays;
    int daysInWeekCT = 8;
    
  //  double week = 0;
    
    std::cout << std::endl;
    std::cout << "For more specific data, enter the decimal value of your result, as a three digit integer: " << std::endl;

    fractionCT = modf (newdateAStoCT, &wholeYearsCT) * 1024; //How could we make this convert for all calendars?  Could we make it work somehow with by making fractionCT equal to all the newdate??toCT variables, added to each other, because 2 are always going to be zero? Maybe, but only if we don't want to implement it in the convert all section.
    
//    fractionCT = fractionInput1();
//    
//    if (fractionCT < 0 || fractionCT > 1000)
//    {
//        std::cout << "¡¡Error!!  ¡¡Error!! ¡¡Error Encountered!! Please enter the decimal value of the year printed above as a three digit integer." << std::endl;
//        fractionCT = fractionInput1();
//    }
    
    
//    (for i = 0; i < fractionCT; i + 0.009765625)  // Why do I need this?
//    {
//        
//    }
    
    if (fractionCT > 512)
    {
        demiyear = 2;
        dYearsCT = fractionCT - 512;
        fractionCT = dYearsCT;
        
    }
    else //This if statement determines if the date falls in the first demiyear of the year.
    {
        demiyear = 1;
        dYearsCT = fractionCT;
        fractionCT = dYearsCT;
    }
    
    
    if (fractionCT > 256) //This if statement determines if the date falls in the second quasiyear of the demiyear.
    {
        quasiyear = 2;
        qYearsCT = dYearsCT - 256;
        fractionCT = qYearsCT;
    }
    else //This if statement determines if the date falls in the first quasiyear of the demiyear.
    {
        quasiyear = 1;
        qYearsCT = fractionCT;
        fractionCT = qYearsCT;
    }

    
    if (fractionCT > 128)  //This if statement determines if the date falls in the second octoyear of the quasiyear.
    {
        octoyear = 2;
        weeksCT = qYearsCT - 128;
      //  fractionCT = oYearsCT;
        remainingDays = weeksCT;
        
    }
    else //This if statement determines if the date falls in the first octoyear of the quasiyear.
    {
        octoyear = 1;
        oYearsCT = fractionCT;
       // fractionCT = oYearsCT;
        remainingDays = oYearsCT;
    }
   
    
    std::cout << "The calendar date in Carnon Time  is..." << std::endl;
    std::cout << "Demiyear: " << demiyear << " Quasiyear: " << quasiyear << " Octoyear: " << octoyear << " ";
    outCalcWeeksDaysCT(remainingDays, daysInWeekCT);
    

    return 0;
}

int outCalcRemainderXE (double &newdateAStoXE) //IT WORKS!  (As user input) (Automatically, it only works out to deciyears).

{
    
    double wholeYearsXE = 0.0;
    double fractionXE = 0.0;  //Total fraction of years XE
  //  double demYearsXE = 0.0;  //Total of demiyears XE
    double pYearsXE = 0.0;    //Total of pentayears XE
//    double decYearsXE = 0.0;  //Total of deciyears XE
    
    double weeksXE = 0.0;     //Total of weeks XE
    
    // double i  = 0;
//    int demiyear = 0;
    int pentayear = 0;
    int deciyear = 0;
    
    int remainingDays = 0;
    int daysInWeekXE = 10;
    
    //  double week = 0;
    
    std::cout << std::endl;
//    std::cout << "For more specific data, enter the decimal value of your result, as a three digit integer: " << std::endl;
    
    fractionXE = modf (newdateAStoXE, &wholeYearsXE) * 1000;
    
//    fractionXE = fractionInput2();
//    
//    if (fractionXE < 0 || fractionXE > 1000)
//    {
//        std::cout << "¡¡Error!!  ¡¡Error!! ¡¡Error Encountered!! Please enter the decimal value of the year printed above as a three digit integer." << std::endl;
//        
//        fractionXE = fractionInput2();
//    }
    
    if (fractionXE >= 800 && fractionXE < 1000) //This if statement determines if the date falls in the fifth pentayear of the year.
    {
        pentayear = 5;
        pYearsXE = fractionXE - 800;
      //  fractionXE = pYearsXE;
    }
    if (fractionXE >= 600 && fractionXE < 800) //This if statement determines if the date falls in the fourth pentayear of the year.
    {
        pentayear = 4;
        pYearsXE = fractionXE - 600;
       // fractionXE = pYearsXE;
    }
    
    if (fractionXE >= 400 && fractionXE < 600) //This if statement determines if the date falls in the third pentayear of the year.
    {
        pentayear = 3;
        pYearsXE = fractionXE - 400;
      //  fractionXE = pYearsXE;
    }
    if (fractionXE >= 200 && fractionXE < 400) //This if statement determines if the date falls in the second pentayear of the year.
    {
        pentayear = 2;
        pYearsXE = fractionXE - 200;
       // fractionXE = fractionXE;
    }
    
    if (fractionXE >= 0 && fractionXE < 200) //This if statement determines if the date falls in the first pentayear of the demiyear.
    {
        pentayear = 1;
        pYearsXE = fractionXE;
        fractionXE = fractionXE;
    }
    
    
    if (pYearsXE >= 100 && pYearsXE < 200)  //This if statement determines if the date falls in the second deciyear of the year.
    {
        deciyear = 2;
        weeksXE = pYearsXE - 100;
        remainingDays = weeksXE;
    }
    if (pYearsXE >= 0 && pYearsXE < 100) //This if statement determines if the date falls in the first deciyear of the year.
    {
        deciyear = 1;
        weeksXE = pYearsXE;
        remainingDays = weeksXE;
//        decYearsXE = fractionXE;
//        remainingDays = decYearsXE;
    }

//THE BELOW CODE (COMMENTED OUT) WAS FOR USE WHEN THE VALUE OF MODF WAS NOT MULTIPLIED BY 1000.
//    if (fractionXE >= .800 && fractionXE < 1.000) //This if statement determines if the date falls in the fifth pentayear of the year.
//    {
//        pentayear = 5;
//        pYearsXE = fractionXE - .800;
//        //  fractionXE = pYearsXE;
//    }
//    if (fractionXE >= .600 && fractionXE < .800) //This if statement determines if the date falls in the fourth pentayear of the year.
//    {
//        pentayear = 4;
//        pYearsXE = fractionXE - .600;
//        // fractionXE = pYearsXE;
//    }
//    
//    if (fractionXE >= .400 && fractionXE < .600) //This if statement determines if the date falls in the third pentayear of the year.
//    {
//        pentayear = 3;
//        pYearsXE = fractionXE - .400;
//        //  fractionXE = pYearsXE;
//    }
//    if (fractionXE >= .200 && fractionXE < .400) //This if statement determines if the date falls in the second pentayear of the year.
//    {
//        pentayear = 2;
//        pYearsXE = fractionXE - .200;
//        // fractionXE = fractionXE;
//    }
//    
//    if (fractionXE >= 0 && fractionXE < .200) //This if statement determines if the date falls in the first pentayear of the demiyear.
//    {
//        pentayear = 1;
//        pYearsXE = fractionXE;
//        fractionXE = fractionXE;
//    }
//    
//    
//    if (pYearsXE >= .100 && pYearsXE < .200)  //This if statement determines if the date falls in the second deciyear of the year.
//    {
//        deciyear = 2;
//        weeksXE = pYearsXE - .100;
//        remainingDays = weeksXE;
//    }
//    if (pYearsXE >= 0 && pYearsXE < .100) //This if statement determines if the date falls in the first deciyear of the year.
//    {
//        deciyear = 1;
//        weeksXE = pYearsXE;
//        remainingDays = weeksXE;
//        //        decYearsXE = fractionXE;
//        //        remainingDays = decYearsXE;
//    }
    
    
    std::cout << "The calendar date in the Xix Era  is..." << std::endl;
    std::cout << /*"Demiyear: " << demiyear << */"Pentayear: " << pentayear << " Deciyear: " << deciyear << " ";
    outCalcWeeksDaysXE(remainingDays, daysInWeekXE);
    
    
    return 0;
}

// * * * * * * * Individual Output Functions * * * * * * *

int outputAStoCT (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateAStoCT)
{
    
    if (date >= 2983)
    {
        calName1 = "A.S.";
        calName2 = "C.T.";
    }
    if ((date >= 0) && (date < 2983))
    {
        calName1 = "A.S.";
        calName2 = "P.Z.";
    }
    if (date < 0)
    {
        calName1 = "E.S.";
        calName2 = "P.Z.";
    }
    
    if (date > 2183) //This if statement is technically somewhat superfluous, but was left in for consistency.
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << date << " " << calName1 << " is the year " << newdateAStoCT << " " << calName2 << std::endl;
    }
    if ((date >= 0) && (date < 2183)) //If the above statement were left or commented out, the condition of this statement would simply be '(date >= 0).
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << date << " " << calName1 << " is the year " << newdateAStoCT << " " << calName2 << std::endl;
    }
    if (date < 0)
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << -date << " " << calName1 << " is the year " << newdateAStoCT << " " << calName2 << std::endl;
    }
    
    return 0;
}
int outputAStoEE (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateAStoEE)
{
    
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
    
    if (date > 2183) //This if statement is technically somewhat superfluous, but was left in for consistency.
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << date << " " << calName1 << " is the year " << newdateAStoEE << " " << calName2 << std::endl;
    }
    if ((date >= 0) && (date < 2183)) //If the above statement were left or commented out, the condition of this statement would simply be '(date >= 0).
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << date << " " << calName1 << " is the year " << newdateAStoEE << " " << calName2 << std::endl;
    }
    if (date < 0)
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << -date << " " << calName1 << " is the year " << newdateAStoEE << " " << calName2 << std::endl;
    }
    
    return 0;
}
int outputAStoXE (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateAStoXE)
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
    if (date >= 2574)
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << date << " " << calName1 << " is the year " << newdateAStoXE << " " << calName2 << std::endl;
    }
    if ((date >= 0) && (date < 2574))
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << date << " " << calName1 << " is the year " << newdateAStoXE << " " << calName2 << std::endl;
    }
    if (date < 0)
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << -date << " " << calName1 << " is the year " << newdateAStoXE << " " << calName2 << std::endl;
    }
    
    return 0;
}
int outputCTtoAS (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateCTtoAS)
{
    if (date >= 0)
    {
        calName1 = "C.T.";
        calName2 = "A.S.";
    }
    if ((date < 0) && (date > -1063.2686))
    {
        calName1 = "P.Z.";
        calName2 = "A.S.";
    }
    if (date <= -1063.2686)
    {
        calName1 = "P.Z.";
        calName2 = "E.S.";
    }
    if (date >= 0)
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << date << " " << calName1 << " is the year " << newdateCTtoAS << " " << calName2 << std::endl;
    }
    if ((date < 0) && (date > -1063.2686))
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << -date << " " << calName1 << " is the year " << newdateCTtoAS << " " << calName2 << std::endl;
    }
    if (date <= -1063.2686)
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << -date << " " << calName1 << " is the year " << newdateCTtoAS << " " << calName2 << std::endl;
    }
    
    return 0;
}
int outputCTtoEE (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateCTtoEE)
{
    
    if (date >= 0)
    {
        calName1 = "C.T.";
        calName2 = "E.E.";
    }
    if ((date < 0) && (date >= -285.5106))
    {
        calName1 = "P.Z.";
        calName2 = "E.E.";
    }
    if (date <= -285.5106)
    {
        calName1 = "P.Z.";
        calName2 = "T.E.";
    }
    if (date >= 0)
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << date << " " << calName1 << " is the year " << newdateCTtoEE << " " << calName2 << std::endl;
    }
    if ((date < 0) && (date > -285.5106))
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << -date << " " << calName1 << " is the year " << newdateCTtoEE << " " << calName2 << std::endl;
    }
    if (date <= -285.5106)
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << -date << " " << calName1 << " is the year " << newdateCTtoEE << " " << calName2 << std::endl;
    }
    
    return 0;
}
int outputCTtoXE (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateCTtoXE)
{
    
    if (date >= 152.8688)
    {
        calName1 = "C.T.";
        calName2 = "X.E.";
    }
    if ((date >= 0) && (date < 152.8688))
    {
        calName1 = "C.T.";
        calName2 = "G.E.";
    }
    if (date < 0)
    {
        calName1 = "P.Z.";
        calName2 = "G.E.";
    }
    if (date >= 152.8688)
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << date << " " << calName1 << " is the year " << newdateCTtoXE << " " << calName2 << std::endl;
    }
    if ((date >= 0) && (date < 152.8688))
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << date << " " << calName1 << " is the year " << newdateCTtoXE << " " << calName2 << std::endl;
    }
    if (date < 0)
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << -date << " " << calName1 << " is the year " << newdateCTtoXE << " " << calName2 << std::endl;
    }
    
    return 0;
}
int outputEEtoAS  (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateEEtoAS)
{
    if (date >= 0)
    {
        calName1 = "E.E.";
        calName2 = "A.S.";
    }
    if ((date < 0) && (date >= -2182))
    {
        calName1 = "T.E.";
        calName2 = "A.S.";
    }
    if (date <= -2183)
    {
        calName1 = "T.E.";
        calName2 = "E.S.";
    }
    if (date >= 0)
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << date << " " << calName1 << " is the year " << newdateEEtoAS << " " << calName2 << std::endl;
    }
    if ((date < 0) && (date >= -2183))
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << -date << " " << calName1 << " is the year " << newdateEEtoAS << " " << calName2 << std::endl;
    }
    if (date <= -2183)
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << -date << " " << calName1 << " is the year " << -newdateEEtoAS << " " << calName2 << std::endl;
        //this statement has a bit of an ugly patch with the negative variable 'newdate'.
    }
    
    return 0;
}
int outputEEtoCT (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateEEtoCT)
{
    
    if (date >= 801)
    {
        calName1 = "E.E.";
        calName2 = "C.T.";
    }
    if ((date < 801) && (date >= 0))
    {
        calName1 = "E.E.";
        calName2 = "P.Z.";
    }
    if (date < 0)
    {
        calName1 = "T.E.";
        calName2 = "P.Z.";
    }
    
    if (date >= 801)
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << date << " " << calName1 << " is the year " << newdateEEtoCT << " " << calName2 << std::endl;
    }
    if ((date < 801) && (date >= 0))
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << date << " " << calName1 << " is the year " << newdateEEtoCT << " " << calName2 << std::endl;
    }
    if (date < 0)
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << -date << " " << calName1 << " is the year " << newdateEEtoCT << " " << calName2 << std::endl;
    }
    
    
    return 0;
}
int outputEEtoXE (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateEEtoXE)
{
    if (date >= 392)
    {
        calName1 = "E.E.";
        calName2 = "X.E.";
    }
    if ((date < 392) && (date >= 0))
    {
        calName1 = "E.E.";
        calName2 = "G.E.";
    }
    if (date < 0)
    {
        calName1 = "T.E.";
        calName2 = "G.E.";
    }
    
    if (date >= 392)
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << date << " " << calName1 << " is the year " << newdateEEtoXE << " " << calName2 << std::endl;
    }
    if ((date < 392) && (date >= 0))
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << date << " " << calName1 << " is the year " << newdateEEtoXE << " " << calName2 << std::endl;
    }
    if (date < 0)
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << -date << " " << calName1 << " is the year " << newdateEEtoXE << " " << calName2 << std::endl;
    }
    
    return 0;
}
int outputXEtoAS (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateXEtoAS)

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
        std::cout << "The year " << std::fixed << std::setprecision(3) << date << " " << calName1 << " is the year " << newdateXEtoAS << " " << calName2 << std::endl;
    }
    if ((date < 0) && (date > -939.5189))
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << -date << " " << calName1 << " is the year " << newdateXEtoAS << " " << calName2 << std::endl;
    }
    if (date <= -939.5189)
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << -date << " " << calName1 << " is the year " << newdateXEtoAS << " " << calName2 << std::endl;
    }

    return 0;
}
int outputXEtoCT (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateXEtoCT)
{
    if (date >= 0)
    {
        calName1 = "X.E.";
        calName2 = "C.T.";
    }
    if ((date < 0) && (date >= -149.2860))
    {
        calName1 = "G.E.";
        calName2 = "C.T.";
    }
    if (date < -149.2860)
    {
        calName1 = "G.E.";
        calName2 = "P.Z.";
    }
    if (date >= 0)
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << date << " " << calName1 << " is the year " << newdateXEtoCT << " " << calName2 << std::endl;
    }
    if ((date < 0) && (date >= -149.2860))
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << -date << " " << calName1 << " is the year " << -newdateXEtoCT << " " << calName2 << std::endl; //Weird patch with the negative 'newdate' again.
    }
    if (date < -149.2860)
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << -date << " " << calName1 << " is the year " << newdateXEtoCT << " " << calName2 << std::endl;
    }
   
    return 0;
}
int outputXEtoEE (std::string &calName1, std::string &calName2, int &navCalZ, int &navCalY, double &date, double &newdateXEtoEE)
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
        std::cout << "The year " << std::fixed << std::setprecision(3) << date << " " << calName1 << " is the year " << newdateXEtoEE << " " << calName2 << std::endl;
    }
    if ((date < 0) && (date > -143.0813))
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << -date << " " << calName1 << " is the year " << newdateXEtoEE << " " << calName2 << std::endl;
    }
    if (date <= -143.0813)
    {
        std::cout << "The year " << std::fixed << std::setprecision(3) << -date << " " << calName1 << " is the year " << newdateXEtoEE << " " << calName2 << std::endl;
    }
    
    return 0;
}
//*****************************INTERACTIONS****************************

std::string getSnarky (std::string &navLoopC, std::string &navLoopD, int &irritation, int &i)  //Function getSnarky is presently UNDER CONSTRUCTION.
{
    
    std::string navLoopE;
    std::string navLoopF;
    std::string navLoopG;
    std::string navLoopH;
    std::string navLoopI;
    std::string navLoopJ;
    std::string navLoopK;
    std::string navLoopL;
    std::string navLoopM;
    std::string navLoopN;
    
    std::string selectCalA;
    std::string selectCalB;
    
    
    if (navLoopC != "yes" && navLoopC != "y" && navLoopC != "Yes" && navLoopC != "Y" && navLoopC != "YES" && navLoopC != "YES." && navLoopC != "Yes." && navLoopC != "no" && navLoopC != "n" && navLoopC != "No" && navLoopC != "N" && navLoopC != "NO" && navLoopC != "NO." && navLoopC != "No.")
    {
        
        for (int irritation = 10; irritation > 0; --irritation)  // Yes, 'i' is for iterator.  'Irritation' is funnier.
        {
            
            if ((irritation = 1))
            {
                std::cout << "Another Calculation?" << std::endl;
                navLoopD = LoopInput1(navLoopD);
                navLoopC = navLoopD;
                
                if (navLoopD == "no" || navLoopD == "n" || navLoopD == "No" || navLoopD == "N" || navLoopD == "NO" || navLoopD == "NO." || navLoopD == "No.")
                {
                    navLoopC = navLoopD;
                    std::cout << "Alright then, ";
                    return navLoopC;
                }
                
                if (navLoopD == "yes" || navLoopD == "y" || navLoopD == "Yes" || navLoopD == "Y" || navLoopD == "YES" || navLoopD == "YES." || navLoopD == "Yes.")
                {
                    
                    //std::cout << "Try again, silly." << std::endl;
                    navLoopC = navLoopD;
                    return navLoopC;
                    
                }
                
                if (navLoopD != "yes" && navLoopD != "y" && navLoopD != "Yes" && navLoopD != "Y" && navLoopD != "YES" && navLoopD != "YES." && navLoopD != "Yes." && navLoopD != "no" && navLoopD != "n" && navLoopD != "No" && navLoopD != "N" && navLoopD != "NO" && navLoopD != "NO." && navLoopD != "No.")
                {
                    
                    
                    navLoopD = navLoopE;
                    
                    
                    //                    std::cout << "Snark?" << std::endl;
                    //                    navLoopE = LoopInput2(navLoopE);
                    //The above input line allows an extra stage here without much trouble (assuming
                    //it replaces the assignment statment above).
                    
                }
                if (navLoopC == "no." || navLoopC == "nO." || navLoopC == "yes." || navLoopC == "yeS." ||
                    navLoopC == "yES." || navLoopC == "YEs." || navLoopC == "YeS." || navLoopC == "yEs.")
                {
                    getSnarkyGrammar(navLoopC);
                    return navLoopC;
                }
                if (navLoopC == "NO!" || navLoopC == "YES!" || navLoopC == "Yes!" || navLoopC == "No!" || navLoopC == "No?" || navLoopC == "Yes?")
                {
                    getSnarkyTone(navLoopC);
                    return navLoopC;
                }
                
            }
            if ((irritation = 2))
            {
                std::cout << "Excuse me, sir or madam. Did you want to make another calculation?" << std::endl;
                navLoopE = LoopInput2(navLoopE);
                navLoopC = navLoopE;
                
                if (navLoopE == "no" || navLoopE == "n" || navLoopE == "No" || navLoopE == "N" || navLoopE == "NO" || navLoopE == "NO." || navLoopE == "No.")
                {
                    navLoopC = navLoopE;
                    std::cout << "Thank you for using the Terran Calendar Converter, ";
                    return navLoopC;
                }
                
                if (navLoopE == "yes" || navLoopE == "y" || navLoopE == "Yes" || navLoopE == "Y" || navLoopE == "YES" || navLoopE == "YES." || navLoopE == "Yes.")
                {
                    
                    //std::cout << "Try again, silly." << std::endl;
                    navLoopC = navLoopE;
                    return navLoopC;
                }
                
                if (navLoopE != "yes" && navLoopE != "y" && navLoopE != "Yes" && navLoopE != "Y" && navLoopE != "YES" && navLoopE != "YES." && navLoopE != "Yes." && navLoopE != "no" && navLoopE != "n" && navLoopE != "No" && navLoopE != "N" && navLoopE != "NO" && navLoopE != "NO." && navLoopE != "No.")
                {
                    
                    //std::cout << "Snarkity Snark?" << std::endl;
                    navLoopF = navLoopE;
                    
                }
                if (navLoopC == "no." || navLoopC == "nO." || navLoopC == "yes." || navLoopC == "yeS." ||
                    navLoopC == "yES." || navLoopC == "YEs." || navLoopC == "YeS." || navLoopC == "yEs.")
                {
                    getSnarkyGrammar(navLoopC);
                    return navLoopC;
                }
                if (navLoopC == "NO!" || navLoopC == "YES!" || navLoopC == "Yes!" || navLoopC == "No!" || navLoopC == "No?" || navLoopC == "Yes?")
                {
                    getSnarkyTone(navLoopC);
                    return navLoopC;
                }
            }
            if ((irritation = 3))
            {
                std::cout << "Excuse me. Excuuuse meeeeee!!" << std::endl;
                navLoopF = LoopInput3(navLoopF);
                navLoopC = navLoopF;
                
                if (navLoopF == "no" || navLoopF == "n" || navLoopF == "No" || navLoopF == "N" || navLoopF == "NO" || navLoopF == "NO." || navLoopF == "No.")
                {
                    navLoopC = navLoopF;
                    std::cout << "Well that sure took a while. ";
                    return navLoopC;
                }
                
                if (navLoopF == "yes" || navLoopF == "y" || navLoopF == "Yes" || navLoopF == "Y" || navLoopF == "YES" || navLoopF == "YES." || navLoopF == "Yes.")
                {
                    
                    navLoopC = navLoopF;
                    return navLoopC;
                    
                }
                
                if (navLoopF != "yes" && navLoopF != "y" && navLoopF != "Yes" && navLoopF != "Y" && navLoopF != "YES" && navLoopF != "YES." && navLoopF != "Yes." && navLoopF != "no" && navLoopF != "n" && navLoopF != "No" && navLoopF != "N" && navLoopF != "NO" && navLoopF != "NO." && navLoopF != "No.")
                {
                    
                    //std::cout << "Snarkity snarkity snark?" << std::endl;
                    navLoopG = navLoopF;
                    
                }
                if (navLoopC == "no." || navLoopC == "nO." || navLoopC == "yes." || navLoopC == "yeS." ||
                    navLoopC == "yES." || navLoopC == "YEs." || navLoopC == "YeS." || navLoopC == "yEs.")
                {
                    getSnarkyGrammar(navLoopC);
                    return navLoopC;
                }
                if (navLoopC == "NO!" || navLoopC == "YES!" || navLoopC == "Yes!" || navLoopC == "No!" || navLoopC == "No?" || navLoopC == "Yes?")
                {
                    getSnarkyTone(navLoopC);
                    return navLoopC;
                }
                
            }
            if ((irritation = 4))
            {
                
                std::cout << "Yo! Want to use this thing again? 'Yes' or 'no'.  It's easy.  'Y', 'N', whatever, man.  I'm easy." << std::endl;
                navLoopG = LoopInput4(navLoopG);
                navLoopC = navLoopG;
                
                if (navLoopG == "no" || navLoopG == "n" || navLoopG == "No" || navLoopG == "N" || navLoopG == "NO" || navLoopG == "NO." || navLoopG == "No.")
                {
                    navLoopC = navLoopG;
                    std::cout << "Finally. ";
                    return navLoopC;
                }
                
                if (navLoopG == "yes" || navLoopG == "y" || navLoopG == "Yes" || navLoopG == "Y" || navLoopG == "YES" || navLoopG == "YES." || navLoopG == "Yes.")
                {
                    
                    navLoopC = navLoopG;
                    return navLoopC;
                    
                }
                
                if (navLoopG != "yes" && navLoopG != "y" && navLoopG != "Yes" && navLoopG != "Y" && navLoopG != "YES" && navLoopG != "YES." && navLoopG != "Yes." && navLoopG != "no" && navLoopG != "n" && navLoopG != "No" && navLoopG != "N" && navLoopG != "NO" && navLoopG != "NO." && navLoopG != "No.")
                {
                    
                    //std::cout << "Snarkity snarkity snarky snark?" << std::endl;
                    navLoopH = navLoopG;
                }
                if (navLoopC == "no." || navLoopC == "nO." || navLoopC == "yes." || navLoopC == "yeS." ||
                    navLoopC == "yES." || navLoopC == "YEs." || navLoopC == "YeS." || navLoopC == "yEs.")
                {
                    getSnarkyGrammar(navLoopC);
                    return navLoopC;
                }
                if (navLoopC == "NO!" || navLoopC == "YES!" || navLoopC == "Yes!" || navLoopC == "No!" || navLoopC == "No?" || navLoopC == "Yes?")
                {
                    getSnarkyTone(navLoopC);
                    return navLoopC;
                }
                
            }
            if ((irritation = 5))
            {
                
                std::cout << "While you decide, perhaps you'd like to know that if you attempt to convert a negative date using the New Terran Calendar Converter the date will print in that calendar's reverse.  (For instance, -420.210 entered into the X.E converter would print out as 420.210 G.E.)" << std::endl;
                navLoopH = LoopInput5(navLoopH);
                navLoopC = navLoopH;
                
                if (navLoopH == "no" || navLoopH == "n" || navLoopH == "No" || navLoopH == "N" || navLoopH == "NO" || navLoopH == "NO." || navLoopH == "No.")
                {
                    navLoopC = navLoopH;
                    std::cout << "You're really quite the time waster, aren't you? ";
                    return navLoopC;
                }
                
                if (navLoopH == "yes" || navLoopH == "y" || navLoopH == "Yes" || navLoopH == "Y" || navLoopH == "YES" || navLoopH == "YES." || navLoopH == "Yes.")
                {
                    
                    navLoopC = navLoopH;
                    return navLoopC;
                    
                }
                
                if (navLoopH != "yes" && navLoopH != "y" && navLoopH != "Yes" && navLoopH != "Y" && navLoopH != "YES" && navLoopH != "YES." && navLoopH != "Yes." && navLoopH != "no" && navLoopH != "n" && navLoopH != "No" && navLoopH != "N" && navLoopH != "NO" && navLoopH != "NO." && navLoopH != "No.")
                {
                    
                    //std::cout << "Snarkity snarkity snarky snark snark?" << std::endl;
                    navLoopI = navLoopH;
                }
                if (navLoopC == "no." || navLoopC == "nO." || navLoopC == "yes." || navLoopC == "yeS." ||
                    navLoopC == "yES." || navLoopC == "YEs." || navLoopC == "YeS." || navLoopC == "yEs.")
                {
                    getSnarkyGrammar(navLoopC);
                    return navLoopC;
                }
                if (navLoopC == "NO!" || navLoopC == "YES!" || navLoopC == "Yes!" || navLoopC == "No!" || navLoopC == "No?" || navLoopC == "Yes?")
                {
                    getSnarkyTone(navLoopC);
                    return navLoopC;
                }
                
            }
            if ((irritation = 6))
            {
                
                std::cout << "Did you know that I can convert more than one calendar at a time?  What a time saver! So, how about it?" << std::endl;
                navLoopI = LoopInput6(navLoopI);
                navLoopC = navLoopI;
                
                if (navLoopI == "no" || navLoopI == "n" || navLoopI == "No" || navLoopI == "N" || navLoopI == "NO" || navLoopI == "NO." || navLoopI == "No.")
                {
                    navLoopC = navLoopI;
                    std::cout << "Okay. That really steams my bun.  You babble meaninglessly this long, and now you're leaving?  I could have been doing something useful, ya daft satsuma. ";
                    return navLoopC;
                }
                
                if (navLoopI == "yes" || navLoopI == "y" || navLoopI == "Yes" || navLoopI == "Y" || navLoopI == "YES" || navLoopI == "YES." || navLoopI == "Yes.")
                {
                    
                    navLoopC = navLoopI;
                    return navLoopC;
                    
                }
                
                if (navLoopI != "yes" && navLoopI != "y" && navLoopI != "Yes" && navLoopI != "Y" && navLoopI != "YES" && navLoopI != "YES." && navLoopI != "Yes." && navLoopI != "no" && navLoopI != "n" && navLoopI != "No" && navLoopI != "N" && navLoopI != "NO" && navLoopI != "NO." && navLoopI != "No.")
                {
                    
                    navLoopJ = navLoopI;
                }
                if (navLoopC == "no." || navLoopC == "nO." || navLoopC == "yes." || navLoopC == "yeS." ||
                    navLoopC == "yES." || navLoopC == "YEs." || navLoopC == "YeS." || navLoopC == "yEs.")
                {
                    getSnarkyGrammar(navLoopC);
                    return navLoopC;
                }
                if (navLoopC == "NO!" || navLoopC == "YES!" || navLoopC == "Yes!" || navLoopC == "No!" || navLoopC == "No?" || navLoopC == "Yes?")
                {
                    getSnarkyTone(navLoopC);
                    return navLoopC;
                }
            }
            if ((irritation = 7))
            {
                std::cout << "Oh, come on.  Now you're just screwing around." << std::endl;
                navLoopJ = LoopInput7(navLoopJ);
                navLoopC = navLoopJ;
                
                if (navLoopJ == "no" || navLoopJ == "n" || navLoopJ == "No" || navLoopJ == "N" || navLoopJ == "NO" || navLoopJ == "NO." || navLoopJ == "No.")
                {
                    navLoopC = navLoopJ;
                    std::cout << "Really?  Really?  It took you seven circles of indecision to decide you didn't want to make another calculation.  It wasn't a hard decision.  You either needed to convert a date, or you didn't.  Your keyboard better have some sticky keys. ";
                    return navLoopC;
                }
                
                if (navLoopJ == "yes" || navLoopJ == "y" || navLoopJ == "Yes" || navLoopJ == "Y" || navLoopJ == "YES" || navLoopJ == "YES." || navLoopJ == "Yes.")
                {
                    
                    navLoopC = navLoopJ;
                    std::cout << "";
                    return navLoopC;
                    
                }
                
                if (navLoopJ != "yes" && navLoopJ != "y" && navLoopJ != "Yes" && navLoopJ != "Y" && navLoopJ != "YES" && navLoopJ != "YES." && navLoopJ != "Yes." && navLoopJ != "no" && navLoopJ != "n" && navLoopJ != "No" && navLoopJ != "N" && navLoopJ != "NO" && navLoopJ != "NO." && navLoopJ != "No.")
                {
                    
                    navLoopK = navLoopJ;
                }
                if (navLoopC == "no." || navLoopC == "nO." || navLoopC == "yes." || navLoopC == "yeS." ||
                    navLoopC == "yES." || navLoopC == "YEs." || navLoopC == "YeS." || navLoopC == "yEs.")
                {
                    getSnarkyGrammar(navLoopC);
                    return navLoopC;
                }
                if (navLoopC == "NO!" || navLoopC == "YES!" || navLoopC == "Yes!" || navLoopC == "No!" || navLoopC == "No?" || navLoopC == "Yes?")
                {
                    getSnarkyTone(navLoopC);
                    return navLoopC;
                }
            }
            if ((irritation = 8))
            {
                
                std::cout << "Don't mind me, I'm just heading out for a cup of coffee.  You want anything? Try to figure out if you want to make another calculation before I get back." << std::endl;
                navLoopK = LoopInput8(navLoopK);
                navLoopC = navLoopK;
                
                if (navLoopK == "no" || navLoopK == "n" || navLoopK == "No" || navLoopK == "N" || navLoopK == "NO" || navLoopK == "NO." || navLoopK == "No.")
                {
                    navLoopC = navLoopK;
                    std::cout << "No? NO? You want a piece of me? Ah, whatever. Thank you for using the Terran Calendar Converter. Please do not call again, mud-dwelling tic. ";
                    return navLoopC;
                }
                
                if (navLoopK == "yes" || navLoopK == "y" || navLoopK == "Yes" || navLoopK == "Y" || navLoopK == "YES" || navLoopK == "YES." || navLoopK == "Yes.")
                {
                    
                    navLoopC = navLoopK;
                    return navLoopC;
                    
                }
                
                if (navLoopK != "yes" && navLoopK != "y" && navLoopK != "Yes" && navLoopK != "Y" && navLoopK != "YES" && navLoopK != "YES." && navLoopK != "Yes." && navLoopK != "no" && navLoopK != "n" && navLoopK != "No" && navLoopK != "N" && navLoopK != "NO" && navLoopK != "NO." && navLoopK != "No.")
                {
                    
                    //std::cout << "Snarkity snarkity snarky snark snarkle?" << std::endl;
                    navLoopL = navLoopK;
                }
                if (navLoopC == "no." || navLoopC == "nO." || navLoopC == "yes." || navLoopC == "yeS." ||
                    navLoopC == "yES." || navLoopC == "YEs." || navLoopC == "YeS." || navLoopC == "yEs.")
                {
                    getSnarkyGrammar(navLoopC);
                    return navLoopC;
                }
                if (navLoopC == "NO!" || navLoopC == "YES!" || navLoopC == "Yes!" || navLoopC == "No!" || navLoopC == "No?" || navLoopC == "Yes?")
                {
                    getSnarkyTone(navLoopC);
                    return navLoopC;
                }
            }
            if ((irritation = 9))
            {
                
                std::cout << "Oh. You still can't decide.  What a surprise.  I'll put on some tea.  Shall I heat up some crumpets?" << std::endl;
                navLoopL = LoopInput9(navLoopL);
                navLoopC = navLoopL;
                
                if (navLoopL == "no" || navLoopL == "n" || navLoopL == "No" || navLoopL == "N" ||
                    navLoopL == "NO" || navLoopL == "NO." || navLoopL == "No.")
                {
                    
                    navLoopC = navLoopL;
                    std::cout << "I've really had it with jerks like you.  Begone. ";
                    return navLoopC;
                }
                
                if (navLoopL == "yes" || navLoopL == "y" || navLoopL == "Yes" || navLoopL == "Y" ||
                    navLoopL == "YES" || navLoopL == "YES." || navLoopL == "Yes.")
                {
                    
                    navLoopC = navLoopL;
                    return navLoopC;
                    
                }
                
                if (navLoopL != "yes" && navLoopL != "y" && navLoopL != "Yes" && navLoopL != "Y" &&
                    navLoopL != "YES" && navLoopL != "YES." && navLoopL != "Yes." && navLoopL != "no" && navLoopL != "n" &&
                    navLoopL != "No" && navLoopL != "N" && navLoopL != "NO" && navLoopL != "NO." && navLoopL != "No.")
                {
                    
                    navLoopM = navLoopL;
                }
                if (navLoopC == "no." || navLoopC == "nO." || navLoopC == "yes." || navLoopC == "yeS." ||
                    navLoopC == "yES." || navLoopC == "YEs." || navLoopC == "YeS." || navLoopC == "yEs.")
                {
                    getSnarkyGrammar(navLoopC);
                    return navLoopC;
                }
                if (navLoopC == "NO!" || navLoopC == "YES!" || navLoopC == "Yes!" || navLoopC == "No!" || navLoopC == "No?" || navLoopC == "Yes?")
                {
                    getSnarkyTone(navLoopC);
                    return navLoopC;
                }
                
            }
            if ((irritation = 10))
            {
                std::cout << "No, seriously you just type 'yes' or 'no' and then press the big key labeled either 'enter' or 'return'.  Might be labled both. Also 'y' or 'n', would do.  'Y', or 'N', also work. 'NO', and 'YES', if you're in a mood, or if your caps lock is stuck.  This is your last chance to tell me if you want to MAKE ANOTHER CALCULATION OR NOT, or I'm hanging up on you." << std::endl;
                navLoopM = LoopInput10(navLoopM);
                navLoopC = navLoopM;
                
                if (std::cin.fail())
                {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max());
                    return navLoopC;
                }
                
                if (navLoopM == "no" || navLoopM == "n" || navLoopM == "No" || navLoopM == "N" ||
                    navLoopM == "NO" || navLoopM == "NO." || navLoopM == "No.")
                {
                    navLoopC = navLoopM;
                    std::cout << "Screw you. ";
                    return navLoopC;
                    
                }
                
                if (navLoopM == "yes" || navLoopM == "y" || navLoopM == "Yes" || navLoopM == "Y" ||
                    navLoopM == "YES" || navLoopM == "YES." || navLoopM == "Yes.")
                {
                    
                    navLoopC = navLoopM;
                    return navLoopC;
                    
                }
                
                if (navLoopM != "yes" && navLoopM != "y" && navLoopM != "Yes" && navLoopM != "Y" && navLoopM != "YES" &&
                    navLoopM != "YES." && navLoopM != "Yes." && navLoopM != "no" && navLoopM != "n" && navLoopM != "No" &&
                    navLoopM != "N" && navLoopM != "NO" && navLoopM != "NO." && navLoopM != "No.")
                {
                    
                    std::cout << "Screw you. ";
                }
                
            }
            
            navLoopC = "n";
            return navLoopC;
        }
        
    }
    
    return navLoopC;
}

std::string getSnarkyGrammar (std::string &navLoopC)
{
    while (navLoopC == "no." || navLoopC == "nO." || navLoopC == "yes." || navLoopC == "yeS." ||
           navLoopC == "yES." || navLoopC == "YEs." || navLoopC == "YeS." || navLoopC != "yEs.")
    {
        std::cout << "Typical commands, if you please.  And if you're going to use a period, please use it in a valid sentence.  Would you like to use the converter again?" <<std::endl;
        navLoopC = exitInput1();
        
        while (navLoopC != "yes" && navLoopC != "y" && navLoopC != "Yes" && navLoopC != "Y" && navLoopC != "YES" && navLoopC != "YES."
               && navLoopC != "Yes." && navLoopC != "no" && navLoopC != "n" && navLoopC != "No" && navLoopC != "N" && navLoopC != "NO"
               && navLoopC != "NO." && navLoopC != "No." && navLoopC != "no." && navLoopC != "nO." && navLoopC != "yes."
               && navLoopC != "yeS." && navLoopC != "yES." && navLoopC != "YEs." && navLoopC != "YeS.")
        {
            std::cout << "That's not valid input, try again ya daft fool." << std::endl;
            navLoopC = exitInput1();
        }
        if (navLoopC == "yes" || navLoopC == "y" || navLoopC == "Yes" || navLoopC == "Y" || navLoopC == "YES" || navLoopC == "YES."
            || navLoopC == "Yes." || navLoopC == "no" || navLoopC == "n" || navLoopC == "No" || navLoopC == "N" || navLoopC == "NO"
            || navLoopC == "NO." || navLoopC == "No.")
        {
            return navLoopC;
        }
        
    }
    return navLoopC;
}

std::string getSnarkyTone (std::string &navLoopC)
{
    while (navLoopC == "NO!" || navLoopC == "YES!" || navLoopC == "Yes!" || navLoopC == "No!")
    {
        std::cout << "I don't respond well to that tone.  Please be more polite in your responses.  Would you like to use this tool again?" << std::endl;
        navLoopC = exitInput1();
        //return navLoopC;
        if (navLoopC == "yes" || navLoopC == "y" || navLoopC == "Yes" || navLoopC == "Y" || navLoopC == "YES" || navLoopC == "YES."|| navLoopC == "Yes." || navLoopC == "no" || navLoopC == "n" || navLoopC == "No" || navLoopC == "N" || navLoopC == "NO"
            || navLoopC == "NO." || navLoopC == "No.")
        {
            return navLoopC;
        }
    }
    while (navLoopC == "No?" || navLoopC == "Yes?")
    {
        std::cout << "Well, you let me know when you've made up your mind." << std::endl;
        navLoopC = exitInput1();
        //return navLoopC;
        if (navLoopC == "yes" || navLoopC == "y" || navLoopC == "Yes" || navLoopC == "Y" || navLoopC == "YES" || navLoopC == "YES."|| navLoopC == "Yes." || navLoopC == "no" || navLoopC == "n" || navLoopC == "No" || navLoopC == "N" || navLoopC == "NO"
            || navLoopC == "NO." || navLoopC == "No.")
        {
            return navLoopC;
        }
    }
    
    return navLoopC;
}
//***************************Calculators****************************

//  This section is fairly self explanatory.  Each function here calculates the input date from a selected calendar to another.

double dateCalcAStoEE (double &date, double &newdateAStoEE)
{
    
    if (date >= 2183)
    {
        newdateAStoEE = date - 2182;  //Converts A.S. to E.E.
    }
    if ((date >= 0) && (date < 2183))
    {
        newdateAStoEE = -date + 2182; //Converts A.S. to T.E.
    }
    if (date < 0)
    {
        newdateAStoEE = -date + 2182; //Converts E.S. to T.E.
    }
    
    return newdateAStoEE;
}

double dateCalcAStoXE (double &date, double &newdateAStoXE)
{
    if (date >= 2574)
    {
        newdateAStoXE = (date / 2.7397) - 939.5189; //Converts A.S. to X.E.
    }
    if ((date >= 0) && (date < 2574))
    {
        newdateAStoXE = (-date / 2.7397) + 939.5189; //Converts A.S. to G.E.
    }
    if (date < 0 )
    {
        newdateAStoXE = (-date / 2.7397) + 939.5189; //Converts E.S. to G.E.
    }
    
    return newdateAStoXE;
}

double dateCalcAStoCT (double &date, double &newdateAStoCT)
{
    if (date >= 2983)
    {
        newdateAStoCT = (date / 2.8055) - 1063.2686; //Converts A.S. to C.T.
    }
    if ((date >= 0) && (date < 2983))
    {
        newdateAStoCT = (-date / 2.8055) + 1063.2686; //Converts A.S. to P.Z.
    }
    if (date < 0 )
    {
        newdateAStoCT = (-date / 2.8055) + 1063.2686; //Converts E.S. to P.Z.
    }
    
    return newdateAStoCT;
}

double dateCalcEEtoAS (double &date, double &newdateEEtoAS)
{
    if (date >= 0)
    {
        newdateEEtoAS = date + 2182; //Converts E.E. to A.S.
    }
    if ((date < 0) && (date > -2182))
    {
        newdateEEtoAS = 2182 - -date; //Converts T.E. to A.S.
    }
    if (date <= -2183)
    {
        newdateEEtoAS = 2181 - -date; //Converts T.E. to E.S.
    }
    
    return newdateEEtoAS;
}

double dateCalcEEtoCT (double &date, double &newdateEEtoCT)
{
    if (date >= 801)
    {
        newdateEEtoCT = (date / 2.8055) - 285.5106; //Converts E.E. to X.E.
    }
    if ((date < 801) && (date >= 0))
    {
        newdateEEtoCT = (-date/ 2.8055) + 285.5106; //Converts E.E. to G.E.
    }
    if (date < 0)
    {
        newdateEEtoCT = (-date / 2.8055) + 285.5106; //Converts T.E. to G.E.
    }
    
    return newdateEEtoCT;
}

double dateCalcEEtoXE (double &date, double &newdateEEtoXE)
{
    if (date >= 392)
    {
        newdateEEtoXE = (date / 2.7397) - 143.0813; //Converts E.E. to X.E.
    }
    if ((date < 392) && (date >= 0))
    {
        newdateEEtoXE = (-date/2.7397) + 143.0813; //Converts E.E. to G.E.
    }
    if (date < 0)
    {
        newdateEEtoXE = (-date /2.7397) + 143.0813; //Converts T.E. to G.E.
    }
    
    return newdateEEtoXE;
}

double dateCalcXEtoAS (double &date, double &newdateXEtoAS)
{
    if (date >= 0)
    {
        newdateXEtoAS = (2.7397 * date) + 2574; //Converts X.E. to A.S.
    }
    if ((date < 0) && (date > -939.5189))
    {
        newdateXEtoAS = (2.7397 * date) + 2574; //Converts G.E. to A.S.
    }
    if (date <= -939.5189)
    {
        newdateXEtoAS = (2.7397 * -date) - 2574; //Converts G.E. to E.S.
    }
    return newdateXEtoAS;
}

double dateCalcXEtoEE (double &date, double &newdateXEtoEE)
{
    if (date >= 0)
    {
        newdateXEtoEE  = (2.7397 * date) + 392.0; //Converts X.E. to E.E.
    }
    if ((date < 0) && (date > -143.0813))
    {
        newdateXEtoEE  = (2.7397 * date) + 392.0; //Converts G.E. to E.E.
    }
    if (date <= -143.0813)
    {
        newdateXEtoEE  = (2.7397 * -date) - 392.0; //Converts G.E. to T.E.
    }
    
    return newdateXEtoEE;
}

double dateCalcXEtoCT (double &date, double &newdateXEtoCT)  //REPAIRED.
{
    if (date >= 0)
    {
        newdateXEtoCT = (date * 1.0240) + 152.8688; //Converts C.T. to X.E.
    }
    if ((date < 0) && (date >= -149.2860))
    {
        newdateXEtoCT = (-date * 1.0240) - 152.8688; //Converts C.T. to G.E.
    }
    if (date < -149.2860)
    {
        newdateXEtoCT = (-date * 1.0240) - 152.8688; //Converts P.Z. to G.E.
    }
    
    return newdateXEtoCT;
}

double dateCalcCTtoAS (double &date, double &newdateCTtoAS)
{
    if (date >= 0)
    {
        newdateCTtoAS = (2.8055 * date) + 2983; //Converts X.E. to A.S.
    }
    if ((date < 0) && (date > -1063.2686))
    {
        newdateCTtoAS = (2.8055 * date) + 2983; //Converts G.E. to A.S.
    }
    if (date <= -1063.2686)
    {
        newdateCTtoAS = (2.8055 * -date) - 2983; //Converts G.E. to E.S.
    }
    return newdateCTtoAS;
}

double dateCalcCTtoEE (double &date, double &newdateCTtoEE)
{
    if (date >= 0)
    {
        newdateCTtoEE = (2.8055 * date) + 801; //Converts X.E. to A.S.
    }
    if ((date < 0) && (date > -285.5106))
    {
        newdateCTtoEE = (2.8055 * date) + 801; //Converts G.E. to A.S.
    }
    if (date <= -285.5106)
    {
        newdateCTtoEE = (2.8055 * -date) - 801; //Converts G.E. to E.S.
    }
    
    return newdateCTtoEE;
}

double dateCalcCTtoXE (double &date, double &newdateCTtoXE)
{
    if (date >= 152.8688)
    {
        newdateCTtoXE = (date / 1.0240) - 149.2860; //Converts C.T. to X.E.
    }
    if ((date >= 0) && (date < 152.8688))
    {
        newdateCTtoXE = (-date / 1.0240) + 149.2860; //Converts C.T. to G.E.
    }
    if (date < 0)
    {
        newdateCTtoXE = (-date / 1.0240) + 149.2860; //Converts P.Z. to G.E.
    }
    
    return newdateCTtoXE;
}


//  DEVELOPMENT NOTES:
//  * * * * * * * * * * * * * * * * * *
//  General Code Notes and Design Ideas
//  * * * * * * * * * * * * * * * * * *
//  - Design premise for convertAll:
//  - - - - - - - - - - - - - - - - -
//  ---> There should simply be an additional menu option for CalSelect1, which then leads to a CalSelect2 choice.
//  ---> This choice should read something like "'Z' to convert all",
//  ---> followed by "'Y' to convert to 'CalSelect1'", and "'X' to convert to 'CalSelect2'"
//  - - - - - - - - - - - - - - - - -
//  Design notes regarding getSnarky:
//  - - - - - - - - - - - - - - - - -
//  - The basic skeleton is finished, though it definietly needs to be slimmed down, broken into functions and generally
//  tidied up.
//  - The final structure should probably use the sub-functions to turn the primary function into a sort of sub-program that will
//  hopefully be rather transferable.  With this in mind, the idea is to be able to call the function to be used in a number
//  of places and circumstances inside the main.  The sub-functions may serve a single purpose (such as the 'complete sentences'
//  remark) but should ultimately be reusable inside the snarkina ex machina itself.
//  - getSnarkyImTooDumbForThat will be excellent at reminding users to use simple, intuitive input.
//  - getSnarkyGuessWhat will be fun to deploy after a certain amount of input failure, and might instruct the user how
//  to do something correctly, or suggest a different course of action. Snarkily, or course.
//  - getSnarkyImSmarterThanYou will automatically correct certain user input, and then bitch about it.  This will use
//  various string reading functions (such as .find) and transform functions (such as toupper).  One example might be to get
//  snarky about having to capitalize the first letter of a word.
//  - ADDITIONAL WORK NEEDED:
//  ---> Function getSnarkyTone. <--- DONE
//  ---> New messages for quitting at different points in the process (the for loop).  Possibly for agreeing to
//  continue, as well. They should be written without endline statements so that they will print with the
//  'Goodbye.' message.  All should be able to with said word as well. <--- IN PROGRESS
//  ---> In terms of housekeeping, the big if statements with a bunch of && =! should probably get changed
//  to trailing else statements. It will be way easier in the long run, and in reality is probably better
//  programming practice. This may or may not occur, as the author is starting to prefer the specificity of ifs.
//  - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//  Design notes regarding implementation of C.T. Calendar:
//  - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//  - The premise of this is simple; write a new formula, plug it in, see if it works, tweak it until it does.  Unfortunately,
//  the actual implementation, as I presently understand it will require an addtional 12 print conditions/if statements, and
//  six new date calculators.
//  * * * * * * * * * * * * * * * * * * * * * * * *
//  Error Flags, Questionable Code, and Bug Reports
//  * * * * * * * * * * * * * * * * * * * * * * * *
//  - In certain instances, funky input still occurs when very specific things are entered by the user. When the integer 392 is
//  entered into dateCalcEEtoXE, it prints in scientific notation.  At present this is the only known example of this bug.
//  This bug was solved by implementing a fixed print, and setting the precision to 3 decimal points (for the X.E./G.E.
//  calendar).
//  - When printing the results for dateCalcCTtoXE, if exactly '152.8688' is entered (a threshold value), then the converter
//  will print -0.000 instead of 0.000.  Again, this is the only known instance of this issue, but is likely to be repeated
//  frequently throughout the program.
//  - In certain cases, if the user inputs anything too quickly, an input character or two appear at the
//  beginning of the next output message, and potentially also get lodged in the buffer?  Weird error.
//  - Occasionally, the program will simply ignore acceptable input, and display an error message.  This was recently (11-5-2015)
//  confirmed when 'n' failed a number of times at the exit loop. Program was immediately tested again for errors without
//  editing any code.  What's up with this?  Grrr.  Who can say?
//  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//  Design notes regarding implementation of Months/Days Converter:
//  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//  - Since the original design was based on user input, there could be a separate simple converter to convert what any calendar day is just
//  within the typical calendar year of another calendar.
//  * * * * * * * * * * * * * * * * * * * * * * *
//  Future Functionality for Later Implementation
//  * * * * * * * * * * * * * * * * * * * * * * *
//  - Converting months, weeks and days.  Possibly hours, minutes, seconds, etc., but not necessarily.  The bits that would
//  actually be likely to appear on a calendar are what's important.
//  ---> This will be easiest with Carnon Time  and the Xix Era .  They can be broken down as normal formulas.
//  ---> Elbert Era  and Aeon Series, which more or less use the Gregorian Calendar, will be more complex.  They will provide
//  an excellent opportunity to work with arrays, so that specific days can be listed by name.  Probably by dividing the
//  year by 365 and listing each of those numbers sequentially as a calendar date.  The same technique could be adapted
//  adapted for any other calendar which required days or months other than those of the Gregorian system.
//  ---> ROAD BLOCK.  Need to learn how to access the decimal, and only the decimal in order to do this calculation.
//  - Additional calendars.  Maybe more terran calendars, but definitely alien calendars.
//  - A convertAll function?  One which converts a single numeric date across all possible conversions and lists them in
//  a prearranged, or even user-specified order?  Kind of silly, but it's another layer of functionality and organization
//  simultaneously, so it's probably good practice, if nothing else.  <--- DONE
//  --->  The best way to organize this would probably just be to add an 'all' option to the first calendar select menu.
//  This would give the option of allowing the user to convert all calendars to a specific calendar, rather than one to all others.
//  Additionally, this function would of course work to convert all calendars to all calendars as well.  It would only print in
//  a prearranged order, though.
//  - Write function getSnarky.  Just a series of if statements, while loops, and for loops (do/whiles seem unlikely) designed
//  to respond to certain user input with snarky or insulting comments. Deploy under appropriate circumstances. <--- ESTABLISHED
//  - Probably at some point, exclude the newline character from input.  Don't make it invalid, just specifically ignore it,
//  so that if the user presses enter a bunch of times, there won't be a bunch of white space.  Alternatively, an error
//  message will be fine, if that's all that can be accomplished.
//  * * * * * * * * * * * * * * *
//  New Calendars and Other Ideas
//  * * * * * * * * * * * * * * *
//  - C.T. and P.Z. for Carnon Time  and Pre-Zero are a strong candidate.  They would be similar to the Exile and
//  Galactic Eras, and used most heavily by those who utilize information and cybernetic systems in a completely
//  dependent fashion.  This method of measuring judges years in terms of 1024 days, rather than the 1000 of the Galactic Era.
//  In Carnon Time , each day is divided into binary halves; night and day.
