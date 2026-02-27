#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    //variabel login
    string username;
    string passwordInput;
    string usernameAsli = "Khanza";
    string passwordAsli = "065";
    int jumlahPercobaan = 0;

    //variabel menu
    int pilihanMenu;

    //variabel konversi
    double nilaiJam, nilaiMenit, nilaiDetik;
    double hasilJam, hasilMenit, hasilDetik;

    //tampilan awal
    cout << "\n";
    cout << "  __________________________________________________\n";
    cout << " |                                                  |\n";
    cout << " |            Iconic Digital Time Converter         |\n";
    cout << " |__________________________________________________|\n\n";

    //login
    while (jumlahPercobaan < 3) {

        cout << " Welcome! Silakan Login\n";
        cout << " Masukkan Username Anda : ";
        getline(cin, username);

        cout << " Masukkan Password Anda (3 digit angka): ";
        getline(cin, passwordInput);

        if (username == usernameAsli && passwordInput == passwordAsli) {
            cout << "\nWelcome!" << username <<endl;
            cout << "Login Berhasil.\n\n";
            break;
        }
        else {
            jumlahPercobaan++;
            cout << " Login gagal. Ulangi! Percobaan ke- " << jumlahPercobaan << endl;

            if (jumlahPercobaan == 3) {
                cout << "\n Maaf, sesi Anda login telah habis.\n";
                cout << "Program Berhenti.\n";
                return 0;
            }
        }
        cout << endl;
    }
    //tampilan menu
    do {
        cout << "\n";
        cout << "  -----------------------------------------------------------\n";
        cout << " |                     MENU UTAMA                           |\n";
        cout << "  -----------------------------------------------------------\n";
        cout << "   [1] Jam    -> Menit & Detik\n";
        cout << "   [2] Menit  -> Jam & Detik\n";
        cout << "   [3] Detik  -> Jam & Menit\n";
        cout << "   [4] Keluar\n";
        cout << "  -----------------------------------------------------------\n";
        cout << "   Masukkan Pilihan (1-4) : ";
        cin >> pilihanMenu;

        cout << endl;

        switch (pilihanMenu) {

            case 1:
                cout << "   Masukkan jumlah jam yang ingin dikonversi : ";
                cin >> nilaiJam;

                hasilMenit = nilaiJam * 60;
                hasilDetik = nilaiJam * 3600;

                cout << "\n   >>> HASIL KONVERSI <<<\n";
                cout << "   " << nilaiJam << " jam = "
                    << hasilMenit << " menit dan "
                    << hasilDetik << " detik\n";
                break;
            
                case 2:
                cout << "   Masukkan jumlah menit yang ingin dikonversi: ";
                cin >> nilaiMenit;

                hasilJam = nilaiMenit / 60;
                hasilDetik = nilaiMenit * 60;

                cout << "\n   >>> HASIL KONVERSI <<<\n";
                cout << "   " << nilaiMenit << " menit = "
                    << hasilJam << " jam dan "
                    << hasilDetik << " detik\n";
                break;

                case 3:
                cout << "   Masukkan jumlah detik yang ingin dikonversi: ";
                cin >> nilaiDetik;

                hasilJam = nilaiDetik / 3600;
                hasilMenit = nilaiDetik / 60;

                cout << "\n   >>> HASIL KONVERSI <<<\n";
                cout << "   " << nilaiDetik << " detik = "
                    << hasilJam << " jam dan "
                    << hasilMenit << " menit\n";
                break;

                case 4:
                cout << "\n   Terima kasih telah menggunakan Iconic Digital Time Converter.\n";
                break;

            default:
                cout << "   Pilihan tidak valid!\n";
        }

        cin.ignore(1000,'\n'); //hapus buffer

    } while (pilihanMenu != 4);

    return 0;
}