# Roomba C++ library
---

Welkom in de Roomba library repo. Deze library is bedoeld als een interface om de Roomba makkelijk te kunnen bedienen
vanaf computer, esp of andere target. 

De library maakt gebruik van CMake om de build files te genereren, hierdoor is er meer vrijheid om te kiezen waarop 
(welk besturingssysteem) en waarin (Welke teksteditor/ide) te programmeren. Voor een snelgids om de ontwikkelomgeving
op te zetten onder [Windows](/Documentatie/MD/Omgeving_opzetten.md). 

De meest gebruikte ide's zijn:
- VSCode
- CLion
- Visual Studio
Maar gebruik vooral wat jezelf fijn vindt :)


## Bookmarks

---
### Code standaarden en regels
- [Code standaarden](/Documentatie/MD/Code_standaarden.md)

### Programma van eisen en acceptatietesten
- [Eisen van de library](/Documentatie/MD/Eisen%20ROOMBA%20lib.md)
- [Functies van de library](/Documentatie/MD/Functies%20ROOMBA%20lib.md)
- [Acceptatietesten](/Documentatie/MD/Acceptatietesten%20ROOMBA%20Lib.md)

### UML STUFF
- [Use case diagram]()
- [Class diagram](/Documentatie/Diagrammen/Roomba%20class%20diagram.drawio.pdf)


## Regels over bijdragen aan de repo

---

- Werk altijd in een aparte branch als je veranderingen wilt maken of een nieuwe feature wilt toevoegen.
  Op deze manier worden fouten bij het mergen van bestanden voorkomen en is het makkelijker om bij pull requests
  een code review te doen.
- Volg de [Code standaarden](/Documentatie/MD/Code_standaarden.md)
- Maak een test alvorens het maken van een nieuwe feature.
  Dan weet je zeker dat je niet vergeet de functie te testen.
- Maak pull requests aan als je klaar bent met het schrijven van een feature of refactoren.
  Op deze manier kunnen mensen nog eventjes de code controleren voordat het in de main komt.
  
## Testen

---

Bij de Roomba library zit nu een google test library ingevoegd. Deze wordt automatisch ingevoegd als de recursive of clone with submodules optie is gekozen bij het clonen van deze repo. Naast dat je zelf kan testen, test ook github automatisch alle code met behulp van ctest (inbegrepen bij cmake) met github workflows.
