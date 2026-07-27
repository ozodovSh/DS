#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int bazani_aniqlash(int tanlov) {
    switch (tanlov) {
        case 1: return 2;   
        case 2: return 8;   
        case 3: return 10;  
        case 4: return 16;  
        default: return 0;
    }
}


void sanoq_tizimini_ozgartir(const string& son_str, int boshlangich_baza, int yakuniy_baza) {
    int onlik_son = stoi(son_str, nullptr, boshlangich_baza);

    if (onlik_son == 0) {
        cout << "Natija: 0" << endl;
        return;
    }

    if (yakuniy_baza == 10) {
        cout << "Natija: " << onlik_son << endl;
        return;
    }

    string natija = "";
    string belgilar = "0123456789ABCDEF";
    int temp = onlik_son;

    while (temp > 0) {
        natija += belgilar[temp % yakuniy_baza];
        temp /= yakuniy_baza;
    }

    reverse(natija.begin(), natija.end());
    cout << "Natija: " << natija << endl;
}

int main() {
    string son_str;
    int tanlov1, tanlov2;

    cout << "Sonni kiriting: ";
    cin >> son_str;

    cout << "Bu son qaysi sanoq sistemasida?\n";
    cout << "1. binary\n2. 8 lik\n3. 10 lik\n4. 16 lik\n";
    cin >> tanlov1;

    cout << "Qaysi sanoq sistemasiga otkazmoqchisiz?\n";
    cout << "1. binary\n2. 8 lik\n3. 10 lik\n4. 16 lik\n";
    cin >> tanlov2;

    int bosh_baza = bazani_aniqlash(tanlov1);
    int yakun_baza = bazani_aniqlash(tanlov2);

    if (bosh_baza == 0 || yakun_baza == 0) {
        cout << "Xato: Notogri raqam tanlandi!" << endl;
        return 1;
    }

    sanoq_tizimini_ozgartir(son_str, bosh_baza, yakun_baza);

    return 0;
}