#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;
bool should_exit = false;
struct StockItem
{
    string id;
    string name;
    double quantity;
    double price;
    double total;
};
void loggin_owner();
void owner_settings();
void loggin_owner();
void login();
void see_stock();
void add();
void editStockItemFromFile();
void abort_function();
void see_stock_emp();
void abort_function()
{
    should_exit = true;
}
void editStockItemFromFile()
{
    cout << endl
         << endl;
    fstream source_file;
    source_file.open("data.txt", ios::in);
    if (!source_file.is_open())
    {
        cout << "Error: Unable to open file " << "data.txt" << " for reading\n";
        return;
    }
    fstream destination_file;
    destination_file.open("edit.txt", ios::out);
    if (!destination_file.is_open())
    {
        cout << "Error: Unable to open file " << "edit.txt" << " for writing\n";
        source_file.close();
        return;
    }
    string line;
    cout << "Enter id: ";
    string inp;
    cin >> inp;
    StockItem cheeku;
    while (getline(source_file, line))
    {
        if (line.substr(0, inp.size()) == inp)
        {
            cout << line << endl;
            cout << "Enter new id: ";
            cin >> cheeku.id;
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, cheeku.name);
            cout << "Enter new quantity: ";
            cin >> cheeku.quantity;
            cout << "Enter new Price: ";
            cin >> cheeku.price;
            cheeku.total = cheeku.price * cheeku.quantity;
            destination_file << cheeku.id << ',' << cheeku.name << ',' << cheeku.quantity << ',' << cheeku.price << ',' << cheeku.total << endl;
        }
        else
        {
            destination_file << line << '\n';
        }
    }
    source_file.close();
    destination_file.close();
    source_file.open("edit.txt", std::ios::in);
    destination_file.open("data.txt", std::ios::out);
    if (source_file.is_open() && destination_file.is_open())
    {
        while (getline(source_file, line))
        {
            destination_file << line << endl;
        }
    }
    destination_file.close();
    source_file.close();
    char response;
    while (!should_exit)
    {
        cout << "Do you want to continue? (y/n): ";
        cin >> response;
        if (response == 'y' || response == 'Y')
        {
            cout << endl
                 << "Continuing..." << endl
                 << endl;
            loggin_owner();
        }
        else if (response == 'n' || response == 'N')
        {
            cout << "Exiting..." << endl;
            abort_function();
            break;
        }
        else
        {
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            cin.clear();
            cin.ignore();
        }
    }
}
void add()
{
    cout << endl
         << endl;
    vector<StockItem> stockItems;
    StockItem newItem;
    cout << "Enter ID: ";
    cin >> newItem.id;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, newItem.name);
    cout << "Enter Quantity: ";
    cin >> newItem.quantity;
    cout << "Enter Price: ";
    cin >> newItem.price;
    newItem.total = newItem.price * newItem.quantity;
    stockItems.push_back(newItem);
    ofstream stockFile("data.txt", ios::app);
    if (stockFile.is_open())
    {
        for (const auto &item : stockItems)
        {
            stockFile << item.id << ","
                      << item.name << ","
                      << item.quantity << ","
                      << item.price << "," << item.total << endl;
        }
        stockFile.close();
        cout << "Stock items saved to data.txt\n";
    }
    else
    {
        cout << "Unable to open file data.txt\n";
    }
    cout << "Stock Items:" << endl
         << endl;
    cout << "__________________________________________________________________________________________________" << endl
         << endl;
    cout << setw(6) << "  ID" << setw(30) << "Name" << setw(20) << "Quantity" << setw(20) << "Price" << setw(20) << "Total Price";
    cout << endl
         << "__________________________________________________________________________________________________" << endl
         << endl;
    cout << endl
         << endl;
    for (const auto &item : stockItems)
    {
        cout << "  " << item.id << setw(30)
             << item.name << setw(20)
             << item.quantity << setw(20)
             << item.price << setw(20)
             << item.total << "\n";
    }
    cout << endl
         << "__________________________________________________________________________________________________" << endl;
    char response;
    while (!should_exit)
    {
        cout << "Do you want to continue? (y/n): ";
        cin >> response;
        if (response == 'y' || response == 'Y')
        {
            cout << endl
                 << "Continuing..." << endl
                 << endl;
            loggin_owner();
            break;
        }
        else if (response == 'n' || response == 'N')
        {
            cout << "Exiting..." << endl;
            abort_function();
            break;
        }
        else
        {
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            cin.clear();
            cin.ignore();
        }
    }
}
void see_stock()
{
    cout << endl
         << endl;
    vector<StockItem> stockItems;
    ifstream stockFile("data.txt", ios::in);
    if (stockFile.is_open())
    {
        string line;
        while (getline(stockFile, line))
        {
            StockItem item;
            stringstream ss(line);
            string field;
            getline(ss, field, ',');
            item.id = field;
            getline(ss, item.name, ',');
            getline(ss, field, ',');
            item.quantity = stoi(field);
            getline(ss, field);
            item.price = stod(field);
            item.total = item.quantity * item.price; // added this line
            stockItems.push_back(item);
        }
        stockFile.close();
        cout << "Stock items loaded from data.txt\n";
        cout << endl
             << endl
             << "__________________________________________________________________________________________________" << endl
             << endl;
        cout << setw(6) << "  ID" << setw(30) << "Name" << setw(20) << "Quantity" << setw(20) << "Price" << setw(20) << "Total Price";
        cout << endl
             << "__________________________________________________________________________________________________" << endl
             << endl;
        cout << endl
             << endl;
        for (const auto &item : stockItems)
        {
            cout << "  " << item.id << setw(30) << item.name << setw(20) << item.quantity << setw(20) << item.price << setw(20) << item.total << endl;
        }
        cout << endl
             << "__________________________________________________________________________________________________" << endl
             << endl;
    }
    else
    {
        cout << "Unable to open file data.txt" << endl
             << endl;
    }
    char response;
    while (!should_exit)
    {
        cout << "Do you want to continue? (y/n): ";
        cin >> response;
        if (response == 'y' || response == 'Y')
        {
            cout << endl
                 << "Continuing..." << endl
                 << endl;
            loggin_owner();
        }
        else if (response == 'n' || response == 'N')
        {
            cout << "Exiting..." << endl;
            abort_function();
            break;
        }
        else
        {
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            cin.clear();
            cin.ignore();
        }
    }
}
void see_stock_emp()
{
    cout << endl
         << endl;
    vector<StockItem> stockItems;
    ifstream stockFile("data.txt", ios::in);
    if (stockFile.is_open())
    {
        string line;
        while (getline(stockFile, line))
        {
            StockItem item;
            stringstream ss(line);
            string field;
            getline(ss, field, ',');
            item.id = field;
            getline(ss, item.name, ',');
            getline(ss, field, ',');
            item.quantity = stoi(field);
            getline(ss, field);
            item.price = stod(field);
            item.total = item.quantity * item.price; // added this line
            stockItems.push_back(item);
        }
        stockFile.close();
        cout << "Stock items loaded from data.txt\n";
        cout << endl
             << endl
             << "__________________________________________________________________________________________________" << endl
             << endl;
        cout << setw(6) << "  ID" << setw(30) << "Name" << setw(20) << "Quantity" << setw(20) << "Price" << setw(20) << "Total Price";
        cout << endl
             << "__________________________________________________________________________________________________" << endl
             << endl;
        cout << endl
             << endl;
        for (const auto &item : stockItems)
        {
            cout << "  " << item.id << setw(30) << item.name << setw(20) << item.quantity << setw(20) << item.price << setw(20) << item.total << endl;
        }
        cout << endl
             << "__________________________________________________________________________________________________" << endl
             << endl;
        cout << "To edit the stock, consult the owner " << endl
             << endl;
    }
    else
    {
        cout << "Unable to open file data.txt" << endl
             << endl;
    }
    char response;
    while (!should_exit)
    {
        cout << "Do you want to continue? (y/n): ";
        cin >> response;
        if (response == 'y' || response == 'Y')
        {
            cout << endl
                 << "Continuing..." << endl
                 << endl;
            login();
        }
        else if (response == 'n' || response == 'N')
        {
            cout << "Exiting..." << endl;
            abort_function();
            break;
        }
        else
        {
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            cin.clear();
            cin.ignore();
        }
    }
}
void owner_settings()
{
    int x;
    cout << endl
         << endl
         << "Following are the choice:- " << endl
         << endl;
    cout << "1.   Change your name" << endl
         << "2.   Change the password" << endl
         << endl
         << endl;
    cout << "Enter your choice: ";
    cin >> x;
    switch (x)
    {
    case 1:
    {
        string line;
        string newLine;
        ifstream infile("owner.txt");
        ofstream outfile("temp.txt");
        int lineNumber = 1;
        cout << "Enter the new name: ";
        getline(cin, newLine);
        getline(cin, newLine);
        for (int i = 1; i <= lineNumber; i++)
        {
            getline(infile, line);
            if (i == lineNumber)
            {
                outfile << newLine << "\n";
            }
            else
            {
                outfile << line << "\n";
            }
        }
        while (getline(infile, line))
        {
            outfile << line << "\n";
        }
        infile.close();
        outfile.close();
        ifstream Infile("temp.txt");
        ofstream Outfile("owner.txt");
        string Line;
        while (getline(Infile, Line))
        {
            Outfile << Line << "\n";
        }
        Infile.close();
        Outfile.close();
        break;
    }
    case 2:
    {
        string line;
        string newLine;
        ifstream infile("owner.txt");
        ofstream outfile("temp.txt");
        int lineNumber = 2;
        cout << "Enter Your new password: ";
        getline(cin, newLine);
        getline(cin, newLine);
        for (int i = 1; i <= lineNumber; i++)
        {
            getline(infile, line);
            if (i == lineNumber)
            {
                outfile << newLine << "\n";
            }
            else
            {
                outfile << line << "\n";
            }
        }
        while (getline(infile, line))
        {
            outfile << line << "\n";
        }
        infile.close();
        outfile.close();
        ifstream Infile("temp.txt");
        ofstream Outfile("owner.txt");
        string Line;
        while (getline(Infile, Line))
        {
            Outfile << Line << "\n";
        }
        Infile.close();
        Outfile.close();
        break;
    }
    default:
    {
        while ((x < 1) or (x > 2))
        {
            cout << endl
                 << endl
                 << "!!INVALID ENTRY!!" << endl
                 << endl
                 << "What do you want:- " << endl
                 << endl
                 << endl;
            cout << "1.   Change your name" << endl
                 << "2.   Change the password" << endl
                 << endl
                 << endl;
            cout << "Enter your choice: ";
            cin >> x;
            break;
        }
    }
    }
    char response;
    while (!should_exit)
    {
        cout << "Do you want to continue? (y/n): ";
        cin >> response;
        if (response == 'y' || response == 'Y')
        {
            cout << endl
                 << "Continuing..." << endl
                 << endl;
            loggin_owner();
        }
        else if (response == 'n' || response == 'N')
        {
            cout << "Exiting..." << endl;
            abort_function();
            break;
        }
        else
        {
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            cin.clear();
            cin.ignore();
        }
    }
}
void loggin_owner()
{
    cout << endl
         << endl;
    string name, pass, word, word1;
    cout << endl
         << endl;
    cout << "***************************************" << endl
         << endl;
    cout << "Enter Your Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Your Password: ";
    cin >> pass;
    ifstream myfile("owner.txt");
    getline(myfile, word);
    getline(myfile, word1);
    if ((word == name) && (word1 == pass))
    {
        cout << endl
             << endl;
        cout << "***************************************" << endl
             << endl;
        cout << "Access Granted!";
        cout << endl
             << endl;
        cout << "***************************************" << endl
             << endl;
        int choice;
        cout << endl
             << endl
             << "Welcome " << name << "!! Its really nice to see you !!" << endl
             << endl;
        cout << endl
             << endl
             << "1.  Add" << endl
             << "2.  See Stock" << endl
             << "3.  Edit Stock Items" << endl
             << "4.  Settings" << endl
             << "5.  Terminate" << endl;
        cout << endl
             << "What would you like to do Sir: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            see_stock();
            break;
        case 3:
            editStockItemFromFile();
            break;
        case 4:
            owner_settings();
            break;
        case 5:
            char response;
            while (!should_exit)
            {
                cout << "Are you sure ??? (y/n): ";
                cin >> response;
                if (response == 'y' || response == 'Y')
                {
                    cout << "Exiting..." << endl;
                    abort_function();
                    break;
                }
                else if (response == 'n' || response == 'N')
                {

                    cout << endl
                         << "Continuing..." << endl
                         << endl;
                    loggin_owner();
                }
                else
                {
                    cout << "Invalid input. Please enter 'y' or 'n'." << endl;
                    cin.clear();
                    cin.ignore();
                }
            }
        default:
            cout << "Invalid choice" << endl
                 << endl;

            while (!should_exit)
            {
                cout << "Do you want to continue? (y/n): ";
                cin >> response;
                if (response == 'y' || response == 'Y')
                {
                    cout << endl
                         << "Continuing..." << endl
                         << endl;
                    loggin_owner();
                }
                else if (response == 'n' || response == 'N')
                {
                    cout << "Exiting..." << endl;
                    abort_function();
                    break;
                }
                else
                {
                    cout << "Invalid input. Please enter 'y' or 'n'." << endl;
                    cin.clear();
                    cin.ignore();
                }
            }
        }
    }
    else
    {
        cout << "Access Denied!" << endl;
        char response;
        while (!should_exit)
        {
            cout << "Do you want to continue? (y/n): ";
            cin >> response;
            if (response == 'y' || response == 'Y')
            {
                cout << endl
                     << "Continuing..." << endl
                     << endl;
                loggin_owner();
            }
            else if (response == 'n' || response == 'N')
            {
                cout << "Exiting..." << endl;
                abort_function();
                break;
            }
            else
            {
                cout << "Invalid input. Please enter 'y' or 'n'." << endl;
                cin.clear();
                cin.ignore();
            }
        }
    }
}
void login()
{
    char choice;
    cout << endl
         << endl;
    cout << "***************************************" << endl
         << endl;
    cout << "           WHO ARE YOU??" << endl
         << endl;
    cout << "***************************************" << endl
         << endl
         << endl;
    cout << "    1.  Manager  (Enter 'M')" << endl
         << "    2.  Employee  (Enter 'E')" << endl
         << "    2.  Terminate (Enter 'T')" << endl
         << endl
         << endl;
    cout << "***************************************" << endl
         << endl;
    cout << "Enter Your Option: ";
    cin >> choice;
    switch (choice)
    {
    case 'm':
    case 'M':
        loggin_owner();
        break;
    case 'E':
    case 'e':
        see_stock_emp();
        break;
    case 't':
    case 'T':
        abort_function();
        break;
    default:
        cout << endl
             << "Invalid option entered, please enter a valid option.";
        login();
        break;
    }
}
int main()
{
    login();
    return 0;
}