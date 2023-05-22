#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <list>
#include <vector> //qt 
using namespace std;
class member
{
private:
public:
    string Category;
    string Name;
    bool Is_favorite;
    string Number;
    member(string cat, string name, string number, bool is_fav)
    {
        this->Category = cat;
        this->Name = name;
        this->Number = number;
        this->Is_favorite = is_fav;
    }
    member(string cat, string name, string number)
    {
        this->Category = cat;
        this->Name = name;
        this->Number = number;
        this->Is_favorite = false; // this constructor don't input is_favorite
    }
    member()
    {
        this->Category = "NONE";
        this->Name = "NONE";
        this->Number = "NONE";
        this->Is_favorite = false;
    }
    void set_cat(string cat)
    {
        this->Category = cat;
    }
    void set_name(string name)
    {
        this->Name = name;
    }
    void set_number(string number)
    {
        this->Number = number;
    }
    void Display()
    {
        cout << '{' << this->Category << " - " << this->Name << " - " << this->Number << '}' << endl;
    }
};
int main()
{
    map<string, member> contact;
    member ali("WORK", "ALI_AHMADI", "0912331221", false);
    member jack("HOME", "JACK_GRY", "0919831221", false);
    member tony("FREIND", "Tony_Kross", "0912312212"); // by default the member is not favorite i implemnetd two constructor to make it easier
    member carlo("FREIND", "carlo_mei", "0932332292", true);
    member alireza("FREIND", "alireza_nobakht", "0998754312", true);

    contact.insert(pair<string, member>("CARLO", carlo));
    contact.insert(pair<string, member>("ALI", ali));
    contact.insert(pair<string, member>("GRY", jack));
    contact.insert(pair<string, member>("TONY", tony));
    contact.insert(pair<string, member>("ALIREZA", alireza));

    int fav_counter = 1;
    map<int, member> favorite;
    for (auto mem : contact)
    {

        if (mem.second.Is_favorite == true)
        {
            favorite.insert(pair<int, member>(fav_counter, mem.second));
            fav_counter++;
        }
    }

    int command;
    cout << " <---------hello and welcome to my contact manager ---------> " << endl;
    cout << "0 -> help guide" << endl;
    cout << "1 -> to add new contact" << endl;
    cout << "2 -> to reomve contact with input name " << endl;
    cout << "3 -> Display all contatcs in alphabetic order" << endl;
    cout << "6 -> Edit contact with given name and I change the all member info" << endl;
    cout << "7-> add new member to your favorite list" << endl;
    cout << "8-> remove member from your favorite list" << endl;
    cout << "9 -> search contact via name" << endl;
    cout << "10 -> Display your favorite list" << endl;
    cout << "11 -> to Edit key value" << endl;
    cout << "12 -> to change fav list order" << endl;
    cout << "-1 -> FINISH" << endl;

    while (command != -1)
    {
        cout << "command -> ";
        cin >> command;
        if (command == 1)
        {
            string key_name, full_name, cat, number;
            cout << "please give me the name, Category, full name,number: ";
            cin >> key_name >> cat >> full_name >> number;

            member temp(cat, full_name, number);
            contact.insert(pair<string, member>(key_name, temp));
        }
        else if (command == 2)
        {
            string wanted_key_name;
            cout << "give me the key_name to remove: ";
            cin >> wanted_key_name;
            contact.erase(wanted_key_name);
        }
        else if (command == 3)
        {
            for (auto mem : contact)
            {
                cout << mem.first << "--> ";
                mem.second.Display();
            }
        }
        else if (command == 6)
        {
            string given_key_name, new_cat, new_full_name, new_number;
            cout << "please give me your key_name you want to edit the info: ";
            cin >> given_key_name;
            for (auto mem : contact)
            {
                if (mem.first == given_key_name)
                {
                    cout << "now please give me your new category,full_name and number to change: ";
                    cin >> new_cat >> new_full_name >> new_number;
                    contact[mem.first] = member(new_cat, new_full_name, new_number);
                    cout << "Successfuly changed";
                }
            }
        }
        else if (command == 7)
        {
            string given_key_name;
            cout << "Who do you want to add give me the key name: ";
            cin >> given_key_name;
            for (auto mem : contact)
            {
                if (mem.first == given_key_name)
                {
                    favorite[fav_counter] = member(mem.second.Category, mem.second.Name, mem.second.Number, true);
                }
            }
        }
        else if (command == 8)
        {
            string give_key_name;
            cout << "Give me the name that you want to remove it from favoirte list: ";
            cin >> give_key_name;
            for (auto mem : contact)
            {
                if (mem.first == give_key_name)
                {
                    contact[mem.first] = member(mem.second.Category, mem.second.Name, mem.second.Number, false);
                }
            }
        }
        else if (command == 9)
        {
            string search_key;
            list<member> search_id;
            bool is_found = false;
            cout << "Search... ";
            cin >> search_key;
            for (auto mem : contact)
            {
                is_found = mem.first.find(search_key);
                if (is_found == false)
                {
                    search_id.push_back(mem.second);
                }
            }
            for (auto x : search_id)
            {
                x.Display();
            }
        }

        else if (command == 10) // display favoirte list
        {
            for (auto mem : favorite)
            {
                cout << mem.first << "--> ";
                mem.second.Display();
            }
        }
        else if (command == 11)
        {
            string given_key_name;
            cout << "Please give me your key_name: ";
            cin >> given_key_name;
            for (auto mem : contact)
            {
                if (mem.first == given_key_name)
                {
                    string new_key_name;
                    cout << "now give me your new key_name: ";
                    cin >> new_key_name;
                    string last_cat, last_Name, last_number;
                    last_cat = mem.second.Category;
                    last_Name = mem.second.Name;
                    last_number = mem.second.Number;
                    contact.erase(given_key_name);
                    member temp(last_cat, last_Name, last_number, false);
                    contact.insert(pair<string, member>(new_key_name, temp));
                }
            }
        }
        else if (command == 12)
        {
            string given_fav_key;
            cout << "please give me your first fav key_name: ";
            cin >> given_fav_key;
            for (auto mem : favorite)
            {
                member first_temp;
                for (auto x : favorite)
                {
                    if (x.first == 1)
                    {
                        first_temp = x.second;
                        break;
                    }
                }
                if (mem.second.Name == given_fav_key)
                {
                    favorite.erase(1);
                    favorite.insert(pair<int, member>(1, mem.second));
                    favorite.insert(pair<int, member>(fav_counter + 1, first_temp));
                }
            }
        }
        else if (command == 0)
        {
            cout << "0 -> help guide" << endl;
            cout << "1 -> to add new contact" << endl;
            cout << "2 -> to reomve contact with input name " << endl;
            cout << "3 -> Display all contatcs in alphabetic order" << endl;
            cout << "6 -> Edit contact with given name and I change the all member info" << endl;
            cout << "7-> add new member to your favorite list" << endl;
            cout << "8-> remove member from your favorite list" << endl;
            cout << "9 -> search contact via name" << endl;
            cout << "10 -> Display your favorite list" << endl;
            cout << "11 -> to Edit key value" << endl;
            cout << "12 -> to change fav list order" << endl;
            cout << "-1 -> FINISH" << endl;
        }
    }
    return 0;
}
