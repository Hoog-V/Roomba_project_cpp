# Acceptatietesten Roomba library

## Acceptatietest 1: Robot van richting laten veranderen

| te testen eisen: | **F-REQ 1 [MH]**: De Roomba library broncode moet het mogelijk maken om de richting van de Roomba te kunnen wijzigen in rechtdoor, achteruit of een bepaalde draairichting met meegegeven hoek. <br /> **F-REQ 2 [MH]:** De Roomba library moet de ingebouwde sensoren van de Roomba kunnen uitlezen.<br/> **F-REQ 3 [MH]:** De Roomba library broncode moet het mogelijk maken om de control modus van de Roomba aan te passen. De modi die het moet ondersteunen zijn: <br/> - Passive <br/> - Safe <br/> - Full|
|---|---|
| Te testen units/onderdelen  | In deze test wordt gekeken of het mogelijk is om een schoonmaakcyclus te starten op de Roomba. Hiervoor is/zijn de volgende unit(s) nodig: <br/> -**Start schoonmaak cyclus** <br/> -**Verander control modus** <br/><br/>Verander control modus is nodig om richting commando's succesvol uit te kunnen voeren.|
| Testvoorbereiding | Om de test uittevoeren is een computer of mcu nodig, een roomba, een kabel om aan te sluiten op de SCI poort van de roomba en de software library zelf met een stukje testcode.  |
| Testinvoer  | De testcode is hetgeen wat moet bepalen welke kant de Roomba opgaat. Het is van belang dat er geen objecten in de rijweg van de Roomba staan, objecten kunnen de richting van de Roomba laten veranderen. |
| Testuitvoer  | Veranderd de Roomba van richting na het starten van de Testcode? (Richting veranderd = ja/nee) -> **JA** <br /> Kan de richting van de Roomba veranderd worden in achteruit (Achteruit = ja/nee) -> **JA** <br /> Kan de richting van de Roomba veranderd worden in vooruit (Vooruit = ja/nee) -> **JA** <br /> Kan de software library de Roomba een bepaald aantal graden laten draaien? (Rotatie = ja/nee) -> **JA** <br/> Geeft het testprogramma geen foutmelding bij het uitlezen van de ingebouwde sensoren van de Roomba (Foutmelding = ja/nee) -> **NEE**|
| Criteria | - Richting veranderd = JA <br/> - Vooruit = JA <br /> - Achteruit = JA <br/> - Rotatie = JA <br/> - Foutmelding = NEE|
| Testprocedure  | **Stap 1:** Sluit de Roomba aan op de Computer of MCU met behulp van de SCI kabel. <br />**Stap 2:** Indien er getest wordt met een mcu: laad het testprogramma in op de MCU. <br /> Indien er getest wordt met een Computer, start het testprogramma op. <br /> **Stap 3:** Schakel de Roomba in <br /> **Stap 4:** Start het schoonmaakprogramma op de Roomba door op de Clean knop te drukken. <br /> **Stap 5:** Start de testprocedure op de MCU of Computer door op enter te klikken in de terminal of debug-console. <br /> **Stap 6:** Het testprogramma bepaald met behulp van de gelezen sensorwaarden of de library voldoet aan de criteria. Uiteraard blijft het ook mogelijk om het handmatig te testen, door de terminal/debug-console en de roomba in de gaten te houden.|
| Testgeslaagd?  |   |

<br/>

## Acceptatietest 2: Het starten van een schoonmaakronde en zoek dock modus

