//Created 10/12/2015, by Tristan Meinke
//This program is designed as a tool to convert a number of fictional calendars from one to another.
//Additionally, it was an experiment in flow control and error handling.

#include <iostream>

int main()

{
    int navA;
    double date;
    int navB;

    do
    {
        std::cout << "Choose the calendar you wish to compute from:" << std::endl; //Main menu
        std::cout << "Select '1' for Aeon Series to Xix Era." << std::endl;
        std::cout << "Select '2' for Aeon Series to Elbert Era." << std::endl;
        std::cout << "Select '3' for Xix Era to Aeon Series." << std::endl;
        std::cout << "Select '4' for Xix Era to Elbert Era." << std::endl;
        std::cout << "Select '5' for Elbert Era to Aeon Series." << std::endl;
        std::cout << "Select '6' for Elbert Era to Xix Era." << std::endl;
        
        std::cin >> navA;
        while (std::cin.fail())
        {
            std::cout << "Please select a valid menu option." << std::endl; //Error message and secondary menu prompt
            std::cout << "'1' for A.S. to E.E." << std::endl;
            std::cout << "'2' for A.S. to X.E." << std::endl;
            std::cout << "'3' for E.E. to A.S." << std::endl;
            std::cout << "'4' for E.E. to X.E." << std::endl;
            std::cout << "'5' for X.E. to A.S." << std::endl;
            std::cout << "'6' for X.E. to E.E." << std::endl;
            std::cin.clear(); //This clears the input buffer of the failed state?
            std::cin.ignore(1024, '\n'); // ...? Honestly not sure what this is doing here, but it seems necessary.
            std::cin >> navA;
        }
    
        while (navA < 1 || navA > 6)
        {
            std::cout << "Please select a valid menu option." << std::endl; //Another way to reach this error message
            std::cout << "'1' for A.S. to E.E." << std::endl;  //and the secondary menu prompt.
            std::cout << "'2' for A.S. to X.E." << std::endl;
            std::cout << "'3' for E.E. to A.S." << std::endl;
            std::cout << "'4' for E.E. to X.E." << std::endl;
            std::cout << "'5' for X.E. to A.S." << std::endl;
            std::cout << "'6' for X.E. to E.E." << std::endl;
            std::cin >> navA;
        }
    
        if (navA == 1)
            {
                std::cout << "Enter the date you want to convert from A.S. to E.E." << std::endl;
                std::cin >> date;
                while (std::cin.fail())
                {
                    std::cout << "Please enter a numeric date." << std::endl; //Another error message!
                    std::cin.clear();
                    std::cin.ignore(1024, '\n');
                    std::cin >> date;
                }
                if (date > 2183)
                {
                    std::cout << " - - - - - " << std::endl;
                    std::cout << "The year " << date << " A.S. is equivalent to: " << date - 2182 << " E.E." << std::endl; //This formula converts Aeon Series into Xix Era.
                }
                if ((date >= 0) && (date < 2183))
                {
                    std::cout << " - - - - - " << std::endl;
                    std::cout << "The year " << date << " A.S. is equivalent to: " << -date + 2182 << " T.E." << std::endl; //This accounts for the overlap period between A.S. and T.E.
                }
                if (date < 0)
                {
                    std::cout << " - - - - - " << std::endl;
                    std::cout << "The year " << -date << " E.S. is equivalent to: " << -date + 2182 << " T.E." << std::endl;  //This formula reverses the dates to their opposite scales, and converts ?? to Terran Era.
                }
            }
        
        if (navA == 2)
            {std::cout << "Enter the date you want to convert from A.S. to X.E." << std::endl;
                std::cin >> date;
                while (std::cin.fail())
                {
                    std::cout << "Please enter a numeric date." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1024, '\n');
                    std::cin >> date;
                }
                if (date >= 2574)
                {
                    std::cout << " - - - - - " << std::endl;
                    std::cout << "The year " << date << " A.S. is equivalent to: " << (date / 2.7397) - 939.5189 << " X.E." << std::endl; //Primary calendar formula 2
                }
                if ((date >= 0) && (date < 2574))
                {
                    std::cout << " - - - - - " << std::endl;
                    std::cout << "The year " << date << " A.S. is equivalent to: " << (-date / 2.7397) + 939.5189 << " G.E." << std::endl; //Overlap formula 2
                }
                if (date < 0 )
                {
                    std::cout << " - - - - - " << std::endl;
                    std::cout << "The year " << -date << " E.S. is equivalent to: " << (-date / 2.7397) + 939.5189 << " G.E." << std::endl; //Reversal formula 2
                }
            }
        
        if (navA == 3)
            {std::cout << "Enter the date you wish to convert from E.E. to A.S." << std::endl;
                std::cin >> date;
                while (std::cin.fail())
                {
                    std::cout << "Please enter a numeric date." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1024, '\n');
                    std::cin >> date;
                }
                if (date >= 0)
                {
                    std::cout << " - - - - - " << std::endl;
                    std::cout << "The year " << date << " E.E. is equivalent to: " << date + 2182 << " A.S." << std::endl; //Primary calendar formula 3
                }
                if ((date < 0) && (date > -2182))
                {
                    std::cout << " - - - - - " << std::endl;
                    std::cout << "The year " << -date << " T.E. is equivalent to: " << 2182 - -date << " A.S." << std::endl; //Overlap formula 3
                }
                if (date <= -2183)
                {
                    std::cout << " - - - - - " << std::endl;
                    std::cout << "The year " << -date << " T.E. is equivalent to: " << 2182 - -date << " E.S." << std::endl; //Reversal formula 3
                }
            }
        
        if (navA == 4)
            {std::cout << "Enter the date you wish to convert from E.E. to X.E." << std::endl;
                std::cin >> date;
                while (std::cin.fail())
                {
                    std::cout << "Please enter a numeric date." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1024, '\n');
                    std::cin >> date;;
                }
                if (date >= 0)
                {
                    std::cout << " - - - - - " << std::endl;
                    std::cout << "The year " << date << " E.E. is equivalent to: " << (date / 2.7397) - 143.0813 << " X.E." << std::endl; //Primary calendar formula 4
                }
                if ((date < 0) && (date > -143.0813))
                {
                    std::cout << " - - - - - " << std::endl;
                    std::cout << "The year " << -date << " E.E. is equivalent to: " << (-date/2.7397) + 143.0813 << " G.E." << std::endl; //Overlap formula 4
                }
                if (date <= -143.0813)
                {
                    std::cout << " - - - - - " << std::endl;
                    std::cout << "The year " << -date - 143.0813 << " T.E. is equivalent to: " << (-date /2.7397) + 143.0813 << " G.E." << std::endl; //Reversal formula 4; this formula has an ugly hole patched in it - the subtraction of 143.0813 on the input variable.  It does work, though.
                }
                
            }
        
        if (navA == 5)
            {std::cout << "Enter the date you wish to convert from X.E. to A.S." << std::endl;
                std::cin >> date;
                while (std::cin.fail())
                {
                    std::cout << "Please enter a numeric date." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1024, '\n');
                    std::cin >> date;
                }
                if (date >= 0)
                {
                    std::cout << " - - - - - " << std::endl;
                    std::cout << "The year " << date << " X.E. is equivalent to: " << (2.7397 * date) + 2574 << " A.S." << std::endl; //Primary calendar formula 5
                }
                if ((date < 0) && (date > -939.5189))
                {
                    std::cout << " - - - - - " << std::endl;
                    std::cout << "The year " << -date << " G.E. is equivalent to: " << (2.7397 * date) + 2574 << " A.S." << std::endl; //Overlap formula 5
                }
                if (date <= -939.5189)
                {
                    std::cout << " - - - - - " << std::endl;
                    std::cout << "The year " << -date << " G.E. is equivalent to: " << (2.7397 * -date) - 2574 << " E.S." << std::endl; //Reversal 5
                }
            }
        
        if (navA == 6)
            {std::cout << "Enter the date you wish to convert from X.E. to E.E." << std::endl;
                std::cin >> date;
                while (std::cin.fail())
                {
                    std::cout << "Please enter a numeric date." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1024, '\n');
                    std::cin >> date;
                }
                if (date >= 0)
                {
                    std::cout << " - - - - - " << std::endl;
                    std::cout << "The year " << date << " X.E. is equivalent to: " << (2.7397 * date) + 392.0 << " E.E." << std::endl; //Formula 6
                }
                if ((date < 0) && (date > -143.0813))
                {
                    std::cout << " - - - - - " << std::endl;
                    std::cout << "The year " << -date << " G.E. is equivalent to: " << (2.7397 * date) + 392.0 << " E.E." << std::endl; //Formula 6
                }
                if (date <= -143.0813)
                {
                    std::cout << " - - - - - " << std::endl;
                    std::cout << "The year " << -date << " G.E. is equivalent to: " << (2.7397 * -date) - 392.0 << " T.E." << std::endl; //Reversal 6
                }
            }
        
        std::cout << " - - - - - " << std::endl;
        std::cout << "Would you like to make another conversion?" << std::endl;
        std::cout << "Enter '1' to return to the menu, press any other key to end." << std::endl;
        std::cin >> navB; // This input returns the user to the main menu, or terminates the program.
        
        }
    while (navB == 1);
    
    if (navB != 1)
        std::cout << "Goodbye." << std::endl;
        
    return 0;
}

/* Major remaining problems include:
/Overlap periods - which is to say, a date could easily be recorded accurately as both G.E. and A.S.
/ --> This could perhaps be addressed by an additional if statement, or an else if followed by an else.
/ ----> As per usual, the if statements would be a little cleaner than the else if/else nonsense would be.
/ ------> PROBLEM SOLVED.
/ - - - - -
 Alright, now that the above issue has been resolved, the next step is probably to rewrite a lot of the formulas.
/For that though, a rewrite of the timeline in question itself might be in order, so that the calendar start dates
/form a more reasonable and perhaps meaningful pattern.  Regardless, the idea is it should be somewhat easier to track.
/ - - - - -
/Additionally, bad input is still possible.  This is noted at any stage if a character is input following a number on
/the same line.  This can be potentially avoided by taking input as a string, and converting it to an int.
/ --> When inputting navB
*/
