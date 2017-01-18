#include <iostream.h>
#include <stdlib.h>

int papan[9];
int count;

void menu();
void init();
void jalan(int simbol, int jenis);
void pemain(int simbol);
void komp(int simbol);
void komJalan(int simbol);
void komTaktik(int simbol, int taktik = 1);
void tampil();
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
	cout<<"Giliran "<<ikec(simbol)<<"\n";
	_sleep(1000);
	komTaktik(simbol);
	count++;
}

void komJalan(int simbol){
	bool sudah = false;
	bool ulang = true;
	bool kosong = false;
	int a = rand() % 5;
	while (ulang && !kosong){
		for (int i=0; i<9; i+=2){
			if(papan[i] == 0){
				kosong = true;
				break;
			}
		}
		if (kosong && (papan[2*a] == 0)){
			papan[2*a] = simbol; 
			ulang = false; 
			sudah = true;
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

void mulai(int perintah){
	int simbol = -1;
	int jenis; //1 player, -1 komputer
	if (perintah <= 2) jenis = 1;
	else if (perintah >= 3) jenis = -1;
	while ((count<9) && (!cekMenang())){
		tampil();
		simbol = -simbol;
		switch (perintah){
			case 1: jalan(simbol, jenis); break;
			case 2: jenis = -jenis; jalan(simbol, jenis); break;
			case 3: jenis = -jenis; jalan(simbol, jenis); break;
			case 4: jalan(simbol, jenis); break;
		}
	}
	tampil();
	if (cekMenang()){
		cout<<endl<<ikec(simbol)<<" Menang!";
	}
	else if (count == 9){
		cout<<endl<<"XO Seri OX";
	}
	cout<<endl;
	system("pause");
	menu();
}

void tampil(){
	system("cls");
	cout<<"\n\t  \t1\t \t2\t \t3\t \n";
	cout<<"\t +--------------+---------------+---------------+\n";
	for(int i = 0 ; i < 3 ; i++){
		cout<<"\t |\t \t|\t \t|\t \t|\n\t |\t \t|\t \t|\t \t|\n";
		cout<<"\t"<<i+1<<"|";
		for(int j = 0 ; j < 3 ; j++){
			cout<<"\t"<<ikec(papan[i*3+j])<<"\t|";
		}
		cout<<"\n\t |\t \t|\t \t|\t \t|\n\t |\t \t|\t \t|\t \t|\n";
		cout<<"\t +--------------+---------------+---------------+\n";
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
	cout<<"Giliran "<<ikec(simbol)<<"\n";
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
		cout<<"Tempat tidak tersedia. Masukkan posisi yang lain\n";
		system("pause");
		tampil();
		pemain(simbol);
	}
}

void menu(){
	int perintah=1;
	while (perintah !=0 ){
		system("cls");
		cout<<"\n--------------------------------------------\n";
		cout<<"\tTicTacToe created by Z-Fikar\n";
		cout<<"============================================\n";
		cout<<" 1. Player O vs Player X\n";
		cout<<" 2. Player O vs Com X\n";
		cout<<" 3. Com O vs Player X\n";
		cout<<" 4. Com O vs Com X\n";
		cout<<" 0. Exit\n";
		cout<<"--------------------------------------------\n";
		cout<<"Perintah: ";
		cin >> perintah;
		if (perintah!=0){
			init();
			mulai(perintah);
		}
		//switch (perintah){
		//	case 1: pvp();
		//	case 2: pvc();
		//	case 3: cvp();
		//	case 4: cvc();
		//}
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

int main(){
	menu();
	return 0;
}
