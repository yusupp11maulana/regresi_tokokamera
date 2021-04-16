#include<iostream>
using namespace std;

void kuadratx(int x[], int n);
void perkalianxy(int x[], int y[], int n);
int jumlahx(int x[], int n);
int jumlahy(int y[], int n);
int jumlahkuadratx(int x[], int n);
int jumlahhasilxy(int x[], int y[], int n);
double konstanta(double ye, double xe2, double xe, double xeye, double n);
double koefisien(double ye, double xe2, double xe, double xeye, double n);
void prediksi(int jumlah, double kstt, double kfsn);

int main(){
    int n, i, totalkuadratx, totalkalixy, totalx, totaly, jumlahdata;
    double konstantanya, koefisiennya;
    int x[] = {8,2,6,4,7,3};
    int y[] = {7,3,7,8,8,6};
    n = sizeof(x)/sizeof(x[0]);

    cout <<endl<< "=============  Yusup Maulana  ============="<<endl<<"============  13.2018.1.00724  ============"<<endl <<endl<<endl;

    // Menampilkan Nilai X
    cout << "Nilai x \t\t: ";
    for (i = 0; i < n;i++){
        cout << x[i]<<" ";
    }
    
    // Menampilkan Nilai Y
    cout<<endl << "Nilai y \t\t: ";
    for (i = 0; i < n;i++){
        cout << y[i]<<" ";
    }

    // Menampilkan hasil Kuadrat X
    cout << endl<< "Hasil Kuadrat x \t: ";
    kuadratx(x, n);

    // Menampilkan Hasil Perkalian XY
    cout << endl<< "Hasil Perkalian XY \t: ";
    perkalianxy(x, y, n);

    // Menampilakan Jumlah X
    totalx = jumlahx(x, n);
    cout<< endl <<"Total Nilai X \t\t: "<<totalx<<endl;

    // Menampilkan Nilai Y
    totaly = jumlahy(y, n);
    cout <<"Total Nilai Y \t\t: "<<totaly<<endl;

    // Menampilkan Jumlah Kuadrat X
    totalkuadratx = jumlahkuadratx(x, n);
    cout <<"Total Kuadrat X \t: "<<totalkuadratx <<endl;

    // Menampilkan Jumlah Perkalian XY
    totalkalixy = jumlahhasilxy(x,y, n);
    cout <<"Total Perkalian XY \t: "<< totalkalixy <<endl;

    // Menampilkan Konstanta
    konstantanya = konstanta(totaly, totalkuadratx, totalx, totalkalixy, n);
    cout <<"Nilai Konstanta \t: "<< konstantanya <<endl;
    
    // Menampilkan Koefisien
    koefisiennya = koefisien(totaly, totalkuadratx, totalx, totalkalixy, n);
    cout <<"Nilai Koefisien \t: "<< koefisiennya <<endl<<endl<<endl;

    cout << "===============  PENCARIAN  ==============="<<endl<<"============  NILAI  PREDIKSI  ============"<<endl <<endl<<endl;

    // Inputan
    cout << "Masukkan Jumlah Data : ";
    cin >> jumlahdata;
    cout << endl<< endl;
    prediksi(jumlahdata, konstantanya, koefisiennya);

    cout << endl<< endl<< "==================  END  =================="<<endl <<endl<<endl;

}

void kuadratx(int x[], int n){
    int i;
    int hasilkuadrat[5];
    for (i = 0; i < n;i++){
        hasilkuadrat[i] = x[i] * x[i];
        cout << hasilkuadrat[i]<<" ";
    }
}

void perkalianxy(int x[], int y[], int n){
    int i;
    int hasilxy[5];
    for (i = 0; i < n;i++){
        hasilxy[i] = x[i] * y[i];
        cout << hasilxy[i]<<" ";
    }
}

int jumlahx(int x[], int n){
    int i, totalx;
    totalx = 0;
    for (i = 0; i < n;i++){
        totalx = totalx + x[i];
    }
    return totalx;
}

int jumlahy(int y[], int n){
    int i, totaly;
    totaly = 0;
    for (i = 0; i < n;i++){
        totaly = totaly + y[i];
    }
    return totaly;
}

int jumlahkuadratx(int x[], int n){
    int i, totalkuadratx;
    totalkuadratx = 0;
    for (i = 0; i < n;i++){
        totalkuadratx = totalkuadratx + (x[i] * x[i]);
    }
    return totalkuadratx;
}

int jumlahhasilxy(int x[], int y[], int n){
    int i, totalperkalianxy;
    totalperkalianxy = 0;
    for (i = 0; i < n;i++){
        totalperkalianxy = totalperkalianxy + (x[i] * y[i]);
    }
    return totalperkalianxy;
}

double konstanta(double ye, double xe2, double xe, double xeye, double n){
    double konst;
    konst = ((ye * xe2) - (xe * xeye)) / ((n * xe2) - (xe*xe));

    return konst;
}

double koefisien(double ye, double xe2, double xe, double xeye, double n){
    double koef;
    koef = ((n * xeye) - (xe * ye)) / ((n * xe2) - (xe * xe));

    return koef;
}

void prediksi(int jumlah, double kstt, double kfsn){
    int i;
    double hasilnya[1000], nilaix[1000];
    for (i = 1; i <= jumlah; i++){
        cout << "Masukkan nilai x ke-" << i << " : ";
        cin >> nilaix[i];
        hasilnya[i] = kstt + (kfsn * nilaix[i]);
        cout << "Hasil Prediksi ke-" << i << " : " << hasilnya[i]<<endl<<endl;
    }
}