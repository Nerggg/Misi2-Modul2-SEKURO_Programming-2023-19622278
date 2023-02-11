#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
using namespace std;
string inttostr(int);
void pelanggan();
void menu();
void line();
string makanan[] = {"null", "Ayam Goreng", "Ayam Bakar", "Bebek Goreng", "Lele Goreng", "Nasi Goreng", "Mie Goreng", "French Fries"}, minuman[] = {"null", "Jus Jeruk", "Jus Jambu", "Jus Semangka", "Jus Alpukat", "Jus Mangga", "Teh Manis", "Kopi Hitam"}, recapTotal, nama;
int hargaMakan[] = {0, 19000, 19000, 24000, 12000, 14000, 12000, 8000}, hargaMinum[] = {0, 9000, 9000, 9000, 9000, 9000, 6000, 6000};
int stokMakan[] = {0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, stokMinum[] = {0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
int hargaTotal=0;
int length = sizeof(makanan)/sizeof(makanan[0]);


int main()
{
    int opt;
    system("cls");
    cout << "Kamu adalah pemiliki toko. Ingin tutup atau membiarkan pelanggan masuk?\n[1] Tutup toko\n[2] Biarkan pelanggan masuk\n";
    cin >> opt;
    if(opt!=2)
    {
        system("cls");
        cout << "Baiklah toko akan ditutup!" << endl;
        if(recapTotal.length()>0)
        {
            ofstream total ("Recap.txt");
            cout << "Berikut adalah rekap penjualanmu" << endl;
            cout << recapTotal << endl;
            cout << "Penghasilan total : " << hargaTotal << endl;
            total << recapTotal + "\n" + "Penghasilan total : " << hargaTotal;
            total.close();
            cout << "Rekap penjualan juga dapat dilihat pada file Recap.txt";
        }
        else
        {
            cout << "Tidak ada penjualan hari ini.";
        }
        return 0;
    }
    cout << "Siapa nama pelanggan?\n";
    cin >> nama;
    pelanggan();
}


void menu()
{
    char input;
    int id, amount = 0;
    system("cls");
    line();
    string recap = "Nama Pelanggan : " + nama + "\n" + "Pesanan\t\tJumlah\t\tHarga\n";
    cout << "Makanan" << endl;
    cout << "ID Menu\t\tNama Menu\t\tHarga Menu\t\tStok" << endl;
    for(int i=1; i<length; i++)
    {
        cout << i << "\t\t" << makanan[i] << "\t\t" << hargaMakan[i] << "\t\t\t" << stokMakan[i] << endl;
    }
    line();
    cout << "Minuman" << endl;
    cout << "ID Menu\t\tNama Menu\t\tHarga Menu\t\tStok" << endl;
    for(int i=1; i<length; i++)
    {
        cout << i << "\t\t" << minuman[i] << "\t\t" << hargaMinum[i] << "\t\t\t" << stokMinum[i] << endl;
    }
    ulangMakan:
    cout << "Apakah ingin membeli makanan? (Y/N)";
    cin >> input;
    if(input=='Y' || input=='y')
    {
        cout << "Masukkan ID makanan yang ingin dibeli\n";
        cin >> id;
        cout << "Mau beli berapa?\n";
        cin >> amount;
        if(stokMakan[id]<amount)
        {
            cout << "Maaf stok makanan yang dipilih tidak mencukupi" << endl;
            goto ulangMakan;
        }
        stokMakan[id]-=amount;
        recap = recap + makanan[id] + "\t" + inttostr(amount) + "\t\t" + inttostr(hargaMakan[id]*amount) + "\n"; 
        hargaTotal+=hargaMakan[id]*amount;
    }
    ulangMinum:
    cout << "Apakah ingin membeli minuman? (Y/N)";
    cin >> input;
    if(input=='Y' || input=='y')
    {
        cout << "Masukkan ID minuman yang ingin dibeli\n";
        cin >> id;
        cout << "Mau beli berapa?\n";
        cin >> amount;
        if(stokMinum[id]<amount)
        {
            cout << "Maaf stok minuman yang dipilih tidak mencukupi" << endl;
            goto ulangMinum;
        }
        stokMinum[id]-=amount;
        recap = recap + minuman[id] + "\t" + inttostr(amount) + "\t\t" + inttostr(hargaMinum[id]*amount) + "\n"; 
        hargaTotal+=hargaMinum[id]*amount;
    }

    if(amount>0)
    {
        cout << "Berikut adalah rekap pembelianmu!" << endl;
        cout << recap;
        recapTotal += recap;
        system("pause");
    }
    pelanggan();
}


void line()
{
    for(int i=0; i<70; i++)
    {
        cout << "=";
    }
    cout << "\n";
}
string inttostr(int num)
{
    stringstream ss;
    string str;
    ss << num;
    ss >> str;
    return str;
}


void pelanggan()
{
    int opt;
    system("cls");
    cout << "Sekarang kamu adalah pelanggan dengan nama " << nama << endl;
    cout << "Apa yang ingin kamu lakukan?\n[1] Lihat menu\n[2] Keluar dari warung\n";
    cin >> opt;
    if(opt==1)
        {
            menu();
        }
    else if(opt==2)
        {
            main();
        }
}
