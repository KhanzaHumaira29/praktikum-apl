#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

struct DataLogin {
    string username;
    string password;
};

DataLogin akun = {"Khanza", "065"};

string inputUsername, inputPassword;
bool berhasilLogin = false;
int kesempatanLogin = 0;

struct Membership {
    string jenisMembership;
    int durasiBulan;
};

struct MemberGym {
    int idMember;
    string namaMember;
    int umurMember;
    Membership informasiMembership;
};

int main() {

    DataLogin daftarUser[100];
    int jumlahUser = 0;

    MemberGym daftarMember[100];
    int jumlahMember = 0;
    int autoID = 1;

    int menuAwal;

    do {
        cout << "\n---- SISTEM MANAJEMEN MEMBERSHIP GYM ----\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu untuk mengakses data membership gym (1-3) : ";
        cin >> menuAwal;

        switch (menuAwal) {

        case 1:
            if (jumlahUser < 100) {
                cout << "\n--- REGISTER USER ---\n";
                cout << "Buat Username : ";
                cin >> daftarUser[jumlahUser].username;

                bool validPassword = false;
                while (!validPassword) {
                    cout << "Buat Password (hanya angka) : ";
                    cin >> daftarUser[jumlahUser].password;

                    validPassword = true;
                    for (int i = 0; i < daftarUser[jumlahUser].password.length(); i++) {
                        if (!isdigit(daftarUser[jumlahUser].password[i])) {
                            validPassword = false;
                            break;
                        }
                    }

                    if (!validPassword) {
                        cout << "Password harus berupa angka saja!\n";
                    }
                }
                jumlahUser++;
                cout << "Registrasi berhasil.\n";

            } else {
                cout << "Maaf, jumlah user sudah penuh.\n";
            }
            break;

        case 2: {
            if (jumlahUser == 0) {
                cout << "Belum ada user terdaftar.\n";
                break;
            }

            string inputUsername, inputPassword;
            bool berhasilLogin = false;
            int kesempatanLogin = 0;

            while (kesempatanLogin < 3) {
                cout << "\n--- LOGIN SISTEM ---\n";
                cout << "Masukkan Username : ";
                cin >> inputUsername;
                cout << "Masukkan Password : ";
                cin >> inputPassword;

                for (int i = 0; i < jumlahUser; i++) {
                    if (inputUsername == daftarUser[i].username &&
                        inputPassword == daftarUser[i].password) {

                        berhasilLogin = true;
                        cout << "\nLogin berhasil! Welcome "
                            << daftarUser[i].username << endl;
                        break;
                    }
                }

                if (berhasilLogin) {
                    break;
                } else {
                    kesempatanLogin++;
                    cout << "Login gagal! Sisa percobaan "
                        << 3 - kesempatanLogin << endl;
                }
            }

            if (!berhasilLogin) {
                cout << "\nAnda gagal login 3 kali. Program berhenti.\n";
                return 0;
            }

            int pilihanMenu;
            do {
                cout << "\n---- MENU UTAMA ----\n";
                cout << "1. Tambah Member\n";
                cout << "2. Lihat Member\n";
                cout << "3. Ubah Member\n";
                cout << "4. Hapus Member\n";
                cout << "5. Logout Menu Utama\n";
                cout << "Pilih menu: ";
                cin >> pilihanMenu;

                switch (pilihanMenu) {

                case 1:
                    if (jumlahMember < 100) {
                        daftarMember[jumlahMember].idMember = autoID++;
                        cout << "\nID Member : " << daftarMember[jumlahMember].idMember << endl;

                        cout << "Nama Member : ";
                        cin >> daftarMember[jumlahMember].namaMember;

                        cout << "Umur Member : ";
                        cin >> daftarMember[jumlahMember].umurMember;

                        string inputJenis;
                        bool jenisValid = false;

                        while (!jenisValid) {
                            cout << "Jenis Membership (Reguler/Ultra/Premium): ";
                            cin >> inputJenis;

                            if (inputJenis == "Reguler") {
                                daftarMember[jumlahMember].informasiMembership.jenisMembership = "Reguler";
                                daftarMember[jumlahMember].informasiMembership.durasiBulan = 1;
                                jenisValid = true;
                            }
                            else if (inputJenis == "Ultra") {
                                daftarMember[jumlahMember].informasiMembership.jenisMembership = "Ultra";
                                daftarMember[jumlahMember].informasiMembership.durasiBulan = 6;
                                jenisValid = true;
                            }
                            else if (inputJenis == "Premium") {
                                daftarMember[jumlahMember].informasiMembership.jenisMembership = "Premium";
                                daftarMember[jumlahMember].informasiMembership.durasiBulan = 24;
                                jenisValid = true;
                            }
                            else {
                                cout << "Error, pilih sesuai yang ada saja.\n";
                            }
                        }

                        jumlahMember++;
                        cout << "Member gym berhasil ditambahkan.\n";
                    } else {
                        cout << "Data penuh!\n";
                    }
                    break;

                case 2:
                    if (jumlahMember == 0) {
                        cout << "Belum ada data membership gym.\n";
                    } else {
                        cout << "\n+----+---------------+--------+---------------+--------+\n";
                        cout << "| ID | Nama          | Umur   | Jenis         | Durasi |\n";
                        cout << "+----+---------------+--------+---------------+--------+\n";

                        for (int i = 0; i < jumlahMember; i++) {
                            cout << "| "
                                << setw(2) << daftarMember[i].idMember << " | "
                                << setw(13) << daftarMember[i].namaMember << " | "
                                << setw(6) << daftarMember[i].umurMember << " | "
                                << setw(13) << daftarMember[i].informasiMembership.jenisMembership << " | "
                                << setw(6) << daftarMember[i].informasiMembership.durasiBulan << " |\n";
                        }

                        cout << "+----+---------------+--------+---------------+--------+\n";
                    }
                    break;

                case 3: {
                    int idUbah;
                    cout << "Masukkan ID Member: ";
                    cin >> idUbah;

                    for (int i = 0; i < jumlahMember; i++) {
                        if (daftarMember[i].idMember == idUbah) {

                            cout << "Nama Baru : ";
                            cin >> daftarMember[i].namaMember;

                            cout << "Umur Baru : ";
                            cin >> daftarMember[i].umurMember;

                            string inputJenisBaru;
                            bool jenisValidBaru = false;

                            while (!jenisValidBaru) {
                                cout << "Jenis Membership Baru (Reguler/Ultra/Premium): ";
                                cin >> inputJenisBaru;

                                if (inputJenisBaru == "Reguler") {
                                    daftarMember[i].informasiMembership.jenisMembership = "Reguler";
                                    daftarMember[i].informasiMembership.durasiBulan = 1;
                                    jenisValidBaru = true;
                                }
                                else if (inputJenisBaru == "Ultra") {
                                    daftarMember[i].informasiMembership.jenisMembership = "Ultra";
                                    daftarMember[i].informasiMembership.durasiBulan = 6;
                                    jenisValidBaru = true;
                                }
                                else if (inputJenisBaru == "Premium") {
                                    daftarMember[i].informasiMembership.jenisMembership = "Premium";
                                    daftarMember[i].informasiMembership.durasiBulan = 24;
                                    jenisValidBaru = true;
                                }
                                else {
                                    cout << "Jenis tidak valid!\n";
                                }
                            }

                            cout << "Data berhasil diubah.\n";
                        }
                    }
                    break;
                }

                case 4: {
                    int idHapus;
                    cout << "Masukkan ID Member: ";
                    cin >> idHapus;

                    for (int i = 0; i < jumlahMember; i++) {
                        if (daftarMember[i].idMember == idHapus) {
                            for (int j = i; j < jumlahMember - 1; j++) {
                                daftarMember[j] = daftarMember[j + 1];
                            }
                            jumlahMember--;
                            cout << "Data berhasil dihapus.\n";
                            break;
                        }
                    }
                    break;
                }

                case 5:
                    cout << "Thank You! Logout menu utama berhasil><\n";
                    break;

                default:
                    cout << "Menu tidak valid.\n";
                }

            } while (pilihanMenu != 5);

            break;
        }

        case 3:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilih sesuai menu (1-3).\n";
        }

    } while (menuAwal != 3);

    return 0;
}