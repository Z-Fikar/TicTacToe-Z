#ifndef _tttz_h
#define _tttz_h
#include <iostream.h>
#include <stdlib.h>

int papan[9];
int count;

void menu();
void init();
void jalan(int simbol, int jenis);
void pemain(int simbol);
void komp(int simbol);
void komSatu(int simbol);
void komJalan(int simbol);
void komTaktik(int simbol, int taktik = 1);
void pvp();
void pvc();
void cvp();
void cvc();
void cls();
void tampil();
void selesai();
bool cekMenang();
char ikec(int angka);


void jalan(int simbol, int jenis = 1){
	if (jenis == 1){
		pemain(simbol);
	}
	else{
		komp(simbol);
	}
}

void komp(int simbol){
	cout<<"Giliran "<<ikec(simbol)<<":\n";
	_sleep(1000);
	komTaktik(simbol);
	count++;
}

void komJalan(int simbol){
	bool sudah = false;
	bool ulang = true;
	bool kosong = false;
	while (ulang){
		for (int i=0; i<9; i+=2){
			if(papan[i] == 0){
				kosong = true;
				break;
			}
		}
		if (kosong){
			switch (rand() % 5 + 1){
				case 1: if (papan[0] == 0) {papan[0] = simbol; ulang = false; sudah = true;} break;
				case 2: if (papan[2] == 0) {papan[2] = simbol; ulang = false; sudah = true;} break;
				case 3: if (papan[4] == 0) {papan[4] = simbol; ulang = false; sudah = true;} break;
				case 4: if (papan[6] == 0) {papan[6] = simbol; ulang = false; sudah = true;} break;
				case 5: if (papan[8] == 0) {papan[8] = simbol; ulang = false; sudah = true;} break;
			}
		}
		else{
			ulang = false;
		}
	}
	if (!sudah || !kosong){
		for (int i = 1; i<8; i+=2){
			if (papan[i] == 0){
				papan[i] = simbol;
				break;
			}
		}
	}
}

void komTaktik(int simbol, int taktik){
	int baris[3], kolom[3], diag[2], i;
	
	baris[1] = papan[0] + papan[1] + papan[2];
	baris[2] = papan[3] + papan[4] + papan[5];
	baris[3] = papan[6] + papan[7] + papan[8];
	
	kolom[1] = papan[0] + papan[3] + papan[6];
	kolom[2] = papan[1] + papan[4] + papan[7];
	kolom[3] = papan[2] + papan[5] + papan[8];
	
	diag[1] = papan[0] + papan[4] + papan[8];
	diag[2] = papan[2] + papan[4] + papan[6];
	
	if (baris[1] == 2*simbol*taktik){
		for (i=0; i<3; i++){
			if (papan[i] == 0){
				papan[i] = simbol;
			}
		}
	}
	else if (baris[2] == 2*simbol*taktik){
		for (i=3; i<6; i++){
			if (papan[i] == 0){
				papan[i] = simbol;
			}
		}
	}
	else if (baris[3] == 2*simbol*taktik){
		for (i=6; i<9; i++){
			if (papan[i] == 0){
				papan[i] = simbol;
			}
		}
	}
	else if (kolom[1] == 2*simbol*taktik){
		for (i=0; i<7; i+=3){
			if (papan[i] == 0){
				papan[i] = simbol;
			}
		}
	}
	else if (kolom[2] == 2*simbol*taktik){
		for (i=1; i<8; i+=3){
			if (papan[i] == 0){
				papan[i] = simbol;
			}
		}
	}
	else if (kolom[3] == 2*simbol*taktik){
		for (i=2; i<9; i+=3){
			if (papan[i] == 0){
				papan[i] = simbol;
			}
		}
	}
	else if (diag[1] == 2*simbol*taktik){
		for (i=0; i<9; i+=4){
			if (papan[i] == 0){
				papan[i] = simbol;
			}
		}
	}
	else if (diag[2] == 2*simbol*taktik){
		for (i=2; i<7; i+=2){
			if (papan[i] == 0){
				papan[i] = simbol;
			}
		}
	}
	else{
		if (taktik == -1){
			komJalan(simbol);
		}
		else{
			komTaktik(simbol, -taktik);
		}
	}
}

void init(){
	count = 0;
	for(int i = 0 ; i < 9 ; i++){
		papan[i] = 0;
	}
	tampil();
}

void pvp(){
	int simbol = -1;
	while ((count<9) && (!cekMenang())){
		tampil();
		simbol = -simbol;
		jalan(simbol);
	}
	tampil();
	if (cekMenang()){
		cout<<" "<<ikec(simbol)<<" Menang!";
	}
	else if (count == 9){
		cout<<"\nXO Seri OX\n";
	}
	selesai();
}

