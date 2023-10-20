#include <iostream>
#include <conio.h>
#include "Budget.h"

using namespace std;

int main() {

    Budget budget("Users.xml");
    char choose;

    while(1) {

        if (!budget.whetherUserIsLogged()) {

            system("cls");
            budget.loginMenu();
            choose = getch();

            switch (choose) {

            case '1':
                budget.userRegistration();
                break;

            case '2':
                budget.logging();
                break;

            case'3':
                budget.showUsers();
                break;

            case '9':
                exit(0);

            default:
                cout << endl << "Option does not exist." << endl << endl;
                system("pause");
                break;
            }

        } else {

            system("cls");
            budget.userMenu();
            choose = getch();

            switch(choose) {

            case '6':
                budget.passwordChange();
                break;

            case '9':
                budget.loggingOut();
                break;

            default:
                cout << endl << "Option does not exist." << endl << endl;
                system("pause");
                break;
            }
        }
    }
}
