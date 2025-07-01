#include <iostream>
#include <string>
using namespace std;

const int MAX_KTP = 100;
int jumlahKTP = 0;

class KTP
{
private:
    int ttl[MAX_KTP][3], rt[MAX_KTP], rw[MAX_KTP], maxHari;
    string nik[MAX_KTP], nama[MAX_KTP], tempat[MAX_KTP], kelamin[MAX_KTP], dusun[MAX_KTP], kelurahan[MAX_KTP], kecamatan[MAX_KTP], agama[MAX_KTP], status[MAX_KTP], pekerjaan[MAX_KTP], kewarganegaraan[MAX_KTP], berlaku[MAX_KTP], provinsi[MAX_KTP], kabupaten[MAX_KTP], golonganDarah[MAX_KTP];

public:
    void inputNIK(int *idx);
    void inputNama(int *idx);
    void inputJenisKelamin(int *idx);
    void inputTempatTanggalLahir(int *idx);
    void inputAgama(int *idx);
    void inputStatus(int *idx);
    void inputPekerjaan(int *idx);
    void inputKewarganegaraan(int *idx);
    void inputBerlaku(int *idx);
    void inputAlamat(int *idx);
    void inputGolonganDarah(int *idx);
    void inputAll(int *idx);
    void displaySatu(int *idx);
    void displayAll();
    void sorting();
    void searchNIK();
    void swapKTPData(int *i, int *j); // Helper function untuk swap data
};

void KTP::inputNIK(int *idx)
{
    cout << "NIK (16 digit)           : ";
    cin >> nik[*idx];
    cin.ignore();

    if (nik[*idx].length() != 16 || !isdigit(nik[*idx][0]))
    {
        cout << "NIK tidak valid, silakan masukkan kembali." << endl;
        inputNIK(idx);
    }
}

void KTP::inputNama(int *idx)
{
    cout << "Nama Lengkap             : ";
    getline(cin, nama[*idx]);
}

void KTP::inputJenisKelamin(int *idx)
{
    int pilihan;
    cout << "Pilih Jenis Kelamin      : " << endl;
    cout << "1. Laki-laki" << endl;
    cout << "2. Perempuan" << endl;
    cout << "Pilihan (1/2)            : ";
    cin >> pilihan;
    cin.ignore();

    if (pilihan == 1)
        kelamin[*idx] = "Laki-laki";
    else if (pilihan == 2)
        kelamin[*idx] = "Perempuan";
    else
    {
        cout << "Pilihan tidak valid, silakan masukkan kembali." << endl;
        inputJenisKelamin(idx);
    }
}

void KTP::inputTempatTanggalLahir(int *idx)
{
    cout << "Tempat lahir             : ";
    getline(cin, tempat[*idx]);
    cout << "Tahun lahir (4 digit)    : ";
    cin >> ttl[*idx][2];

    do
    {
        cout << "Bulan lahir (2 digit)    : ";
        cin >> ttl[*idx][1];
        if (ttl[*idx][1] < 1 || ttl[*idx][1] > 12)
            cout << "Bulan tidak valid, silakan masukkan kembali." << endl;
    } while (ttl[*idx][1] < 1 || ttl[*idx][1] > 12);

    if (ttl[*idx][1] == 2)
    {
        if ((ttl[*idx][2] % 4 == 0 && ttl[*idx][2] % 100 != 0) || (ttl[*idx][2] % 400 == 0))
        {
            maxHari = 29;
            cout << "Tahun " << ttl[*idx][2] << " adalah tahun kabisat." << endl;
        }
        else
        {
            maxHari = 28;
            cout << "Tahun " << ttl[*idx][2] << " bukan tahun kabisat." << endl;
        }
    }
    else
        ((ttl[*idx][1] == 4 || ttl[*idx][1] == 6 || ttl[*idx][1] == 9 || ttl[*idx][1] == 11) ? maxHari = 30 : maxHari = 31);

    do
    {
        cout << "Tanggal lahir (1-" << maxHari << ")    : ";
        cin >> ttl[*idx][0];
        if (ttl[*idx][0] < 1 || ttl[*idx][0] > maxHari)
            cout << "Tanggal tidak valid, silakan masukkan kembali." << endl;
    } while (ttl[*idx][0] < 1 || ttl[*idx][0] > maxHari);
    cin.ignore();
}

