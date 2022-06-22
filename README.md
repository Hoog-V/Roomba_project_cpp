# Roomba C++ library
---

Welkom in de Roomba library repo. Deze library is bedoeld als een interface om de Roomba makkelijk te kunnen bedienen
vanaf computer, esp of andere target. 


## Bookmarks

---
### Code standaarden en regels
- [Code standaarden](https://hoog-v.github.io/Roomba_project_cpp/html/6.html)

### Programma van eisen en acceptatietesten
- [Eisen van de library](https://hoog-v.github.io/Roomba_project_cpp/html/2.html#autotoc_md0)
- [Acceptatietesten](https://hoog-v.github.io/Roomba_project_cpp/html/3.html)

### UML STUFF
- [Use case diagram](https://hoog-v.github.io/Roomba_project_cpp/html/4.html)
- [Class diagram](https://hoog-v.github.io/Roomba_project_cpp/html/5.html)



## Functies van de library
- Instellen van cleaningmodes Roomba
- Veranderen rijrichting Roomba
- Aan- en uitzetten van de Roomba
- Aanpassen van leds op de Roomba
- Afspelen van noten op de Roomba
- Opslaan van noten in de songslots van de Roomba
- Uitlezen van de sensoren
- Het aan- of uitzetten van de stofzuiger motoren
- Het aanpassen van de controlmode van de Roomba

## Regels over bijdragen aan de repo

---
De library maakt gebruik van CMake om de build files te genereren, hierdoor is er meer vrijheid om te kiezen waarop
(welk besturingssysteem) en waarin (Welke teksteditor/ide) te programmeren. Voor een snelgids om de ontwikkelomgeving
op te zetten onder [Windows](/docs/DocPages/Omgeving_opzetten.md).

De meest gebruikte ide's zijn:
- VSCode
- CLion
- Visual Studio
Maar gebruik vooral wat jezelf fijn vindt >:)

Voor de regels over het bijdragen aan de repo zie het kopje:
[Bijdragen](https://hoog-v.github.io/Roomba_project_cpp/html/6.html) in de github pages wiki van deze repo.

Daar staan de code- en git regels in.


## Testen

---

Bij de Roomba library zit nu een google test library ingevoegd. Deze wordt automatisch ingevoegd als de recursive of clone with submodules optie is gekozen bij het clonen van deze repo. Naast dat je zelf kan testen, test ook github automatisch alle code met behulp van ctest (inbegrepen bij cmake) met github workflows.
