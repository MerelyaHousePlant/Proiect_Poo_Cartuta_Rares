#include "Usermenu.h"
using namespace std;

bool UserMenu::Authenticate()
{
    cout << "Pentru a continua este necesar sa dovedesti ca esti unul dintre utilizatori:" << endl;
    cout << "Cand esti gata sa incepi apasa tasta enter, atentie ai o singura incercare" << endl;
    system("pause");
    Session s(20);
    UserFileManager  ufm;
    int userID = (s.userSession());
    if (userID != 0)
    {
        cout << "Te-ai logat cu success: " << ufm.getUserByID(userID) << endl;
        return true;
    }
    else
    {
        cout << "Logarea a esuat" << endl;
        return false;
    }
}

void UserMenu::CalculatorMenu()
{
    Session firstObject;
    Session secondObject;
    int dataType;
    int operationType;
    cout << "Specificati tipul de data cu care doriti sa lucrati" << endl;
    cout << "Apasati 1 pentru int" << endl;
    cout << "Apasati 2 pentru float" << endl;
    cout << "Apasati 3 pentru obiect de tip Session" << endl;
    cin >> dataType;

switch (dataType)
{
    case 1:
    {

        Calculator<int> calc;
        cout << "Specificati tipul de operatie pe care doriti sa il faceti" << endl;
        cout << "Apasati 1 pentru adunare" << endl;
        cout << "Apasati 2 pentru scadere" << endl;
        cout << "Apasati 3 pentru inmultire" << endl;
        cout << "Apasati 4 pentru impartire" << endl;
        cout << "Apasati 5 pentru modulo" << endl;
        cin >> operationType;
        int firstNumber;
        int secondNumber;
        cout << "Introduceti primul numar: "<<endl;
        cin >> firstNumber;
        cout << "Introduceti al doilea numar: " << endl;
        cin >> secondNumber;
        switch (operationType)
        {
        case 1: cout << calc.CalculateSum(firstNumber, secondNumber) << endl;
            break;
        case 2: cout << calc.CalculateSubtraction(firstNumber, secondNumber) << endl;
            break;
        case 3: cout << calc.CalculateMultiplication(firstNumber, secondNumber) << endl;
            break;
        case 4: cout << calc.CalculateDivision(firstNumber, secondNumber) << endl;
            break;
        case 5: cout << calc.CalculateModulo(firstNumber, secondNumber) << endl;
            break;
        default: cout << "invalid operation";
        }
        break;
    }
    case 2:
        Calculator<float> calc2;
        cout << "Specificati tipul de operatie pe care doriti sa il faceti" << endl;
        cout << "Apasati 1 pentru adunare" << endl;
        cout << "Apasati 2 pentru scadere" << endl;
        cout << "Apasati 3 pentru inmultire" << endl;
        cout << "Apasati 4 pentru impartire" << endl;
        cout << "Apasati 5 pentru modulo" << endl;
        cin >> operationType;
        float firstNumber;
        float secondNumber;
        cout << "Introduceti primul numar: " << endl;
        cin >> firstNumber;
        cout << "Introduceti al doilea numar: " << endl;
        cin >> secondNumber;
        switch (operationType)
        {
        case 1: cout << calc2.CalculateSum(firstNumber, secondNumber) << endl;
            break;
        case 2: cout << calc2.CalculateSubtraction(firstNumber, secondNumber) << endl;
            break;
        case 3: cout << calc2.CalculateMultiplication(firstNumber, secondNumber) << endl;
            break;
        case 4: cout << calc2.CalculateDivision(firstNumber, secondNumber) << endl;
            break;
        //case 5: cout << calc2.CalculateModulo(firstNumber, secondNumber) << endl;
         //   break;
        default: cout << "invalid operation";
        }
        break;
    case 3:
        Calculator<Session> calc3;
        cout << "Specificati tipul de operatie pe care doriti sa il faceti" << endl;
        cout << "Apasati 1 pentru adunare" << endl;
        cout << "Apasati 2 pentru scadere" << endl;
        cout << "Apasati 3 pentru inmultire" << endl;
        cout << "Apasati 4 pentru impartire" << endl;
        cout << "Apasati 5 pentru modulo" << endl;
        cin >> operationType;
        cin >> firstObject;
        cin >> secondObject;
        switch (operationType)
        {
        case 1: cout << calc3.CalculateSum(firstObject, secondObject) << endl;
            break;
        case 2: cout << calc3.CalculateSubtraction(firstObject, secondObject) << endl;
            break;
        case 3: cout << calc3.CalculateMultiplication(firstObject, secondObject) << endl;
            break;
        case 4: cout << calc3.CalculateDivision(firstObject, secondObject) << endl;
            break;
        case 5: cout << calc3.CalculateModulo(firstObject, secondObject) << endl;
            break;
        default: cout << "operatie invalida";
        }
        break;
      default: cout << "tip de data invalid";
       break;
    }
    }