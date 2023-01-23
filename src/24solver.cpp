#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

char op[4] = {'+','-','*','/'};
ofstream out_file("../test/Hasil.txt");

void permutasi(vector<float> kartu, vector<vector<float> >& perm, int ctr1, int ctr2)
{
	if (ctr1 == ctr2) {
        bool found = false;
        int i = 0;

        while(!found && i < perm.size()){ //pengecekan duplikasi
             if(kartu == perm.at(i)){
                 found = true;
             }
		 	i++;
         }

        if(!found){
            perm.push_back(kartu);
		    return;
        }
	}

	for (int i = ctr1; i <= ctr2; i++) {

		int temp = kartu[ctr1];
		kartu[ctr1] = kartu[i];
		kartu[i] = temp;

        permutasi(kartu, perm, ctr1 + 1, ctr2);
 
		temp = kartu[ctr1];
		kartu[ctr1] = kartu[i];
		kartu[i] = temp;

	}
}

float operasi(float left, char op, float right){
    if(op == '+'){
        return left + right;
    }
    else if(op == '-'){
        return left - right;
    }
    else if(op == '*'){
        return left * right;
    }
    else if(op == '/'){
        try {
            float result = (float)left/right;
            //cout << result;
            return result;
        }
        catch (...) {
            cout << "";
        }
    }
}

int perhitungan(float a, float b, float c, float d, int savefile){
    int count = 0; 
    for (char p : op){
        for (char q : op){
            for (char r : op){
                if (operasi(operasi(a, p, b), q, operasi(c, r, d)) == 24.00) {
                    if(savefile == 1){
                        out_file << "(" << a << p << b << ")" << q << "(" << c << r << d << ")" << endl;
                    }
                    cout << "(" << a << p << b << ")" << q << "(" << c << r << d << ")";
                    cout << "\n";
                    count++;
                        
                }
                if (operasi(operasi(operasi(a, p, b), q, c), r, d) == 24.00) {
                    if(savefile == 1){
                        out_file << "((" << a << p << b << ")" << q << c << ")" << r << d << endl;
                    }
                    cout << "((" << a << p << b << ")" << q << c << ")" << r << d;
                    cout << "\n";
                    count++;
                }
                if (operasi(operasi(a, p, operasi(b, q, c)), r, d) == 24.00) {
                    if(savefile == 1){
                        out_file << "(" << a << p << "(" << b << q  << c  << "))" << r << d << endl;
                    }
                    cout << "(" << a << p << "(" << b << q  << c  << "))" << r << d;
                    cout << "\n";
                    count++;
                }
                if (operasi(a, p, operasi(b, q, operasi(c, r, d))) == 24.00) {
                    if(savefile == 1){
                        out_file << a << p << "(" << b << q << "(" << c << r << d << "))" << endl;
                    }
                    cout << a << p << "(" << b << q << "(" << c << r << d << "))";
                    cout << "\n";
                    count++;
                }
                if (operasi(a, p, operasi(operasi(b, q, c), r, d)) == 24.00) {
                    if(savefile == 1){
                        out_file << a << p << "((" << b << q << c << ")" << r << d << ")" << endl;
                    }
                    cout << a << p << "((" << b << q << c << ")" << r << d << ")";
                    cout << "\n";
                    count++;
                }
            }
        }
    }
    return count;
}

bool validate(vector<float> kartu){
    float n = 0;
    for(int i =0;i<kartu.size();i++){
        n += kartu[i];
    }
    return(n<=52);
}

float randomgen(){
    float awal = 0;
    float akhir = 0;

    awal = clock();
    for(int i = 0; i <4;i++){
        cout << "";
    }
    akhir = clock();
    float angka = abs(round((akhir - awal)));
    return angka;
}

