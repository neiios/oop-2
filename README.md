# 1-oji objektinio programavimo užduotis

## Versijos v0.5 aprašymas

### Testavimo sistema:
- CPU: AMD Ryzen 5 1600 3.6Ghz
- RAM: 16GB 3200MHz
- SSD: 1TB SATA

### Testavimo rezultatai:

| Vector                      | 1000          | 10000         | 100000      | 1000000    | 10000000  |
|-----------------------------|---------------|---------------|-------------|------------|-----------|
| Failo nuskaitymo laikas:    | 0.00156437 s  | 0.01364 s     | 0.139249 s  | 1.38866 s  | 14.1488 s |
| Rūšiavimo laikas:           | 0.000140243 s | 0.00138938 s  | 0.0174134 s | 0.227699 s | 2.82822 s |
| Vektorių padalijimo laikas: | 0.000059392 s | 0.000679204 s | 0.0113564 s | 0.186192 s | 2.22674 s |
| Pilnas laikas:              | 0.00176401 s  | 0.0157086 s   | 0.168019 s  | 1.80255 s  | 19.2038 s |

| List                        | 1000          | 10000         | 100000      | 1000000    | 10000000  |
|-----------------------------|---------------|---------------|-------------|------------|-----------|
| Failo nuskaitymo laikas:    | 0.00133846 s  | 0.0133157 s   | 0.136074 s  | 1.44558 s  | 14.6822 s |
| Rūšiavimo laikas:           | 0.000077305 s | 0.00111127 s  | 0.0336137 s | 0.549307 s | 9.57814 s |
| Vektorių padalijimo laikas: | 0.000054452 s | 0.000631104 s | 0.0202938 s | 0.222197 s | 2.37254 s |
| Pilnas laikas:              | 0.00147022 s  | 0.0150581 s   | 0.189982 s  | 2.21708 s  | 26.6329 s |

| Deque                       | 1000          | 10000         | 100000      | 1000000    | 10000000  |
|-----------------------------|---------------|---------------|-------------|------------|-----------|
| Failo nuskaitymo laikas:    | 0.00131495 s  | 0.0132299 s   | 0.164927 s  | 1.4533 s   | 15.1485 s |
| Rūšiavimo laikas:           | 0.000162264 s | 0.00175371 s  | 0.0269816 s | 0.303426 s | 4.18401 s |
| Vektorių padalijimo laikas: | 0.000033813 s | 0.000322725 s | 0.0154212 s | 0.121304 s | 1.78823 s |
| Pilnas laikas:              | 0.00151102 s  | 0.0153063 s   | 0.20733 s   | 1.87803 s  | 21.1207 s |

### Išvados
Vector konteineris veikia greičiau nei List ir Deque, kai studentų skaičius yra daugiau nei 100000. 
Tačiau, kai studentų skaičius yra mažas, List ir Deque konteineriai veikia greičiau.

## Versijos v0.4 aprašymas
Programos veikimo laikas, kai kiekvienas studentas turi po 10 pažymių:

|                            | 1000        | 10000       | 100000    | 1000000  | 10000000 |
|----------------------------|-------------|-------------|-----------|----------|----------|
| Failo nuskaitymo laikas    | 0.00145373  | 0.0136561   | 0.141471  | 1.38757  | 14.2994  |
| Rūšiavimo laikas           | 0.000123762 | 0.00133734  | 0.0176121 | 0.222841 | 2.75276  |
| Vektorių padalijimo laikas | 0.000049613 | 0.000700154 | 0.0116927 | 0.187523 | 2.18616  |
| Įrašymo į failus laikas    | 0.000815409 | 0.00681796  | 0.0699192 | 0.715964 | 7.29826  |
| Pilnas laikas              | 0.00244251  | 0.0225115   | 0.240696  | 2.51389  | 26.5366  |

## Versijos v0.3 aprašymas
Pabaigta programos v0.3 versija. Programos struktūra buvo pertvarkyta, visi source failai dabar yra saugomi src aplanke. 
Try-catch blokas yra panaudotas failo atidarymui tikrinti.

Paleisti galima komandinėje eilutėje su g++ kompiliuojant tinkamus failus, arba kaip CMake projektą.

## Versijos v0.2 aprašymas

Pabaigta programos v0.2 versija. Duomenis galima nuskaityti iš failo. 
Outputas yra gražiai išlygiuotas ir studentai yra surūšiuoti pagal pavardes.

Paleisti galima komandinėje eilutėje su g++ kompiliuojant tinkamą failą, arba kaip CMake projektą.

## Versijos v0.1 aprašymas

Pabaigta programos v0.1 versija. Studentų namų darbai gali būti saugomi arba į C masyvą, arba į vektorių.

Paleisti galima komandinėje eilutėje su g++ kompiliuojant tinkamą failą, arba kaip CMake projektą.
