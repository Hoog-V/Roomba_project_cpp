@page 6 Bijdragen
@tableofcontents

@section a Algemene regels

- Werk altijd in een aparte branch als je veranderingen wilt maken of een nieuwe feature wilt toevoegen.
  Op deze manier worden fouten bij het mergen van bestanden voorkomen en is het makkelijker om bij pull requests
  een code review te doen.
- Volg de [Code standaarden](MD/Code_standaarden.md)
- Maak een test alvorens het maken van een nieuwe feature.
  Dan weet je zeker dat je niet vergeet de functie te testen.
- Maak pull requests aan als je klaar bent met het schrijven van een feature of refactoren.
  Op deze manier kunnen mensen nog eventjes de code controleren voordat het in de main komt.
- Als je een git message maakt. begin dan met -enh -add -wip (of een andere die logisch is)  


@section c Code standaarden
- Gebruik van camelCase <- dus testFun bijv. nu is library mixed case gebruikt dat is fout :| ,

- Gebruik van getters en setters waar het kan (-> setPin of setLED)

- Haakjes bij if-statement:
  if(test){
     
     runTest();
     
   }

 
  **Gebruik altijd haakjes als er meer dan 1 lijn code in de if statement staat. Anders snapt de compiler het niet!**

- Haakjes openen op dezelfde regel bij definitie functie of loop:
   
   void testFun(){

   
   }
   
   
- Zoveel mogelijk const en constexpr gebruiken


- Zoveel mogelijk de regels voor benoemen van functies, variabelen, classes de Naming convention in cpp aanhouden:
Zie https://www.geeksforgeeks.org/naming-convention-in-c/

- Zoveel mogelijk de google C++ style guide aanhouden (met uitzondering van naming conventions en cpp standaard versie):
https://google.github.io/styleguide/cppguide.html

- C++20 functies zijn toegestaan