void KTP::inputAgama(int *idx)
{
    int pilihan;
    cout << "Pilih Agama              : " << endl;
    cout << "1. Islam" << endl;
    cout << "2. Kristen" << endl;
    cout << "3. Katolik" << endl;
    cout << "4. Hindu" << endl;
    cout << "5. Buddha" << endl;
    cout << "6. Konghucu" << endl;
    cout << "7. Lainnya/Tidak Beragama" << endl;
    cout << "Pilihan (1/2/3/4/5/6/7)    : ";
    cin >> pilihan;
    cin.ignore();

    switch (pilihan)
    {
    case 1:
        agama[*idx] = "Islam";
        break;
    case 2:
        agama[*idx] = "Kristen";
        break;
    case 3:
        agama[*idx] = "Katolik";
        break;
    case 4:
        agama[*idx] = "Hindu";
        break;
    case 5:
        agama[*idx] = "Buddha";
        break;
    case 6:
        agama[*idx] = "Konghucu";
        break;
    case 7:
        agama[*idx] = "Lainnya/Tidak Beragama";
        break;
    default:
        cout << "Pilihan tidak valid, silakan masukkan kembali." << endl;
        inputAgama(idx);
        break;
    }
}

void KTP::inputStatus(int *idx)
{
    int pilihan;
    cout << "Pilih Status Perkawinan  : " << endl;
    cout << "1. Belum Kawin" << endl;
    cout << "2. Kawin" << endl;
    cout << "3. Cerai Hidup" << endl;
    cout << "4. Cerai Mati" << endl;
    cout << "Pilihan (1/2/3/4)        : ";
    cin >> pilihan;
    cin.ignore();

    switch (pilihan)
    {
    case 1:
        status[*idx] = "Belum Kawin";
        break;
    case 2:
        status[*idx] = "Kawin";
        break;
    case 3:
        status[*idx] = "Cerai Hidup";
        break;
    case 4:
        status[*idx] = "Cerai Mati";
        break;
    default:
        cout << "Pilihan tidak valid, silakan masukkan kembali." << endl;
        inputStatus(idx);
        break;
    }
}

void KTP::inputPekerjaan(int *idx)
{
    cout << "Pekerjaan                : ";
    getline(cin, pekerjaan[*idx]);
}

void KTP::inputKewarganegaraan(int *idx)
{
    int pilihan;
    cout << "Pilih Kewarganegaraan    : " << endl;
    cout << "1. WNI" << endl;
    cout << "2. WNA" << endl;
    cout << "Pilihan (1/2)            : ";
    cin >> pilihan;
    cin.ignore();

    if (pilihan == 1)
        kewarganegaraan[*idx] = "WNI";
    else if (pilihan == 2)
        kewarganegaraan[*idx] = "WNA";
    else
    {
        cout << "Pilihan tidak valid, silakan masukkan kembali." << endl;
        inputKewarganegaraan(idx);
    }
}

void KTP::inputBerlaku(int *idx)
{
    cout << "Berlaku Hingga           : ";
    getline(cin, berlaku[*idx]);
}

void KTP::inputAlamat(int *idx)
{
    cout << "RT (3 digit)             : ";
    cin >> rt[*idx];
    cout << "RW (3 digit)             : ";
    cin >> rw[*idx];
    cin.ignore();
    cout << "Dusun/Kampung            : ";
    getline(cin, dusun[*idx]);
    cout << "Kelurahan/Desa           : ";
    getline(cin, kelurahan[*idx]);
    cout << "Kecamatan                : ";
    getline(cin, kecamatan[*idx]);
    cout << "Kabupaten/Kota           : ";
    getline(cin, kabupaten[*idx]);
    cout << "Provinsi                 : ";
    getline(cin, provinsi[*idx]);
}

void KTP::inputGolonganDarah(int *idx)
{
    int pilihan;
    cout << "Pilih Golongan Darah     : " << endl;
    cout << "1. A" << endl;
    cout << "2. B" << endl;
    cout << "3. AB" << endl;
    cout << "4. O" << endl;
    cout << "Pilihan (1/2/3/4)        : ";
    cin >> pilihan;
    cin.ignore();

    switch (pilihan)
    {
    case 1:
        golonganDarah[*idx] = "A";
        break;
    case 2:
        golonganDarah[*idx] = "B";
        break;
    case 3:
        golonganDarah[*idx] = "AB";
        break;
    case 4:
        golonganDarah[*idx] = "O";
        break;
    default:
        cout << "Pilihan tidak valid, silakan masukkan kembali." << endl;
        inputGolonganDarah(idx);
        break;
    }
}

