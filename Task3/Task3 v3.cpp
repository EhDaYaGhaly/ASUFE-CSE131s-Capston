/*      Computer Progamming [CSE 131s]    */
/*                Task_3                  */
/*  Name: Ahmed Hussein AbdelKarim Raslan */
/*            ID: 2100714                 */
/*            Section: 7                  */
/*             Spring 2023                */
/*----------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

// functions declaration

double ser(string txt);
double para(string txt);
bool valid(string txt);

int main()
{

    string circuit;
    double resistance, voltage, current;
    cout << "Circuit description: ";
    getline(cin, circuit);
    cout << "Voltage applied: ";
    cin >> voltage;
    if (!valid(circuit))
    {
        cout << "Wrong Circuit Description" << endl;
        exit(0);
    }
    if (circuit[0] == 'S')
    {
        resistance = ser(circuit);
    }
    else if (circuit[0] == 'P')
    {
        resistance = para(circuit);
    }
    current = voltage / resistance;
    cout << "Total Resistance: " << resistance << endl;
    cout << "Current Intensity: " << current;
}
double ser(string txt)
{
    double ser_sum = 0;
    txt = txt.substr(2);
    string aux;
    int index;
    while (txt.find('e') != string::npos)
    {
        for (int i = txt.find('e'); i > 0; i--)
        {
            if (txt[i] == 'S')
            {
                index = i;
                aux = txt.substr(index, txt.find('e') - index + 1);
                txt.replace(txt.find(aux), aux.size(), to_string(ser(aux)));
            }
            else if (txt[i] == 'P')
            {
                index = i;
                aux = txt.substr(index, txt.find('e') - index + 1);
                txt.replace(txt.find(aux), aux.size(), to_string(para(aux)));
            }
        }
    }
    while (isdigit(txt[0]))
    {
        ser_sum += stod(txt);
        txt = txt.substr(txt.find(" ") + 1);
    }
    return ser_sum;
}

double para(string txt)
{
    double para_sum = 0;
    double rec = 0;
    txt = txt.substr(2);
    string aux;
    int index;

    while (txt.find('e') != string::npos)
    {
        for (int i = txt.find('e'); i > 0; i--)
        {
            if (txt[i] == 'S')
            {
                index = i;
                aux = txt.substr(index, txt.find('e') - index + 1);
                txt.replace(txt.find(aux), aux.size(), to_string(ser(aux)));
            }
            else if (txt[i] == 'P')
            {
                index = i;
                aux = txt.substr(index, txt.find('e') - index + 1);
                txt.replace(txt.find(aux), aux.size(), to_string(para(aux)));
            }
        }
    }

    while (isdigit(txt[0]))
    {
        rec += (1.0 / stod(txt));
        txt = txt.substr(txt.find(" ") + 1);
    }
    para_sum = 1.0 / rec;
    return para_sum;
}
bool valid(string txt)
{
    for (int i = 0; i < txt.size(); i++)
    {
        if ((isalpha(txt[i])) && ((txt[i] != 'P') || (txt[i] != 'S')))
            return false;
    }
    return true;
}
