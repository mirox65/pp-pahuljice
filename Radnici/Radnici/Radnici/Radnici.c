/*

Napišite program koji radi slijedeæe:

S tipkovnice uèitava prirodni broj M - broj radnika koji rade u trgovini.

Zatim uèitava M skupina podataka o radnicima i upisuje direktnim pristupom u neformatiranu datoteku.

Radnik je struktura koja se sastoji od slijedeæih podataka:
- šifra radnika, troznamenkasti prirodni broj,
- ime i prezime, string od 30 znakova ukljuèujuæi praznine,
- godina prvog zaposlenja, èetveroznamenkasti broj > 1970.
- osnovica plaæe, realni pozitivni broj.

Šifra radnika je pozicija strukture radnika u datoteci pa se ne smije ponavljati.
U sluèaju unošenja šifre koja veæ postoji u datoteci – ispisati odgovarajuæu poruku i tražiti ponovni upis šifre.

Nakon upisa radnika datoteku zatvoriti i otvoriti za èitanje.

Zatim, proèitati sve podatke o radnicima iz datoteke i izraèunati koliko je ukupno potrebno za plaæe radnika,
ispisujuæi pri tome podatke o radnicima na zaslon monitora sa iznosom plaæe svakog radnika.

Plaæa je zbroj osnovice i dodatka na staž.
Dodatak na staž je umnožak osnovice, godina radnog staža do trenutka raèunanja i koeficijenta 0.005.

Na kraju ispisati ukupni iznos za plaæe, sve toèno prema prikazanom primjeru:

Ime i prezime           God. staza     Osnovica     Dod.staz       Placa
Stanko Božiæ		   20           3250.00      325.00       3575.00
Franjo Joziæ               10           4000.00      200.00       4200.00

Datoteku na kraju zatvoriti i ispisati koliko je zapisa o radnicima iz nje proèitano.

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

		// Unos šifre radnika
		do {

			printf("Sifra (3 znamenke u pozitivi): ");

			// Sve unose spremamo u stukturu datoteke
			scanf("%d%*c", &radnik.sifra);

			// Provjeri da li je pozitivan troznamenkasti broj
			if ((radnik.sifra > 99) && (radnik.sifra < 1000)) {

				// Provjera da li šifra veæ postoji u datoteci

				// Spremimo unesenu šifru u novu varijablu
				sifra = radnik.sifra;

				// Pretpostavljamo uvijek da šifra ne postoji, ukoliko pogriješimo vrtimo se u krug dok šifra ne postane jedinstvena
				sifra_postoji = 0;

				// Otvori datoteku za èitanje kao binarnu, ukoliko ne postoji ili je nedostupna iz nekog razloga javi grešku
				FILE *datoteka = fopen("radnici.dat", "wb");
				if (datoteka == NULL) printf("Datoteka ne postoji!\n");

				// Saznaj koliko zapisa u datoeci ima kako bi znao zaustaviti kasnije petlju

				// Skoèi do kraja datoteke
				fseek(datoteka, 0L, SEEK_END);

				// Spremi velièinu datoteke u bytovima
				velicina_datoteke = ftell(datoteka);

				// Spremi koliko zapisa imamo tako da podijeliš ukupnu velièinu daoteke s pojedinaènim
				broj_zapisa = velicina_datoteke / sizeof(provjera_sifre_radnika);

				// Vrati se na poèetak datoteke
				fseek(datoteka, 0, SEEK_SET);

				// Saznali smo koliko zapisa imamo pa možemo u petlju kroz sve njih
				for (j = 0; j<broj_zapisa; j++) {

					// Zanimaju nas samo šifre pa njih isèitavamo
					fread(&provjera_sifre_radnika, sizeof(provjera_sifre_radnika), 1, datoteka);

					// Ukoliko pronaðemo unesenu šifru u datoteci, zapamtimo to tako da promijenimo poèetnu pretpostavku da šifra ne postoji
					if (provjera_sifre_radnika.sifra == sifra) sifra_postoji = 1;

				}

				// Zatvorimo datoteku
				fclose(datoteka);

				// Ukoliko nismo pronašli šifru u datoteci, završavamo s do petljom odnosno unosom šifre radnika, u suprotnom ispišemo grešku i idemo ispoèetka
				if (sifra_postoji == 0) break;
				else printf("Sifra vec postoji!\n");

			}

			else printf("Sifra mora biti pozitivan troznamenkasti broj!\n");

		} while (1);

		// Unos imena i prezimena
		do {

			printf("Ime i prezime: ");

			// Podrži unos razmaka, uz naravno velika i mala slova u jedan string
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

		// Unos osnovice plaæe
		do {

			printf("Osnovica place: ");
			scanf("%f%*c", &radnik.osnovica_place);

			// Provjeri pozitivu
			if (radnik.osnovica_place > 0) break;
			else printf("Osnovica place mora biti pozitivna!\n");

		} while (1);

		// Zapiši sve gore uneseno u datoteku

		// Otvori datoteku za dodavanje binarno
		FILE *datoteka = fopen("radnici.bin", "ab");
		if (datoteka == NULL) printf("Datoteka ne postoji!\n");

		// Zapiši sve gore strukturirano unesene podatke u datoteku te ju potom zatvori
		fwrite(&radnik, sizeof(radnik), 1, datoteka);
		fclose(datoteka);

	}

	// Otvori datoteku i kreni s raèunanjem te ispisima na ekran

	// Otvori datoteku za èitanje binarno
	FILE *datoteka = fopen("radnici.bin", "rb");
	if (datoteka == NULL) printf("Datoteka ne postoji!\n");

	// Ispis zaglavlja
	printf("\n%-17s | %-12s | %-12s | %-12s | %-12s \n", "Ime i prezime", "Staz", "Osnovica", "Dodatak", "Placa");

	// Proði kroz sve artikle u datoteci radi raèunanja i ispisa
	while (fread(&radnik, sizeof(radnik), 1, datoteka) != 0) {

		// Izraèunaj broj godina radnog staža
		broj_godina_radnog_staza = 2013 - radnik.godina_prvog_zaposlenja;

		// Izraèunaj dodatak na staž
		dodatak_na_staz = radnik.osnovica_place * (float)broj_godina_radnog_staza * 0.005;

		// Izraèunaj plaæu
		placa = radnik.osnovica_place + dodatak_na_staz;

		// Izraèunaj ukupne plaæe
		ukupne_place = ukupne_place + placa;

		// Ispiši svakog pojedinaènog radnika
		printf("%-17s | %-12d | %-12.2f | %-12.2f | %-12.2f \n", radnik.ime_prezime, broj_godina_radnog_staza, radnik.osnovica_place, dodatak_na_staz, placa);

		// Broji koliko ukupno radnika ima
		ukupno_radnika++;

	}

	// Ispiši ukupan iznos plaæa
	printf("\nUkupan iznos placa: %.2f \n", ukupne_place);

	// Ispiši ukupni broj radnika
	printf("Broj radnika: %d \n\n", ukupno_radnika);

	// Zatvori datoteku
	fclose(datoteka);

	return 0;

}