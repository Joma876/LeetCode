#include <iostream>
#include <algorithm>
#include <ctime>
#include <array>

using namespace std;

#define Squared(x) (x * x)

void Square() {
    cout << Squared(5); 
}



void Arrays_2() {
    array<int, 100> arr;
    srand(time(NULL));
    for (int x = 0; x < arr.size(); x++) {
        arr[x] = rand();
    }

    sort(arr.begin(), arr.end());

    for (int x = 0; x < arr.size(); x++) {
        cout << x + 1 << "\t : \t" << arr[x] << endl;
    }

    cout << "Kleinste Zahl: " << arr[0]  << "Position: 0" << endl;
    cout << "Gr" << (char)148 << (char)225 << "te Zahl: " << arr[arr.size() - 1] << "Position:" << arr.size();

}


void Arrays_3() {
    unique_ptr<array<int, 10000>> RandomArray = make_unique<array<int, 10000>>(); 
    //array<int, 10000> RandomArray; 
    array<int, 10> FrequencyArray = {};
    srand(time(NULL));

    for (int x = 0; x < RandomArray->size(); x++) {
        (*RandomArray)[x] = rand() % 10 + 1;
        FrequencyArray[(*RandomArray)[x] - 1]++;
    }

    for (int x = 0; x < FrequencyArray.size(); x++) {
        cout << x + 1 << "\t : \t" << FrequencyArray[x] << endl;
    }

}

//Heap Algorithm
class Repetitions {

    int Reps;
    int UserInput;
    int Position = 1;
    array<int, 8> OutputArray;

private:

    void setArray();
    void PrintArray();
    bool isValid();
    void swap(const int& x1, const int& x2);

public:

    void setRepetitions();
    void Permutation(int Position = 1);
};


int main() {
    Repetitions rep;
    rep.setRepetitions();

    rep.Permutation();

}

void Repetitions::setRepetitions() {
    cout << "Set the number of repetitions, at least 1, not bigger than 8: ";
    cin >> UserInput;
    cout << endl;
    if (isValid()) {
        setArray();
        Permutation(UserInput);
    }
    else setRepetitions();

}

bool Repetitions::isValid() {
    if (UserInput > 0) {
        return UserInput < 9;
    }
    return false;

}

void Repetitions::setArray() {
    for (int x = 0; x < UserInput; x++) {
        OutputArray[x] = (x + 1);
    }
}

void Repetitions::PrintArray() {
    for (int x = 0; x < UserInput; x++) {
        cout << OutputArray[x] << " ";
    }
    cout << endl;
}

void Repetitions::swap(const int& x1, const int& x2) {
    int TempVal = OutputArray[x2];
    OutputArray[x2] = OutputArray[x1];
    OutputArray[x1] = TempVal;
}

void Repetitions::Permutation(int position) {

    if (position == 1) {
        PrintArray();
        return;
    }

    Permutation(position - 1);

    for (int i = 0; i < position - 1; i++) {
        if (position % 2 == 0) swap(i, position - 1);
        else swap(0, position - 1);

        Permutation(position - 1);
    }
}


class TankPreise {

    array<array<float, 3>, 3> List;
    char value;
    int Type;
    float Price;
    float Quantity;

private:

    void SetType();
    void Print();

public:
    TankPreise();
    void Run();

};

TankPreise::TankPreise() {
    for (int x = 0; x < List.size(); x++) {
        for (int y = 0; y < List[x].size(); y++) {
            List[x][y] = 0;
        }
    }
}

void TankPreise::Run() {
    while (true) {
        cout << "Geben sie die Kraftstoffart an: ";
        cin >> value;
        try {
            SetType();
            if (Type == 3) break;
            if (List[Type].size() < 50) {
                cout << endl;
                cout << "Geben sie die Menge und den Kaufpreis an: ";
                cin >> Quantity;
                List[Type][0] += Quantity;
                cout << "\t";
                cin >> Price;
                List[Type][1] += Price;
                List[Type][2]++;
            }
            else cout << "Die Liste für diesen Kraftstofftyp ist voll" << endl;
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }
    Print();
}

void TankPreise::SetType() {
    switch (value) {
    case 'N':
        Type = 0;
        break;
    case 'S':
        Type = 1;
        break;
    case 'D':
        Type = 2;
        break;
    case 'X':
        Type = 3;
        break;
    default:
        throw runtime_error("Bitte nur N, S oder D eingeben, oder X zum beenden");
    }
}

void TankPreise::Print() {
    cout << " \t Summe Liter \t Summe Kaufpreis      Durschnitts Preis" << endl;
    for (int Type = 0; Type < List.size(); Type++) {

        if (Type == 0) cout << "Normal";
        else if (Type == 1) cout << "Super";
        else cout << "Diesel";

        if (List[Type][1] != 0) {
            int Temp = List[Type][2];
            List[Type][2] = List[Type][1] * Temp;
            ~Temp;
            List[Type][1] = List[Type][0] * List[Type][2];

        }
        for (int y = 0; y < List[Type].size(); y++) {
            if (y == 0) cout << "\t\t" << List[Type][y] << "l";
            else cout << "\t\t" << List[Type][y];
        }
        cout << endl;
    }
}

void array() {
    int a[3][5];

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 5; y++) {
            a[x][y] = (x * 10) + 10 + y + 1;
        }
    }

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 5; y++) {
            cout << a[x][y] << "->";
            //cout << *(a[x] + y) << "->";			//Pointer zur Array position + y
            //cout << (*(a + x))[y] << "->";		//Pointer zur Array position x --> Derferenced an position y
            //cout << *((*(a + x)) + y) << "->";	//Pointer zur Array position x --> Derferenced pointer zur position y
            cout << *(&a[0][0] + 5 * x + y);		//a pointer ab dem ersten element --> x*5 itteration des Mainarrays | y iteration der subarrays
            cout << "\t";
        }
        cout << endl;
    }
}