| te testen eisen: | **F-REQ 4 [SH]:** De Roomba library broncode moet het mogelijk maken om een schoonmaak ronde te starten op de Roomba. De schoonmaak modi die het moet ondersteunen zijn:<br/> - Normale schoonmaak <br />- volledige schoonmaak <br/> - schoonmaak op de huidige plek (spot cleaning) zijn. <br/><br/> **F-REQ 5 [SH]:** De Roomba library broncode moet het mogelijk maken om de dock modus van de Roomba te activeren.|
|---|---|
| Te testen units/onderdelen  | In deze test wordt de schoonmaak cyclus en seek dock functionaliteit van de software library getest. Hiervoor is/zijn de volgende unit(s) nodig: <br/> - **start schoonmaak cyclus**<br/>- **zoek dock**<br/><br/>Verander control modus is eventueel nodig om richting commando's succesvol uit te kunnen voeren.|
| Testvoorbereiding | Om de test uittevoeren is een computer of mcu nodig, een roomba, een kabel om aan te sluiten op de SCI poort van de roomba en de software library zelf met een stukje testcode.  |
| Testinvoer  | N.V.T. |
| Testuitvoer  | Start de Roomba met het normale schoonmaak programma? (normale schoonmaak = ja/nee) -> **JA** <br /> Start de Roomba met het volledige schoonmaak programma? (volledige schoonmaak = ja/nee) -> **JA** <br /> Start de robot met het Spot schoonmaak programma(Spot schoonmaak = ja/nee) -> **JA** <br /> Kan de dock modus van de Roomba geactiveerd worden? (Dock = ja/nee) -> **JA** <br /> Geeft het testprogramma tijdens het testen een foutmelding (Foutmelding = JA/NEE) -> **NEE** |
| Criteria | - Normale schoonmaak = JA <br/> - Volledige schoonmaak = JA <br /> - Spot schoonmaak = JA <br/> - Dock = JA <br/> - Foutmelding = NEE|
| Testprocedure  | **Stap 1:** Sluit de Roomba aan op de Computer of MCU met behulp van de SCI kabel. <br />**Stap 2:** Indien er getest wordt met een mcu: laad het testprogramma in op de MCU. <br /> Indien er getest wordt met een Computer, start het testprogramma op. <br /> **Stap 3:** Schakel de Roomba in <br />  **Stap 4:** Start de testprocedure op de MCU of Computer door op enter te klikken in de terminal of debug-console. <br /> **Stap 5:** De robot zal nu met een normale schoonmaak ronde beginnen. Controleer a.d.h.v. de ledjes op de Roomba of dit klopt <br/> **Stap 6:** Na 1 seconde zal het testprogramma de schoonmaak cyclus afbreken. Controleer of dit klopt. <br/> **Stap 7:** Druk op enter in de terminal of debug-console <br/> **Stap 8:** Herhaal de Stappen 5, 6, 7 voor de volledige schoonmaak, spot schoonmaak en dock modus.|
| Testgeslaagd?  |   |


## Acceptatietest 3:  Aan/uit zetten

| te testen eisen: | **F-REQ 6 [SH]:** De Roomba library broncode moet het mogelijk maken om de Roomba aan en uit te zetten. |
|---|---|
| Te testen units/onderdelen  | In deze test wordt de aan/uit functionaliteit van de software library getest. Hiervoor is/zijn de volgende unit(s) nodig: <br/> -**Zet Roomba aan/uit**<br/>  <br/>Verander control modus is eventueel nodig om richting commando's succesvol uit te kunnen voeren.|
| Testvoorbereiding | Om de test uit te voeren is een computer of mcu nodig, een roomba, een kabel om aan te sluiten op de SCI poort van de roomba en de software library zelf met een stukje testcode.  |
| Testinvoer  | Zorg dat de Roomba uitstaat voor het starten van de test. |
| Testuitvoer  | Gaat de Roomba aan (aan = JA/NEE) -> **JA** <br/> Gaat de Roomba uit (uit = JA/NEE) -> **JA** |
| Criteria | - aan = JA <br/> - uit = JA|
| Testprocedure  | **Stap 1:** Sluit de Roomba aan op de Computer of MCU met behulp van de SCI kabel. <br />**Stap 2:** Indien er getest wordt met een mcu: laad het testprogramma in op de MCU. <br /> Indien er getest wordt met een Computer, start het testprogramma op. <br /> **Stap 3:** Start de testprocedure op de MCU of Computer door op enter te klikken in de terminal of debug-console. <br /> **Stap 4:** De Roomba zal nu aangaan. <br/>Controleer a.d.h.v. de leds op de Roomba of de Roomba inschakelt. <br /> **Stap 5:** Na een seconde schakelt het testprogramma de Roomba uit. <br/>Controleer weer a.d.h.v. de leds op de Roomba of de Roomba uitschakelt.|
| Testgeslaagd?  |   |


