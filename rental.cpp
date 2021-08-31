#include <bits/stdc++.h>
using namespace std;

class login
{
    map<string, string> oweners;
    map<string, string> customers;

public:
    login()
    {
        oweners["Sanat Thakur"] = "1234";
        oweners["Anmol Choudhary"] = "1234";
        customers["helo"] = "00";
        customers["helo1"] = "11";
    }

    bool search_oweners(string o_name, string o_pass)
    {
        bool o_found = false;
        auto it = oweners.find(o_name);
        if (it != oweners.end())
        {
            if (it->second == o_pass)
            {
                cout << "Successfully Login\n";
                o_found = true;
            }
            else
            {
                cout << "Password is incorrect\n";
            }
        }
        else
        {
            cout << "Owener not found\n";
        }
        return o_found;
    }

    bool search_customers(string c_name, string c_pass)
    {
        bool c_found = false;
        auto it = customers.find(c_name);
        if (it != customers.end())
        {
            if (it->second == c_pass)
            {
                cout << "Successfully Login\n";
                c_found = true;
            }
            else
            {
                cout << "Password is incorrect\n";
            }
        }
        else
        {
            cout << "Customer not found\n";
        }
        return c_found;
    }

    void register_customer()
    {
        string reg_cust_name, reg_cust_pass;
        cout << "Enter Your Name and password\n";
        getchar();
        getline(cin, reg_cust_name);
        getline(cin, reg_cust_pass);
        customers.insert({reg_cust_name, reg_cust_pass});
        cout << "Successfully Registered\n";
    }
};

int main()
{
    login l;
    char person_type;
    char l_or_r;
    string c_name, c_pass;
    string o_name, o_pass;
    bool owener_logged_in = false, customer_logged_in = false;

    while (true)
    {
        cout << "Welcome to Rental Service Please login!!!\n"
             << "Are you Owener or Customer(o/c)? or to exit(e)\n";
        cin >> person_type;

        if (person_type == 'o')
        {
            cout << "Enter Your name and password\n";
            getchar();
            getline(cin, o_name);
            getline(cin, o_pass);

            bool is_valid_owener = l.search_oweners(o_name, o_pass);
            if (is_valid_owener)
            {
                cout << "Owener Welcome to Rental Services\n";
                owener_logged_in = true;
            }
        }
        else if (person_type == 'c')
        {
            cout << "Login or Register(l/r)?\n";
            cin >> l_or_r;

            if (l_or_r == 'l')
            {
                cout << "Enter Your name and password\n";
                getchar();
                getline(cin, c_name);
                getline(cin, c_pass);

                bool is_valid_customer = l.search_customers(c_name, c_pass);
                if (is_valid_customer)
                {
                    cout << "Customer Welcome to Rental Services\n";
                    customer_logged_in = true;
                }
                else
                {
                    char want_reg;
                    cout << "Want to Register(y/n)?\n";
                    cin >> want_reg;

                    if (want_reg == 'y')
                    {
                        l.register_customer();
                    }
                    else if (want_reg == 'n')
                    {
                        cout << "Ok...\n";
                    }
                    else
                    {
                        cout << "Invalid Input\n";
                    }
                }
            }
            else if (l_or_r == 'r')
            {
                l.register_customer();
            }
            else
            {
                cout << "Invalid Input\n";
            }
        }
        else if (person_type == 'e')
        {
            break;
        }
        else
        {
            cout << "Invalid Input\n";
        }

        if (owener_logged_in)
        {
        }
        else if (customer_logged_in)
        {
        }
    }
    return 0;
}
