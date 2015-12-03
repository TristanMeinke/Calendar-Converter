#include <iostream>
#include <limits>
#include <string>

int main ()

{
    double varA = 10.0;
    double varB = 2.7397;
    
    int varX;
    int varY;
    int varZ;
    std::string varW;

    
    std::cout << "Choose Your Calendar:" << std::endl;
    std::cout << "Enter '1' for X.E. to E.E." << std::endl;
    std::cout << "Enter '2' for E.E. to X.E." << std::endl;
    
    std::cin >> varX;


  
   if (varX != 1 or 2)
   
       if (varX == 1)
       {std::cout << "Enter the date you wish to compute:" << std::endl;
           std::cin >> varY;
           std::cout << varY << "X.E. is equal to " << (varB * varY) + 392.0 << "E.E." << std::endl;}
    
       else if (varX == 2)
       {
            {std::cout << "Enter the date you wish to compute:" << std::endl;
            }
            std::cin >> varY;
            std::cout << varY << "E.E. is equal to " << varA * (varY / 27.397) - 143.0813 << "X.E." << std::endl;
        }
       else
       {
        do
            {
                std::cout << "Enter 1 or 2, or type 'end' to terminate." << std::endl;
                std::cin >> varX;
                //std::cin >> varW;
                if (varX == 1)
                    {
                        std::cout << "Enter the date you wish to compute:" << std::endl;
                        std::cin >> varY;
                        std::cout << varY << "X.E. is equal to " << (varB * varY) + 392.0 << "E.E." << std::endl;
                    }
                if (varX == 2)
                {
                    std::cout << "Enter the date you wish to compute:" << std::endl;
                    std::cin >> varY;
                    std::cout << varY << "E.E. is equal to " << varA * (varY / 27.397) - 143.0813 << "X.E." << std::endl;
                }
                
            }
        while (varX < 2);
       }
    
        //do
            //set continue variable to discontinue
            //input
    
            //thing 1
    
            //thing 2
    
            //continue??
                //set continue variable to continue
    
        //while
    
            
       
            
/*
 
    if (varX == 1)
            {std::cout << "Enter Your Date:" << std::endl;
            std::cin >> varY;
            std::cout << varY << "X.E. is equal to " << (varB * varY) + 392.0 << "E.E." << std::endl;}
    else
        do
            {std::cout << "1 or 2" << std::endl;
                std::cin >> varZ;
            if (varZ == 1)
                {std::cout << "Enter the date you wish to compute:" << std::endl;
                    std::cin >> varY;
                    std::cout << varY << "X.E. is equal to " << (varB * varY) + 392.0 << "E.E." << std::endl;}}

        while (varX != 1 or 2);

        
    if (varX == 2)
        {std::cout << "Enter the date you wish to compute:" << std::endl;
        std::cin >> varY;
        std::cout << varY << "E.E. is equal to " << varA * (varY / 27.397) - 143.0813 << "X.E." << std::endl;}
    else
        do{
            {std::cout << "1 or 2" << std::endl;
                std::cin >> varZ;}
        if (varZ == 1)
            {std::cout << "Enter the date you wish to compute:" << std::endl;
                std::cin >> varY;
                std::cout << varY << "E.E. is equal to " << varA * (varY / 27.397) - 143.0813 << "X.E." << std::endl;}}

    while (varX != 1 or 2);
 */
    
return 0;
}