## Acceptatietest 4:  Motoren manipuleren.

| te testen eisen: | **F-REQ 7 [SH]:** De Roomba library broncode moet het mogelijk maken om de motoren van de Roomba te manupileren. De motoren die het moet kunnen manupileren zijn:<br/>- Borstel<br/>- Zuiger<br/>- Zijborstel |
|---|---|
| Te testen units/onderdelen  | In deze test wordt de motoren manipulatie functionaliteit van de software library getest. Hiervoor is/zijn de volgende unit(s) nodig: <br/> -**Motoren manipuleren**<br/>  <br/>Verander control modus is eventueel nodig om richting commando's succesvol uit te kunnen voeren.|
| Testvoorbereiding | Om de test uit te voeren is een computer of mcu nodig, een roomba, een kabel om aan te sluiten op de SCI poort van de roomba en de software library zelf met een stukje testcode.  |
| Testinvoer  | N.V.T. |
| Testuitvoer  | Gaat de borstel motor aan? (borstel aan = JA/NEE) -> **JA** <br/> Gaat de borstel motor uit? (borstel uit = JA/NEE) -> **JA** <br/> Gaat de zuiger motor aan? (zuiger aan = JA/NEE) -> **JA** <br/> Gaat de zuiger motor uit? (zuiger uit = JA/NEE) -> **JA** <br/> Gaat de zijborstel motor aan? (zijborstel aan = JA/NEE) -> **JA** <br/> Gaat de zijborstel motor uit? (zijborstel uit = JA/NEE) -> **JA** <br/> Zijn de motoren regelbaar in snelheid? (regelbaar = JA/NEE) -> **JA** |
| Criteria | - borstel aan = JA <br/> - borstel uit = JA <br/> - zuiger aan = JA <br/> - zuiger uit = JA <br/> - zijborstel aan = JA <br/> - zijborstel uit = JA <br/> - regelbaar = JA|
| Testprocedure  | **Stap 1:** Sluit de Roomba aan op de Computer of MCU met behulp van de SCI kabel. <br />**Stap 2:** Indien er getest wordt met een mcu: laad het testprogramma in op de MCU. <br /> Indien er getest wordt met een Computer, start het testprogramma op. <br /> **Stap 3:** Zet de Roomba aan. <br/>**Stap 4:** Start de testprocedure op de MCU of Computer door op enter te klikken in de terminal of debug-console. <br /> **Stap 5:** Het testprogramma bepaald met behulp van de gelezen sensorwaarden of de library voldoet aan de criteria. Uiteraard blijft het ook mogelijk om het handmatig te testen, door de terminal/debug-console en de roomba in de gaten te houden.|
| Testgeslaagd?  |   |

## Acceptatietest 5:  Leds manipuleren