void pvc(){
	int simbol = -1;
	int jenis = -1;
	while ((count<9) && (!cekMenang())){
		tampil();
		simbol = -simbol;
		jenis = -jenis;
		jalan(simbol, jenis);
	}
	tampil();
	if (cekMenang()){
		cout<<" "<<ikec(simbol)<<" Menang!";
	}
	else if (count == 9){
		cout<<"\nXO Seri OX\n";
	}
	selesai();
}

void cvp(){
	int simbol = 1;
	int jenis = 1;
	while ((count<9) && (!cekMenang())){
		tampil();
		simbol = -simbol;
		jenis = -jenis;
		jalan(simbol, jenis);
	}
	tampil();
	if (cekMenang()){
		cout<<" "<<ikec(simbol)<<" Menang!";
	}
	else if (count == 9){
		cout<<"\nXO Seri OX\n";
	}
	selesai();
}

void cvc(){
	int simbol = -1;
	while ((count<9) && (!cekMenang())){
		tampil();
		simbol = -simbol;
		jalan(simbol, -1);
	}
	tampil();
	if (cekMenang()){
		cout<<" "<<ikec(simbol)<<" Menang!";
	}
	else if (count == 9){
		cout<<"\nXO Seri OX\n";
	}
	selesai();
}

void selesai(){
	cout <<endl;
	system("pause");
	menu();	
}

void cls(){
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif
}

void tampil(){
	cls();
	cout<<" |\t1\t2\t3\n";
	cout<<"-+-------------------------\n";
	for(int i = 0 ; i < 3 ; i++){
		cout<<i+1<<"|\t";
		for(int j = 0 ; j < 3 ; j++){
			cout<<ikec(papan[i*3+j])<<"\t";
		}
		cout<<"\n";
	}
}


bool cekMenang(){
	int baris1, baris2, baris3;
	int kolom1, kolom2, kolom3;
	int diag1, diag2;
	bool baris, kolom, diag;
	
	baris1 = papan[0] + papan[1] + papan[2];
	baris2 = papan[3] + papan[4] + papan[5];
	baris3 = papan[6] + papan[7] + papan[8];
	
	kolom1 = papan[0] + papan[3] + papan[6];
	kolom2 = papan[1] + papan[4] + papan[7];
	kolom3 = papan[2] + papan[5] + papan[8];
	
	diag1 = papan[0] + papan[4] + papan[8];
	diag2 = papan[2] + papan[4] + papan[6];
	
	baris = (abs(baris1) == 3) || (abs(baris2) == 3) || (abs(baris3) == 3);
	kolom = (abs(kolom1) == 3) || (abs(kolom2) == 3) || (abs(kolom3) == 3);
	diag = (abs(diag1) == 3) || (abs(diag2) == 3);
	
	if (baris || kolom || diag){
		return true;
	}
	else{
		return false;
	}
}

void pemain(int simbol){
	int baris, kolom;
	cout<<"Giliran "<<ikec(simbol)<<":\n";
	cout << "Baris ke: ";
	cin >> baris;
	cout << "Kolom ke: ";
	cin >> kolom;
	if ((papan[3*baris+kolom-4] == 0) && (baris<=3) && (kolom<=3) && (baris>0) && (kolom>0)){
		papan[3*baris+kolom-4] = simbol;
		count = count + 1;
		cout<<" "<<count<<endl;
	}
	else{
		cout<<"Tempat tidak tersedia. Masukkan posisi yang lain";
		system("pause");
		pemain(simbol);
	}
}

void menu(){
	int perintah=1;
	while (perintah !=0 ){
		cls();
		cout<<"   TicTacToe Z\n";
		cout<<"-----------------------\n";
		cout<<"1. Player O vs Player X\n";
		cout<<"2. Player O vs Com X\n";
		cout<<"3. Com O vs Player X\n";
		cout<<"4. Com O vs Com X\n";
		cout<<"0. Exit\n\n";
		cout<<"Perintah: ";
		cin >> perintah;
		if (perintah!=0){
			init();			
		}
		switch (perintah){
			case 1: pvp();
			case 2: pvc();
			case 3: cvp();
			case 4: cvc();
		}
	}
	exit(0);
}

char ikec(int angka){
	if ((angka == -1) || (angka == -3)){
		return 'X';
	}
	else if((angka == 1)||(angka == 3)){
		return 'O';
	}
	else{
		return '_';
	}
}

#endif
