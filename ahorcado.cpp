#include <iostream>
#include <string>
using namespace std;

int main() {
    string palabra;
    string adivinadas;
    int errores = 0;
    char letra;
    bool completa;
    
    cout << "Ingrese la palabra secreta: ";
    cin >> palabra;
    
    for (int i = 0; i < palabra.length(); i++) {
        adivinadas += '_';
    }
    
    cout << "\nComienza el juego!\n";
    
    while (errores < 6) {
        cout << "\" ";
        for (int i = 0; i < palabra.length(); i++) {
            cout << adivinadas[i] << " ";
        }
        cout << "\"\n";
        
        completa = true;
        for (int i = 0; i < palabra.length(); i++) {
            if (adivinadas[i] == '_') {
                completa = false;
                break;
            }
        }
        if (completa) break;
        
        cout << "Ingrese letra: ";
        cin >> letra;
        
        bool encontrada = false;
        for (int i = 0; i < palabra.length(); i++) {
            if (palabra[i] == letra) {
                adivinadas[i] = letra;
                encontrada = true;
            }
        }
        
        if (!encontrada) {
            errores++;
            cout << "Pierde \"";
            switch (errores) {
                case 1: cout << "pierna derecha"; break;
                case 2: cout << "pierna izquierda"; break;
                case 3: cout << "brazo derecho"; break;
                case 4: cout << "brazo izquierdo"; break;
                case 5: cout << "tronco"; break;
                case 6: cout << "cabeza"; break;
            }
            cout << "\"\n";
        }
    }
    
    cout << "\" ";
    for (int i = 0; i < palabra.length(); i++) {
        cout << adivinadas[i] << " ";
    }
    cout << "\"\n";
    
    if (errores >= 6) {
        cout << "\nHas perdido el juego!\n";
        cout << "La palabra era: " << palabra << endl;
    } else {
        cout << "\n Has ganado!\n";
    }
    
    return 0;
}