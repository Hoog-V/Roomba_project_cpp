- Gebruik van camelCase <- dus testFun bijv. nu is library mixed case gebruikt dat is fout :| ,

- Gebruik van getters en setters waar het kan (-> setPin of setLED)

- Haakjes bij if-statement behalve als het een oneliner is:
   bijv. dit is een oneliner:
  if(test)
     
     runTest();

   bij meer dan 1 lijn code in een if statement:
  
   if(test){
   
    LOG("Tests started")
    
    runTest()  
   
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
