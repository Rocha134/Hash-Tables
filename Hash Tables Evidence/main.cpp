//Francisco Rocha Juarez A01730560
//Iker Guerrero Gonzalez A00830026
//Aldo Mauricio Cruz Lozada A01732372

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <math.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

ifstream in("bitacora.txt");
vector<string> registros;


struct Direccion {
    string dominio;
    int accesos;
    int conexiones;
    bool empty = true;

    vector<string> ips;
};

vector<Direccion> table;

int HASH(string key){
    int total = 0;
    for (int i = 0; i < key.length(); i++){
        total += (int)key[i];
    }
    return total % 32749;
}

//O(n)
int IpCleaner(string og){
    int total = 0;
    for (int i = 0; i < og.length(); i++){
        total += (int)(og[i] - '0') * (pow(10, og.length()-i-1));
    }
    return total;
}

//O(n log n)
void SortIps(int num){
    string imax1;
    string imax2;
    string imax3;
    string jmax1;
    string jmax2;
    string jmax3;
    for (int i = 0; i < table[num].ips.size(); i++){
        for (int j = 0; j < table[num].ips.size(); j++){

            stringstream itemp(table[num].ips[i]);
            getline(itemp, imax1, '.');

            getline(itemp, imax1, '.');

            getline(itemp, imax1, '.');

            getline(itemp, imax2, ':');

            getline(itemp, imax3);


            stringstream jtemp(table[num].ips[j]);

            getline(jtemp, jmax1, '.');

            getline(jtemp, jmax1, '.');

            getline(jtemp, jmax1, '.');

            getline(jtemp, jmax2, ':');

            getline(jtemp, jmax3);

            if (IpCleaner(imax1) < IpCleaner(jmax1)){
                string now = table[num].ips[i];
                table[num].ips[i] = table[num].ips[j];
                table[num].ips[j] = now;
            }
            else if (IpCleaner(imax1) == IpCleaner(jmax1)){
                if (IpCleaner(imax2) < IpCleaner(jmax2)){
                    string now = table[num].ips[i];
                    table[num].ips[i] = table[num].ips[j];
                    table[num].ips[j] = now;
                }
                else if (IpCleaner(imax2) == IpCleaner(jmax2)){
                    if (IpCleaner(imax3) < IpCleaner(jmax3)){
                        string now = table[num].ips[i];
                        table[num].ips[i] = table[num].ips[j];
                        table[num].ips[j] = now;
                    }
                }
            }
        }
    }
}

//O(n)
void ReadFile(){
    string linea;

    //Inicializamos un contador un 0 para contar las líneas de nuestro documento bitacora.txt
    int counter = 0;
    while(getline(in,linea)){
        registros.push_back(linea);
        counter++;
    }

    string palabra;
    for (int i = 0; i < registros.size(); i++){
        stringstream temp(registros[i]);

        getline(temp, palabra, ' ');

        getline(temp, palabra, ' ');

        getline(temp, palabra, ':');

        getline(temp, palabra, ':');

        getline(temp, palabra, ' ');

        getline(temp, palabra, '.');
        string ahora = to_string(IpCleaner(palabra));

        getline(temp, palabra, '.');
        string ahora2 = to_string(IpCleaner(palabra));

        getline(temp, palabra, ' ');
        string tip = palabra;

        string combo = ahora + "." + ahora2;


        int hashed = HASH(combo);

        if (!table[hashed].empty){
            if (table[hashed].dominio == combo){
                table[hashed].accesos++;
                bool c = true;
                for (int a = 0; a < table[hashed].ips.size(); a++){
                    if (table[hashed].ips[a] == tip){
                        c = false;
                    }
                }
                if (c){
                    table[hashed].ips.push_back(combo + "." + tip);
                    table[hashed].conexiones++;
                    SortIps(hashed);
                }
            }
            else {
                int y = 1;
                while (!table[(hashed + y) % 32749].empty){
                    if ((hashed + y) % 32749 == hashed){
                        cout << "Tabla llena, imposible meter más datos" << endl;
                        break;
                    }
                    if (table[(hashed + y) % 32749].dominio == combo){
                        table[hashed + y].accesos++;
                        bool c = true;
                        for (int z = 0; z < table[(hashed + y) % 32749].ips.size(); z++){
                            if (table[(hashed + y) % 32749].ips[z] == tip){
                                c = false;
                            }
                        }
                        if (c){
                            table[(hashed + y) % 32749].ips.push_back(combo + "." + tip);
                            table[(hashed + y) % 32749].conexiones++;
                            SortIps((hashed + y) % 32749);
                            break;
                        }
                    }
                    y++;
                }
                if (table[(hashed + y) % 32749].empty){
                    table[(hashed + y) % 32749].dominio = combo;
                    table[(hashed + y) % 32749].accesos = 1;
                    table[(hashed + y) % 32749].conexiones = 1;
                    table[(hashed + y) % 32749].empty = false;

                    table[(hashed + y) % 32749].ips.push_back(combo + "." + tip);
                }
            }
        }
        else{
            table[hashed].dominio = combo;
            table[hashed].accesos = 1;
            table[hashed].conexiones = 1;
            table[hashed].empty = false;

            table[hashed].ips.push_back(combo + "." + tip);
        }
    }
}

//O(1)
void search(){
    string dom;
    cin >> dom;
    string d1;
    string d2;
    stringstream temp(dom);

    getline(temp, d1, '.');
    getline(temp, d2);

    dom = to_string(IpCleaner(d1)) + "." + to_string(IpCleaner(d2));

    int hashed = HASH(dom);
    bool encontrado = false;

    int i = 0;

    if (!table[hashed].empty){

        if (table[hashed].dominio == dom){

            encontrado = true;
        }
        else{
            while (!table[(hashed + i) % 32749].empty){
                if (table[(hashed + i) % 32749].dominio == dom){
                    encontrado = true;
                    break;
                }
                i++;
            }
        }
    }
    if (encontrado){
        cout << table[(hashed + i) % 32749].dominio << endl;
        cout << table[(hashed + i) % 32749].accesos << endl;
        cout << table[(hashed + i) % 32749].conexiones << endl;
        for (int x = 0; x < table[(hashed + i) % 32749].ips.size(); x++){
            cout << table[(hashed + i) % 32749].ips[x] << endl;
        }
    }
    else{
        cout << "dato no encontrado" << endl;
    }
    cout << endl;
}


int main(){
    table.resize(32749);

    ReadFile();

    int num;
    cin >> num;

    for (int i = 0; i < num; i++){
        search();
    }
    return 0;
}