int main(){
    vector<float> kartu;
    vector<float> kartutemp;
    vector<float> kartuvalid;

    bool cek = false;
    int input1;
    int ctr = 0;
    float waktuawal, waktuakhir, durasi;
    
    float a, b, c, d, w, x, y ,z;
    
    int p = 0;
    cout<<                    "   _______________________________________ " << endl;
    cout<<                    " /   __________________________________    \\ " << endl;
    cout<<                    " |   |            __ __                |   | " << endl;
    cout<<                    " | _ |    /\\     ) _) /''''',          |   | " << endl;
    cout<<                    " |(.)|   <  >    \\ ) // '  `,          |   | " << endl;
    cout<<                    " | ` |    \\/       \\/// ~ |~:    +     |   | " << endl;
    cout<<                    " |   |             ///*\\  ' :    |     |   | " << endl;
    cout<<                    " |   |            ///***\\_~.'    |     |   | " << endl;
    cout<<                    " |   |  .'.    __///````,,..\\_   |     |   | " << endl;
    cout<<                    " |   |   ` \\ _/* +_\\#\\~\\ooo/ \\ |       |   | " << endl;
    cout<<                    " |   |     |/:\\ + *\\_\\#\\~\\so/!!\\       |   | " << endl;
    cout<<                    " |   |    _\\_::\\ * + \\-\\#\\o/!!!\\       |   | " << endl;
    cout<<                    " |   |   / <_=::\\ + */_____@_!!!_|     |   | " << endl;
    cout<<                    " |   |  <__/_____\\ */( /\\______ _|     |   | " << endl;
    cout<<                    " |   |   |_   _ __\\/_)/* \\   ._/  >    |   | " << endl;
    cout<<                    " |   |   | !!! @     /* + \\::=_>_/     |   | " << endl;
    cout<<                    " |   |   |\\!!!/o\\#\\_\\ + * \\::_\\        |   | " << endl;
    cout<<                    " |   |   | \\!!/os\\~\\#_\\_* + \\:/|       |   | " << endl;
    cout<<                    " |   |   |  \\_/ooo\\~\\#_\\+_*/- \\        |   | " << endl;
    cout<<                    " |   |   |    \''``,,,,///      .`.     |   | " << endl;
    cout<<                    " |   |   |     ,.- ***///        '     |   | " << endl;
    cout<<                    " |   |   |    : ~  \\*///               |   | " << endl;
    cout<<                    " |   |   +    : |   \\//\\               |   | " << endl;
    cout<<                    " |   |        ,~  ~ //_( \      /\\      | ; | " << endl;
    cout<<                    " |   |        ,'  ` /_(__(    <  >     |(_)| " << endl;
    cout<<                    " |   |         `````           \\/      |   | " << endl;
    cout<<                    " |   |_________________________________|   | " << endl;
    cout<<                    " \\_________________________________________/ " << endl;

    while(!cek){
        cout << endl;
        cout << "          SELAMAT DATANG DI 24 SOLVER" << endl;
        cout << "\"Takjublah kalian dengan kecerdasan sang ratu\"" << endl;
        cout << endl;
        cout << "Ratu : \"Pilihan cara memilih kartu yang akan diberikan kepadaku!\"" << endl;
        cout << "1. Random" << endl;
        cout << "2. Input kartu" << endl;
        cout << "> ";
        cin >> input1;
        if(input1 == 1 || input1 == 2){
            cek = true;
        }
        else{
            cout << "Ratu : \"Masukan salah. Ulangi!\"" << endl;
        }
    }

    cout << endl;

    if(input1 == 1){
        vector<float> kartu;
        bool isA, isJ, isQ, isK;
        bool done = false;
        float random;
        cout << "Mendapatkan angka... " << endl;
        while(!done){

            random = randomgen() - 5;
            if(random > 1 && random < 14){
                kartu.push_back(random);
            }
            if(kartu.size() == 4){
                done = true;
            }
        }
        cout << "Kartu yang didapat : (A = 1, J = 11, Q = 12, K = 13)" << endl;
        cout << kartu[0] << " " << kartu[1] << " " << kartu[2] << " " << kartu[3] << endl;
        kartuvalid = kartu;
    }
    else{
        
        bool valid = false;
        bool cukup = false;
        bool startinput = false;
        while(!cukup || !valid){
            string n = "";
            char m;
            vector<float> kartu;
            int ctr1;
            int ctr0;

            //cout << "Masukkan kartu : ";
            getline(cin, n);
            for(int i = 0; i<n.length(); i++){
                m = n[i];
                if (n[i] != ' '){
                    if(m=='A'){
                        x = 1;
                    }
                    else if(m=='J'){
                        x = 11;
                    }
                    else if(m=='Q'){
                        x = 12;
                    }
                    else if(m=='K'){
                        x = 13;
                    }
                    else if(m=='2'){
                        x = 2;
                    }
                    else if(m=='3'){
                        x = 3;
                    }
                    else if(m=='4'){
                        x = 4;
                    }
                    else if(m=='5'){
                        x = 5;
                    }
                    else if(m=='6'){
                        x = 6;
                    }
                    else if(m=='7'){
                        x = 7;
                    }
                    else if(m=='8'){
                        x = 8;
                    }
                    else if(m=='9'){
                        x = 9;
                    }
                    else if(m=='1'){
                        if (n[i+1] == '0'){
                            x = 10;
                            i++;
                        }
                        else{
                            x = 666;
                        }
                    }
                    else{
                        x = 666;
                    }
                    kartu.push_back(x);
                }
            }    
            if(kartu.size() == 4 && startinput){
                cukup = true;
                valid = validate(kartu);
            } 
            else if (startinput){
                cout << "Ratu : \"Pastikan hanya 4 kartu!\"" << endl;
                cukup = false;
                valid = validate(kartu);
            }
            if(!valid && startinput){
                cout << "Ratu : \"Terdapat kartu yang salah!\"" << endl;
            }

            if(!startinput){
                cout << "Masukan kartu : " << endl;
            }
            else if (!cukup || !valid){
                cout << "Masukan kartu : " << endl;
            }
            kartutemp = kartu;
            
            startinput = true;
        }
        kartuvalid = kartutemp;   
    }
    vector<vector<float> > perm;
    int savefile;
    string namafile;
    int ctr2 = kartuvalid.size() - 1;
    permutasi(kartuvalid, perm, 0, ctr2);

    cout << endl;

    cout << "Ratu : \"Apakah ingin menyimpan solusi yang ku dapat nanti ke dalam file?\"" << endl;
    cout << "1. Ya" << endl;
    cout << "2. Tidak" << endl;

    cout << "> ";
    cin >> savefile;

    if(savefile==1){
        cout << "Masukan nama file : " << endl;
        cin >> namafile;
    }
    else{
        remove("../test/Hasil.txt");
    }
    
    waktuawal = clock();
    for (auto x : perm) {
        vector<float> cards;
		for (auto y : x) {
            cards.push_back(y);
		}
        a = cards[0];
        b = cards[1];
        c = cards[2];
        d = cards[3];
        ctr += perhitungan(a,b,c,d,savefile);
	}
    waktuakhir = clock();
    durasi = (waktuakhir - waktuawal) / CLOCKS_PER_SEC;
    if(ctr != 0){
        cout << "Ratu : \"Aku berhasil mendapat " << ctr << " solusi.\"\n";
        if(savefile == 1){
        cout << "Ratu : \"Solusi berhasil disimpan di file " << namafile << ".txt\"" << endl;
        ifstream inFile("../test/Hasil.txt");
        ofstream outFile("../test/"+namafile);
        outFile << inFile.rdbuf();
        remove("../test/Hasil.txt");
    }
    }
    else{
        cout << "Ratu : \"Aku tidak dapat menemukan solusi.\"\n";
        if(savefile==1){
            cout << "Ratu : \"Tidak melakukan penyimpanan file.\"\n";
            remove("../test/Hasil.txt");
        }
    }
    
    out_file.close();
    
    cout << fixed << "Ratu : \"Waktu eksekusi : " << (float)durasi << " detik\"" << endl;
    return 0;
}