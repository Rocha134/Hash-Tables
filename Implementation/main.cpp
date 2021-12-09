//Francisco Rocha Juarez A01730560
//Iker Guerrero Gonzalez A00830026
//Aldo Mauricio Cruz Lozada A01732372

#include <iostream>
#include <vector>

using namespace std;

struct Coche {
    string placa;
    string marca;
    string modelo;
    int anio;

    bool empty = true;
    bool chain = false;
};

vector<Coche> table;

int HASH(string placa){
    int total = 0;
    for (int i = 0; i < 7; i++){
        total += (int)placa[i];
    }
    return total % 97;
}

//Complejidad O(1)
void ins(){
    string placa;
    string marca;
    string modelo;
    int anio;

    cin >> placa;
    cin >> marca;
    cin >> modelo;
    cin >> anio;

    int hashed = HASH(placa);

    if (!table[hashed].empty){
        int i = 1;
        bool poder = true;

        if (table[hashed].placa == placa){
            cout << "imposible insertar, placa duplicada" << endl;
            poder = false;
        }
         //Complejidad O(n)
        while (!table[(hashed + i) % 97].empty){
            if ((hashed + i) % 97 == hashed){
                cout << "tabla llena, imposible insertar" << endl;
                poder = false;
                break;
            }
            if (table[hashed].placa == placa){
                cout << "imposible insertar, placa duplicada" << endl;
                poder = false;
                break;
            }
            i++;
        }

        if (poder){
            table[(hashed + i) % 97].placa = placa;
            table[(hashed + i) % 97].marca = marca;
            table[(hashed + i) % 97].modelo = modelo;
            table[(hashed + i) % 97].anio = anio;
            table[(hashed + i) % 97].empty = false;
            table[(hashed + i) % 97].chain = true;
            table[((hashed + i) % 97)-1].chain = true;
        }
    }
    else{
        table[hashed].placa = placa;
        table[hashed].marca = marca;
        table[hashed].modelo = modelo;
        table[hashed].anio = anio;
        table[hashed].empty = false;
    }
    cout << endl;
}
 //Complejidad O(1)
void del(){
    string placa;
    cin >> placa;
    int hashed = HASH(placa);

    if (!table[hashed].empty || table[hashed].chain){
        int i = 1;
        bool poder = false;

        if (table[hashed].placa == placa){
            table[hashed].empty = true;
            table[hashed].placa = "";
            table[hashed].marca = "";
            table[hashed].modelo = "";
            table[hashed].anio = 0;
        }
        else{
            while (!table[(hashed + i) % 97].empty || table[(hashed + i) % 97].chain){
                if ((hashed + i) % 97 == hashed){
                    poder = false;
                    break;
                }
                else if (table[(hashed + i) % 97].placa == placa){
                    poder = true;
                    break;
                }
                i++;
            }

            if (poder){
                table[(hashed + i) % 97].empty = true;
                table[(hashed + i) % 97].placa = "";
                table[(hashed + i) % 97].marca = "";
                table[(hashed + i) % 97].modelo = "";
                table[(hashed + i) % 97].anio = 0;
            }
        }
    }

    cout << endl;
}

//Complejidad O(1)
void search(){
    string placa;
    cin >> placa;
    int hashed = HASH(placa);
    bool encontrado = false;

    if (!table[hashed].empty || table[hashed].chain){
        int i = 1;

        if (table[hashed].placa == placa){
            cout << table[hashed].placa << " " << table[hashed].marca << " " << table[hashed].modelo << " " << table[hashed].anio << endl;
            encontrado = true;
        }
        else{
            while (!table[(hashed + i) % 97].empty || table[(hashed + i) % 97].chain){
                if (table[(hashed + i) % 97].placa == placa){
                    cout << table[(hashed + i) % 97].placa << " " << table[(hashed + i) % 97].marca << " " << table[(hashed + i) % 97].modelo << " " << table[(hashed + i) % 97].anio << endl;
                    encontrado = true;
                    break;
                }
                i++;
            }
        }
    }
    if (!encontrado){
        cout << "dato no encontrado" << endl;
    }
    cout << endl;
}

void print(){
    for (int i = 0; i < 97; i++){
        cout << i;
        if (!table[i].empty){
            cout << " " << table[i].placa << " " << table[i].marca << " " << table[i].modelo << " " << table[i].anio << endl;
        }
        else{
            cout << endl;
        }
    }
    cout << endl;
}

int main(){
    table.resize(97);
    int decision = 10;

    while (decision != 0){
        cin >> decision;
        if (decision == 1){
            ins();
        }
        else if (decision == 2){
            del();
        }
        else if (decision == 3){
            print();
        }
        else if (decision == 4){
            search();
        }
    }
}
