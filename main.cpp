#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool checkLoggedIn(){
    string username, password, un, pw;

    cout   << "Please enter your username" << endl;
    cin    >> username;
    cout   << "Please enter your password" <<endl;
    cin    >>password;

    ifstream read("Data\\" + username + ".txt");
    getline(read,un);
    getline(read,pw);
    if(un == username && pw == password){
        return true;

    }
        return false;

    }
int main()
{
    int choice;

    cout<<" 1:Register:\n 2:Login\n Enter your choice" <<endl; cin >> choice;

    if(choice == 1){
            string username, password;
        cout <<"Please enter a  preferred username"<<endl;
        cin >>username;
        cout<<"Please enter a preferred password"<<endl;
        cin>> password;

        ofstream file;
        file.open("Data\\"+ username + ".txt");
        file <<username << endl << password;
        file.close();
        main();

    }
    else if(choice == 2){
        bool status = checkLoggedIn();
        if(!status){
            cout<<"You have an invalid Login"<<endl;
            system("PAUSE");
            return 0;
        }
        else {
            cout <<"You have successfully logged in" <<endl;
            system("PAUSE");
            return 1;
        }

    }
    cout<<"You entered an invalid Input"<<endl;
    return 0;
}