| te testen eisen: | **F-REQ 8 [SH]:** De Roomba library broncode moet het mogelijk maken om de leds van de Roomba te manupileren. De leds die het moet kunnen manipuleren zijn:<br/>- DD<br/>- MAX<br/>- CLEAN<br/>- SPOT<br/>- STATUS |
|---|---|
| Te testen units/onderdelen  | In deze test wordt de aan/uit functionaliteit van de software library getest. Hiervoor is/zijn de volgende unit(s) nodig: <br/> -**Zet Roomba aan/uit**<br/>  <br/>Verander control modus is eventueel nodig om richting commando's succesvol uit te kunnen voeren.|
| Testvoorbereiding | Om de test uit te voeren is een computer of mcu nodig, een roomba, een kabel om aan te sluiten op de SCI poort van de roomba en de software library zelf met een stukje testcode.  |
| Testinvoer  | Zorg dat de Roomba uitstaat voor het starten van de test. |
| Testuitvoer  | Gaat de DD Led aan (DD aan = JA/NEE) -> **JA** <br/> Gaat de DD Led uit (DD uit = JA/NEE) -> **JA** <br/> Gaat de MAX Led aan (MAX aan = JA/NEE) -> **JA** <br/> Gaat de MAX Led uit (MAX uit = JA/NEE) -> **JA** <br/> Gaat de CLEAN Led aan (CLEAN aan = JA/NEE) -> **JA** <br/> Gaat de CLEAN Led uit (CLEAN uit = JA/NEE) -> **JA** <br/> Gaat de SPOT Led aan (SPOT aan = JA/NEE) -> **JA** <br/> Gaat de SPOT Led uit (SPOT uit = JA/NEE) -> **JA** <br/>Gaat de STATUS Led aan (STATUS aan = JA/NEE) -> **JA** <br/> Gaat de STATUS Led uit (STATUS uit = JA/NEE) -> **JA** <br/>|
| Criteria | - DD aan = JA <br/> - DD uit = JA <br/>- MAX aan = JA <br/> - MAX uit = JA <br/>- CLEAN aan = JA <br/> - CLEAN uit = JA <br/>- SPOT aan = JA <br/> - SPOT uit = JA <br/>- STATUS aan = JA <br/> - STATUS uit = JA <br/>|
| Testprocedure  | **Stap 1:** Sluit de Roomba aan op de Computer of MCU met behulp van de SCI kabel. <br />**Stap 2:** Indien er getest wordt met een mcu: laad het testprogramma in op de MCU. <br /> Indien er getest wordt met een Computer, start het testprogramma op. <br /> **Stap 3:** Start de testprocedure op de MCU of Computer door op enter te klikken in de terminal of debug-console. <br /> **Stap 4:** Het testprogramma zal nu alle leds uitzetten <br/>Controleer of alle leds zijn uitgeschakelt. <br /> **Stap 5:** Het testprogramma zal nu elke led een voor een inschakelen en uitschakelen. Het testprogramma geeft daarbij aan wat de benaming van de led is en eventuele stappen die uitgevoerd moeten worden.|
| Testgeslaagd?  |   |

## Acceptatietest 6:  Baudrate aanpassen

| te testen eisen: | **F-REQ 9 [SH]:** De Roomba library broncode moet het mogelijk maken om de Baudrate van de SCI poort te wijzigen. De baudrates die het moet ondersteunen zijn:<br/> - 300 bps <br/>- 600 bps <br/>- 1200 bps <br/>- 2400 bps<br/>- 4800 bps<br/>- 9600 bps<br/>- 14400 bps<br/>- 19200 bps<br/>- 28800 bps<br/>- 38400 bps<br/>- 57600 bps<br/>- 115200 bps|
|---|---|
| Te testen units/onderdelen  | In deze test wordt de verander baudrate functionaliteit van de software library getest. Hiervoor is/zijn de volgende unit(s) nodig: <br/> -**Verander baudrate**<br/>  <br/>Verander control modus is eventueel nodig om richting commando's succesvol uit te kunnen voeren.|
| Testvoorbereiding | Om de test uit te voeren is een computer of mcu nodig, een roomba, een kabel om aan te sluiten op de SCI poort van de roomba en de software library zelf met een stukje testcode.  |
| Testinvoer  | Controleer alvorens de test dat de computer of MCU alle bovenstaande baudrates ondersteund  |
| Testuitvoer  | Ondersteund 300 bps? (300 bps = JA/NEE) -> **JA** <br/>Ondersteund 600 bps? (600 bps = JA/NEE) -> **JA** <br/> Ondersteund 1200 bps? (1200 bps = JA/NEE) -> **JA** <br/> Ondersteund 2400 bps? (2400 bps = JA/NEE) -> **JA** <br/> Ondersteund 4800 bps? (4800 bps = JA/NEE) -> **JA** <br/> Ondersteund 9600 bps? (9600 bps = JA/NEE) -> **JA** <br/> Ondersteund 14400 bps? (14400 bps = JA/NEE) -> **JA** <br/> Ondersteund 19200 bps? (19200 bps = JA/NEE) -> **JA** <br/> Ondersteund 28800 bps? (28800 bps = JA/NEE) -> **JA** <br/> Ondersteund 38400 bps? (38400 bps = JA/NEE) -> **JA** <br/>Ondersteund 57600 bps? (57600 bps = JA/NEE) -> **JA** <br/>Ondersteund 115200 bps? (115200 bps = JA/NEE) -> **JA** <br/>|
| Criteria | - 300 bps = JA <br/> - 600 bps = JA <br/>- 1200 bps = JA <br/> - 2400 bps = JA <br/>- 4800 bps = JA <br/> - 9600 bps = JA <br/>- 14400 bps = JA <br/> - 19200 bps = JA <br/>- 28800 bps = JA <br/> - 38400 bps = JA <br/>- 57600 bps = JA <br/>- 115200 bps = JA <br/>|
| Testprocedure  | **Stap 1:** Sluit de Roomba aan op de Computer of MCU met behulp van de SCI kabel. <br />**Stap 2:** Indien er getest wordt met een mcu: laad het testprogramma in op de MCU. <br /> Indien er getest wordt met een Computer, start het testprogramma op. <br /> **Stap 3:** Start de testprocedure op de MCU of Computer door op enter te klikken in de terminal of debug-console. <br /> **Stap 4:** Het testprogramma zal nu alle leds uitzetten <br/>Controleer of alle leds zijn uitgeschakelt. <br /> **Stap 5:** Het testprogramma zal nu elke baudrate uittesten. Het testprogramma geeft vervolgens aan wat de testresultaten zijn. |
| Testgeslaagd?  |   |

