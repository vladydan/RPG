
void combat(int vie) {
   println("Tapez help pour afficher toutes les commandes relative au combat ");
   boolean quitter=false;
   int vie_mob =20;
 
     while(vie!=0&&vie_mob!=0&&quitter!=true){
      String choix = ("Vous vous faites attaquer,voulez vous attaquer bloquer ou fuire?");
      clear();
      println("Vos points de vie: " + vie+"                   point de vie du mob" + vie_mob);
   	
   	if (equal(choix,"bloquer")){
   		force++;
   	}
     if (equal(choix, "fuire")) {
     	quitter=true;
   }
  
   vie=vie+(force_mob+random(1,10);
}
}
static int stone_sword;

static int wooden_sword;

static int force, intelligence, vie;

static int niveau;

static int barre;

static int update(int barre) {
   boolean niv;
   niv = false;
   if (barre ==20) {
      niveau ++;
      niv = true;
   }
   if (niv == true) {
      force = force+3;
      intelligence = intelligence+3;
      vie = vie+30;
   }
   if (wooden_sword ==1) {
      force =10;
   }
   if (stone_sword ==1) {
      force =15;
   }
   return  barre;
}

static boolean reset(char empty_map[][], boolean coffre, int taillex, int tailley, int have_item[][]) {
   for (int i =0; i < taillex; i ++) {
      for (int j =0; j < tailley; j ++) {
         empty_map[i][j] = ' ';
         have_item[i][j] =0;
      }
   }
   return  false;
}


void spawn(char map[][], char map2[][], int MAX, int MAXb) {
   int a,b,q,s;
   a = random(1, MAX);
   b = random(1, MAXb);
   map[a][b] = 'X';
   map2[a][b] = 'X';
}

void show(char map[][], int taillex, int tailley) {
   for (int i =0; i < taillex; i ++) {
      for (int j =0; j < tailley; j ++) {
         print(map[i][j] + "  ");
      }
      println(" ");
   }
}

void main() {
   clear();
   int i,j;
   int taillex = random(20, 40);
   int tailley = random(20, 40);
   char map[][] = new char[taillex][tailley];
   int have_item[][] = new int [taillex][tailley];
   int MAX = taillex -1;
   int MIN =1;
   int tailletotal;
   int a,b;
   int MAXb = tailley -1;
   int MINb =1;
   char pos_joueur = 'X';
   String choix;
   boolean coffre = false;
   niveau =1;
   vie =50;
   force =5;
   int pot_vie =0;
   intelligence =5;
   char empty_map[][] = new char[taillex][tailley];
   for (i =0; i < taillex; i ++) {
      for (j =0; j < tailley; j ++) {
         map[i][j] = ' ';
         map[0][j] = '#';
         map[i][0] = '#';
         map[i][tailley -1] = '#';
         map[taillex -1][j] = '#';
      }
   }
   tailletotal = taillex * tailley;
   tailletotal = tailletotal /5;
   for (i =0; i < tailletotal; i ++) {
      a = random(MIN, MAX);
      b = random(MINb, MAXb);
      map[a][b] = '#';
   }
   for (i =0; i < taillex; i ++) {
      for (j =0; j < tailley; j ++) {
         if (map[i][j] == '-' && map[i -1][j] == '#' && map[i][j -1] == '#' && map[i +1][j] == '#' && map[i][j +1] == '#') {
            map[i +1][j] = '-';
         }
         if (map[i][j] == 'C' && map[i -1][j] == '#' && map[i +1][j] == '#' && map[i][j -1] == '#') {
            map[i +1][j] = '-';
            map[i -1][j] = '-';
            map[i][j -1] = '-';
            map[i][j +1] = '-';
         }
      }
   }
   println("Deplacez vous avec ZQSD");
   println("Tapez help pour avoir plus d'info");
   for (i =0; i <5; i ++) {
      coffre = false;
      reset(empty_map, coffre, taillex, tailley, have_item);
      int q = random(MIN, MAX);
      int s = random(MINb, MAXb);
      map[q][s] = 'C';
      map[q +1][s] = 'M';
      map[q -1][s] = 'M';
      map[q][s -1] = 'M';
      map[q][s +1] = 'M';
      a = random(1, MAX);
      b = random(1, MAXb);
      map[a][b] = 'X';
      empty_map[a][b] = 'X';
      while ( ! coffre) {
         choix = readString();
         if (equal(choix, "help")) {
            clear();
            println("Map pour afficher la carte");
            println("Fouiller pour fouiller le sol et y trouvé des objets");
            println("Status pour afficher l'état du personnage");
            println("Inventaire pour afficher l'inventaire du personnage");
         }
         if (equal(choix, "status")) {
            clear();
            println("Vous êtes niveau " + niveau + " et vous êtes à " + barre+" barre sur 20");
            println("Vous avez actuellement : ");
            println(force + " de force");
            println(intelligence+" d'inteligence");
            println(vie+" de vie");
         }
         if (equal(choix, "inventaire")) {
            clear();
            println("Vous avez actuellement : ");
            println(pot_vie+" potion de vie");
         }
         if (equal(choix, "fouiller")) {
            if (have_item[a][b] ==1) {
               println("Vous avez déja fouillé ici");
            } else {
               int chance = random(0, 100);
               if (chance <=50) {
                  println("Vous n'avez rien trouvé ici");
               }
               if (50 <= chance && chance <80) {
                  println("Bravo , vous avez trouvé une potion de vie!");
                  pot_vie++;
               }
               if (50 <= chance && chance <85) {
                  println("Bravo , vous avez trouvé une épée en bois!");
                  wooden_sword =1;
                  print(wooden_sword);
               }
               if (85 <= chance && chance <88) {
                  println("Bravo , vous avez trouvé une épée en pierre!");
                  stone_sword =1;
               }
               update(barre);
               have_item[a][b] =1;
            }
         }
         if (equal(choix, "map")) {
            clear();
            show(empty_map, taillex, tailley);
         }
         if (equal(choix, "cheat")) {
            clear();
            show(map, taillex, tailley);
         }
         if (equal(choix, "d")) {
            clear();
            if (map[a][b +1] == '#') {
               println("Ouch , il y a un mur juste devant !");
               empty_map[a][b +1] = '#';
            } else {
               map[a][b] = ' ';
               empty_map[a][b] = map[a][b];
               b = b +1;
               empty_map[a -1][b] = map[a -1][b];
               empty_map[a +1][b] = map[a +1][b];
               empty_map[a][b +1] = map[a][b +1];
               empty_map[a][b -1] = map[a][b -1];
               map[a][b] = 'X';
               empty_map[a][b] = 'X';
               barre++;
               update(barre);
            }
         }
         if (equal(choix, "q")) {
            clear();
            if (map[a][b -1] == '#') {
               println("Ouch , il y a un mur juste devant !");
               empty_map[a][b -1] = '#';
            } else {
               map[a][b] = ' ';
               empty_map[a][b] = map[a][b];
               b = b -1;
               empty_map[a -1][b] = map[a -1][b];
               empty_map[a +1][b] = map[a +1][b];
               empty_map[a][b +1] = map[a][b +1];
               empty_map[a][b -1] = map[a][b -1];
               map[a][b] = 'X';
               empty_map[a][b] = 'X';
               barre++;
               update(barre);
            }
         }
         if (equal(choix, "z")) {
            clear();
            if (map[a -1][b] == '#') {
               println("Ouch , il y a un mur juste devant !");
               empty_map[a -1][b] = '#';
            } else {
               map[a][b] = ' ';
               empty_map[a][b] = map[a][b];
               a = a -1;
               empty_map[a -1][b] = map[a -1][b];
               empty_map[a +1][b] = map[a +1][b];
               empty_map[a][b +1] = map[a][b +1];
               empty_map[a][b -1] = map[a][b -1];
               map[a][b] = 'X';
               empty_map[a][b] = 'X';
               barre++;
               update(barre);
            }
         }
         if (equal(choix, "s")) {
            clear();
            if (map[a +1][b] == '#') {
               println("Ouch , il y a un mur juste devant !");
               empty_map[a +1][b] = '#';
            } else {
               map[a][b] = ' ';
               empty_map[a][b] = map[a][b];
               a = a +1;
               empty_map[a -1][b] = map[a -1][b];
               empty_map[a +1][b] = map[a +1][b];
               empty_map[a][b +1] = map[a][b +1];
               empty_map[a][b -1] = map[a][b -1];
               map[a][b] = 'X';
               empty_map[a][b] = 'X';
               barre++;
               update(barre);
            }
         }
         if (map[a][b] == map[q][s]) {
            println("Bravo , vous avez trouvé le trésor!");
            choix = readString("Voulez vous passé au niveau suivant?");
            if (equal(choix, "oui")) {
               coffre = true;
            }
            if (equal(choix, "non")) {
               println("La commande niveau est maintenant disponible , passez ce niveau quand vous le voulez");
            }
         }
         int combat = random(1, 10);
         if (combat >=3) {
         }
         if (barre >=21) {
            barre =1;
         }
      }
   }
   show(map, taillex, tailley);
}
