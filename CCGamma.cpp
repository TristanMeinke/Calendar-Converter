/* This project is the continued refinement of the Calendar Converter project.  It allows the conversion of dates from one
/  fictional calendar to another, designed at primarily as a tool to improve ease of writing.  Since it's original conception,
/  it has become something of an academic exercise in flow control and error handling.
/  Created by Tristan on 10/20/15.
/  Copyright © 2015 Tristan. All rights reserved.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>

int main()
{

    std::string navA;
    std::string navB;
    double date;
    std::string navC;
    int navZ = 0;
    int navY = 0;
 
   do
       {
           
// ------------------------------------------ Menus -----------------------------------------------------
           
            std::cout << "Which Calendar would you like to convert from?" << std::endl; //Main menu
            std::cout << "Select '1' for Aeon Series." << std::endl;
            std::cout << "Select '2' for Xix Era." << std::endl;
            std::cout << "Select '3' for Elbert Era." << std::endl;
           
            std::cin >> navA;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Clears the input buffer preimptively to keep bad input from lurking in the wings.
            std::stringstream convert(navA);
           
            if ( !(convert >> navZ))
            {
                navZ = 0;
            }
           
            while (navA != "1" && navA != "2" && navA != "3")
            {
                
                std::cout << "Please select a valid menu option." << std::endl; //Initial input error message and secondary menu prompt
                std::cout << "Select '1' for Aeon Series." << std::endl;
                std::cout << "Select '2' for Xix Era." << std::endl;
                std::cout << "Select '3' for Elbert Era." << std::endl;

                std::cin >> navA;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Clears the input buffer so the loop won't fire multiple times with input including spaces; amongst other things.
                
                std::stringstream convert(navA);
                
                if ( !(convert >> navZ))
                {
                    navZ = 0;
                }
                
            }
           
            if (navZ == 1)
            {
                std::cout << " - - - - - - - - - - - - " << std::endl;
                std::cout << "Which Calendar would you like to convert to?" << std::endl;
                std::cout << "Select '1' for Xix Era." << std::endl;
                std::cout << "Select '2' for Elbert Era." << std::endl;
                
                std::cin >> navB;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                std::stringstream convert(navB);
                
                    if ( !(convert >> navY))
                        {
                            navY = 0;
                        }
                
                while (std::cin.fail())
                {
                    std::cout << "Please select a valid menu option." << std::endl; //navB error message and secondary menu prompt
                    std::cout << "Select '1' for Xix Era." << std::endl;
                    std::cout << "Select '2' for Elbert Era." << std::endl;
                }
            }
            if (navZ == 2)
            {
                std::cout << " - - - - - - - - - - - - " << std::endl;
                std::cout << "Which Calendar would you like to convert to?" << std::endl;
                std::cout << "Select '1' for Aeon Series." << std::endl;
                std::cout << "Select '2' for Elbert Era." << std::endl;
                
                std::cin >> navB;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                std::stringstream convert(navB);
                
                    if ( !(convert >> navY))
                        {
                            navY = 0;
                        }
                
                while (std::cin.fail())
                {
                    std::cout << "Please select a valid menu option." << std::endl; //navB error message and secondary menu prompt
                    std::cout << "Select '1' for Aeon Series." << std::endl;
                    std::cout << "Select '2' for Elbert Era." << std::endl;
                }
            }
            if (navZ == 3)
            {
                std::cout << " - - - - - - - - - - - - " << std::endl;
                std::cout << "Which Calendar would you like to convert to?" << std::endl;
                std::cout << "Select '1' for Aeon Series." << std::endl;
                std::cout << "Select '2' for Xix Era." << std::endl;
                
                std::cin >> navB;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                std::stringstream convert(navB);
                
                    if ( !(convert >> navY))
                        {
                            navY = 0;
                        }
                
                while (std::cin.fail())
                {
                    std::cout << "Please select a valid menu option." << std::endl; //navB error message and secondary menu prompt
                    std::cout << "Select '1' for Aeon Series." << std::endl;
                    std::cout << "Select '2' for Xix Era." << std::endl;
                }
            }
            while (navY != 1 && navY != 2)
            {
                std::cout << "Please enter '1', '2'." << std::endl; //third error message
                std::cin >> navB;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                std::stringstream convert(navB);
                
                if ( !(convert >> navY))
                {
                    navY = 0;
                }
                
            }
        
  // ------------------------------------ Calculations -----------------------------------------------
           
            if (navZ == 1 && navY == 1)
            {
                std::cout << " - - - - - - - - - - - - " << std::endl;
                std::cout << "Please enter the date you wish to convert from Aeon Series to the Xix Era:" << std::endl;
                
                std::cin >> date;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                while (std::cin.fail())
                {
                    std::cout << "Please enter a numeric date." << std::endl; //Another error message!
                    std::cin.clear();
                    std::cin.ignore(1024, '\n');
                    std::cin >> date;
                    std::cin.ignore(1024, '\n');
                }
                if (date > 2183)
                {
                    std::cout << " - - - - - - - - - - - - " << std::endl;
                    std::cout << "The year " << date << " A.S. is equivalent to: " << date - 2182 << " E.E." << std::endl; //This formula converts Aeon Series into Xix Era.
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
            }
            if (navZ == 1 && navY == 2)
            {
                std::cout << " - - - - - - - - - - - - " << std::endl;
                std::cout << "Please enter the date you wish to convert from Aeon Series to the Elbert Era:" << std::endl;
                
                std::cin >> date;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                while (std::cin.fail())
                    {
                        std::cout << "Please enter a numeric date." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(1024, '\n');
                        std::cin >> date;
                        std::cin.ignore(1024, '\n');
                    }
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
            }
            if (navZ == 2 && navY == 1)
            {
                std::cout << " - - - - - - - - - - - - " << std::endl;
                std::cout << "Please enter the date you wish to convert from the Xix Era to Aeon Series:" << std::endl;
                
                std::cin >> date;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                while (std::cin.fail())
                {
                    std::cout << "Please enter a numeric date." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1024, '\n');
                    std::cin >> date;
                    std::cin.ignore(1024, '\n');
                }
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
            }
            if (navZ == 2 && navY == 2)
            {
                std::cout << " - - - - - - - - - - - - " << std::endl;
                std::cout << "Please enter the date you wish to convert from the Xix Era to the Elbert Era:" << std::endl;
                
                std::cin >> date;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                while (std::cin.fail())
                {
                    std::cout << "Please enter a numeric date." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1024, '\n');
                    std::cin >> date;
                    std::cin.ignore(1024, '\n');
                }
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
            }
            if (navZ == 3 && navY == 1)
            {
                std::cout << " - - - - - - - - - - - - " << std::endl;
                std::cout << "Please enter the date you wish to convert from the Elbert Era to Aeon Series:" << std::endl;
                
                std::cin >> date;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                while (std::cin.fail())
                {
                    std::cout << "Please enter a numeric date." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1024, '\n');
                    std::cin >> date;
                    std::cin.ignore(1024, '\n');
                }
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

            }
            if (navZ == 3 && navY == 2)
            {
                std::cout << " - - - - - - - - - - - - " << std::endl;
                std::cout << "Please enter the date you wish to convert from the Elbert Era to the Xix Era:" << std::endl;
                
                std::cin >> date;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                while (std::cin.fail())
                {
                    std::cout << "Please enter a numeric date." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1024, '\n');
                    std::cin >> date;
                    std::cin.ignore(1024, '\n');
                }
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
            }
       
        std::cout << "Would you like to make another calculation?" << std::endl;
           std::cout << "Enter 'yes' to return to the main menu, enter 'no' to end the program." << std::endl;
        std::cout << " - - - - - - - - - - - - " << std::endl;
        
        std::cin >> navC;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
       }
    while (navC == "yes" || navC == "y" || navC == "Yes" || navC == "Y");
    
    while (navC != "yes" && navC != "y" && navC != "Yes" && navC != "Y"
           && navC != "no" && navC != "n" && navC != "No" && navC != "N")
    {
        std::cout << "Another calculation?" << std::endl;

        std::cin >> navC;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    if (navC == "no" || navC == "n" || navC == "No" || navC == "N")
      std::cout << "Goodbye." << std::endl;
    
    
    return 0;
}
