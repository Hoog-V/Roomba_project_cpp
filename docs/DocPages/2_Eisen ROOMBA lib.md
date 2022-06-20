@page 2 MoScoW eisen
@tableofcontents

# Eisen Roomba lib m.b.v. MOSCOW

**F-REQ 1 [MH]:** De Roomba library broncode moet het mogelijk maken om de richting van de Roomba te kunnen wijzigen in rechtdoor, achteruit of een bepaalde draairichting met meegegeven hoek.

**F-REQ 2 [MH]:** De Roomba library moet de ingebouwde sensoren van de Roomba kunnen uitlezen.

**F-REQ 3 [MH]:** De Roomba library broncode moet het mogelijk maken om de control modus van de Roomba aan te passen. De modi die het moet ondersteunen zijn:
- Passive
- Safe
- Full


**F-REQ 4 [SH]:** De Roomba library broncode moet het mogelijk maken om een schoonmaak ronde te starten op de Roomba. De schoonmaak modi die het moet ondersteunen zijn:
- Normale schoonmaak
- volledige schoonmaak
- schoonmaak op de huidige plek (spot cleaning) zijn.


**F-REQ 5 [SH]:** De Roomba library broncode moet het mogelijk maken om de dock modus van de Roomba te activeren.

**F-REQ 6 [SH]:** De Roomba library broncode moet het mogelijk maken om de Roomba aan en uit te zetten.

**F-REQ 7 [SH]:** De Roomba library broncode moet het mogelijk maken om de motoren van de Roomba te manipuleren. De motoren die het moet kunnen manipuleren zijn:
- Borstel
- Zuiger
- Zijborstel

**F-REQ 8 [SH]:** De Roomba library broncode moet het mogelijk maken om de leds van de Roomba te manipuleren. De leds die het moet kunnen manipuleren zijn:
- DD
- MAX
- CLEAN
- SPOT
- STATUS

**F-REQ 9 [SH]:** De Roomba library broncode moet het mogelijk maken om de Baudrate van de SCI poort te wijzigen. De baudrates die het moet ondersteunen zijn:
- 300 bps
- 600 bps
- 1200 bps
- 2400 bps
- 4800 bps
- 9600 bps
- 14400 bps
- 19200 bps
- 28800 bps
- 38400 bps
- 57600 bps
- 115200 bps

**F-REQ 10 [SH]:** De Roomba library broncode moet het mogelijk maken om noten af te spelen op de Roomba.

**F-REQ 11 [CH]:** De Roomba library broncode moet liedjes af kunnen spelen op de Roomba met behulp van midi bestanden.

Moscow methode:
[MH] = Must Have
[SH] = Should Have
[CH] = Could Have


**NF-REQ 1 [MH]:** De Roomba library moet zo platform onafhankelijk mogelijk geschreven worden. 

**NF-REQ 2 [MH]:** De Roomba library moet in de programmeertaal C++ geschreven worden.