## Acceptatietest 7:  Noten afspelen

| te testen eisen: | **F-REQ 10 [SH]:** De Roomba library broncode moet het mogelijk maken om noten af te spelen op de Roomba. |
|---|---|
| Te testen units/onderdelen  | In deze test wordt de noot afspeel functionaliteit van de software library getest. Hiervoor is/zijn de volgende unit(s) nodig: <br/> -**Noten afspelen**<br/>  <br/>Verander control modus is eventueel nodig om richting commando's succesvol uit te kunnen voeren.|
| Testvoorbereiding | Om de test uit te voeren is een computer of mcu nodig, een roomba, een kabel om aan te sluiten op de SCI poort van de roomba en de software library zelf met een stukje testcode.  |
| Testinvoer  | N.V.T. |
| Testuitvoer  | Speelt de Roomba noten af (Noten = JA/NEE) -> **JA** <br/> Kan het opgeslagen worden en opgeroepen worden uit geheugen (geheugen = JA/NEE) -> **JA** |
| Criteria | - Noten = JA <br/> - geheugen = JA|
| Testprocedure  | **Stap 1:** Sluit de Roomba aan op de Computer of MCU met behulp van de SCI kabel. <br />**Stap 2:** Indien er getest wordt met een mcu: laad het testprogramma in op de MCU. <br /> Indien er getest wordt met een Computer, start het testprogramma op. <br />**Stap 3:** Zet de Roomba aan<br/> **Stap 4:** Start de testprocedure op de MCU of Computer door op enter te klikken in de terminal of debug-console. <br /> **Stap 5:** Het testprogramma slaat de noten op volgorde op in het geheugen en roept ze vervolgens op. Het testprogramma vraagt na zestien noten of alle noten te horen waren. <br/>Typ hier Ja of nee om de volgende 16 noten te kunnen beluisteren.|
| Testgeslaagd?  |   |


## Acceptatietest 8: Controleer code conventies

| te testen eisen: | **NF-REQ 1 [MH]:** De Roomba library moet zo platform onafhankelijk mogelijk geschreven worden. <br/> <br/>**NF-REQ 2 [MH]:** De Roomba library moet in de programmeertaal C++ geschreven worden. |
|---|---|
| Te testen units/onderdelen  | In deze test wordt gecontroleerd of de broncode van de geschreven software library voldoet aan de code conventies opgesteld in NF-REQ1 en NF-REQ2.|
| Testvoorbereiding | Om de test uit te voeren is een computer nodig en de software library zelf.  |
| Testinvoer  | N.V.T. |
| Testuitvoer  | Bevat de library alleen maar cpp source files (cpp source file = JA/NEE) -> **JA** <br/> Bevat de library cpp functies (cpp functies = JA/NEE) -> **JA** <br/> Bevat de library platform afhankelijke functies (platform afhankelijk = JA/NEE) -> **NEE**|
| Criteria | - cpp source file = JA <br/> - cpp functies = JA <br/> - platform afhankelijk = NEE|
| Testprocedure  | Controleer de software library op aanwezigheid van cpp functionaliteit, cpp headers en platform afhankelijke functies.|
| Testgeslaagd?  |   |