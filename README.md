# 1-oji objektinio programavimo užduotis

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

## Užduoties formuluotė

- Parašykite programą, kuri nuskaito šiuos studentų duomenis:
    - vardą ir pavardę.
    - n atliktų namų darbų (nd) rezultatus (10-balėje sistemoje), o taip pat egzamino (egz) rezultatą.
    - Tuomet iš šių duomenų, suskaičiuoja galutinį balą (galutinis):
        - Galutinis = 0.4 * (vidurkis arba mediana) + 0.6 * egzaminas
