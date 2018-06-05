/*

Napi�ite program koji radi slijede�e:

S tipkovnice u�itava prirodni broj M - broj radnika koji rade u trgovini.

Zatim u�itava M skupina podataka o radnicima i upisuje direktnim pristupom u neformatiranu datoteku.

Radnik je struktura koja se sastoji od slijede�ih podataka:
- �ifra radnika, troznamenkasti prirodni broj,
- ime i prezime, string od 30 znakova uklju�uju�i praznine,
- godina prvog zaposlenja, �etveroznamenkasti broj > 1970.
- osnovica pla�e, realni pozitivni broj.

�ifra radnika je pozicija strukture radnika u datoteci pa se ne smije ponavljati.
U slu�aju uno�enja �ifre koja ve� postoji u datoteci � ispisati odgovaraju�u poruku i tra�iti ponovni upis �ifre.

Nakon upisa radnika datoteku zatvoriti i otvoriti za �itanje.

Zatim, pro�itati sve podatke o radnicima iz datoteke i izra�unati koliko je ukupno potrebno za pla�e radnika,
ispisuju�i pri tome podatke o radnicima na zaslon monitora sa iznosom pla�e svakog radnika.

Pla�a je zbroj osnovice i dodatka na sta�.
Dodatak na sta� je umno�ak osnovice, godina radnog sta�a do trenutka ra�unanja i koeficijenta 0.005.

Na kraju ispisati ukupni iznos za pla�e, sve to�no prema prikazanom primjeru:

Ime i prezime           God. staza     Osnovica     Dod.staz       Placa
Stanko Bo�i�		   20           3250.00      325.00       3575.00
Franjo Jozi�               10           4000.00      200.00       4200.00

Datoteku na kraju zatvoriti i ispisati koliko je zapisa o radnicima iz nje pro�itano.

Uputa: zapis o radniku definirati kao strukturu.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {

	int M, i, j, velicina_datoteke = 0, broj_zapisa = 0, sifra = 0, sifra_postoji = 0, broj_godina_radnog_staza = 0, ukupno_radnika = 0;
	float dodatak_na_staz = 0, placa = 0, ukupne_place = 0;

	// Struktura unosa radnika
	struct unos {
		int sifra;
		char ime_prezime[31];
		int godina_prvog_zaposlenja;
		float osnovica_place;
	} radnik, provjera_sifre_radnika;

	// Unos broja radnika
	printf("Broj radnika: ");
	scanf("%d", &M);

	// Unos radnika
	for (i = 1; i <= M; i++) {

		// Redni broj radnika
		printf("\nRADNIK %d:\n", i);

		// Unos �ifre radnika
		do {

			printf("Sifra (3 znamenke u pozitivi): ");

			// Sve unose spremamo u stukturu datoteke
			scanf("%d%*c", &radnik.sifra);

			// Provjeri da li je pozitivan troznamenkasti broj
			if ((radnik.sifra > 99) && (radnik.sifra < 1000)) {

				// Provjera da li �ifra ve� postoji u datoteci

				// Spremimo unesenu �ifru u novu varijablu
				sifra = radnik.sifra;

				// Pretpostavljamo uvijek da �ifra ne postoji, ukoliko pogrije�imo vrtimo se u krug dok �ifra ne postane jedinstvena
				sifra_postoji = 0;

				// Otvori datoteku za �itanje kao binarnu, ukoliko ne postoji ili je nedostupna iz nekog razloga javi gre�ku
				FILE *datoteka = fopen("radnici.dat", "wb");
				if (datoteka == NULL) printf("Datoteka ne postoji!\n");

				// Saznaj koliko zapisa u datoeci ima kako bi znao zaustaviti kasnije petlju

				// Sko�i do kraja datoteke
				fseek(datoteka, 0L, SEEK_END);

				// Spremi veli�inu datoteke u bytovima
				velicina_datoteke = ftell(datoteka);

				// Spremi koliko zapisa imamo tako da podijeli� ukupnu veli�inu daoteke s pojedina�nim
				broj_zapisa = velicina_datoteke / sizeof(provjera_sifre_radnika);

				// Vrati se na po�etak datoteke
				fseek(datoteka, 0, SEEK_SET);

				// Saznali smo koliko zapisa imamo pa mo�emo u petlju kroz sve njih
				for (j = 0; j<broj_zapisa; j++) {

					// Zanimaju nas samo �ifre pa njih is�itavamo
					fread(&provjera_sifre_radnika, sizeof(provjera_sifre_radnika), 1, datoteka);

					// Ukoliko prona�emo unesenu �ifru u datoteci, zapamtimo to tako da promijenimo po�etnu pretpostavku da �ifra ne postoji
					if (provjera_sifre_radnika.sifra == sifra) sifra_postoji = 1;

				}

				// Zatvorimo datoteku
				fclose(datoteka);

				// Ukoliko nismo prona�li �ifru u datoteci, zavr�avamo s do petljom odnosno unosom �ifre radnika, u suprotnom ispi�emo gre�ku i idemo ispo�etka
				if (sifra_postoji == 0) break;
				else printf("Sifra vec postoji!\n");

			}

			else printf("Sifra mora biti pozitivan troznamenkasti broj!\n");

		} while (1);

		// Unos imena i prezimena
		do {

			printf("Ime i prezime: ");

			// Podr�i unos razmaka, uz naravno velika i mala slova u jedan string
			scanf("%[a-zA-Z ]s", radnik.ime_prezime);

			// Ukoliko ime i prezime ima manje od 30 znakovova idemo dalje, ukoliko ne ponavljamo ovaj unos
			if (strlen(radnik.ime_prezime) < 30) break;
			else printf("Ime i prezime ne smiju imati vise od 30 znakova!\n");

		} while (1);

		// Unos godine prvog zaposlenja
		do {

			printf("Godina prvog zaposlenja: ");
			scanf("%d%*c", &radnik.godina_prvog_zaposlenja);

			// Provjera raspona godina
			if ((radnik.godina_prvog_zaposlenja > 1970) && (radnik.godina_prvog_zaposlenja < 2013)) break;
			else printf("Godina prvog zaposlenja mora biti veca od 1970 i manja od 2013!\n");

		} while (1);

		// Unos osnovice pla�e
		do {

			printf("Osnovica place: ");
			scanf("%f%*c", &radnik.osnovica_place);

			// Provjeri pozitivu
			if (radnik.osnovica_place > 0) break;
			else printf("Osnovica place mora biti pozitivna!\n");

		} while (1);

		// Zapi�i sve gore uneseno u datoteku

		// Otvori datoteku za dodavanje binarno
		FILE *datoteka = fopen("radnici.bin", "ab");
		if (datoteka == NULL) printf("Datoteka ne postoji!\n");

		// Zapi�i sve gore strukturirano unesene podatke u datoteku te ju potom zatvori
		fwrite(&radnik, sizeof(radnik), 1, datoteka);
		fclose(datoteka);

	}

	// Otvori datoteku i kreni s ra�unanjem te ispisima na ekran

	// Otvori datoteku za �itanje binarno
	FILE *datoteka = fopen("radnici.bin", "rb");
	if (datoteka == NULL) printf("Datoteka ne postoji!\n");

	// Ispis zaglavlja
	printf("\n%-17s | %-12s | %-12s | %-12s | %-12s \n", "Ime i prezime", "Staz", "Osnovica", "Dodatak", "Placa");

	// Pro�i kroz sve artikle u datoteci radi ra�unanja i ispisa
	while (fread(&radnik, sizeof(radnik), 1, datoteka) != 0) {

		// Izra�unaj broj godina radnog sta�a
		broj_godina_radnog_staza = 2013 - radnik.godina_prvog_zaposlenja;

		// Izra�unaj dodatak na sta�
		dodatak_na_staz = radnik.osnovica_place * (float)broj_godina_radnog_staza * 0.005;

		// Izra�unaj pla�u
		placa = radnik.osnovica_place + dodatak_na_staz;

		// Izra�unaj ukupne pla�e
		ukupne_place = ukupne_place + placa;

		// Ispi�i svakog pojedina�nog radnika
		printf("%-17s | %-12d | %-12.2f | %-12.2f | %-12.2f \n", radnik.ime_prezime, broj_godina_radnog_staza, radnik.osnovica_place, dodatak_na_staz, placa);

		// Broji koliko ukupno radnika ima
		ukupno_radnika++;

	}

	// Ispi�i ukupan iznos pla�a
	printf("\nUkupan iznos placa: %.2f \n", ukupne_place);

	// Ispi�i ukupni broj radnika
	printf("Broj radnika: %d \n\n", ukupno_radnika);

	// Zatvori datoteku
	fclose(datoteka);

	return 0;

}