void KTP::inputAll(int *idx)
{
    cout << "===== Masukkan data KTP =====" << endl;
    inputNIK(idx);
    inputNama(idx);
    inputJenisKelamin(idx);
    inputTempatTanggalLahir(idx);
    inputAgama(idx);
    inputStatus(idx);
    inputPekerjaan(idx);
    inputKewarganegaraan(idx);
    inputBerlaku(idx);
    inputAlamat(idx);
    inputGolonganDarah(idx);
}

void KTP::displaySatu(int *idx)
{
    cout << "=============================================================" << endl;
    cout << "\t\tPROVINSI " << provinsi[*idx] << endl;
    cout << "\t\tKABUPATEN " << kabupaten[*idx] << endl;
    cout << "=============================================================" << endl;
    cout << "NIK\t\t\t: " << nik[*idx] << endl;
    cout << "Nama\t\t\t: " << nama[*idx] << endl;
    cout << "Tempat/Tgl Lahir\t: " << tempat[*idx] << ", " << ttl[*idx][0] << "-" << ttl[*idx][1] << "-" << ttl[*idx][2] << endl;
    cout << "Jenis Kelamin\t\t: " << kelamin[*idx] << "\t\tGol. Darah: " << golonganDarah[*idx] << endl;
    cout << "Alamat\t\t\t: " << dusun[*idx] << endl;
    cout << "\tRT/RW\t\t: " << rt[*idx] << "/" << rw[*idx] << endl;
    cout << "\tKel/Desa\t: " << kelurahan[*idx] << endl;
    cout << "\tKecamatan\t: " << kecamatan[*idx] << endl;
    cout << "Agama\t\t\t: " << agama[*idx] << endl;
    cout << "Status Perkawinan\t: " << status[*idx] << endl;
    cout << "Pekerjaan\t\t: " << pekerjaan[*idx] << endl;
    cout << "Kewarganegaraan\t\t: " << kewarganegaraan[*idx] << endl;
    cout << "Berlaku Hingga\t\t: " << berlaku[*idx] << endl;
    cout << "=============================================================" << endl;
}

void KTP::displayAll()
{
    if (jumlahKTP == 0)
    {
        cout << "Tidak ada data KTP yang tersedia." << endl;
    }
    else
    {
        for (int i = 0; i < jumlahKTP; i++)
        {
            cout << "=============================================================" << endl;
            cout << "\t\tPROVINSI " << provinsi[i] << endl;
            cout << "\t\tKABUPATEN " << kabupaten[i] << endl;
            cout << "=============================================================" << endl;
            cout << "NIK\t\t\t: " << nik[i] << endl;
            cout << "Nama\t\t\t: " << nama[i] << endl;
            cout << "Tempat/Tgl Lahir\t: " << tempat[i] << ", " << ttl[i][0] << "-" << ttl[i][1] << "-" << ttl[i][2] << endl;
            cout << "Jenis Kelamin\t\t: " << kelamin[i] << "\t\tGol. Darah: " << golonganDarah[i] << endl;
            cout << "Alamat\t\t\t: " << dusun[i] << endl;
            cout << "\tRT/RW\t\t: " << rt[i] << "/" << rw[i] << endl;
            cout << "\tKel/Desa\t: " << kelurahan[i] << endl;
            cout << "\tKecamatan\t: " << kecamatan[i] << endl;
            cout << "Agama\t\t\t: " << agama[i] << endl;
            cout << "Status Perkawinan\t: " << status[i] << endl;
            cout << "Pekerjaan\t\t: " << pekerjaan[i] << endl;
            cout << "Kewarganegaraan\t\t: " << kewarganegaraan[i] << endl;
            cout << "Berlaku Hingga\t\t: " << berlaku[i] << endl;
            cout << "=============================================================" << endl;
        }
    }
}

void KTP::sorting()
{
    if (jumlahKTP <= 1)
    {
        cout << "Tidak ada data KTP yang cukup untuk diurutkan." << endl;
    }
    else
    {
        do
        {
            cout << "====== Menu Pengurutan KTP ======" << endl;
            cout << "1. Urutkan dari yang tertua" << endl;
            cout << "2. Urutkan dari yang termuda" << endl;
            cout << "3. Kembali ke menu utama" << endl;
            cout << "Pilih opsi (1/2/3): ";
            int pilihan;
            cin >> pilihan;

            switch (pilihan)
            {
            case 1:
                for (int i = 0; i < jumlahKTP - 1; i++)
                {
                    for (int j = i + 1; j < jumlahKTP; j++)
                    {
                        if (ttl[i][2] > ttl[j][2] ||
                            (ttl[i][2] == ttl[j][2] && ttl[i][1] > ttl[j][1]) ||
                            (ttl[i][2] == ttl[j][2] && ttl[i][1] == ttl[j][1] && ttl[i][0] > ttl[j][0]))
                        {
                            swapKTPData(&i, &j);
                        }
                    }
                }
                displayAll();
                break;
            case 2:
                for (int i = 0; i < jumlahKTP - 1; i++)
                {
                    for (int j = i + 1; j < jumlahKTP; j++)
                    {
                        if (ttl[i][2] < ttl[j][2] ||
                            (ttl[i][2] == ttl[j][2] && ttl[i][1] < ttl[j][1]) ||
                            (ttl[i][2] == ttl[j][2] && ttl[i][1] == ttl[j][1] && ttl[i][0] < ttl[j][0]))
                        {
                            swapKTPData(&i, &j);
                        }
                    }
                }
                displayAll();
                break;
            case 3:
                return;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            }
        } while (true);
    }
}

