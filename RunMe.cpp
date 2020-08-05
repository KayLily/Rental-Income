/***********************************************************************
* Basic Rental Income Calculator - Based on Minimal Financial Factors
* Kaylynne - July 2020 
************************************************************************/
#include <iostream>
#include <string>
using namespace std;


/**********************************************************************
 * Prompt user for: Desired Rent; Mortgage; Monthly Expenses; State; 
 * HAO & fee's; Vacancy cost; Management & fee's; 
**********************************************************************/
//Prompt: Ask user for data input
bool prompt()
{
    char proceed;
    bool answer = false;

    cout << endl << endl
         << "Welcome User!" << endl
         << "Would you like help figureing out the ROI of a property?\n"
         << "Please type 'Y' or 'N'." << endl;
    
    cin >> proceed;

    switch (proceed)
    {
    case 'Y':
        cout << "Excellent! Let's continue.\n\n ";
        answer = true;
        break;
    case 'y':
        cout << "Excellent! Let's continue.\n\n ";
        answer = true;
        break;
    default:
         cout << "Sorry I was unable to assist you. Good luck.\n";
        break;
    }

  return answer;
/*******************************************************************************
 * This code is basic and was 'broken' - allowing any char to be inserted.
 * The switch case allows for multiple input options; but only via int or char.
 *******************************************************************************
    cin  >> proceed;

    if (proceed == 'N')
        cout << "Sorry I was unable to assit you. Good luck." << endl;
    else
        cout << "Excellent! Let's continue. " << endl << endl;
*********************************************************************************/
}

//Gets and holds users mortgage price
float getMortgage()
{
    float mortgage;

    cout << "How much do you or will you be paying in Mortgage monthly?\n";
    cin  >> mortgage;

    return mortgage;
}

//Holds user's asking rent price
float getRent()
{
    float rent;

    cout << "How much are you wanting for rent?\n";
    cin  >> rent;
    
    return rent;
}

//Tax rate based on user's input - As of Feb 2020 "Wallet Hub"
float getTax()
{
    string stateName;
    float tax = 2.14;

    cout << "Which USA State are you looking in? " << endl;
    cin  >> stateName;


/*******************************************************************************************************************
    if (stateName == "Alabama" || "AL")
       {
            tax = 0.42;
            cout << "You said: " << stateName << " which has a Tax Rate of "
                 << tax << "%" << endl;
       }
    if else (stateName == "Alaska" || "AK")
        {
            tax =  1.18;
            cout << "You said: " << stateName << " which has a Tax Rate of "
                 << tax << "%" << endl;
        }
    else 
        {
            cout << "Sorry, that was invalid. Would you like to try typing it again? " << endl;           
        }
***********************************************************************************************************************/
    return tax;
}

//Holds HOA fee based on user's input
float HOA()
{
    char hoa;
    float hoaFee = 200;
// ASK about HOA
    cout << "Does the property have an HOA?\n";
    cin  >> hoa;

     switch (hoa)
    {
    case 'Y':
        cout << "Excellent! Let's continue.\n";
        cout << "How much will you be paying monthly for your HOA?\n If you do not know the cost, please enter 'N'.\n ";
        cin  >> hoaFee;
        break;
    case 'y':
        cout << "Excellent! Let's continue.\n\n ";
        cout << "How much will you be paying monthly for your HOA?\n If you do not know the cost, please enter 'N'.\n ";
        cin  >> hoaFee;
        break;
    default:
        hoaFee = 0;
        break;
    }
    
    return hoaFee;
}

//Money lost if proptery is vacant -- Mortgage - Rent
float vacancy(float mortgage, float hoaFee, float tax)
{

    return 0;
}

//Average cost of management company
float managementFee()
{
    char answer;
    bool management = false;
    float setupFee = 0;

    cout << "Will you be using a Property Management company?\n";
    cin  >> answer;

     switch (answer)
    {
    case 'Y':
        cout << "Due to a large variance of company fee's, we will assume a flate rate of $300 initial costs, and 9% of the monthly income.\n\n";
        management = true;
        setupFee = 300;
        break;
    case 'y':
         cout << "Due to a large variance of company fee's, we will assume a flate rate of $300 initial costs, and 9% of the monthly income.\n\n";
        management = true;
        setupFee = 300;
        break;
    default:
        management = false;
        break;
    }

    return setupFee;
}

//Does final Calculation
float calculate(float mortgage, float hoaFee, float rent, float tax, float vacant, float management)
{
    float ROI = 0;
    float monthlyPayments = 0;

    cout << mortgage << endl << hoaFee << endl << management << endl;

    monthlyPayments = mortgage + hoaFee + management;
    cout << monthlyPayments;

    return ROI;
}

//Is this a good home to rent
bool goodRental()
{
    return 0;
}
/************************************************************************
 * MAIN
************************************************************************/
int main ()
{
    bool answer = prompt();

    if (answer)
    {
        float mortgage = getMortgage();
        float hoaFee= HOA();
        float tax = getTax();
        float vacant = vacancy(mortgage, hoaFee, tax);
        float management = managementFee();
        float rent = getRent();
        calculate(mortgage, hoaFee, rent, tax, vacant, management);
    }   
    else
        cout << "Good luck!\n";   

    return 0;
}