#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string name;
        string school;
        cin >> name >> school;

        if(name[0] == 'W' && name[1] == 'a')
            cout << name << " the " << school << " Waninoko" << endl;
        else if(name[0] == 'M' && name[1] == 'i')
            cout << name << " the " << school << " Milotic" << endl;
        else if(name[0] == 'M' && name[1] == 'a')
            cout << name << " the " << school << " Magikarp" << endl;
        else if(name[0] == 'V' && name[1] == 'a')
            cout << name << " the " << school << " Vaporeon" << endl;
        else if(name[0] == 'S' && name[1] == 'h')
            cout << name << " the " << school << " Sharpedo" << endl;
        else if(name[0] == 'T' && name[1] == 'a' && name[2] == 'p' && name[3] == 'u')
            cout << name << " the " << school << " Tapu Fini" << endl;
        else if(name[0] == 'E' && name[1] == 'm')
            cout << name << " the " << school << " Empoleon" << endl;
        else if(name[0] == 'L' && name[1] == 'a')
            cout << name << " the " << school << " Lapras" << endl;
        else if(name[0] == 'P' && (name[1] == 'i' || name[1] == 'e'))
            cout << name << " the " << school << " Pikachu" << endl;
        else if(name[0] == 'M' && name[1] == 'e')
            cout << name << " the " << school << " Mega Gyarados" << endl;
        else
            cout << name << " is looking for a Chinese tutor, too!" << endl;
    }
}