void KTP::searchNIK()
{
    if (jumlahKTP == 0)
    {
        cout << "Tidak ada data KTP yang tersedia." << endl;
    }
    else
    {
        string searchNIK;
        cout << "Masukkan NIK yang ingin dicari: ";
        cin >> searchNIK;

        for (int i = 0; i < jumlahKTP; i++)
        {
            if (nik[i] == searchNIK)
            {
                displaySatu(&i);
                return;
            }
        }
        cout << "NIK tidak ditemukan." << endl;
    }
}

void KTP::swapKTPData(int *i, int *j)
{
    string tempString;
    int tempInt, tempTTL[3];

    tempString = nik[*i];
    nik[*i] = nik[*j];
    nik[*j] = tempString;

    tempString = nama[*i];
    nama[*i] = nama[*j];
    nama[*j] = tempString;

    tempString = tempat[*i];
    tempat[*i] = tempat[*j];
    tempat[*j] = tempString;

    for (int k = 0; k < 3; k++)
    {
        tempTTL[k] = ttl[*i][k];
        ttl[*i][k] = ttl[*j][k];
        ttl[*j][k] = tempTTL[k];
    }

    tempString = kelamin[*i];
    kelamin[*i] = kelamin[*j];
    kelamin[*j] = tempString;

    tempString = dusun[*i];
    dusun[*i] = dusun[*j];
    dusun[*j] = tempString;

    tempInt = rt[*i];
    rt[*i] = rt[*j];
    rt[*j] = tempInt;

    tempInt = rw[*i];
    rw[*i] = rw[*j];
    rw[*j] = tempInt;

    tempString = kelurahan[*i];
    kelurahan[*i] = kelurahan[*j];
    kelurahan[*j] = tempString;

    tempString = kecamatan[*i];
    kecamatan[*i] = kecamatan[*j];
    kecamatan[*j] = tempString;

    tempString = agama[*i];
    agama[*i] = agama[*j];
    agama[*j] = tempString;

    tempString = status[*i];
    status[*i] = status[*j];
    status[*j] = tempString;

    tempString = pekerjaan[*i];
    pekerjaan[*i] = pekerjaan[*j];
    pekerjaan[*j] = tempString;

    tempString = kewarganegaraan[*i];
    kewarganegaraan[*i] = kewarganegaraan[*j];
    kewarganegaraan[*j] = tempString;

    tempString = berlaku[*i];
    berlaku[*i] = berlaku[*j];
    berlaku[*j] = tempString;

    tempString = provinsi[*i];
    provinsi[*i] = provinsi[*j];
    provinsi[*j] = tempString;

    tempString = kabupaten[*i];
    kabupaten[*i] = kabupaten[*j];
    kabupaten[*j] = tempString;

    tempString = golonganDarah[*i];
    golonganDarah[*i] = golonganDarah[*j];
    golonganDarah[*j] = tempString;
}

int main()
{
    KTP ktp;
    int pilihan;
    do
    {
        cout << "====== Menu KTP ======" << endl;
        cout << "1. Input Data KTP" << endl;
        cout << "2. Tampilkan Semua Data KTP" << endl;
        cout << "3. Tampilkan Data KTP Berdasarkan NIK" << endl;
        cout << "4. Urutkan Data KTP" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih opsi (1/2/3/4/5): ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            if (jumlahKTP < MAX_KTP)
            {
                ktp.inputAll(&jumlahKTP);
                jumlahKTP++;
            }
            else
            {
                cout << "Jumlah KTP sudah mencapai batas maksimum." << endl;
            }
            break;
        case 2:
            ktp.displayAll();
            break;
        case 3:
            ktp.searchNIK();
            break;
        case 4:
            ktp.sorting();
            break;
        case 5:
            cout << "Terima kasih! Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 5);
    return 0;
}