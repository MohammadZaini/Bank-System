#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"
#include <fstream>

class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;
        short FailedLoginCount = 0;

        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                FailedLoginCount++;

                cout << "\nInvalid Username/Password!";
                cout << "\nYou have " << (3 - FailedLoginCount)
                    << " Trial(s) to login.\n\n";
            }

            if (FailedLoginCount == 3)
            {
                cout << "\nSystem has been Locked after 3 failed trails \n\n";
                return false;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenu();
        return true;
    }

public:

    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t    Login Screen");
        return _Login();

    }

};