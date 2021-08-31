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

class Cab{

public:
map<string, int > availCab;
map<string, int > CabPrice;
public:
Cab();
void addCab(){
  cout<<"Available cars \n\n";
     for (auto const &pair: CabPrice) {
        std::cout << ":-" << pair.first<< " , "<<pair.second<<"\n";
    }
    cout<<"\n\n";
    tryagain:
    cout<<"select 1 for adding a new Cab or select 0 for update  no. of existing car?\n";
    int s;
    cin>>s;
    if(s==1){
      cout<<"Enter Car name\n";
      string carname;
       getchar();
      getline(cin, carname);
      cout<<"Enter Number of cars you want to add\n";
    int qw;
    cin>>qw;
    cout<<"Enter price of car\n";
    int price;
    cin>>price;
     availCab.insert(pair<string, int>(carname, qw));
      CabPrice.insert(pair<string, int>(carname, price));
      cout<<"\n\nPrice of cabs\n\n";
        for (auto const &pair: CabPrice) {
        std::cout << ":-" << pair.first<< " , "<<pair.second<<"\n";
    }
     cout<<"\n\nNumber of cabs\n\n";
      for (auto const &pair: availCab) {
        std::cout << ":-" << pair.first<< " , "<<pair.second<<"\n";
    }
    }
    else if(s==0){
      cout<<"Enter name of car you want to update no. of cars\n";
      string st="";
      getchar();
      getline(cin, st);
      cout<<"Enter number of cars you want to add\n";
      int gq;
      cin>>gq;
      std::map<string, int>::iterator it = availCab.find(st); 
if (it != availCab.end())
    it->second += gq;
    cout<<"\n\n";

       for (auto const &pair: CabPrice) {
        std::cout << ":-" << pair.first<< " , "<<pair.second<<"\n";
    }
    }
    else{
      cout<<"please Enter valid input\n";
        goto tryagain;
    }
   
    
}
// void removeCab(){

// }
// void changeRate(){

// }
// void availCab(){

// }

};
Cab::Cab(){
   availCab.insert(pair<string, int>("Nano", 10));
    availCab.insert(pair<string, int>("thar", 3));
    availCab.insert(pair<string, int>("creta", 4));
    availCab.insert(pair<string, int>("verna", 5));
    availCab.insert(pair<string, int>("supra", 1));
    CabPrice.insert(pair<string, int>("Nano", 1000));
     CabPrice.insert(pair<string, int>("thar", 5000));
     CabPrice.insert(pair<string, int>("creta", 4500));
     CabPrice.insert(pair<string, int>("verna", 3000));
     CabPrice.insert(pair<string, int>("supra", 45000));
}

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
